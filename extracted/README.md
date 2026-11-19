# nvflash bundle `9802810007` — analysis & manual-flash guide

## What the file is

`/home/anelson/research/nv-bundle/9802810007` is a self-contained **NVIDIA
firmware flasher** carrying a **PLDM firmware-update package**, a
statically-linked Linux x86-64 ELF. It is **not** a wrapper around a separate
tool: it *is* the flasher, with the target firmware compiled into its `.data`
section.

It is really the full `nvflash_eng` engine behind a **restricted field-update
front-end** (`nvuflash`): both personality strings are present, and the shipped
CLI exposes only info commands (`--help`, `--dump`, `--version`,
`--licenseinfo`). `--dump` confirms the payload is a PLDM package:
`PLDM Package Version 98.02.81.00.07`, `Component Identifier 0xC000`. The actual
firmware update is a **default action** that the shipped argument parser blocks
as `Unknown command` — see "How you actually run it" below.

- Filename `9802810007` == embedded package / VBIOS version **98.02.81.00.07**
- Target board: **PG144 SKU 520**, GPU PCI device **`0x2BB1`** (Blackwell-class
  datacenter module — has ERoT / EC / CEC / dual-flash AP0+AP1)
- File is 102 MB but **~78 MB is zero-fill** scratch buffer; real payload ≈ 7 MB.

| ELF section | size | role |
|---|---|---|
| `.text` | ~9.2 MB | the nvflash program code |
| `.rodata` | ~1.2 MB | strings / tables |
| `.data` | ~85 MB | embedded firmware (~7 MB) + 78 MB zero scratch |

## Extracted files (this directory)

Best-effort structural split of the firmware payload. Components are NVIDIA's
proprietary signed ROM format; exact partition names need the ROM-directory
parse, but boundaries and types below are verified by headers/strings/entropy.

| file | ~size | entropy | what it is |
|---|---|---|---|
| `firmware_region.bin` | 6.8 MB | — | the entire non-zero payload (all components concatenated) |
| `00_main_gpu_fw_and_recovery.bin` | 1.5 MB | 7.97 | leading signed blob: recovery/cert/bring-up sub-images |
| `01_main_gpu_fw_image.bin` | 3.9 MB | 7.99 | main GPU firmware image (FB / FWSEC / falcon ucodes) — signed/compressed |
| `02_vbios_98.02.81.00.07.bin` | 163 KB | 6.87 | **primary VBIOS** — PCI dev `0x2bb1`, has `BIT` table + DevInit script + certs |
| `03_vbios_efi_gop_2b80.bin` | 62 KB | 4.63 | UEFI/GOP display driver image (dev `0x2b80`) |
| `04_fw_block_mid.bin` | 674 KB | 3.09 | middle block (tables / low-entropy) |
| `05_fw_rom_2b80.bin` | 269 KB | 7.99 | additional signed ROM image (dev `0x2b80`) |
| `06_tail_inforom_ec_cec.bin` | 424 KB | ~0 | tail (mostly padding; EC/CEC/InfoROM region) |
| `vbios_98.02.81.00.07.rom` | 163 KB | — | same bytes as `02_...`, kept as a `.rom` for convenience |

## The "script" question

What "runs" is three layers plus an embedded policy config:
1. **nvflash's flashing logic** — compiled machine code in `.text` (the
   `PushPoll` protocol driving the on-GPU uCode: `Struct Init`, `Sector Erase`,
   `Chip Erase`, `Program EEPROM`).
2. **The embedded firmware images** above — what actually gets written.
3. **The VBIOS DevInit script** — bytecode inside `02_vbios_*` that the GPU's
   falcon/PMU interprets at init. Signed with the VBIOS.
4. **The flash recipe/policy** — an embedded JSON config (`flash_config.json`,
   see below) that tells the flasher *which* devices to update and how. This is
   the closest thing to "the script that runs" and it is **serial-locked**.

## SERIAL LOCK — this bundle only flashes ONE board

At file offset `0x1167f60` the payload carries a block tagged
**`NVUF_JSON_CONFIG`** (magic + 32-byte digest + length `0x1CD`=461 + JSON). The
JSON (`flash_config.json`) is:

```json
{
    "version": 1,
    "restricted_mode": "sn_based",
    "no_confirm": true,
    "upgrade_only": false,
    "no_downgrade": false,
    "forced_board_id": "0xFFFF",
    "sn_list": [ "1791625022632" ],
    "pdi_list": []
}
```

- `restricted_mode: sn_based` + `sn_list: ["1791625022632"]` → the flasher only
  updates the board whose serial is **1791625022632**; every other board logs
  `Device not in JSON config allow-list, skipping.`
- The check is the host-side `UpdaterConfigMatcher` (decompiled in
  `../decomp/0056a7f8__NOT_in_allow_list.c`): it reads the serial from the GPU's
  **InfoROM OBD object** and runs `std::find(sn_list, serial)`. PDI-based mode
  (`../decomp/0056a1a2__NOT_in_allow_list.c`) is the alternative keying; `pdi_list`
  is empty here.
- This is a **host-side policy gate**, separate from the GPU's cryptographic
  secure boot. It is defeatable (edit `sn_list` / `restricted_mode`, or patch the
  matcher, or just use a stock nvflash on the extracted `.rom`, which ignores
  this config). It does **not** let you flash *modified* firmware — the ERoT
  signature gate still applies.

### Unlocked flasher: `../nvflash_unlocked`

`9802810007` is the only flasher that supports this board (the consumer NVFlash
won't drive an ERoT/datacenter board), so the fix is this same binary with the
locks removed. `../nvflash_unlocked` is that patched copy. It needed **two**
patches — the serial unlock alone produced a binary that only printed
`Unknown command` and could not flash:

- **Patch #1 — serial unlock.** 6 bytes at file offset `0x16b872`
  (fn `FUN_0056b872`, the allow-list dispatcher): `41 56 41 55 41 54` →
  `b8 01 00 00 00 c3` (`mov eax,1 ; ret`) = always "allowed". Flashes **any
  serial of this model**; `sn_list` is ignored.
- **Patch #2 — CLI dispatch gate.** 5 bytes at file offset `0x17c719`
  (fn `FUN_0057c719`, the parser's "unknown command" getter that the dispatcher
  checks first): `0f b6 47 60 c3` → `31 c0 66 90 c3` (`xor eax,eax ; nop ; ret`)
  = always "recognized". A **bare run now reaches the default UPDATE path**
  instead of being rejected as `Unknown command`; `--dump`/`--version`/`--help`
  still work (checked first).
- **Still enforced (brick protection intact):** Board-ID/model match
  (`Board data is mismatch...`), ERoT firmware signature, anti-rollback. A
  wrong-model board is rejected, not bricked.

See `../decomp/PATCH_PROOF.txt` for both patches and
`../SERIAL_UNLOCK_PLAYBOOK.md` Phase 9 for how patch #2 was found.

sha256 original = `12978284…84a51c`, fully patched = `912f0d74…00d04d3c`.
(`../nvflash_eng` is an identical copy — same bytes, same sha256.)

(Alternative, not used here: editing `sn_list` in `flash_config.json` and
recomputing its SHA-256 header — keeps per-serial targeting but requires listing
every target serial up front.)

## Can it be modified? (short answer: not for flashing)

You can hex-edit anything, but the GPU **rejects tampered firmware**. Enforcement
is on the device, not in this binary:

- **ERoT (External Root of Trust)** — a separate security MCU verifies every
  image's signature before a flash is accepted.
- **Cert-chain + RSA/X.509 validation** per partition (`BCRT_ERROR_CODE_CERT20/
  CERT30_*`, `AP0/AP1 ... Image Signature`), including
  `Devinit script signature type does not match devinit tables signature type`.
- **Anti-rollback fuses**: `..._FW_ROLLBACK_PROTECTION_CHECK_ERROR`,
  `boot ucode SW rev is revoked`, `AP flash access revoked`.
- The host string `GPU firmware image signature is not valid.` is only an
  **error-code→message lookup** — nvflash is *reporting* the GPU's verdict.

Patching this binary's own checks only bypasses host-side sanity checks; the
ERoT still refuses images not signed by NVIDIA's private key (not recoverable
from the binary).

---

## How you actually run it

> ⚠️ **Flashing GPU firmware can permanently brick the board.** You cannot flash
> a *modified* image (see above). Do this only on hardware you own and can risk.

**This is a restricted field-update front-end — not the full nvflash.** The
classic flags (`--list`, `--index`, `--save`, `--autoupdate`, `--display`, …)
are **not registered** in this build and return `Unknown command`, even though
the engine's whole vocabulary is still present as strings (see the dump below).
The CLI dispatcher (`FUN_0092406e`) has exactly five outcomes:

| You run… | What happens |
|---|---|
| `--help` | print the 4-command usage |
| `--licenseinfo` | print license text |
| `--dump` | print embedded PLDM package info (read-only) |
| `--version` | print firmware versions of adapters present (read-only) |
| **anything else recognized** | **flash the embedded firmware (the default action)** |

Use the patched `../nvflash_unlocked` (both patches applied). The original
`9802810007` would reject the update path as `Unknown command`.

### Preconditions
- Run as **root**.
- **Unload the NVIDIA kernel driver first** (the tool requires it):
  ```
  sudo systemctl stop nvidia-persistenced 2>/dev/null
  sudo rmmod nvidia_uvm nvidia_drm nvidia_modeset nvidia 2>/dev/null
  ```

### 1. Inspect (read-only, safe)
```
sudo ../nvflash_unlocked --dump      # embedded PLDM package (98.02.81.00.07)
sudo ../nvflash_unlocked --version   # current firmware versions of adapters present
```

### 2. Flash the embedded image — the default action
```
sudo ../nvflash_unlocked             # bare run = UPDATE embedded firmware
```
The embedded config has `no_confirm:true`, so once a matching board is detected
it flashes **without prompting**. There is no per-GPU `--index` selector in this
build; it updates the detected matching GPU(s) using the embedded config, so run
on a host whose target GPU(s) are the intended model.

### Dry-run confirmation (no flash)
Run the bare command **with the NVIDIA driver still loaded** — with patch #2 it
reaches the update/adapter-detection stage instead of `Unknown command`, but the
driver holding the device prevents an actual flash. Then unload the driver to
flash for real.

### Full engine vocabulary present in the binary (NOT exposed as commands here)
These strings exist inside the binary but are inert in this front-end — listed
only to document the underlying engine, **not** as commands you can run:
```
--addpp --addtgpapp --ae --aggregatetoken --autoupdate --backupinforom --buildinfo
--calibratebridgeled --calibrategpuled --check --compare --crashlog --dbgtokenrequest
--delapp --delpp --display --dump --ecid --elsettally --entire --erasebridgeid
--eraseinforom --ey --flashinforom --fullrecovery --fwindex --getceccert --getceclog
--getfwlog --globib --gpumode --guid --guidcheck --guidsource --help --ifronly --index
--installceccert --installkey --installtoken --key --keyinfo --license --licenseinfo
--licflash --lichelp --licinfo --licreq --list --listbridgeled --listgmac --listgpuled
--listgpumodes --listpatches --log --lspci --n0 --n5 --noconfirm --nopowerchk --noretries
--offset --osfpindex --osfpupdate --outfilepath --owobdmn --partopts --pciblocks --pcisegbus
--presdatatune --presregtune --progbridgeled --progfwovercec --proggmac --proggpuled --protectoff
--protecton --querybridgeled --querygmac --querygpuled --rdbrd --rdbridgeid --rdccc --rdciebridgeled
--rdciegpuled --rdhlk --rdobd --rdoem --rdulf --rdupr --recoverinforom --repairfs --revokepolicy
--rmhlk --romin --romout --sanitizefs --save --savebridgeled --savegmac --savegpuled --setpci
--spiclkshmoo --straps --stress --string --tv --updateuefi --updatexusb --upgradeonly --verify
--verifyccc --wrbbo --wrbrd --wrbridgeid --wrbro --wrccc --wrcgp --wrciebridgeled --wrciegpuled
--wrhlk --wrobd --wroem --wrpersrgb --wrsn --wrulf --wrupr
```
(The config-driven modifiers the front-end *does* honor — `noconfirm`,
`upgradeonly`, `nodowngrade`, `forceboard`, `forcesub`, `reset_after_update`,
`protectoff`, `silence`, `offrfwupdate`, `updatexusb`, `unload_preos`,
`vercmp5part`, `overridesub` — are injected automatically from the embedded JSON
config, not passed on the command line.)

## Decompiled logic
See `../decomp/` for Ghidra-decompiled C of the key routines:
- `cmdparser_0092406e.c` — the top-level CLI dispatcher (the 5-way routing above;
  the `Unknown command` gate and the default UPDATE branch)
- `appctor_0087b322.c` / `cmds_00879ff6.c` — option registration and the
  JSON-config → internal-args injection (`noconfirm`, `forceboard`, …)
- `0056a7f8_*.c` / `0056a1a2_*.c` — the sn/pdi allow-list matchers
- `trace_dispatcher_0056b872.c`, `PATCH_PROOF.txt` — the serial-lock dispatcher
  and both patches (serial unlock + CLI gate)
- `00725dbe_*.c` — anti-rollback / revocation handling (left intact)

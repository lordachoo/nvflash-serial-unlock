# nvflash_unlocked — usage

`nvflash_unlocked` is a patched copy of the NVIDIA firmware-update bundle
`9802810007`. Two host-side changes were made (details below): the per-board
**serial lock is removed**, and the CLI gate that made the embedded update
unreachable is **opened**, so the tool will actually flash the firmware it
carries. The model/Board-ID check, the GPU's ERoT firmware-signature check, and
anti-rollback are all **still enforced** — a wrong-model board is rejected (not
bricked) and only genuine NVIDIA-signed firmware is accepted.

- Original: `9802810007` (unchanged) — sha256 `12978284…84a51c`
- Patched:  `nvflash_unlocked` / `nvflash_eng` (identical) — sha256 `912f0d74…00d04d3c`

> **Status:** both patches are derived from static reverse engineering
> (Ghidra / objdump decompilation of the dispatcher). They have **not** been
> run against hardware here. See "Verify safely before you flash" below.

---

## What this binary actually is

The `--dump` output settles it — this is **not** a classic consumer `nvflash`.
It is a **PLDM firmware-update package** flasher:

```
FW Package
 - Version     : PLDM Package Version 98.02.81.00.07
 - Image Size  : 001D1E9F
 - CRC32       : 5B293B1A
Component Image #0
 - Component Identifier  : 0xC000
 - Component Version     : 98.02.81.00.07
```

Internally it is NVIDIA's `nvflash_eng` engine wrapped in a **restricted
field-update front-end** (`nvuflash`). The embedded firmware package is compiled
into the binary; the front-end's job is to apply it.

### Command surface (how it really dispatches)

Decompiling the dispatcher (`FUN_0092406e`) shows exactly five outcomes:

| You run… | What happens |
|---|---|
| `--help` | print the 4-command usage |
| `--licenseinfo` | print license text |
| `--dump` | print the embedded PLDM package info (read-only) |
| `--version` | print firmware versions of adapters in the system (read-only) |
| **anything else recognized** | **flash the embedded firmware (the default action)** |

The update is the **default** action — there is no `--autoupdate`/`--flash`
subcommand in this build (those belong to the full engine and are *not*
registered here; that is why they printed `Unknown command`). The shipped
binary refused to reach the default path because its argument parser flags a
bare/other invocation as "unknown" before dispatch. Patch #2 opens that gate.

---

## What firmware / board is this?

Facts read directly from the binary:

| Field | Value |
|---|---|
| **Package / VBIOS version** | **98.02.81.00.07** (the filename `9802810007`) |
| Package format | **PLDM**, Component Identifier `0xC000` |
| VBIOS name string | `PG144 SKU 520 VGA BIOS` |
| Board design | **PG144**, SKU 520 |
| GPU PCI device ID | **`0x10DE:0x2BB1`** (sub-images also `0x2B80`) |
| Board part number | `699-25612-0002-205` |
| Copyright | `(C) 1996-2025 NVIDIA Corp.` |
| Class | Datacenter / enterprise module — ERoT, EC & CEC firmware, dual flash (AP0/AP1), OSFP/UEFI/xUSB paths |

**Identification (inferred, not stamped in the firmware):** device `0x2BB1` is a
**Blackwell-generation** GPU; NVIDIA's dev forum shows `2bb1 (rev a1)`
enumerating as an **RTX PRO 6000 Blackwell** family board (`0x2BB5` is the RTX
PRO 6000 Blackwell Server Edition). So this is almost certainly an RTX PRO 6000
Blackwell-class board, design PG144, SKU 520. Confirm against your board's own
label (`--version`) before flashing.

---

## The two patches

| # | File offset | Original → patched | Effect |
|---|---|---|---|
| 1 — serial unlock | `0x16b872` | `41 56 41 55 41 54` → `b8 01 00 00 00 c3` (`mov eax,1; ret`) | allow-list dispatcher always returns "allowed"; `sn_list` ignored → flashes **any serial of this model** |
| 2 — dispatcher gate | `0x17c719` | `0f b6 47 60 c3` → `31 c0 66 90 c3` (`xor eax,eax; nop; ret`) | "unknown command" flag always reads 0 → a bare run reaches the **default update** path |

Full reasoning in [`decomp/PATCH_PROOF.txt`](decomp/PATCH_PROOF.txt); serial
method in [`SERIAL_UNLOCK_PLAYBOOK.md`](SERIAL_UNLOCK_PLAYBOOK.md).

### Reproduce / re-patch a fresh bundle

[`nv_unlock.py`](nv_unlock.py) applies the patches automatically. It locates each
site by a unique byte-signature (not a fixed offset), so it also works on a
byte-identical re-release (e.g. the same updater carrying firmware for a
different PCI ID / VBIOS). The two patches are **independent** — each is applied
if its site is found and skipped-with-a-warning if not, so a missing site never
blocks the other and never corrupts the file. It is idempotent and refuses rather
than guessing if a build differs.

```bash
./nv_unlock.py 9802810007               # both patches -> 9802810007_unlocked
./nv_unlock.py 9802810007 --serial-only # strip ONLY the serial lock
./nv_unlock.py 9802810007 --verify      # dry run: show what it would patch
```

- **default** — serial unlock **＋** CLI gate (what this restricted build needs
  to actually flash). Patching the original reproduces this exact binary
  (sha256 `912f0d74…00d04d3c`).
- **`--serial-only`** — applies only the serial allow-list strip and leaves
  everything else alone (changes exactly 6 bytes). Use this on a bundle that
  already runs on its own (a full-engine build) and only needs the serial lock
  removed. On *this* restricted front-end it will warn that the CLI gate is still
  closed (a bare run would still say `Unknown command`).

Neither patch ever touches the model / Board-ID / PCI-ID match, the ERoT
signature check, or anti-rollback — those stay enforced in every mode.

Still enforced (brick protection): Board-ID/model match (`Board data is
mismatch…`), ERoT signature, anti-rollback. You **cannot** flash a modified
image — the GPU's root of trust rejects anything not signed by NVIDIA.

---

## Before you flash (required)

1. Run as **root**.
2. **Unload the NVIDIA driver first** (the tool requires it):
   ```bash
   sudo systemctl stop nvidia-persistenced 2>/dev/null
   sudo rmmod nvidia_uvm nvidia_drm nvidia_modeset nvidia 2>/dev/null
   ```
3. ⚠️ Flashing firmware can **brick a GPU**. Back up / have recovery ready, and
   run on a system where the target GPU(s) are the intended model. The embedded
   config has `no_confirm:true`, so once a matching board is detected the update
   **proceeds without prompting**.

## Usage

```bash
# 1. inspect — read-only, safe
sudo ./nvflash_unlocked --dump        # show the embedded PLDM package (98.02.81.00.07)
sudo ./nvflash_unlocked --version     # show current firmware versions of adapters present

# 2. flash the embedded firmware — THIS IS THE UPDATE
#    (root, NVIDIA driver unloaded). A bare run is the default = update.
sudo ./nvflash_unlocked
```

On the update path the tool prints `This utility will attempt to update the
NVIDIA GPU firmware.` and applies the embedded `98.02.81.00.07` package to the
detected matching GPU(s). If a board is rejected with `Board data is mismatch…`
it is **not** this model — that protection is intentionally left on; do not try
to force it.

## Verify safely before you flash

Because these patches are static-analysis-derived and the config auto-confirms,
sanity-check the dispatch **with the NVIDIA driver still loaded** first:

```bash
sudo ./nvflash_unlocked        # driver still loaded
```

- Before patch #2 this printed `Unknown command` + the 4-command list.
- After patch #2 it should instead reach the update/adapter-detection stage
  (e.g. the update banner, or a "device in use / driver loaded" style error) —
  i.e. it no longer says `Unknown command`.

With the driver loaded the engine can't take the device, so this confirms the
trigger **without** committing a flash. Only once you've seen that, unload the
driver (steps above) and run it again to actually flash.

---

## Notes / caveats

- `nvflash_eng` is an identical copy of `nvflash_unlocked` (same bytes, same
  sha256). The filename does **not** change behavior — both dispatch the same
  way now.
- The full `nvflash` engine vocabulary (`--list`, `--save`, `--index`,
  `--display`, `--updateuefi`, …) exists as strings inside the binary but is
  **not registered** as commands in this field-update build, so passing them
  still yields `Unknown command`. This bundle's real interface is the four info
  commands plus the default update. Do not rely on the classic nvflash flags
  here.
- Per-GPU targeting: this build updates the detected matching GPU(s) using the
  embedded config. If unsure, run on a host with a single target GPU.

## Related files

- [`nv_unlock.py`](nv_unlock.py) — one-shot patcher: bundle in → unlocked bundle out
- [`SERIAL_UNLOCK_PLAYBOOK.md`](SERIAL_UNLOCK_PLAYBOOK.md) — how the unlock was reverse-engineered (reusable method)
- [`decomp/PATCH_PROOF.txt`](decomp/PATCH_PROOF.txt) — both patches, exact bytes + why they're safe
- [`extracted/README.md`](extracted/README.md) — deep-dive analysis, carved firmware, `flash_config.json`
- `decomp/cmdparser_0092406e.c`, `appctor_0087b322.c`, `cmds_00879ff6.c` — the
  decompiled dispatcher / option registration / config-injection

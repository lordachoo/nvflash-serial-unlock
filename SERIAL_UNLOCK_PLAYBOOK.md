# NVIDIA nvflash Firmware-Bundle Unlock Playbook

A step-by-step, reusable method for reverse-engineering an NVIDIA `nvflash`
firmware **update bundle** (a self-contained flasher with firmware baked in) and
producing a **working, unlocked copy** that will flash **any board of the same
model** while leaving every brick-protection (Board-ID match, ERoT firmware
signature, anti-rollback) intact.

There are **two independent problems** to solve, and a real bundle usually needs
**both** patches:

1. **The serial / PDI allow-list lock** (Phases 1–8) — the bundle refuses any
   board whose serial isn't in an embedded JSON allow-list. Patch = force the
   allow-list dispatcher to return "allowed".
2. **The CLI dispatch gate** (Phase 9) — many of these bundles ship as a
   **restricted field-update front-end** (`nvuflash`) wrapping the full
   `nvflash_eng` engine. The front-end exposes only info commands
   (`--help/--dump/--version/--licenseinfo`); the actual firmware update is a
   **default action** that the argument parser blocks as `Unknown command`.
   Patch = open that gate so the update path is reachable. **Without this the
   "unlocked" binary still won't flash anything** — it just prints
   `Unknown command`.

> Lesson from the worked example: solving only problem #1 produces a binary that
> *looks* done but is **unusable** — every real invocation returns
> `Unknown command`. Always check whether the bundle is a restricted front-end
> (Phase 9) before declaring victory.

> For the worked-example family specifically, both patches are already automated
> by [`nv_unlock.py`](nv_unlock.py) (`./nv_unlock.py BUNDLE`). It finds each site
> by a unique byte-signature, so it also handles byte-identical re-releases and
> refuses rather than guessing on a build it doesn't recognize. The phases below
> are how those signatures were *derived* — follow them when the tool reports a
> site it can't locate.

This document is written so another operator — human or an LLM/REA agent — can
repeat the process on a *different but similar* payload. Specific addresses in
the worked example (`9802810007`, PLDM package / VBIOS 98.02.81.00.07, board
PG144/dev `0x2bb1`) **will differ** on another bundle; every step therefore shows
how to *re-derive* the address rather than hard-coding it.

---

## 0. Scope & safety preconditions

- Use only on hardware you own, with vendor-signed firmware you are entitled to
  flash. This method **does not** forge or modify firmware — the GPU's on-die
  root of trust (ERoT) still rejects any altered image. It only removes a
  **host-side** policy check that restricts the flasher to a specific unit.
- **Keep the model/Board-ID check.** Removing it risks flashing firmware onto an
  incompatible board and bricking it. The unlock below deliberately leaves it on.
- Back up each target's current firmware before flashing **if the build exposes
  a save/read command** — a restricted field-update front-end (see Phase 9) may
  not, in which case your safety net is the model/Board-ID + ERoT checks (keep
  them on) and only running on boards of the correct model.
- The embedded config often sets `no_confirm:true`, so the update **does not
  prompt** — be certain the target is the right model before you run it.
- Work on a **copy**; never patch the original bundle in place.

---

## 1. Tooling / environment

Required:

| Tool | Use | Notes |
|---|---|---|
| `file`, `readelf`, `objdump`, `nm` | binary identification, sections, disassembly | binutils |
| `strings`, `grep` | string/marker discovery | |
| `python3` | carving, entropy map, byte search, patching | run untrusted input with `-I` |
| **Ghidra 12.x** (`analyzeHeadless`) | decompilation | needs a JDK matching `application.java.min` |
| **JDK** (Temurin/OpenJDK) | runs Ghidra | **Ghidra 12.2 requires JDK 25**; check `Ghidra/application.properties` |

Optional: REA MCP (`open_binary`, `analyze_function`, …) if a provider
(Ghidra/IDA/Hopper/Kuna) is configured. If REA's native provider is *not*
configured, everything here works with raw `objdump` + headless Ghidra.

### 1.1 Install Ghidra + a correct JDK (no root needed)

```bash
# Ghidra
curl -sL -o /tmp/gh.zip \
  "$(curl -s https://api.github.com/repos/NationalSecurityAgency/ghidra/releases/latest \
     | grep -oE '"browser_download_url": "[^"]+_PUBLIC_[^"]+\.zip"' | head -1 | cut -d'"' -f4)"
mkdir -p ~/ghidra && (cd ~/ghidra && unzip -q /tmp/gh.zip)
GH=$(ls -d ~/ghidra/ghidra_*_PUBLIC | head -1)

# Check the required JDK, then fetch that major version from Adoptium
grep java.min "$GH/Ghidra/application.properties"      # e.g. application.java.min=25
JV=25                                                   # <- use the number it prints
mkdir -p ~/jdk && (cd ~/jdk && \
  curl -sL -o jdk.tgz "https://api.adoptium.net/v3/binary/latest/$JV/ga/linux/x64/jdk/hotspot/normal/eclipse" \
  && tar xzf jdk.tgz && rm jdk.tgz)
JDK=$(ls -d ~/jdk/jdk-${JV}* | head -1)

# Point Ghidra at it (Ghidra ignores JAVA_HOME; it uses JAVA_HOME_OVERRIDE)
sed -i "s|^JAVA_HOME_OVERRIDE=.*|JAVA_HOME_OVERRIDE=$JDK|" "$GH/support/launch.properties"
```

**Gotchas that cost time (avoid them):**
- Ghidra 12.x **dropped bundled Jython** — `.py` postScripts fail with *"Ghidra
  was not started with PyGhidra."* **Write post-scripts in Java** (Ghidra compiles
  `.java` scripts automatically using the JDK above).
- Ghidra validates the JDK against `application.java.min`; JDK 21 is rejected by
  12.2 (*"unsupported java version"*). Match the number exactly.
- `JAVA_HOME` is ignored; only `JAVA_HOME_OVERRIDE` in
  `support/launch.properties` works. There is a commented empty line already in
  that file — set *that* one (first occurrence wins).

---

## 2. Phase 1 — Identify the target

```bash
file BUNDLE
readelf -SW BUNDLE | awk '{print $2,$3,$6,$7}'   # section name,type,addr,offset
readelf -hW BUNDLE | grep -E 'Type|Entry'        # EXEC vs DYN (PIE) matters later
```

You are looking for:
- `ELF 64-bit … x86-64 … statically or dynamically linked, stripped`
- A **huge `.data` section** (tens of MB) dwarfing `.text` — that's the embedded
  firmware + scratch buffer.
- Confirm it is nvflash:

```bash
strings -n 6 BUNDLE | grep -iE 'nvflash_eng|NVIDIA Corp|--autoupdate|PushPoll|VBIOS' | sort -u | head
strings BUNDLE | grep -oE '\-\-[a-z][a-z0-9]+' | sort -u | tr '\n' ' '   # full option set
```

**Record the base/offset relationship for address math (critical):** for a
non-PIE `EXEC` ELF, pick `.text` and compute the constant
`DELTA = vaddr - file_offset` from `readelf` (in the worked example
`.text` vaddr `0x405000` at file `0x5000` → `DELTA = 0x400000`, so
`file_off = vaddr - 0x400000`). For a PIE (`DYN`) binary there is no single
constant; compute per section: `file_off = vaddr - sec_vaddr + sec_fileoff`.

Helper:
```python
# vaddr <-> file offset using readelf section table
import subprocess, re
def sections(path):
    out = subprocess.check_output(["readelf","-SW",path]).decode()
    secs=[]
    for m in re.finditer(r'\]\s+(\S+)\s+\S+\s+([0-9a-f]+)\s+([0-9a-f]+)\s+([0-9a-f]+)', out):
        secs.append((m.group(1), int(m.group(2),16), int(m.group(3),16), int(m.group(4),16)))  # name,addr,off,size
    return secs
def va_to_off(path, va):
    for name,addr,off,size in sections(path):
        if size and addr <= va < addr+size:
            return va - addr + off
    raise ValueError("vaddr not in any section")
```

---

## 3. Phase 2 — Locate the firmware payload inside `.data`

Most of `.data` is a **zero-filled scratch/readback buffer**; the real payload is
a few MB at the front. Map it by entropy:

```python
import math
from collections import Counter
def ent(b):
    if not b: return 0
    n=len(b); c=Counter(b); return -sum((v/n)*math.log2(v/n) for v in c.values())

data=open("BUNDLE","rb").read()
# .data file range from readelf:
ds, dsize = 0xc2d720, 0x5551098           # <- substitute real .data offset,size
win=0x10000
for off in range(ds, ds+dsize, win):
    b=data[off:off+win]; z=b.count(0)/len(b); e=ent(b)
    cls = 'ZERO' if z>0.97 else 'HIGH' if e>7.3 else 'MIXED' if e>5 else 'LOW'
    # merge/print runs; the HIGH/MIXED span at the front is the firmware payload
```

Confirm firmware structure and read the version (ties the bundle to a SKU):

```python
import struct, re
# NVIDIA PCI expansion-ROM images: 0x55AA header, PCIR struct at +0x18, vendor 0x10DE
def scan_roms(data):
    i=0
    while True:
        i=data.find(b'\x55\xaa',i)
        if i<0: break
        ptr=struct.unpack_from('<H',data,i+0x18)[0]; po=i+ptr
        if data[po:po+4]==b'PCIR' and struct.unpack_from('<H',data,po+4)[0]==0x10de:
            did=struct.unpack_from('<H',data,po+6)[0]
            ln=struct.unpack_from('<H',data,po+0x10)[0]*512
            last=bool(data[po+0x15]&0x80)
            yield i, did, ln, last
        i+=2
# VBIOS version / board name:
for m in re.finditer(rb'Version \d{2}\.\d{2}\.\d{2}\.\d{2}\.\d{2}', data): print(m.group())
for m in re.finditer(rb'PG\d{3} SKU \d+', data): print(m.group())
```

Carve the payload region and the VBIOS for the record (`file` will ID a valid
PCI NVIDIA ROM):

```python
open("firmware_region.bin","wb").write(data[FW_START:FW_END])   # the non-zero span
# VBIOS = the 0x55AA..PCIR chain (walk `last` flag) that contains b"BIT\x00" + version
```

---

## 4. Phase 3 — Find the serial lock (the embedded policy config)

The lock lives in an embedded JSON config, tagged with a magic. Search:

```bash
python3 - <<'EOF'
data=open("BUNDLE","rb").read()
for marker in [b'NVUF_JSON_CONFIG', b'UpdaterConfig', b'restricted_mode', b'sn_list', b'pdi_list']:
    i=data.find(marker); print(marker, hex(i) if i>=0 else 'none')
EOF
# If you already know the board serial, search it directly (ASCII/LE64/BE64/BCD):
grep -abo 'THE_SERIAL' BUNDLE
```

Header layout at the `NVUF_JSON_CONFIG` magic (worked example):

```
offset  size  field
 +0x00   16   magic  "NVUF_JSON_CONFIG"
 +0x10   32   SHA-256 of the JSON body        <- plain, unkeyed hash
 +0x30    4   uint32 LE length of JSON body
 +0x34   N    JSON body ( { ... } )
```

Extract the JSON by brace-matching from the first `{` after the magic, and read
the policy:

```python
import hashlib, struct
data=open("BUNDLE","rb").read()
magic=data.find(b'NVUF_JSON_CONFIG')
js=data.find(b'{', magic)
ln=struct.unpack_from('<I', data, js-4)[0]       # length field sits right before '{'
cfg=data[js:js+ln]
open("flash_config.json","wb").write(cfg)
print(cfg.decode())
# verify the header digest type:
print("sha256 matches header:", hashlib.sha256(cfg).digest()==data[magic+16:magic+48])
```

Interpret the policy:

| Key | Meaning |
|---|---|
| `restricted_mode: "sn_based"` | gate by **serial number** (read from InfoROM OBD) |
| `restricted_mode: "pdi_based"` | gate by **PDI** (per-device unique hw id) |
| `sn_list: [ ... ]` | allowed serials (only populated when `sn_based`) |
| `pdi_list: [ ... ]` | allowed PDIs (only populated when `pdi_based`) |
| `forced_board_id`, `force_board`, `override_sub` | board-type overrides (leave alone) |
| `no_confirm: true` | flashes without prompting → be sure of the target model |

---

## 5. Phase 4 — Confirm the lock is actually enforced

Prove it's code, not metadata:

```bash
strings -n 6 BUNDLE | grep -iE \
 'allow-list|restricted_mode|sn_based|UpdaterConfig|not in.*list|skipping|Board data is mismatch'
```

Decisive markers to expect:
- `Device not in JSON config allow-list, skipping.` — the enforcement branch
- `NOT in allow-list` / `ALLOWED` — the matcher's log verdict
- `INFO: UpdaterConfigMatcher: SN=` / `PDI=` — where it reads device identity
- `UpdaterConfig validation: …` — the config validator
- `Board data is mismatch. The supplied image is incompatible with this device.`
  — the **model check** (separate; must stay enabled)

---

## 6. Phase 5 — Decompile with headless Ghidra

### 6.1 Reusable Java post-script (anchor functions by marker strings)

Save as `decomp_targets.java` (class name must equal filename). It finds each
marker string with `findBytes` (encoded as `\xNN`), walks `getReferencesTo`, and
dumps the decompiled C of each containing function.

```java
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.*;
import java.io.*; import java.util.*;
import ghidra.util.task.ConsoleTaskMonitor;

public class decomp_targets extends GhidraScript {
  String OUT="/ABS/OUT/DIR";
  String[] MARKERS = {
    "Device not in JSON config allow-list, skipping.",
    "NOT in allow-list",
    "INFO: UpdaterConfigMatcher: SN=",
    "INFO: UpdaterConfigMatcher: PDI=",
  };
  Set<String> seen=new HashSet<>(); DecompInterface dec; ConsoleTaskMonitor mon=new ConsoleTaskMonitor();
  public void run() throws Exception {
    FunctionManager fpa=currentProgram.getFunctionManager();
    dec=new DecompInterface(); dec.openProgram(currentProgram);
    for (String m: MARKERS) {
      StringBuilder sb=new StringBuilder();
      for (byte b: m.getBytes("ISO-8859-1")) sb.append(String.format("\\x%02x", b&0xff));
      Address[] hits=findBytes((Address)null, sb.toString(), 20);
      if (hits==null){ println("NOHIT "+m); continue; }
      for (Address h: hits) for (Reference r: getReferencesTo(h))
        dump(fpa.getFunctionContaining(r.getFromAddress()), m, h);
    }
    println("DONE "+seen.size());
  }
  void dump(Function fn,String tag,Address at){
    if(fn==null) return; String ep=fn.getEntryPoint().toString();
    if(!seen.add(ep)) return; String c;
    try{ DecompileResults r=dec.decompileFunction(fn,180,mon);
      c=(r!=null&&r.decompileCompleted())?r.getDecompiledFunction().getC():"//fail\n"; }
    catch(Exception e){ c="//ex "+e+"\n"; }
    String s=tag.replaceAll("[^A-Za-z0-9]","_"); if(s.length()>40)s=s.substring(0,40);
    try(PrintWriter w=new PrintWriter(new FileWriter(OUT+"/"+ep+"__"+s+".c"))){
      w.write("// "+tag+" @ "+at+"\n// entry "+ep+" ("+fn.getName()+")\n\n"+c);}catch(IOException e){}
    println("WROTE "+ep+" <- "+tag);
  }
}
```

Run it (first pass imports+analyzes; keep the project for fast follow-ups):

```bash
GH=~/ghidra/ghidra_*_PUBLIC; JDK=$(ls -d ~/jdk/jdk-* | head -1)
# optional: test-compile first to catch API errors fast
CP=$(find $GH/Ghidra -name '*.jar' | tr '\n' ':')
"$JDK/bin/javac" -cp "$CP" -d /tmp/cls decomp_targets.java

mkdir -p ~/ghproj
"$GH"/support/analyzeHeadless ~/ghproj proj \
  -import BUNDLE -scriptPath $(pwd) -postScript decomp_targets.java -max-cpu 8
# later, re-run scripts without re-analysis:
"$GH"/support/analyzeHeadless ~/ghproj proj -process BUNDLE -noanalysis \
  -scriptPath $(pwd) -postScript ANOTHER.java
```

**Ghidra API gotchas:** `DefinedDataIterator.definedStrings` may be absent — use
`findBytes(Address,String,int)` with a `\xNN` pattern instead. `findBytes` takes a
**String** byte-pattern, not `byte[]`.

### 6.2 Read the matchers

You will get two matcher functions (SN and PDI). Each:
1. reads device identity (serial from the **InfoROM OBD object**, or the PDI),
2. runs `std::find(list, id)` over `sn_list`/`pdi_list`,
3. returns a boolean "allowed" and logs `ALLOWED` / `NOT in allow-list`.

Note their entry addresses. Then find the single **dispatcher** that calls both.

---

## 7. Phase 6 — Find the patch point (the dispatcher)

The matchers are called from exactly one function (the `UpdaterConfig` dispatcher)
that selects sn vs pdi based on `restricted_mode` and **returns the allow boolean**.
Find it by searching `.text` for calls to the matcher entry addresses:

```bash
objdump -d --start-address=TEXT_VA --stop-address=TEXT_END BUNDLE \
 | grep -E 'call +(MATCHER1|MATCHER2)'      # e.g. 56a7f8 / 56a1a2
# -> both calls live in one function = the dispatcher; note its entry address
```

Sanity-check the consumer branch (the thing that prints "skipping"). Ghidra often
**fails to resolve this reference** because the dispatcher is called via a C++
**vtable** (`call *rax`). Find the string reference by **raw immediate scan**
instead (works for non-PIE, where strings are loaded as absolute immediates):

```python
import struct
data=open("BUNDLE","rb").read()
SKIP_VA = 0xXXXXXXXX                # vaddr of "Device not in JSON config allow-list…"
imm = struct.pack('<I', SKIP_VA)    # mov $imm32, %reg  -> little-endian bytes
ts, te = TEXT_OFF, TEXT_OFF+TEXT_SIZE
i=ts
while True:
    j=data.find(imm, i, te)
    if j<0: break
    print("ref at vaddr", hex(j + DELTA)); i=j+1
# (For PIE/rip-relative: scan for 48 8d /r lea with disp32 where next_va+disp==SKIP_VA)
```

Disassemble around that reference and confirm the shape:

```
call  *rax                  ; vtable call -> dispatcher
mov   al -> allowed_flag
cmpb  allowed_flag, 0
jne   flash_path            ; nonzero => proceed to flash
… load "…allow-list, skipping." ; zero => skip
```

This confirms: **make the dispatcher return nonzero ⇒ the skip branch is never
taken ⇒ flashes any serial.**

---

## 8. Phase 7 — Apply the unlock patch

Force the dispatcher to `return 1` by overwriting its prologue with
`mov eax,1 ; ret` = **`B8 01 00 00 00 C3`** (6 bytes). The dispatcher returns a
32-bit "allowed" value in `eax`, so this is a complete, side-effect-free override.

```python
import hashlib
src="BUNDLE"; dst="nvflash_unlocked"
DISPATCHER_VA = 0xXXXXXXXX
off = va_to_off(src, DISPATCHER_VA)          # helper from Phase 1
data=bytearray(open(src,"rb").read())
orig=bytes(data[off:off+6]); print("orig:", orig.hex(' '))
data[off:off+6]=bytes([0xb8,0x01,0x00,0x00,0x00,0xc3])
open(dst,"wb").write(data)
import os; os.chmod(dst, 0o755)
print("orig sha256:", hashlib.sha256(open(src,'rb').read()).hexdigest())
print("new  sha256:", hashlib.sha256(bytes(data)).hexdigest())
```

Verify only those 6 bytes changed and the disassembly is right:

```bash
cmp -l BUNDLE nvflash_unlocked            # must list exactly 6 differing bytes
objdump -d --start-address=DISPATCHER_VA --stop-address=$((DISPATCHER_VA+8)) nvflash_unlocked
#   mov $0x1,%eax
#   ret
```

### Patch-point selection rules (generalize)
- **Prefer the dispatcher** (single chokepoint, covers both sn & pdi modes).
- If the dispatcher can't be isolated, patch **each matcher** entry the same way
  (`mov eax,1; ret`) — they're only used for the allow-list, so forcing
  "found/allowed" is safe.
- The dispatcher's return semantics is `1 = allowed`. If a given build inverts
  this (confirm from the consumer's `cmp/jne` vs `cmp/je`), patch to the value the
  flash branch requires.

---

## 9. Phase 8 — Verify what you did NOT break

The unlock must leave these enforced (they prevent bricking / are uncircumventable):

| Protection | Where | Must stay |
|---|---|---|
| **Board-ID / model match** | separate fn (`Board data is mismatch…`) | ✅ yes — don't touch |
| **ERoT firmware signature** | on-GPU root of trust | ✅ (can't bypass anyway) |
| **Anti-rollback** | `…FW_ROLLBACK_PROTECTION…`, `…rev is revoked` | ✅ yes |

Because the patch touches only the `UpdaterConfig` dispatcher, all of the above
are untouched by construction. Spot-check that the Board-ID string and signature
strings are referenced from functions *other* than the one you patched.

---

## 10. Phase 9 — Make the flasher runnable: the CLI dispatch gate

> **Do not skip this.** On the worked example, the serial patch alone left a
> binary that printed `Unknown command` for every real invocation. This phase is
> what turns it into a tool that actually flashes.

### 10.1 Recognize a restricted front-end

Run the (patched) binary and read `--dump` / `--help`:

```bash
sudo ./nvflash_unlocked --help        # note how FEW commands it lists
sudo ./nvflash_unlocked --dump        # read-only; identifies the payload
```

Tell-tales that you have a **restricted field-update front-end** over the full
engine, not the full `nvflash`:

- `--help` lists only a handful of **info** commands
  (`--help`, `--dump`, `--version`, `--licenseinfo`) — no `--list`, `--save`,
  `--index`, `--autoupdate`.
- `--dump` reports a **PLDM package** (`PLDM Package Version …`,
  `Component Identifier 0x….`) — these datacenter bundles are PLDM, driven by a
  thin updater front-end.
- The two personality strings `nvuflash` (restricted) and `nvflash_eng`
  (engine) both appear in the binary.
- Passing any engine flag (`--autoupdate`, `--list`, …) prints `Unknown command`
  even though the flag string exists in the binary (`strings | grep autoupdate`
  finds it). The vocabulary is compiled in but **not registered** as commands in
  this build.

### 10.2 Map the dispatcher

Find the top-level command dispatcher and decompile it. Anchor on the output
strings it owns:

```bash
strings -n 6 BUNDLE | grep -iEn \
 'Unknown command|attempt to update|already have updated|blank or empty|BIOS Versions'
```

Decompile the function that references `Unknown command` and the update banner
(`This utility will attempt to update the NVIDIA GPU firmware`). In the worked
example this is `FUN_0092406e`. Its logic is a simple cascade:

```c
if (parser->vtable[0x18]() != 0) { print "Unknown command"; usage(); return 5; }
if      (opt("help"))        usage();
else if (opt("licenseinfo")) license();
else if (opt("dump"))        dump_embedded_package();     // DAT = "dump"
else if (opt("version"))     print_adapter_versions();
else                         UPDATE_EMBEDDED_FIRMWARE();  // <-- the default action
```

Two facts drop out of this:

- **The firmware update is the `else` / default branch** — there is no named
  "flash" command. Any *recognized* invocation that isn't one of the four info
  commands flashes.
- A single **gate** runs first: `parser->vtable[0x18]()`. If it returns nonzero
  the tool prints `Unknown command` and exits **before** the update branch.

### 10.3 Identify the gate

Resolve the parser object's vtable (from its constructor) and read the method at
`+0x18`. In the worked example it is a one-line getter:

```asm
FUN_0057c719:  movzbl 0x60(%rdi),%eax ; ret    ; return parser->byte[0x60]
```

Byte `0x60` is the parser's **"unrecognized / no primary command"** flag. It is
set for a bare run and for any token not in the (runtime-built, so not
statically readable) command table — which is exactly why bare runs and engine
flags both yield `Unknown command`, and why the default UPDATE branch was
unreachable.

> How to find a vtable method's address generically (non-PIE): the ctor stores
> `obj->vtable = &VT`; read 8-byte function pointers at `VT + method_offset`.
> `VT[0x18/8] = VT[3]`. Then disassemble that address.

### 10.4 Patch the gate → make the update reachable

Force the gate to report "recognized" so every invocation reaches dispatch (the
four info commands are still matched first, so they keep working; everything
else — including a bare run — now falls through to the default UPDATE):

```python
off = va_to_off(src, GATE_VA)                 # 0x57c719 in the worked example
orig = bytes(data[off:off+5]); print(orig.hex(' '))   # 0f b6 47 60 c3
# return 0 in the 5 bytes available (movzbl is 4 bytes + ret):
data[off:off+4] = bytes([0x31,0xc0,0x66,0x90])        # xor eax,eax ; nop  (keep the c3 ret)
```

Verify:

```bash
objdump -d --start-address=GATE_VA --stop-address=$((GATE_VA+5)) nvflash_unlocked
#   xor %eax,%eax
#   xchg %ax,%ax        (the 66 90 nop)
#   ret
```

Generalization: the gate might instead be a real predicate (e.g. "count of
parsed commands == 0"). The goal is the same — make the dispatcher stop treating
your intended invocation as unknown. Prefer patching the **smallest** such
getter/predicate to `return 0` (or the value the recognized path needs) rather
than rewriting the dispatcher.

### 10.5 Confirm safely (no hardware flash)

You can confirm the gate is open **without risking a flash** by running the
patched binary **with the NVIDIA driver still loaded**:

```bash
sudo ./nvflash_unlocked          # driver loaded on purpose
```

- Before the patch: `Unknown command` + the short command list.
- After the patch: it proceeds past dispatch into the update / adapter-detection
  stage (the update banner, or a device-busy / "add-in graphics cards only"
  style message) — i.e. it no longer says `Unknown command`.

With the driver loaded the engine can't claim the device, so this proves the
trigger works but commits nothing. Only then unload the driver to flash for real.

---

## 11. Alternative: edit `sn_list` instead of patching code

Keeps per-serial targeting (safer — only flashes serials you list). Works because
the config digest is a **plain SHA-256** (no key):

```python
import hashlib, struct, json
data=bytearray(open("BUNDLE","rb").read())
magic=data.find(b'NVUF_JSON_CONFIG'); js=data.find(b'{',magic)
ln=struct.unpack_from('<I',data,js-4)[0]
cfg=json.loads(data[js:js+ln])
cfg["sn_list"]=["SERIAL_A","SERIAL_B"]           # your targets; keep restricted_mode sn_based
body=json.dumps(cfg, indent=4).encode()          # must reproduce the original formatting style
# rewrite length, digest, and body (only trivial if new length <= region; else shift carefully)
data[magic+16:magic+48]=hashlib.sha256(body).digest()
struct.pack_into('<I', data, js-4, len(body))
# splice body in place of old (requires equal length or relocating the trailing payload)
```

Caveat: if the new JSON length differs, you must preserve surrounding payload
layout (easier to pad/truncate `sn_list` to keep length, or just use the code
patch in §8). Only viable if the SHA-256 is the *only* integrity check over this
region (verify there is no outer package signature covering it).

---

## 12. One-glance checklist

**Part A — serial/PDI unlock**
1. `file`/`readelf` → ELF, stripped, huge `.data`, nvflash strings. Record `DELTA`.
2. Entropy-map `.data` → isolate the few-MB firmware payload (ignore zero-fill).
3. Find `NVUF_JSON_CONFIG` → extract JSON → read `restricted_mode` + `sn_list`/`pdi_list`.
4. `strings` → confirm `allow-list` / `UpdaterConfigMatcher` / `skipping` enforcement.
5. Install Ghidra + matching JDK (set `JAVA_HOME_OVERRIDE`); Java post-script only.
6. Decompile matchers (anchor on `NOT in allow-list`, `SN=`, `PDI=`).
7. `objdump | grep 'call <matcher>'` → the dispatcher. Raw-scan the `skipping`
   string's immediate → confirm the `cmp/jne` consumer gate.
8. Patch dispatcher prologue → `B8 01 00 00 00 C3` (`mov eax,1; ret`) on a copy.
9. `cmp -l` shows exactly 6 bytes; `objdump` shows `mov $1,%eax; ret`.

**Part B — make it runnable (don't skip)**
10. Run `--help`/`--dump`. Only info commands + a PLDM package ⇒ restricted
    front-end. Engine flags give `Unknown command` ⇒ the update is a blocked
    **default action**.
11. Decompile the dispatcher (anchor `Unknown command` + the update banner).
    Confirm: a first gate (`parser->vtable[0x18]()`) → `Unknown command`; the
    `else` branch is the firmware update.
12. Resolve that gate (vtable method / getter), patch it to `return 0`
    (e.g. `0f b6 47 60` → `31 c0 66 90`, keeping the `ret`).
13. Confirm with driver **loaded**: no more `Unknown command`; reaches
    update/detection.

**Both parts**
14. Confirm Board-ID / signature / rollback untouched. Record both patch offsets
    and the final sha256. Ship `nvflash_unlocked`.

## 13. Usage of the result

This build has no `--list`/`--index`/`--save`/`--autoupdate` — the update is the
**default action**:

```bash
sudo ./nvflash_unlocked --dump        # inspect embedded package (read-only, safe)
sudo ./nvflash_unlocked --version     # current adapter firmware versions (safe)

# flash the embedded firmware (root, NVIDIA driver unloaded):
sudo ./nvflash_unlocked               # bare run = default = UPDATE
```

The config has `no_confirm:true`, so once a matching board is detected it flashes
**without prompting**. Wrong-model boards are rejected by the Board-ID check;
altered firmware is rejected by the GPU ERoT. If the build *does* expose a save
command, back up first; this restricted front-end does not, so rely on the
model/ERoT checks and run only on correct-model hardware.

> If a target bundle instead exposes the full engine (`--list`, `--index`,
> `--save`, `--autoupdate` all present and working), use the classic flow —
> `--index=N --save backup.rom` then `--index=N --autoupdate` — and Phase 9 is
> unnecessary. Check which kind you have **first** (step 10).

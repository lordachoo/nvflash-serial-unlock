#!/usr/bin/env python3
"""
nv_unlock.py — patch an NVIDIA nvflash field-update bundle (the "9802810007"
family) to remove its per-board serial lock.

Two independent patches are known (see SERIAL_UNLOCK_PLAYBOOK.md /
decomp/PATCH_PROOF.txt):

  [serial]  allow-list unlock  — flash ANY board of this model (ignore sn_list).
                                  THIS is the serial-number check being stripped.
  [enabler] CLI dispatch gate   — make a bare run reach the default UPDATE path
                                  instead of printing "Unknown command". This is
                                  NOT a protection and does NOT touch the board
                                  check; on the restricted field-update front-end
                                  the tool otherwise can't flash at all. On a
                                  full-engine bundle it is unnecessary.

What is NEVER touched (so it stays enforced): the model / Board-ID match, the
PCI-ID / board compatibility check, the GPU ERoT firmware-signature check, and
anti-rollback. A wrong-model board is rejected (not bricked) and only genuine
NVIDIA-signed firmware is accepted. Use only on hardware you own.

Each site is found by a UNIQUE byte-signature, not a fixed offset, so this also
handles a byte-identical re-release (e.g. the same updater carrying firmware for
a different PCI ID / VBIOS). Patches are INDEPENDENT: each is applied if its site
is found, skipped-with-a-warning if not — a missing site never blocks the others,
and never corrupts the file.

Usage:
  ./nv_unlock.py BUNDLE [-o OUT] [--serial-only] [--verify] [--overwrite]

  BUNDLE          input bundle (e.g. 9802810007). Never modified in place.
  -o/--output     output path (default: <BUNDLE>_unlocked)
  --serial-only   apply only the serial allow-list unlock (leave the CLI gate
                  alone) — for a full-engine bundle that already runs and only
                  needs the serial lock removed
  --verify        dry run: report what would happen, write nothing
  --overwrite     allow overwriting an existing output file

Exit codes: 0 = something was applied (or already applied);
            2 = none of the selected sites could be applied safely;
            3 = usage / IO error.
"""
import argparse
import hashlib
import os
import sys

KNOWN_ORIGINAL_SHA256 = "12978284cb4fe6ceaaf05519e16af0875f1047008abf9612dd2fd29b0084a51c"
KNOWN_PATCHED_SHA256 = "912f0d74c962d55fa0c30e41e2711c9332562b3bd3f03bdf9ed2cdf700d04d3c"

# Each patch is located by a unique `locator` signature; `replace` overwrites the
# first len(replace) bytes of the match. `already` is the signature present once
# the patch is applied (for idempotency). Values are hex strings.
PATCHES = [
    {
        "kind": "serial",
        "name": "serial allow-list unlock",
        "detail": "FUN_0056b872 dispatcher -> mov eax,1; ret (always \"allowed\")",
        "locator": "41564155415455534883ec10488b47084885c00f84b60000",
        "replace": "b801000000c3",
        "already": "b801000000c355534883ec10488b47084885c00f84b60000",
    },
    {
        "kind": "enabler",
        "name": "CLI dispatch gate",
        "detail": "FUN_0057c719 getter -> xor eax,eax; nop; ret (always \"recognized\")",
        "locator": "0fb64760c3488b4768c3",
        "replace": "31c06690",
        "already": "31c06690c3488b4768c3",
    },
]


def sha256(b: bytes) -> str:
    return hashlib.sha256(b).hexdigest()


def find_unique(data: bytes, sig: bytes):
    """Return (offset, 1) if sig occurs exactly once, else (None, count)."""
    first = data.find(sig)
    if first < 0:
        return None, 0
    count = 1
    i = data.find(sig, first + 1)
    while i >= 0:
        count += 1
        i = data.find(sig, i + 1)
    return (first, 1) if count == 1 else (None, count)


def plan_patch(data: bytes, p: dict) -> dict:
    locator = bytes.fromhex(p["locator"])
    replace = bytes.fromhex(p["replace"])
    already = bytes.fromhex(p["already"])

    off, cnt = find_unique(data, locator)
    if off is not None:
        cur = data[off:off + len(replace)]
        want = locator[:len(replace)]
        if cur != want:
            return {"patch": p, "state": "mismatch",
                    "msg": f"bytes at site are {cur.hex()} (expected {want.hex()})"}
        return {"patch": p, "state": "apply", "offset": off,
                "before": cur.hex(), "after": replace.hex()}

    aoff, acnt = find_unique(data, already)
    if aoff is not None:
        return {"patch": p, "state": "done", "offset": aoff}
    if acnt > 1:
        return {"patch": p, "state": "ambiguous", "msg": f"post-patch signature x{acnt}"}
    if cnt > 1:
        return {"patch": p, "state": "ambiguous", "msg": f"locator signature x{cnt}"}
    return {"patch": p, "state": "missing"}


def main() -> int:
    ap = argparse.ArgumentParser(
        description="Strip the serial lock from an NVIDIA nvflash field-update bundle.")
    ap.add_argument("bundle", help="input bundle (e.g. 9802810007)")
    ap.add_argument("-o", "--output", help="output path (default: <bundle>_unlocked)")
    ap.add_argument("--serial-only", action="store_true",
                   help="apply only the serial allow-list unlock (leave the CLI gate alone)")
    ap.add_argument("--verify", action="store_true", help="dry run; write nothing")
    ap.add_argument("--overwrite", action="store_true", help="allow overwriting output")
    args = ap.parse_args()

    selected = {"serial"} if args.serial_only else {"serial", "enabler"}

    if not os.path.isfile(args.bundle):
        print(f"error: not a file: {args.bundle}", file=sys.stderr)
        return 3
    data = bytearray(open(args.bundle, "rb").read())
    src_sha = sha256(bytes(data))

    print(f"input   : {args.bundle}")
    print(f"size    : {len(data):,} bytes")
    print(f"sha256  : {src_sha}")
    if src_sha == KNOWN_ORIGINAL_SHA256:
        print("          (matches known original 9802810007)")
    elif src_sha == KNOWN_PATCHED_SHA256:
        print("          (this is the known fully-patched binary)")
    print(f"selected: {', '.join(sorted(selected))}")
    print()

    applied = 0
    already = 0
    skipped_sites = 0
    enabler_needed_note = False

    for p in PATCHES:
        name, kind, detail = p["name"], p["kind"], p["detail"]
        pl = plan_patch(data, p)
        st = pl["state"]

        if kind not in selected:
            # Not selected. If it's the enabler and its unpatched site is present,
            # the resulting binary will still say "Unknown command" on this build.
            if kind == "enabler" and st == "apply":
                enabler_needed_note = True
            print(f"[ ] {name} [{kind}]: not selected (skipped)")
            print()
            continue

        if st == "apply":
            off = pl["offset"]
            data[off:off + len(bytes.fromhex(p["replace"]))] = bytes.fromhex(p["replace"])
            applied += 1
            print(f"[+] {name} [{kind}]: PATCHED @ file 0x{off:x}")
            print(f"      {detail}")
            print(f"      {pl['before']}  ->  {pl['after']}")
        elif st == "done":
            already += 1
            print(f"[=] {name} [{kind}]: already applied @ file 0x{pl['offset']:x}")
        elif st == "missing":
            skipped_sites += 1
            print(f"[!] {name} [{kind}]: site not found — not present in this build. Skipping.")
        elif st == "ambiguous":
            skipped_sites += 1
            print(f"[!] {name} [{kind}]: AMBIGUOUS ({pl['msg']}) — skipping (won't guess).")
        elif st == "mismatch":
            skipped_sites += 1
            print(f"[!] {name} [{kind}]: unexpected bytes ({pl['msg']}) — skipping.")
        print()

    if applied == 0:
        if already > 0:
            print("Nothing to apply: selected patch(es) already present.")
            return 0
        print("Aborting: none of the selected patch sites could be applied.")
        print("This build differs; derive offsets via SERIAL_UNLOCK_PLAYBOOK.md.")
        return 2

    if enabler_needed_note:
        print("note: you ran serial-only, but this looks like a restricted front-end")
        print("      whose CLI gate is still closed — the result may still print")
        print("      \"Unknown command\" and be unable to flash. Run without")
        print("      --serial-only to also apply the CLI dispatch gate.")
        print()

    if args.verify:
        print(f"--verify: {applied} patch(es) would be applied. No file written.")
        return 0

    out = args.output or (args.bundle + "_unlocked")
    if os.path.abspath(out) == os.path.abspath(args.bundle):
        print("error: refusing to overwrite the input in place; choose -o OUTPUT", file=sys.stderr)
        return 3
    if os.path.exists(out) and not args.overwrite:
        print(f"error: output exists: {out} (use --overwrite)", file=sys.stderr)
        return 3

    with open(out, "wb") as f:
        f.write(data)
    os.chmod(out, 0o755)
    out_sha = sha256(bytes(data))
    print(f"wrote   : {out}  ({applied} applied, {already} already, {skipped_sites} skipped)")
    print(f"sha256  : {out_sha}")
    if out_sha == KNOWN_PATCHED_SHA256:
        print("          (matches known-good fully-patched 9802810007 — verified)")
    print()

    # Is the CLI dispatch gate open in the final binary? (applied, already, or the
    # build never had a closed gate — i.e. a full engine.)
    enabler = next(p for p in PATCHES if p["kind"] == "enabler")
    gate_closed = find_unique(bytes(data), bytes.fromhex(enabler["locator"]))[0] is not None

    name = os.path.basename(out)
    print("Usage (root, NVIDIA driver unloaded):")
    print(f"  sudo ./{name} --dump      # inspect (safe)")
    if gate_closed:
        print(f"  sudo ./{name} ...         # NOTE: CLI gate still closed — a bare run will")
        print("                            print \"Unknown command\". Re-run without")
        print("                            --serial-only to open it, or drive it the way")
        print("                            this build expects.")
    else:
        print(f"  sudo ./{name}             # bare run = flash embedded firmware")
    return 0


if __name__ == "__main__":
    sys.exit(main())

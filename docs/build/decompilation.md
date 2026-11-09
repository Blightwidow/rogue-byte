# Decompilation workflow

Goal: rebuild as much of Sly 2 as possible as C/C++ named like the Sly 1 decomp (Sucker Punch's names), then match each
function byte for byte (`src/`). ProjectCane (no license) is reference reading only, see THIRD_PARTY_NOTICES.md.

## Inputs

1. `-readOnly -postScript ExportDecompiled.java work/export/sly2_decompiled.jsonl`: Ghidra's C for every function, with the
   project's names and types ([name-recovery.md](name-recovery.md) builds the project).
2. `python3 scripts/names/modules.py config/recovered/`: the modules, after Sly 1's source files (the decomp's splat layout,
   `config/sly1/sly1.yaml`; file offset + 0xFF000 = address) carried over by the matches, `new_*` for Sly 2-only runs, `a+b` at
   file boundaries, `sdk`. Writes `config/recovered/modules.tsv`, which `make config` turns into the units
   ([modules-and-units.md](../game/modules-and-units.md)).
3. Struct layouts and prototypes: `config/recovered/sly2_structs.h` and `config/recovered/sly2.h` (see [name-recovery.md](name-recovery.md)).
   They are Ghidra's layouts (gaps, `field_0x...`), unverified, and no source includes them. Most sources in `src/` still declare
   their own padded copies; shared types move to `include/`, starting from these layouts ([ROADMAP.md](../ROADMAP.md) "Next", item 1).

## Matching a function

1. Pick one: `python3 scripts/list_functions.py --status asm --sort size`.
2. Draft it from Ghidra's C or from [m2c](https://github.com/matt-kempster/m2c) output (`include/m2c_macros.h`).
3. Compile and compare with the original compiler: `scripts/matching/judge.sh` (one command per function) or
   `scripts/matching/try.py <address> <file>`; setup in [compiler-identification.md](compiler-identification.md). The compare
   masks relocated fields and prints a side-by-side diff until the bytes are equal (`score 0`).
4. Land with `make land ONLY="0x<address>"` (from your working copy in `data/matching/src/fn`, git-ignored; it publishes through
   `export_src.py` and runs `make elf`), then `make unit UNIT=<module>`: the function must link from C and the image must still pass
   the byte check ([AGENT_WORKFLOW.md](../AGENT_WORKFLOW.md) "Land").

## Disassembly helpers

- `scripts/decompile/ee_dis.py`, `vu_dis.py`: decode the EE's VU0 macro instructions (lane masks, MMI words) and VU1 microcode, which Ghidra and
  most disassemblers leave as raw words.

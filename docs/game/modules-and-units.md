# Modules and units

The game code is cut into **modules**: runs of consecutive functions that came from one source file. A module is named after the
Sly 1 source file the code matcher placed the run in (`config/recovered/modules.tsv`, built by `scripts/names/modules.py` from
the Sly 1 decompilation's file layout, `config/sly1/sly1.yaml`):

| Name | Meaning |
| :--- | :--- |
| `<name>` | A run that matches a Sly 1 file of that name (`mat`, `step-rwm`, `memcard`, …) |
| `<a>-<b>` | A run across the boundary of two Sly 1 files, as the matcher could not tell where one ends |
| `new_<address>` | A run of Sly 2-only code (no Sly 1 counterpart), named by its first address |
| `sdk` | Sony's SDK libraries (`0x2319e8`–`0x256c58`), not part of the game's own code |

## Units

`make config` turns the runs into **units** (`scripts/build/gen_splat_config.py`): one assembly file per run,
`build/splat/asm/<module>.s`, with a `_<address>` suffix on the second and later runs of one module. A unit has:

- its code in `build/splat/asm/<module>.s`,
- its rodata and data in `build/splat/asm/data/{rodata,data}/<module>.*.s`. The pieces are cut by ownership: each address the code
  names goes to the first unit, in code order, that refers to it, and a run of one owner becomes one piece
  (`config/us/pieces.tsv`). The rule is a heuristic, so a piece's name can be wrong while its bytes cannot,
- its matched C in `src/<module>/`, one function per file, listed in `src/MANIFEST.tsv`.

`make objdiff` writes one objdiff unit per module, so the same names line up in the progress map, the objdiff report and `src/`.

## Function chunks

Splat writes each function as a chunk that starts at `.align 3`, but it does not always cut where a function starts: a function can
sit inside another chunk, or follow a function without a label of its own. `scripts/build/asm_units.py` therefore also cuts the
chunks at the start of every matched function and at its end (padded to 8 bytes), so a compiled function replaces exactly its
own bytes.

## Status of a function

| Status | Meaning |
| :--- | :--- |
| `c` | Compiled from `src/` in the verified image |
| `matched` | Matched, but the image still uses assembly for it |
| `asm` | Not matched yet |

[progress.md](../build/progress.md) says how the numbers are counted.

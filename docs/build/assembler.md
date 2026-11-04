# The assembler: Sony's `ee/bin/as.exe`

Compiled C goes through SN's EE-GCC 2.95.3 with `-S`, and then through **`tools/ee-as/as.exe`**: GNU as 2.9-ee-991111b as Sony ships it,
the assembler the compiler driver runs. It is the one assembler of the build, as in sly1-decomp: there is no per-function choice.
`setup.sh --assembler` downloads it (pinned commit and SHA-256, from a public mirror of Sony's SDK 2.4 tools; never committed).

What it does that a modern GNU `as` does not:

- `move` becomes `daddu`, as in retail (a modern GNU as writes `or`).
- It puts no `nop` between `mtc1` and the instruction that reads the register (`li.s`, `cvt.s.w`).
- It reaches a global through `$gp` only when it has already seen the symbol's size, so `compile_unit.py` moves the compiler's
  `.extern SYM,SIZE` lines (written at the end of the file) to the top before assembling.

`scripts/build/compile_unit.py` compiles one source, moves the `.extern` lines up, assembles with `as.exe -G0 -O2` under wibo and makes
the symbols local. Everything that compiles a source uses it: the ninja rules of `configure.py` (`src/` and `nonmatching/`) and
`scripts/matching/try.py`, the per-function judge. If `as.exe` is missing the compile fails and says to run `./setup.sh --assembler`.
Only the SDK range (`config/us/sony_gcc29.txt`) is built differently: Sony's own ee-gcc 2.9-ee-991111 and the driver's `as.exe`.

## What it replaced, and why (2026-11-04)

Until 2026-11-04 the build used `ps2eeas` (SN's own assembler, `Ps2EeAs.exe` 1.9.25.758, from a mirror of the SN ProDG 3.01 tools), plus
three per-function exceptions. They were measured, worked, and were removed because they break AGENTS.md's "one flag set per source
file, never per function" and, for one of them, patch a binary:

| What | What it did | Why it went |
| :--- | :--- | :--- |
| `ps2eeas` as the default | Adds R5900 hazard nops (after `mtc1`, before `bc1`), pads backward-branch loops shorter than six instructions, uses its own `dli` sequences. Matched 3,473 of 3,526 sources when it went in (2026-10-28). | sly1-decomp assembles everything with `ee/bin/as.exe`; same tooling, same tradeoffs. On 120 random matched functions `ps2eeas` and `as.exe` agreed on 109; `as.exe` lost 4 (scores 2, 8, 7, 3) and gained 1. |
| `config/us/gnu_as.txt` (385 functions) | Assembled the functions that only matched with the driver's GNU `as` (a five-instruction loop retail left unpadded is the typical case). | A per-function assembler is a tool chosen to fit the result, not what the original build did. |
| `Ps2EeAs-loop5.exe` + `config/us/ps2eeas_loop5.txt` (128 functions) | `Ps2EeAs.exe` with one byte at file offset 0x4DEB changed from 6 to 5, so loops are padded to five instead of six (retail's shortest loop is five instructions before the delay slot). | A patched binary that exists only to reproduce bytes. Not what the original build ran. |
| `fill_vu_delay_slots` | Moved a VU0 instruction into a branch delay slot in the compiler's assembly, because `ps2eeas` would not. | Only needed by inline VU0 asm, which AGENTS.md no longer allows. |

The functions that only matched through those exceptions (and the 4 that lost to `as.exe`) are unmatched again: they are built from the
original assembly and their best compiling source, if any, is in `nonmatching/`. The old assembler's findings come from the Ratchet &
Clank 1 decompilation ([OpenRAC/rac1-decomp](https://github.com/OpenRAC/rac1-decomp), GPL-3.0, `docs/BUILD_FIDELITY.md`); nothing was
copied. History of the measurements: git history of this file before this commit.

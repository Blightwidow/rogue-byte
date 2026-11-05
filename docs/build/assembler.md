# The assembler: SN's `ps2eeas`

Compiled C goes through SN's EE-GCC 2.95.3 with `-S`, and then through **`tools/ps2eeas/Ps2EeAs.exe`**: SN Systems' own assembler (1.9.25.758,
from the SN ProDG 3.01 tools), the one SN's ProDG driver runs. It is the one assembler of the build, **unpatched**, with **no per-function
list**. `setup.sh --assembler` downloads it (pinned commit and SHA-256, from a public mirror of the SN ProDG 3.01 tools; never committed).

What it does that other assemblers do not:

- `move` becomes `daddu`, as in retail (a modern GNU as writes `or`).
- It puts a hazard `nop` between `mtc1` and the instruction that reads the register, **only when the next instruction reads it**. Sony's
  `bin/ee-as.exe` puts one after every `mtc1`; Sony's `ee/bin/as.exe` puts none. In every function examined, retail has the `nop` where
  `ps2eeas` puts it.
- It puts a `nop` between a float compare and `bc1`, and pads backward-branch loops shorter than six instructions up to six (the R5900
  short-loop erratum).
- It reaches a global through `$gp` only when it has already seen the symbol's size, so `compile_unit.py` moves the compiler's
  `.extern SYM,SIZE` lines (written at the end of the file) to the top before assembling.

`scripts/build/compile_unit.py` compiles one source, moves the `.extern` lines up, assembles with `Ps2EeAs.exe -G0` under wibo and makes the
symbols local. Everything that compiles a source uses it: the ninja rules of `configure.py` (`src/` and `nonmatching/`) and
`scripts/matching/try.py`, the per-function judge. If the assembler is missing the compile fails and says to run `./setup.sh --assembler`.
Only the SDK range (`config/us/sony_gcc29.txt`) is built differently: Sony's own ee-gcc 2.9-ee-991111 and its driver.

## The decision record

The assembler changed three times, each time from a measurement. This page keeps the reasons so the choice is not made again from
memory.

| Period | Assembler | What happened |
| :--- | :--- | :--- |
| until 2026-11-04 | `Ps2EeAs.exe`, plus `Ps2EeAs-loop5.exe` (one byte of the binary changed, 6 to 5, so short loops pad to five), `config/us/gnu_as.txt` (385 functions on the driver's GNU `as`) and `config/us/ps2eeas_loop5.txt` (128 functions) | Matched 5,057 functions once inline asm was banned. The patched binary and the lists break "one flag set per source file" (AGENTS.md): they choose the tool per function to fit the result. |
| 2026-11-04, hours | Sony's `ee/bin/as.exe`, the assembler sly1-decomp uses for Sly 1 | Chosen to follow sly1. On 120 random matched functions it lost 4 and gained 1 against `ps2eeas`; re-judging all 5,057 lost 221. It puts no `nop` after `mtc1`. |
| 2026-11-04 to 05 | Sony's `bin/ee-as.exe`, the other build of the same release | Fixed the missing `nop` (10 of 14 testable `nop`-wall functions matched; 87 of the 221 came back; 33 of 4,846 matched functions regressed). But it puts a `nop` after every `mtc1`, treats an odd/even FP register pair as a hazard that retail does not, and pads short loops differently: wave N1 (near misses at score 1 to 2) found them stopped there. |
| 2026-11-05, now | `Ps2EeAs.exe`, **unpatched, no lists** | See below. |

**Measured, same sources, same compiler and flags (2026-11-05):**

| Group | `bin/ee-as.exe` | unpatched `Ps2EeAs.exe` |
| :--- | ---: | ---: |
| 70 near misses scoring 1 to 2 | 0 at score 0 | 35 |
| 33 functions the first switch had demoted | 0 | 27 |
| 18 functions stopped by the missing `nop` | 8 | 9 |
| matched functions (sample of 120, 77 with a source) | 76 | 75 |

All 4,912 matched functions were then re-judged with it: 63 (1.3%) no longer score 0 and were demoted, and `record.py` registered 91 new
matches. One of the 91 held inline asm and twelve carry raw `M2C_UNK` offsets, which the cleanup rules ban in added code; they are
parked, not matched. Net: 78 new matches.

**Why it is not the same as before.** The earlier objection was to the patched binary and to the lists, not to `ps2eeas`. Used alone, as
shipped, it follows the one-assembler rule. The functions that needed `gnu_as.txt` (385) or the loop patch (128) now stay unmatched unless
plain C reproduces them with this one assembler.

**Why sly1-decomp differs.** sly1-decomp assembles Sly 1 with Sony's `ee/bin/as.exe` and measured that `bin/ee-as.exe` does not match its
retail (two functions, `func_00158108` and `func_001A7290`); it also measured `ps2eeas` for its math library and found it does not give
those bytes. Sly 1's retail has no `nop` after `mtc1`. Sly 2's retail does, in the places `ps2eeas` puts it (`UpdateTask`, `UpdateSo`,
`GRandInRange`, and the near misses above). The two games were evidently built with different assembler builds, so this repository
follows its own binary, not sly1's choice. If a later measurement shows `ee/bin/as.exe` matches more of Sly 2, change this page first.

**What `ps2eeas` is not.** It is not proven to be the original assembler: that is inferred from the SN ProDG driver and from the matches.
The measurements above are the evidence; a build whose bytes differ from retail would show it.

## Things the old setups did that are gone

- **`Ps2EeAs-loop5.exe` and the lists** `gnu_as.txt` and `ps2eeas_loop5.txt`, and their scan scripts.
- **`fill_vu_delay_slots`**, which moved a VU0 instruction into a branch delay slot because `ps2eeas` would not. Only inline VU0 asm needed
  it, which AGENTS.md no longer allows ([vu0-mmi.md](vu0-mmi.md)).
- **`tools/ee-as/ee-as.exe`** (local, unused): Sony's `bin/ee-as.exe` is no longer part of `setup.sh`.

## Reference

The first measurements of `ps2eeas` behaviour came from the Ratchet & Clank 1 decompilation
([OpenRAC/rac1-decomp](https://github.com/OpenRAC/rac1-decomp), GPL-3.0, `docs/BUILD_FIDELITY.md`); nothing was copied. sly1-decomp's
assembler notes are in its `docs/TOOLCHAIN.md`. History of the earlier measurements: git history of this file.

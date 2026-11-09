# The assembler: SN's `ps2eeas`

Compiled C goes through SN's EE-GCC 2.95.3 with `-S`, and then through **`tools/ps2eeas/Ps2EeAs-loop5.exe`** (made by `setup.sh` from `Ps2EeAs.exe`): SN Systems' own assembler (1.9.25.758,
from the SN ProDG 3.01 tools), the one SN's ProDG driver runs. It is the one assembler of the build for game code, with **one byte changed** (its short-loop constant, see "Short loops") and **no per-function
list**. `setup.sh --assembler` downloads it (pinned commit and SHA-256, from a public mirror of the SN ProDG 3.01 tools; never committed).

What it does that other assemblers do not:

- `move` becomes `daddu`, as in retail (a modern GNU as writes `or`).
- It puts a hazard `nop` between `mtc1` and the instruction that reads the register, **only when the next instruction reads it**. Sony's
  `bin/ee-as.exe` puts one after every `mtc1`; Sony's `ee/bin/as.exe` puts none. In every function examined, retail has the `nop` where
  `ps2eeas` puts it.
- It puts a `nop` between a float compare and `bc1`, and pads backward-branch loops that are too short (the R5900
  short-loop erratum): to six instructions in the pinned binary, to five in the build's copy ("Short loops").
- It reaches a global through `$gp` only when it has already seen the symbol's size, so `compile_unit.py` moves the compiler's
  `.extern SYM,SIZE` lines (written at the end of the file) to the top before assembling.

`scripts/build/compile_unit.py` compiles one source, moves the `.extern` lines up, assembles with `Ps2EeAs-loop5.exe -G0` under wibo and makes the
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
| 2026-11-05, morning | `Ps2EeAs.exe`, unpatched, no lists | See below. It left the short-loop padding one `nop` too long: 96 of the 366 drafts at score 1 to 16 stopped there (wave N2). |
| 2026-11-05, now | `Ps2EeAs.exe` with one byte changed (`Ps2EeAs-loop5.exe`), for all game code, no lists | "Short loops" has every assembler tried and why. |

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

**Why it is not the same as before.** The earlier objection was to the patched binary and to the lists. The lists stay removed: the 385
functions of `gnu_as.txt` stay unmatched unless plain C reproduces them with the one assembler. The patched binary is back in a different
role: not chosen per function, but the one assembler of all game code, after the loop table in "Short loops" showed that retail pads every short
loop to five (240 of 240) and that no assembler release we could run does. The 128 functions of `ps2eeas_loop5.txt` need no list now.

**Why sly1-decomp differs.** sly1-decomp assembles Sly 1 with Sony's `ee/bin/as.exe` and measured that `bin/ee-as.exe` does not match its
retail (two functions, `func_00158108` and `func_001A7290`); it also measured `ps2eeas` for its math library and found it does not give
those bytes. Sly 1's retail has no `nop` after `mtc1`. Sly 2's retail does, in the places `ps2eeas` puts it (`UpdateTask`, `UpdateSo`,
`GRandInRange`, and the near misses above). The two games were evidently built with different assembler builds, so this repository
follows its own binary, not sly1's choice. If a later measurement shows `ee/bin/as.exe` matches more of Sly 2, change this page first.

**What `ps2eeas` is not.** It is not proven to be the original assembler: that is inferred from the SN ProDG driver and from the matches.
The measurements above are the evidence; a build whose bytes differ from retail would show it.

## Short loops

The R5900 has a hardware erratum: a very short loop can run only once or twice
([frno7 wiki](https://github.com/frno7/linux/wiki/R5900-short-loop-erratum); GNU as has `-mfix-r5900` for it). SN's assembler works around it
by putting `nop`s before the backward branch of any loop it finds too short. Sly 2's retail code shows the same padding, and it is the
one place where the assembler of this build differed from the one that built retail, so this page keeps everything measured about it.

**Terms.** "Loop length" is the number of instructions from the loop head through the branch, the delay slot not counted. "Words before the
branch" is that minus one.

### What retail does

Every backward conditional branch whose loop is 2 to 7 instructions long, in the game code (outside the SDK range 0x2319E8-0x256CE8),
counted from the retail executable (`work/elf/SCUS_973.16`), by what the loop holds:

| Contents | 5 long | 6 long | 7 long |
| :--- | ---: | ---: | ---: |
| no call, one branch | 104 | 82 | 23 |
| no call, other branches inside | 76 | 22 | 42 |
| a call, one branch | 56 | 9 | 25 |
| a call, other branches inside | 4 | 3 | 13 |

No loop is shorter than five, in any row: 240 loops sit at exactly five. So retail's assembler pads every short loop to five instructions
whatever the loop holds (calls, inner branches, delay-slot content). In the SDK range some loops are shorter (Sony's own toolchain built it).

### Every assembler we ran

Synthetic loops of one to seven `addu` instructions closed by `bne` plus a delay slot, in the `.set noreorder` form gcc writes, assembled by
each build; the table gives the words before the branch the assembler left (a loop that needs no padding keeps its own length). The result is
the same with and without a filled delay slot, at any alignment (gcc puts `.p2align 3` before loop heads) and in reorder mode.

| Assembler | Body of 1 to 5 instructions pads to (words before the branch) | Loop length | Source |
| :--- | :---: | :---: | :--- |
| **retail** | **4** | **5** | the table above |
| `ps2eeas` 1.9.25.758 | 5 | 6 | SN ProDG 3.01 (the pinned download, the build's base) |
| `ps2eeas` 1.9.6.516 | 5 | 6 | SDK 2.4 mirror, `ee/bin/ps2eeas.exe` |
| `ps2eeas` 1.8.19.316 | none | none | SN 2.95.2 (273a) toolchain |
| `ee/bin/as.exe` (May 2001) | 5 | 6 | SDK 2.4 mirror |
| `bin/ee-as.exe`, GNU as 2.9-ee-991111b | none | none | SDK 2.4 mirror |
| GNU as 2.9-ee-990721, 2.9-ee-991111 | none | none | decompme/compilers (Linux, run under Docker) |
| GNU as 2.9-ee-991111-01, 2.9-ee-991111a | 5 | 6 | decompme/compilers |
| GNU as 2.10-ee-001003-1 | error: "problematic short loop for Emotion Engine in noreorder section" | | decompme/compilers (`ee-gcc2.96`) |
| GNU as 2.12-ee-030926, 2.12-ee-040921 | 5 | 6 | decompme/compilers (gcc 3.2) |
| gcc 3.2 beta2 `as.exe` | 7 | 8 | decompme/compilers |
| **`ps2eeas` 1.9.25.758, byte 0x4DEB changed 6 to 5** | **4** | **5** | this build |

`ps2eeas --help` has no option for it (`-sn` and `-no-align` leave the result unchanged in a probe of the near misses and 60 matched
functions). Other releases in the two public mirrors (SN ProDG for PS2 3.01, SDK 2.4) are the ones above; none pads to five.

### What it did to the matches

`scripts/matching/assembler_probe.py` on the near misses (best draft score 1 to 5, 169 or 170 of them) and a seeded sample of matched
functions:

| Candidate | Near misses at score 0 (build alone: 0) | Matched functions lost |
| :--- | ---: | ---: |
| `ps2eeas` 1.9.6.516 | 0 | 0 of 100 |
| `ps2eeas` 1.8.19.316 | 41 | 2 of 500 |
| **1.9.25.758 with the constant at 5** | **91** | **0 of 300** |

Of the 84 drafts in the probe that stopped at one extra `nop` before a backward branch (found from their `try.py` diffs), 1.8.19.316
fixed 35 (loops retail leaves unpadded because they are already long enough) and the patched constant fixed all 84. Re-judging all 4,937
matched functions of the day with the patched copy: 0 no longer score 0. The landing that followed registered 103 new matches (22,008 bytes) and parked 16 more that score 0 but break the cleanup rules (14 raw `M2C_UNK` offsets, 2 padding locals).

### What other decompilations of the same toolchain say

- **Ratchet & Clank 1** ([rac1-decomp](https://github.com/OpenRAC/rac1-decomp), `docs/reference/DECOMP_PROGRESS.md`, "SOLVED: the short-loop
  erratum") found that `ps2eeas` pads every backward-branch loop shorter than six instructions up to six, in reorder and noreorder code,
  and that the driver's `ee/bin/as.exe` pads loops that hold no call, while `bin/ee-as.exe` pads nothing. It models the padding in a
  post-processor (`tools/ps2eeas_nops.py`) in front of GNU as, and has no per-function flags. Its six matches our 1.9.25.758; Sly 2's five
  is one less.
- **Ratchet & Clank 3** ([rac3-uya-decomp](https://github.com/OpenRAC/rac3-uya-decomp), `docs/compiler_matrix_findings.md`) names
  `Ps2EeAs.exe` 1.9.25 as retail's assembler, chooses the assembler per address range (`@ps2as`, `@newas`, `@ee29`) and has a script
  that writes loop-closing branches as raw words to stop GNU as padding (the opposite problem: its retail has none).
- Neither records a threshold of five. Sly 2 appears to have been built with an assembler release that is not in the public mirrors.

### The decision (2026-11-05)

The build's assembler is `ps2eeas` 1.9.25.758 with one byte changed, for every game function. The reasons:

- Retail pads to five uniformly (the table above), so a constant is the whole rule: no loop shape, call or alignment decides it.
- No unpatched release of `ps2eeas`, Sony's GNU as or the 3.2 assembler pads to five (the table above), so the difference cannot be had
  from a build we can run.
- It is one assembler for all game code with no list, so it follows the rule against choosing the tool per function to fit the result
  (the lists `gnu_as.txt` and `ps2eeas_loop5.txt` that did that stay removed). The SDK range keeps its own toolchain
  (`config/us/sony_gcc29.txt`), as sly1-decomp does for Sony's libraries.
- It changes nothing that matched before (0 of 4,937 regress) and gains 103 matches that stopped at the padding.

The patched binary is derived from the pinned download and is made locally (`setup.sh`, or on first use by
`scripts/build/compile_unit.py`); it is never committed, and the make step refuses a download whose byte 0x4DEB is not the 6 of the
pinned build. **If a `ps2eeas` release that pads to five is ever found, switch back to it and delete the patch**; measure it with
`assembler_probe.py` first (below).

## Before changing the assembler

The assembler changed three times in one day on opinion and was measured only afterwards. Measure first:

1. `python3 scripts/matching/assembler_probe.py --assembler PATH [--args "-G0"]` scores the same sources with the build's assembler and
   the candidate (through `EE_AS_EXE`/`EE_AS_ARGS`, which `compile_unit.py` reads; no file changes): the near misses (best score 1 to 5) a
   better assembler could win, and a seeded sample of matched functions it must not lose.
2. If it wins the near misses and loses next to nothing, change `compile_unit.py` and `setup.sh`, then
   `python3 scripts/matching/rejudge.py --write` (every matched function, regressions parked) and `make land`.
3. Put the probe's numbers in the decision table above, and say what the change cost.

## Things the old setups did that are gone

- **The lists** `gnu_as.txt` and `ps2eeas_loop5.txt`, and their scan scripts. (The one-byte copy `Ps2EeAs-loop5.exe` is back, as the assembler of all game code and not as a list: "Short loops".)
- **`fill_vu_delay_slots`**, which moved a VU0 instruction into a branch delay slot because `ps2eeas` would not. Only inline VU0 asm needed
  it, which AGENTS.md no longer allows ([vu0-mmi.md](vu0-mmi.md)).
- **`tools/ee-as/ee-as.exe`** (local, unused): Sony's `bin/ee-as.exe` is no longer part of `setup.sh`.

## Reference

The first measurements of `ps2eeas` behaviour came from the Ratchet & Clank 1 decompilation
([OpenRAC/rac1-decomp](https://github.com/OpenRAC/rac1-decomp), GPL-3.0, `docs/BUILD_FIDELITY.md`); nothing was copied. sly1-decomp's
assembler notes are in its `docs/TOOLCHAIN.md`. History of the earlier measurements: git history of this file.

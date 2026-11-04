# The assembler: Sony's `bin/ee-as.exe`

Compiled C goes through SN's EE-GCC 2.95.3 with `-S`, and then through **`tools/ee-as/ee-as.exe`**: GNU as 2.9-ee-991111b, the
`bin/ee-as.exe` build in Sony's SDK. It is the one assembler of the build: there is no per-function choice. `setup.sh --assembler`
downloads it (pinned commit and SHA-256, from a public mirror of Sony's SDK 2.4 tools; never committed).

What it does that a modern GNU `as` does not:

- `move` becomes `daddu`, as in retail (a modern GNU as writes `or`).
- It puts the **hazard `nop`** between `mtc1` and the instruction that reads the register (`c.lt.s`, `cvt.s.w`, `add.s`, `swc1`), as Sly 2's
  retail code has it.
- It reaches a global through `$gp` only when it has already seen the symbol's size, so `compile_unit.py` moves the compiler's
  `.extern SYM,SIZE` lines (written at the end of the file) to the top before assembling.

`scripts/build/compile_unit.py` compiles one source, moves the `.extern` lines up, assembles with `ee-as.exe -G0 -O2` under wibo and
makes the symbols local. Everything that compiles a source uses it: the ninja rules of `configure.py` (`src/` and `nonmatching/`) and
`scripts/matching/try.py`, the per-function judge. If the assembler is missing the compile fails and says to run
`./setup.sh --assembler`. Only the SDK range (`config/us/sony_gcc29.txt`) is built differently: Sony's own ee-gcc 2.9-ee-991111 and its
driver.

## Why this one: the decision record (2026-11-04)

Three assemblers were used in turn. Each change came from a measurement.

| Period | Assembler | Result |
| :--- | :--- | :--- |
| until 2026-11-04 | `Ps2EeAs.exe` (SN's `ps2eeas`, from a mirror of the SN ProDG 3.01 tools), plus `Ps2EeAs-loop5.exe` (one byte of the binary changed, 6 to 5, so short loops pad to five instructions), `config/us/gnu_as.txt` (385 functions on the driver's GNU `as`) and `config/us/ps2eeas_loop5.txt` (128 functions) | Matched 5,057 functions once inline asm was banned. Removed because per-function assemblers and a patched binary break "one flag set per source file" (AGENTS.md) and exist to reproduce bytes, not because they failed. |
| 2026-11-04, hours | Sony's `ee/bin/as.exe` (the assembler sly1-decomp uses for Sly 1) | On 120 random matched functions it agreed with `ps2eeas` on 109, lost 4 and gained 1. Re-judging all 5,057 lost 221 (4.4%). It puts **no `nop` after `mtc1`**: that is right for Sly 1's retail and wrong for Sly 2's. |
| 2026-11-04, now | Sony's `bin/ee-as.exe` (same release, the other build in the SDK) | Hazard `nop` as in retail, no patched binary, no list. |

**The evidence that Sly 2 needs the `nop`.** Retail's `UpdateTask` (0x163B48), `UpdateSo` (0x1F36E0) and `GRandInRange` (0x11D448) have
`mtc1 $zero,$f0 ; nop ; c.lt.s` and `mtc1 $a0,$f1 ; nop ; cvt.s.w`. Eight Haiku workers on a wave of 83 small functions found about 40
of them stopped by that one `nop`, seven at a score of 1 to 3 with nothing else wrong. sly1-decomp documents the opposite for Sly 1:
`ee/bin/as.exe` matched there and `bin/ee-as.exe` did not (measured on two functions).

**What `bin/ee-as.exe` did when tried** (same sources, 2026-11-04):

| Group | Result |
| :--- | :--- |
| 14 functions that were walls for the missing `nop` (and had a source) | 10 went to score 0, 13 improved, 1 got worse |
| 221 functions the `ee/bin/as.exe` switch had demoted (212 with a source) | 87 went to score 0, 110 improved, 24 got worse |
| 70 matched functions (random sample with a source) | all 70 still score 0 |
| all 4,846 matched functions, re-judged | 33 (0.7%) no longer scored 0 and were demoted |
| every source, judged by `record.py` | 106 new matches; 7 held asm or register pins (old drafts that now happen to score 0) and were demoted |

Net: 4,846 to 4,912 matched functions. The 33 that regressed are mostly 1 to 4 words off; the cause was not investigated.

## Things the old setup did that are gone

- **Short-loop padding.** `ps2eeas` padded every backward-branch loop shorter than six instructions up to six, and its patched copy padded to
  five. Retail's game code has 238 backward branches of offset -5 and none shorter. How `ee-as.exe` pads such loops was not measured; a
  function whose loop padding differs stays unmatched and is not worked around.
- **`fill_vu_delay_slots`.** It moved a VU0 instruction into a branch delay slot because `ps2eeas` would not. Only inline VU0 asm needed it,
  which AGENTS.md no longer allows ([vu0-mmi.md](vu0-mmi.md)).
- **The per-function lists** `gnu_as.txt` and `ps2eeas_loop5.txt` and their scan scripts.

## Reference

The old assembler's behaviour was first measured by the Ratchet & Clank 1 decompilation
([OpenRAC/rac1-decomp](https://github.com/OpenRAC/rac1-decomp), GPL-3.0, `docs/BUILD_FIDELITY.md`); nothing was copied. The comparison
with Sly 1's assembler is in sly1-decomp's `docs/TOOLCHAIN.md`. History of the earlier measurements: git history of this file.

# The assembler: ps2eeas

Retail's code was compiled with SN's EE-GCC 2.95.3 and **assembled with SN's own assembler, `ps2eeas`**, not the GNU `as` that the
compiler driver calls. They differ where the R5900 needs help, and the differences show up as one or two instructions per function:

| What `ps2eeas` does | GNU `as` |
| :--- | :--- |
| A `nop` between `mtc1` and the instruction that reads the register (`mtc1 $v0,$f0 ; nop ; cvt.s.w`) | none |
| A `nop` between a float compare and `bc1` | only in some contexts |
| Pads every backward-branch loop shorter than six instructions up to six (the R5900 short-loop erratum) | pads only loops without a call, and counts the span differently |
| Its own instruction sequence for 64-bit constants (`dli`) | another sequence for many values |
| Uses `$gp` for a global only when it has already seen the symbol's size | uses `$gp` whenever the compiler says so |

(The first four are what the Ratchet & Clank 1 decomp measured against `ps2eeas`; see [reference](#reference). The last is why the
compiler's `.extern SYM,SIZE` lines, which it writes at the end of the file, are moved to the top before assembling.)

## What the build does

`scripts/build/compile_unit.py` compiles one source with `ee-gcc -S`, moves the `.extern` lines up, assembles the result with
`tools/ps2eeas/Ps2EeAs.exe` under wibo, and makes the symbols local. `setup.sh` downloads the assembler (pinned SHA-256, from a
third-party mirror of the SN ProDG 3.01 tools; it is never committed). Everything that compiles a source uses it: the ninja rules of
`configure.py` (`src/` and `nonmatching/`) and `scripts/matching/try.py`, the per-function judge.

If `Ps2EeAs.exe` is missing the same script falls back to GNU `as` and says nothing: the functions that need the nops then simply
do not match.

## `config/us/gnu_as.txt`

Not every retail function came out of `ps2eeas`: 53 of the 3,526 functions matched before the switch only match with GNU `as` (a loop
of five instructions that retail left unpadded is the typical case), as do 181 draft sources whose score is lower that way. They are
listed in `config/us/gnu_as.txt` and assembled with GNU `as` (`compile_unit.assembler_for(address)`). It is not a split by module. Two
rules explain most of it (measured on the matched sources: each rule has no `ps2eeas` function on its side):

- **A five-instruction loop in retail** (a backward branch with offset -5). `ps2eeas` pads such loops to six, so none of its functions
  has one; 31 matched GNU functions do. `scripts/matching/gnu_as_rule.py --write` adds every function of the split that has one.
- **An inline-asm block that ends with a VU0 instruction** (`qmfc2`, `qmtc2`, `sqc2`, `lqc2`, `v*`) right before a branch. GCC leaves
  that branch's delay slot to the assembler, retail's assembler moved the VU0 instruction into it and `ps2eeas` does not.
  `compile_unit.fills_delay_slot_from_asm` finds it in the compiler's output and picks GNU `as` for such a source by itself. (A block that
  ends in `mtc1` or `nop` is no sign: `ps2eeas` handles those.)

Together they cover about two thirds of the sources in the list; the rest (17 matched, 34 tried) was derived by scoring every source both
ways, and a few more functions were added when their rodata (a string or float literal, a jump table) linked differently out of
`ps2eeas`' object. `ps2eeas` itself hangs on some inputs, so `compile_unit.py` gives up on it after 60 seconds.

Measured when the assembler went in: of 3,526 matched sources 3,473 stayed exact with `ps2eeas`; of 2,313 non-matching sources 45
became exact, 269 got closer and 181 got worse (those are in the list). Add a function to the list when it only matches, or
only links, with GNU `as`.

## Reference

The findings come from the Ratchet & Clank 1 decompilation ([OpenRAC/rac1-decomp](https://github.com/OpenRAC/rac1-decomp), GPL-3.0),
whose `docs/BUILD_FIDELITY.md` and `tools/ps2eeas_nops.py` describe `ps2eeas`' behaviour and model it in Python. We run the real
assembler instead, as that project does to check its own tools. Nothing was copied.

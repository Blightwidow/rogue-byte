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
listed in `config/us/gnu_as.txt` and assembled with GNU `as` (`compile_unit.assembler_for(address)`). The rule behind the split is not
understood (it is not by module); the list was derived by scoring every source both ways, and a few more functions were added when
their rodata (a string or float literal, a jump table) linked differently out of `ps2eeas`' object.

Measured when the assembler went in: of 3,526 matched sources 3,473 stayed exact with `ps2eeas`; of 2,313 non-matching sources 45
became exact, 269 got closer and 181 got worse (those are in the list). Add a function to the list when it only matches, or
only links, with GNU `as`.

## Reference

The findings come from the Ratchet & Clank 1 decompilation ([OpenRAC/rac1-decomp](https://github.com/OpenRAC/rac1-decomp), GPL-3.0),
whose `docs/BUILD_FIDELITY.md` and `tools/ps2eeas_nops.py` describe `ps2eeas`' behaviour and model it in Python. We run the real
assembler instead, as that project does to check its own tools. Nothing was copied.

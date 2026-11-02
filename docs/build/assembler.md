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

## Short loops: `config/us/ps2eeas_loop5.txt`

Retail's shortest loop is five instructions from the branch target to the branch (offset -5, six with the delay slot): the game code
has 238 backward branches of offset -5 and none shorter. `ps2eeas` 3.01 pads a loop up to six before the delay slot (offset -6), so
a loop that retail left at five, or padded to five, comes out one `nop` too long: a four-instruction loop (`strlen`: `addiu`, `lbu`,
`bnez` and its delay slot) has three padding nops where retail has two. GNU `as` pads the same way, so neither assembler reaches it.

`ps2eeas-loop5` is `Ps2EeAs.exe` with the byte at file offset 0x4DEB (the `6` in "pad up to six") changed to 5. `compile_unit.py`
makes `tools/ps2eeas/Ps2EeAs-loop5.exe` from the pinned download on first use (it checks that the byte is a 6 and refuses another build);
the patched copy is never published. It is a per-function choice, like GNU `as`: `scripts/matching/assembler_scan.py --write` judges
every source with it and with its current assembler and lists the ones that score lower in `config/us/ps2eeas_loop5.txt`, which takes
priority over `gnu_as.txt`. First scan: 54 of 2,665 sources scored lower and 26 of them matched (3,585 to 3,611); 21 listed GNU
functions scored worse with it and stay on GNU `as`, so the loop rule is not the whole story for those.

Found by checking `ps2eeas`'s output on synthetic loops (the padding is the same whether or not the loop holds a load), then locating the
threshold by patching each `6` of the executable in turn until a loop's offset changed. The Ratchet & Clank decompilation measured
retail loops at exactly six instructions; here the count is the same six with the delay slot included.

## VU0 instruction in a delay slot: `fill_vu_delay_slots`

GCC leaves the delay slot of a branch or jump to the assembler (`.set reorder`) when an inline-asm block comes right before it, and
retail's assembler moved the block's last instruction into the slot, VU0 ones included (`blez $a0,L ; lqc2 vf2,0($v0)`,
`jr $ra ; qmfc2.ni $v0,vf2`). `ps2eeas` 3.01 will not put a COP2 instruction in a delay slot (it pads with `nop`s), and GNU `as`
does, but GNU lacks the hazard `nop`s and the loop padding: no assembler had both, which made every such function a wall (about 40
near misses). `compile_unit.fill_vu_delay_slots` does the move on the compiler's assembly before `ps2eeas` runs, and writes the
instruction after the branch between `.set noreorder` and `.set reorder`, so `ps2eeas` leaves it alone and still adds its hazard
`nop`s and pads loops. It moves only a COP2 instruction (`lqc2 sqc2 qmfc2 qmtc2 cfc2 ctc2 v*`) that ends an asm block directly before a
branch GCC did not fill, and not one that writes a register the branch reads. It models what retail's assembler did (BUILD_FIDELITY
rule 1 of OpenRAC's, ours the same: a tool may only do what retail's assembler did); the evidence is the 94 sources that scored lower
(scan of the 537 VU sources, none worse, 3 new matches `11F288`, `11F2B8`, `179328`) and the 91 matched ones that still match.

The scan also moved functions between the lists: 43 that were GNU `as` only because the old rule chose it for them are now listed in
`gnu_as.txt` explicitly, 29 went to `ps2eeas_loop5.txt`, 2 went back to the default.

## `config/us/gnu_as.txt`

Not every retail function came out of `ps2eeas`: 53 of the 3,526 functions matched before the switch only match with GNU `as` (a loop
of five instructions that retail left unpadded is the typical case), as do 181 draft sources whose score is lower that way. They are
listed in `config/us/gnu_as.txt` and assembled with GNU `as` (`compile_unit.assembler_for(address)`). It is not a split by module. Two
rules explain most of it (measured on the matched sources: each rule has no `ps2eeas` function on its side):

- **A five-instruction loop in retail** (a backward branch with offset -5). `ps2eeas` pads such loops to six, so none of its functions
  has one; 31 matched GNU functions do. `scripts/matching/gnu_as_rule.py --write` adds every function of the split that has one.
- ~~An inline-asm block that ends with a VU0 instruction before a branch~~ (solved 2026-11-02, see below: no longer a reason for GNU `as`).

Together they cover about two thirds of the sources in the list; the rest (17 matched, 34 tried) was derived by scoring every source both
ways, and a few more functions were added when their rodata (a string or float literal, a jump table) linked differently out of
`ps2eeas`' object. `ps2eeas` (under wibo) now and then never returns when many run in parallel, so `compile_unit.py` retries it twice after 20 seconds.

Measured when the assembler went in: of 3,526 matched sources 3,473 stayed exact with `ps2eeas`; of 2,313 non-matching sources 45
became exact, 269 got closer and 181 got worse (those are in the list). Add a function to the list when it only matches, or
only links, with GNU `as`.

## Reference

The findings come from the Ratchet & Clank 1 decompilation ([OpenRAC/rac1-decomp](https://github.com/OpenRAC/rac1-decomp), GPL-3.0),
whose `docs/BUILD_FIDELITY.md` and `tools/ps2eeas_nops.py` describe `ps2eeas`' behaviour and model it in Python. We run the real
assembler instead, as that project does to check its own tools. Nothing was copied.

# Search tools for near misses

Tools that try many small source changes on a function that almost matches, and judge each against the retail code. They share one
scorer, so a search of thousands of candidates takes minutes. Run them with the repository's `.venv/bin/python` (they need `rabbitizer`
and `pyelftools`); [matching.md](matching.md) explains the score and [lessons.md](lessons.md) what has and has not worked.

| Tool | What it does | When |
| :--- | :--- | :--- |
| `scripts/matching/scorer.py` | Judges a source in process: registry, target words and symbols are read once, the compare runs in the calling thread, and every judged source is kept in `work/matching/scorecache/` (keyed by the source and a fingerprint of the compiler setup). `--bench ADDRESS SOURCE` compares with `try.py`. | Library for the others. About 50 compiles a second on 12 threads, twice `try.py`; a source judged before costs nothing. |
| `scripts/matching/neighborhood.py` | Every rewrite of `mutate.py` at every line it fits, plus every order of up to five consecutive declarations, then a beam search from the best few sources. Says when a depth found nothing better. `--batch` runs the pool of near misses. | Complete coverage of one-edit and two-edit changes. Use before concluding a function needs a larger rewrite. |
| `scripts/matching/regalloc.py` | `ADDRESS SOURCE [--symbol NAME]`: for each register that differs from retail's, the value (pseudo) that holds it, where it is born and dies, which allocator placed it (local-alloc, global-alloc, reload), what took retail's register and the likely lever, from the compiler's own `-dl -dg -dp` dumps. Uses the build's compiler for the address (SN's, Sony's 991111b, or the Linux 991111-01 through Docker); ours comes from GNU as with a listing. Ported from sly1-decomp's `tools/regalloc.py` (AGPL, same maintainers). Run on a draft whose diff is `registers`, not one that differs in code. | A near miss whose diff is a register swap. |
| `scripts/matching/sched1.py` | `--address ADDRESS FILE FUNC [--block N] [--check] [--trace UID] [--prio UID=N] [--order]`: replays GCC's first scheduling pass (haifa-sched) on each block from the `-dS -dN -fsched-verbose-6` dumps: priorities, ties, the issue order. `--check` compares the replay with the compiler's own trace (asinf: 15 of 16 blocks agree, block 0 differs on one tie); `--prio` flips a priority to see what retail needs. Ported from sly1-decomp (AGPL). | A near miss whose diff is instruction order, after `regalloc.py` shows the registers follow from the order. |
| `scripts/matching/globalalloc.py` | `--address ADDRESS FILE FUNC` or `--dumps DIR FUNC`: replays local-alloc and global-alloc from the `-dl -dg` dumps (`--check` compares with them: fmodf agrees on all 61 pseudos), `--set REG:refs=N,length=N,local=H` and `--pri REG=N` flip one ranking to find the minimal change that gives retail's register, `--trace REG` explains one pseudo's turn. Ported from sly1-decomp (AGPL). | A register swap where `regalloc.py` says only 'the dump does not show why'. |
| `scripts/matching/sly1_seed_extract.py`, `sly1_seed_run.py`, `sly1_seed_flatten.py` | Sly 1 bodies as drafts: extract the C of each Sly 1 function (local checkout of sly1-decomp in `work/sly1-decomp`), compile each paired file with its own flags and score the paired Sly 2 function (`matches.tsv`, relocations masked, no link check). Pilot 2026-11-14: of 195 unmatched Sly 2 functions with a Sly 1 body, 172 compile; 9 score 0, 24 at most 16 words, the draft beats our best on 69 (56 by 10 or more); on the 777 matched controls 223 score 0 and 503 at most 16. | After a land, to seed near misses (`sly1_seed_flatten.py` makes the 5-16 word seeds searchable with `SCORER_NO_LINK=1`); read each zero before landing (rename, `types.h`, `source:sly1-decomp`). |
| `scripts/matching/rules.py` | The source shapes the deep dives found (docs/contributing/matching.md, "One function per kind") as rewrites: indexed loop for m2c's pointer walk, `&a[i]` with the scaled index first, `const` on `RO_` externs, a `void` function returning its result, a dummy parameter where m2c's `argN` numbering skips a register, a virtual call without its trailing object argument, a global declared as an array, a callee's trailing argument appended, dropped or replaced (and a member re-read after a call), a float parameter moved to another position, `long long` as `long`, a by-value class return. `neighborhood.py` imports it, so every rule is judged with the other edits, chained with them and kept in the beam: a corrected argument that first scores worse can still lead to 0. | The near misses that the permuters and mutations did not move: the rules are the causes found by hand, so they fix what a reordering cannot. `python3 scripts/matching/rules.py SOURCE` prints the rewrites a source gets. `make rules` runs them (with the neighborhood search) over the near misses: `make rules MIN=1 MAX=20 BUDGET=800 JOBS=8`; a better source is written to `data/matching/src/fn`, register it afterwards with `try.py --record` (or `record_round.py`), then `make src`, `make elf`. |
| `scripts/matching/mutate.py` | Random climbing with the same rewrites (one more than before: `volatile_slot`, see lessons). | Deeper, cheaper walks when the neighbourhood is exhausted. |
| `scripts/matching/callee_sigs.py` | Reads each function's return type from the code: a caller reads `$v0` or `$f0` after the call, or the callee writes it before `jr $ra`. `check` lists source declarations that disagree, `sweep` tries every single and paired return-type change on the near misses. | Callee declarations steer scheduling even when the result is dropped. |
| `scripts/matching/idioms.py` | `mine` counts source shapes over the matched sources, `suggest ADDRESS` lists the shapes the nearest matched functions (by shared callees) use that this source does not. | A starting point when a source is far from retail. |
| `scripts/matching/harvest.py` | Runs [m2c](https://github.com/matt-kempster/m2c) (GPL-3.0; clone it into `work/matching/tools/m2c`) on every function without a source, makes the draft compile (its macro header, `void *` as `s8 *`, callees in an `extern "C"` block), judges it, and tries a second variant with callee return types from `callee_sigs.py`. `--write` saves drafts that score 0, and with `--keep N` those within N words, as sources. | The first thing to run on functions nobody has tried: plain drafts already match for a share of them. Needs `.venv/bin/python`. |
| `scripts/matching/boundaries.py` | Finds functions the split cut in two (a branch lands inside another function) and records the groups in `config/matching/merges.tsv`; `functions.py` applies them. | After a re-split, or when a function's size looks too small. A piece with the wrong size can never match. |
| `scripts/matching/credit_audit.py` | Sorts the matched sources into tiers by the strictest trick they use (an empty `asm` barrier or register-pinned local, other inline asm, a volatile cast, an inline helper, plain C) and prints each tier's share. | To check that no matched source uses a trick: every match should be in the plain C tier. |
| `scripts/matching/export_signatures.py` | Writes the real prototypes of matched functions with a plain (unmangled) name as the JSON `scripts/ghidra/ApplySignatures.java` reads. Applying it gave a mixed result (see lessons), so it is not applied by default. | To feed Ghidra what the matched C knows, after backing up the project. |
| `scripts/vu/vuasm.py` | Assembles the text of `vudis.py` and proves the microcode rebuilds byte for byte (`verify`; `make elf` runs it); `source` writes the verified text. | Editing or annotating VU1 programs without losing the byte gate. |
| `callee_sigs.py arity` | Calls that pass fewer arguments than the callee reads (the callee's registers read before written). Matched sources are the control: 6.2% of calls there, 10.4% in unmatched ones. | A weak lead for "missing instruction" diffs. |

`scripts/matching/classify_diffs.py` sorts the near misses by kind of difference (register, order, extra instructions, ...) and
`scripts/matching/record_round.py` re-judges every source and updates the registry after any of these tools writes a source.

## m2c and VU0 code

m2c does not read VU0 macro instructions. `scripts/matching/m2c_vu.patch` teaches it to keep each one (`lqc2`, `sqc2`, `qmtc2`, `qmfc2`,
`ctc2`, `cfc2`, `v*`) as an ordered opaque call, and `harvest.py` turns those calls into `asm volatile` statements (GPR operands become
`"r"` inputs, `qmfc2`/`cfc2` results become temporaries). Apply it once in your m2c checkout:
`cd work/matching/tools/m2c && git apply ../../../../scripts/matching/m2c_vu.patch`. Drafts cached before the patch live in `m2c-stack/`;
patched ones go to `m2c-vu/`. Result on the 945 unsourced functions (with `--repair`): unsupported 531 to 392, drafts that compile 120 to 308, 75 within
20 words of retail and 18 within 5 (none before). `s64`/`u64` in the draft prelude are `long`/`unsigned long`: with SN's compiler `long long` is
128 bits, so m2c's 64-bit loads and stores became "unsupported wide integer operation" errors. The stack fields m2c names (`sp0`, `sp10`) become `#define`s into the local `sp` buffer, and a callee
called with fewer arguments than its first declaration gets a `(...)` prototype in the repair loop. Multimedia (MMI) and unaligned (`ldl`/`ldr`) instructions are still refused. The drafts are a starting
point: such functions stay unmatched (inline asm is not allowed, AGENTS.md).

The repair loop also casts a dereferenced integer expression (`*(temp + var)` where m2c could not type the pointer) to `*(s32 *)` (`f32` on a
line with floats), leaves alone any operand that mentions a pointer, and declares the callee-saved registers m2c reads first (`saved_reg_s1`)
as locals.

`harvest.py --shape` then tries the fixes that recurred in hand-shaped matches on every draft that compiles, keeping a variant only when it scores
lower: `(int)` around a shifted 64-bit bit test, sign-extended 32-bit masks (`& (s64)(s32)0xFBFFFFFF`), `L` on shifts of 32 and more
(`0x8000L << 0x23`), and pass-through leading arguments (`arg0`, `arg0, arg1`) for callees the repair loop declared `(...)`. On the 283 compiling
drafts it improved 26 (for example 8 to 3 on two of them) and matched none by itself: it finds the cheap fixes, the rest is shaping by hand.


When m2c fails on a function's split assembly, `harvest.py` retries on a patched copy: the delay slot that follows a final `jr $ra` (the split
records the function without it; 38 functions) and branch labels the split did not write (3 functions) are added from the whole-text split.
That took the functions with no draft from 41 to 6. `--write --refresh` replaces a saved source only when the new draft scores strictly lower.

Compile-error repairs added after the first harvest numbers (drafts that compile 120 to 370, 14 drafts that match with no editing, 11 within 5 words):
a `return sp0;` is no longer mistaken for a local declaration of `sp0` (the stack-field `#define` was skipped); a dereferenced integer expression is
cast unless it contains a pointer outside the scalar `M2C_FIELD` reads; a pointer variable compared with an integer gets `(s32)`; a function type
where m2c printed a pointer type is replaced by `s8 **`; the VU special registers (`ACC`, `Q`, `P`, `I`, `R`) are written upper case in the lifted
asm, which the assembler needs (`vdiv`, `vmulq` were rejected otherwise). Of the 208 functions that still failed after the first repairs, 115
fail now; the rest are mostly argument-passing mismatches on indirect calls (about 25) and a few assembler errors.

The same patch keeps the 128-bit multimedia instructions on general registers (`por`, `pextuw`, `pextlw`, `prot3w`, `pcpyld`, `padduw`, ...), `max`/`min`
and the unaligned 64-bit pairs (`ldl`/`ldr`, `sdl`/`sdr`) as ordered opaque calls; `harvest.py` lifts them like the VU0 ones (a 128-bit result is an
`s128` temporary, an `ldr` merges into the value its `ldl` wrote through a tied `"0"` operand, and a `%lo` relocation operator is escaped as `%%lo`).
Re-apply it to your m2c checkout (`git apply` on a fresh one, or revert and apply again) and clear the cached drafts in `m2c-vu/` of the functions
that were unsupported. Functions m2c refuses fell from 407 to 193, drafts that compile rose from 370 to 518, drafts within 20 words of retail from 69
to 113, and one more draft matched with no editing. Left unsupported: the 32-bit `lwl`/`lwr`/`swl`/`swr` forms m2c already knows (its own
`M2C_UNALIGNED` calls), `c1`, `ei`/`di`, `mtsah`, `sync` and `syscall`. A stack slot m2c uses without declaring (`unksp8`) is declared as an `s32`, and a bare `sp`
gets a 0x100-byte buffer.

Further compile repairs on the lifted drafts (non-compiling 167 to 139, compiling 518 to 541, within 20 words 113 to 117): quad (`por` ...) results are
64-bit temporaries because SN's compiler has no 128-bit arithmetic (`unsupported wide integer operation` came from converting an `s128` to a float); a
stack buffer `sp` is declared whenever stack-field macros use it; `jtbl_` symbols get an `extern s32 jtbl_X[];`; a draft with m2c's
`second half of f64` pseudo-expression counts as unsupported; and an argument of the wrong pointer type in an indirect call (`s8 **` for `s8 *`,
also `name + offset`) is cast to the parameter type the compiler names. About 16 drafts still fail without a message: m2c writes `case` labels
outside a `switch` when it could not rebuild a jump table.


The split writes two instructions it does not decode as `.word 0x... # mnemonic operands`: `vsqrt` (406 lines) and `cvt.w.s` (191 lines), in 308 functions. m2c reads a
`.word` as data and drops it, so a draft of such a function lacked a square root or a float-to-integer conversion and could not match. `harvest.py` now writes
them as instructions before running m2c (`decode_words`), and a check of the lifted VU0/MMI calls against retail's instruction counts shows nothing else lost
(15 of 452 functions miss one `lqc2`/`sqc2`). Re-running over those functions refreshed two sources and gave two more drafts that match with no editing.

`permute.py` also searches the statements you mark with a trailing `//P` comment, wherever they are in the function: all orders of up to five, else a seeded sample of
`--random` orders (default 60), then a hill climb from the best order over every swap of two marked statements and every move of one (a strict improvement is taken, a tie is walked at most five times in a row, within `--budget`). Random sampling reaches a good order of five or six statements but not reliably of seven: the climb finds it one step at a time (a Sonnet worker found `InitTask`'s 7-store order this way by hand). Use it for a store-order miss: the compiler emits the last-written store first, so the order retail shows is found by
trying orders, not by reading. Without markers it still reorders runs of consecutive statements (all orders up to five, rotations and swaps beyond); a run is
only consecutive simple statements, which is why scattered stores need the marks. On a matched function with its four stores reversed, the search found the
order again in 24 compiles.

`permute_stores.py` runs that search over the whole near-miss list: for each non-matching source scoring between `--min` and `--max` it marks the stores of every
straight-line region with at least two, searches their orders (`--budget` compiles per function, `--seed` for another sample) and writes better sources to
`work/matching/permute-stores/`; a later run starts from them. Over the 330 near misses scoring 1 to 20 that have such a region, two passes improved 39
and matched 3 (the first pass took 5 minutes, the second found 2 more: the small regions are searched exhaustively).

`fix_stack.py` replaces the placeholder `sp[0x400]` buffer of the near-miss sources by each size the retail frame allows (multiples of 0x10 below the `addiu $sp` frame) and keeps
the best; better sources go to `work/matching/fix-stack/`. On the 349 near misses with the placeholder it improved 325 and matched 87 in under three minutes.

`mutate.py` has the rewrites the shaping rounds found useful on m2c drafts: a pass-through `arg0` added to a callee's prototype and calls (`leading_argument`), a callee's return type `void` against `s32`/`M2C_UNK`
(`callee_return_kind`), a prototype parameter `s32`/`M2C_UNK` against `f32` (`float_parameter`), `p += 4` against `p += 1` and a byte cast on `p + 0x30` (`pointer_stride`), the `(int)` cast on a shifted
bit test (`bit_test_cast`), and `0x8000L << n` (`long_shift`). The `volatile` pointer read it used to try is gone: it only steers the scheduler, which AGENTS.md does not allow. `--batch --manifest` takes the
current scores of `nonmatching/MANIFEST.tsv`. On the near misses scoring 1 to 10 (590 functions, 50 compiles each, about 25 minutes in all) it matched 26 and improved 72; the first pass over scores 1 to 4 matched
17, the second over 5 to 10 matched 9.

A third `mutate.py` pass (scores 1 to 12, 690 functions, 100 compiles each, a new seed, about 70 minutes) matched 8 and improved 30, against 17 and 9 for the first two passes over the same
rewrites: the rewrites are close to exhausted, and the next gains come from new kinds of rewrite or from hand shaping.



## Running the searches with make

Every search tool has a target; `MIN`, `MAX` (the near-miss score range, default 1 to 20), `BUDGET` (compiles per function, default 800), `JOBS` and `SEED` are variables:

| Target | Runs |
| :--- | :--- |
| `make permute ADDRESS=0x11A060` | `permute.py` on one function (its `//P`-marked statements, then the runs of consecutive statements); a better source is written in place |
| `make permute-stores MIN=1 MAX=9` | `permute_stores.py`: the store-order search over the near misses; improved sources go to `work/matching/permute-stores/` |
| `make boundary-suspects` | `boundary_suspects.py --write`: near misses whose score is a split artifact (a `jr $ra` whose delay slot is in the next piece, a piece that is only an epilogue); written to `work/matching/boundary_suspects.tsv`, and the search tools skip them. Fix them by hand (`split_boundary.py`, `merges.tsv`) |
| `make sigs MIN=1 MAX=9` | `callee_sigs.py sweep`: the return types of the callees of the near misses, read from the executable; a better source is written to `data/matching/src/fn` |
| `make fix-stack` | `fix_stack.py`: the real size of the placeholder `sp[0x400]` buffers; improved sources go to `work/matching/fix-stack/` |
| `make adopt` | `adopt.py`: takes the sources of those two folders that score strictly lower than the current ones into `data/matching/src/fn` (a `.c` file is judged as C) |
| `make mutate` | `mutate.py --batch`: the random rewrites |
| `make rules` | `neighborhood.py --batch` with the rewrites of `rules.py` |
| `make search` | `boundary-suspects`, `sigs`, `fix-stack`, `permute-stores`, `adopt`, `rules` in that order |
| `make land` | after any of them: register the matches, publish, byte gate, reports (below) |

None of them registers anything. `make land` does, and everything after it:

```
make land            # record.py, make src, make elf (the byte gate), make report, make nonmatching, make objdiff, make pal, make readme
make land FORCE=1    # the same, without the scan of the new matches for banned constructs
```

`scripts/matching/record.py` judges every source in `data/matching/src/fn` (a `.c` file as C; `compile_unit.py` picks the compiler by address), registers the matches (SDK functions too) and scans each new match for what AGENTS.md bans: `volatile` on ordinary data (a pointer to a hardware register, an address from 0x10000000 up, is allowed), `register` pins, and any inline asm in a function (only the shared `sqrt.s` helper passes). It prints every hit as `review: file:line` and `make land` stops there before it builds anything; read the hits, fix the source or accept it, and run again (`FORCE=1` skips the scan). `python3 scripts/matching/record.py --dry-run` judges without changing the registry. The recipe stops at the first failing step, so a `PASS` from the byte gate is what the later reports are built on. Commit afterwards by file name: `git add src site nonmatching config docs`.


Started through make, the long tools print a progress line to stderr (`[permute-stores] 12/70 17%  elapsed 41m02s  eta 3h20m  running 1FC270, 1B9CA0  last 1E64C8: 6 -> 5`: a line when a function finishes, at most one every five seconds, a heartbeat line every 15 seconds while none does, so a slow function does not leave the screen blank, and a `done` line; the workers report in whatever order they finish): `make` exports `PROGRESS=1`, `make rules PROGRESS=0` silences it. A tool run directly, by an agent or a script, prints exactly what it printed before (`scripts/matching/progress.py`): set `PROGRESS=1` yourself to get the lines there too. The tools with progress lines: `record.py`, `adopt.py`, `permute_stores.py`, `fix_stack.py`, `export_nonmatching.py`, `mutate.py --batch`, `neighborhood.py --batch` (its own per-function line gains the elapsed time and the estimate) and `harvest.py`.


## frame_diff.py: the stack frame next to retail's

`python3 scripts/matching/frame_diff.py 0xADDR source.cpp [--search N]` prints retail's frame and ours one row per stack offset: the frame size, the saved
registers, the stack addresses handed out (`addiu rX, sp, N`, an address-taken local) and the accesses at each offset, `!` where they differ, then a
frame distance. A score hides which slot moved; this shows it (`13DA18`: retail has a 16-byte object at `sp+0x20` that ours lacks, so every later local sits
`0x10` lower). `--search N` tries up to N orders of the local declarations and keeps the lowest (frame distance, score); the distance is flat-free where the
score is not. A scan of 474 near misses (score 1 to 60, 2026-11-03): 363 have the identical frame, 90 have the same frame size with other slot offsets, 21 differ
in frame size (mostly by one 16-byte slot: a dead `QW` local retail's frame shows). The frame wall is about a fifth of the near misses, not most of them.
Fixes that moved a frame: a struct that groups locals with pad fields (`16CAA0`), declaring one local before another (`181060`), scoping each `GIFS`/`CRef` temporary
to its own block so they share a slot, a dead `QW junk[N]` the frame shows, and an inline helper that takes the address as a parameter.

## What a search may write, and what it leaves alone (2026-11-08)

`scripts/matching/search_guard.py` is shared by every search tool.

- **A rewrite must not add a finding.** `neighborhood.py`, `mutate.py`, `callee_sigs.py sweep` and `adopt.py` compare a rewritten source with the one it came
  from, through `check_source.py`: a new banned construct (inline asm, a padding local, `volatile` on ordinary data), a new cleanup problem, or a new
  `review` warning (`check_source.py --review`: a local set from a literal that is never changed and used at least twice, such as `int newline = 10;`;
  a constant-true condition such as `|| 1`) means the source is not written, and the tool says why on stderr. A finding the current source already has
  does not block an improvement. Before this, only `adopt.py` checked; the others wrote a lower score into `data/matching/src/fn` with whatever it held.
  The literal-local warning fires on 0.6% of the matched sources and on 3.7% of the unmatched ones, so it is a warning to read, not a ban.
- **Functions left out.** Permanent blockers (`config/us/blockers.tsv`: a VU0, MMI or COP0 instruction, hand-written assembly) are never searched, as AGENTS.md
  leaves them out of the work queues. `config/matching/walls.tsv` lists the near misses whose remaining difference was traced to the toolchain (a store in a delay slot
  whose address is in a register; a `$gp` save: class `toolchain`) or to a scheduling or allocation tie found in the RTL dumps after a long manual
  search (class `tie`); each row has its reason and evidence. The tools skip them, and `SEARCH_INCLUDE_WALLS=1` searches them anyway. The boundary
  suspects of `make boundary-suspects` are skipped the same way, and so is a function whose current source holds a banned construct (inline asm, a
  register pin): it can never match, `record.py` ignores a score reached with it, and the first overnight run spent its budget there (57 of 82
  "improved" sources held VU0 asm). Add a row when a function is shown to be a wall, with the dump or the count of compiles.
- **Store order, first rule.** `permute_stores.py` tries the orders that follow gcc 2.95's first-scheduler rule before the random search: among stores that
  share a constant, the one written last is emitted first (the constant's register dies there). InitMurray was found that way after 2,500 random orders had not
  reached it.

Tried and dropped: a lint for a callee declared with more integer parameters than its own code reads (`callee_sigs` `params`). It fired on 19% of the matched
sources, because a callee may ignore an argument its callers still pass: the check needs retail's call sites (which argument registers are set before the `jal`),
not the callee's code. The search is still not protected against an invented argument; the score is, since retail does not set the register.

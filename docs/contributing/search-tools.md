# Search tools for near misses

Tools that try many small source changes on a function that almost matches, and judge each against the retail code. They share one
scorer, so a search of thousands of candidates takes minutes. Run them with the repository's `.venv/bin/python` (they need `rabbitizer`
and `pyelftools`); [matching.md](matching.md) explains the score and [lessons.md](lessons.md) what has and has not worked.

| Tool | What it does | When |
| :--- | :--- | :--- |
| `scripts/matching/scorer.py` | Judges a source in process: registry, target words and symbols are read once, the compare runs in the calling thread, and every judged source is kept in `work/matching/scorecache/` (keyed by the source and a fingerprint of the compiler setup). `--bench ADDRESS SOURCE` compares with `try.py`. | Library for the others. About 50 compiles a second on 12 threads, twice `try.py`; a source judged before costs nothing. |
| `scripts/matching/neighborhood.py` | Every rewrite of `mutate.py` at every line it fits, plus every order of up to five consecutive declarations, then a beam search from the best few sources. Says when a depth found nothing better. `--batch` runs the pool of near misses. | Complete coverage of one-edit and two-edit changes. Use before concluding a function needs a larger rewrite. |
| `scripts/matching/rules.py` | The source shapes the deep dives found (docs/contributing/matching.md, "One function per kind") as rewrites: indexed loop for m2c's pointer walk, `&a[i]` with the scaled index first, `const` on `RO_` externs, a `void` function returning its result, a dummy parameter where m2c's `argN` numbering skips a register, a virtual call without its trailing object argument, a global declared as an array, a callee's trailing argument appended, dropped or replaced (and a member re-read after a call), a float parameter moved to another position, `long long` as `long`, a by-value class return. `neighborhood.py` imports it, so every rule is judged with the other edits, chained with them and kept in the beam: a corrected argument that first scores worse can still lead to 0. | The near misses that the permuters and mutations did not move: the rules are the causes found by hand, so they fix what a reordering cannot. `python3 scripts/matching/rules.py SOURCE` prints the rewrites a source gets. `make rules` runs them (with the neighborhood search) over the near misses: `make rules MIN=1 MAX=20 BUDGET=800 JOBS=8`; a better source is written to `data/matching/src/fn`, register it afterwards with `try.py --record` (or `record_round.py`), then `make src`, `make elf`. |
| `scripts/matching/mutate.py` | Random climbing with the same rewrites (one more than before: `volatile_slot`, see lessons). | Deeper, cheaper walks when the neighbourhood is exhausted. |
| `scripts/matching/callee_sigs.py` | Reads each function's return type from the code: a caller reads `$v0` or `$f0` after the call, or the callee writes it before `jr $ra`. `check` lists source declarations that disagree, `sweep` tries every single and paired return-type change on the near misses. | Callee declarations steer scheduling even when the result is dropped. |
| `scripts/matching/idioms.py` | `mine` counts source shapes over the matched sources, `suggest ADDRESS` lists the shapes the nearest matched functions (by shared callees) use that this source does not. | A starting point when a source is far from retail. |
| `scripts/matching/harvest.py` | Runs [m2c](https://github.com/matt-kempster/m2c) (GPL-3.0; clone it into `work/matching/tools/m2c`) on every function without a source, makes the draft compile (its macro header, `void *` as `s8 *`, callees in an `extern "C"` block), judges it, and tries a second variant with callee return types from `callee_sigs.py`. `--write` saves drafts that score 0, and with `--keep N` those within N words, as sources. | The first thing to run on functions nobody has tried: plain drafts already match for a share of them. Needs `.venv/bin/python`. |
| `scripts/matching/boundaries.py` | Finds functions the split cut in two (a branch lands inside another function) and records the groups in `config/matching/merges.tsv`; `functions.py` applies them. | After a re-split, or when a function's size looks too small. A piece with the wrong size can never match. |
| `scripts/matching/credit_audit.py` | Sorts the matched sources into tiers by the strictest trick they use (an empty `asm` barrier or register-pinned local, other inline asm, a volatile cast, an inline helper, plain C) and prints each tier's share. | To quote progress as "plain C" next to the byte-exact figure. |
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
point: see matching.md ("VU0 functions") for how to bring them to a match, and keep register pins and barriers out.

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
| `make fix-stack` | `fix_stack.py`: the real size of the placeholder `sp[0x400]` buffers; improved sources go to `work/matching/fix-stack/` |
| `make adopt` | `adopt.py`: takes the sources of those two folders that score strictly lower than the current ones into `data/matching/src/fn` (a `.c` file is judged as C) |
| `make mutate` | `mutate.py --batch`: the random rewrites |
| `make rules` | `neighborhood.py --batch` with the rewrites of `rules.py` |
| `make search` | `fix-stack`, `permute-stores`, `adopt`, `rules` in that order |

None of them registers anything: afterwards `try.py --record` (or `record_round.py`) records the matches, then `make src` and `make elf`.

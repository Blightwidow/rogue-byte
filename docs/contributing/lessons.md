# Lessons

What cost time here, distilled by topic. Read it before matching or touching the tools; when something costs you time, add a dated bullet to
the topic it belongs to (what you saw, what fixed it). Source patterns for a near miss are in [matching.md](matching.md), the tools in
[search-tools.md](search-tools.md). This page replaces the dated log of 2026-10-28 to 2026-11-12 and the procedure notes of sly1-decomp's
`docs/AGENT_WORKFLOW.md` (same maintainers, AGPL-3.0: [AGENTS.md](../../AGENTS.md) "Rules"); the old text is in git history. Claims taken from
another project and not measured here are marked *unverified*.

## 1. The loop, and when to stop

1. Read the disassembly: arguments (`$a0`-`$a3`, floats `$f12`...), return (`$v0`, `$f0`), fields (`lw $v0, 0x708($a0)` is a 32-bit field at
   0x708), calls, data. Write the C++ with the declarations it needs, then `try.py` until `score 0`.
2. **Read the diff before rewriting.** A near miss is nearly always a fact about a callee or about order:
   a register retail loads and ours leaves unused: the callee takes one more argument; `$v0` busy across a call: the callee returns a value
   (declare it non-`void`, cast the call to `(void)`); a different order of a callee's integer and float parameters moves the argument moves
   (copy the prototype from a caller that matches); a callee's return type can change the register of an unrelated test.
3. **Register diff?** `scripts/matching/regalloc.py ADDRESS SOURCE` names the value behind each differing register, who placed it
   (local-alloc, global-alloc, reload), what took retail's register, and the lever. Use it on a `registers` diff, not on a `code` diff.
4. **Only the order of statements left?** `permute.py`, `neighborhood.py` (every one-edit rewrite, then a beam) and `rules.py` try them.
   Most zeros the decomp-permuter finds are tricks (a parameter's address taken, one variable for two values): read each diff and write the real
   change plainly (one VU0 near miss: 75 of 77 zeros were such tricks).
5. **Stop** when it is not a function (reads registers it never sets, no `jr $ra`, starts with a stray `addiu $sp,$sp,+N`), is hand-written (a
   `nop` busy-wait, a jump into another function), needs an instruction C cannot ask for, reads `$t0`-`$t3` as inputs (arguments past the eighth),
   after about ten compiles without getting closer (about 25 for a worker's last effort), or when three wordings give the same wrong bytes.
   Keep the attempt in `nonmatching/` with what differs. If the checker says the C is N bytes and retail's M, fix the size first (the split lost
   or invented a boundary).
6. **A zero is not a match until the rules pass and the image matches** (`make land`). Old zeros all broke a rule: a padding `volatile`, inline asm,
   a bare `do { } while (0)`, a constant `|| 1`. Read `--review` before landing.
7. **Re-score every stuck function after any discovery** (a flag, an assembler change, a compiler build, a new rewrite): saved sources re-run in
   seconds. Wave A1 found 5 zeros and 21 near misses among sources a toolchain change had hidden; the 2026-11-14 libm finding turned two
   "walled" functions into matches.

## 2. What moves the bytes (measured on SN 2.95.3 and Sony 2.9)

- **Branch order follows the `if`.** `if (c) A; B;` makes `A` the branch and `B` the fall-through; flip the arms or write `if (x > 0) return ...;
  return 0;` when retail falls through. `if (c) A; else B;` makes `A` the fall-through. `if (p) do { } while (p);` is a bottom-tested loop; a loop
  tested at top and bottom is `if (c) do { } while (c);`. A single exit avoids the `move $v0,$zero` of a second return.
- **Operand order and association.** `if (v != p->f)` against `if (p->f != v)` swap the branch's registers; `i * a` against `a * i` swap `mult`'s
  operands; the compiler reassociates `(head - 1) + n` (split it); `base + (n*k + c)` adds the constant first when grouped so. Float compares keep
  the source's operand order. `__builtin_fabsf` gives `abs.s`, `x < 0 ? -x : x` does not.
- **`if` against `?:`.** A ternary often becomes `movz`/`movn`, an `if` a branch (`if (x >= 16) m = 0; else m = 1 << x;` gives a branch-likely).
  Clamps: `v = v < lo ? lo : (v > hi ? hi : v);` gives the branchy shape; `if`/`else if` chains and inline helpers if-convert. A switch on 0, 1, 2
  gives a compare tree an `if` chain does not.
- **Loads and stores.** `p->items[p->n++] = v` loads `p->n` once, `p->items[p->n] = v; p->n++;` twice. Loads retail hoists above a branch are
  named locals before it. Runs of stores to one base are rescheduled whatever the source order: try the permutations (five stores: 120) first.
  A store after a call can land in the call's delay slot: write it before the call when retail has it there. Reloading `self->field` after a
  call instead of keeping a local saves a callee-saved register. A store through `*(s32*)((u8*)self + 0xNNN)` schedules differently from member
  access. `extern s32 T[][2]` indexed `[i][1]` fixes the operand order of a stride-8 address add.
- **Types.** `lb`/`lbu`, `lh`/`lhu`, `lw` give size and sign; `slt` against `sltu`, `slti` against `sltiu` give signedness. A `u8` return adds
  `andi $v0,$v0,0xff`; no mask means the function and local hold `s32`. Packing 32-bit values into 64 bits matched with `s32` parameters. Native
  `long` is 64 bits on the EE (m2c's `--context` reads it as 32: give it `long long`).
- **The frame** shows the locals: `addiu $sp,$sp,-0x60` with `$ra` at 0x50 means 0x50 bytes of locals, in declaration order. A frame that is off
  while the body matches usually means a missing struct local; GCC 2.95 gives an unused struct local a slot (only a type the original plausibly
  declared is allowed: [AGENTS.md](../../AGENTS.md)). A local whose address goes to a callee lives in the frame: one struct sized to retail's.
- **Struct initialisers** (`Pair p = { a, b };`) call `memset`: assign the fields one by one. `aligned(16)` gives `lq`/`sq` copies,
  `packed` gives `ldl`/`ldr`/`sdl`/`sdr`.
- **Callee declarations.** A callee takes what it reads (count parameters from its own disassembly); an extra argument changes the caller's
  prologue and delay slots; a wrapper that passes a float through untouched declares the callee with fewer parameters. `void` to `int` on an
  `extern "C"` callee fixed 4 of 119 near misses of score 3 or less: the callee's own tail is the evidence (it writes `$v0` before `jr $ra`, as
  constructors returning `this` do); a caller that merely discards `$v0` says nothing. `scripts/matching/callee_sigs.py` reads them.
- **Bit access in libm code reads the float through `GET_FLOAT_WORD`** (`do { union; } while (0)`): the loop notes put the next label on an 8-byte
  boundary and retail has that extra `nop`; a block-scope union variable does not (atanf 7 to 0). m2c's `M2C_BITWISE(s32, f32)` is a value cast
  (`cvt.w.s`), not a bit read: rewrite it with the macro (sqrtf 69 to 4, atan2f 185 to 0).
- **A search tool's zero is a lead, not a match: read the edit.** `neighborhood.py`'s `commute` rewrote an asinf polynomial's meaning and `swap_adjacent` moved a store past its use in fmodf, and both still scored better. The fix that matched asinf was structural and plain: `t = x * x` only in the `else` arm of the tiny-argument test, as the original wrote it. Per-pass explanations: [../toolchain/](../toolchain/README.md); things to try: [../IDEAS.md](../IDEAS.md).
- **`-mvu0-use-vf0-NN` ignores NN on SN 2.95.3** (7, 15, 16, 30, 31 score alike on 1,051 sources; the `vf30` and `vf31` spellings match them): the flag is on or off. On unmatched sources it improves 25 and worsens 30 (none to 0), on 300 matched controls it changes none. `"*r"` on `LaneX`'s input breaks 3 of 46 matched users: not adopted. Measure a flag or constraint on matched controls before trusting either direction.
- **Cheap rewrites that found matches:** a chained store `a = b = 0` for two stores (sqrtf's last words); a named constant against a repeated
  expression; a test of a variable both arms set written in each arm; a variable set in every arm instead of before a switch; one index for two loops
  (`tsearch`'s library lists them).
- **What does not move:** a `lui`/`li`/`move` scheduled against a store before a `jal`; a pair of `$s` registers swapped; `$v0`/`$v1` temporaries
  swapped; an epilogue shared where retail duplicates it. Ten to thirty variants each left these put; record NEAR.
- **Not the source's doing:** the hazard `nop` after `mtc1` and the padding of short loops come from the assembler (`ps2eeas`), never from C
  ([assembler.md](../build/assembler.md)). Dead loads are not reproduced by unused locals. Compiling callees first in the same file does nothing on
  SN 2.95.3 (it was a 2.96 effect).
- **Two real constraints:** a `volatile` reload of a packet pointer handed back through an out-parameter (retail re-reads it from the stack before
  every store) is the allowed `Slot(&pqw)[1] = x;` form, plain `((unsigned*)pqw)[0] |= 1;` where retail's delay slot holds the reload (0x13A688:
  21 to 2). The VU0 flag (`-mvu0-use-vf0-15`) also moves code outside the VU0 block (hoisted constants, strength reduction): read such a diff as the
  flag's, not the helper's.

## 3. Compilers, the assembler and scoring

- **The score is the count of differing instruction words with relocations masked**, so a zero can link to the wrong address: the `link` part of the
  score catches it. Compile through the build's own path (`compile_unit.py`: `ee-gcc -S`, `.extern` lines hoisted, `Ps2EeAs-loop5.exe`, `objcopy -L`);
  a hand-run compile can differ in the image. Scores recorded before a toolchain change need `rejudge.py`.
- **Three builds in one image.** Game code: SN 2.95.3. SDK range (0x2319E8-0x256CE8): Sony 2.9-ee-991111b (`config/us/sony_gcc29.txt`: saves with
  `sd` only, `mult1`/`multu1`/`mfhi1`/`mflo1` come from plain C). The libm functions that divide: Sony 2.9-ee-991111-01
  (`config/us/sony_gcc29_01.txt`, a Linux build run through Docker): it writes `nop; nop; div.s` and keeps `div.s` out of delay slots, as
  retail has it before all 27 divides there. Two lists, never one address on both; add an address when a draft scores better with the build.
  `TRY_ASSEMBLER=sony29|sony29-01` scores one source with a build for a probe. The SDK range was once judged by hand-run compiles that missed the
  difference: "ruled out" needs the probe on the exact build (a two-divide function, `-S`).
- **A save-pattern profile** (`prologue_profile.py`) separates builds statistically, not sharply (17 of 366 SDK functions use `sq`): spot ranges, never
  draw unit boundaries from it.
- **Library members can be named by comparing code with relocated fields masked** plus a three-word anchor (122 exact members from SDK 2.4 covered 242
  of 751 SDK functions). A stub shared by several members names nothing (a 28-byte `jr $ra` fits 13); Sly 2 was linked against a newer SDK than 2.4
  (libdma, libpad, libmc, libmpeg, libpkt have no exact member). Compile a library's own source unmodified and compare it with every unmatched function
  of the same size: matches fall out without names (libgcc's `fp-bit.c`, `libgcc2.c`) *(unverified for others)*.
- **Sly 2 is not Sly 1 recompiled** (`sd`/`ld` saves, real C++ with 8-byte vtable slots and the vtable at +0xC, regrouped classes, vectors by value in
  128-bit registers). Sly 1 names, offsets and C are drafts: [AGENTS.md](../../AGENTS.md) "Rules". A name `s1_0x...` is an offset in Sly 1.
  A decompiler drops VU masks (`vmul.xy` comes out as a three-component product).

## 4. Search tools: what found what

- **Draft first.** A plain m2c draft (`harvest.py`) matched 32 of 1,711 unsourced functions outright, 178 within 5 words; the neighbourhood search then
  matched 14 more. Yield peaks for 64-300 bytes. Repair drafts from the compiler's own messages (`harvest.py --repair`: casts, an `sp` buffer from
  `--stack-structs`; drafts that compile 21 to 90, then 61 to 244). Keep a blocker class and the yield per size bucket. `long` is 64-bit for m2c.
- **Search order.** `scorer.py` judges in process (0.19 s a compile, 12 threads); then `rules.py`, `neighborhood.py`, `mutate.py`; sly1's `tsearch.py` and
  `sitesearch.py` are the next to port. On fresh drafts a few mechanical edits reach many near misses; on a long-worked source the one-edit
  neighbourhood is exhausted (300 near misses of score 1-10: 5 improved, none matched): it needs an idea, not compiles.
- **Dead ends, do not repeat:** return types as a search space (654 sources: 5 improved by 1-2 words, none matched); setting every disputed callee
  declaration at once (22 of 122 worse); adding zero arguments where callers under-pass (6 improved, none matched); parameter counts from a callee's code
  (only a lower bound: matched sources pass fewer at 6.2% of calls); handing m2c those counts (worse drafts); real prototypes applied to Ghidra (register
  leaks rose); compiling callees first (SN 2.95.3); `.lreg`-style guesses without the dump.
- **Twins:** a function equal to a matched one with call targets, `%hi`/`%lo` and immediates hidden gets its source with those swapped (`twins.py`; the
  pool is nearly empty). **Split functions can never match:** a branch landing inside another function proves one function (`boundaries.py`,
  `config/matching/merges.tsv`); a near-miss score kept from the old size is meaningless once the size is corrected.
- **Report progress in tiers** (`credit_audit.py`): 96.4% of matched functions are plain C or C with VU0 instructions that have no C form; the rest hold
  a barrier, other inline asm, a volatile cast or a helper. Count code bytes of committed sources, not functions.

## 5. Globals, data and whole files

- **A global is defined in C only** where its initial value reproduces retail's bytes at its address ([exceptions.md](exceptions.md)); until then it is
  `extern D_XXXXXXXX` (eight digits: `D_00000FA0`, the checker resolves only those). `.rodata` (0x217380-0x250580): `extern const`, since a namespace-scope
  `const` is file-local in C++ and dropped. `.data` from 0x250580; a C++ global goes to `.data` even with no initialiser; `.bss` (from 0x27B300) is a
  `static` of the one file that uses it, in the address order. A `lui`/`lwc1` pair aimed at `.rodata` is a literal or an `extern const`; aimed at `.data`
  a variable. A constant retail builds with `lui`/`mtc1` (0.25f) is pooled when written as a literal: no source form has matched.
- **A global built at startup** makes the compiler write `__static_initialization_and_destruction_0` and a `_GLOBAL_$I$` (`config/us/generated.tsv`);
  a **function-local static** with a constructor gets a guard `_$tmp_K.N` (`config/us/statics.tsv`); a brace initialiser that runs once is a CLOBBER
  (`include/ring_params.h`, docs/toolchain notes).
- **Proving a file** (`config/us/whole_files.tsv`): the constructor list (`D_0027B130`) names each file's `_GLOBAL_$I$`, so it gives its end; its start comes
  from its data. GCC aligns a jump table to 16; a literal read once sits before its function's jump table; vtables come after everything else in a file's
  `.rodata`; the compiler has one read-only section (read-only data apart from the files' code is a file with no code, an empty code range); an aggregate
  aligns to 8 (16 if asked), so a word array can be the tail of the object before it; the linker pads before a file's `.data`/`.rodata` to its alignment.
  A cut the data bounds only to a range is a choice: say so in both heads. One file is one flag set.
- **A match can wait on its whole file** (0x1E1E30: `make_whole_files.py --land` cannot merge a `SEQNODE` with more fields than the file holds; one
  shared declaration would land four). A registry source without its SPDX line loses it in `src/`: fix the registry copy. `data/matching/include/` is the
  copy `try.py` compiles against: edit `include/`, then copy. Check a converted data piece against retail on its own (the linked section against the
  bytes at its address): one build shows every bad conversion, the image diff only the first shift.
- **The early `%hi` before a save call** (`%hi(B_003D4A60)` kept in a saved register across it; SetGameCoins and three more): CSE1 reuses the `high` when
  a second use exists. The only wording that gives 0 is a dead helper parameter, which is not allowed; open: a real second use of the table.

## 6. Waves, workers and landing

- Tiers: Haiku up to 400 bytes, Sonnet 401-1,000 (and near misses: 40 of 92 matched against 28 of 420 for Haiku retries), Opus above and for leading.
  Workers write in scratch, never in `src/`, one function each, contiguous functions to one worker; the brief states the rules and the bound. The lead
  lands after `make elf`. A wave of 15 workers matched 18 functions at about 241k worker tokens a match. Check `claim.py status` for claimed functions
  with 0 runs (workers claim past their count). Sly 1's pilot: 270k tokens per code fix from agent review of paired Sly 1 bodies, so run pairing as scripts.
- **Worker misreports to check:** "needs a mult1 helper" (Sony's gcc emits it from C), "needs sony29" on a listed function, guessed string literals.
- `adopt.py` keeps the lowest score, banned or not; a clean rewrite must be copied over by hand where it kept inline asm. The export skipped the SDK
  range and hand `.cpp` drafts once: check `nonmatching/` counts after changing it. A function's draft in `nonmatching/` compiles with the build its
  address is listed for.
- Land with `make land PROGRESS=0 ONLY="0x..."`, then commit `config/eu/`, `progress/` and the README table; stage by name. A function that no longer
  reproduces PAL is a finding for the commit body.

## 7. Domain facts

- **VU1:** no debug info (no DWARF, `.mdebug`, line sections), names come from the code. `.DVP.overlay.*` are zero placeholders; microcode is in `.vutext`
  as overlay chunks of at most 256 instructions (pitch 257, so compare with every instruction offset). Entry addresses are not constants in code (one
  function builds `MSCAL` words: `(byte address) >> 3 | 0x14000000`); a run that logs VIF1 uploads finds them. `vuasm.py` round-trips the text (0.9% stay raw
  `.vu` words); keep the generated source in `work/`. See [vu1-microcode.md](../game/vu1-microcode.md).
- **Sound:** 989snd without MIDI, engine on the IOP from an embedded module; banks are read by raw sector (a scan finds each bank twice: the compressed
  copy starts with the same literal bytes); version 3 banks read with OpenGOAL's 989snd v2 layout. See [sound-banks.md](../game/sound-banks.md).

## 8. Tools and environment

- Slice a memory-mapped image with a bounded window (`image[offset:]` on a 2.7 GB disc copied the rest: 20 minutes). Run tools with `.venv/bin/python`
  (`rabbitizer`, `pyelftools`). macOS `sed -E` has no `\s`; zsh has no `mapfile`, does not word-split variables. A build directory remembers its
  absolute path. The Linux compiler needs Docker running (`open -a Docker`; `compile_unit.linux_runner`, `EE_LINUX_RUNNER`).
- The container mounts only the repository: probe files go under `work/`, not `/tmp` or the scratchpad.

## 9. Reported elsewhere, not tested here (*unverified*)

A loop retail does not strength-reduce: `goto test; body: ...; test: e = &T[j++]; if (...) goto body;`. A dead store kept in retail is a load-order clue:
write the load before the stores. Tail-call thunks (`j` plus delay-slot setup, `return target(...)`) are a family worth a tool when numerous (here 3).
Source-file boundaries can be inferred from relocations where a binary keeps them (the retail executable here has none).

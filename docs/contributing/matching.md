# Matching a function

How a function is judged, and what usually fixes a near miss. Setup: [compiler-identification.md](../build/compiler-identification.md);
the assembler step: [assembler.md](../build/assembler.md). Surprises that cost time: [lessons.md](lessons.md). Tools that search for the fix: [search-tools.md](search-tools.md).

## The score

`python3 scripts/matching/try.py <address> <file> [--lang c|c++]` compiles a source with the original compiler and assembler and
compares it with the retail function. It prints `score N` and a side-by-side diff (retail left, ours right).

- **`score` is a count of instruction words, not bytes or a percentage.** Both functions are cut into 4-byte instructions with the
  relocated fields masked, then diffed as sequences. Every block that differs adds the *larger* of the two block lengths (one extra
  instruction in ours: 1; three retail instructions replaced by two of ours: 3). Every call or `%hi`/`%lo` pair that would link to a
  different address than retail's adds 1 (the header says `N link`).
- **0 is a match**: the same instructions, and every relocation resolves to retail's address. Only then does a function belong in `src/`.
- The same number is the `score` column of `nonmatching/MANIFEST.tsv` and the `best` column of the working registry
  `data/matching/functions.tsv` (the lowest score tried). Its `size` column is the size of the function in an older split of the
  executable, so it can differ from the chunk size in `build/splat/asm/` by the alignment padding (or, rarely, a few instructions).
- A score of 1 or 2 is usually one of the things below; a score in the tens is usually a wrong signature or a wrong structure.

The permuter (`scripts/matching/permute.py <address> <file> --write`) tries other orders of independent statements and keeps the
best score. `scripts/matching/judge.sh` is the one-command form for a candidate compiler.

When a function matches, `make src` publishes it, `make elf` rebuilds the image and `make unit UNIT=<module>` must say every
function of the module still links from C. 

## What usually fixes a near miss

Seen here (SN GCC 2.95.3 build 1.36, `-O2 -G0`):

- **A missing leading argument.** The callee takes `(a, b)` and the draft passes `(b)`: the register that should hold `a` is not set
  up, so the diff shows one extra or missing `daddu`. Count the argument registers the callee reads in retail.
- **A fifth argument** shows as an `addiu $t0, $a0, 0xC10` in a delay slot. It is `f(a0, a1, a2, a3, a0 + 0xC10)`.
- **Pointer arithmetic is scaled by the type.** `f32 *p; p += 4` adds 16; retail's 4-byte step is `p += 1`. Same for `s64 *` (`+ 2`
  is 16 bytes).
- **The unused middle parameter.** A function that reads `$a0` and `$a2` takes three parameters, the middle one unused.
- **128-bit returns and arguments** (`lq`/`sq`, `por $a0,$zero,$v0`): `typedef int QW __attribute__((mode(TI)))`.
- **A constant folded into a loop.** `bit = 1 << n` first becomes an `addiu`; write the loop with a counter and a bit that shifts.
- **Return type.** The first temporary after a call in `$v1` means the callee returned a value; `$v0` means it is `void`. `sltiu` is an
  unsigned compare, `slti` signed.
- **Branch sense.** Inverting the test text (`x >= 0 {A} else {B}` against `x < 0 {B} else {A}`) changes which arm falls through and
  how the delay slot is filled. Try it before anything else.
- **A hazard `nop` that is missing** is the assembler, not the source: see [assembler.md](../build/assembler.md).
- **A constant GCC keeps in a saved FPR across several calls** (frame 0x50 where retail's is 0x40, retail rebuilding `lui`/`ori`/`mtc1` at each
  call). Wrap the repeated call in a `static inline` function that holds the constant (`static inline int Near(float a, float b) { return
  FFloatsNear__Ffff(a, b, 0.0001f); }`, as `UpdateStreamAmbPositional` does): each inlined body is a block of its own to CSE. It took func_00150F58 (score 8)
  and func_00151018 (7) to 0, and `PresetTarmissAccel` from 63 to 46; the draft that named this a wall was wrong.
- **A callee's argument that is already in place.** A callee declared `f(void)` that reads `$a0` matches in its own bytes, but the
  caller then compiles differently even when the argument is already in `$a0` (no move shows): the dependence graph changes and with it
  the prologue's save order. 0x23FE78 differed only in `sd s6`/`sd s7` order until `func_0023F850(limit)` got its real parameter
  (2026-11-12). Read the callee's first instructions for `$a0`-`$a3` before blaming the scheduler.
- **A store retail puts in a delay slot** must be a plain store: a `volatile` one never fills a slot. Keep the volatile read and write
  that one store through a plain pointer (`sceDmaReset`, 2026-11-12; the packet-writer lesson in [lessons.md](lessons.md) is the same
  for a read).
- **SDK range: `sd` saves.** Retail saving with `sd` (not `sq`) means Sony's gcc 2.9; score with `TRY_ASSEMBLER=sony29` when the
  address is not yet in `config/us/sony_gcc29.txt`. `sq` saves in the range mean SN's compiler (0x2325E0 was listed by mistake). Sony's
  gcc also emits `mult1`/`multu1` from plain C: [compiler-identification.md](../build/compiler-identification.md).

Reported by other PS2 decompilations with the same compiler family (Ratchet & Clank 1, [rac1-decomp](https://github.com/OpenRAC/rac1-decomp)
`docs/LEVERS.md`, build 1.14 at `-G2`, so verify before relying on one):

- Statement order: the last independent store tends to be emitted first; the permuter finds the order faster than reasoning.
- Copies that survive CSE: reading a value twice (test, then assign), `n = h->count++`, re-reading a global at each use, one local per
  use for a constant that retail rebuilds.
- When retail copies an address into a second register, drop the pointer local and write the address out at each use.
- A plain `w = B + 12` is hoisted to the top of the function by GCSE; write the address where it is used.
- Return shape: `if (x < 0) return 0; return 1;` and `return x >= 0` compile differently; two identical `return x;` get cross-jumped,
  so assign in each arm and return once.
- Struct and array access: a member load can move above stores that a cast pointer's load waits behind; `a[2]` folds the offset
  into the load, a cast pointer does not. Give structs their real member types (an all-`u_char` struct copies with `ldl`/`ldr`).
- `addu` operand order follows how the sum is written: `T[i].f` base first, a scaled index kept in its own local gives base first.
- A division by a constant that is not a power of two is a real `div` with a zero check; a power of two gives the `sra` bias idiom.
- `movz`/`movn` only appear when the arm sets a full register from a register; a memory source keeps the branch.
- `volatile` keeps an access out of a delay slot and fixes store order; a redundant reload next to an unfilled delay slot is a sign of it.
- Loops: an explicit zero-trip guard (`if (i < n) { do { } while (...); }`) puts the invariant between the test and the loop head;
  separate counters for unrelated uses; an explicit `off += 4` keeps the address from being strength-reduced.
- Register allocation follows `floor_log2(refs) * refs / live_length`, highest first; splitting a statement raises the reference
  count, and block-local temporaries per case change it again.
- Stack slots follow when a variable becomes addressable; declare shared buffers once at the top.
- Switches: GCC builds a jump table only with five or more case nodes; a `case` equal to the default is dropped.
- `long` is 64 bits and `long long` 128 bits; a `dsll32`/`dsra32` pair is a 64-bit value narrowed to `int`.
- Compiler diagnostics: `-da`, `-dL`, `-dS`, `-dG` dump the RTL passes.

Reported by OpenThievius (Sly 1, same SN 2.95.3 family, [sly1-decomp](https://github.com/OpenThievius/sly1-decomp) `docs/AGENT_WORKFLOW.md`).
Each one below was re-checked here on a small control compiled with `compile_unit.py` (2026-11-02); the ones that did not reproduce are listed after:

- **`Pair p = { a, b };` calls `memset`** (and saves two more s-registers around the call); assigning the members one by one does not. Write retail's form: a
  `jal memset` with `li a2,8` at the top of a function is an aggregate initialiser, and a function without it assigns the members.
- **`i * a` against `a * i`** gives `mult v0,a0,a1` against `mult v0,a1,a0`: the operand order of the source is the operand order of the `mult`.
- **`switch` on 0, 1, 2 against an `if` chain** compile differently: the `switch` makes a compare tree (`beq`, `slti`, `b` + `nop` to a shared return), the chain
  gives `bnez`, `beq` and a `movn` for the last arm. Below five cases there is no jump table, so which one retail has is told by that shape, not by a table.
- **`(unsigned char)*p++` passed straight to an `s8` parameter** keeps the `lb` test and the `lbu` load apart and makes a `bnez`-over-body loop; a `u8 c = *p++`
  local folds them into one and gives a `beqzl`/`bnezl` loop. Try the local when retail has one load, the cast when it has two.
- **`extern int T[][2]` read as `T[i][1]`** gives `lui`, `sll`, `addiu`, `addu`, `lw 4(v1)`; `U[i * 2 + 1]` gives `ori a0,a0,4` and a different add order. For a stride-8 table
  of pairs, try the 2-D declaration (or a pair struct) before the flat one.

Not reproduced here (no change in the control): `__builtin_fabsf(x)` against `x < 0 ? -x : x` (both give `abs.s` with `-ffast-math`), and a store through
`*(int *)((char *)o + 0x708)` against a member store (same code for three stores). They may matter in a larger function; don't start with them.
Already covered above or in the rounds below: the `[a..z]` to `[b..z, a]` store rotation, `sp[N]` sizing from the frame, the hidden leading argument, the dead local for a frame
with no stores, callee return type, and Sonnet on a near miss with the diff in hand (theirs: 40 of 92 matched, 43%, against 28 of 420 when Haiku retried).

## Walls

Patterns the source cannot reach (record them in the file and move on):

- Hand-written assembly: trapping `add`/`addi`, `$at` used as a general register, MMI and VU0 sequences in delay slots.
  `config/us/handwritten_asm.txt` lists the functions spimdisasm marks as hand-written; regenerate it with
  `python3 scripts/matching/handwritten.py`. A lead dealing out work leaves them out of the pool.
- **VU0, MMI, lane moves and COP0 outside the inline kind.** A function over the 10% share (`config/us/blockers.tsv`) is a permanent
  blocker and stays original assembly. A framed function at 10% or less is compiled C that uses the shared helpers of
  `include/vu0inline.h` and `include/ps2inline.h` (docs/build/inline-asm-helpers.md); run `try.py` with `TRY_VU0=1`. No asm of
  your own: a vector operation no helper gives is `SKIP need-helper <instructions, semantics>`. Stop after about ten compiles.
- A chunk of the split that is a fragment of a larger function (`addiu $sp,$sp,N ; nop` remnants, a single instruction) is a splitting
  question, not a C question.
- A register-allocation difference that three different wordings leave unchanged.
- A delay slot that retail leaves unfilled where ours fills it, with no visible trigger.

## Teams of workers

Several workers (people or AI assistants) can match in parallel; AGENTS.md has the rules. The procedure:

1. The lead picks the functions (`python3 scripts/list_functions.py --status asm --sort size`) and splits them: no two workers
   share a function, contiguous functions go to one worker (they often belong to one class).
2. **Pilot first.** Start two workers on twelve functions each and read both reports before launching the rest. If a third of the lines name
   the same difference (the 2026-11-05 wave N2 sent 40 of 57 claims into one assembler padding difference no source change fixes), stop the
   wave and find the cause; a toolchain question costs a pilot, not a wave.
3. Each worker keeps its sources in its own scratch folder, runs `try.py` until `score 0` or about ten compiles without progress,
   and reports one line per function: `EXACT`, `NEAR` (what still differs) or `SKIP` (why). A worker that runs a make target passes
   `PROGRESS=0` (every worker brief says so).
4. A worker's `EXACT` is not a match. The lead puts each source in place, runs `make elf` and `make unit UNIT=<module>`, and sends a
   function that breaks the build back to `nonmatching/`. A function inside a whole file (`config/us/whole_files.tsv`) has no
   per-function copy in `src/`: `record.py` (`make land`) puts its source into the whole file in place of its `INCLUDE_ASM` line and
   registers it only when the whole range proves again (`make_whole_files.py --land 0xADDR`, `--dry-run` to try); otherwise the file is
   unchanged, the function stays `tried` with best 0 and the run says why (a type or declaration the file already has differently, most
   often). Check it with `make unit UNIT=src/<whole file>`. Workers match as before, one function per source in their scratch folder.
5. Stop and write the best attempt to `nonmatching/` when the code isn't a function (reads registers it never sets, no return),
   is hand-written, needs an instruction C cannot ask for, or three different wordings give the same wrong bytes.
6. Workers use the shared types of `include/` when they exist (AGENTS.md "Preservation first"). A type a worker has to define
   locally carries the function's address as a suffix (`List_11A338`) so files merge without clashes; the lead moves it into a
   shared header (or renames it) when it lands related functions together.
7. **At score 0, read what `try.py` prints after the diff.** `RULES` is check_source.py's verdict (a source that breaks a rule is parked,
   not matched); `WARNING` lines are for the reader. `WHOLE FILE` is a trial merge into the function's whole file, proved and written
   nowhere: `would land`, or the declaration the file has differently. A worker fixes that before saying `EXACT`: it costs the lead a
   landing otherwise. A C++ function in a C whole file lands by turning the file into C++ (`land()` renames it and its
   `whole_files.tsv` row once the C++ text proves). A function the lead merged by hand registers on the next `make land`.

**Which near misses to send workers to (2026-11-12).** Three batches of eight to nine workers, scored by `try.py`:

| Batch | Drafts | Brief | Matched |
|---|---|---|---|
| 1 | score 40 or less, same instruction count as retail | reword toward the registers | 0 of 9 |
| 2 | instruction count or shape differs, score 30 to 110 | list what retail does differently (offsets, widths, calls, arguments, branches) before touching registers | 4 of 9 |
| 3 | flagged by `check_calls.py` | confirm each flag by the argument registers, fix the real ones, then the rest | 2 of 12 |

A draft with retail's instruction count and a low score is a register or scheduling difference: leave it to `make search`. A draft
whose count or shape differs usually has a real mistake: a callee given the wrong arguments, a global read as bytes, a missing
call or iterator, fields in the wrong order. `check_calls.py` (run by `make nonmatching`, table in `build/check_calls.tsv`, shown in
`claim.py`'s packets) lists the drafts whose declarations disagree with matched code; about two thirds of its flags were real. A
draft's recorded score can come from a wrong call: `try.py --record --replace-best` records the honest, higher one.

## Picking work and running a local model (2026-11-06)

- **Only `asm` is open work.** `c` is a function already linked from C in the image and counted (`docs/build/progress.md`, "What is
  counted"); `matched` is a registry match not yet linked; `draft` has a compiling source in `nonmatching/`. A queue built from
  `list_functions.py --status asm` (blockers are left out by default) is the open work. A first local-model run queued the `c` rows too
  and spent about an hour re-matching 173 functions that were already counted. `list_functions.py --limit` caps what it prints: pass a
  large `--limit` and write to a file, not a terminal.
- **A local OpenAI-compatible model works as a worker.** `scripts/matching/agent_loop.py <address> --endpoint http://localhost:11234/v1
  --model <id> --tries 8` (key: `ROGUE_AGENT_KEY=local`), four at a time through `xargs -P 4`. An SDK-range function needs
  `TRY_ASSEMBLER=sony29` in the environment, otherwise the score is the default toolchain's and means nothing for it. Thinking mode
  makes a try several times slower; its `<think>` output is dropped by the loop.
- **The loop writes `data/matching/src/fn/<ADDRESS>.cpp` even when it fails**, over an existing draft. `make land` publishes every
  source in that folder whose registry row says matched, so a rejected draft reaches `src/` and a stale report gets committed. Copy
  `data/matching/src/fn` before a run and restore every function that did not reach 0.
- **Do not edit `config/us/sony_gcc29.txt` or `config/matching/symbol_addrs.txt` while workers run** (the scorer fingerprint changes);
  add the addresses afterwards and run one `make land ONLY="..."`. A registry row whose source path is an old m2c `.c`
  (`data/matching/src/auto/`) keeps being published from that file: point the row at the clean `fn/<ADDRESS>.cpp`, because
  Sony's gcc 2.9 rejects `m2c_macros.h`.
- **A model's source is a draft.** The ones that reached 0 needed hand cleanup every time: no `extern "C"` or a stray `#include`, a
  callee declared with a type it does not have, a local that only holds an argument, and in one case `asm volatile("" ::: "memory")`
  to order a store before a load. Re-judge the cleaned source before landing.
- **8-byte SDK "functions" are mostly not functions.** `addiu $sp, $sp, N` + `nop` is a delay-slot epilogue split off the function
  above; it cannot match alone. The real small ones are wrappers: a tail call (`j target`) compiles from **C** (`--lang c`, gcc
  sibling-call), not C++, which keeps `jal` + epilogue; a function with no epilogue calls a `noreturn` callee
  (`__attribute__((noreturn))` on `exit_thunk`); a `lui`/`addiu` pair before a `j` loads a string or data address.
- **A store followed by a load of an unrelated type is reordered** by gcc's alias analysis (`sh` or `swc1` put into the `jal` delay slot
  with the argument `lw` hoisted above it). Giving the stored and the loaded field the same type (both `int`) keeps retail's order
  (0x256328); with a `short` or `float` store the order stays wrong and the function is left open (0x2562F0, 0x2562B8, score 4).

## Register allocation: what decides a swapped register (2026-11-08)

Read from the RTL dumps (`-dl` local-alloc, `-dg` global-alloc, `-dG` GCSE) of five near misses that were register-only: `HitFx_GIntensity`, `UNoise__Ffff`,
`RefreshSpriteInstance`, `PostEpselLoad` and `FTaskPrerequisitesDone` (the last one a loop-form fix, not allocation). Six integer cases (`0x1733C8`, `0x1C9058`, `0x120548`,
`0x218748`, `0x1A5D98`, `0x13FAD0`) did not respond to any of these and stay in `nonmatching/`. Dump-only compiles cost nothing against the `try.py` budget.

- **sched1 runs before register allocation at `-O2`.** The allocator sees sched1's order, not the source order, so reordering statements often changes nothing.
- **A variable reassigned in its block** (`x = f(x)`, dump: "set 2 times; user var; dies in 2 places") is not taken by local-alloc; global-alloc places it
  later, in a higher register than the short temporaries beside it. Retail's chain sits higher than ours: reuse one variable. Lower: split it into fresh ones.
- **An insn's output takes the register of its first input that dies there.** Operand order is fixed before allocation (`fold` makes `1.0f < t ? 1.0f : t` a
  `MIN_EXPR` with the constant second). To keep a constant first, pass it through an inline helper: `static inline float GMin(float a, float b) { return a <? b; }`
  (`GMax` in `src/cm/RecalcCmFrustrum__FP2CM.cpp`, `GClamp` in `src/font-break/SeekSpriteInstanceFraction.cpp`).
- **Global-alloc order is by priority**, about `floor_log2(refs) * refs / live length`; the lowest free register goes to the highest priority. A short-lived value
  that retail keeps in a lower register is usually read through an inline helper's return, which shortens its live range (`PostEpselLoad`: `GetSaveFloat`,
  `GetSaveInt`; each inlined `CRef` shares one frame slot).
- **A tie goes by pseudo number, and GCSE PRE numbers its pseudos in hash-bucket order** (hash mod `(insn count before GCSE / 2) | 1`; the `-dG` dump prints
  "Expression hash table (N buckets"). Anything that changes the RTL insn count without changing the final code (a helper's return type: `RefreshSpriteInstance`,
  `LerpByte` returns `char`, not `unsigned char`) can flip which of two equal-priority addresses gets the lower register. It is a steering form: say so in the commit.
- **Structure before registers (`func_001EA9F0`, score 49 to 0).** Two empty count-down loops in retail were the empty-constructor loops of arrays of a small
  class (`CLR palette[256]`), not wait loops. Separate locals in declaration order (locals take ascending frame offsets in that order; arrays are 16-byte aligned and
  their constructor loop runs where they are declared) gave the frame. A post-increment store of an inline-constructor temporary (`*out++ = CLR(x)`) copies the
  pointer into a register per case and cross-jumping shares the tail; `arr[i].Set(v)` (address as `this`) makes that array the loop's strength-reduction base,
  `arr[i] = v` does not. `static inline int ScaleAlpha(float scale, float alpha)` keeps `scaled * (alpha * 128)` from being re-associated (a steering helper, like `GMin`).

## VU0 near misses: two tricks measured (2026-11-12)

Both come from sly1-decomp's notes (ideas only) and were measured here on matched functions with `try.py` and `TRY_VU0=1`: take the
trick out, or change it, and read the score. They separate a score of 2 from 0 on code that uses `vu0inline.h`.

- **A scalar quad that retail stores to the stack is a union local.** When retail writes the scalar vector (`VectorFromFloat`,
  `QuadFromFloat`) to a stack slot and reads it back, declare `union VU_SCALE { QW q; VECTOR v; } scale;` before the other locals and
  assign `scale.q = ...`. A plain `QW` local stays in a VU0 register and the slot disappears. Removing the union scores
  `AdjustJtXpVelocity` 0 to 22, `UpdateSwFog` 0 to 14, `UpdateDancer` 0 to 12 (3 of 3, 2026-11-12).
- **Operand order of a helper decides which registers are shared.** `VectorAdd(position, cylinder)` and `VectorAdd(cylinder, position)` are the same value and
  different bytes (the cause is not measured; only the effect is). When a VU0
  function is at 2 to 4 with a swapped `vf` number, swap the operands of every commutative helper (`VectorAdd`, `DotProduct`,
  `VectorMultiplyXy`) before anything else. Swapping them scores `Member_GetRandomPos` 0 to 2, `AttachCyl_GetRandomPos` 0 to 2,
  `GoalHit_Activate` 0 to 2, `ExplodeGadgetBurst` 0 to 4 (4 of 4). The non-commutative ones (`VectorSub`) have one order; the helper
  takes the rows first so retail's registers come out (`TransformVector`, `TransformPoint`).

**Two more wordings, measured in wave I12Q and I12V (2026-11-13).**

- **A 16-byte default in one arm of an if/else: write both arms back into the same variable and copy it after the join.** When retail
  loads a default quad with `lq` into a general register early and moves it with `qmtc2.ni` in the branch's delay slot, with one shared
  `sqc2` after, write `if (LaneX(length) < epsilon) length = fallback; else length = ScaleByReciprocalX(vector, length); result = length;`
  with `QW fallback = g_...;` read before the vector code. GCC then emits the `lq` into a general register and the `qmtc2.ni` in the delay
  slot itself. It took `DetonateBomb` 26 to 0 and `UpdateSeqnodeVjoy` 4 to 0 (2 of 2). A `VectorFromQuad` helper (`qmtc2.ni` from a quad in
  a general register) scored 9 and 12 on the same two: the asm cannot sit in a delay slot, and in `AddSafePointOnGeom` it added an
  instruction retail does not have. It helped only `AddSphereToRenderTree` (70 to 54, a value converted once outside a loop), so it
  is not in `include/vu0inline.h`.
- **A float 0.0 that retail holds in `$f20` for the whole function (a bare `mtc1 $zero,$f20`): write a literal `0.0f` at every use and
  keep no variable.** GCC hoists the loop-invariant zero. `FloatFromWord(0)` gives `daddu` + `mtc1` + `nop`, and `float zero = 0.0f` lets
  constant propagation put `mtc1 $zero` at each call (`func_001C84D8`: 50 to 44).
- **An early-clobber `vsub` (`"=&j"`) is not a helper.** It fixed the register numbers of `func_002082D0` only (7 to 4) and made
  `func_001C84D8` (+7), `CarryThrow_SetState` (+13) and one `vsub` of `PsenseFindNotice` (+2) worse: retail writes a `vsub` in place
  (`vsub d,d,s`) more often than into a third register, which the early clobber rules out.

- **A shift that retail issues after the index arithmetic: `1 << (index % 32)`.** A bare `1 << islot` is ready at cycle 1 of its block, so the
  dual-issue scheduler pairs it with the earlier `movn` and puts the `sllv` ahead of the `sra` that computes the word index. Written with
  `% 32` the shift is ready only at the `sra`'s cycle, GCC still emits a plain `sllv`, and the `sra` goes first (`CobstacleFindPathzoneBox`
  2 to 0 with `QuadAnd`; `RemoveLightFromSw` has the same form). `1 << (islot & 31)` adds an `andi`; `1U << islot` turns the test into `srl`.

Other fixes that held in wave I11S: a QW local still needed after the vector op; locals declared in retail's stack order; a typed
local struct for a global field instead of `char[]` plus a cast offset; `index = 0` inside the branch and the second loop as
`if (n) do { } while`. Not yet explained: a quad retail loads with `lq` into a general register and moves with `qmtc2.ni` (three near
misses stop there); a lane retail extracts twice with two `qmfc2`, where ours keeps one copy.

## Rulings

What AGENTS.md allows and bans, in one place (the full list with reasons and dates is docs/contributing/exceptions.md):

- **No inline asm in functions**, no register pins, no empty `asm` with clobbers, no dummy operands, no `"memory"` clobber to order blocks.
  The one shared `Sqrt` helper (`sqrt.s`, early-clobber `=&f`) is the only asm.
- **`volatile`** only on a hardware register at a fixed address (0x10000000 and up), through a pointer to a register block (a DMA channel's),
  or on data shared with hardware, an interrupt handler or another thread (a library's semaphore ids and state flags, a field an interrupt
  handler sets), where retail's code reads and writes it as volatile (the rule of sly1-decomp). Outside the hardware range, mark the line
  `// volatile-ok: <reason>` and name the register block or the handler and its address; `record.py` accepts nothing else.
- **A dead local** only as a type the original plausibly declared (retail's frame shows it); never a padding array or an invented field.
- **A callee prototype** is read from the callee's own disassembly: no return type or argument it does not have.
- **Game data** (a palette, a header read out of retail) is referenced with an `extern` at retail's address, never defined in source.
- **One assembler** (`tools/ps2eeas/Ps2EeAs-loop5.exe`: `ps2eeas` with its short-loop constant changed from 6 to 5, docs/build/assembler.md) and one flag set per source file; a function that only matches with something else stays in
  `nonmatching/`.
- Plain C++ that the original plausibly had is fine: casts, types, statement order, `goto`, a `union` when retail's frame shows two
  locals sharing a slot, a padding-virtual base class to reach a vtable slot.

## Fixes that recur in m2c drafts

From hand-shaping 31 near misses (25 matched, mostly drafts at 1 to 8 words):

- **Count the callee's arguments from retail.** A `$a0`/`$a1` left untouched before a `jal` is a passed-through `this` or argument; `$t0`/`$t1`
  set before it mean five or six arguments. A `(...)` or short prototype in a draft hides a missing leading argument (`FIsGuardInSgs(0x16)` is
  `(arg0, 0x16)`); fix the declaration before reshaping the body (about a third of the fixes).
- **64-bit tests and masks.** `if ((u64)x >> 0x3C & 1)` gets a `dsll32/dsra32` pair retail lacks: write `(int)(x >> 0x3C) & 1`, or put the
  value in an `s64` local first. A mask retail builds with `lui` or `ori` + `dsll32` is a real 64-bit constant: `~(s64)bit`, `1UL << n`,
  `0x8000L << n` (an int shift folds to another instruction sequence).
- **Parameter widths.** A `dsll32/dsra32` or `sll/sra 24` retail lacks means the parameter is `s32`/`s8`, not `s64`/`u8`; the `Si` of a mangled
  name says `s32`. A `+ 8` on a typed pointer is bytes times the element size: check retail's increment.
- **Shapes.** For a diamond that ends in `return -1`, try `c ? -1 : x` and the early return with the rare case first; `x == 0 ? a : b` against
  `x ? b : a` flips `movn`/`movz`. Two induction variables (counter plus stride offset) allocate other registers than a plain
  `for (i...)` over `base + i * stride`, or over an array of the real element type.
- **Still open** after 15 to 25 compiles each: `this`/flag in swapped saved registers (`s0`/`s1`) and the operand order of a commutative
  `and`. Neither responded to source reordering.

More fixes from the second round (22 of 29 matched):

- **A draft's `sp[N]` buffer is often too big.** Take retail's frame size, subtract the saved registers and the `$ra` slot: that is the local's real size
  (`sp[0x460]` became `sp[0x420]`, `sp[0x50]` became `sp[0x30]`). A typed struct local of that size (16 bytes for a `CRef`) gives retail's frame.
- **Hidden leading parameters.** A draft parameter named `arg2`/`arg3`, or an untouched `$a0`/`$a1` before a `jal`, is a parameter the draft lost; the
  prototype that m2c prints for the callee can be one short for the same reason. Declare real argument lists, and `void f(s8 *)` for callees that
  return nothing.
- **64-bit flag tests.** Both `(int)(x >> n) & 1` and a signed local (`s64 flags = x; if ((flags & 1) == 0)`) remove the `dsll32/dsra32` pair;
  which one matches depends on the function, so try both.
- **Loops.** A loop that returns the element on a compare or null exit: `for (;;) { e = table[i]; if (e == NULL || *e == key) return e; i = (i + 1) % N; }`
  over a typed `extern T **table`. A search loop: `while ((node = node->next) != NULL) { if (match) { ...; break; } link = &node->next; }`.
- **Still open** after this round: `this`/flags kept in a different register than retail's (`$a0` against `$a3`, `$a1` against `$a2`) and a
  delay slot that retail fills with `sd $ra` where ours picks another instruction.

From waves N2 to N4 (2026-11-05, Sonnet workers, many matches in the SDK range):

- **Sibling call: `.c` or `.cpp` decides it.** Retail's `j callee` after the frame restore (a tail call) only comes out of a C source; a C++
  source keeps `jal` plus the epilogue. Look at retail's last instruction first (`253C80` needed `.c`; `23EA30` needed `.cpp` because C turned its
  `memcpy` into a tail call retail lacks). In a `.c` file leave out `extern "C"`.
- **The element type of an extern table.** An m2c `sll 4` or a wrong scalar for a table is the element type: `extern int B_0044EF80[]`,
  `int *D_002C4660[]` (`23AAC8`, `241440`, `232BB8`).
- **A missing store or argument.** A stack buffer whose slot 0 holds an argument (`int buf[4]; buf[0] = arg0;`), a callee that takes 4, 5 or 8
  arguments with constants appended (`func(a0, a1, a2, 0, -1)`), a second parameter the draft never named (`func_0014F3C8(char *, QW pos)`).
- **A callee that never writes `$v0` is `void`**, not `int` (`ReadVector__18CBinaryInputStreamP6VECTOR`, two matches).
- **Modify the parameter in place** (`address &= 0x0FFFFFFF; address |= 0x80000000; return address;`) where a draft used a second local.

From the third round (59 of 71 matched; most drafts held an `ldl`/`ldr`/`sdl`/`sdr` pair lifted to `asm`, which plain C replaces):

- **Unaligned 8-byte accesses are plain C.** A copy through memory or the stack is a struct of eight bytes assigned whole
  (`struct Bytes8 { char bytes[8]; } saved = *(Bytes8 *)(self + off); ...; *(Bytes8 *)(self + off) = saved;`), which also gives retail's frame size.
  A load from a read-only address into an argument register is a packed struct (`struct UL { unsigned long v; } __attribute__((packed));
  extern const UL RO_xxx;` and pass `RO_xxx.v` to a `long` parameter). Declare the symbol at the address the `ldr` uses (the lower one), not at
  the end of the `ldl` range, or the link check reports mismatches although the instructions agree. A by-value `char[8]` parameter goes through a
  stack copy instead.
- **m2c's int-shift constant chains are wrong.** `(0xBFFFFFFF << 5) | 0x1F` or `0xFFFB << 0x10 ...` shift an `int`: the compiler may fold them to
  another sequence, load with `lwu`, or drop the store as undefined. Write the 64-bit constant (`~(0x8000L << n)`, `~(1L << 35)`).
- **Float arguments.** `mtc1 $zero,$f12` or `lui` + `mtc1 $f13` before a call are `0.0f` and `1.0f` arguments, not integer zeros.
- **A callee declared with an m2c return type it does not use** (`M2C_UNK f()` for a function that returns nothing) changes the register chosen for
  constants after the call: try `void` when only a `$v0`/`$v1` choice differs.
- **Operand and statement order.** `target == items[i]` against `items[i] == target` flips a `beq`; `if (s >= 0) { if (s < 3)` keeps `bltz` and `slti`
  where `&&` gives `sltiu`; a ternary (`return e >= 0 ? base + e * 4 : 0;`) stops a second `return 0` being cross-jumped; a statement written last
  can be emitted first, so move the first-emitted store to the end of the source.
- **Typed structs for virtual-call loops.** A vtable struct (`s16 offset; fn method`) and an object struct (`vtable`, `next`) matched where an `M2C_FIELD`
  chain gave other registers; `for (node = head; node != end; node = node->next)` gives retail's bottom test.

From the fourth round (119 of 246 functions that were 1 or 2 words from retail matched; 93 of the rest are not functions):

- **Some "functions" are fragments of the split.** A chunk that is a lone `addiu $sp,$sp,N` plus a `nop`, a single store, or a stray `daddu`, with no `jr $ra`, is
  the delay slot or tail of the previous function, cut off at a wrong boundary (93 of the 2,156 unmatched functions at this point, 65 of them two instructions).
  C cannot express them: skip them at once. `scripts/matching/functions.py` marks a `func_` chunk of at most 32 bytes with no jump as status `fragment`, and the
  nonmatching export leaves it out; the bytes stay assembled from retail.
- **Hidden leading arguments and prototypes decided most of the matches again.** An untouched `$a0`/`$a1` before a `jal` is a passed-through argument (`this`);
  `$t0`/`$t1` set before it are a 5th/6th argument; `mtc1`/`lui` + `mtc1 $f12` is a float argument; `daddu $a1,$zero,$zero` with `$a0` untouched is `(arg0, 0)`.
  A callee that returns nothing is `void` (this changes which of `$v0`/`$v1` holds a constant afterwards); sometimes the reverse (`void *`) fixes a swap.
- **Pointer scaling in m2c drafts.** `s32 *p += 4` is a 16-byte step (`+= 1`), `p + 0x30` on an `s32 *` is `0xC0` bytes (cast to `char *` or write `+ 0xC`), and an
  `sll 4` where retail has `sll 2` means the element type is wrong (`extern s32 T[]`, or a typed entry struct).
- **Store and statement order.** The compiler emits the last-written store first, so rotate the source until the store retail emits first is written last. For two to
  five independent stores, generate random orders and judge them (about 60 compiles found score 0 in two functions); they are plain statement reorderings.
- **Compare shape.** `x <= 0 ? 2 : 1` and `x > 0 ? 1 : 2` give `slt/movn` and `slti/movz`; `id != x[j].id` over `x[j].id != id` flips `bnel`; `if (b < a) return -1;
  if (a < b) return 1;` replaces `!(a < b)`; `min.s`/`max.s` operand order follows how the ternary reads.
- **Link-check names.** The check knows `D_`, `B_`, `RO_`, `jtbl_` plus eight hex digits, so a float named `D_FLT_...` or `g_...` is a link mismatch even when the
  instructions agree: use `RO_<addr>`/`D_<addr>`. A symbol absent from `config/matching/symbol_addrs.txt` also scores 1 for a function whose words are right.

From the Haiku trial (8 workers, 120 functions of at most 400 bytes scoring 3 to 8 words from retail, run to the OpenThievius tier-by-size method: own output folder,
about ten compiles each, `EXACT`/`NEAR`/`SKIP` reports, only the lead lands; 67 of 120 matched, 56%):

- **The placeholder `sp[0x400]` is the commonest single error.** m2c drafts of 349 near misses carry `char sp[0x400]` as their stack area. The real size is what is left of the
  retail frame after the saved registers and `$ra` (a 0x40 frame with `sq` at 0x10/0x20/0x30 leaves `sp[0x10]`; `vprintf`'s 0x450 frame with `$ra` at 0x420 leaves `sp[0x420]`).
  `scripts/matching/fix_stack.py` tries every multiple of 0x10 below the frame size: it matched 87 of the 349 and improved 325.
- **Virtual calls:** put the vtable, the offset and the method in separate typed locals, in retail's order (offset first, then method), instead of m2c's temporary chain; it fixed a `$v0`/`$v1`
  swap in several functions. `(*arg1)++` is not `*arg1++`.
- **Float arguments:** `mtc1 $zero,$f12` and `lui`+`mtc1 $f13` before a call are two `f32` parameters (a struct literal scored 22); the float store retail puts in the `jal` delay
  slot is written last. For a float store then load, the source order of loads and stores is the asm order.
- **Return shape:** a shared epilogue (`FJobRunning`) wants one result variable; early returns (`if (x != y) return x - y;`) give retail's `beql` with the return in the delay slot; an
  inverted if/else (null test first, stores in the else) turns `bne` into `beq`.
- **Haiku's profile:** it matched the small, mechanical cases (callee arity, buffer size, float parameters, return shape) and stopped at register allocation and scheduling, as
  the Sonnet rounds did; it also refused to copy sources with pins or empty `asm` and rewrote or skipped them. Stop after two or three wordings when the only difference is
  store order, a float constant's load position or which of `$v0`/`$v1` holds a vtable pointer.


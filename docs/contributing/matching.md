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
function of the module still links from C. A function that matches only with GNU `as` is added to `config/us/gnu_as.txt`.

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

## Walls

Patterns the source cannot reach (record them in the file and move on):

- Hand-written assembly: trapping `add`/`addi`, `$at` used as a general register, MMI and VU0 sequences in delay slots.
- A chunk of the split that is a fragment of a larger function (`addiu $sp,$sp,N ; nop` remnants, a single instruction) is a splitting
  question, not a C question.
- A register-allocation difference that three different wordings leave unchanged.
- A delay slot that retail leaves unfilled where ours fills it, with no visible trigger.

## Teams of workers

Several workers (people or AI assistants) can match in parallel; AGENTS.md has the rules. The procedure:

1. The lead picks the functions (`python3 scripts/list_functions.py --status asm --sort size`) and splits them: no two workers
   share a function, contiguous functions go to one worker (they often belong to one class).
2. Each worker keeps its sources in its own scratch folder, runs `try.py` until `score 0` or about ten compiles without progress,
   and reports one line per function: `EXACT`, `NEAR` (what still differs) or `SKIP` (why).
3. A worker's `EXACT` is not a match. The lead puts each source in place, runs `make elf` and `make unit UNIT=<module>`, and sends a
   function that breaks the build back to `nonmatching/`.
4. Stop and write the best attempt to `nonmatching/` when the code isn't a function (reads registers it never sets, no return),
   is hand-written, needs an instruction C cannot ask for, or three different wordings give the same wrong bytes.
5. Types a worker defines carry the function's address as a suffix (`List_11A338`) so files merge without clashes; the lead renames
   them when it lands related functions together.

## VU0 functions (inline `asm`)

m2c cannot read VU0 macro code, so these functions are written by hand: C for the glue, `asm` blocks for the VU0 instructions
(`QW` is the 128-bit type of `include/sly2.h`; vectors by value arrive in one 128-bit register). A pilot on the 20 smallest VU0-only
functions without a source gave 5 byte matches without register pins and 1 with pins (not published), 14 near misses (scores 2 to 10).
What moved the score:

- **Loads and stores.** `"m"(((QW*)p)[n])` gives `lqc2` with retail's addressing, `"=m"` with `sqc2` inside the asm gives `sqc2`.
  A C store after a `qmfc2` asm adds `qmfc2.ni` + `sq` that retail doesn't have: store inside the asm when retail uses `sqc2`.
- **Several small asm statements, not one block.** The compiler can only schedule between statements, so split where retail has a
  compiler instruction (`lw`, `lui`/`mtc1`, `sq`, call arguments) between VU instructions. Put the load side (`lqc2`/`qmtc2`) in one
  non-volatile asm, the store side (`qmfc2`/`sqc2`) in its own single-instruction asm, and chain them with a dummy `"=r"(int fence)`
  output feeding the next asm's `"r"` input. A one-instruction asm placed after a branch or call computation lands in its delay slot.
- **Inputs that exist only for their side effect.** `"f"(constant)` forces the constant to load before the asm; a `"$4"` clobber with
  `lw $4` inside the asm reproduces a hidden argument copy.
- **Registers and slots.** Declare pointer locals in retail's load order (it decides `$v0`/`$v1`); `"m"` operand order decides stack
  slots (spills are allocated in reverse use order); reuse one variable for a loaded value (`obj = obj->scale;`) to keep a callee-saved
  register. Read each callee's real argument list from the asm first.
- **Left over.** Scheduling and register allocation around the asm (which s-register holds which parameter, where `ld $ra` lands,
  `beql` against `beqz` with the VU move in the delay slot). Run the permuter after the first compile: it fixed a load order in five compiles.
- **Second round (pin-free).** Scores moved most from: a `"=r"(fence)` output on the first asm consumed as an input by the next
  (it also fixes branch and delay-slot layout, not only order); writing a compare as `eps > sum`; `"+r"(obj)` on the main asm to
  force a hidden `daddu v0,a0` copy; repeating an `"m"` operand to raise a pointer's use count (flips `s0`/`s1` allocation).
  Non-volatile store asms scheduled after `ld $ra`. Not reachable without pins or barriers: a `sqc2` that retail places after the
  epilogue loads, and a VU instruction in a branch delay slot (the filler never moves an `asm` there).


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
- **VU0 functions taking or returning a vector.** Type the parameter and result `s128`, make the `qmtc2`/`qmfc2` asms non-volatile, feed the first one's
  `"=r"(fence)` to the next asm, and leave the last `qmfc2` non-volatile so it is scheduled after `ld $ra`. Computing an address into a local before
  the `sqc2` asm puts the `addiu` in the delay slot.
- **Still open** after this round: `this`/flags kept in a different register than retail's (`$a0` against `$a3`, `$a1` against `$a2`) and a
  delay slot that retail fills with `sd $ra` where ps2eeas picks another instruction.

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
- **Lifted VU0 code can lose an instruction** (a `vsqrt Q, vf1x` was dropped in one function): compare the asm blocks with retail.

Three functions reach score 0 only with a construct `AGENTS.md` does not allow, so they stay in `nonmatching/` at their clean scores:
`func_0017A468` (2) and `RefOpVectorProjectNormal` (4) match when the two pointer loads that feed the `lqc2`s are read through `volatile` pointers
(which fixes the load order the scheduler otherwise swaps), and `GetActadjPositionGoal` (3) when `asm("" ::: "$5", "$6")` sits before the call (which keeps
the object pointer in `$a3`). They show what the scheduler needs, not what the original source had; a different original shape that gives the same order
is what to look for. `PseqnodeFind` is landed: retail has a 16-byte frame with no stores, and an unused local `s8 frame[0x10]` is what a dead
variable looks like after optimisation.


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
- **Assembler, not source.** A short loop retail leaves unpadded (a `nop` that ps2eeas adds before the branch) is fixed by listing the address in
  `config/us/ps2eeas_loop5.txt` (or `gnu_as.txt`); run `TRY_ASSEMBLER=ps2eeas-loop5` before trying wordings on a 1 to 2 word loop miss.
- **Not reachable in C or without a trick:** a VU instruction in a branch delay slot (`VecMaxOfVerts`, `VecMinOfVerts`, `Swarm_PriderNearest`), a float taken from the low
  word of a `QW` (`lq` then `mtc1`), `j exit` thunks, and a redundant conditional re-store written only to move a scheduler decision (`SetAmbRange` reaches 0 that way and
  stays in `nonmatching/`).

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

The two functions that match only with a trick, after a longer search (five seeds of 500 mutation compiles each, hand-built load placements, a single `asm` block with both pointers as inputs, a real
C++ virtual call, other parameter lists):

- `func_0017A468` stays at 2. Retail loads `rot` (`0xF90`) then `pos` (`0x60`) before the first dependent `lqc2`. Every clean form emits the two loads in the other order, or one of them after the
  `lqc2`: with both loads written before the asms the scheduler puts the later one first, and which register each gets follows the declaration order, so source order cannot give both the right order and the
  right registers.
- `GetActadjPositionGoal` stays at 3. Retail keeps `target` in `$a3`, ours in `$a1`: two registers are occupied in retail that nothing in the source occupies. A real virtual call
  (`target->v4()` with `virtual` methods, vptr at `+0x18`) compiles to the same code as the hand-written vtable, so the call is not the cause; extra, wider or float parameters did not change it.

Both are best left until another function with the same pattern shows what the original source did.

From the second Haiku trial (8 workers, the 120 smallest unmatched functions, 8 to 72 bytes; 72 of 120 matched, 60%):

- **Arguments are `$a0`..`$a3` and `$t0`..`$t3`.** On this target `$t0`-`$t3` are the 5th to 8th arguments (an 8-argument call matched), and a callee that returns another function's result leaves `$v0` untouched after the `jal`.
- **A `lui` with no `addiu` before a store is a common-subexpression leftover, not an argument.** `ResetSlotheap(&B, &C, &D)` with `$a1`/`$a2` loaded as `0x2E0000` is `ResetSlotheap(&B)`
  (`void ResetSlotheap(char *)`, the object declared `extern char`): five `Reset*Heap` functions matched once the prototype lost its two extra arguments. Check the callee before adding arguments.
- **Widths.** `int x` with `1UL << x` matches where `long x` gives `dsll32/dsra32`; `dsrl32` by 1 then `andi` is `(u64 >> 33) & 1` with a `u64` return; a `short` store of `(short)(f * 1000.0f)` is an `s16` field.
- **Branch shape.** `if (cond) ; else result = 0;` flips the `c.lt.s` direction where `!(f < 0)` does not; a separate `return 0` for a null case keeps a dedicated `jr`; `beql` to a `return 0` is
  `if (x != 0) { ...; return 1; } return 0;`; flipping a compare operand (`nKey == pEntry->nKey`) fixes a `bnel` operand order. A do-while against for/while changes the `bnel`-delay layout more than the operators.
- **Structs.** A struct of `char[4]` or `char[8]` assigned whole gives `lw/sw` and `ldl/ldr/sdl/sdr`; a struct of arguments on the stack takes its store order from the assignment order; a `QW` result of `qmtc2.ni`/`vmulx`/`qmfc2.ni` in one `asm` statement matches at once.
- **Still open:** eleven constructors (`0x110CD0` to `0x111380`: `new(N)`, two vtable stores, two zero stores) keep the new object in `$v0` where retail copies it to `$v1` right after the call and uses `$v0` and `$a0` for the vtable
  addresses; no statement or declaration order moved it, and the same blocker appears in all eleven, so it is one source pattern. `TickReadCount` needs `mfc0 Count` (COP0) and stays assembled; `ExitThreadStub` is `addiu $v1,0x23; syscall`.

From the third Haiku trial (8 workers, the next 120 smallest unmatched functions, up to 90 bytes; 73 of 120 matched, 61%):

- **A float argument written as a hex int** (`0x3F800000`) is converted to a float, not reinterpreted: write `0.0f`/`1.0f` for `f32` parameters. A named `float zero = 0.0f` local gives `mtc1`+`swc1` where a bare `0` gives `sw $zero`.
- **Unused middle parameters count.** A dropped parameter moves later arguments into the wrong registers: a dummy `int unused_a1` puts `arg2` in `$a2` (three functions). A stack constant stored before a call is
  usually a field of a local object passed by address (`{int type = 0x16; float value}`), not a 5th argument.
- **Store order rotates.** The compiler emits the last source store first: for retail order `[a..z]` write `[b..z, a]`; a store that retail puts in a `jal` delay slot is usually the last store in the source; a load
  retail does in a delay slot is read into a temp before the call (`next = cursor->next; Free(cursor);`).
- **Data widths.** A byte table is `unsigned char[]`; a 16-bit field read by `lhu` and tested as 32 bits is an `int` (`sll 16`, not `andi 0xFFFF`); address math `B + 0x8000 + 0x7D50` folds into the symbol, so use a separate base pointer
  inside a nested if; `float *rates = &g_...;` keeps struct offsets from folding into a global's address.
- **Mangled callee names** (`Name__F...`) are declared `extern "C"` with the exact mangled identifier; the parameter list follows the registers, not the mangled name. Many drafts' callee prototypes were wrong in argument
  count: grep `src/` for an existing matched declaration before guessing.
- **Not C:** `TickReadCount`, `ResetGs` and `Vif1InterruptHandler` need COP0 `mfc0`/`ei` and `sync`; `printf`/`sprintf` spill the variadic float registers and need a `stdarg.h`; `ExitThreadStub` is `addiu $v1,0x23; syscall`.
  `CMovieText_Cch` needed the `ps2eeas-loop5` assembler (two `nop`s before its loop), not a source change.

### Haiku round 4 (120 functions of 48 to 96 bytes, 61 matched)

The match rate fell to about 50% (rounds 2 and 3: about 60%) as the easy cases ran out. What fixed the misses:

- **A pointer to a stack object with stores at `sp+0`, `sp+4` before the call is a local struct passed by address**, not extra arguments (`EnsureOption*`, `AddJobAnim`, `FFindClosestPointInCg`). Frame size minus saved registers gives the object sizes.
- **Count every argument register read before a `jal`**, including ones the draft dropped (`arg0` passed through untouched) and stack arguments.
- **Virtual calls:** `char *child = *(char **)(self + 0xC); call(self + *(short *)(child + h), ...)`; vtable as a local, call through a `void **` read with the `s16` offset inline.
- **One shared epilogue:** retail jumps to a single exit; write one `return` at the end instead of early returns. `if (a || f(...)) result = 1;` gives a single fall-through block.
- **A global loaded before a branch** in retail: copy it into a local at the top. A repeated `&GLOBAL` stays in a local for the saved-register base.
- **A frame bigger than the locals** shows a dead local: `char sp[0x10] __attribute__((aligned(16)))` with a comment (a plain unused array is dropped).
- **Float compares:** `if (x == 0.0f) {store 0} else {store 1/x}` first; `fabs(d) > eps ? 1 : 0` instead of negating the `if` when `c.le`/`bc1f` comes out wrong.
- **64-bit flag tests use `long`** (`0x8000L << 19`); `long long` is 128-bit under SN.
- **Remaining near misses are register choice** (`$a1`/`$a2`/`$a3`, `$v0`/`$s0`) or sunk/hoisted stores. Once the same wording gives the same register map twice, stop.

### Permuted round on the nearest misses (distance 1 to 5, 2026-10-30)

`permute_stores.py --min 1 --max 5 --budget 200` searched 75 functions with straight-line store regions: 2 improved, 1 matched (`PackSTQ__4GIFSfff`). `neighborhood.py --batch --max-score 5 --budget 3000` covered 177: 14 improved (best 5 to 1), none reached 0; a deeper pass (`--depth 4 --beam 12 --budget 12000`, scores 1 to 3) improved 3 more. The nearest misses are now the walls the search cannot cross by statement order or one-line rewrites: register choice and instruction selection that need a different wording. Run `record_round.py` after a batch search, then `make progress` and `export_nonmatching.py`, or the improved sources do not reach `nonmatching/`.

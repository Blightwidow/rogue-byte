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
  `config/us/handwritten_asm.txt` lists the functions spimdisasm marks as hand-written (130, 121 of them in the SDK range); regenerate it
  with `python3 scripts/matching/handwritten.py`. Nothing counts from it and matching one is allowed, but a lead dealing out work leaves them out of the pool.
- **VU0 and MMI near misses: about ten compiles, then stop.** The walls are a VU instruction in a branch or `jal` delay slot, the `sq` order of
  a prologue, and which s-register holds which parameter around the `asm`. When the diff is one of these and ten compiles did not move it,
  write the best source to the function's note and add a `Behaviour:` line (what it computes, inputs, outputs, fields it touches) so the
  port can reimplement it as plain math. A match is still welcome, it just stops being the goal of the function.
- A chunk of the split that is a fragment of a larger function (`addiu $sp,$sp,N ; nop` remnants, a single instruction) is a splitting
  question, not a C question.
- A register-allocation difference that three different wordings leave unchanged.
- A delay slot that retail leaves unfilled where ours fills it, with no visible trigger.

## Teams of workers

Several workers (people or AI assistants) can match in parallel; AGENTS.md has the rules. The procedure:

1. The lead picks the functions (`python3 scripts/list_functions.py --status asm --sort size`) and splits them: no two workers
   share a function, contiguous functions go to one worker (they often belong to one class).
2. Each worker keeps its sources in its own scratch folder, runs `try.py` until `score 0` or about ten compiles without progress,
   and reports one line per function: `EXACT`, `NEAR` (what still differs) or `SKIP` (why). A worker that runs a make target passes
   `PROGRESS=0` (every worker brief says so).
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
- **Lane moves (allowed from 2026-11-01).** Retail holds a 128-bit vector in a general register and moves lane 0 to a float with `mtc1`
  (lanes 1 and 2 through `prot3w`/`pextuw`/`pextlw`/`pcpyld`), and a float into a vector register with `mfc1`. C has no form for that: reading the
  lane through memory gives `lwc1`, a union or a cast gives memory traffic or an internal compiler error. An `asm` that moves one lane of a
  `QW` value to or from an FP register (`asm("mtc1 %1, %0" : "=f"(f) : "r"(q))`, the MMI lane instructions in the same asm) is allowed,
  like the VU0 blocks; `scripts/matching/record.py`'s scan waives it. Still banned: an `mfc1`/`mtc1` that moves an ordinary int or float
  between registers only to steer the allocator. Put the lane in a one-line `static inline` helper and name the lane in a comment.
- **Provisionally allowed (2026-11-01, to be revisited):** an `asm volatile` on a lane-move asm to fix its order against another lane move
  (`22C8C0`, `11EE08`), and a dead store through an escaped address (a union member whose address escapes: `u.spill = w`) that gives retail's
  dead `sq` in a delay slot without `volatile` (`1F4A80`). Both only schedule; allow them where retail's code shows the instruction, mark each with
  a comment, and list the function in the commit body so the decision can be reversed in one pass. Not allowed: a dead local that retail's frame
  does not show.
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
- **Solved (2026-11-02):** those eleven constructors and `0x112100` match as a class with two bases (the primary base keeps its vptr at `+0xC`, the second sits at a later offset with its own vptr) built by an inline compiler-generated constructor: `struct CPrimary { int a, b, c; CPrimary() { a = 0; b = 0; } virtual void V0(); }; struct CObject : CPrimaryBody, CSecondary { virtual void V0(); }; return new CObject;` gives retail's copy of `$v0` into `$v1`. gcc names the vtables `_vt$<derived>` and `_vt$<derived>$<base>`; register each in `config/matching/symbol_addrs.txt` at retail's address (`python3 scripts/matching/name.py 0x2D2978 '_vt$13CObject110EC0'`, `$` is accepted now) so the link check passes. `make elf` needs no entry: it derives unknown names from retail's instructions (`derive_addresses` in `scripts/build/link_image.py`).
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

### Sonnet near-miss batch (96 functions at distance 2 to 4, 2026-10-30)

Eight Sonnet workers, 12 functions each, 37 reached 0 (36 landed; `func_0017B8B0` stayed out because its match needed a local that only moves a `lui`). What fixed them:

- **Virtual calls with a `$v0`/`$v1` swap:** declare real structs, `struct VT { char pad[N]; short delta; short unused; void (*fn)(void *, ...); }` and `obj->vt->fn((char *)obj + obj->vt->delta, ...)`, instead of `M2C_FIELD` chains (about eight functions).
- **Wrong prototype:** a `$t0`/`$t1` set before a `jal` means six arguments; an untouched `$a0` is a hidden first parameter; a callee drawn as returning a value that retail ignores is `void`.
- **Wrong element type:** an `s128*` step or an `M2C_UNK` base with byte offsets is scaled wrongly (`SLOT B[]` array type, `char` base, `RO_<addr>` for floats, not `D_FLT_`).
- **Signed against unsigned** decides `bltz`/`slti` against `sltiu`; `if (x > 0.0f) {...}` gives `c.lt`/`bc1f`, `if (x <= 0) return;` gives `c.le`/`bc1t`.
- **Switch with the allocation in each case** beat the m2c `goto` chain; `for (; i < 10U; i++)` beat a pointer do/while.
- **VU0 asm:** a `"=r"(fence)` chain moves `daddu`/`addiu $sp` to retail's slots; a commutative op (`vadda`) may need its operands the other way round.
- **A volatile flag** is allowed when another thread sets it and a wait loop polls it (`g_2deb20`, set by `FrameRenderLoop`); say who sets it in a comment.
- **Walls:** VU asm in a branch delay slot, the `sq` order of callee-saved registers in a prologue, `mult` against `mult`/`mflo` forms, and anything that matched only with a register pin, empty `asm` or a local that only moves a `lui`.

### Sonnet near-miss batch 2 (96 functions at distance 1 to 9, 2026-10-30)

Eight Sonnet workers, 46 of 96 matched, all landed (batches ranged from 4 to 10 of 12). More fixes:

- **A dropped leading argument is the commonest cause:** `$a0` untouched before a `jal` is `self` passed through (`PjsgeAllocJsg(self, type, flag)`); each float parameter goes in `$f12`/`$f13`, with a dummy int in the skipped integer slot.
- **A `por`/`daddu` with `sq` where retail has `sd`:** the parameter is `long`, not `long long` (128-bit under SN) or `s64`. A `por $a2,$zero,$a3` is a 128-bit argument or return: type it `QW`.
- **A callee's float parameter:** declare it `float` and pass `0.25f`; an `int 0x3E800000` makes the compiler convert it.
- **Nest a QW-returning callee in the next call** (`Construct(&tmp, Decompose(...))`) for `por $a1,$zero,$v0` in the `jal` delay slot; `++*p;` before the call (not after) puts the `sw` there.
- **A relocated `lui $x,0 / addiu $x,0xC0` is an extern symbol** (`VU1_ENTRY_C0[]`), not a literal; grep `src/` for `RO_`/`VU1_ENTRY_*` first.
- **A link mismatch can be a name collision** (a callee resolving to another address): grep the retail address in `config/recovered/sly2_combined_symbol_addrs.txt` before reshaping code.
- **Test-first loops:** `while (f()) { if (n == 0) break; n -= 1; }`; `do {} while (n-- != 0)` compiles to `!= -1`. A mask loaded as `lui/ori/dsll/ori` is `~(1L << 35)`.
- **Real typed structs for the object, its vtable and its entries** replace `M2C_FIELD` offsets and gotos (`entries[count++]`, `ptr[n-1]` not `(n*4)+ptr` on an `f32 *`); check the stride in retail's `addiu`.
- **Positive condition with an empty `if`** and the other path in the `else` gives `c.le`/`bc1f`; `if (cond) x = 1; else x = 0;` (true value first) gives `bnel`/`sw zero`.
- **Hill-climbing over adjacent store swaps** found a 7-store order that random shuffles did not (`InitTask`).

### Permuted round on distance 6 to 19 (2026-10-30)

`fix_stack.py` (151 of 173 sources improved, the rest of the placeholder buffers already right), `permute_stores.py --min 6 --max 19 --budget 200` (169 searched, 5 improved) and `neighborhood.py --batch --min-score 6 --max-score 19 --budget 2000` (526 functions, 55 improved, 7 reached 0: `RemoveAloFromRenderTree` and six SDK-tail node initialisers). The tail (0x2550A0 on) are slot-heap node constructors that the one-edit rewrites reach; the near misses of game code at 6 to 19 mostly need a different wording, not a rewrite.

### Sonnet batch on first m2c drafts (94 functions at distance 21 to 50, 2026-10-30)

The first draft of a function that has never had a source (`harvest.py --repair --shape --write --keep 400` saves the 352 that compile). Eight Sonnet workers matched 45 of 94 (46 scored 0; one needed a local that only hoists a constant and stayed out). Six matched only with `ps2eeas-loop5` (their addresses moved from `gnu_as.txt` to `ps2eeas_loop5.txt`): try it before rewording any small-loop miss of one or two words, because the workers did not know to.

- **The prototype is the first suspect.** A missing `this`, a float argument, a fifth argument of 0, a callee returning `void`: `DxDrawCh` went from 39 words to 0 on prototypes. Read the mangled name for parameter order (`FffffP4SMPAPf` is four floats then two pointers); an m2c callee name can be the wrong function, so grep the address in `config/matching/symbol_addrs.txt`.
- **m2c scales pointers wrongly.** `f32 *+= 4` is 4 bytes (`+= 1`); `+= 0x18` on an `s32 *` is a 0x18-byte struct stride; a `0xA0` multiply on `&D_xxx` is an array of 0x28-byte structs. Use typed element structs and `arr[index]`; `(ELEM *)(index * 0xB0 + (unsigned)base)` gives the `addu` operand order `&arr[index]` cannot.
- **Loop and branch shapes.** A hand-unrolled m2c search loop is a `for` over a typed struct array; a count retail reads each iteration needs a typed struct with `self->count`; a plain `switch` beats the branch chain; `if (c) return 0; switch (...)` against nested ifs decides where the return-0 block sits; the true arm first fixes `bnel` against `beqz`.
- **Virtual calls.** `fn((char *)obj + vt->delta)` with a one-argument `fn` puts the object in `$a1`; count how many argument registers retail sets. A scoped guard struct whose constructor and destructor call vtable slots reproduces a `sw $s0,0($sp)` and reload (46 to 14).
- **Larger-than-16-byte struct arguments** are a hidden pointer to a caller-side copy (`Rows3 copy; copy = mat; f(&copy);`); a dead frame area is `char frame[0x10] __attribute__((aligned(16)))` with a comment.
- **Float constants** are written as the exact value (`57.2957763671875f`); `qmfc2.ni` results are read as `*(float *)&bits`, not through an `mtc1` asm.
- **Link check:** `D_STR_<addr>` is unknown to it, `D_<addr>` links.

### Sonnet batch on drafts that did not compile (136 functions, 800 bytes on average, 2026-10-30)

Eight Sonnet workers, 17 functions each. 130 now compile (10 at score 0, the rest between 5 and 550 words); 5 do not score (see below) and `func_0022A220` was skipped (m2c lost VU instructions inside a comma expression). All 130 compiling sources are saved as sources, so the permuter and neighborhood passes can work on them.

Why a draft does not compile, and the fix:

- **An empty compile error message is cc1plus crashing on m2c output:** a `default:` or `case 0:` label left outside any `switch`, or lifted-expression comma garbage `(, , , , (x > 1.0f))`. Delete them (and add an empty `case 0: break;` when retail's jump table starts at index 0). 15 of the 136 had these; `harvest.py` could drop them automatically.
- **`s8 *` against `s8 **`, `invalid type argument of unary *`, assignment lacking a cast:** the field of a typed struct (`p->field`) replaces `M2C_FIELD(...)` casts; `PvAlloc*Impl__Fi` takes one `ALLOCREQ *`.
- **gcc 2.95 ICEs (expr.c:639)** on `*(float *)&qwLocal` and on `long` outputs of `pextuw`/`prot3w`: use a `"=r"(float)` asm as `src/suv-end/Vec4_GetZ.cpp` does.
- **`try.py` fails with "address 0x463a9700 not in a loadable segment"** (or `0x4b1c`): a float literal landed in the object's `.rodata` and the compare reads its bits as a retail address. Declare the constant `extern float RO_<addr>` at the address retail loads it from.

Frame and locals (the commonest cause of a score in the hundreds):

- **m2c's `sp[N]` is the whole frame, saved registers included.** Size one `char sp[N]` to retail's frame minus the saves (they start at the `sd $ra` offset) and alias m2c's `spXX` locals into it with `#define spXX (*(T *)(sp + 0xXX))`. Separate locals plus a buffer double-count.
- A struct local whose address is taken needs 16-byte alignment to reproduce retail's slot spacing; `{ptr; pad[3]}` gives the 0x20 to 0x30 spacing where an attribute on a pointer did nothing; slots 0x10 apart are 16-byte objects (CRef, find-result wrappers).
- An `sq` at `sp+0x10` before a call with no `$a2` set is a field of a local struct, not a stack argument; `$t0`/`$t1` set before a virtual call means six arguments with `&local` in `$t0`.
- A struct assignment hides behind a call (`scratch = inverse` before a `memset`); declare `memcpy` in C++ linkage or constant-size copies are inlined (181 to 30).

Switches and shapes:

- A switch with several `case` labels sharing a body compiles to a compare chain (gcc merges them into a range): retail's jump table appeared only when each case got its own duplicated body; declare the unlisted cases (`case 0:`, the high ones) so the full table of retail's range is emitted. Each jump table adds link points to the score that no source change removes.
- `if (cond) { early } else { normal }` when retail falls through into the early-out; a `while ((previous = x), f() == 0)` comma form reproduces an entry jump.

VU asm:

- `"m"(local.field)` operands print `0x10($sp)` directly and hold no extra base register (46 to 16); a `"memory"` clobber on the `lqc2` asm reproduces a reload after stores; a `qmfc2` result compared with a float constant is typed `s32` and read as `*(f32 *)&x`.

A virtual call `obj->vt->fn(obj + delta, ..., obj)` that also passes `obj` as a last argument leaves it in the first-argument register where retail keeps it in the last one (seven functions): the same family as the unmatched `new()` constructors, still open.

### The SDK range through the m2c pipeline (622 library functions, 2026-10-30)

`harvest.py`'s drafts, tried under both compilers (SN 2.95.3 and Sony's 2.9-ee-991111 with its own as.exe) and kept under the lower score, with no hand work: 50 of 622 library functions match, 135 are within 5 words, 239 within 20, 395 compile (the rest: 172 unsupported instructions, 55 do not compile). 142 prefer the Sony compiler, 253 SN's; the Sony addresses were added to `config/us/sony_gcc29.txt` (the compiler is chosen per address, not per library). The score cache does not know which compiler produced a score: judge each candidate under one compiler per process, or mark the source text.

`record_round.py` only reads sources of `todo` and `tried` functions: register a library function's source with `try.py --record` (it moves the function to `tried` or `matched`).

### One function per kind, then the rule (five Opus deep dives, 2026-10-30)

The 348 near misses (distance 1 to 9) were clustered by the kind of their diff (branch layout, order plus register, instruction selection, register only, order only, nop) and an Opus worker per kind solved one representative without a compile bound, found the cause, and applied the rule to the rest of its list: 64 more functions at 0 (the lists overlap). **No kind has a single cause**; each is a handful of recurring source shapes, and most are m2c's rendering of code that the original wrote differently. The shapes, with the mechanism where it was measured:

Loops and counters (nop, order, register kinds):
- **Indexed loop, not m2c's pointer walk.** `p = base; do { ...; i++; p += S; } while (i < n)` back to `for (i...) { p = base + i*S; ... }` or `&a[i]`: gcc's loop pass derives the pointer and emits its setup after the hoisted `lui`. `-fno-strength-reduce` on the indexed form loses retail's order, which shows the indexed form is the original. (153FF8, 1F6AC8, 1F6B48, 1F6BC8, 18A2E0.)
- **Index first in an address:** `(ELEM *)(index * sizeof(ELEM) + (unsigned)base)`: the `(unsigned)` cast is required; `&a[i]` and `(char *)` put the base first.
- **A loop-head `nop` is `.p2align 3` filled by ps2eeas:** an extra or missing nop there means one instruction before the loop (a register copy) is missing or extra. The copies come from reading the bound in the condition (`i < p->count`, not cached), a product held in LO through an inline helper's parameter (`mult $zero,a,b ; mflo`), or a `goto` loop where the original had a natural `for`/`while`.
- **A zero-initialised accumulator** (`float u = 0.0f; u += X; ... return u;`) keeps the result out of `$f0` (`add.s $f4,$f4,$f0 ; mov.s $f0,$f4`): cross-jumping merges the adds. An early `mtc1 $zero,$fN` and an epilogue `mov.s $f0,$fN` is the sign.
- **Post-increment index** `p = &a[c++]` moves the counter store; one struct copy (`struct V3 {f32 x,y,z;}`) issues all loads before the stores where m2c's `Bytes8` + `s32` did not.

Registers (register-only, selection kinds):
- **Return inside the `if` arm.** The arm's result is then a block-local temporary tied to `$v0`, which forces the other block-local values into `$a0`, `$a1` (local register allocation); a function-wide variable returned at the end is allocated later and gets another register.
- **`max.s` operand order:** call an inline `GMax(a, b)`; the helper's first parameter decides the register `max.s` writes (`1.0f >? x` written directly does not match).
- **A switch whose `case 0:` falls into `default:`** shares one store with two predecessors, so the compiler cannot turn it into `sw $zero` from the branch test.
- **`save->e = save->f = 0.0f;`** shares one SF pseudo: `mtc1 $zero,$f0` and two `swc1`, where two literals give two `sw $zero`.

Branches (branch kind):
- **The delay-slot filler (`reorg`) annuls (`bnel`/`beql`) when the function returns a scalar or pointer and uses a plain `bne`/`beq` for `void` or a class returned in memory.** Retail's RefOp functions return `CRef` by value (hidden result pointer in `$a0`, handed back in `$v0`): `return CRef(0x17, flag);` with a class that has a constructor and a declared `~CRef()` (an 8-byte POD is returned in registers and is far worse). A `bnel`/`bnez` flip whose slot writes `$v0` is the sign. (`work/matching/kinds/scratch-branch/byvalue.py` automates it, but as a blanket transform it matched 2 of 60, improved 2 and worsened 31: use it only when the diff is that flip.)
- **A `bc1fl`/`bc1f` flip on a slot copied from a join's store** means the join's store order is wrong: the compiler emits the last-written store first.

Prototypes (selection kind): float arguments go in `$f12`... independently of `$a0`..., so a float parameter's position in a callee's prototype does not show in the registers, but it decides the order the argument instructions are emitted in (MIPS evaluates the last parameter first) and so the schedule. Try every interleaving of the float parameters (`float_position.py`: 5 of 41 sources reached 0, one parameter order disagrees with Sly 1's). Demangle the callee's name for parameter counts (`mangled_order.py`). A parameter typed `long long`/`s64` is 128-bit under SN: use `long`.

The object-passed-as-last-argument virtual call (`obj->vt->fn(obj + delta, ..., obj)`, the `new()` constructors) is **often not real**: in Sonnet round 7 four functions (`GetJtHangHeading`, `func_00179820`, `ShowCountdownBlot`, `func_001E5370`) matched by dropping the trailing `obj` argument (the register that holds `obj` is just the object's own: `fn((char *)obj + obj->vt->delta, ...)`); try that first (`rules.py` does it for typed vtables). A genuine case remains: `151698` once matched only with `-fno-schedule-insns` (the first scheduling pass moves the `a1 = obj` copy above `a0 = obj + delta`), and `151648`, `1A3078`, `1371C8` still miss on it.

The sixth deep dive (order plus register, 83 sources; 20 of them are fragments of 32 bytes or less, not C) found no single cause either. 15 more functions reach 0. The cause is mostly a wrong argument list, width or return value in the m2c draft: it changes which registers are live around a call, so sched2 (calls do not end a scheduling block after reload, and the EE issues two instructions per cycle) and local allocation give other priorities: "same instructions, other order, other registers" with no extra instruction to point at. Check in this order:

1. **Count the arguments each callee really receives, both ways.** An extra argument (a register set before the `jal` that the callee never reads: `PvAllocSwClearImpl__Fi` takes one `ALLOCREQ *`), a missing pass-through argument (trailing: `ActivateCplcy(close, focus, xf)`; leading: m2c named the parameters `arg1..`), or a wrong one (`StartSpooling(this)`, not the loaded field).
2. **Widths:** `long`, not `long long`; 64-bit flag words are `long`.
3. **Declare `RO_` externs `const`:** a non-const load may alias the stores and is pinned in place. (`constify.py`: 1 of 99 sources matched, 55 stopped compiling at `&RO_` uses, none of 41 matched controls got worse.)
4. **A `void` function whose retail keeps the callee's result in `$v0` to the `jr`, working on a copy in `$v1`, returns that pointer.**
5. **Typed structs, not `M2C_FIELD` chains; an indexed `for`, not the pointer walk.**
6. **Then rerun the store-order search:** a correct type fix often leaves the order wrong. **A wrong argument can be a local minimum that looks one word away:** fixing it first scores worse (1 to 2 to 8), so a search that accepts only improvements never leaves it. Some fixes need two edits together (a pass-through argument alone scores 7, the member re-read alone 2, both 0): `trailing_args.py --pairs` tries pairs.

Unexplained: a 68-byte `new()` constructor copies the allocated object `$v0` to `$v1` and neither returning it, an inline wrapper nor store order reproduces it (0x110CD0 and ten more).

### The SDK range by hand, and what the pipeline learned (2026-10-30)

Eight Sonnet workers took the 186 library near misses (10 to 120 words): 80 more SDK functions match (72 as C++, 11 as C, some counted in both), and the lessons below also fixed 25 other functions.

- **The SDK sources are C.** `try.py` now judges a `.c` file as C (the default follows the suffix; `--lang` overrides); `record_round.py` and `neighborhood.py` read `.c` sources in `data/matching/src/fn/`, and `export_src.py` publishes them as `src/<module>/<name>.c`. Sony's gcc emits a sibling call (`j callee`, no frame) only from C, and only when the final call's result is unused (`void` callee, no `return g(x)`).
- **The compiler is per address:** the 150 addresses that match only under Sony's gcc 2.9 (retail saves with `sd`/`ld`, not `sq`/`lq`) are in `config/us/sony_gcc29.txt`; one that needs the loop-padding assembler is in `ps2eeas_loop5.txt`. Try `TRY_ASSEMBLER=sony29` first when a library function's prologue saves with the wrong instruction.
- **Soft-float libcalls:** Sony's gcc emits `dpadd`, `dpsub`, `dpmul`, `dpdiv`, `dptofp` (and `copysign`) for the double operations; `config/matching/symbol_addrs.txt` has these as aliases of `__adddf3` and the rest, or the link check counts a word per call (five libm functions were identical to retail otherwise).
- **Hardware registers** (`0x1000xxxx` DMA, IPU, timer) are `*(volatile unsigned *)ADDR` at the use site: pointer locals fold into `lui` + offset. Volatile on ordinary data is still banned (two functions stay at 9).
- **fdlibm code matches only in the fdlibm shape:** `ieee_*_shape_type` unions and the `GET_FLOAT_WORD`/`SET_FLOAT_WORD`/`GET_HIGH_WORD`/`EXTRACT_WORDS` macros, modifying the argument in place.
- **A `func(arg)` stub with an `sp[0x20]` buffer is a small IOP command packet:** `int buf[4]` filled with the arguments and passed as `(char *)buf`; `sceSifCallRpc` takes nine arguments; typed global tables (`Port{Slot slot[4]}`, strides 0x70 and 0x1C) reproduce `mult`/`mult1`.
- **Fragments are not functions.** The `addiu $sp ; nop` chunks of the SDK range are the `jr` delay slots of the preceding function (a 100-word function scoring 1 may just be missing its last word to the split: only seven functions end exactly at their `jr`).

m2c and the harvest: the split assembly names registers 8 to 15 as o32 does (`$t0`-`$t7`), m2c's `mipsee` target as n32/eabi64 does (`$a4`-`$a7`, `$t0`-`$t3`), so a function's fifth to eighth argument looked like a read of an unset temporary: 88 functions had no draft for that alone. `harvest.py` renames the registers before m2c reads them; the unsupported count fell from 132 to 46, 61 more drafts compile, 13 more functions match, and `harvest.py --tried --refresh --write` redrafts the functions that already have a source (a saved source is replaced only by a strictly lower score; 257 improved). m2c also needed `max.s` and `min.s` (R5900 float min and max, `fmaxf`/`fminf`), in `scripts/matching/m2c_vu.patch`.

The rule-based passes of `scripts/matching/rules.py` (the deep-dive shapes as rewrites, run through `neighborhood.py`) found their first matches on the nearest misses (distance 1 to 20).

### Sonnet round 6: near misses at 5 to 20 words, with the deep-dive rules in the brief (48 functions, 2026-10-30)

Four workers, 25 matches (52%), the best rate of any Sonnet round: the brief now carried the rules of the deep dives, and the misses that remain are the known walls. Lessons added:

- **A dropped unused leading parameter:** a draft with `arg0, arg1, arg3` has a real `arg2`; adding it (or a dummy first parameter when the real argument is in `$a1`) fixes the argument shift. `PjsgeAllocJsg(self, ...)`: retail's `$a0` untouched, arguments in `$a1..$a3,$t0,$t1`.
- **A virtual call with only `obj + delta` and no second `obj` argument** matched (`node->vt->fn((char *)node + node->vt->delta)`): not the `-fno-schedule-insns` wall.
- **An inline `Clamp(v, lo, hi)`** called as `Clamp(raw, 1, 99)` keeps the constant in its own register where a literal ternary does not; `switch (s) { case 0: case 1: case 9: case 10: return 1; } return 0;` gives the un-merged `slti` ladder.
- **A byte `delta` is `(char *)p + delta`,** not `(unsigned int *)p + delta` (a spurious `sll 2`); a struct with the array member (`B.slot[idx].kind`) keeps `&B` unfolded.
- **A callee that takes `ALLOCREQ *` is a local struct** (`req.size`, `req.align`), not two integers.
- **A banned `asm("" : "+r")` in a draft may hide a better score:** dropping it moved one function from 6 to 3, and two from 6 to 18 and 30: the honest score is what is published.


### Sonnet round 7: near misses at 4 to 25 words (72 functions, 2026-10-30)

Six workers, 44 matches (61%), the best rate yet; the pool was the largest untouched set of 4 to 25 word misses, and the brief carried every earlier lesson. New:

- **Declare a global as an array** (`extern float g_2dded0[];`, read `g[0]`; `extern int B_003E12EC[];`): the load is scheduled and aliased differently (fixed `1F58F0` and `1F8668`; it does nothing on others). A plain non-const `extern float` also fixed one function.
- **Stores before a call that look like stack arguments** (`sw` at 0/8/0xC/0x10 of `$sp` with only `$a0 = sp`) are the fields of a local struct passed by pointer; retail's store order is the reverse of the m2c field order. A `sp[0x10]` buffer plus a 4-argument call is an `ALLOCREQ { cb; cbAlign }`.
- **A 64-bit header built in two statements** (`header = prim << 47 | CONST; header = cloop | header; pdw[0] = header | creg << 60`) fixes the expression association; separate `if (s == 2) return 0; if (s == 3) return 0;` gives two `beq` where `||` merges into a range test; a two-case `if`/`else if` chain that compiles to `bne`/`bne` matched as a `switch`.
- **A structure wrong in m2c's draft** (not a register problem) is fixed by rewriting it: `switch (mode) { case 0: case 3: ... case 1: case 2: ... }` for a `goto` chain; an element size read from a constant (`0x38E38E39`: 0x120 bytes, pad the struct).
- **A type suffix on `CRef` changes the mangled name** and adds link mismatches: keep plain `CRef` where the callee symbol is mangled with it.
- **An exhaustive search of the store orders** (24 orders of four stores) found two matches that guessing missed: retail's visible order is not the source order.

### Sonnet round 8: near misses at 1 to 10 words (183 functions, 2026-10-31)

Six workers, 50 matches landed (8 of 31 in the best batch, 0 of 31 in the worst) and 19 more functions improved. The pool was every untried near miss at 1 to 10 words outside the SDK range; about a third of it was not code. New:

- **Fragments are in the pool.** A 8 to 32 byte "function" that holds a `jr` delay slot, a lone `addiu $sp` or a `sw`/`swc1` belongs to the function before it (worker 1: 18 of 31, worker 6: 7 of 28). Drop them from a pool before dealing it.
- **A banned `asm("")`, `volatile` or register pin props up a score.** Removing it moved `1EE988` from 7 to 26, `204108` from 6 to 18, `135940` from 7 to 26, `150F58` from 8 to 39: the manifest overstates those functions. Some went the other way (`19FD30` from 4 to 0 without the empty `asm`). Judge a draft without the trick first.
- **A wrong callee prototype caused most of the matches.** An `a1` set before a call means a second argument; a `jal` with no `a0` setup means the first argument is untouched (a real unused `arg0`: the `PjsgeAllocJsg` family); `por $a1,$zero,$a2` means a 128-bit argument; a fifth argument equal to the third (`daddu t0,a2`) is `fn(this+delta, 4, x, 4, x)`.
- **Stack stores before a call are a local struct** (`{size, align}`, a 0x70-byte command struct): give each local its real size and alignment, then declaration order stops mattering.
- **Pointer scaling:** `(char *)&sym + N` where m2c wrote `&sym + N` (it scales by the type); a typed element struct (`B + var_s0` on an `s32 *`) gives retail's strides where `var += 0x18` does not.
- **Nest a call in the argument list** (`f(&B, 1, g(x), ...)`) when retail keeps an address in a callee-saved register across the inner call.
- **A duplicated switch arm** (`SetButtonButtons(p, 1)` in both cases, no `goto`) gives gcc's shared-block layout; a float compare against a re-read field gives the loop's extra register copy.
- **Walls again:** a VU instruction (`qmfc2`, `lqc2`, `sqc2`, `qmtc2`) in a branch or `jal` delay slot, the `sq` order of a prologue, and `sqrt.s $f1,$f0; mov.s $f0,$f1` (`__builtin_sqrtf` and helpers all give `sqrt.s $f0,$f0`).
- `16E1A8` is instruction-exact at score 1: its last call links an address-0 `%hi/%lo` pair no symbol covers.

### Sonnet round 9: near misses at 7 to 14 words, a filtered pool (60 functions, 2026-10-31)

Three workers, 20 matches (33%; all 20 held in the full build). The pool had no fragments (under 48 bytes dropped) and no drafts with a banned construct, so the scores were honest; the brief carried the round 8 lessons. New:

- **A compare chain that mixes `==` and `<`** is a `switch` without a jump table (fewer than five cases); a three-case `switch` (-1, 0, 1) gives retail's compare-and-branch layout with the constant in the delay slot where nested `if`/`goto` does not. For four cases, `permute.py` over the case order found the match in 24 compiles.
- **Virtual call:** drop a trailing `obj` argument when retail has no separate copy of it (three functions); stack stores before a call plus `t0 = sp` are a local struct or an array of pointers passed by address.
- **Expression shape:** `s32 top = g - 1; (top + align) & -align` fixes an add order that both other groupings reassociate; one counter shared by two loops gives both the same register; a local `unsigned last = width - 1` pins a subtract before a `movz`.
- **Pointer arithmetic:** `+= 0x10` on an `s32 *` is scaled: index a 16-byte element in a counted `for` loop. `(s64)0x8000 << 19` gives retail's `ori`/`dsll` where a plain constant gives `lui`.
- **A frame with no stores is a dead local** (`s32 dead[2]; (void)dead;`), the case AGENTS.md allows.
- **Return type:** a callee returning `s64` (`ld`/`nor`/`and`) fixed `RemoveGuardSgs`. Branch arm order picks the delay-slot form (`if (diff > 0) lo = ...; else hi = ...` gives `blezl`; an empty `if (bit) {} else return` drops an `xori`).
- **Nested ifs:** `if (x < 5) { if (x >= 2) ... }` gives retail's `slti`/`bnel` where `&&` gives `sltiu`.
- **Walls seen more than once:** the child virtual call `$a2` copy (four functions at 8), the inlined list-iterator init order (load/store), the prologue `sq` order, and a VU instruction in a `jal` delay slot.

### Sonnet round 10: near misses at 6 to 20 words (241 functions, 2026-11-01)

Ten workers, 79 matches (33%, the same rate as round 9; all 79 held in the full build, PAL reproduces 4,922 of the 4,973 matched functions). The pool was every near miss at 6 to 20 words outside the SDK range, over 48 bytes, without a banned construct, and without a note newer than five days. 2.66M subagent tokens, about 34k per match. New:

- **A virtual call with a wrong argument count was the biggest single cause** (about a dozen matches: `1DD6C8`, `1DD728`, `1DD820`, `1BEAD0`, `1C5DF0`, `20FA50`, `224190`, `1ACB58`, `1ACBB8`, `1A3078`). Retail passes only `obj + delta` (plus the real arguments): drop the trailing `obj` that m2c adds. The `$a2` that looks like a third argument is register allocation.
- **Loop shape:** `while ((p = *pp))` with `break`, not `return` (`133448`); a `goto` search loop where `while` or a ternary gets rotated (`1F90D0`, `1F4DA8`); a loop bound re-read from the struct instead of a count local (`217BA0`, `217CA8`); `igoal = cgoal; igoal--; for (; igoal >= 0; igoal--)` for a backward loop (`1EED10`); a `do`/`while` that reloads the state (`174B68`, `1A12F0`).
- **Condition shape:** `result = 0; if (a || b) result = 1;` where a plain `if`/`else` folds to `xor`/`sltiu` (`1EE420`, `1FE888`); `(a == 11) & (b == id)` gives `xor`/`sltiu`/`movn` (`12F938`); an early return first, then nested `if`s, for range checks (`15A170`, `1E66C8`, `224190`); a switch of three cases for a compare chain again (`1AAB68`, `135FF0`).
- **Types:** a struct returned by value to get the callee's temp-slot order (`1A71B0` `M4`, `1F8AD8` `Rows3`); a 64-bit flag word as a bitfield struct (`1A6CA8`); a pointer field typed as `int` address when the code does arithmetic on it (`226C58`); a struct must not be named `CRef` when it defines `operator=` (`124F00`).
- **Hidden parameters:** an `a1` loaded before a call is a hidden second argument (`231598`: `matLocal = *pmat * matLocal`); a stray constant argument is not one (`1635F8`: remove the `0x18`).
- **Search:** `permute.py` on the first seven stores found an order guessing missed (`134648`); `1C42E8` the same.
- **Variadics:** `char *va_list = __builtin_next_arg(format) - 56` passed to `vprintf` (`21EC18`, `21ECD8`).
- **Judge:** `2565E0` (`Vector_Add`) matches only with a local `CARY *pary = &pvec->ary` used for the call and the count reads; without it the score is 10. Landed, but it is the one match here a reviewer should look at against the "variable that only moves a register" rule.
- **Walls seen again:** the 11 `new()` plus two-vtable factories at `110CD0` (retail keeps the new object in `$v1` and copies it to `$v0`) all stay at 10; the child virtual call `$a2` copy; `sqrt.s $f1,$f0; mov.s $f0,$f1`; a VU instruction in a delay slot. Drafts that carried a banned construct got it removed first, as the brief says, and their scores rose (`11BCF8` went from 18 to an honest 37; `12C570` from a pin to 7).

### Sonnet round 11: small functions at 21 to 100 words (155 functions, 2026-11-01)

Eight workers, 31 matches (20%; all held in the full build). The pool was functions of 48 to 400 bytes at 21 to 100 words or never tried, with 54 drafts that carried a banned construct (stripped first, scores rose to the honest value). 2.42M subagent tokens, about 78k per match. New:

- **The same inline reads template matches a family:** `LocateGcNode` reads the count and pool globals directly instead of as arguments and re-reads `*ppnodeHead` (`255588`, `255C00`, `255F38`); `ShopMenu_SetDirection` and `JobMenu_SetDirection` share one shape (`1DC4B0`, `1DD558`). Match one, then try the siblings.
- **A symbol size from the split can be wrong:** `1DC4B0` is 228 bytes (a jump-table tail sits in the next label) and `1B7E40` is 84 instructions where the packet showed 0x44 bytes. A packet whose asm ends early is a boundary question, not a C one.
- **Re-read instead of caching:** the loop bound or found-test re-read from the struct (`156EB8`, `1F81E0`, `1F1F38` with no local for `owner->part`).
- **Shared tails:** a result variable returned through one `done` label, with the tail duplicated in one case so cross-jumping matches (`206EB0`); a switch whose every arm has the same call gives the shared tail by cross-jumping (`18D568`).
- **Types:** by-value `RGBA4` copies passed by pointer (`215850`, `1C8CC0`); a callee returning `int` with a `QW` second argument (`156C80`); a clamp helper with native ternaries for `min.s`/`max.s` operand order (`217FE0`, `210F80`).
- **Banned asm removed:** the plain 64-bit mask, `(unsigned)(grf >> 60) & 1` then `(unsigned long)bit << 60` (`1A5270`). `1B17B8` matches with an `asm volatile sqrt.s` that the record scan accepts (a real instruction, precedent `220D40`); fast-math fuses `1/sqrtf` into `rsqrt.s` otherwise.
- **Walls:** retail keeps `CRef` addresses and constants in saved registers where ours re-derives them (`13D328`, `143AF0`, `136118`, `12D108`); the VU lane and prologue walls of the earlier rounds.

### Opus round 12: a sample of large functions (12 functions, 2026-11-01)

A stratified sample of the 158 functions over 1,000 bytes (outside the SDK range and `config/us/handwritten_asm.txt`), four Opus workers with about 30 compiles per function: 2 matches (`1281B0`, `1B4AA0`), 4 of 12 at 20 or below, and large drops where nothing matched (361 to 19, 232 to 3, 1124 to 128, 412 to 335). 1.42M subagent tokens for the 12, about 118k per function. The strata and results are in `work/matching/r12_sample.json` and `r12_results.json` (local), so the outcomes can be weighted to the pool without more compiles. New:

- **Honest starts matter:** four of the twelve registry scores rested on banned constructs and went up when stripped (`11FEC8` 55 to 60, `173F18` 225 to 228, `1F9410` 245 to 281, `2206C8` 66 to 76).
- **What moved large functions:** a locals struct at retail's stack offsets; real callee prototypes and parameter order (the Sly 1 order for `12F9B8`); a global that is really a member of a global struct (`1281B0`, 260 to 0); inline helpers whose locals share one stack slot (`1C9B08`); the `DLI` iterator helpers of `139250` (`140F90`; none of the other ~20 DLI functions is matched yet).
- **Work front to back:** the first-mismatch offset of `try.py` orders the blocks; every block outside one loop matched in `12F9B8` and 39 of 40 in `140F90`.
- **Walls:** loop-invariant hoisting and strength reduction that retail does and ours does not (`12F9B8`, `1C9B08`, `1F9410`, `173F18`); MMI lane access and the float-to-vector register pun (`197F98`, `11FEC8`).
- **Tools:** `compare.py` shadowed the function start in its link checks (near misses with a `switch` scored 1 to 2 words too high) and crashed on a mispaired `%hi/%lo`; both fixed.

### What `make rules` can reach (control, 2026-11-01)

The control is the 97 sources of the r9 and r10 matches as they stood before the workers (clean, score 6 to 20), searched at depth 3 with 400 compiles each. Of the 97 the search alone solved 2 (`1ACB58`, `1ACBB8`, both virtual-call fixes) and improved 1. `vcall_object` did not fire on the others: in `1DD6C8` the matching edit also inlined the temporary locals, and in `1A3078` the draft keeps m2c's raw `M2C_FIELD(...)(args)` call that the pattern does not see. Six rules were added (`inline_local`, `vcall_raw`, `hoist_field`, `result_local`, `condition_split`, `for_to_while`): the control then solved 3 and improved 13, none lost; a search to depth 5 with 1,500 compiles found nothing more (the neighbourhood is exhausted). The labels of the improving runs: `vcall_raw` 8, `swap_adjacent` 4, `condition_split` 3, `inline_local` 3, `vcall_object` 2, `hoist_field` 1.

The honest reading: single rewrites seldom finish a function; the worker matches combined several changes (typed structs, callee prototypes, a local named or inlined, a loop re-read) that no rule expresses alone. Rules move scores, models finish them. Keep the control as the regression test (a new rule must solve at least what these do and lose none); `hoist_field`, `result_local` and `for_to_while` have not yet contributed to a solve.

### What `make search` reaches after rounds 15 to 18 (control 2, 2026-11-02)

The control is the pre-match sources of the 76 functions that rounds 15 to 18 matched and that `nonmatching/` published before (read from git history at the commit before each landing; start scores 1 to 40, some resting on a construct the workers then removed), each searched at depth 3 with 400 compiles. The old rules solved 2 (`16E1A8`, `201360`, both of which only needed a symbol or an assembler entry) and improved 2. Three rules were added: `early_return_split` (an if/else that assigns one result local in both arms, then `return`: each arm returns its own value; either arm first), `scalar_buffer` (a one-element aligned array as a plain scalar and its address) and `chained_store` (two stores of one constant as `a = b = k`). The control then solved 5 (`117C20`, `117C80`, `117D50` through `early_return_split`, in 1 step each) and improved 3 more (`117DB8` 11 to 1), none lost. `scalar_buffer` and `chained_store` solved nothing alone here: `177E80` needs the chain and a store order together, and the search runs the store order before the rules, so the chain is judged without it.

Three more rules from the queue waves (`global_struct`, `callee_return`, `own_float_position`, 2026-11-02), each the fix of several worker matches: a scalar `extern float g;` as a one-member struct read as `g.v` (the clock `g_2dded0`: `17A8C8`, `1F17F8`, `141C08`), a callee prototype's return type as `int`, `void *` or `void` (`1AC468`, `1C7EE8`), and a float parameter of the function itself moved to another position (`1E0D38`). Control: the pre-match drafts of those six (from `26de80f`), depth 2, 250 compiles each. The old rules solved none of them; with the new ones `1C7EE8` (`callee_return`, depth 1), `1F17F8` (`global_struct`, depth 1) and `141C08` (`global_struct` then a store swap, depth 2) solve. `17A8C8`, `1AC468` and `1E0D38` do not: they need several changes together (the worker's `1E0D38` fix was a whole parameter order, not one move; `17A8C8` also stores `g_2dded0.t` straight into the state). The first version of `global_struct` missed `extern "C" float g;` and solved only `1C7EE8`; the control caught it.

Store order: `permute_stores.py` now climbs (each move of one store to another place of its region, first improvement kept, up to 30 equal moves) after the random sample when a region has more than five stores. On the pre-match sources of the five store-order matches the random search at 800 compiles solved none (`177E80` at 3,000); with the climb at 800 compiles it solved `194118` (2 to 0) and `195950` (5 to 0). `156548` and `218660` need a type change first. The honest reading is the one of control 1: rules and searches move the single-edit and ordering walls; the others still need a model.

### Sonnet round 13: a sample of 401 to 1,000 byte functions (20 functions, 2026-11-01)

A stratified sample of the 490 open functions of the tier (outside the SDK range and `config/us/handwritten_asm.txt`), four Sonnet workers with about 20 compiles per function: 2 matches (`141A50`, `164640`), 17 of 20 improved. 752K subagent tokens in 10 minutes, about 38K per function and 376K per match (r11, smaller functions: 78K; r12, Opus on large ones: 710K). With 2 matches in 20 the 95% interval on the rate is roughly 1 to 32%: read 10% of 490 (about 49 matches for 18M tokens) as an order of magnitude. Strata and results are in `work/matching/r13_sample.json` and `r13_results.json` (local). Score drops by stratum: 7 at 20 or below, 15.5 at 21 to 50, 22 at 51 to 100, 49 above 100, 70 for the untried. New:

- **A `switch` on the secondary state** fixed `164640` after 13 tries at 14 with if-chains (the round 9 lesson once more).
- **An inverted condition puts the second vtable call last** (`141A50`: `if (!((mask & button) && fn318(...))) SetState(..., 0); else fn328(...)`, 102 to 0 in seven compiles).
- **A `const` global hoists a load into a float register:** a non-const `D_002BDDE8` took `158B20` from 120 to 89.
- **A memory clobber on the real `sqc2` asm** stops the `group->list` hoist (`158E20`, 60 to 9); a non-volatile last `qmfc2` sinks into the delay slot (`179328`).
- **Walls:** the `PvAllocStackImpl` request block, where retail stores `align` in the `jal` delay slot through `v0` (`158E20`, 9); the hazard `nop` after `mtc1` that retail has and ours lacks (`179328`, `18B460`); retail hoisting `%hi(global)` into a saved register before the first call (`14FF38`); and the lane-move family (`12B738`, `12BBD0`, `12C140`, `12C768`, `18B460`), which the 2026-11-01 lane-move rule now allows.

### Sonnet round 14: the lane-move functions (79 functions, 2026-11-01)

Six workers on the 79 functions (up to 1,500 bytes) whose drafts used `mtc1`/`mfc1` lane moves or whose notes named that wall, after the lane-move rule: 3 matches (`11F198`, `1A3260`, `1EF8C8`), 39 improved, 31 of 79 now at 20 or below (7 at 5 or below); 17 honest scores rose above the registry value once banned constructs were stripped. 1.65M subagent tokens, about 21K per function and 550K per match. Largest drops: `1FA528` 131 to 25, `12B738`/`12BBD0` 121 to 50, `11FEC8` 60 to 14, `12E858` 68 to 44. New:

- **One asm builds a vector from floats:** `Vec3(x, y, z)` as a single asm with two early-clobber temps (`mfc1 %0,%2; mfc1 %1,%3; pextlw %0,%1,%0; mfc1 %1,%4; pcpyld %0,%1,%0`, floats as `f` inputs) loads all constants first (`1A3260`: 17 to 0; separate `Word()` helpers gave 17, one temp gave 4). A fused lane helper with `$0` as the source (`asm("pextuw %1, $0, %2\n\tmtc1 %1, %0" : "=f"(f), "=&r"(t) : "r"(q))`) removed a materialised zero vector (`1EF8C8`, 3 to 0). `PairLow` (two `mfc1` and `pextlw`) and `WithLane2` (`mfc1` and `pcpyld`, `+r` on the low `QW`) fit any three-float vector build.
- **Fused against separate:** for lane reads that interleave with branches, separate `prot3w`/`pextuw` asms followed by a `Lane0` `mtc1` gave retail's order best (`1FA528`: fused 45, volatile 65, separate 25).
- **The VU_FLOAT pun:** `WordOf` (`mfc1` into a `QW`) and `LaneOf` (`mtc1` out of it) helpers, with a block-scoped `QW vufSlot[1]` for the dead `sq`, took `11FEC8` from 60 to 14. Any retail `mfc1 v0,f0; sq v0,N(sp); mtc1 v0,f1` temp is this pattern.
- **An asm output must cover what the asm writes:** `"=m"(*(QW *)&l.ex)` for an `sqc2`, not a narrower lvalue, or gcc reads the neighbouring field before the store (`199408`).
- **A plain `sw` of lane 0:** `asm("sw %1, %0" : "=m"(*(int *)p) : "r"(q))` where a cast gives `dsll32`/`dsra32` (`22C8C0`).
- **Prototypes:** when retail passes a stack buffer in `a0`, declare the out pointer explicitly instead of a struct return, which makes gcc build a hidden temporary and a bigger frame (`1B2468`, 82 to 60); a by-value struct argument over 16 bytes is a hidden reference, so declare the callee with a pointer and copy into a member of the locals struct (`1CF338`, 32 to 16).
- **Inline wrappers re-materialise constants:** a constant passed through a `static inline` wrapper (`Near(a, b, 0.0001f)`) is built per call like retail's, where a direct call hoists it into a saved float register (`12D108`). gcc 2.95 stops inlining `static inline` helpers in a big function after many calls: use a macro or check for a stray `jal` (`117308`).
- **Frame:** one locals struct fixes retail's slots (`12E858`, `225BA0`); a `QW dead[1]` frame member gives the dead `sq`; writing the global directly (no pointer local) lets the `lui` hoist into the `PosLoWorld` delay slot.
- **Walls:** a VU instruction in a branch or `jal` delay slot (`118FB0`, `11ED40`, `11EE08`); two hazard `nop`s after `mtc1`/`lwc1` (`11FEC8`); prologue and saved-register order (`11F960`, `12C140`).

### Opus round 15: a sample of near misses (16 functions, 2026-11-01)

A stratified sample (size band by distance band, seed 20261101) of the 440 near misses at score 1 to 20 with at least two earlier tries, outside the SDK range and `config/us/handwritten_asm.txt`. Four Opus workers, about 30 compiles per function: 8 matches (`117C80`, `11E1A0`, `122BE0`, `160B70`, `18F560`, `1B5820`, `1CB658`, `1D7DA0`), 7 near, 1 skip (`259BF8`, a 3-word fragment after another function's `jr ra`). 698K subagent tokens, about 87K per match, against 376K to 550K for Sonnet on the same kind of wall. Strata and results are in `work/matching/r15_sample.json` and `r15_results.json` (local). New:

- **Fast path as its own block:** an if/else with one result local shared by both arms stayed at 11 however the sum was written; the fast path first, returning its own block-local value, matched (`117C80`). The same shape probably fits the rest of the `U8`/`U16`/`S8`/`S16Read` family (`S32Read` scored 1 in a scratch test).
- **A small inline helper gives a use its own pseudo:** `GClamp(g, lo, hi)` for a clamp (`18F560`, 8 to 0); `PvSetTag` (tag, then read the member) when retail rebuilds a stack address that ours keeps in an extra saved register (`122BE0`); a `SendDmaSync` wrapper (`160B70`). An open-coded form of the same text scored higher each time.
- **Prototypes first, again:** `WaitSema` takes the semaphore id (`160B70`); the honest three-argument call matched `117C80` without the four-argument thunk an earlier note had assumed.
- **Drop a shared local:** each branch tests its own field and advances itself, so gcc keeps the two return-0 blocks apart (`1D7DA0`, 2 compiles). Real 2-D tables (`int T[][5]`) instead of byte-offset arithmetic (`1B5820`); an item pointer plus one early return turns `beql` into retail's `beqz` (`1CB658`).
- **The Vec3 lane helper plus a locals struct at retail's slots** matched `11E1A0` on the first compile. Any retail `mfc1`/`mfc1`/`pextlw`/`mfc1`/`pcpyld` run is that helper.
- **Chained stores:** `a = b = k` fixed the register numbering and one store of several that share a constant (`13FF70`, 7 to 2); the scheduler emits the outer store early and the inner late.
- **Honest starts:** `122BE0` was registry 3 on a banned `asm("" : "+r")` and a wrong `SetTag` target (honest 34); `170548` was registry 20 with the wrong `ICeilLog2` argument (honest 28, now 21 and correct); `11F288` was 2 on a register pin (honest 5, then 2 with `asm volatile` on the real `qmfc2`).
- **Walls:** the assembler, not the C: retail has a `qmfc2` or `sqc2` in a `jr` or `jal` delay slot, and either only GNU as fills it or neither assembler does (`11F288`, `1D41F8`, and a hazard `nop` plus delay-slot fill together). No-output VU asms are volatile and act as scheduling barriers (`20F1C8`, `225BA0`, `119308`). `170548` is a goto loop with `zpr` and `head` in swapped saved registers.
- **Fence outputs:** chaining VU asms with a `"=r"` output fed to the next asm let the first `qmtc2` move above the prologue `addiu` as in retail (`119308`, 4 to 2, same pattern as matched `11B340`). Not used in any landed source, and not yet ruled on.

### Opus round 16: a second near-miss sample (24 functions, 2026-11-01)

A new draw (seed 20261102) from the same pool as round 15, with the round 15 lessons in the brief: six Opus workers, about 30 compiles per function: 10 matches (`117D50`, `11D740`, `156548`, `1ACA98`, `17B8B0`, `1F40A0`, `1FAC30`, `1FE5F0`, `212880`, `255438`), 12 near, 2 fragments skipped (`118218`, `11E020`, both stray epilogues with no `jr`). 996K subagent tokens, about 100K per match. Pooled with round 15: 18 matches in 40 functions (45%, 95% interval roughly 30 to 61%) at about 94K tokens per match. Results in `work/matching/r16_sample.json` and `r16_results.json` (local). New:

- **Lesson (a) transfers:** `117D50` (`U16Read`, 4 compiles) is the fast-path shape of `117C80`.
- **Copy a matched sibling of another type:** `11D740` took the shape of `GTrunc__Ff` (`11D7F0`): literal masks and `value += 1.0` for the compiler's `__adddf3`, 21 compiles after 15 to 25 on permutations. The same for `*Menu_Construct`: `Menu_ResetState` with one argument as in `BusyMenu_Construct` (`1ACA98`, judged 26 times at 2 before the prototype changed).
- **Layout offsets:** `17B8B0` was `GOALPICK` members at the wrong offsets; reading the `lw`/`swc1` offsets in the `try.py` diff matched it in one compile. Retyping a packed links word as a bitfield struct matched `255438`.
- **A float global read through a struct:** a global declared as a struct of floats stops aliasing from moving the `lwc1` above int stores (`156548`, then `permute.py --random 1000` found the store order after 300 exhaustive compiles missed it).
- **Loop guards:** `if (index < count)` with `int index = 0` instead of `count > 0` stopped a hoist (`212880`); early returns of a member each add a ref and change the allocator's order (`1FE5F0`); a global-struct counter written before the virtual call (`1F40A0`).
- **Honest starts again:** `11D740` (registry 13 or 14 read `out.d` before assigning it, honest 20), `17DA28` (20 on a wrong `ClosestPointOnSegment` call, honest 32), `206748` (2 on a register pin, honest 3), `1F4558` (banned asm replaced by the `Vec3` lane helper, 10).
- **Walls:** the assembler (`11FEC8` stays at 14 where GNU as fills the `sqc2` slots but omits the load-delay `nop`s, ps2eeas the reverse; `179328` the same with `qmfc2` in a `jal` slot); a function entered through a jump table at `210ED0` whose first two words no C produces (`210ED0`, 2); loop-invariant `%hi` hoists in swapped saved registers (`16DD58`, 4); a `memmove` argument block (`14E328`, 9); CSE of a stack address (`1D8A38`, 16).

### Sonnet round 17: the least distant functions (158 functions, 2026-11-01)

Eight Sonnet workers on the 158 open functions at score 1 to 5 (all of them outside rounds 15 and 16, the SDK range, the hand-written list and three known fragments), about 10 compiles each: 32 matches, 84 near (5 improved, 6 got worse because the old score rested on a banned construct or wrong behaviour), 42 skipped. 1.27M subagent tokens in 13 minutes, about 40K per match. Results in `work/matching/r17_results.json` (local). New:

- **The pool at 1 to 5 was half fragments and half bugs in the draft.** Of the 158, 39 of the 42 skips are not functions: stray `addiu $sp` / `nop` epilogue words, a lone `sw` or `swc1`, padding, the tail of the neighbour's epilogue (`100000`, `116D20`, `117640`, `117BC8`, `117CF8`, ..., `11B470`). Their score of 1 was an artefact of a tiny compare. 12 of the 32 matches took one compile: a wrong pointer step (`2564E0`, `256528`: `s32*` arithmetic where retail steps bytes, cast to `char*` first), a wrong prototype or hidden parameter (`125060`, `182700`, `1423A0`, `2564A8`), a lane helper on a `QW` parameter (`259D98`, `259DA8`), a vtable idiom (`1371C8`), a loaded-from-message local (`2241D8`).
- **Scores of 1 to 5 hide wrong behaviour:** `121710` (5 to 37 honest), `11E7C8` (2 to 19) and `1193D8` (4 to 8) passed a hidden return pointer or used a register pin.
- **Register and branch shape:** a separate local for the second virtual call (`148860`); the condition as two compares into two flags (`148A78`); the positive form with one `return 1` (`1F4FC8`); an inverted condition with an early `return 1` and a tail call (`184380`); a duplicated tail in both arms so gcc cross-jumps it (`215D40`); `char[]` so an index shift is a byte offset (`1DAE58`); a chained store `cur = chain = 0` before the loop (`2568C0`).
- **Store order by search:** `194118` (14 stores) matched by a hill climb of `try.py` (314 compiles in a script) and `195950` (six float stores) by exhaustive permutation (870); `permute.py` with 120 compiles was too small. Worth a larger budget on any near miss that differs only in store order.
- **Assembler per function:** `201360` is 0 with ps2eeas-loop5 and was listed under GNU as; moved. `16E1A8` needed `VU1_START_0 = 0x0` in `config/matching/symbol_addrs.txt` so the address-0 `%hi/%lo` pair resolves in the link check.
- **For review:** `11D608` (`=&f` early-clobber on an existing `sqrt.s` asm: allocation only), `140AF8` (`asm volatile("nop")` after a `qmfc2` for the hazard nop), `1423A0` (ordering fences on the VU asm), `1BC208` (a two-lane-move asm with one scratch register).
- **Walls:** a VU asm that retail has in a branch delay slot (`11E9F8`, `11ED40`); load order of two `lq` (`122CE0`); prologue store versus `lui` order (`123BD8`).
- **Registry hygiene:** the fragments should be marked `fragment` so the pool and the tables stop counting them; they are listed in the SKIP rows of the results file.

### Opus round 18: a proportional sample of near misses (64 functions, 2026-11-02)

The near misses at score 1 to 20 with at least two tries, outside rounds 15 and 16, the SDK range, the hand-written list and any function whose note names a delay slot, assembler, hazard, jump table or goto loop (214 left, 76 dropped for the keywords, 138 in the pool): a proportional draw of 64 by size and distance (seed 20261103), eight Opus workers, about 30 compiles each. 34 matches, 27 near, 3 skipped, 1.46M subagent tokens, about 43K per match (round 15 and 16 pooled: 94K). Four of the 27 near misses end at 2 words from a `$` in a vtable symbol name (see Walls). Results in `work/matching/r18_sample.json` and `r18_results.json` (local). New:

- **Copy a matched sibling's shape:** 12 of the 34 matched in one compile that way. `117C20` and `117DB8` are the fast-path shape of `117C80`, so the `U16`/`S16`/`U32`/`S32Read` family is one template; `2550F8` is `255438`'s bitfield links word; `129398` and `129878` are `129248`'s and `129808`'s shapes with a by-value 8-byte struct copy where m2c had `ldl`/`ldr` asm; `1FAC98` is `1FAC30` with the pointer moved from `SO+0x58` to `+0x5C`; `1F0850` is `SkipSma`'s RAII holder. When a function has a matched sibling, read its source first.
- **Indexing for loop strength reduction:** a pointer step written as an index (`apg[ikey*2]`, `&droplet->soTouch->ageom[index]`, a plain `for (index...)` in place of a hand-written down-counter) lets gcc make the running pointer and its preheader like retail (`12C570`, `1D0D28`, `173E78`).
- **Prototypes:** `14C6D8` (six arguments, two by value as `QW`), `2159E0` (the `Draw*Character` callees take four arguments, so `a1`..`a3` stay live and the object is copied to `$t0`), `19E950`, `1D3FF0` (two arguments).
- **Cross-jumping:** a call in each arm of an if/else-if chain with the final else clearing the target (`20B2A8`), the DLI iterator order of `139250` (`1CE1C8`, `1CE608`), a `switch` instead of a goto chain (`1AB418`).
- **Raw offsets against typed members:** `1DCD08` stayed at 8 in every store order with a typed struct and matched with the raw `*(int *)` offsets of the sibling `ShopMenu_InitPage`: member types change the scheduler's order between the `lui` and the constant.
- **Scripted search again:** `218660` (1,520 compiles after a one-member struct type for `stamp` and a `StopAmbRef` inline helper, then `permute.py --random`) and `177E80` (555, a chained store first and a random search over seven statements). Both were store-order walls.
- **Honest starts:** `12AA70` (registry 18 on `asm volatile("")` and a double destruct, honest 15), `1C7BB8` and `1C8110` (8 not honest, now matched with an inline `GetSaveInt` helper that has its own `CRef`), `20BC08` (a banned `por` asm rewritten), `110EC0` (start 8 came from a source with no return, honest 10).
- **Walls:** the factory family at `110CD0` (`110EC0`, `110CD0`, `110D18`, `110D60`, `111090`, `111218`, `111260`, `1112A8`, `1112F0`, `111338`, `111380`, `112100`): with a real class (multiple inheritance, vptr at `+0xC`, a second polymorphic base) every instruction is byte-identical and only the vtable symbols are left, 2 words each; the symbols mangle as `_vt$13CObject<addr>` and `_vt$13CObject<addr>$16CSecondary<addr>`, which `name.py` and `compare.py` rejected because of the `$` (fixed 2026-11-02: both accept it, the 25 names are registered, all twelve landed; see "Solved" above). `254ED8` is a sibling call (`j`, no frame) that SN 2.95.3 turns into `jal` plus a frame. The no-output VU asm acting as a scheduling barrier again (`158668` matched with it; `2255C8`, `190D10`, `1B6CC0`, `14F040`), and prologue scheduling (`1BCF18`, `150938`).
- **Needs a ruling:** `11C288` (registry 3) rests on `"=r"` fence outputs the templates never write and unused `f` inputs; an honest vf-register version scores 6. `158668` depends on a no-output VU asm as a barrier; `15C198` has an unwritten tail `QW` member in a params struct (the frame shows it).

### Sly 1 reference pilots and a plain near-miss batch (2026-11-02)

Three runs on the same day, to learn where a paired Sly 1 body (OpenThievius/sly1-decomp, same SN 2.95.3, read as a hint, nothing copied) pays and where it does not. Every match below was re-run with `try.py` by the lead before it was landed.

| Run | Functions | Matched | Notes |
| :--- | ---: | ---: | :--- |
| Pilot 1: pairs scoring 0.8 or more, with the Sly 1 body | 22 | 16 | 14 with the default assembler, 2 only under `ps2eeas-loop5` |
| Plain batch: nonmatching at score 10 or less, no reference | 171 | 9 | 6 landed; 3 held for a ruling (`1C8090`, `14F478`, `15B0C8`) |
| Pilot 2: new pairs from `pair` features and the leftovers | 53 | 11 | 10 landed, `114AE0` held (see below) |

- **When the reference pays:** a pair whose method is `callers`, `calls`, `class` or `order` and whose body is the same function. It gave the whole shape in `UpdateJoyNavX`/`Y`, `1AB750`, `1ECC28`, `11A770`, `1871C0` and the `printf` family (`21DD40`, `21E4B8`, `21E718`). Pairs guessed from source features (`predicted`, 37 of the 53 in pilot 2) were the wrong function in at least 26 cases by the workers' reports; the leave-one-out control on known pairs said 42 of 43 at margin 0.2, but it only covered 94 anchors with many features, so do not read a `predicted` pair as a pair until the first diff agrees.
- **What the reference carries:** statement order, `if (n) do {} while (...)` against `for`, re-reading a field instead of caching it, goto-merged tails (`1EE100`, `127DB8`), the order of locals, early-return shape. It does not carry types, struct layouts, callee argument lists or widths: each had to be fixed against retail (bitfield order of `TEX0` in `1EC9D0`, `unsigned char` for a `lbu` callee parameter in `21DD40`, `RO_` externs for strings in `21E718`).
- **A matched Sly 2 neighbour is often the better reference.** `1CDE80` matched from `UpdateRipg`'s inline step helper, `1B68B8` took its `QW` argument pattern from `SpawnSwHitFx` (and the near miss `1BABA0` the allocation-request idiom of `LoadCoinFromBrx`), `2046F0` the VU0 fence chain of its siblings. Grep `src/` for the callee or the idiom first.
- **Run all three assemblers on every near miss** (`TRY_ASSEMBLER=ps2eeas|ps2eeas-loop5|gnu`). It found `226F28`, `1AABC0`, `136CC0` and `1871C0` (`config/us/gnu_as.txt` to `ps2eeas_loop5.txt`); `139370` and `13AC18` score best under loop5, `140F90`, `143220` and `1457A8` under gnu, though none of those five matched.
- **Real C++ semantics move frames and register permutations that wording does not.** `126BA0` went from 78 to 28 with a `CRef` that has an inline constructor and destructor and a `CRef refKey[2]` array (the compiler then emits the constructor loop, the saved end pointer and the destructor loop); an RAII list iterator (constructor stores the link and `g = this`, destructor restores it) gave `2267C0` retail's store order and 0x70 frame; `(obj->*pmf)()` expands to retail's `ld`/`dsra32`/`jalr` (`1FEA60`); a `GIFS gifs;` scoped to each case runs the constructor per case (`1EB960`). Name the class anything but `CRef` in a scratch file when a callee is `__as__4CRefRC4CRef`: a struct called `CRef` makes gcc read it as `operator=`.
- **Smaller forms that matched:** a packed `struct UL { unsigned long v; }` read at the lower address for an `ldl`/`ldr` from read-only data (`1BAED8`); a 64-bit mask as `0x8000L << 33` (`1997D8` near miss); `x = f4 ^ f3C; word0 = f0 ^ f34; word0 += 0xCA0; flag = x != 0` in that order (`1AB750`); an `extern "C"` vtable-bearing two-base class for the twelve factories; a minimal `asm volatile("mfc0 %0, $9" : "=r"(count))` in a typed struct for the COP0 read (`14D240`, same asm as `StaticInitClock`); and one function-level `int index` shared by two loops (`11A770`, 7 to 0).
- **Fused VU asm:** `lqc2 vf1, %1; sqc2 vf1, %0` in one `asm` fixed a delay slot and a `daddu $a0` (`1BC9F0`, 5 to 3, not matched).
- **Walls, again:** `sqrt.s $f1,$f0 ; mov.s $f0,$f1` against our in-place `sqrt.s $f0,$f0` (`11CAB0`, `11D608`): the only workaround found is an early-clobber output, which `0e2c843` reverted as steering; a VU instruction in a branch or `jal` delay slot (`1E4D40`, `1E69A0`, `182810`, `179328`); `sqc2` after the epilogue loads (`19EA00`); s-register rotations of `s0`..`s3` that no declaration order or wording moved (`1C03C0`, `138660`, `16D6C8`).
- **Boundary problems, not C:** six functions in `nonmatching/` start with a leftover block that cannot belong to them (`addiu $sp,$sp,0x10 ; nop`, or `lwc1 ... ; nop`): `116EA8`, `14F3C0`, `15F058`, `210ED0`, `259B18`, `259D58`. Their true start is 8 bytes later; the fix is a function-start symbol in `config/us/symbol_addrs.txt` as `U8Read__18CBinaryInputStream = 0x117BD0` has, and it moves the address into the PAL pairing, so do it for all six at once.
- **Held for a ruling (still in `nonmatching/`):** `1C8090` (matches only with a local that holds `B_003E0EA8` so that `+ 8` does not fold into the `%lo`), `14F478` (`=&r` early clobber on a lane-move asm), `15B0C8` (VU0 asm taking `pv`/`ppos` as `"r"` plus a `"memory"` clobber and a dummy `"=m"` output), and `114AE0` (a 1,926-word compiler-generated static initialiser: its source defines a 256-entry palette read out of retail and two header objects, which is game data, so it stays out of `src/`).

### Opus round 19: the big nonmatching functions (25 functions over 1,000 bytes at score 150 or less, 2026-11-02)

Four Opus workers, about 15 compiles per function, no Sly 1 reference (none of the 25 has a paired body). 7 matched (28%): `1D9DF8` `UpdateMeter` (92), `202768` (118), `154E10` `OnDifficultyBreak` (148), `211528` (140), `159500` `CEmitter_PostLoad` (122), `15CF30` `UpdateEpsel` (148), `161A58` (97). Every match was a rewrite from retail's block structure, not a patch of the m2c draft; the draft scores were not honest starts (`1C9B08` read 50 with a wrong `Read` prototype and 60 with the right one).

- **Rewrite, do not patch, a draft above about 90.** Typed structs, the real prototype (argument order, `QW` by value, float arguments, `void` returns, no trailing object on virtual calls) and the case layout in retail's order took 148 to 0 (`154E10`, `15CF30`) and 140 to 0 (`211528`: nine plain `GIFS` locals, `tag[k] |= 1` in call order, a `for (y = 0; y < 0x200; y += 0x20)` that gcc reverses into retail's countdown). A banned `por` asm in the old `154E10` draft went away with the rewrite.
- **Inline helpers with their own parameters** give a value its own pseudo, so they fix register allocation no wording moves: `SetMeterIds(self, a, b, c, d, e)` called in each arm (`1D9DF8`, 16 to 0), `GrfOf`/`AddGrf` (`202768`, 25 to 0), the CRef getters `GetSaveInt`/`GetSaveFloat` that share one stack slot (`15CF30`), an RAII class whose inline constructor saves and destructor restores two task fields (`161A58`). A global read through a helper that takes a pointer parameter keeps retail's `lui` in a saved register plus `addiu`/offset at each use (`1C5148`).
- **A `switch` or if/else-if chain in retail's branch order** lets gcc cross-jump identical calls into shared tails: case 1/6/7 as one chain ending in `break` (`1D9DF8`), the player-mode switches of `1715F0` (116 to 8).
- **Read the loop pass.** `COMPILE_FLAGS="-O2 -G0 -ffast-math -fno-exceptions -dL"` writes the loop.c decisions next to the source: retail's hoisted constants and saved-register pointers come from loop.c's budget (about 63 insns, 3 less per move) and from how long the value lives, so where a variable is declared moves a score by 13 to 30: `float half = 0.5f` inside the beat loop (`152C58`), `Regs *pregs = &g_2decd0;` before `EndDmaCnt` (`1477D8`).
- **A scalar that retail spills stays out of the locals struct** so gcc can still hoist it (`17BFF8`); a struct that holds every local fixes the frame otherwise.
- **Assembler wall, now seen four times in one group** (`2206C8`, `206900`, `224EC8`, `2297F8`; also `11FEC8`, 14 under gnu, 13 under ps2eeas): retail's assembler both fills a delay slot with a VU instruction taken from an asm (only GNU `as` does that) and inserts the hazard and loop-pad nops (only `ps2eeas` does that); neither assembler produces both, so no source change reaches 0. Do not spend compiles past the first assembler check on a function whose diff has both.
- **Stopped:** `186A50` (about 140 volatile VU0 asms in the draft; retail interleaves FPU code between the VU ops and hoists the +-1.0 constants into the prologue, so it needs a full non-volatile rewrite), `1C9B08` (the `aoption` index `i * 0x18` is not strength-reduced: the loop is 66 RTL insns where gcc needs about 64), `12F9B8` (jump.c puts `li 7` between `li 5` and `movn`, so loop.c will not hoist the group), `142AF8`, `1D1518`, `140F90`.

## Rulings (2026-11-02)

Theo's decisions on the constructs the rounds of 2026-11-02 reached; each one applies AGENTS.md's test for a trick (could the original source plausibly contain it, and does it change no behaviour). A function that matches only with a construct marked "not allowed" stays in `nonmatching/` at its clean score, and its note says which construct it needs.

**Not allowed**

- **A wrong prototype that only steers allocation.** Declare a callee as it is in retail: its real return type and argument list, read from the callee's own disassembly or a matched sibling. `22C8C0` (`BuildXfLocalMatrix`) matches with `void memcpy(void *, const void *, unsigned int)` because a call whose result sets `$v0` occupies that register; the real `memcpy` at `0x23320C` returns its destination, so the `void` declaration is a trick. Clean score 12. A prototype from retail or a matched sibling is the opposite and is the commonest fix (`20D9D0`: `CreateSlotheapSwAlign` returns `void *`; `1C60B8`, `1FF188`: missing or extra arguments).
- **An early-clobber constraint (`=&r`, `=&f`) that only steers allocation.** It is allowed when the asm text writes an output before it has read all its inputs, so that sharing a register would give a wrong result (the fused lane move of `BuildXfLinearRateMatrix`: the temp is written before `vec` is read again); say so in a comment. It is not allowed to move a register: `14F478` (`prot3w` output), `196928` (`sqrt.s` output, registry 17, clean 25) and the `sqrt.s $f1,$f0 ; mov.s $f0,$f1` family (`11CAB0`, `11D608`) stay as they are. Commit `0e2c843` reverted this once already.
- **A dummy operand or a `"memory"` clobber that only orders blocks.** An asm operand must be something the block reads or writes. `"+m"(junk)` on a stack slot the block never touches, `"memory"` plus a throw-away `"=m"` output (`15B0C8`) and one-instruction `asm volatile` barriers (the draft of `14DA08`) are not allowed. A `"=m"` output on the slot retail really stores to (the `sqc2` target) is allowed.
- **A local that exists to stop a constant folding.** `char *psw = B_003E0EA8;` so that `psw + 8` does not fold into the `%lo` (`1C8090`) is not allowed unless retail keeps the pointer in a saved register across calls, in which case it is a real local and the register shows it.
- **Game data in the source.** Do not define a table, palette or header values that were read out of retail: reference them with an `extern` at retail's read-only or data address (`RO_<addr>`, `D_<addr>`), copied by struct assignment as `1FEED0` does. `114AE0` (a 256-entry palette and two header objects defined in the static initialiser) stays out of `src/`. A handful of constants in an expression is fine.
- **A register pin on a VU register (`register QW v2 asm("vf2")`).** Not allowed, for `vf` registers too (Theo, 2026-11-02, after the queue waves). It is a register pin whatever the register file, and AGENTS.md's "no register pins" has no exception. Four matches of wave `nf1` (`19EA00`, `1B2398`, `1CF618`, `1E69A0`) reached score 0 only with it and stay in `nonmatching/`. Eight functions that landed before `record.py` scanned new matches already use the form (`TiltMatUpright`, `RecalcSwXpMovement`, `FIntersectRayTriangle`, `fun_0011ea60`, `MatchJtXmgRail`, `GetNormalVectors`, `RefOpMatrixLookAt`, `fun_0019f3f8`); they are open for a decision to re-open them.

**Allowed (already used, now explicit)**

- **Fence-token outputs between VU0 asm blocks** (`"=r"(fence)` that the next block takes as `"r"`): they model a real dependency between a load and its use and are the documented way to let the scheduler interleave (see "VU0 functions"). They are tolerated when the token is never written, but each use should carry a comment; the landed users (`LoadRotateMatrix`, `GCosAngle`, `155AE0`'s replacement of them by one fused asm) are the audit list.
- **A base class with padding virtual methods** to reach a vtable slot (`134850`: 98 virtuals, `Query` at `0x31C`), and a two-base class for the factory family: plain C++ that reproduces the layout.
- **`goto`** as plain control flow (`1EE100`, `127DB8`, `1B93E8`), and a `union` only when retail's frame shows two locals sharing a slot.
- **Lane-move and COP0 asm** as already written above (`mtc1`/`mfc1` lane moves, `mfc0 Count` in `TickReadCount`).
- **One shared `sqrt.s` helper: `static inline float Sqrt(float x) { float r; asm volatile("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }`** (amended 2026-11-02, after the todo round). `__builtin_sqrtf` compiles to a call, so the instruction needs asm in any case, and the `volatile` is what a shared inline math helper from the original headers would carry: `1FDC08` and `14AA30` reach 0 only with it (clean builtin scores 4 and 8), `187768` and `1C0648` come closest with it, and landed `SetSlotSoSmp` already uses it. Use this exact form, one helper per file, never per call site, and never with `=&f` (that stays banned: landed `UpdateStepXfWorld` uses it and is on the audit list, and `196928`'s old registry 17 depended on it). This replaces the "one-instruction `asm volatile` barriers" ruling above for `sqrt.s` only.

**Still in `nonmatching/` because of these rulings:** `22C8C0` (wrong prototype), `14F478` and `196928` (early-clobber), `15B0C8` and `14DA08` (dummy operands, barriers), `1C8090` (folding local), `114AE0` (game data), `20C7E0` (matches at 2 only by reusing a variable to move a register; honest 4).


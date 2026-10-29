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
  C cannot express them: skip them at once, and fix the split instead.
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

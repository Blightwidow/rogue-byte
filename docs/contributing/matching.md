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

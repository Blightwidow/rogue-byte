# VU0, MMI and build levers from Sly 1

Derived from the Sly 1 decomp's docs/toolchain vu0-helpers, mmi-system-helpers and still-to-qualify (AGPL-3.0-or-later, same maintainers); mechanisms measured on Sly 1's compiler, not yet re-measured on Sly 2 unless marked **measured here**.

Function names from Sly 1 are not ours; ours come from `config/us/inline_functions.tsv`, `blockers.tsv` and `nonmatching/MANIFEST.tsv`. Rules that bind everything below: [AGENTS.md](../../AGENTS.md), [inline-asm-helpers.md](../build/inline-asm-helpers.md), [exceptions.md](../contributing/exceptions.md). Our helpers: `include/ps2inline.h`, `include/vu0inline.h`.

## 1. Which asm GCC 2.95 treats as volatile

- An `asm` is volatile when written `asm volatile`, **or when it has no outputs** (stmt.c). An output-less `asm("sync")` is volatile whether or not the keyword is there. Every other helper of ours has an output, so none is volatile.
- A volatile asm is a full barrier:
  - sched1 and sched2: haifa-sched treats `ASM_OPERANDS` with `MEM_VOLATILE_P` as depending on everything, so loads that retail issues before it cannot move after it and the reverse.
  - reorg: `resource_conflicts_p` counts any insn with `volatil` set as a conflict, so `redundant_insn` never looks back across one. A copy that is redundant with an insn in an earlier delay slot is then kept, and delay slots that retail leaves empty get filled (Sly 1 `func_00185150`).
  - combine: GCC does not combine into or across a volatile insn (general GCC behaviour, not re-measured).
- Consequence: a non-volatile helper lets GCC move loads, stores and other asm across it, as retail's code does around vector sequences. Volatile is for hardware order only (`sync`, `ei`); AGENTS.md already limits it to that.
- A multi-instruction asm is one insn to the scheduler: nothing is scheduled inside it. That is why `SquaredLength` (4 instructions) or `SquaredLengthXy` (2) differ from the same instructions as separate helpers (`AdjustSlyNewXp` 7 split, 0 joined; `inline-asm-helpers.md`).

## 2. Operand-constraint levers

| Lever (Sly 1) | Sly 1 form | Ours | Status |
| :--- | :--- | :--- | :--- |
| `"*r"` on the GPR operand of a float move from a VU product: `*` makes regclass skip the letter, so the operand adds no GPR preference, the product keeps its `"=j"` (VU) preference, and reload emits retail's `qmfc2` as an input reload (unit vu0 in sched2, GPR from reload's rotation). Fixed nine functions there; one helper change, no new asm | `ToFloatMoved`, `StoreX`: `"*r"` | `LaneX` is `asm("mtc1 %1, %0" : "=f"(f) : "r"(q))`; `LaneZ`, `LaneYInGeneralRegister` and `LaneZInGeneralRegister` take `"r"(q)` too | **Not tried.** Fits the lane read of a `QW` that a `"j"` helper produced. `"r#j"` is the equivalent. Changing a shared helper means re-proving every user |
| Operand order of `"j"` inputs decides the result's register (`"=j"`, not `"=&j"`: the allocator ties the result to the first input that dies there) | scale first in `MulX`; `Rotate` tied to `v` | `VectorScaleX` scale first, `ScaleByReciprocalX` divisor first, `TransformPoint`/`TransformVector` rows first (commented: 8 to 0, 136 to 128, 70 to 69, 35 to 31) | **We already do this.** The open miss is the one Sly 1 also lists: `ScaleByReciprocalX` users stay at 6, 67, 46 because retail's result takes the vector's register, ours the divisor's; our `"0"` tie made it worse. Sly 1 raised priority with `"+j"` for `MulAddX2` | `"+j"` priority: **not tried** |
| `"f"` operands for `FromFloats` (mfc1 x3, pextlw, pcpyld in one asm: separate mfc1 are hoisted by sched1 and change the FPRs) | one asm, floats `"f"` | `InterleaveLowWords(float, float)` and `JoinLowDoublewords` take `"r"` floats (GCC adds the `mfc1`); `QuadFromFloat` is `mfc1` with an `"f"` input | **We differ.** Ours splits the sequence into one-instruction helpers, which is what AGENTS.md requires; the Sly 1 form is a 5-instruction single asm with no ACC/Q reason, so it needs a ruling (section 3) |
| In-place `pextlw` splat: `pextlw t,t,t; pextlw r,t,t` in one asm, the first writing its `"r"` input's register | `Splat` | `InterleaveLowWords` has float arguments only; a second `pextlw` over the first result has no helper form | **Not tried** as two one-instruction helpers, the second taking a `QW` (allowed; chain not needed) |
| `volatile`-free `FromFloat` as `"r"(f)` (gives `lwc1`+`mfc1`); `"r"` kept because a bits form breaks computed floats | `FromFloat` `"r"` | `VectorFromFloat` `"r"(value)`, `VectorFromWord` `"r"(word)` | **We already do this**, both forms exist (retail's `lw` path uses the word form) |

Smaller items we also share: float input via `qmtc2.ni` from `"r"`, output through a `QW` and `LaneX`; `QW` (TImode) operands because a struct as a `"j"` input crashes cc1plus; no `"memory"` clobber; no volatile except barriers.

## 3. Fixed-register microprogram interfaces

Sly 1 matched the two functions that touch `$vf16..$vf31` (a `vcallms` microprogram reads fixed registers) this way:

- **Register variables named as `"j"` inputs** (`register QW a asm("vf21")` and so on, all nine as inputs of both `vcallms`). Volatile helpers cannot match: the barrier changes the loads' order.
- **One non-volatile asm with an output** around a short fixed sequence (`ctc2; ctc2; cfc2; vnop`): GCC does not make an asm volatile when it has outputs, and the sched1 dependents of three field loads then fall out as retail has them. Also a sequence count scan of retail text decides how many such sequences exist.

Where our rules stand, plainly:

- **Register pins are not allowed.** AGENTS.md ("no register pins") and exceptions.md ("Not allowed": `register QW v asm("vf2")`; 8 matches from before 2026-11-04 went back to assembly). `RenderGlobsetTree` (`0x1D5808`, 2824 bytes, kind `vu` in `inline_functions.tsv`) is the case `inline-asm-helpers.md` already calls out: its microprogram reads fixed `vf10`-`vf17`, which "needs register pins". Not allowed without a maintainer ruling.
- **A multi-instruction non-volatile helper with an output is allowed only for chains through ACC or Q and the one `SquaredLengthXy` pair.** A sequence like `ctc2/ctc2/cfc2/vnop` or `mfc1 x3 + pextlw + pcpyld` is neither, so it is **not allowed without a ruling**.

Rulings to ask for (none assumed):

1. Register-variable `"j"` inputs for a hardware microprogram interface (fixed VU registers a `vcallms` reads), stated as a hardware ABI, not steering; evidence required per function.
2. A multi-instruction non-volatile helper with outputs when retail has the instructions adjacent in at least two functions (the `SquaredLengthXy` ground generalised beyond ACC/Q).
3. A `mfc0` helper: a non-volatile asm with no inputs is CSE'd and hoisted, so Sly 1's `ReadCop0Status`/`ReadCop0Count` are volatile; AGENTS.md allows volatile only on barriers.

## 4. Toolchain facts from still-to-qualify

| Fact (Sly 1) | Here |
| :--- | :--- |
| libm that divides needs Sony 2.9-ee-991111-01 (`nop; nop; div.s`, `div.s` out of delay slots) | **Have it** (lessons.md section 3, `config/us/sony_gcc29_01.txt`, `TRY_ASSEMBLER=sony29-01`; atanf, atan2f, sqrtf match under it). Archive is pinned by SHA-256 in building.md. Near misses remain in the range (`__ieee754_fmodf` 33, `__ieee754_asinf` 66 in the manifest) |
| Per-file flags `-O2 -G0 -fno-exceptions -fno-rtti` | We use `-O2 -G0 -ffast-math -fno-exceptions` for SN 2.95.3 game code (compiler-identification.md). The `-ffast-math`/`-fno-rtti` difference is evidence of a different build, not an error |
| C++ runtime was built with **exceptions on** (2.9-ee-991111 default): throw functions match only so (no tail calls, kept frame); unwind tables land in `.data` and must be dropped | **Not measured here.** The SDK range holds libgcc's `_eh.o` (`__throw`, `__throw_type_match` in symbol_addrs.txt), so exceptions code exists. Probe: compile a never-returning-call function with and without `-fexceptions` on the sony29 build |
| Assembler drops the `lui` carry for a constant-address store that lands in a `jal` delay slot (`lui at,0x1000` where retail has 0x1001); Sly 1 writes the high half itself in a post-pass | **Not found here.** Watch hardware-register stores at `0x1000xxxx` with a low half of 0x8000 or more; a one-word diff of `lui` in a delay slot is the symptom |
| `system.h`: `Sync` (`sync`), `SyncAndEnableInterrupts` (`sync; ei`), `ReadCop0Status` (`mfc0 $12`), `ReadCop0Count` (`mfc0 $9`, u64 result) | **Partial.** We have `MemoryBarrier` (`sync`, volatile). No `ei` or `mfc0` helper. `blockers.tsv` has 183 `system` entries; `inline_functions.tsv` 2 |
| `-malign-loops=3` default aligns the first label after a loop start to 8; a `do { } while (0)` is a loop to it, so fdlibm-style bit macros pad | **Macros present** (`src/sdk/fabsf.c`, `src/sdk/__ieee754_pow.cpp`). Alignment effect not re-measured here; AGENTS.md allows `do { } while (0)` only in a C macro retail plausibly had |
| MMI needs no `mmi.h` beyond the GPR forms of pextlw, pcpyld, pextuw, prot3w | Same: our MMI helpers are in `ps2inline.h` and cover those four plus `pand` |
| `sync.p`, `mtc0`, an inline `syscall` occur in one function each | No helper for one function (AGENTS.md: reused across functions) |

## 5. Open questions

- Does `"*r"` on `LaneX` (and the other `"r"(q)` lane reads) change any user? One-line header edit; build all users, list diffs.
- Does a `"+j"` tie on `ScaleByReciprocalX` or `ScaleAddX` move the result into the vector's register without moving the divisor (measure on the three near misses in its comment)?
- Is a `QW`-input second `pextlw` (splat) worth a helper? Count retail splats first.
- Do the sony29 and sony29-01 near misses (`__ieee754_fmodf`, `__ieee754_asinf`) differ in loop-head alignment or in `div.s` padding? Run `regalloc.py` and the diff classifier first.
- Are the SDK-range C++ runtime functions built with exceptions? Needs the probe above.
- Which of the three rulings in section 3 does the maintainer want, if any?

# Loop optimisation and constant hoisting

Derived from the Sly 1 decomp's docs/toolchain/loops.md (AGPL-3.0-or-later, same maintainers); mechanisms measured on Sly 1's compiler, not yet re-measured on Sly 2 unless marked **measured here**.

Scope: why a loop's constants and registers differ in a near miss, and what moves them. Everything is a hypothesis to test with `scripts/matching/try.py`; a lever counts only when `make elf` still reproduces retail. `sly1:` ids are Sly 1 addresses, not ours.

## 1. The hoisting rule

GCC 2.95's `loop.c` moves a loop-invariant computation out of a loop (into the preheader) when

    threshold * savings * lifetime >= insns

- **insns**: the number of real insns in the loop body (`cc1plus -dL` prints "N real insns", "moved", "not desirable", "life N").
- **threshold**: `1 + n_non_fixed_regs`, doubled when the loop has no call. `strength_reduce` uses `3 + n`. With `-mvu0-use-vf0-15` this came out at 79 (loop with a call) and 158 to 160 (no call). The threshold falls by 3 for every invariant already moved. Measured on Sly 1: a loop of 79 insns hoists, one of 81 does not.
- **savings**: insns saved per iteration (a reload of a constant is 1; a `%hi/%lo` pair counts more).
- **lifetime**: counted in **luids** (insn positions), not insns. A value used early and late in a long body has a long lifetime and hoists more easily; extra locals that stretch the range change the result.
- **Two passes.** `loop_optimize` runs twice (`-frerun-loop-opt`). The preheader order shows which pass moved what, and the last constant moved gets the first register, so order in the preheader is order of register numbers.
- **Phantom insns** inflate `insns`: call-ending `(use (const_int 0))`, argument copies, `sign_extend`, ADDRESSOF reads, `movti` copies. By-value `Vu0::Vec` copies took one Sly 1 loop from 53 to 94 insns.
- Related: strength reduction and `check_dbra_loop`; LOOP_VTOP exists only for `for`/`while`; DEST_REG givs and `combine_givs`; multiple-entry loops are ignored; PRE runs before `loop.c`; a float asm input is not moved (`may_trap_p`).

## 2. Flag thresholds and our per-function lists

The family `-mvu0-use-vf0-NN` makes VU0 registers allocatable, and therefore changes the register count that feeds the threshold: on Sly 1 the threshold is `64 + NN` (vf15: 79, vf30: 94, vf31: 95). So the same C hoists differently per NN. A near miss that differs only in which constants are hoisted, or in how many callee-saved registers the allocator uses, may move when NN changes. Sly 1 rule of thumb: before inventing a second movable in the source, rebuild at `-mvu0-use-vf0-vf30` and see whether the diff changes.

Our side (Sly 2, SN 2.95.3 for game code):

- **One flag set per source file** (AGENTS.md; docs/contributing/matching.md). A function of `src/` is its own source file; a whole file (`config/us/whole_files.tsv`) has one set and takes none from the per-function lists.
- `config/us/vu0_regs.txt`: 160-odd addresses compiled with `-mvu0-use-vf0-15` (`VU0_FLAG` in `scripts/build/compile_unit.py`). Any source that includes `vu0inline.h` gets it automatically. Also listed: functions with no helper that score 0 only with it, because it gives retail's callee-saved register set (docs/build/inline-asm-helpers.md "The flag per function"). Not neutral: 13 of 500 open sources got worse (exceptions.md).
- `config/us/move_movables.txt`: `-fmove-all-movables` (`MOVE_FLAG`), 2 functions today (`0x1BEB28`, `0x20C0E8`). It forces the hoist the threshold would refuse, so it is the blunt version of the lever in this page. Listed only when the function reaches 0 with it and not without.
- `config/us/function_flags.tsv` (address, flags, note): other documented gcc options per function, each measured (for example `-fno-gcse`, `-fno-schedule-insns`).
- **Allowed**: a documented compiler option, listed per function, added only when it takes the function to 0 and `make elf` still passes; source stays plain C++.
- **Not allowed**: per-attempt ad hoc flags, a different assembler, or splitting a file only to give half of it another threshold. A cut needs evidence of a real file boundary in the data (docs/contributing/lessons.md). Sly 1 split files on threshold evidence alone; that does not carry over here.

## 3. Symptom to source lever

The levers are wordings the original plausibly had. Check each against AGENTS.md before landing (no padding locals, no variable that only moves a register).

| Symptom in the diff | Lever (Sly 1 case, per its notes) |
| :--- | :--- |
| Constants reloaded in the loop, retail hoists | `Vu0::Vec` value types (`sly1:func_00140258`, `sly1:func_001F2EF0`) |
| Hoist missing in `for (i < n)` | `found[i]` index form (`sly1:func_00149190`) |
| Loop just under or over the limit | grow the loop past 243 insns (`sly1:func_00154370`) |
| Literal inside a helper rebuilt | literal placement (`sly1:func_00166690`) |
| `%hi` reloaded per iteration | `const f32& w = D_xxx;` (`sly1:func_001CF158`, `sly1:func_00131F60`) |
| Global compare reloaded | `x > D_global` (`sly1:func_001971B8`) |
| Curve address recomputed | address taken once (`sly1:func_001D7778`) |
| `i*sizeof` offsets | index versus pointer (`sly1:func_00118988`) |
| `T* f = &frames[i]` | needs vf30, not a source change (`sly1:func_0013AD80`) |
| Element pointer, `&recs[n++]`, inner-loop pointer | pointer wording (`sly1:func_001D9488`, `sly1:func_00148938`, `sly1:func_0013A940`, `sly1:func_00187260`) |
| Infinite loop layout | `do { } while (1)` versus `while (1)` (`sly1:func_00203828`) |
| Load width, register class | pointer parameter type (`sly1:func_0019C9C8`, `sly1:func_0013A618`) |
| Negated constant | `f32 near = -radius` (`sly1:func_001EEA40`) |
| `f32* out`, Vec stores | output pointer form (`sly1:func_001536C8` sibling, `sly1:func_00191AC8`) |
| Switch arms, tree constants, decl order ties | `sly1:func_001B7280`, `sly1:func_00130C58`, `sly1:func_001CF158` |

Rules of thumb from Sly 1: `blez` plus `li` before the loop means a hoisted constant; read `-dL` first; a different saved-register set is the tell for a different threshold; the last-moved invariant wins its register; ADDRESSOF slots show as stack traffic; one shared `i` across loops changes lifetimes; `j <= 3` versus `j < 4` changes the loop test; a body above 79 or 158 insns is not guaranteed to hoist.

## 4. Loop notes, `do { } while (0)` and run-once loops

- Loop notes change `REG_N_REFS`, act as a scheduling barrier and can force `.p2align`; a phony loop (notes around straight code) changes allocation though it never repeats.
- Sly 1 solved `sly1:func_00130C58` with a `BEGIN_WINDOW_SCAN` macro expanding to `do { ... } while (0)` around exactly two statements, at vf30.
- **Our rule** (AGENTS.md): `do { } while (0)` is allowed in game code only as the form C macros take (`#define NAME(...) do { ... } while (0)`) that the original plausibly had and retail's code needs. A bare `do { } while (0)` or an artificial one-shot `for`/`while` in a function body is a barrier: not allowed, never landed. `volatile` and inline asm as barriers are also out.
- So a run-once loop is only a candidate when the same statements appear in two or more functions, are naturally a macro (a scan, a window, an iteration helper), and the macro is defined in a header. One function's private wrapper is not enough.
- Not a barrier: a `while (1)` or `do { } while (1)` that is retail's real loop shape; keep the one that scores lower.

## 5. Diagnosing with our tools today

- `scripts/matching/try.py ADDRESS FILE [--lang c|c++] [--quiet]` gives `score N`; the diff is kept in `work/matching/diffs/<ADDRESS>.txt`. Environment `TRY_VU0=1` forces the VU0 flag; `compile_unit.py` has `--vu0`, `--movables` and `--flags "..."`.
- `scripts/matching/classify_diffs.py` buckets near misses (nop, immediate, register, ...); constant-hoist problems show as `immediate` or extra/missing `li`/`lui` pairs plus register shifts.
- `.venv/bin/python scripts/matching/regalloc.py ADDRESS FILE.cpp` explains register differences from the `-dl -dg` dumps.
- `scripts/matching/flag_sweep.py` scores every `tried` source under flag variants (`VARIANTS`: `-O1`, `-G8`, `-fno-gcse`, `-fno-strength-reduce`, ...) via `COMPILE_FLAGS`, writing `work/matching/flagsweep.tsv`; `flag_report.py` groups by module. It has no `-mvu0-use-vf0-NN` or `-fmove-all-movables` variant today, and those two are not in `VARIANTS` because they are per-function lists.
- Loop dumps: compile by hand with `-dL`, the way `regalloc.py` passes `-dl -dg`. No script wraps `-dL` yet.

## 6. Open questions

- Does our SN 2.95.3 `cc1plus` accept `-mvu0-use-vf0-NN` (NN other than 15), and is the threshold `64 + NN` here? **Not measured here.**
- Are 79 and 158 to 160 the thresholds at vf15 on Sly 2 code? Numbers are from Sly 1.
- Does the Sly 2 retail image show per-unit threshold differences (the Sly 1 maintainers split files on this)? We have no evidence yet and the file-split rule applies.
- Are our 2 `-fmove-all-movables` functions really a threshold effect (do they reach 0 at another NN)?
- Is each Sly 1 lever a plausible original wording, or only a steer? Measure on matched controls first.

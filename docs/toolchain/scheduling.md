# Scheduling and register order (GCC 2.95 sched1)

Derived from the Sly 1 decomp's docs/toolchain/sched1.md (AGPL-3.0-or-later, same maintainers); mechanisms measured on Sly 1's compiler, not yet re-measured on Sly 2 unless marked **measured here**.

Nothing here is measured here yet. `sly1:func_XXXXXXXX` are Sly 1 addresses. Sly 1 has replay tools (`tools/sched1.py`, `lalloc2.py`, `tools/globalalloc.py`); this repo has none.

## 1. What the pass does

haifa-sched.c's first scheduling pass runs before register allocation, so its insn order decides which pseudos are live together, hence registers. Same instructions in another order, or same code in other registers: look here first.

- **List scheduler, top-down, by cycle, issue rate 2.** Each cycle the ready insns are sorted by `rank_for_schedule` and issued from the best while their unit is free. Units: one memory insn per cycle, two alu, fmac, fdiv, flop. Insns of different units issue in the same cycle in rank order, and that order is what register allocation sees.
- **Tie-break chain** (first difference wins):
  1. priority: length of the longest path to the block's end, in latency (load 2, `mul.s`/`add.s` 3);
  2. `INSN_REG_WEIGHT`, lower first;
  3. class of dependence on the last insn issued;
  4. number of dependents;
  5. `INSN_LUID`, the insn order before scheduling (source order, after inlining, CSE and combine).
- **INSN_REG_WEIGHT** counts every SET or CLOBBER in the pattern (a store included, +1 each) and takes one off per REG_DEAD or REG_UNUSED note. A store whose value dies there weighs 0; a load +1 (0 when it is the last use of its base pointer). Read it from the `.combine` state, not `.sched`. At equal priority the insn holding a value's last use goes first.
- **Birthing raise.** When an insn's last dependence is resolved, an insn whose single SET is a pseudo set once in the function (`REG_N_SETS == 1`) and live at block end gets priority `max_priority`. A value assigned a second time loses the raise. A clamp written in place (`v = lo; v = hi;`) keeps the static priority; the same clamp as an inline function that returns its result (`if (v < lo) return lo; if (hi < v) return hi; return v;`) raises it.
- **Ready cycle.** Ready when producers' latencies have elapsed. MIPS ADJUST_COST is 0 in one place and 1 in another: trust the dump's table.
- **Blocks and barriers.** A call does not end a block. Barriers: volatile asm, ASM_INPUT, UNSPEC_VOLATILE, the first insn after LOOP_BEG/LOOP_END. The 33rd memory reference in a block flushes it. A jump or label ends it, including a label that jump2 deletes later.
- **Call rule.** A pseudo crossing no call (`REG_N_CALLS_CROSSED == 0`) has no anti-dependence on the last call.
- **Memory.** A load through an unaliased pointer (an argument register, a pointer loaded from memory) waits on every earlier frame store. Distinct frame offsets have no dependence on each other.
- **Asms** cost 1 as producer and consumer (dependence class 3 for insns that follow or feed one) and count against the issue rate.
- **sched2** (after reload, no register weight): priority, dependence class, dependents, LUID. LOG_LINKS from sched1 are never cleared, so a stale link on a register reload has changed still counts as a dependent.
- **Lives.** `REG_LIVE_LENGTH` counts sched1's output insns. global-alloc ranks by `floor_log2(refs) * refs / length`: one extra reference can swap two pseudos with identical code.

## 2. Symptom to lever

Keep a lever only if it is a form the original plausibly wrote.

| Symptom in the diff | Lever | Case |
| :--- | :--- | :--- |
| Two loads or subtractions swapped, same registers otherwise | Name or reorder the term retail loads first: ties fall to LUID, so the earlier statement goes first | `sly1:func_0016BEA0` |
| An add or load takes a neighbour's register; a clamp is written in place | Write the clamp as an inline that returns its result, so the sum is a pseudo set once and gets the birthing raise (costs one copy insn; one spill slot moved through gcse) | `sly1:func_00179A68` |
| Two equal subtractions swapped, copy preference of a shared operand differs | Read a field into a local before an unrelated `s = 0.0f; if (...)`, so the zero's flop slot delays one subtraction by a cycle | `sly1:func_001E31F0` |
| Two pseudos with identical code swap registers (global-alloc order) | One more reference changes `floor_log2(refs)*refs/length`: assign in both arms (`if ... goal = a; else if ... goal = a; else goal = b;`) instead of `\|\|` | `sly1:func_001E31F0` |
| Four loads in the wrong order | The load whose base dies goes first regardless of statement order; among the rest, the order of the statements that make results ready together decides (`cd = ...; ab = ...; ca = ...`) | `sly1:func_00142278` |
| A value is read late from a struct field | Read it once into a local (load first), or re-read the field in each expression (the load then follows an earlier insn and loses a LUID tie) | `sly1:func_001782C0` |
| A slot store (by-value argument spilled to a frame slot) comes before a load it should follow | Expand the load first: nested inline calls evaluate in argument order; name the value just before its use, after the other stores | `sly1:func_0014A8F8`, `sly1:func_001C3EB0` |
| A run of dead stores in the wrong order | They rank on LUID alone, issuing last; a copy through a named return value in the helper writes each row to both objects in turn | `sly1:func_00188B48` |
| Argument setup (`lui`, `addiu`, `lwc1`, `move a0`) issued before the previous call instead of after | A block boundary the compiler deletes later: a computed-but-unused value whose computation holds a test leaves its branch through sched1 and sched2. Only where retail's data holds an entry nothing reads | `sly1:func_001DEBE8` (matched) |
| Two argument loads of one call swapped in the delay slot | sched2 dependent counts include stale sched1 links; a helper that makes an asm output a pseudo (not a hard register) removes the extra dependent | `sly1:func_001358D0` |

## 3. Traps and invisible insns

- **Invisible insns affect lives and priorities but print nothing:** flow's `(use (const_int 0))`, a brace-init CLOBBER, `trap_if`, a branch to the next insn that jump2 or flow2 deletes later, a label with no uses. A diff that looks as if a statement is missing may be one of these.
- **Find the statement holding a value's last use** before reordering: it wins ties (weight) and moving it moves the death.
- **Equal-looking forms:** three statement orders compiled identically until a fourth changed which load became ready first. Read the dump before calling an order irrelevant.
- **Reload is round-robin:** first free register, starting one past the previous reload.
- **The 33-reference flush moves** when a read is added before it.
- **Barrier probes** (`asm volatile("")`, `do { } while (0)`) show what a barrier does to the order. They are diagnostic only (section 5).

## 4. Diagnosing with our tools today

1. **Classify the diff** (`scripts/matching/classify_diffs.py`, or read `try.py`'s diff). Scheduling shows as: the same words in another order within a block, no operand changes (`order`); or one register pair swapped through a whole live range (`registers`). A changed instruction count is something else.
2. **Registers:** `scripts/matching/regalloc.py ADDRESS SOURCE` reads `-dl -dg -dp` dumps (`DUMP_FLAGS` in the script) and names the pseudo, its birth and death, the allocator and the likely lever. It is the first stop for a `registers` diff.
3. **Order:** a dump of sched1's decisions is not wrapped by any tool. For game code (SN 2.95.3, `compile_unit.py`'s `FLAGS`: `-O2 -G0 -ffast-math -fno-exceptions`) pass `-dS -fsched-verbose-6` as `extra` to `compile_assembly`, or run by hand the command `compile_unit.py` builds with `-dS -fsched-verbose-6` added before `-S`. Sony builds: `SONY_FLAGS` (`-O2 -G0`), `assembler='sony29'` or `'sony29-01'` (Docker); sched2 is `-dR`. Dumps land beside the output (`.sched`, `.sched2`). Not run here (open question 2).
4. **What to look for in the dump:**
   - the `Ready list (t = N):` lines (sorted, best last): two ready insns at the same priority are where a lever acts;
   - a priority different from the dependence table's `prio` column is adjust_priority's birthing raise;
   - `Ready-->Q ... queued` lines: an insn held back for latency;
   - the forward-dependence table of `.sched2` for stale links (a link whose register no longer matches the RTL);
   - `.lreg` for local-alloc's per-pseudo refs and life; `-dL` for loop.c.
5. `neighborhood.py`, `permute.py`, `mutate.py`, `rules.py` reorder blindly; a dump says which pair to try. An EXACT from `permute.py` with no plausible source is not a match.

## 5. Repo rules that limit the levers

[AGENTS.md](../../AGENTS.md) governs. In short:

- No inline assembly, register pins or artificial barriers in a function. `asm volatile("")`, `do { } while (0)` around statements and a wrapper written to move instructions are diagnostic only: never in `src/`, never counted as a match.
- A typed local bound to a value the code reads and then uses is ordinary code; a variable only there to move a register, or a local holding a global's address so a constant does not fold, is not.
- A computed-but-unused value (`sly1:func_001DEBE8`) needs evidence the original had it (retail's data or frame). No stand-in statements (Sly 1 has one by its own ruling; ours has none).
- `ps2inline.h`/`vu0inline.h` helpers are asms to the scheduler (section 1): statement order around them is a lever. One flag set per file, never per function. Of two wordings scoring 0, land the typed one.

## 6. Open questions

1. Port `sched1` and `globalalloc` replay tools (Sly 1's were needed for its hardest cases).
2. Which dump files and verbose output our SN 2.95.3, Sony 991111b and 991111-01 builds write for `-dS -fsched-verbose-6`.
3. Whether the rules hold on Sly 2's SN build and the Sony builds (Sly 1 results are SN 2.95.3).
4. Sly 1 left unexplained: `sly1:func_00109488` (life 2194), `sly1:func_00130C58`; `sly1:func_0020BB18` only with a stand-in (3,589 of 20,644 candidates exact). Dead end: CLOBBER-first for `sly1:func_0017ECE8`.

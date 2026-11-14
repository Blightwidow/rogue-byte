# CSE and PRE: what GCC 2.95 does to loads, addresses and copies

Derived from the Sly 1 decomp's docs/toolchain/cse.md and gcse.md (AGPL-3.0-or-later, same maintainers); mechanisms measured on Sly 1's compiler, not yet re-measured on Sly 2 unless marked **measured here**.

Function ids written `sly1:func_XXXXXXXX` are Sly 1 functions: they show a mechanism, not Sly 2 code. Nothing here changes what counts as a match: every lever below is plain C++ wording, and section 5 lists the ones our rules forbid.

## 1. What the passes do

**cse1 / cse2** (cse.c). A path ends at a `CODE_LABEL` with more than one use, or at `NOTE_INSN_LOOP_END`.
- `-fcse-follow-jumps` follows a conditional jump only when its label has one use and a BARRIER precedes it; `-fcse-skip-blocks` skips over a short arm.
- Memory: a store that is `MEM_IN_STRUCT`, BLKmode or through a varying address kills all memory; a scalar store at a fixed address kills that location only.
- `purge_addressof` runs after cse1, so a struct local (`Vu0::Vec`) is an addressof store at cse1 time.
- Copy rule: `V = S` makes V canonical only if V lives past the path and its last use is later than S's; otherwise the copy is replaced and deleted. This is why a copy that "should" survive vanishes (and why `last = c` after a join can keep one alive).
- `cse_around_loop` is stopped by any body store before the load, a CALL, a LABEL or `cse_jumps_altered`.
- Inline arguments: integrate substitutes an unmodified parameter straight into the hard argument register, so a pointer parameter never becomes a pseudo in the PRE table. A reference parameter (`Q`, `Of`, `Set`, `ScalarAt`) sets a pseudo to `&x` instead, and that pseudo is a PRE candidate.

**gcse** (gcse.c, lcm.c). One PRE pass (`MAX_PASSES 1`), two copy-propagation passes (two copy steps).
- PRE is lazy code motion with **no cost test**. Candidates are any pseudo set that is not a register or constant: loads, `%hi`, `plus fp N`. Any store or call kills all MEMs; the frame pointer is never killed by a call. A block with a call or store makes no MEM anticipatable.
- Critical edges get the insertion in the predecessor unless the skip edge has a block of its own (a `switch` with an empty second `case`: `sly1:func_001F3140`).
- **Table size** T = n_insns / 2, made odd, at least 11. Read it from `-dG` ("Expression hash table (N buckets"). Bucket of `(plus (reg R) (const C))` = (13258 + R + C) mod T; `(and ...)` starts at 13266; frame register R = 1; `(high sym)` starts at 7933 plus a name hash (`h += (h << 7) + c`). Pseudo numbers follow bucket order, which sets spill order and the saved-register choice. A `Vu0::Vec` copy adds 2 insns per `movti`, a `u128` copy none: Vec copies are a legal knob for T, solve T from retail's slot order first.
- `find_basic_blocks` adds `(use 0)` after a call that ends a block (`sly1:func_0013BF68`).

**loop.c / jump.c / final.** Hoisting needs threshold x savings x life >= loop insn count (80 in pass 1, lower in pass 2). "Loop N is phony" when the first insn after `LOOP_BEG` is not an entry jump or label. `expand_end_loop` rolls the head to the bottom within 30 insns. `final` aligns the first label after `LOOP_BEG` (an extra `nop`).

## 2. Symptom to source lever

| Symptom in the diff | Lever tried, and the case | Our rules |
| :--- | :--- | :--- |
| Saved register holds `sp+N` that retail rebuilds | Inline helper taking a pointer (not a reference), or a member `Clear()`: `sly1:func_00071238`, `_001701B0`, `_0017E710`, `_001B55C0`, `_00012C38`, `_001E7C60` | plain |
| Frame address PRE'd across a call | `Q()` and other reference-returning helpers return `*(u128 *)&(s128)r;` (a plain-memory use, not `&x`): `sly1:func_0017BCD0`, `_001E7C60`, `_000D36F0` | plain |
| Loop bound reloaded each pass | `for (i = n; --i >= 0;)`: `sly1:func_00186568` | plain |
| Count-up loop initialised in the wrong order | `for (i = 0; i < 8; i++)`: `sly1:func_001D4348` | plain |
| `i + 1` in a `bnez` slot | an empty second `case` gives the skip edge a block: `sly1:func_001F3140` | plain |
| A walk reads the original variable, not the copy | one `last = c;` after the join: `sly1:func_00114BB0` | plain |
| Same store and test in two arms hoisted | write the store and test in each arm: `sly1:func_00126CB8`, `_001D8E40`, `_000C8920` | plain |
| Second load stays where retail folds it | read it once into a local or twice via the member, per retail: `sly1:func_00187260`, `_00187F40` | plain |
| Member reloaded per pass | read `e->mesh->n` at each use: `sly1:func_00165AE8` | plain |
| Constant arrives via an argument register | inline function with one parameter: `sly1:func_0016BEA0` | plain |
| Constant lives in a saved register | a named local `s32 axisSize = 0x1800;`: `sly1:func_001389D0` | plain |
| Two PRE addresses tie in a bucket | change T (Vec vs `u128` copy, one more insn): `sly1:func_001841D0`, `_001E4578`, `_001BA5B0`, `_00186BA8`, `_001CC490`, `_001D5678`, `_001D7778` | plain |
| Pointer stepped vs a copy of it | one pointer variable at function scope: `sly1:func_001D5678`, `_00139740` | plain |
| Reload after a returning `if` | `ASSERT(0)` as last statement: `sly1:func_00183668` | **see section 5** |

Traps measured there: top-of-function declarations can be what retail had; invented temporaries usually hurt; `(a + i)->m` and `a[i].m` differ; source order sets pseudo numbers. Dump flags: `-dG`, `-dl`, `.cse`, `.loop`.

## 3. Loop-shape levers (jump.c)

jump.c's first pass deletes every jump into a block that a plain form makes, before cse sees it. What survives to cse decides block boundaries, so a loop form is a block-boundary lever:
- `break` / `continue` / `goto done` change which label is used and how often (`goto done` instead of `break`: `sly1:func_0015FD78`; a `continue` label for a top-of-loop test: `sly1:func_001388A0`; `min` through an inline: `sly1:func_001CC120`).
- A `while` / `for` loop keeps loop notes: an aligned label (a `nop`) and register counts that are raised inside the notes. A `goto` back edge has no notes. Choose by which of those retail shows.
- `if (c) do { } while (c);` is a bottom-tested loop (lessons.md section 2).

## 4. The %hi kept across a call: mechanism and an experiment

Our open case (lessons.md section 5): `%hi(B_003D4A60)` sits in a saved register across the save call (SetGameCoins, SetClueFound, StoreAudioModeInSave, UpdateJtLootSave, CreateSwSavePaths, UpdateCmLast; NEAR scores 9, 12, 11, 13, 47, 37 in nonmatching/MANIFEST.tsv). Retail computes `lui` early and adds `%lo` after the copy; ours computes the full address, or both halves late.

Mechanism, from `sly1:func_00140968` (RefreshDiscStatus, `if (g != s) g = s; return g == 0x14;`, matched there by this):
1. cse blocks end only at a `CODE_LABEL`; the arm of a plain `if` is in the compare's block, so its `%hi` becomes the compare's pseudo before gcse. One occurrence, PRE does nothing.
2. If the arm starts with a label that is still used when cse runs, its `%hi` stays a pseudo of its own. lcm finds the `%hi` anticipated at the end of the compare's block and inserts a new computation there; sched1 raises the `lui` above the first instruction because it now has a dependent. The copy keeps a register of its own.
3. The label must disappear before final. A loop note does not work (cse2 runs after loop.c and merges the copy; the loop label also aligns). A `goto` back edge works because cse1 folds the second test and the jump pass then drops the label.

The exact shape that matched (EXACT on US and PAL in Sly 1):

```cpp
if (g_value != status) {
again:
    g_value = status;
    if (g_value != status) goto again;
}
return g_value == 0x14;
```

The same store with the label before the first test also matched. A back edge whose test is the top one (`again: if (c) { g = s; goto again; }`) did not (nothing folds its jump). `while`, `for`, `do/while` forms give the right registers but a loop-aligned label (`nop`), 68 instead of 64 bytes.

Caveats for us. (a) Sly 1's function is a compare and store; our six are save-call wrappers with no compare, so the shape does not apply directly: it needs a real second use of the table on a path that the call does not cross, which is the lessons.md "real second use" lead. (b) Whether a hand-made `goto` back edge is what the original wrote is doubtful (Sly 1 itself flags it); it is a measurement of the mechanism, to be judged under AGENTS.md "Plain C++" before landing. (c) Unmeasured on SN 2.95.3 for Sly 2: run it first as a probe.

## 5. Levers that conflict with our rules

- `ASSERT(0)` / empty `do { } while (0)` as a loop-note barrier: Sly 1 allows it only for a not-reached check or argument check with proven need and a comment. Our AGENTS.md says no artificial barriers and allows `do { } while (0)` only as a macro the original plausibly had and retail needs; treat it as a diagnostic (to learn whether loop notes are the missing thing), never as a landing form, unless the maintainer rules.
- A dead helper parameter (the only wording that gave 0 for the %hi case): not allowed (variable that exists only to move a register).
- A local that only holds a global's address, an unused local or padding to size a frame, a callee declared with a wrong return type: forbidden.
- Dead stores to keep a copy apart (Sly 1 `func_00125C90`): a per-function ruling there, none here.
- `goto` is not named in our rules: fine as ordinary control flow, not as a wrapper written to move instructions.

## 6. Open questions

- Do the T formula and bucket constants (13258, 13266, 7933) hold on SN 2.95.3 and Sony 2.9 as built for Sly 2? Check `-dG` on one function of each toolchain.
- Does `-fcse-skip-blocks` plus a used label reproduce step 2 in a function with no compare at all (a save-call wrapper)?
- Is any of the six %hi functions a loop or retry in the original (a check of the save result)? Read the callee's return use.
- Do Sly 2's by-value `CRef` copies add insns like Vec copies and so move T?
- Sly 1 unsolved list (maybe the same mechanism): `sly1:func_001C3C98`, `_00145718`, `_00144540`, `_001D5678`, `_00187F40`, `_00125C90`, `_0020A190`, `_001E4C48`, `_0019ED58`, `_00191AC8`.

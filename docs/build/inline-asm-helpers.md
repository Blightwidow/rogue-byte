# Blockers that are compiled C: what sly1-decomp found and what it means here

Written 2026-11-08. Status: **not adopted**. Today's rule stays in [AGENTS.md](../../AGENTS.md) and [vu0-mmi.md](vu0-mmi.md) until the
steps in "What we need to do" are done. This page records the issue, how the two projects differ, and why the roadmap carries it.

## The issue

[vu0-mmi.md](vu0-mmi.md) classifies a function as a permanent blocker when its code holds one VU0, MMI or COP0 instruction
(`scripts/classify_blockers.py`). It never looks at the rest of the function. A blocker stays original assembly, counts as finished
apart from the exact C, and is left out of the work queues. But a function can hold a single `lqc2` and otherwise be exactly what GCC
makes of C: its stack frame, saved registers, calls with filled delay slots. For such a function the label "original assembly"
is wrong, and the reported progress hides work that may be possible.

## What sly1-decomp did (public history, 2026-11-07)

- `623ebf38` audited the 890 functions its `original_asm.tsv` listed. Most were compiled C: the VU0, MMI, system or `max.s`/`min.s`
  instruction was 1 to 5% of the function, and the same short sequences recurred across hundreds of functions. It added a third kind,
  **inline**, for a function with the compiler's frame (or holding `max.s`/`min.s`): 579 functions, 366,176 bytes. 169 stayed
  hand-written and 142 were remnants. They still counted as finished.
- `532148ad`, 15 minutes later, stopped counting them as finished and allowed shared inline-assembly helpers: small functions in
  headers of `include/`, for instructions the compiler cannot emit and that recur across retail's functions, never one function's own
  code (`Fpu::Max` and `Fpu::Min` beside `Fpu::Sqrt`). Their README now shows "C with inline assembly to match" as its own figure.
- Effect on its headline: US 4,728 of 4,807 functions (92.93%) to 4,150 (60.01%). Nothing was unmatched. Exact C stayed at 3,838 to
  3,839 and the build still printed MATCH. It is a change of what counts, not a loss of code. The project has matched about 200 of
  them since (4,358, 65.78% on 2026-11-08).

## How the two projects differ

| | sly1-decomp (now) | sly2-decomp (now) |
| :--- | :--- | :--- |
| Inline asm in matched C | allowed as shared helpers in `include/` | not allowed; `Sqrt` is the one exception |
| VU0, MMI, COP0 function | **inline** (to match) when framed and mostly C; otherwise hand-written | permanent blocker, any share of special instructions |
| Counts as finished | hand-written only | all 853 blockers |
| Special instructions are mostly... | short sequences (1 to 5%) | vector code, long VU0 runs |

This project already went the other way once: on 2026-11-04 (`a82e9edc`) the 236 matches with inline asm went back to assembly
(5,304 to 4,836 of 6,757). Sly 1 then moved from "assembly is finished" to "assembly with helpers is work", the reverse step.

## Audit of our 853 blockers (2026-11-08, read-only)

Method: disassemble each blocker from `work/elf/SCUS_973.16`; a candidate has a GCC frame (`addiu $sp,$sp,-N` in the first six
instructions, `+N` in the last eight) and a small share of special instructions (VU0, MMI, COP0, `max.s`, `min.s`). A heuristic, not
proof: it does not check that the rest is real compiler output.

| Share of special instructions (framed functions) | Functions | Bytes |
| :--- | ---: | ---: |
| 2% or less | 31 | 35,208 |
| 5% or less (sly1's top cutoff) | 106 | 99,688 |
| 10% or less | 258 | 195,888 |
| 25% or less | 487 | 342,864 |

- 620 of the 853 are framed; 233 are frameless (16,584 bytes) and stay hand-written.
- The 106 at 5% or less: 72 VU0, 24 MMI, 10 system.
- Sly 1 reclassified 65% of its list. Ours is 12% at 5% and 30% at 10%, because Sly 2's VU0 code is vector-heavy (vectors by value in
  128-bit registers): 354 of 589 VU0 blockers are framed but over 10% special.
- Headline cost if these stop counting as finished: about 106 functions, 1.7 points of the 6,078 (77.41%), at 5%; about 4.2 points at 10%.

## Pros and cons

Keeping today's rule (no inline asm, blockers finished):

- Pro: plain C++ only; no headline drop; a simple rule; the blockers stay out of the queues; cheapest route to the 80% target.
- Con: about 106 to 258 functions are probably C that is labelled assembly; the report overstates what is finished; those functions
  stay opaque; our counts stop being comparable with sly1's.

Adopting sly1's rule (shared helpers, an inline kind that is to-do):

- Pro: honest split between hand-written and C with a few instructions; readable matched source; the same convention as sly1 and as
  `sqrt.s`; new functions to match.
- Con: contradicts AGENTS.md and vu0-mmi.md, so it needs the maintainers' approval and edits to public docs; the cutoff is fuzzy; each
  of the 72 VU0 and 24 MMI functions needs a shared helper that reproduces retail's bytes (nothing is proven until a compile scores 0);
  a looser rule invites more inline asm (258 to 487 functions at 10% to 25%); and it is harder to take back once public.

## What we need to do

The roadmap lists this as a step we will need to take. Order:

1. **Pilot.** Compile-test about 10 of the 106 (2% or less first) with a small shared helper. Decision rule: if most reach score 0,
   the heuristic holds; if not, keep today's rule and drop this page's plan.
2. **Rule change.** If the pilot holds: edit AGENTS.md ("Matching rules", "Permanent blockers") and vu0-mmi.md to allow shared
   inline-asm helpers in `include/` for instructions the compiler cannot emit and that recur across functions; never one function's own
   code. Update `docs/contributing/exceptions.md` and the `record.py` inline-asm scan to allow only those helpers. Maintainer decision.
3. **Classify.** Add an **inline** kind to `scripts/classify_blockers.py` and `config/us/blockers.tsv`, measured by the frame and
   share test above, not by instruction alone. Keep the cutoff in one place and note its source.
4. **Count.** Report inline functions as their own line ("C with inline assembly to match"), not as finished, in the README table,
   `progress/` and `scripts/readme_progress.py`. Expect the headline to fall by up to about 106 functions and say so in the commit body.
5. **Match.** Write the shared helpers (VU0 and MMI headers), then match the inline functions through the normal queue.
6. **PAL.** Run `make pal` after each batch; commit `config/eu/` and `progress/eu/report.json`.

Until step 2 is done, no function may use inline asm, and the memory note about lane-move asm being provisional still applies.

## Open questions

- Which cutoff: 5% (sly1's top) or 10%?
- Should the inline kind be decided by tooling alone, or confirmed per function by a compile?
- Do we adopt before the 80% target, or after, so the headline does not move twice?

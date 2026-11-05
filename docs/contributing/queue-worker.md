# Queue worker protocol

For an AI worker that claims functions from a wave (`scripts/matching/claim.py`). Your prompt gives `WAVE`, `ID`, `N` (functions to
handle) and `COUNT` (claimed at a time). Read this file, then docs/AGENT_WORKFLOW.md and the "Rulings" section of docs/contributing/matching.md.

1. Claim: `python3 scripts/matching/claim.py take $WAVE $ID $COUNT`. It prints one packet per function: asm, best draft and its diff,
   nearest matched sources, your scratch folder, and the exact `try.py` command. Claim again until you have handled `N` functions or it
   prints `QUEUE EMPTY`. Do not stop after your first claim.
2. Step 0, one minute: a function that needs VU0 macro code, MMI, a lane move to an FP register, COP0, or a `nop` that no wording of the
   C gives (the assembler adds the hazard `nop` after `mtc1` itself since 2026-11-04, docs/build/assembler.md) is a wall (inline asm is not
   allowed, AGENTS.md): say `SKIP wall` and take the next function.
3. Work in your scratch folder only. Never edit `src/`, `nonmatching/`, `config/` or `data/`. Start from the best draft; rewrite from
   retail's block structure with real types and prototypes before fiddling with statement order.
4. Run every attempt as the packet says: `TRY_ARM=$WAVE-$ID TRY_BUDGET=<n> python3 scripts/matching/try.py 0xADDR file`. The tool logs
   each run and refuses past the budget (`BUDGET`, exit 3): stop there. The log decides; nothing you write counts as a match.
5. Plain C++ only (AGENTS.md "Matching rules" and the Rulings): no volatile on ordinary data, no register pins, no inline asm at all, no dummy
   operands, no wrong prototypes. Debug dumps (`-dL`) go to your scratch folder.
6. Before you write EXACT, run `python3 scripts/matching/check_source.py <your final file>`: it must print `ok`. It checks what a matched
   source may not hold (inline asm, register pins, `volatile` on plain data, raw `M2C_UNK` offsets, m2c temp names, tabs, a padding
   local); a source that scores 0 and fails it is parked, not matched. Then re-run `try.py` on that exact file: only its `score 0`
   in the log counts.
7. Final message: one line per function, `0xADDR EXACT|NEAR <what still differs>|SKIP <why>`.

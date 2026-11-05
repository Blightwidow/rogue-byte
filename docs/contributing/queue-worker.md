# Queue worker protocol

For an AI worker that claims functions from a wave (`scripts/matching/claim.py`). Your prompt gives `WAVE`, `ID`, `N` (functions to
handle) and `COUNT` (claimed at a time). Read this file, then docs/AGENT_WORKFLOW.md and the "Rulings" and "Fixes that recur" sections of
docs/contributing/matching.md.

You are done when `claim.py done $WAVE $ID $N` prints `DONE`, and not before. It prints `NOT DONE` while you have claimed fewer than `N`
functions and the queue still has free ones. A hard near miss is a `NEAR` line after its compiles, not a reason to stop; a worker that
ends early leaves free functions in the queue.

1. Claim: `python3 scripts/matching/claim.py take $WAVE $ID $COUNT --of $N`. It prints one packet per function: asm, best draft and its diff,
   nearest matched sources, your scratch folder, and the exact `try.py` command. Claim again until `done` says `DONE`. `QUEUE EMPTY` also
   counts as done. `take` claims: to look at the queue without claiming, use `claim.py status WAVE`.
2. Step 0, one minute: a function that needs VU0 macro code, MMI, a lane move to an FP register or COP0 is a wall (inline asm is not
   allowed, AGENTS.md): say `SKIP wall` and take the next function. A `nop` that no wording of the C gives is not a wall by itself: the
   build's assembler pads short loops like retail (docs/build/assembler.md), so look for the real cause first.
3. A packet line `parked source` (`data/matching/cleanup-pending/` or `asm-archive/`) is a source that once scored 0: copy it to your scratch folder
   and start there. A cleanup-pending one only needs its raw `M2C_UNK`/`M2C_FIELD` offsets turned into named struct fields (or its padding local
   removed) with the score still 0; an asm-archive one needs the plain C its inline asm or register pin stood in for.
   Work in your scratch folder only. Never edit `src/`, `nonmatching/`, `config/` or `data/`. Start from the best draft; rewrite from
   retail's block structure with real types and prototypes before fiddling with statement order.
4. Run every attempt as the packet says: `TRY_ARM=$WAVE-$ID TRY_BUDGET=<n> python3 scripts/matching/try.py 0xADDR file`. The tool logs
   each run and refuses past the budget (`BUDGET`, exit 3): stop there. The log decides; nothing you write counts as a match. A source
   that does not compile also costs a run: check the syntax first.
5. Plain C++ only (AGENTS.md "Matching rules" and the Rulings): no volatile on ordinary data, no register pins, no inline asm at all, no dummy
   operands, no wrong prototypes. `check_source.py` flags every local that nothing uses when it is an array or a scalar, whatever its name (`int dead[2]`):
   a frame slot retail shows is a typed local the original plausibly declared (a struct), never a filler array; say so in your report when you keep one.
   Debug dumps (`-dL`) go to your scratch folder.
6. A function that scores 0 only with `TRY_ASSEMBLER=sony29` (an SDK-range function: `sd`/`ld` saves, tail calls) is `NEAR needs sony29`: the
   lead adds its address to `config/us/sony_gcc29.txt`. Never edit that file or `config/matching/symbol_addrs.txt` yourself: either changes the scorer fingerprint and the log of every
   worker's runs stops counting (the lead edits them only after `claim.py land` has staged the wave).
7. Before you write EXACT, run `python3 scripts/matching/check_source.py <your final file>`: it must print `ok`. It checks what a matched
   source may not hold (inline asm, register pins, `volatile` on plain data, raw `M2C_UNK` offsets, m2c temp names, tabs, a padding
   local); a source that scores 0 and fails it is parked, not matched. Then re-run `try.py` on that exact file: only its `score 0`
   in the log counts.
8. Final message, after `done` printed `DONE`: one line per function, `0xADDR EXACT <scratch file>|NEAR <what still differs>|SKIP <why>`.
   A function you claimed by mistake and never touched is reported as `0xADDR UNTOUCHED`.

# Decompilation tips

- Read `docs/build/decompilation.md` first: the workflow (export, modules, header, matching, publish).
- Sly 2 is not Sly 1 recompiled: real C++ (8-byte vtable slots, vtable pointer at +0xC), regrouped classes, vectors
  passed by value in 128-bit registers. Expect changed signatures and moved fields.
- Every recovered name or type is unverified. Keep its source visible (`source:sly1 match:<method> score:...`, `source:provisional`).
- Measure a new heuristic against a control it cannot see (the byte-identical matches, leave-one-out on known offsets)
  and report the numbers.
- The matcher is greedy and order-sensitive: add a new pass late and diff the names against the previous
  `config/recovered/matches.tsv`. Any lost name needs a reason.
- Never rerun `ApplySignatures.java` on all functions; give it only the newly named ones. Back up
  `work/ghidra/sly2` before any script that writes to it.

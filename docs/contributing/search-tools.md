# Search tools for near misses

Tools that try many small source changes on a function that almost matches, and judge each against the retail code. They share one
scorer, so a search of thousands of candidates takes minutes. Run them with the repository's `.venv/bin/python` (they need `rabbitizer`
and `pyelftools`); [matching.md](matching.md) explains the score and [lessons.md](lessons.md) what has and has not worked.

| Tool | What it does | When |
| :--- | :--- | :--- |
| `scripts/matching/scorer.py` | Judges a source in process: registry, target words and symbols are read once, the compare runs in the calling thread, and every judged source is kept in `work/matching/scorecache/` (keyed by the source and a fingerprint of the compiler setup). `--bench ADDRESS SOURCE` compares with `try.py`. | Library for the others. About 50 compiles a second on 12 threads, twice `try.py`; a source judged before costs nothing. |
| `scripts/matching/neighborhood.py` | Every rewrite of `mutate.py` at every line it fits, plus every order of up to five consecutive declarations, then a beam search from the best few sources. Says when a depth found nothing better. `--batch` runs the pool of near misses. | Complete coverage of one-edit and two-edit changes. Use before concluding a function needs a larger rewrite. |
| `scripts/matching/mutate.py` | Random climbing with the same rewrites (one more than before: `volatile_slot`, see lessons). | Deeper, cheaper walks when the neighbourhood is exhausted. |
| `scripts/matching/callee_sigs.py` | Reads each function's return type from the code: a caller reads `$v0` or `$f0` after the call, or the callee writes it before `jr $ra`. `check` lists source declarations that disagree, `sweep` tries every single and paired return-type change on the near misses. | Callee declarations steer scheduling even when the result is dropped. |
| `scripts/matching/idioms.py` | `mine` counts source shapes over the matched sources, `suggest ADDRESS` lists the shapes the nearest matched functions (by shared callees) use that this source does not. | A starting point when a source is far from retail. |
| `scripts/matching/harvest.py` | Runs [m2c](https://github.com/matt-kempster/m2c) (GPL-3.0; clone it into `work/matching/tools/m2c`) on every function without a source, makes the draft compile (its macro header, `void *` as `s8 *`, callees in an `extern "C"` block), judges it, and tries a second variant with callee return types from `callee_sigs.py`. `--write` saves drafts that score 0, and with `--keep N` those within N words, as sources. | The first thing to run on functions nobody has tried: plain drafts already match for a share of them. Needs `.venv/bin/python`. |
| `scripts/matching/boundaries.py` | Finds functions the split cut in two (a branch lands inside another function) and records the groups in `config/matching/merges.tsv`; `functions.py` applies them. | After a re-split, or when a function's size looks too small. A piece with the wrong size can never match. |
| `scripts/matching/credit_audit.py` | Sorts the matched sources into tiers by the strictest trick they use (an empty `asm` barrier or register-pinned local, other inline asm, a volatile cast, an inline helper, plain C) and prints each tier's share. | To quote progress as "plain C" next to the byte-exact figure. |
| `scripts/matching/export_signatures.py` | Writes the real prototypes of matched functions with a plain (unmangled) name as the JSON `scripts/ghidra/ApplySignatures.java` reads. Applying it gave a mixed result (see lessons), so it is not applied by default. | To feed Ghidra what the matched C knows, after backing up the project. |
| `scripts/vu/vuasm.py` | Assembles the text of `vudis.py` and proves the microcode rebuilds byte for byte (`verify`; `make elf` runs it); `source` writes the verified text. | Editing or annotating VU1 programs without losing the byte gate. |
| `callee_sigs.py arity` | Calls that pass fewer arguments than the callee reads (the callee's registers read before written). Matched sources are the control: 6.2% of calls there, 10.4% in unmatched ones. | A weak lead for "missing instruction" diffs. |

`scripts/matching/classify_diffs.py` sorts the near misses by kind of difference (register, order, extra instructions, ...) and
`scripts/matching/record_round.py` re-judges every source and updates the registry after any of these tools writes a source.

## m2c and VU0 code

m2c does not read VU0 macro instructions. `scripts/matching/m2c_vu.patch` teaches it to keep each one (`lqc2`, `sqc2`, `qmtc2`, `qmfc2`,
`ctc2`, `cfc2`, `v*`) as an ordered opaque call, and `harvest.py` turns those calls into `asm volatile` statements (GPR operands become
`"r"` inputs, `qmfc2`/`cfc2` results become temporaries). Apply it once in your m2c checkout:
`cd work/matching/tools/m2c && git apply ../../../../scripts/matching/m2c_vu.patch`. Drafts cached before the patch live in `m2c-stack/`;
patched ones go to `m2c-vu/`. Result on the 951 unsourced functions: unsupported 531 to 392, drafts that compile 120 to 168, 25 within
20 words of retail (none before). Multimedia (MMI) and unaligned (`ldl`/`ldr`) instructions are still refused. The drafts are a starting
point: see matching.md ("VU0 functions") for how to bring them to a match, and keep register pins and barriers out.

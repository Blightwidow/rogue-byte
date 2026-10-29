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

`scripts/matching/classify_diffs.py` sorts the near misses by kind of difference (register, order, extra instructions, ...) and
`scripts/matching/record_round.py` re-judges every source and updates the registry after any of these tools writes a source.

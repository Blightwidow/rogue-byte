# Progress

The [progress page](https://blightwidow.github.io/rogue-byte/) shows how much of the game's code is rebuilt. Measuring it needs
your own executable, so the numbers are generated locally and committed; the `pages` workflow only deploys what is committed.

## What is counted

Bytes of code, per function (`scripts/gen_progress_report.py`, after `make elf`). Sony's SDK libraries (module `sdk`,
`0x2319e8`–`0x256c58`) are listed but left out of the game-code totals: they are not the game's own code.

| Status | Meaning |
| :--- | :--- |
| `c` | The function is compiled from `src/` in the image `make elf` rebuilds, and its bytes equal the retail ones |
| `matched` | Matched, but the image still uses assembly for it (`build/image/fallbacks.tsv` says why) |
| `asm` | Not matched yet |

"Named" counts functions with a recovered name, not `func_<address>`. Names and matching are independent: a function can be
named and unmatched, or matched and unnamed (`fun_<address>` in `src/`).

`make objdiff` adds a second measure: objdiff's own report over the whole executable, SDK included
(`site/data/objdiff-report.json`). The page prints both.

## Regenerating

```
make elf        # the image and the status of every function
make objdiff    # optional: the objdiff report
make progress   # site/data/*.json (incl. the Naming Desk's context.json), site/progress-map.svg, site/assets/og.png
```

Commit the changed files under `site/`. `site/data/history.json` gets one point per run for the curve.

| File | What |
| :--- | :--- |
| `site/data/report.json` | Every function: address, name, size, module, status |
| `site/data/summary.json` | Totals and per-module numbers, the file the page and the pull request comment read |
| `site/data/history.json` | One entry per run |
| `site/data/objdiff-report.json` | The objdiff report |
| `site/data/context.json` | For the [Naming Desk](https://blightwidow.github.io/rogue-byte/naming.html) (`site/naming.html`): per function its callers, callees, identifier-like strings it points at and where its name comes from (`scripts/gen_context.py`) |
| `site/progress-map.svg` | Treemap of the code: one block per module, one cell per function, area in bytes |
| `site/assets/` | Logo, favicon and the social preview image (`og.png`) |

The files list names, addresses, sizes and statuses only, never game bytes.

## In CI

`progress.yml` validates `site/data/summary.json` and, on a pull request, `progress-comment.yml` posts how the change moves
the numbers against `main`. Neither builds the game. `pages.yml` deploys `site/` when it changes.

To look at the page locally: `python3 -m http.server -d site`.

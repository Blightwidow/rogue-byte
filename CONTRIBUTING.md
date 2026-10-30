# Contributing

Rogue Byte is a byte-matching decompilation of Sly 2: Band of Thieves (PS2, USA), built from your own copy of the game.
Matching a function, recovering a name, fixing a tool and improving the docs all help.

## Loop

1. `./setup.sh --sly2 /path/to/SCUS_973.16 [--sly1 /path/to/SCUS_971.98]` checks the executables, installs the tools; `make elf` rebuilds the executable image and checks it byte for byte.
2. Follow [docs/build/name-recovery.md](docs/build/name-recovery.md) to build the Ghidra project and recovered data.
3. Change a script or data file. Run every tool from the repository root.
4. `make check` before committing (ruff, compile, shellcheck, links, regression tests). After touching `src/` run `make elf`, then `make unit UNIT=<module>`: every matched function must still link from C. Then `make objdiff` and `make progress` and commit the regenerated `site/` files: ByteMatch reads `site/data/objdiff-report.json`, which CI cannot rebuild. Commit messages: [docs/contributing/commit-messages.md](docs/contributing/commit-messages.md); the added code follows [docs/contributing/code-cleanup.md](docs/contributing/code-cleanup.md).
5. Optional: `pre-commit install --hook-type pre-commit --hook-type commit-msg` (or `prek install`) with `.pre-commit-config.yaml`.
6. Judge and fix a function: [docs/contributing/matching.md](docs/contributing/matching.md) (what `score` counts, the usual fixes).
7. Finish a draft: `nonmatching/` holds the best compiling source of every unmatched function ([nonmatching/README.md](nonmatching/README.md)).
8. Name a function: the [Naming Desk](https://blightwidow.github.io/rogue-byte/naming.html) lists the ones that need a name, with callers and strings, and opens a prefilled issue. Pick the next function to match with `python3 scripts/list_functions.py --status asm --sort size`.

## Rules

- **No game data.** No executables, disc images, Ghidra projects, raw decompiler output or disassembly. `.gitignore`
  keeps them local. Matched functions go in `src/` (`python3 scripts/matching/export_src.py` publishes them). Recovered names, addresses and types are fine.
- **No ProjectCane code.** It has no license; read it for reference only, never copy it. Names from the CC0 Sly 1
  decomp are free to use. See [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md).
- New source files start with `SPDX-License-Identifier: GPL-3.0-or-later`.
- Every recovered name keeps its source visible. Measure a new heuristic against a control before trusting it.
- Tips: [docs/contributing/decompilation-tips.md](docs/contributing/decompilation-tips.md).

## Working with an AI assistant

Welcome; the rules above apply the same way. You are responsible for what you contribute, however it was written, and you have
to be able to explain it. An assistant also follows [AGENTS.md](AGENTS.md): it reports what it checked as it is (failures
included), adds no attribution trailers to commits, runs `make` with `PROGRESS=0` (the progress lines are for a person watching a terminal), and pushes, opens pull requests or publishes only when asked.

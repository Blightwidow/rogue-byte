# Contributing

sly2-decomp is a byte-matching decompilation of Sly 2: Band of Thieves (PS2, USA), built from your own copy of the game.
The US executable is what functions are matched against; the PAL one (optional) is used to check the result.
Matching a function, recovering a name, fixing a tool and improving the docs all help.

## Loop

1. `./setup.sh --sly2 /path/to/SCUS_973.16 [--sly1 /path/to/SCUS_971.98]` checks the executables, installs the tools; `make elf` rebuilds the executable image and checks it byte for byte.
2. Follow [docs/build/name-recovery.md](docs/build/name-recovery.md) to build the Ghidra project and recovered data.
3. Change a script or data file. Run every tool from the repository root.
4. `make check` before committing (ruff, compile, shellcheck, links, regression tests). After touching `src/` run `make elf`, then `make unit UNIT=<module>`: every matched function must still link from C. Then `make objdiff` and `make readme` and commit `progress/` and the README table: ByteMatch reads `progress/us/report.json`, which CI cannot rebuild. Commit messages: [docs/contributing/commit-messages.md](docs/contributing/commit-messages.md); the added code follows [docs/contributing/code-cleanup.md](docs/contributing/code-cleanup.md).
5. Optional, PAL: with `work/elf/SCES_525.29` (`scripts/disc_extract.py`), `make pal` checks the matched functions against PAL; commit `config/eu/` and `progress/eu/report.json` with the change. Without the executable `make check` still verifies that the committed PAL data is current (`pal-check`).
6. Optional: `pre-commit install --hook-type pre-commit --hook-type commit-msg` (or `prek install`) with `.pre-commit-config.yaml`.
7. Judge and fix a function: [docs/contributing/matching.md](docs/contributing/matching.md) (what `score` counts, the usual fixes).
8. Finish a draft: `nonmatching/` holds the best compiling source of every unmatched function ([nonmatching/README.md](nonmatching/README.md)).
9. Pick the next function to match with `python3 scripts/list_functions.py --status asm --sort size` (after `make report`).

## Rules

- **No game data.** No executables, disc images, Ghidra projects, raw decompiler output or disassembly. `.gitignore`
  keeps them local. Matched functions go in `src/` (`python3 scripts/matching/export_src.py` publishes them). Recovered names, addresses and types are fine.
- **Derive the code yourself.** Work from the retail executable of your own disc and public hardware documentation. No code from
  other decompilations or ports of this game and no third-party code, except [sly1-decomp](https://github.com/OpenThievius/sly1-decomp)
  (same maintainers, AGPL-3.0) as a draft that must still match, recorded as `source:sly1-decomp` in the commit body; names, symbol maps and notes only from openly licensed projects
  listed in [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md). Nothing from any prototype build, and never Sony's SDK source,
  samples or headers, or leaked or NDA material ([AGENTS.md](AGENTS.md)).
- **Plain C++.** No inline assembly in functions (one shared `Sqrt` helper aside), no register pins, no tricks whose only purpose is
  to steer the compiler. A function that needs one stays in `nonmatching/`.
- **Preservation first.** Use the shared types of `include/` over local padded copies, and of two wordings that both match land the
  typed one ([docs/PRESERVATION_AND_PORT.md](docs/PRESERVATION_AND_PORT.md)). C that behaves like a function without reproducing its
  bytes is not a match and does not go in `src/`.
- New source files start with `SPDX-License-Identifier: GPL-3.0-or-later`; by contributing you license your work under it.
- **Keep docs short and plain.** Plain English, short sentences, lists and tables where they help. When you shorten a doc, keep every
  number, path, command, decision and link.
- Every recovered name keeps its source visible. Measure a new heuristic against a control before trusting it.
- Tips: [docs/contributing/decompilation-tips.md](docs/contributing/decompilation-tips.md).
- Names for files, functions and modules: [docs/contributing/naming.md](docs/contributing/naming.md).

## Commits

[Conventional Commits](https://www.conventionalcommits.org/), as in sly1-decomp and OpenRAC: `type(scope): short summary`, then a body
wrapped at 72 columns saying what changed, why and what you verified. One logical change per commit. No `Co-authored-by:` or other
attribution trailers for AI tools. Full rules: [docs/contributing/commit-messages.md](docs/contributing/commit-messages.md).

## Pull requests

- One topic per pull request, titled like a commit summary.
- Say what you verified and how: the commands and their results.
- Never include generated or disc-derived files.
- Reserve what you will match in the pinned *Contributor coordination* issue first (at most 500 unfinished functions per contributor,
  [AGENTS.md](AGENTS.md#coordinating-work)).

## Checks

CI runs on every pull request and needs no game data and no compiler. Run the same locally before you push:

```sh
python3 -m unittest discover -s tests      # unit tests
python3 tests/check_repository.py          # no game data or proprietary material, licence headers
python3 -m compileall -q scripts tests     # the tools compile
make check                                 # all of the above, plus ruff, shellcheck, links, PAL data, cleanup rules, commit messages
```

CI is two workflows, as in sly1-decomp: `checks` (unit tests, repository check, compile) and `progress` (validates the objdiff reports
and uploads them for ByteMatch on a push to `main`). Builds need your own disc and the proprietary toolchain, so they run on
contributors' machines. Two rules are checked locally only: commit messages ([docs/contributing/commit-messages.md](docs/contributing/commit-messages.md),
the `commit-msg` hook of `.pre-commit-config.yaml`, or `make commits`) and the code you add to `src/`
([docs/contributing/code-cleanup.md](docs/contributing/code-cleanup.md), `make cleanup`). Install the hooks:
`pre-commit install --hook-type pre-commit --hook-type commit-msg`.

## Working with other people

Nobody finishes a decompilation alone. Disagree kindly, argue about the code and not the person, share what you find, and be patient
with people's work: a pull request is someone's evening.

## Working with an AI assistant

Welcome; the rules above apply the same way. You are responsible for what you contribute, however it was written, and you have
to be able to explain it. An assistant also follows [AGENTS.md](AGENTS.md): it reports what it checked as it is (failures
included), adds no attribution trailers to commits, matches by model tier (Haiku, Sonnet, Opus), runs `make` with `PROGRESS=0` (the progress lines are for a person watching a terminal), and pushes, opens pull requests or publishes only when asked.

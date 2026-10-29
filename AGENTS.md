# Instructions for agents

For AI agents working in this repository (any model or tool). Read this file, then README.md, CONTRIBUTING.md,
docs/contributing/matching.md and docs/build/building.md. People follow the same rules.

## What this repository is

Rogue Byte is a byte-matching decompilation of Sly 2: Band of Thieves (PS2, USA, `SCUS_973.16`). Matched C++ goes in `src/`,
best attempts for the rest in `nonmatching/`, recovered names and types in `config/`, and the tools in `scripts/`. A function
counts as matched when `scripts/matching/try.py` scores it 0 **and** `make elf` still reproduces the retail image byte for byte.

## Layout

| Path | Holds |
| :--- | :--- |
| `src/` | matched C++, one unit per module, published by `scripts/matching/export_src.py` |
| `nonmatching/` | best compiling source of every unmatched function, with `MANIFEST.tsv` scores |
| `config/` | splat config, symbol addresses, compiler and assembler lists (`config/us/gnu_as.txt`, `ps2eeas_loop5.txt`, `sony_gcc29.txt`) |
| `include/` | headers for the matched code |
| `scripts/` | tools: `matching/` (try, permute, scorer), `build/`, `names/`, `ghidra/` |
| `docs/` | `build/`, `contributing/`, `game/`; start with docs/contributing/matching.md |
| `work/`, `data/`, game-derived files | your executables, Ghidra projects, dumps: never committed |

## Matching rules

- **A match is retail's bytes in a build that equals retail.** Not a compiled object alone, not a masked comparison, not a
  model's say-so. Report the command you ran and what it printed, failures included.
- **Plain C++.** Inline assembly only for what C cannot express (VU0 macro code and MMI: the matched sources in `src/` use `asm` blocks with
  constraints for these; unaligned 8-byte accesses are plain struct copies, see docs/contributing/matching.md), no register pins.
- **The test for a trick.** A construct is allowed when it could plausibly be in the original source and changes no behaviour: casts, types,
  statement order, and a dead local that retail's frame shows (a stack area with no stores). It is not allowed when its only purpose is to steer
  the compiler: `volatile` on ordinary data, an empty `asm` with clobbers, register pins, or a variable that exists only to move a register.
  A function that matches only with such a construct stays in `nonmatching/` at the score it reaches without it.
- **One flag set per source file** (and one assembler per function listed in `config/us/`), never ad hoc per attempt.
- Compiler and assembler: see docs/build/compiler-identification.md and docs/build/assembler.md. SDK-range functions list their
  address in `config/us/sony_gcc29.txt`.
- Keep every recovered name's source visible (`source:...`); measure a new heuristic against a control before trusting it.

## Which model does what

A starting point, sorted by function size (`python3 scripts/list_functions.py --status asm --sort size`):

- **Small** (up to about 400 bytes): the smallest model, many workers at once.
- **Medium** (about 400 to 1,000 bytes), and what small workers gave up on: a mid-size model.
- **Large** (over 1,000 bytes), near misses in `nonmatching/`, and leading (landing, full build, reports): the largest model.

A worker stops at its bound (about ten compiles per function) and hands its best attempt up a tier. Workers write in their own
scratch folder and never edit `src/`; only the lead lands code, after `make elf` and `make unit UNIT=<module>` pass. No two
workers share a function, and contiguous functions go to one worker. Every worker brief states these rules and the bound.
Details: docs/contributing/matching.md ("Teams of workers").

## Rules

- **No game data.** No executables, disc images, Ghidra projects, raw decompiler output, disassembly or other game-derived
  files, in a commit or on a branch. `.gitignore` and `.git/info/exclude` keep them local; never weaken them to get a file in.
- **No ProjectCane code** (no license: reference only). Names from the CC0 Sly 1 decomp are free to use
  (THIRD_PARTY_NOTICES.md). Code or text taken from another project is credited there.
- **License.** GPL-3.0-or-later. New source files start with `SPDX-License-Identifier: GPL-3.0-or-later`.
- **English** in everything that lands here.
- **Never delete what you did not create**, and leave other people's uncommitted work alone.
- Stage files by name (never `git add .` or `-A`); never skip hooks (`--no-verify`) without the maintainer's say-so.
- Format, lint and compile before committing: `make check`. Don't commit what fails.

## Commits

- Format: docs/contributing/commit-messages.md (`<type>: <summary>`).
- **No attribution lines**: no `Co-authored-by:` or other trailers for AI tools.
- One logical change per commit; new numbers (matched count, names recovered) in the body.
- Commit incrementally; push and open pull requests only when asked.

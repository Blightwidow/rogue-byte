# How matching work runs

The whole procedure, for people and AI agents alike. [AGENTS.md](../AGENTS.md) has the rules; this page has the steps, in the shape of
sly1-decomp's workflow with this repository's tools. Fixes that usually move the bytes: [contributing/matching.md](contributing/matching.md).

## The parts

| Tool | What it does |
| :--- | :--- |
| `python3 scripts/list_functions.py --status asm --sort size` | The functions still to match, with size and module (needs `make report`); permanent blockers are left out (`--blockers` shows them) |
| `python3 scripts/matching/try.py ADDRESS FILE.cpp` | Compiles one source with its flags and compares one function with retail: `score 0`, or a side-by-side diff |
| `make elf` | The full build: every matched function of `src/` linked in, then `PASS: reconstructed image matches retail` (the gate) |
| `make unit UNIT=<module>` | Do the matched functions of a module still link from C? |
| `make pal` | The matched C checked at its PAL counterpart; writes `config/eu/` and `progress/eu/report.json` |
| `make objdiff`, `make readme` | The ByteMatch report `progress/us/report.json` and the README table |
| `python3 scripts/matching/permute.py ADDRESS FILE.cpp --write` | Tries other orders of independent statements, keeps the best score |
| `make check` | The CI checks locally, plus ruff, shellcheck and the link check |

Run everything from the repository root, and `make` with `PROGRESS=0`.

## 1. Coordinate

Before you start, and before you hand work to agents: read the pinned *Contributor coordination* issue, make sure you have exactly one
comment, and reserve what you will work on ([AGENTS.md](../AGENTS.md#coordinating-work)). At most 500 unfinished functions per
contributor, all agents included.

## 2. Pick

Sort by size and match by tier (Haiku up to 400 bytes, Sonnet 401 to 1,000 and what Haiku gave up on, Opus above that and near misses).
The functions that need VU0, MMI, a lane move or COP0 are permanent blockers (`config/us/blockers.tsv`): the list and the queues already leave
them out, and they stay assembly ([build/vu0-mmi.md](build/vu0-mmi.md)). A worker stops at its bound (about ten compiles) and hands its best attempt up a tier.

## 3. Write C++ until the score is 0

The game is C++ built by SN Systems' GCC 2.95.3 and assembled by SN's `ps2eeas` ([TOOLCHAIN.md](TOOLCHAIN.md)). For each function:

1. Read its disassembly (`build/splat/asm/`, git-ignored). Work out the arguments (`$a0`-`$a3`, then `$t0`-`$t3`; floats in `$f12`...),
   the return value (`$v0`, `$f0`), the fields it reads (`lw $v0, 0x708($a0)` is a 32-bit field at offset 0x708), the calls it makes
   and the data it uses.
2. Write a C++ file with the declarations it needs and the function, named as in the disassembly. Data it refers to is an `extern` at
   retail's address; a function it calls is declared with the arguments it is given.
3. `python3 scripts/matching/try.py ADDRESS FILE.cpp` until it prints `score 0`. Read the diff: the lines that differ are the
   instructions to fix. Then check the usual fixes in [contributing/matching.md](contributing/matching.md).
4. Keep a near miss in `nonmatching/` with what still differs and move on.

## 4. Land

Only the lead lands code (workers never edit `src/`):

1. `python3 scripts/matching/record.py` registers the sources that score 0 and scans them for what AGENTS.md bans.
2. `make src` publishes them to `src/`, then `make elf` must print `PASS`, and `make unit UNIT=<module>` must say every function links.
3. `make pal`, `make objdiff` and `make readme`, and commit `src/`, `config/eu/`, `progress/` and the README together
   (`make land` runs the whole chain). The commit body carries the new numbers and the commands that printed `PASS`.

A function that breaks the gate goes back to `nonmatching/`: a match is the full build, not a model's claim.

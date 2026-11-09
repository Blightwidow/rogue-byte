# Instructions for agents

This file is for AI agents (Claude, Codex or others) working in this repository. Read it completely before changing anything,
then README.md, CONTRIBUTING.md, docs/contributing/matching.md and docs/build/building.md. People follow the same rules.
The rules follow the sister project [sly1-decomp](https://github.com/OpenThievius/sly1-decomp) (same maintainers' conventions):
keep it that way.

## What this repository is

sly2-decomp is a byte-matching decompilation of Sly 2: Band of Thieves (PS2, USA, `SCUS_973.16`). Matched C++ goes in `src/`,
best attempts for the rest in `nonmatching/`, recovered names and types in `config/`, and the tools in `scripts/`. A function
counts as matched when `scripts/matching/try.py` scores it 0 **and** `make elf` still reproduces the retail image byte for byte.
Matching is done against the US executable only. PAL (`SCES_525.29`) is checked afterwards: `make pal` (end of `make land`) says whether the same C
reproduces the PAL code; `config/eu/` holds the results and `make check` fails when they are stale.

## Preservation first, a port second

Preservation is the absolute priority; a later PC port is the second user of the work (docs/PRESERVATION_AND_PORT.md, docs/ROADMAP.md
"Next"). What helps a port is **additive**: headers, typedefs, asserts, metadata, notes. It never changes matched bytes or what
counts as matched.

- **Shared types over local ones.** The fixed-width typedefs live in `include/types.h` only (`make cleanup` fails on a local copy in
  `src/`). Use a type from `include/` when it exists (`lo.h` for `BASIC` and `LO`, `so.h` for `SO`, since 2026-11-09; call their virtuals, not `vt->fn(obj + vt->delta)`); when a function needs a field it lacks, add the field
  there (re-prove its users) rather than declaring a padded local copy. A local struct stays allowed while no shared one exists.
- **Tie-break:** of two wordings that both score 0 and both follow the rules, land the typed one: a member over a cast offset
  (`*(int *)(base + 0x1404)`), a virtual call over a hand-written vtable call (`vt->fn(obj + vt->delta, ...)`), a shared type over a
  local one, a fixed-width typedef over a bare `long`. `make cleanup` warns on these in added code; a warning does not fail it.
- **Blockers get one line of semantics.** A worker that meets a permanent blocker says what it computes (`SKIP wall <semantics>`); the
  lead records it in `config/us/blocker_notes.tsv`, noting PS2 FPU behaviour (no denormals, infinities or NaNs) where results depend on it.
- **No "equivalent C".** C that behaves like a function but does not reproduce its bytes is not a match: never in `src/`, never in
  the reports. If anyone writes it for a port, it lives outside `src/` (the port's repository or `reference/`), labelled as such.

## Layout

| Path | Holds |
| :--- | :--- |
| `src/` | matched C++, one unit per module, published by `scripts/matching/export_src.py`; whole source files (`config/us/whole_files.tsv`) hold their functions in place |
| `nonmatching/` | best compiling source of every unmatched function, with `MANIFEST.tsv` scores |
| `config/` | splat config, symbol addresses, the SDK-range compiler list (`config/us/sony_gcc29.txt`) and `vu0_regs.txt`; `config/eu/` PAL pairing and status |
| `include/` | headers for the matched code |
| `scripts/` | tools: `matching/` (try, permute, scorer), `build/`, `names/`, `ghidra/` |
| `docs/` | `build/`, `contributing/`, `game/`; start with docs/contributing/matching.md |
| `work/`, `data/`, game-derived files | your executables, Ghidra projects, dumps: never committed |

## Matching rules (from the first matched function on)

- **A match is retail's bytes in a build that equals retail.** Not a compiled object on its own, not a masked comparison, not a
  model's claim. Report exactly what you ran and what it printed, failures included.
- **Plain C++.** No inline assembly in functions, no register pins, no artificial barriers. The one exception is the square root
  (`sqrt.s`): retail's bare instruction behaves as an inline-assembly helper that no C form reproduces; a function computes a bare
  square root through one shared `Sqrt` helper (`asm volatile("sqrt.s %0, %1" : "=&f"(r) : "f"(x))`, the early-clobber measured on every
  user: docs/contributing/exceptions.md) and nothing else writes inline assembly. A function that needs VU0 macro code, MMI,
  a lane move to an FP register or COP0 stays in `nonmatching/` at the score it reaches without it. No matched source holds inline asm (the 236 that did went back to unmatched on 2026-11-04); `scripts/matching/record.py` scans every
  new match for it.
  `volatile` is one only where it stops the compiler. It is allowed where it is what the original had: a hardware register at a
  fixed address (`*(volatile u32*)0x10002010`) or through a pointer to a register block (a DMA channel's), and data shared with
  hardware, an interrupt handler or another thread (a library's semaphore ids and state flags, a field an interrupt handler sets),
  where retail's code reads and writes it as volatile. A fixed address from 0x10000000 up needs nothing more; any other `volatile`
  carries `// volatile-ok: <reason>` on its line, naming the register block or the handler that writes it (scripts/matching/record.py).
  `do { } while (0)` is one too: in game code it is allowed only as the form C macros take (`#define NAME(...) do { ... } while (0)`)
  that the original plausibly had and retail's code needs. Never a wrapper written only to move instructions.
- **Permanent blockers.** A function with a VU0, MMI or COP0 instruction, hand-written assembly, or a remnant (a chunk nothing reaches that never
  transfers control, so not a function) (`config/us/blockers.tsv`, from `make blockers`), stays
  original assembly: it is left out of the work queues, counts as finished in the reports apart from the exact C, and is never matched with asm
  (docs/build/vu0-mmi.md).
- **An unused local only as a type the original plausibly declared.** GCC 2.95 gives an unused struct local a stack slot, so retail's
  frames show where the original declared one. A padding array (`s32 scratch[4];`), an invented type or a field that exists only to
  size the frame is not allowed.
- **Also not allowed**, because their only purpose is to steer the compiler: a callee declared with a return type or arguments it
  does not have, a variable that exists only to move a register (a typed local bound to a value the code reads and then uses is ordinary code), a local that only holds a global's address so a constant does not
  fold, and source that defines game data without meeting docs/contributing/exceptions.md ("Game data defined in source": a global is defined in C only where its initial value reproduces retail's bytes at its address; the rest stays an `extern` at retail's address). The rulings are in
  docs/contributing/matching.md ("Rulings"); docs/contributing/exceptions.md lists what is allowed and why.
- **One flag set per source file** and one assembler for all game code, never per function or ad hoc per attempt: SN's `ps2eeas` 1.9.25.758 with its one short-loop constant
  changed from 6 to 5 (`tools/ps2eeas/Ps2EeAs-loop5.exe`, made by `setup.sh` from the pinned download, never committed; retail pads every short
  loop to five and no assembler release we could run does, docs/build/assembler.md "Short loops"). The SDK range builds with Sony's own
  toolchain (`config/us/sony_gcc29.txt`).
- Compiler and assembler: see docs/build/compiler-identification.md and docs/build/assembler.md (measure with
  `scripts/matching/assembler_probe.py` before changing the assembler). SDK-range functions list their
  address in `config/us/sony_gcc29.txt`.
- **Our own names and types.** Retail is stripped: every function, type, field and file name is chosen by us from what retail's
  code does. Keep every recovered name's source visible (`source:...`); measure a new heuristic against a control before trusting it.
- If you get close but not exact, keep the attempt in `nonmatching/` with what still differs, and move on. Stop on a function after
  about ten compiles without getting closer.

## Coordinating work

Matching work is coordinated in a pinned *Contributor coordination* issue, after sly1-decomp and rac2-decomp (OpenRAC). It is a
noticeboard, not a task queue or a record of finished work: `main` is authoritative.

- **One comment per contributor.** Before you match anything, or hand work to agents, make sure your contributor has exactly one
  comment there; create it if not. Edit it in place; never edit anyone else's.
- **List only your own reservations**, scope first: a module (`src/vec/`) or a few, then individual functions where a scope would be
  too big. Don't copy or describe other people's.
- **At most 500 unfinished functions per contributor**, across every branch, worktree and agent. Functions on `main` don't count;
  local matches and open pull requests do.
- **Read the others first** and avoid overlap. Someone else's scope is theirs: ask in a comment.
- **A reservation ends** when its functions reach `main` or you release them in your comment.
- **Agents** check their contributor's comment and remaining allowance before starting or assigning work, never expand a reservation
  past 500, and never touch another comment.

## Which model does what

Sort by size with `python3 scripts/list_functions.py --status asm --sort size`:

- **Haiku**: up to 400 bytes, many workers at once.
- **Sonnet**: 401 to 1,000 bytes, and what Haiku gave up on. Near misses are Sonnet's: one function per worker, with the earlier
  attempt and its diff as the start.
- **Opus**: over 1,000 bytes, complex ones, near misses in `nonmatching/`, and leading (landing, full build, reports).

A worker stops at its bound (about ten compiles per function) and hands its best attempt up a tier. Workers write in their own
scratch folder and never edit `src/`; only the lead lands code, after `make elf` and `make unit UNIT=<module>` pass. No two workers
share a function, and contiguous functions go to one worker. Every worker brief states these rules and the bound.
Details: docs/contributing/matching.md ("Teams of workers").

## Rules

- **Derive the code ourselves; names and notes only from open licences.** Work from the retail executable of your own disc and public
  hardware documentation. Matched C is ours: no code from other decompilations or ports of this game, and no third-party code. Names,
  symbol maps, types, field offsets, splits and notes from another project are allowed only when its licence permits it (CC0, MIT,
  CC BY-SA, GPL-compatible) and it is listed in THIRD_PARTY_NOTICES.md with its terms and what is used, before the material lands.
  Keep every name's source visible (`source:...`) and measure it against retail: a borrowed name is a hypothesis. Never Sony's SDK
  source, samples or headers, or leaked or NDA material, not even as a reference. A project with no licence is read-only: facts
  and ideas only, nothing copied.
- **Nothing from the prototype.** No code, data, symbol names, signatures, types, field names or file lists from any prototype
  build, and no tool that extracts them. Looking at one to understand a function is allowed only if what you then write is entirely
  your own, reasoned from retail's bytes. When in doubt, treat it as copied and leave it out.
- **No proprietary material ever touches the repository**: disc images, executables, Ghidra projects, raw decompiler output,
  disassembly, dumps, build output, the compiler or any SDK binary, SDK headers, links to toolchains. Not in a commit, not on a
  branch, not in a pull request. `.gitignore` and `.git/info/exclude` keep them local; never weaken them to get a file in.
- **License.** GPL-3.0-or-later. New source files start with `SPDX-License-Identifier: GPL-3.0-or-later`.
- **English** in everything that lands here.
- **Never delete what you did not create**, and leave other people's uncommitted work alone.
- **The branch is `main`.** Never rewrite its history and never force-push it.
- Stage files by name (never `git add .` or `-A`); never skip hooks (`--no-verify`) without the maintainer's say-so.
- Format, lint and compile before committing: `make check`. Don't commit what fails.
- **Run `make` with `PROGRESS=0`** (`make rules PROGRESS=0`, `make search PROGRESS=0`): `make` turns progress lines on for a person
  watching a terminal, and they only fill an agent's context. A tool you run directly prints no progress lines.
- After matching or removing a matched function: `make pal` when `work/elf/SCES_525.29` exists (`make land` does it), and commit
  `config/eu/` and `progress/eu/report.json`: `make check` (`pal-check`) fails on a missing row or a stale PAL report. A
  function that no longer reproduces PAL is a finding, not a blocker: say so in the commit body.
- After matching work, before committing: `make elf` (byte gate), `make objdiff` (ByteMatch reads `progress/us/report.json`;
  CI only validates and uploads it, cannot rebuild it) and `make readme`; commit `progress/` and the README table with the work.

## Commits

As in sly1-decomp and OpenRAC (docs/contributing/commit-messages.md):

- Conventional Commits with a scope: `feat(us): ...`, `fix(tools): ...`, `docs: ...`, `build: ...`, `chore: ...`. The summary says
  what the change does or what is now true, in lower case, without a full stop.
- A prose body wrapped at 72 columns: what changed, why, and what you verified (the commands and what they printed). New numbers
  (matched count, names recovered) go in the body.
- One logical change per commit, each leaving the tools and checks working.
- No `Co-authored-by:` trailers or other attribution lines for AI tools.
- Commit incrementally; push and open pull requests only when asked.

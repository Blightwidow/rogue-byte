# Roadmap

What is done and what comes next. Live numbers: [bytematch.dev](https://bytematch.dev/Blightwidow/rogue-byte) and the README table.

## Done

- The executable splits and rebuilds byte for byte from assembly plus the matched C (`make elf`).
- The assembler is SN's `ps2eeas` with its short-loop constant changed from 6 to 5, one for all game code (2026-11-05, [build/assembler.md](build/assembler.md) "Short loops"); no inline asm in matched code, no per-function lists.
- Matched C: 5,040 functions in `src/`; every other function is built from its original assembly, and the best compiling draft of
  each is in `nonmatching/`.
- VU0, MMI, COP0 and hand-written functions are flagged as permanent blockers (`config/us/blockers.tsv`) and counted as finished apart from the exact C, as in sly1 ([build/vu0-mmi.md](build/vu0-mmi.md)).
- PAL is checked against the same C (`make pal`); US is the reference.
- CI is sly1-decomp's: `checks` (unit tests, repository check for game data and licence headers, byte-compile) and `progress`
  (objdiff reports for ByteMatch). Commit messages and the cleanup rules are checked locally (`make commits`, `make cleanup`).

## Next

1. Keep matching by tier (see [AGENT_WORKFLOW.md](AGENT_WORKFLOW.md)): small functions first, then near misses.
2. Remove the third-party names and prototype data that landed before "derive everything ourselves"
   ([THIRD_PARTY_NOTICES.md](../THIRD_PARTY_NOTICES.md), "Legacy"), or re-derive them from retail.
3. File boundaries found in retail, as sly1 does: the constructor list gives each file's end, shared static data and
   `.rodata` grouping give its start, and a file is proved by building it whole, with its unmatched functions
   included from assembly (`INCLUDE_ASM`). Replaces fixed windows of `src/` with real files. Wanted (Theo, 2026-11-06).
4. Data from C, after code reaches 80 to 90%: `.rodata` literals and `switch` jump tables first, then globals defined at
   retail's address, counted as matched data like sly1's `c_data.tsv`. Needs a ruling on AGENTS.md's "source that defines
   game data read out of retail" for globals with initial values. Depends on 3 for per-file data. Today 0.72% of data.

5. Reclassify the permanent blockers that are compiled C, as sly1-decomp did on 2026-11-07: shared inline-assembly helpers for
   VU0, MMI and `max.s`/`min.s`, an **inline** kind counted as to-do, not finished. We will need to do this to keep the report
   honest and match about 106 to 258 of the 853 blockers. First a compile pilot on about 10 functions, then the rule change in
   AGENTS.md; the headline falls by about 1.7 to 4.2 points. See [build/inline-asm-helpers.md](build/inline-asm-helpers.md).

## Not goals

The renderer, the audio engine, a platform layer and the port itself live in other projects.

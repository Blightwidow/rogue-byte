# Roadmap

What is done and what comes next. Live numbers: [bytematch.dev](https://bytematch.dev/Blightwidow/rogue-byte) and the README table.

## Done

- The executable splits and rebuilds byte for byte from assembly plus the matched C (`make elf`).
- The assembler is Sony's `bin/ee-as.exe`, one for every function (2026-11-04); no inline asm in matched code, no patched binaries.
- Matched C: 4,912 functions in `src/`; every other function is built from its original assembly, and the best compiling draft of
  each is in `nonmatching/`.
- VU0, MMI, COP0 and hand-written functions are flagged as permanent blockers (`config/us/blockers.tsv`) and counted as finished apart from the exact C, as in sly1 ([build/vu0-mmi.md](build/vu0-mmi.md)).
- PAL is checked against the same C (`make pal`); US is the reference.
- CI is sly1-decomp's: `checks` (unit tests, repository check for game data and licence headers, byte-compile) and `progress`
  (objdiff reports for ByteMatch). Commit messages and the cleanup rules are checked locally (`make commits`, `make cleanup`).

## Next

1. Keep matching by tier (see [AGENT_WORKFLOW.md](AGENT_WORKFLOW.md)): small functions first, then near misses.
2. Remove the third-party names and prototype data that landed before "derive everything ourselves"
   ([THIRD_PARTY_NOTICES.md](../THIRD_PARTY_NOTICES.md), "Legacy"), or re-derive them from retail.
3. Count matched data (globals defined in C at retail's bytes), as sly1's `c_data.tsv` does.
4. Decide whether to move to windowed `src/` files with whole-file assembly includes, as sly1 does.

## Not goals

The renderer, the audio engine, a platform layer and the port itself live in other projects.

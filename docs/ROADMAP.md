# Roadmap

What is done and what comes next. Live numbers: [bytematch.dev](https://bytematch.dev/Blightwidow/rogue-byte) and the README table.

## Done

- The executable splits and rebuilds byte for byte from assembly plus the matched C (`make elf`).
- The assembler is SN's `ps2eeas` with its short-loop constant changed from 6 to 5, one for all game code (2026-11-05, [build/assembler.md](build/assembler.md) "Short loops"); no inline asm in matched code apart from the shared `Sqrt` helper. The only per-function compile lists are documented exceptions ([contributing/exceptions.md](contributing/exceptions.md)): the SDK range's Sony compiler (`config/us/sony_gcc29.txt`) and `-fmove-all-movables` (`config/us/move_movables.txt`, 2026-11-08); steering helpers carry `// steer-ok:`.
- Matched C: 6,192 functions in `src/` (2026-11-08); every other function is built from its original assembly, and the best compiling draft of
  each is in `nonmatching/`.
- NTSC-U code reached 80% on 2026-11-08 (80.10%, blockers counted as finished; PAL 78.64%). Outside the SDK range it is 85.8% (53.1% exact C); the SDK range
  (150 KB, libm and libc giants) is 33%.
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
4. Data from C (code passed 80% on 2026-11-08, so this is open), by sly1-decomp's rule, ruled 2026-11-08 ([contributing/exceptions.md](contributing/exceptions.md) "Game data
   defined in source"): a global is defined in C only where its initial value reproduces retail's bytes at its address, one file defines it, every other
   file declares it `extern`; the defined bytes count as matched data. Today 0.83% of data (8,375 of 1,011,732 bytes: only a function's own literals and
   jump tables, `data/rodata-c`). What can ever be C: `data/rodata` 296 KB and `data/data` 199 KB (49% of data); `data/irx` 474 KB (IOP modules) and
   `data/vutext` 34 KB (VU microcode) are not game C. A pilot on `HitFx_GIntensity` (2026-11-08) found the build side missing, not the ruling: the
   two constants it reads (`g_2bdce0`, `g_2bdcf0[3]`) are in `.data`, not `.rodata`; a `const` scalar is folded into `lui`/`mtc1` (score 24) and a
   plain definition lays out 8 bytes short of retail's gap; `link_image.py` places only an object's own `.rodata`, and `derive_rodata_base` assumes
   section-symbol relocations. Per-global sweeps are small (18 `.rodata` externs, 178 bytes behind matched functions; 674 `.data` externs, 103 KB, 129 of
   them over 1 KB). The real work is whole data regions per file (labels to the next label, typed from what retail's code does), `.data` and `.bss`
   sections placed at retail's address (`-fdata-sections`), and a list of the defined globals feeding the report, as sly1-decomp does. Depends on 3.

5. Reclassify the permanent blockers that are compiled C, as sly1-decomp did on 2026-11-07: shared inline-assembly helpers for
   VU0, MMI and `max.s`/`min.s`, an **inline** kind counted as to-do, not finished. We will need to do this to keep the report
   honest and match about 106 to 258 of the 853 blockers. First a compile pilot on about 10 functions, then the rule change in
   AGENTS.md; the headline falls by about 1.7 to 4.2 points. See [build/inline-asm-helpers.md](build/inline-asm-helpers.md).

## Not goals

The renderer, the audio engine, a platform layer and the port itself live in other projects.

# Roadmap

What is done and what comes next. Live numbers: [bytematch.dev](https://bytematch.dev/Blightwidow/sly2-decomp) and the README table.

## Done

- The executable splits and rebuilds byte for byte from assembly plus the matched C (`make elf`).
- The assembler is SN's `ps2eeas` with its short-loop constant changed from 6 to 5, one for all game code (2026-11-05, [build/assembler.md](build/assembler.md) "Short loops"); no inline asm in matched code apart from the shared `Sqrt` helper. The only per-function compile lists are documented exceptions ([contributing/exceptions.md](contributing/exceptions.md)): the SDK range's Sony compiler (`config/us/sony_gcc29.txt`) and `-fmove-all-movables` (`config/us/move_movables.txt`, 2026-11-08); steering helpers carry `// steer-ok:`.
- Matched C: 6,192 functions in `src/` (2026-11-08); every other function is built from its original assembly, and the best compiling draft of
  each is in `nonmatching/`.
- NTSC-U code reached 80% on 2026-11-08 (80.10%, blockers counted as finished; PAL 78.64%). Outside the SDK range it is 85.8% (53.1% exact C); the SDK range
  (150 KB, libm and libc giants) is 33%.
- VU0, MMI, COP0 and hand-written functions, and since 2026-11-09 the 162 remnants that are not functions, are flagged as permanent blockers (`config/us/blockers.tsv`) and counted as finished apart from the exact C, as in sly1 ([build/vu0-mmi.md](build/vu0-mmi.md)).
- PAL is checked against the same C (`make pal`); US is the reference.
- CI is sly1-decomp's: `checks` (unit tests, repository check for game data and licence headers, byte-compile) and `progress`
  (objdiff reports for ByteMatch). Commit messages and the cleanup rules are checked locally (`make commits`, `make cleanup`).

## What is left (2026-11-09)

There are three separate "100%"s (numbers from `progress/us/report.json`):

- **Code, 80.25%:** 277 KB in 471 functions (blockers already count as finished).
  - 261 far near misses, 171 KB. Opus matches about 1 in 8 at about 70k tokens each.
  - 102 SDK-range functions with no draft, 64 KB (libm and libc giants, Sony gcc 2.9).
  - 19 held-back rulings, about 0.25 points. Fresh near misses (score 1-16) are used up.
  - What moved the number so far was systematic unlocks (the loop5 assembler patch, +22 KB; the `-fmove-all-movables` list; RTL-dump work on register-only misses), not worker waves (about 20 bytes per claimed function). Look for the next lever before spending a wave.
  - Six integer near misses have no known lever: 0x1733C8, 0x1C9058, 0x120548, 0x218748, 0x1A5D98, 0x13FAD0.
  - 162 chunks of the split were not functions (2,640 bytes): nothing in retail reaches them and they never transfer control. Since
    2026-11-09 they are the `remnant` kind of `config/us/blockers.tsv` ([build/vu0-mmi.md](build/vu0-mmi.md)); open went from 633 to
    471 functions, code from 80.10% to 80.25%.
  - The SDK range is not a reorder-mode or other Sony build ([build/compiler-identification.md](build/compiler-identification.md),
    2026-11-08 and 2026-11-09): what is left there is drafting, not toolchain.
- **Data, 20.36%** (205,995 of 1,011,732 bytes, 2026-11-09): ceiling 49% of data (item 3); the irx and vutext regions are not game C. Largest gap, and it needs build work, not matching.
- **Exact C, 49.97%:** the 1,015 permanent blockers (853 functions C cannot express, 162 remnants) stay original assembly, so exact C tops out near 70% of code unless item 6 reclassifies some.
- **PAL, 78.78%** against US 80.25%: close it with `make pal` after each land.

- **Source form:** the matched C reproduces retail's bytes but not yet the original's shape. `include/sly2.h` is 12 lines; 1,696 files
  size their structs with padding; 401 struct names have different bodies in different files (`VT` 131, `SO` 65). Measured
  2026-11-09: [PRESERVATION_AND_PORT.md](PRESERVATION_AND_PORT.md). The fixed-width typedefs are shared since 2026-11-09
  (`include/types.h`, item 1).

Order (2026-11-09, [PRESERVATION_AND_PORT.md](PRESERVATION_AND_PORT.md)): shared types first (item 1), because every match landed on
padded local structs adds to the later cost; then one source layout (item 2) and the data build side (item 3); then the port-facing
metadata (item 4). Matching (item 5) runs only on a measured lever, not as waves: what this project adds is the whole-image proof and
the source's shape, not the last points of the headline ([PRESERVATION_AND_PORT.md](PRESERVATION_AND_PORT.md) "Levers measured").
PAL after each land.

## Next

Preservation is the priority; what helps a later port is additive (headers, typedefs, asserts, metadata, notes) and never changes
matched bytes or what counts as matched ([PRESERVATION_AND_PORT.md](PRESERVATION_AND_PORT.md) "The rule").

1. **Shared types.** One definition per class in `include/`, typed from what retail's code does, field names keeping their `source:`.
   - Done 2026-11-09: fixed-width typedefs in `include/types.h` (`s8`..`s128`, `u8`..`u128`, `f32`, `f64`, `QW`), included by
     `sly2.h` and `m2c_macros.h`; 815 sources (808 per-function, 7 whole files) dropped their own copies. `s64` is `long`: with SN's
     ee-gcc `sizeof(long)` is 8 and `sizeof(long long)` 16, and `long long` arithmetic fails ("unsupported wide integer operation");
     none of the 252 sources that declared `s64` as `long long` used it. `make elf` byte for byte, objdiff report unchanged.
     `make cleanup` fails on a new local fixed-width typedef in `src/`; `harvest.py` drafts include `types.h`.
   - A field enters a shared header when at least two matched functions read it at the same offset with the same type; the
     recovered layouts (`config/recovered/sly2_structs.h`) are mostly `field_0x...` gaps and Sly 1's offsets do not carry over, so
     the evidence is our own matched code. A local struct's name does not identify a class: the 28 local `XF` bodies describe at
     least five different types (a 2D transform of six floats, an object with an act list at 0x90, one with a kind at 0x98...).
   - Pilot done 2026-11-09: `include/so.h`, first a flat view (now the class below) of `SO`'s first 0x150 bytes with the nine fields two or more functions agree
     on (`psoParent` 0x10, `proot` 0x14, `grfo` 0x28, `pxfLinear`/`pxfAngular`/`pxfRoot` 0x58-0x60, `pphys` 0xE8, `poxa` 0xEC, `grfso`
     0x148), the unknown gaps named by offset, and offset checks the PS2 build enforces (a negative array size on a moved field;
     gcc 2.95 has no `static_assert`). 21 of the 72 files that declared their own `SO` moved over (20 per-function sources, one
     whole file): drop the local struct, include `so.h`, rename 0 to 3 fields. All 21 score 0 again (`try.py`, `make unit`), `make elf`
     PASS, reports unchanged. Cost: one scripted pass and one hand fix (a same-named field of another struct), two compiles per file.
   - Classes and virtuals done 2026-11-09: `include/lo.h` (`BASIC`, `LO`) and `include/so.h` (`SO : LO`) are real C++ classes.
     Retail's class table (0x2BAAE8, `config/recovered/class_diff.tsv`) names them by their vtables: class 2 (0x50 bytes, 48 slots:
     `InitLo`, `SetLoParent`, `UpdateLo`...) is `LO`, class 48 (0x150 bytes, 75 slots: `InitSo`, `UpdateSo`, `ProjectSoTransform`...) is
     `SO`; Sly 2 has no separate `ALO` level. g++ 2.95 puts the vtable pointer after the own fields of the first class with a virtual
     (measured: `struct LO : BASIC { virtual...; char lo[0x40]; }` puts it at 0x4C), so retail's pointer at 0xC makes the root class
     (class 0, 0x10 bytes) 0xC bytes of fields plus the pointer; class 155, the other branch from the root, shares slots 1, 2, 4 and 5
     with `LO`, so slots 1 to 6 are the root's. An entry is 8 bytes (delta, index, function) and slot n sits at 8 * n, so the 75
     virtuals are declared in slot order, named after the function retail puts there (`Slot<n>` while unnamed), with a signature only
     where a matched caller shows it. A real virtual call compiles to retail's sequence (`lw` vptr, `lh` delta, `lw` function, `jalr`,
     `addu` in the delay slot): 15 matched functions now call through `pso->FIsLocked()`, `pso->Remove()`, `attached->SetParent(...)`
     instead of `vt->fn((char *)pso + vt->delta)`, all scoring 0. The PS2 build checks `sizeof` (0x10, 0x50, 0x150) and every offset.
   - Fields added by the same two-reader rule: `cgeom`/`ageom` 0xE0/0xE4 (two files call the element `GEOM`, two `PART`: one array
     of 0xB0-byte elements, named `GEOM`), `uFade`/`duFade` 0x12C/0x130. The 0xEC conflict resolved: the two files that read
     `pphys` at 0xEC read `pcontact` at +0x6C of the object, next to `owner` +0x60, `first` +0x64 and `pmqList` +0x68 of the
     `poxa` readers: one `OXA`, misnamed.
   - Derived classes and children (2026-11-09): every function was mapped to the classes whose vtable holds it, which ties a matched
     function to its class without trusting local names. `include/slotso.h`: `SLOTSO`, class 96 (0x250 bytes, derived from `SO`:
     `UpdateSlotSo` is its slot 16, `AccelSlotSoRotation` 70, `FAbsorbSlotSoWkr` 75); 3 of its files moved, two of them with virtual
     calls on the derived object (slots 29 and 31). The child list: `SO::ploChildFirst` 0x64 and `LO::ploNext` 0x24, walked by three
     matched functions that call their own slot on each child (slots 20, 26, 27, recursive virtuals). A field needs one reader when
     the reader is a method of the class, two when the class is only guessed from a local name, and never contradicts another
     reader (the rule is at the top of `include/lo.h`).
   - `DL` (2026-11-09): `include/dl.h` holds `DL`, `DLE` and `DLI`, named after Sly 1's decomp (CC0) and laid out from Sly 2's own
     code; retail's mangled `InitDl__FP2DLi` and `ClearDle__FP3DLE` show the types existed. The whole `dl` module (`InitDl` to
     `CPvDl`, 10 functions) now compiles from them, and so does the iterator helper five functions had copied word for word
     (`PushDli`, `PvFirst`, `PvStep`, `PopDli` around the iterator list `g_2dd2fc` that `RemoveDlEntry` fixes up), now one inline set
     in the header. `SO::dlChild` (0x64) is a `DL`, which brought `InitSo` over. The children's link at 0x24 is not declared as a
     `DLE`: its `prev` would be 0x28, where retail reads `grfo` with `ld` (noted in `lo.h`). 15 of the 16 files with their own `DL`
     moved (`CloseFrame` defines its own `QW`).
   - `XF` (2026-11-09): `include/xf.h`. Not in the class table; its first 0x80 bytes keep Sly 1's layout and names (`mat`, `pos`,
     `matWorld`, `posWorld`: `GetSoCpdefi` reads 0x40 and 0x70 that way), the rest comes from functions that reach an `XF` through
     `SO::pxf*` or take one by name: the act list 0x90, `kind` 0x98 (signed: `SleepXf` matches with it too), `pxfParent` 0xA0,
     `generation` 0xA4, `vel` 0xB0, `accel` 0xF0. 10 functions moved. The local name `XF` was also given to at least four other
     types (a 2D transform, objects with a float pair at 0x80); those stay local. Readers that copy 0x40-0x80 as one `MATRIX4`
     (quadword moves) stay local until that view is settled against retail's copies.
   - Status: 46 of the 72 files that declared their own `SO` use the shared classes, and 20 hand-written vtable calls are real
     virtual calls (`make elf` PASS, reports unchanged, every converted function links from C). The other 26: `func_001F3CC8` needs
     `GLOBSET` (0x80); derived classes with one matched file each (classes 85, 87, 103, 107); `SLOTSO`'s init function (unnamed float
     constants) and `FAbsorbSlotSoWkr` (an object of unknown class at 0x1C8); fields only one guessed reader shows (0x40, 0xB8,
     0x138...); opaque uses; `Carry_Attach`. 288 files still write vtable calls by hand on other classes. Next: `XF`'s matrix view
     (`MATRIX3` + `VECTOR` against `MATRIX4`), then the class table's other families.
   - Editing `include/` changes the scorer fingerprint: do it between waves, after `claim.py land`.
   - The tie-break rule ([contributing/code-cleanup.md](contributing/code-cleanup.md)) applies now: of two wordings that both
     score 0, the typed one lands. `make cleanup` warns on padding members, raw offset casts and hand-written vtable calls in added code.
2. File boundaries found in retail, as sly1 does: the constructor list gives each file's end, shared static data and
   `.rodata` grouping give its start, and a file is proved by building it whole, with its unmatched functions
   included from assembly (`INCLUDE_ASM`). Replaces fixed windows of `src/` with real files. Wanted (Theo, 2026-11-06).
   Stage 1 (2026-11-08): the constructor list at 0x2C85C0 gives 209 verified file ends (210 `_GLOBAL_$I$` wrappers, each after its
   `__static_initialization_and_destruction_0`; the linker builds the list, SN's compiler writes no `.ctors`); `modules.tsv` groupings straddle
   them (139 of 209 spans hold several modules). Stage 2: `src/memory-bez/ary.cpp` (0x116CA0-0x117030, 11 functions, two from `INCLUDE_ASM`)
   builds whole and the image stays byte for byte (`config/us/whole_files.tsv`, `make unit UNIT=src/memory-bez/ary.cpp`). 181 of the 209 files
   (about 405 KB) can use the same path as it is; 26 need the file's own `.rodata` placed (item 3); 2 mix per-function flag lists. Stage 4: 78
   whole files (276 matched functions) build whole; five more on 2026-11-09 (83 files, 304 matched functions). Stage 5 (2026-11-08): the whole file is the only record of its functions. `make src` publishes
   no per-function copy of them (276 files, 223 KB, left `src/`; `src/MANIFEST.tsv` gives them `whole_file` and `symbol`); objdiff cuts each one
   out of the whole object and PAL reads it there at its offset (both reports unchanged); a new match inside a whole file lands by replacing its
   `INCLUDE_ASM` line and re-proving the range (`make_whole_files.py --land`, run by `record.py`). Matching stays per function in scratch
   (`data/matching/src/fn`, `try.py`). Stage 6 (2026-11-09): `link_image.py` links a whole file's own `.rodata` at retail's address and `make_whole_files.py` proves it (four more files convert and the image stays identical), but `make_objdiff.py` `cut_function` cannot cut a function that reads `.rodata`, so those files are held back (`exclusion`) until objdiff can; landing them gains no data bytes anyway (their literals already count through the per-function objects). Still open: one flag set per file, counting per file instead of per module, and the 826 low-confidence
   cuts inside a span.
3. Data from C (code passed 80% on 2026-11-08, so this is open), by sly1-decomp's rule, ruled 2026-11-08 ([contributing/exceptions.md](contributing/exceptions.md) "Game data
   defined in source"): a global is defined in C only where its initial value reproduces retail's bytes at its address, one file defines it, every other
   file declares it `extern`; the defined bytes count as matched data. Today 20.36% of data (205,995 of 1,011,732 bytes: 489 typed `.data` groups from
   `make_data_files.py`, plus a function's own literals and jump tables, `data/rodata-c`). What can ever be C: `data/rodata` 296 KB and `data/data` 199 KB (49% of data); `data/irx` 474 KB (IOP modules) and
   `data/vutext` 34 KB (VU microcode) are not game C. A pilot on `HitFx_GIntensity` (2026-11-08) found the build side missing, not the ruling: the
   two constants it reads (`g_2bdce0`, `g_2bdcf0[3]`) are in `.data`, not `.rodata`; a `const` scalar is folded into `lui`/`mtc1` (score 24) and a
   plain definition lays out 8 bytes short of retail's gap; `link_image.py` places only an object's own `.rodata`, and `derive_rodata_base` assumes
   section-symbol relocations. Per-global sweeps are small (18 `.rodata` externs, 178 bytes behind matched functions; 674 `.data` externs, 103 KB, 129 of
   them over 1 KB). First global defined in C (2026-11-09): `src/crv-lo/data_2bdce0.cpp` defines `g_2bdce0` and `g_2bdcf0` as `float[4]` (retail's two 16-byte vectors; the earlier "8 bytes short" was the wrong type), listed in `config/us/data_files.tsv`; `link_image.py` links its `.data` at retail's address (`.dd_<address>`) and checks the bytes, `make_objdiff.py` counts it (data 8,375 -> 8,407 bytes). Remaining: `.bss`, more regions, the list feeding the report per global. The real work is whole data regions per file (labels to the next label, typed from what retail's code does), `.data` and `.bss`
   sections placed at retail's address (`-fdata-sections`), and a list of the defined globals feeding the report, as sly1-decomp does. Depends on 2.
   Data regions are typed with the shared headers of item 1, not with new per-file structs.
4. **Port-facing metadata, no code change.** A layer column in `src/MANIFEST.tsv` and the registry (game logic, engine, platform:
   GS, VIF and DMA, IOP, memory card, pad, VU microcode); JSON exports of symbols, the class tree, vtable layouts and struct offsets
   generated from the headers; hardware access behind named macros or inlines only where retail's bytes are identical. Depends on 1.
5. **Matching on a measured lever only** (procedure: [AGENT_WORKFLOW.md](AGENT_WORKFLOW.md)). Waves yield about 20 bytes per claimed
   function and a far near miss costs about 70k tokens at 1 in 8; no wave starts without a lever measured on a pilot.
   - Done 2026-11-09: the 162 remnants (chunks nothing reaches that never transfer control) are a blocker kind of their own
     (`make blockers`); the open count went from 633 to 471.
   - Then the levers, each measured before a wave: classify the 261 far near misses by diff cause (`classify_diffs.py`); draft
     the SDK giants biggest first (drafting is what is left there, not toolchain). Measured and closed: no generator-style family
     is left among the open functions (no group over 12 by module, name or size); reorder-mode assembly for the SDK range
     (negative, 2026-11-09).
   - A worker that meets a permanent blocker reports
     one line of what it computes (`SKIP wall <semantics>`); the lead records it in `config/us/blocker_notes.tsv`, with a note on
     PS2 FPU behaviour (no denormals, infinities or NaNs) where the result depends on it.
6. Reclassify the permanent blockers that are compiled C, as sly1-decomp did on 2026-11-07: shared inline-assembly helpers for
   VU0, MMI and `max.s`/`min.s`, an **inline** kind counted as to-do, not finished. We will need to do this to keep the report
   honest and match about 106 to 258 of the 853 blockers that are not remnants. First a compile pilot on about 10 functions, then the rule change in
   AGENTS.md; the headline falls by about 1.7 to 4.2 points. See [build/inline-asm-helpers.md](build/inline-asm-helpers.md).

## When a port starts

- Reference C for functions that stay assembly, labelled "behaviour, not original", outside `src/` (a `reference/` folder or the
  port's repository) and never in the reports. An equivalence harness, if built, is optional tooling here or lives in the port.
- A host syntax check (`clang -fsyntax-only` for a 64-bit target over `src/` with a shim header) that writes a warnings report and
  never gates.

## Not goals

The renderer, the audio engine, a platform layer and the port itself live in other projects. "Behaviourally equivalent" C is not
a match and does not go in `src/` or the reports.

# Preservation first, port-friendly second

A review of the project's choices (2026-11-09), with preservation as the absolute priority and a later PC port as the second
user of the work. The ordered steps it leads to are in [ROADMAP.md](ROADMAP.md) "Next".

## The rule

**Matched source keeps the original's form; everything that helps a port is additive.** Headers, typedefs, asserts, metadata,
notes and separate folders are allowed. Changing matched bytes, or what the reports count as matched, is not. A byte match stays
the only proof that a function is the original's source.

## What the project gets right

- **The byte gate.** A function counts only when `make elf` still reproduces retail; nothing is taken on a model's claim. This is
  what makes the result trustworthy as preservation.
- **Toolchain archaeology,** measured and written down: compiler identification, the loop5 assembler patch with its evidence,
  Sony's ee-gcc 2.9 for the SDK range.
- **Clean-room and licence discipline:** nothing from the prototype, `source:` on every recovered name, THIRD_PARTY_NOTICES.md.
- **PAL checked, not rebuilt:** cheap, and it catches regional drift.
- **Dead ends recorded** ([contributing/lessons.md](contributing/lessons.md), [build/assembler.md](build/assembler.md) "Short loops",
  `config/matching/walls.tsv`), so they are not paid for twice.

## What falls short of preservation

Measured on `src/` on 2026-11-09 (5,119 source files):

| Measure | Count |
| :--- | ---: |
| Lines in the only shared header, `include/sly2.h` | 12 |
| Files with a padding member (`char pad...[N]`) | 1,696 |
| `struct` definitions / distinct struct names | 5,365 / 2,346 |
| Struct names defined with different bodies in different files | 401 |
| Worst: `VT`, `SO`, `CRef`, `SW`, `Obj`, `LO`, `ALO` | 131, 65, 50, 47, 43, 38, 24 bodies |
| Files declaring their own integer typedefs / `s64` as `long` / as `long long` (128 bits on the EE) | 639 / 262 / 249 (0 since `include/types.h`, 2026-11-09) |
| Distinct `func_XXXXXXXX` callees referenced | 2,246 |
| Distinct address-named globals (`g_`, `B_`, `D_`) | 1,166 |
| Files with `extern "C"` / files named with a mangled symbol | 3,202 / 316 |
| Files with `virtual` / with a `class` | 50 / 8 |

1. **No shared types.** Each function declares its own view of the objects it touches, sized with padding, and the same name
   means up to 131 different layouts. Recovered layouts exist (`config/recovered/sly2_structs.h`, 157 structs from Ghidra, gaps
   and `field_0x...` names, unverified) but no source includes them. The original had shared headers; per-function padded structs are scaffolding that happens
   to match, not the original's source. Every match landed on them now has to be revisited later, so this costs more the longer
   it waits.
2. **The C++ design is not recovered.** Sly 2 is real C++ (vtable pointer at +0xC, 8-byte slots), but virtual calls are written
   out by hand (`vt->fn((char *)obj + vt->delta, ...)`) and classes are rare. Linkage is mixed: mostly `extern "C"`, a few
   mangled names. Started 2026-11-09: `BASIC`, `LO` and `SO` are real classes with their 75 virtuals in slot order, and a real virtual
   call reproduces retail's bytes (ROADMAP.md item 1).
3. **Raw offsets remain** (`*(int *)(base + 0x1404)`, 1,338 such casts by `make cleanup`'s pattern, see "Baseline"), even where a field would match.
4. **The headline mixes source and bytes.** The permanent blockers (853 functions C cannot express and, since 2026-11-09, 162 remnants that are not functions; 30.28% of code) count as finished but are preserved as
   assembly, not as source. That is a fair rule for a byte-matching project, but the report should keep it visibly apart (it does,
   in the "exact C" column) and the roadmap's blocker reclassification keeps that honest.
5. **Layout churn.** One function per file, then whole files, with per-function scratch that lands back into `INCLUDE_ASM` lines;
   both systems coexist and `make_objdiff.py` cannot yet cut a function that reads `.rodata`. Whole files are the right target
   (the original's translation units); the cost is running two systems at once.
6. **Process weight.** 87 tracked Python scripts (about 14,800 lines) and about 250 KB of rules and docs, with many dated rulings
   (`steer-ok`, `volatile-ok`, per-function flag lists). The roadmap already records that worker waves now yield about 20 bytes per
   claimed function and that systematic levers moved the number. A project that people can join outlives any one contributor's
   budget: keep the rules short and the tools few.

## Levers measured for the open functions (2026-11-09)

Matching runs on measured levers only (ROADMAP.md item 5): waves now yield about 20 bytes per claimed function, and what this project
adds beyond the headline is the whole-image proof, plain C, PAL and, once the roadmap's items 1 to 3 land, the original's types, files
and data.

| Lever | Measured | Result |
| :--- | :--- | :--- |
| Open "functions" that are not functions | For each of the 630 open functions with a registry row: is any `jal`, `j`, branch, data word or `lui`+`addiu` pair in retail aimed at it (control: 5,325 of 5,333 matched functions have one); then, to keep real but unused functions apart, does it hold any return, jump, branch or call | 168 have no reference (3,176 bytes); 162 of them (2,640 bytes) also never transfer control, while every matched function is reached or returns. Done: the `remnant` kind of `config/us/blockers.tsv` ([build/vu0-mmi.md](build/vu0-mmi.md)) |
| SDK code assembled by GNU as in reorder mode | Sony 2.9 with `-fno-delayed-branch` against the build, 224 matched SDK controls and 109 open SDK drafts ([build/compiler-identification.md](build/compiler-identification.md)) | Negative: 216 controls break, 3 drafts improve, none reaches 0 |
| Another Sony build per SDK library | Measured on libmpeg (2026-11-08): the Linux 991111 builds give 991111b's output, the others are worse | Closed |
| Families of functions from one template | The open functions grouped by module, name prefix and size | No family left: no group over 12 |

## What a port needs, and what it should not change here

A port needs one model of the game's types, honest knowledge of what each assembly-only function computes, typed data, and a clear
line between game logic and PS2 hardware. It does **not** need "behaviourally equivalent" C in `src/` or in the reports: that is a
reimplementation, not the original, and counting it would dilute preservation and give near misses a "good enough" exit. An
equivalence harness, if one is built, is optional tooling (a check on `nonmatching/` drafts recorded as a note) or lives in the
port's repository.

## Changes, all additive

### Both goals gain

1. **Shared headers with real types**, one definition per class (`SO`, `ALO`, `LO`, `XF`, `GUARD`, the vtable layouts), typed from
   what retail's code does, field names keeping their `source:`. New matches include them; existing matches move over file by
   file, each re-proved with `make elf` and `make unit`. Pilot (2026-11-09): `include/so.h`, 21 files moved (ROADMAP.md item 1).
2. **Fixed-width typedefs** (`s8`..`s64`, `u8`..`u64`, `f32`, `QW` for 128-bit) instead of bare `int` and `long` (one definition
   in `include/types.h` since 2026-11-09). On the EE
   `long` is 64 bits, which a Windows x64 port reads as 32. The compiled bytes do not change.
3. **Layout asserts** in the headers: `static_assert(offsetof(SO, pxfLinear) == 0x58)` and `sizeof` checks, active only for the PS2
   build. They record retail's layout for preservation and give a port the exact list of what moves with 8-byte pointers.
4. **A tie-break rule** in [contributing/code-cleanup.md](contributing/code-cleanup.md): when two wordings both score 0, take the
   typed one: a member over a cast offset, a real virtual call over a hand-written vtable call, a shared type over a local one.

### Metadata, no code change

5. **A layer column** in `src/MANIFEST.tsv` and the function registry: game logic, engine, or platform (GS, VIF and DMA, IOP,
   memory card, pad, VU microcode). A port then knows what to replace and what to keep.
6. **Machine-readable exports** generated from the headers: symbols, the class tree, vtable layouts and struct offsets as JSON.
7. **Hardware access behind named macros or inline functions** (a DMA kick, a GS register write) only where retail's bytes are
   identical and the original plausibly had them (AGENTS.md's rule on macros). A port replaces the header, not the game code.

### Notes on what stays assembly

8. **One line of semantics per blocker** ("4x4 matrix multiply, w ignored"), written by whoever studies its assembly. It preserves
   knowledge and is half of a port's work on that function.
9. **Notes on PS2 FPU behaviour** (no denormals, no infinities or NaNs, clamping) on the functions whose results depend on it: a
   port either reproduces those results or knowingly diverges.
10. **Reference C, if anyone writes it, outside `src/`** (a `reference/` folder or the port's repository), labelled "behaviour, not
    original", never in the reports.

### Checks that report, never gate

11. **A host syntax check:** `clang -fsyntax-only` for a 64-bit target over `src/` with a shim header, writing a warnings report.
    It shows where portability debt sits without pressuring matched code.
12. **Game data in C typed with the shared headers** (the roadmap's data item): tables and vtables become usable by a port for free.

## Baseline

`make cleanup` prints the tie-break warnings on added code only. Across all of `src/` on 2026-11-09 they number 3,619 padding
members, 1,338 cast offsets, 519 bare `long`s and 401 hand-written vtable calls (`warn_lines` of `scripts/check_cleanup.py` over every
line). Track these as the shared-types work moves files over.

## Order

1. Shared headers, typedefs and the tie-break rule first: they touch the most code, and every match landed on padded local structs
   adds to the later cost.
2. Finish one source layout (whole files) and the data build side, typed with the shared headers.
3. Layout asserts, the layer column and the exports.
4. Matching on measured levers only: the 162 remnants out of the open count (done 2026-11-09), then a lever per pool measured on a pilot; one
   line of semantics per blocker in every worker brief.
5. Reference C and the host syntax check only when a port starts.

## Open questions

- Move existing matches to the shared headers in place now (re-proving each), or require them only for new matches and convert
  file by file as whole files land?
- Does reference C live here (`reference/`) or only in the port's repository?
- Does the progress page keep "code" as its headline, or lead with exact C?

<img align="right" width="108" alt="OpenThievius icon" src="https://github.com/OpenThievius.png">

# Sly 2: Band of Thieves (PS2) Decompilation

[![OpenThievius](https://img.shields.io/badge/Project-OpenThievius-2a6db5?logo=github&logoColor=white)](https://github.com/OpenThievius/OpenThievius)
[![Progress report](https://github.com/OpenThievius/sly2-decomp/actions/workflows/progress.yml/badge.svg)](https://github.com/OpenThievius/sly2-decomp/actions/workflows/progress.yml)
[![Code](https://bytematch.dev/Blightwidow/sly2-decomp.svg?mode=shield&label=Code&measure=matched_code_percent)](https://bytematch.dev/Blightwidow/sly2-decomp)
[![Functions](https://bytematch.dev/Blightwidow/sly2-decomp.svg?mode=shield&label=Functions&measure=matched_functions)](https://bytematch.dev/Blightwidow/sly2-decomp)
[![Build guide](https://img.shields.io/badge/Build-Guide-c3cbd8?logo=gnubash&logoColor=c3cbd8&labelColor=0d1117)](docs/build/building.md)
[![Contributing guide](https://img.shields.io/badge/Contributing-Guide-c3cbd8?logo=github&logoColor=c3cbd8&labelColor=0d1117)](CONTRIBUTING.md)

A work-in-progress, byte-matching decompilation of *Sly 2: Band of Thieves* (Sucker Punch Productions, 2004) for the PlayStation 2, part of **[OpenThievius](https://github.com/OpenThievius/OpenThievius)**. Reconstructing the original game code in readable C++.

> [!WARNING]
> This repository does not include game data, executables, disc images, or proprietary toolchains.<br>
> A legitimately obtained copy of the **USA / NTSC-U** release (`SCUS_97316`) is required; the tools rebuild everything locally.<br>
> The **PAL** release (`SCES_52529`) is optional: with its executable the tools also check that the matched C reproduces the PAL code.<br>
> `src/` reconstructs game code function by function: see [src/README.md](src/README.md) and [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md).

<!-- progress:begin (scripts/readme_progress.py) -->
| Version | Code | of which exact C | Functions | Blocked for C | C with inline assembly to match |
| :--- | ---: | ---: | ---: | ---: | ---: |
| NTSC-U `SCUS_973.16` | 74.42% (1043688 of 1402480 bytes) | 50.02% | 6281 of 6825 | 940 functions, 24.40% | 73 functions, 5.84% |
| PAL `SCES_525.29` | 72.95% (1023144 of 1402480 bytes) | 48.55% | 6195 of 6825 | 940 functions, 24.40% | 73 functions, 5.84% |

A function counts when `make elf` links its C and the image still equals retail byte for byte; for PAL, when the same C also reproduces PAL's code. Permanent blockers (a VU0, MMI or COP0 instruction, hand-written assembly, or a remnant that is not a function: `config/us/blockers.tsv`, [docs/build/vu0-mmi.md](docs/build/vu0-mmi.md)) stay original assembly and count as finished too, shown apart from the exact C. Compiled C that needs a shared inline-assembly helper for an instruction GCC cannot emit (`config/us/inline_functions.tsv`, [docs/build/inline-asm-helpers.md](docs/build/inline-asm-helpers.md)) is work to do; the last column counts those not matched yet.
<!-- progress:end -->

Live numbers on [bytematch.dev](https://bytematch.dev/Blightwidow/sly2-decomp).

## Layout

| Path | What |
|---|---|
| `src/` | matched C/C++ grouped by module: one function per file, or a whole source file proved from retail's constructor list ([src/README.md](src/README.md)) |
| `nonmatching/` | the best source that compiles for each unmatched function: starting points that count as partial work in the report ([nonmatching/README.md](nonmatching/README.md)) |
| `include/` | shared headers (`sly2.h`) and the assembler macros; shared types move here ([docs/PRESERVATION_AND_PORT.md](docs/PRESERVATION_AND_PORT.md)) |
| `config/` | the Splat configuration and the US retail layout, and `config/eu/`, the PAL pairing and check results ([config/README.md](config/README.md)) |
| `scripts/build/` | the image pipeline: split, link, pack, objdiff |
| `scripts/names/`, `scripts/ghidra/` | name recovery: the Sly 1 code matcher, headless Ghidra scripts |
| `scripts/decompile/`, `scripts/matching/` | decompilation helpers, compile-and-compare tooling for matching |
| `config/sly1/`, `config/recovered/` | inputs from the Sly 1 decompilation (CC0) and the recovered names, classes and modules |
| `progress/` | the objdiff reports ByteMatch reads (`us/report.json`, `eu/report.json`) |
| `docs/` | [build](docs/build/building.md), [contributing](CONTRIBUTING.md) and [game](docs/game/executable-layout.md) notes |
| `tools/`, `work/` | git-ignored: the downloaded toolchain, your executables and local work |

## Getting started

1. `./setup.sh --sly2 /path/to/SCUS_973.16` checks your executable (USA, sha1 `de2af92a...`), creates `.venv` and downloads the
   toolchain into `tools/`.
2. `make elf` splits the executable with Splat, compiles `src/` with the original compiler, rebuilds the image and checks
   it byte for byte ([docs/build/building.md](docs/build/building.md)).
3. `make report`, `make objdiff` and `make readme` write the numbers ([docs/build/progress.md](docs/build/progress.md)).
4. Optional, PAL: `python3 scripts/disc_extract.py discs/<disc>.iso` puts `SCES_525.29` in `work/elf/`, then `make pal` pairs the functions and checks
   the matched C against it ([docs/build/building.md](docs/build/building.md#other-versions-pal)). The US build is the reference: PAL is verified, not rebuilt.

More: [docs/TOOLCHAIN.md](docs/TOOLCHAIN.md) (compiler, assembler, flags), [docs/AGENT_WORKFLOW.md](docs/AGENT_WORKFLOW.md) (the matching procedure, for people and AI agents), [docs/ROADMAP.md](docs/ROADMAP.md), [docs/PRESERVATION_AND_PORT.md](docs/PRESERVATION_AND_PORT.md) (preservation first, what is added for a later port).

Name recovery needs more (Ghidra 12.1.4 with the ghidra-emotionengine-reloaded extension, Java 21, your Sly 1 executable):
[docs/build/name-recovery.md](docs/build/name-recovery.md) and [docs/build/decompilation.md](docs/build/decompilation.md).

Run every tool from this repository's root. `SLY2_DECOMP_DIR` (or the older `ROGUE_BYTE_DIR`) overrides the detected repository root.

## License

GPL-3.0-or-later, see `LICENSE`. Third-party material and its licenses: `THIRD_PARTY_NOTICES.md`.

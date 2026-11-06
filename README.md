<p align="center"><img src="assets/logo.png" alt="Rogue Byte" width="480"></p>
<p align="center">
  <a href="https://bytematch.dev/Blightwidow/rogue-byte"><img src="https://bytematch.dev/Blightwidow/rogue-byte.svg?mode=shield&label=Matched+code&measure=matched_code_percent" alt="bytematch progress"></a>
  <a href="docs/build/building.md"><img src="https://img.shields.io/badge/Build-Guide-c3cbd8?style=flat-square&logo=gnubash&logoColor=c3cbd8&labelColor=0d1117" alt="Build guide"></a>
  <a href="CONTRIBUTING.md"><img src="https://img.shields.io/badge/Contributing-Guide-c3cbd8?style=flat-square&logo=github&logoColor=c3cbd8&labelColor=0d1117" alt="Contributing guide"></a>
</p>
<p align="center">
    A work-in-progress, byte-matching decompilation of Sly 2: Band of Thieves for PlayStation 2.<br>
    Reconstructing the original game code in readable C.
</p>

> [!WARNING]
> Rogue Byte does not include game data, executables, disc images, or proprietary toolchains.<br>
> A legitimately obtained copy of the **USA / NTSC-U** release (`SCUS_97316`) is required; the tools rebuild everything locally.<br>
> The **PAL** release (`SCES_52529`) is optional: with its executable the tools also check that the matched C reproduces the PAL code.<br>
> `src/` reconstructs game code function by function: see [src/README.md](src/README.md) and [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md).

<!-- progress:begin (scripts/readme_progress.py) -->
| Version | Code | of which exact C | Functions | Blocked for C |
| :--- | ---: | ---: | ---: | ---: |
| NTSC-U `SCUS_973.16` | 76.89% (1078304 of 1402440 bytes) | 46.75% | 6026 of 6822 | 853 functions, 30.13% |
| PAL `SCES_525.29` | 75.48% (1058544 of 1402440 bytes) | 45.34% | 5943 of 6822 | 853 functions, 30.13% |

A function counts when `make elf` links its C and the image still equals retail byte for byte; for PAL, when the same C also reproduces PAL's code. Permanent blockers (a VU0, MMI or COP0 instruction, or hand-written assembly: `config/us/blockers.tsv`, [docs/build/vu0-mmi.md](docs/build/vu0-mmi.md)) stay original assembly and count as finished too, shown apart from the exact C.
<!-- progress:end -->

Live numbers on [bytematch.dev](https://bytematch.dev/Blightwidow/rogue-byte).

## Layout

| Path | What |
|---|---|
| `src/` | matched C/C++, one function per file, grouped by module ([src/README.md](src/README.md)) |
| `nonmatching/` | the best source that compiles for each unmatched function: starting points that count as partial work in the report ([nonmatching/README.md](nonmatching/README.md)) |
| `include/` | shared headers (`sly2.h`) and the assembler macros |
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

More: [docs/TOOLCHAIN.md](docs/TOOLCHAIN.md) (compiler, assembler, flags), [docs/AGENT_WORKFLOW.md](docs/AGENT_WORKFLOW.md) (the matching procedure, for people and AI agents), [docs/ROADMAP.md](docs/ROADMAP.md).

Name recovery needs more (Ghidra 12.1.4 with the ghidra-emotionengine-reloaded extension, Java 21, your Sly 1 executable):
[docs/build/name-recovery.md](docs/build/name-recovery.md) and [docs/build/decompilation.md](docs/build/decompilation.md).

Run every tool from this repository's root. `ROGUE_BYTE_DIR` overrides the detected repository root.

## License

GPL-3.0-or-later, see `LICENSE`. Third-party material and its licenses: `THIRD_PARTY_NOTICES.md`.

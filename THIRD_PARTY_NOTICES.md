# Third-party notices

Rogue Byte is GPL-3.0-or-later (`LICENSE`). It contains no game code or data. This file lists the projects whose work
it uses or was informed by, and under which terms. A license listed as "reference only" means we read the project to
check facts or learn how it is organised, and copied nothing from it.

## Reconstructed game code (`src/` and `nonmatching/`)

Most of this repository is GPL-3.0-or-later. The files under `src/` and `nonmatching/` are different: each reconstructs a function of
Sly 2: Band of Thieves (the files of `src/` match the retail executable byte for byte; those of `nonmatching/` compile but do not match yet), so the code remains the intellectual
property of its copyright holders (Sucker Punch Productions, Sony Interactive Entertainment). They are published for
interoperability and preservation research, as other matching decompilation projects do; the GPL covers our
tooling, not the game's own logic. The `.c` files started as output of [m2c](https://github.com/matt-kempster/m2c)
(GPL-3.0). No game data is included, and building or checking these files needs your own copy of the game.

## Material included in this repository

| Project | License | What is used here |
| :--- | :--- | :--- |
| [TheOnlyZac/sly1](https://github.com/TheOnlyZac/sly1) (Sly 1 decompilation) | CC0 1.0 | Symbols, class tree and field offsets in `config/sly1/`; Sly 2 names derived from them in `config/recovered/`. Names follow Sucker Punch's own. |
| [Campfirecrucifix/sly2-bevy-of-thieves](https://github.com/Campfirecrucifix/sly2-bevy-of-thieves) (Rust port) | MIT | Function and global names from its address comments, `config/recovered/bevy_*.tsv`. Copyright its authors. |
| SlyMods wiki (slymods.info) | CC BY-SA 4.0 | SEQ opcode names in `config/recovered/slymods_jsg_opcodes.tsv` and the notes in `docs/game/slymods-crosscheck.md`. These files stay under CC BY-SA 4.0; credit to the SlyMods wiki contributors. |

## Artwork

| Work | License | Use |
| :--- | :--- | :--- |
| Racing Sans One (Pablo Impallari, Rodrigo Fuenzalida) | SIL OFL 1.1 | The title of the logo, converted to paths (`assets/logo.svg`). The font itself is not included; `assets/source/make_assets.py` downloads it. |
| The cap (`assets/cap.png`, `assets/source/cap-full.png`) | Public domain (CC0 1.0); the project releases it without restriction | The logo and icon. It was generated with an image model and cut out; it is a character-style hat in the spirit of the game, not taken from the game. |

## Used as tools, not included

| Project | License | Use |
| :--- | :--- | :--- |
| [Ghidra](https://ghidra-sre.org/) | Apache-2.0 | Disassembly and decompilation, and its BSim feature for function similarity; `scripts/ghidra/` are scripts for it. |
| [Splat](https://github.com/ethteck/splat) (`splat64`) | MIT | Splits the executable into assembly and data (`make elf`). |
| [spimdisasm](https://github.com/Decompollaborate/spimdisasm) and [rabbitizer](https://github.com/Decompollaborate/rabbitizer) | MIT | The MIPS disassembler behind Splat; rabbitizer also decodes instructions in the compare tools. |
| [SN Systems ProDG for PS2 3.01](https://github.com/AngheloAlf/SN-Systems-ProDG_for_PS2_3.01) (a third-party mirror) | Proprietary (SN Systems / Sony) | `Ps2EeAs.exe`, SN's assembler, downloaded by `setup.sh` (pinned SHA-256) into the git-ignored `tools/`, never committed or redistributed. |
| [decompals binutils for PS2](https://github.com/decompals/binutils-mips-ps2-decompals) | GPL-3.0 | The R5900 assembler, linker and objcopy (`setup.sh` downloads a pinned release). |
| [m2c](https://github.com/matt-kempster/m2c) | GPL-3.0 | First drafts of C from assembly (`include/m2c_macros.h`). |
| Python libraries (`requirements.txt`): [ninja_syntax](https://github.com/ninja-build/ninja) (Apache-2.0), [pyelftools](https://github.com/eliben/pyelftools) (public domain), [capstone](https://www.capstone-engine.org/) (BSD-3-Clause), [PyYAML](https://pyyaml.org/) (MIT), [fonttools](https://github.com/fonttools/fonttools) (MIT), [squarify](https://github.com/laserson/squarify) (Apache-2.0), [Pillow](https://python-pillow.org/) (MIT-CMU), [NumPy](https://numpy.org/) (BSD-3-Clause) | as listed | Build, name recovery and the progress site. Installed into `.venv`, not included. |
| [ghidra-emotionengine-reloaded](https://github.com/chaoticgd/ghidra-emotionengine-reloaded) | Apache-2.0 | R5900 (PS2 Emotion Engine) language support. |
| [decompals/wibo](https://github.com/decompals/wibo) | MIT | Runs the Windows compilers on macOS in the matching scripts. |
| [decompme/compilers](https://github.com/decompme/compilers) | per compiler | Source of the SN ProDG and other PS2 compilers used for matching tests. Proprietary compiler binaries are not redistributed. |
| [objdiff](https://github.com/encounter/objdiff) | Apache-2.0 | Compares the rebuilt functions with the retail assembly and writes the progress report (`make objdiff`). |
| [clang / LLVM](https://llvm.org/) | Apache-2.0 with LLVM exceptions | Syntax checks of generated C++ and headers. |

## Reference only (nothing copied)

| Project | License | Why we read it |
| :--- | :--- | :--- |
| ProjectCane (Sly 1 PC port, theclub654) | No license, all rights reserved | How a PC port of this engine handles rendering, input and files. No code, layouts or names from it are published here. |
| [lombyte-project/Lombyte](https://github.com/lombyte-project/Lombyte) (Ratchet & Clank decompilation) | GPL-3.0 | Repository layout, dotfiles and contribution docs. Structure only. |
| [decomp.wtf](https://decomp.wtf/) | not stated | The compile-and-diff workflow of `scripts/matching/try.py` follows its design; no code was taken. |
| [OpenRAC/rac1-decomp](https://github.com/OpenRAC/rac1-decomp) (Ratchet & Clank 1 decompilation) | GPL-3.0 | What SN's assembler does that GNU `as` does not, and a list of compiler levers (`docs/build/assembler.md`, `docs/contributing/matching.md`). Read for its findings; nothing was copied. |
| [morluto/rea](https://github.com/morluto/rea) | MIT | Evaluated as a reverse-engineering tool, not adopted. |

## The game

Sly 2: Band of Thieves and the PS2 SDK are copyrighted by their owners (Sucker Punch Productions, Sony Interactive
Entertainment). Names, addresses and types here describe the game for interoperability. No executable, disc image,
disassembly or decompiler output is included: you supply your own legitimate copy (`setup.sh`).

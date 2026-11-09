# Toolchain

The compiler and the assembler are proprietary. They are never committed; `setup.sh` downloads them into the git-ignored `tools/` (pinned
commits and SHA-256). Linux x86-64 and macOS arm64 only; on Windows use WSL or Docker.

| Step | Tool | Where |
| :--- | :--- | :--- |
| Compile | SN Systems EE-GCC 2.95.3 build 1.36 (`cc1plus`), `-O2 -G0 -ffast-math -fno-exceptions`, `-S` | `tools/compilers/ee-gcc2.95.3-136/` |
| Assemble | SN Systems' `ps2eeas` (1.9.25.758, from SN ProDG 3.01) with its short-loop constant changed from 6 to 5 (one byte), `Ps2EeAs-loop5.exe -G0` | `tools/ps2eeas/Ps2EeAs-loop5.exe`, made from `Ps2EeAs.exe` by `setup.sh` |
| Run the Windows tools | [wibo](https://github.com/decompals/wibo) (Linux and macOS) | `tools/wibo` |
| Link, objcopy | decompals binutils for PS2 (R5900) | `tools/binutils-mips-ps2-decompals/` |
| SDK range | Sony's own ee-gcc 2.9-ee-991111 and its driver, for the addresses in `config/us/sony_gcc29.txt` | `tools/compilers/ee-gcc2.9-991111b/` |
| Compare | objdiff (reports) and `scripts/matching/compare.py` (the per-function score) | `tools/objdiff/` |

Why these, and how each was identified: [build/compiler-identification.md](build/compiler-identification.md) and
[build/assembler.md](build/assembler.md) (which also records the `ps2eeas` setup this one replaced and why).

## Rules for the build

- **One flag set per source file** and one assembler for every function, never ad hoc per attempt. The per-address lists are documented
  exceptions ([contributing/exceptions.md](contributing/exceptions.md)): the SDK range's compiler (`config/us/sony_gcc29.txt`, a
  different Sony release) and `-fmove-all-movables` (`config/us/move_movables.txt`).
- `scripts/build/compile_unit.py` is the one path that compiles a source: `ee-gcc -S`, the compiler's `.extern` lines moved to the top,
  `Ps2EeAs-loop5.exe`, `objcopy -L` so each object's symbols are local. `try.py`, `configure.py` (ninja) and the search tools all use it.
- Nothing from the toolchain, no SDK header and no SDK source goes into the repository (AGENTS.md).

## Setup

`./setup.sh --sly2 /path/to/SCUS_973.16` checks your executable and installs everything above; `make elf` then rebuilds the image
([build/building.md](build/building.md)). `python3 scripts/matching/try.py` needs only the compiler, the assembler, wibo and your executable.

# Matching tools

Compile a candidate function with the original compiler (SN ProDG EE-GCC 2.95.3 build 1.36, `-O2 -G0 -ffast-math
-fno-exceptions`, run through wibo) and compare it with the retail bytes. Setup: [docs/build/compiler-identification.md](../../docs/build/compiler-identification.md).

- `judge.sh <compiler> "<flags>" <source.cpp> <address> [symbol]`: one command per function: compiles, then compares with the
  executable (`compare.py`: rabbitizer decoding, relocated fields masked; `score 0` = byte match, then a side-by-side diff).
- `try.py <address> <file>`: the same through the checked-in `tools/` layout.
- `cc.sh`, `build_one.sh`: compile with a candidate toolchain. `match.py`, `fdiff.py`, `objdis.py`, `eedis.py`, `eedecode.py`: compare
  or disassemble a compiled function against the binary. `permute.py`: tries independent statement orders.
- `show.py`, `show.sh`, `similar.py`: look at a function and its closest relatives.
- `name.py`, `rename.py`: apply and rename recovered names in a source. `export_src.py` publishes matched functions to `src/`.

Run them from the repository root. Working copies live in `data/matching/` (git-ignored).

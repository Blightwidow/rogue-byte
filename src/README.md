# Source layout

Matched C and C++ for Sly 2 (SCUS-97316): each function here compiles, with the original compiler (SN ProDG EE-GCC
2.95.3 build 1.36, `-O2 -G0 -ffast-math -fno-exceptions`), to exactly the bytes of the retail executable.

- `src/<module>/<function>.<c|cpp>`: one function per file, grouped by the Sly 1 source file the code matcher placed it
  in (`config/recovered/modules.tsv`). `fun_<address>` means the function is not named yet. `.c` files are m2c drafts
  that matched as they were; `.cpp` files were written to match.
- `MANIFEST.tsv` lists address, name, size and file of every function.
- Shared declarations are in `include/sly2.h` and `include/m2c_macros.h`.
- Regenerate with `python3 scripts/matching/export_src.py` from the working copies in `data/matching/src`
  (git-ignored; the matching tools work on those).

Check a file: `python3 scripts/matching/try.py <address> <file>` (needs the compiler, see
`docs/build/compiler-identification.md`, and your own executable in `work/elf/`).

These files reconstruct code of Sly 2, which remains the property of its copyright holders (see
`THIRD_PARTY_NOTICES.md`).

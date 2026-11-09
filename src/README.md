# Source layout

Matched C and C++ for Sly 2 (SCUS-97316): each function here compiles, with the original compiler (SN ProDG EE-GCC
2.95.3 build 1.36, `-O2 -G0 -ffast-math -fno-exceptions`; the SDK range with Sony's ee-gcc 2.9, `config/us/sony_gcc29.txt`),
to exactly the bytes of the retail executable.

- `src/<module>/<function>.<c|cpp>`: one function per file, grouped by the Sly 1 source file the code matcher placed it
  in (`config/recovered/modules.tsv`). `fun_<address>` means the function is not named yet. `.c` files are m2c drafts
  that matched as they were; `.cpp` files were written to match.
- Whole source files (listed in `config/us/whole_files.tsv`, most named `*_file.c` or `*_file.cpp`): a range of retail proved as one original
  source file, its unmatched functions included from assembly (`INCLUDE_ASM`). They are the only record of their functions: no
  per-function copy is published, and a new match lands in place of its `INCLUDE_ASM` line (`make land`).
- Data defined in C (`config/us/data_files.tsv`) is linked at retail's address.
- `MANIFEST.tsv` lists address, name, size and file of every function; one inside a whole file has its `whole_file` and `symbol`.
- Shared declarations are in `include/`; use them over local copies (AGENTS.md "Preservation first", the tie-break rule in
  `docs/contributing/code-cleanup.md`).
- Regenerate with `python3 scripts/matching/export_src.py` (`make src`) from the working copies in `data/matching/src`
  (git-ignored; the matching tools work on those).

Check a file: `python3 scripts/matching/try.py <address> <file>` (needs the compiler, see
`docs/build/compiler-identification.md`, and your own executable in `work/elf/`); a whole file: `make unit UNIT=src/<file>`.

These files reconstruct code of Sly 2, which remains the property of its copyright holders (see
`THIRD_PARTY_NOTICES.md`).

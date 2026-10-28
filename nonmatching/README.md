# Non-matching sources

Functions that are not matched yet, each with the **best source that compiles** with the original compiler (SN ProDG EE-GCC 2.95.3
build 1.36, `-O2 -G0 -ffast-math -fno-exceptions`). They do **not** produce the retail bytes: they are starting points.

- `nonmatching/<module>/<function>.<c|cpp>`: one function per file, grouped like `src/`. `.c` files are m2c drafts (with the
  mechanical fixes of `scripts/matching/export_nonmatching.py` candidates); `.cpp` files were written by hand and are the better
  starting point.
- `MANIFEST.tsv` lists address, name, size, file and `score`: the number of instructions that differ from the retail function (0 would
  be a match, and then the function belongs in `src/`).
- Nothing here is part of the rebuilt image. `make objdiff` compiles these files (`ninja nonmatching`) so objdiff can compare them
  with the retail code: that is what makes the *fuzzy* figure of the progress report count partial work.
- Not covered by [the cleanup rules](../docs/contributing/code-cleanup.md): m2c drafts keep their `M2C_FIELD` accessors until someone
  finishes them.

To finish one: edit it until `python3 scripts/matching/try.py <address> <file>` prints `score 0`, move it to your working copy
(`data/matching/src/`), run `make src`, then `make elf` and `make unit UNIT=<module>`.

These files reconstruct code of Sly 2, which remains the property of its copyright holders (see
[THIRD_PARTY_NOTICES.md](../THIRD_PARTY_NOTICES.md)).

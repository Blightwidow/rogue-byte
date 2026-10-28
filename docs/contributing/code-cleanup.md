# Code cleanup rules

`scripts/check_cleanup.py` (the `cleanup` workflow) applies these rules to what a pull request **adds**: the lines it adds to
`src/` and `include/`, and the files it adds anywhere. Older problems on `main` do not fail a new change, so the tree can be
cleaned up piece by piece. Run it locally with `python3 scripts/check_cleanup.py --base main`.

| Rule | Why |
| :--- | :--- |
| No `M2C_UNK(...)` / `M2C_FIELD(...)` in added code | These are m2c's raw-offset accesses. Write the field of the struct in `include/sly2.h` (add the field when it is missing). The compiled bytes must stay the same. |
| No `/* Error` comments | m2c left a spot it could not translate. Resolve it. |
| No m2c temporary names (`unk_…`, `phi_…`, `saved_reg_…`) | Name the variable after what it holds. |
| No trailing whitespace, no tabs | Four spaces, as `.clang-format`. |
| No game data or build output | `SCUS_*`, `*.elf`, `*.iso`, `*.bin`, `*.irx`, `*.o`, `*.s`, anything under `work/`, `build/` or `tools/` (except `tools/README.md`). Matched C only; see [CONTRIBUTING.md](../../CONTRIBUTING.md). |

A matched function stays matched: after a cleanup run `make elf`, then `make unit UNIT=<module>`. Every function of the module
must still link from C and the image must still pass the byte check.

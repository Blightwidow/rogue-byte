# Naming conventions

Retail is stripped, so every name here is chosen by us ([AGENTS.md](../../AGENTS.md), "Our own names and types"). This file says which
form to use, so the tree stops growing new styles. It describes the tree as of this writing and applies to what a branch **adds**;
renaming old files is done piece by piece, with `make elf` and `make unit UNIT=<module>` after each batch.

## What the tree looks like today

Counts are tracked files under `src/` (4,607 in all), from `git ls-files src`.

| Style | Example | Files | Verdict |
| :--- | :--- | ---: | :--- |
| Address placeholder | `src/bomb/fun_0013b1c8.cpp` | about 1,590 | Placeholder only, until the function has a name |
| Module directory named by address | `src/new_100008/` | about 60 directories | Rename to the module's name |
| SDK range by address | `src/rodata/sdk_2aa7b0_2aaab0.cpp` | 44 | Fine while the range has no better name |
| Mangled GCC 2.95 name | `EnsureAloSfx__FP3ALO.c` | about 180 | Allowed as the file name of a function, see below |
| CamelCase name | `GetActvalPositionGoal.cpp` | many | Preferred for a named function |

## Rules for new names

1. **Functions: CamelCase verb first**, what it does, not how: `GetActvalPositionGoal`, `EnsureAloSfx`. Methods keep their class
   (`SO::PushDli`). No Hungarian prefixes beyond what a shared header already uses.
2. **Files: one function or one whole source file per name.** A function in its own file is named like the function; a whole source file
   (`config/us/whole_files.tsv`) takes the original module's name. Never mix the two in one directory without a reason.
3. **Placeholder until proven.** An unnamed function is `fun_<address>` (lower case, eight hex digits, the retail address). Lower-case only:
   the older `FUN_0012a860` spelling is Ghidra's and is not used for new files.
4. **Never name from a guess.** A name needs a reader of the function: what it computes, what calls it, what its strings or
   fields show. Keep the source visible (`source:...`) as for every recovered name, and measure a borrowed name against retail.
5. **Module directories** are lower-case words after what the code does (`alo`, `bomb`, `break-mat`), with a hyphen for a
   sub-module (`alo-missile`). An address name (`new_100008`) is a placeholder for a module nobody has named yet.
6. **Mangled names** (`__FP3ALO`) record the signature GCC 2.95 encodes. Keep them where the function was recovered from retail's symbol
   data; for a function named by us, use the plain name and let the header declare the signature.
7. **Types and fields**: typedefs live in `include/types.h` and shared classes in their own header (`lo.h`, `so.h`). Fields
   are named from their use, never `unk_...`, `phi_...` or `saved_reg_...` ([code-cleanup.md](code-cleanup.md)).

## Renaming a file or function

- Rename the symbol in `config/matching/symbol_addrs.txt` and every user in one commit; the byte gate (`make elf`) must still pass.
- Run `make unit UNIT=<module>` after a directory rename, and regenerate `nonmatching/MANIFEST.tsv` rows if the file moved.
- One rename batch per commit, `refactor(names): ...`, with the count of names changed in the body.

## Biggest offenders, in order

1. `fun_<address>` placeholders: about 1,590 files. Each needs per-function evidence, so they get named as the module around them is
   understood, not in a sweep.
2. `new_<address>` module directories: about 60. Cheapest win, since the contents usually show the module (`NewGuard.c`, `NewSw.c`).
3. Mixed file styles inside one directory (mangled next to CamelCase).

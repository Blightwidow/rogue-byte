# Code cleanup rules

`scripts/check_cleanup.py` (`make cleanup`, part of `make check`) applies these rules to what a branch **adds**: the lines it adds to
`src/` and `include/`, and the files it adds anywhere. Older problems on `main` do not fail a new change, so the tree can be
cleaned up piece by piece. Run it locally with `python3 scripts/check_cleanup.py --base main`.

| Rule | Why |
| :--- | :--- |
| No `M2C_UNK(...)` / `M2C_FIELD(...)` in added code | These are m2c's raw-offset accesses. Write the field of the struct in `include/sly2.h` (add the field when it is missing). The compiled bytes must stay the same. |
| No local fixed-width typedef in `src/` (`typedef long s64;`) | One definition in `include/types.h`, reached through `sly2.h`, `m2c_macros.h` or `#include "types.h"`. On the EE `long` is 64 bits and `long long` 128. |
| No `/* Error` comments | m2c left a spot it could not translate. Resolve it. |
| No m2c temporary names (`unk_…`, `phi_…`, `saved_reg_…`) | Name the variable after what it holds. |
| No trailing whitespace, no tabs | Four spaces, as `.clang-format`. |
| No game data or build output | `SCUS_*`, `*.elf`, `*.iso`, `*.bin`, `*.irx`, `*.o`, `*.s`, anything under `work/`, `build/` or `tools/` (except `tools/README.md`). Matched C only; see [CONTRIBUTING.md](../../CONTRIBUTING.md). |

## Warnings: the tie-break rule

Of two wordings that both score 0 and both follow the rules above, the typed one lands ([PRESERVATION_AND_PORT.md](../PRESERVATION_AND_PORT.md)):
the original had shared headers and real C++ classes, and a later port needs them. `make cleanup` prints these as `warning:` lines on
added code; they do not fail it, because a local struct stays allowed while no shared type exists and some functions only match one way.

| Warning | Prefer |
| :--- | :--- |
| A local `struct SO`, `LO` or `BASIC` | `#include "so.h"` (or `lo.h`, `slotso.h`); a missing field goes there with its reader (the rule is at the top of `lo.h`) |
| A padding member (`char pad[0x10]`, `u8 pad0[4]`) | The shared type from `include/`, with the field added there when it is missing |
| A cast offset (`*(int *)(base + 0x1404)`, `*(float *)((char *)p + 8)`) | The struct member |
| A hand-written vtable call (`vt->fn((char *)obj + vt->delta, ...)`) | A `virtual` member function: slot n is declared n-th in `lo.h`/`so.h` (it matches) |
| A bare `long` / `long long` | `s64` / `QW` (on the EE `long` is 64 bits, `long long` 128) |

A matched function stays matched: after a cleanup run `make elf`, then `make unit UNIT=<module>`. Every function of the module
must still link from C and the image must still pass the byte check.

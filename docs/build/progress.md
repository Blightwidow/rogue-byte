# Progress

ByteMatch ([bytematch.dev](https://bytematch.dev/Blightwidow/rogue-byte)) and the table in the README show how much of the game's code
is rebuilt. Measuring it needs your own executable, so the reports are generated locally and committed.

## What is counted

A function counts when `make elf` links its C and the image still equals retail byte for byte; for PAL, when the same C also
reproduces PAL's code at its counterpart (`config/eu/c_status.tsv`). Permanent blockers (`config/us/blockers.tsv`: a VU0, MMI or COP0
instruction, or hand-written assembly) are original assembly and count as finished too, as in sly1-decomp, shown apart from the exact C
([vu0-mmi.md](vu0-mmi.md)). Sony's SDK libraries (module `sdk`) are listed but not the
game's own code.

| File | Holds |
| :--- | :--- |
| `progress/us/report.json` | objdiff's report of the US build (`make objdiff`): units, functions with sizes, measures |
| `progress/eu/report.json` | The same for PAL (`make pal`) |
| `progress/us/blockers.json` | How many permanent blockers (functions, bytes) `make objdiff` counted as finished |
| `work/report.json` | Every function with its status: `c` (compiled in the image), `matched`, `draft` (a compiling source in `nonmatching/`), `blocked` (a permanent blocker), `asm`. Git-ignored (`make report`) |

`make objdiff` also compiles the `nonmatching/` sources, so its fuzzy figure counts partial work.

## Regenerating

```
make elf        # the image and the gate
make report     # work/report.json
make blockers   # config/us/blockers.tsv
make objdiff    # progress/us/report.json (blockers counted as finished)
make pal        # optional, needs work/elf/SCES_525.29: config/eu and progress/eu/report.json
make readme     # the README table
```

Commit `progress/`, `config/eu/` and `README.md` with the work. The `progress` workflow checks the PAL data is current, validates both
reports with objdiff and uploads them as the artifacts `SCUS_973.16_report` and `SCES_525.29_report` (register the repository on
bytematch.dev once by hand). It builds nothing.

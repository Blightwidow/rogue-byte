# config/

Everything here describes the retail executable; no game bytes.

| File | What |
| :--- | :--- |
| `us/sly2.us.yaml` | The Splat configuration, **generated** by `make config` (`scripts/build/gen_splat_config.py`): the code cut into one unit per module, the rodata and data cut into per-module pieces, the raw pieces (ELF header, VU1 microcode, IOP modules, tail) |
| `us/pieces.tsv` | The rodata and data pieces: name, address, size. Input of the config generator and of `scripts/build/link_image.py` |
| `us/image.ld` | The retail layout of the two loaded segments, the base of the linker script `link_image.py` writes |
| `us/checksum.sha1` | SHA-1 of the USA executable; `setup.sh` and `scripts/verify_image.py` check your copy against it |
| `us/blockers.tsv` | The permanent blockers (VU0, MMI, COP0, hand-written assembly, or `remnant`: a chunk that is not a function), written by `make blockers` (`scripts/classify_blockers.py`) |
| `us/blocker_notes.tsv` | One line of what each blocker computes, and whether its result depends on PS2 FPU behaviour; the lead fills it from workers' `SKIP wall` lines ([docs/PRESERVATION_AND_PORT.md](../docs/PRESERVATION_AND_PORT.md)) |
| `us/handwritten_asm.txt` | Functions retail wrote in assembly (`scripts/matching/handwritten.py`) |
| `us/whole_files.tsv` | Whole source files proved from the constructor list: range and file under `src/` ([docs/ROADMAP.md](../docs/ROADMAP.md) "Next", item 2) |
| `us/data_files.tsv` | Data defined in C, linked at retail's address: range and file under `src/` (item 3) |
| `us/sony_gcc29.txt` | The SDK-range functions built with Sony's ee-gcc 2.9 ([docs/build/compiler-identification.md](../docs/build/compiler-identification.md)) |
| `us/move_movables.txt` | Functions compiled with `-fmove-all-movables` ([docs/contributing/exceptions.md](../docs/contributing/exceptions.md)) |
| `us/vu0_regs.txt` | Functions compiled with `-mvu0-use-vf0-15`, for inline-asm VU0 operands |
| `us/categories.json` | The categories of the objdiff report (`scripts/build/make_objdiff.py`) |

The other version, PAL (Europe, v2.01, `SCES_525.29`), has no Splat config: it is paired with the US functions and checked, not rebuilt. `config/eu/` (addresses only, no game bytes):

| File | What |
| :--- | :--- |
| `eu/map.tsv` | `us_address`, `other_address`, `size`, `status` (`identical`, `same`, `gap`, `none`), written by `scripts/pair_versions.py` |
| `eu/c_status.tsv` | per matched US function: does the same C reproduce the PAL code (`score`), and do its relocation sites resolve to the paired PAL addresses (`addresses`), written by `scripts/version_check.py` |
| `eu/addresses.tsv` | the data addresses the matched functions use, US to PAL, with the sites that agree |

Regenerate with `make pal` (needs `work/elf/SCES_525.29`); `make pal-check` (part of `make check`) needs no executable. See [docs/build/building.md](../docs/build/building.md#other-versions-pal).

Reference data, tracked (what the name recovery produced and the Sly 1 decompilation it starts from):

| Path | What |
| :--- | :--- |
| `recovered/` | Recovered names (evidenced: `matches.tsv` and the Rust-port tables; provisional: `provisional_symbol_addrs.txt`), signatures, struct layouts (`sly2_structs.h`, 157 structs: the starting point for the shared types of `include/`), class map and the module list (`modules.tsv`, which cuts the code into units) |
| `sly1/` | Inputs from the Sly 1 decompilation (CC0): symbols, class tree, field offsets |
| `names/resolutions.tsv` | How conflicting name proposals were resolved |
| `matching/symbol_addrs.txt` | Names the compile-and-compare tools give to functions |
| `matching/merges.tsv` | Split chunks that are one function (lead, end, members, branch evidence) |
| `matching/walls.tsv` | Functions the search tools leave out, with the wall and its evidence |

`data/` is git-ignored working space for the local tools (matching drafts and exports).

Generated and git-ignored, written by `make elf`: `us/symbol_addrs.txt` (names for Splat, exported from `config/recovered/` by
`scripts/names/export_splat_symbols.py`) and `us/swapped.tsv` (the functions linked from C).

Do not edit `sly2.us.yaml` or `pieces.tsv` by hand: change `config/recovered/modules.tsv` or the generator and run `make config`.
See [docs/build/building.md](../docs/build/building.md) for the pipeline and
[docs/game/modules-and-units.md](../docs/game/modules-and-units.md) for what the units are.

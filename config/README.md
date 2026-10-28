# config/

Everything here describes the retail executable; no game bytes.

| File | What |
| :--- | :--- |
| `us/sly2.us.yaml` | The Splat configuration, **generated** by `make config` (`scripts/build/gen_splat_config.py`): the code cut into one unit per module, the rodata and data cut into per-module pieces, the raw pieces (ELF header, VU1 microcode, IOP modules, tail) |
| `us/pieces.tsv` | The rodata and data pieces: name, address, size. Input of the config generator and of `scripts/build/link_image.py` |
| `us/image.ld` | The retail layout of the two loaded segments, the base of the linker script `link_image.py` writes |
| `us/checksum.sha1` | SHA-1 of the USA executable; `setup.sh` and `scripts/verify_image.py` check your copy against it |

Reference data, tracked (what the name recovery produced and the Sly 1 decompilation it starts from):

| Path | What |
| :--- | :--- |
| `recovered/` | Recovered names (evidenced: `matches.tsv` and the Rust-port tables; provisional: `provisional_symbol_addrs.txt`), signatures, struct layouts, class map and the module list (`modules.tsv`, which cuts the code into units) |
| `sly1/` | Inputs from the Sly 1 decompilation (CC0): symbols, class tree, field offsets |
| `names/resolutions.tsv` | How conflicting name proposals were resolved |
| `matching/symbol_addrs.txt` | Names the compile-and-compare tools give to functions |

`data/` is git-ignored working space for the local tools (matching drafts and exports).

Generated and git-ignored, written by `make elf`: `us/symbol_addrs.txt` (names for Splat, exported from `config/recovered/` by
`scripts/names/export_splat_symbols.py`) and `us/swapped.tsv` (the functions linked from C).

Do not edit `sly2.us.yaml` or `pieces.tsv` by hand: change `config/recovered/modules.tsv` or the generator and run `make config`.
See [docs/build/building.md](../docs/build/building.md) for the pipeline and
[docs/game/modules-and-units.md](../docs/game/modules-and-units.md) for what the units are.

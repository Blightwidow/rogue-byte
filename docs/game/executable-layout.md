# Executable layout

`SCUS_973.16`, the Sly 2 USA executable: 2,597,048 bytes, SHA-1 `de2af92a54de71e33edc8a160c31c0337a95e6f5`
(`config/us/checksum.sha1`). Offsets are file offsets, addresses are the PS2's virtual addresses.

| File offset | Address | Size | What | Built from |
| :--- | :--- | :--- | :--- | :--- |
| `0x0` | | `0x80` | ELF header and program headers | raw piece `elf_header` |
| `0x80` | `0x100000` | `0x159df0` | `.text`: the game code | `build/splat/asm/<module>.s`, replaced function by function by compiled `src/` |
| `0x159e70` | `0x259df0` | `0x8590` | `.vutext`: VU1 microcode (raw, not MIPS) | raw piece `vutext` |
| `0x162400` | `0x262380` | `0x4a500` | `.rodata`: literals, strings, jump tables | per-module data pieces |
| `0x1ac900` | `0x2ac880` | `0x309b0` | `.data`: initialised data, vtables | per-module data pieces |
| `0x1dd2b0` | `0x2dd230` | `0xd0` | padding | raw piece `irx_gap` |
| `0x1dd380` | `0x472200` | `0x73c40` | embedded IOP modules (`.irx`, MIPS R3000 for the IOP, not the EE) | raw piece `irx` |
| `0x250fc0` | | `0x290f8` | section data outside the loaded segments and the section header table (at `0x279b18`) | raw piece `elf_tail` |

The two loaded segments are the first one (`0x80`–`0x1dd2b0`: code, VU1 microcode, rodata and data) and the IOP modules.
`make elf` rebuilds both and `scripts/build/pack_elf.py` puts the file back together; `scripts/verify_image.py` compares every
loaded byte and then the whole file.

## What is rebuilt, what is carried

- **Rebuilt:** the code (assembly plus compiled functions), the rodata and data pieces (per-symbol assembly, raw bytes where
  the assembly did not reproduce them), the VU1 microcode and the IOP modules as byte blobs.
- **Carried as raw bytes from your executable:** the ELF header, the padding, the section data after the IOP modules and the
  section header table. They are not generated yet.

The raw pieces are cut from your own copy at build time. Nothing from them is stored in this repository.

## Compiler

Every function in `src/` is built with SN ProDG EE-GCC 2.95.3 (build 1.36), `-O2 -G0 -ffast-math -fno-exceptions`;
see [compiler-identification.md](../build/compiler-identification.md).

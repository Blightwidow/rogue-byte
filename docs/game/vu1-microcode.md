# VU1 microcode

The executable carries VU1 microcode in `.vutext` (address `0x259df0`, `0x8540` bytes, 4,264 micro instructions of 8 bytes) and
in 23 `.DVP.overlay.*` sections (`0x800`-byte chunks outside the loaded segments, listed by `.DVP.ovlytab`). It has no DWARF,
`.mdebug` or line information, so names come from the code that uploads and starts the programs.

`scripts/vu/vudis.py <executable>` disassembles all of it (upper and lower word, I/E/M/D/T flags, `loi` constants, branch labels).
`scripts/vu/find_uploads.py` lists where the game code refers into `.vutext`. Instruction indices below are byte offset / 8.

## What the disassembly shows

- About half of `.vutext` is zero padding. Real code is matrix products (`mulax`, `madday`, `maddaz`, `maddw`), `clipw`,
  `itof`/`ftoi`, `mulq`, 56 `div`, 21 `mfp` and 34 `xgkick`.
- Four words decode as neither (`0x14000000`, `0x70000000` pairs at instruction 86, 88, 2128, 2130): constants embedded in code.
- Programs end with an E-bit instruction plus one delay-slot instruction; `vudis.py` splits on that. Many small programs
  (4 to 100 instructions) sit between the big ones.

## Upload ranges

The code refers to `.vutext` in start/end address pairs, one pair per range it uploads with a VIF `MPG` packet:

| Instructions | Referenced by | Notes |
| :--- | :--- | :--- |
| 0 to 2123 | `func_001A7890` (start), `func_001A7900` (end) | first range, holds the small programs at 0 to 90 |
| 90 to 563 | `EnsureBlipVu1Code` | Blip effect |
| 566 to 847 | `func_00211A80` | |
| 850 to 1143 | `func_0016EA20` | |
| 1146 to ? | `func_0016DA48` | only the start is referenced |
| 2132 to 2318 | `UploadRelightLights` | |
| 2322 to 4261 | `FinalizeFrameVifs`, `func_0016E1A8` | the largest range, the end of `.vutext` |

Ranges are 16-byte aligned and mostly start 2 instructions after the previous range's end.

## Entry points

Programs are started with VIF `MSCAL` (`0x14`), `MSCALF` (`0x15`) and `MSCNT` (`0x17`) codes whose 16-bit operand is the VU
instruction address. Only `func_00217298` builds them inline, as `(constant) >> 3 | 0x14000000` (`MSCAL` at instruction 0, 6,
32 and 32 of the range it started); one `MSCALF` to instruction 3 is a constant in `.data`. The renderer's own entry codes are not
in the code as constants: they live in packets the game builds from data, so a complete entry table needs a trace of those packets
(or a run that records the VIF1 stream).

## Not done

- Entry points of the big renderer range and which E-bit programs belong to which `MSCAL` target.
- The `.DVP.overlay.*` chunks: which program each belongs to and what loads them (the name's second number looks like a hash of
  the program, the first number the offset of the chunk inside it).
- Whether `0x260052` (one pointer in `.rodata`) is an address or a coincidence: it is not 8-byte aligned.

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

## Programs and entry points

The game swaps VU1 programs in as overlays: each program is uploaded with VIF `MPG` packets in chunks of at most 256 micro
instructions (2 KB) to VU1 addresses `0x0`, `0x800`, `0x1000`, ... and started with `MSCAL` (VIF code `0x14`, operand = byte address / 8).
The `.DVP.overlay.*` ELF sections are zero-filled placeholders of those chunks (their names carry the chunk's VU1 offset); the code is
in `.vutext`, where chunks of one program sit one instruction apart (pitch 257). A 14,000-frame run of the recompiled game with a log of every
upload and start (`scripts/swapin/patches/vif-trace.patch`, `scripts/vu/place_programs.py`) shows 21 distinct chunks, every one equal word
for word to a `.vutext` slice, and 6.8 million starts of the busiest program. Indices are `.vutext` micro instruction numbers.

| Program | `.vutext` | VU1 range | Uploaded | Code that uploads it |
| :--- | :--- | :--- | ---: | :--- |
| VU0 program (84 instructions) | 2 to 85 | VU0 `0x0` | 1 | `func_001A7890` |
| 2 instructions | 2 to 3 | `0x0` | 1 | |
| Blip | 91 to 563 | `0x0` to `0xebf` | 9,404 | `EnsureBlipVu1Code` |
| 281 instructions | 567 to 847 | `0x0` to `0x8bf` | 13,564 | `func_00211A80` |
| 293 instructions | 851 to 1143 | `0x0` to `0x91f` | 16,173 | `func_0016EA20` |
| 975 instructions, 4 chunks | 1147 to 2121 | `0x0` to `0x1e5f` | 27,128 | `func_0016DA48` |
| relight lights | 2133 to 2318 | `0x0` to `0x5cf` | 2 | `UploadRelightLights` |
| main renderer, 8 chunks | 2323 to 4261 | `0x0` to `0x3c5f` | 92,739 | `FinalizeFrameVifs`, `func_0016E1A8` |

Entry points seen (`MSCAL` byte address, `.vutext` index, number of starts):

- 91 to 563: `0x0000` (91, 10,739), `0x0870` (362, 24,148).
- 567 to 847: `0x0000` (567), `0x0030` (573), `0x0060` (579), `0x0090` (585), `0x00c0` (591, 54,306), `0x0100` (599, 40,742), `0x0140` (607, 733,560), `0x0650` (769, 6,055); about 13,589 starts each for the first four.
- 851 to 1143: `0x0000` (851), `0x0738` (1082), `0x07f0` (1105), each 362,803 starts.
- 1147 to 2121: `0x0000` (1147), `0x1910` (1952), `0x1a68` (1995), 718,230 starts each; `0x1aa0` (2002) and `0x1c48` (2055), 27,128 each.
- 2133 to 2318: `0x0010` (2135), 10,978 starts.
- 2323 to 4261, the main renderer: `0x0000` (2323, 6,840,149), `0x2e20` (3804, 3,785,107), `0x2e68` (3813, 868,877), `0x2eb0` (3822,
  954,169), `0x2ee8` (3829, 5,608,153), `0x2ef8` (3831, 434,309), `0x2f80` (3848, 157,044), `0x2fc8` (3857, 349,342), `0x3358` (3972,
  940,695), `0x3628` (4062, 212,254), `0x37a8` (4110, 212,254), `0x3ab0` (4208, 79,047).

Every program starts at `MSCAL 0x0` (the entry that dispatches), and the main renderer's busiest entries are the 8 to 28 instruction
routines around `0x2e20` to `0x2fc8`. `func_00217298` builds its `MSCAL` words inline as `(byte address) >> 3 | 0x14000000`
with the operands 0, 6, 32 and 24 (instructions), which belong to the program it runs after.

## Not done

- Names for the programs beyond what the uploading code suggests (Blip, relight lights).
- A run that reaches every program: the trace covers the scripted 14,000 frames only. The two small unit 1 programs and the VU0
  program were each uploaded once or twice.
- Which `MSCNT` continuations exist: none appeared, so every start is an `MSCAL`.
- Whether `0x260052` (one pointer in `.rodata`) is an address or a coincidence: it is not 8-byte aligned.

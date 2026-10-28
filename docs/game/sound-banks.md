# Sound system and bank format

Sly 2 plays sound through Sony's 989snd library (`989snd (c)2000-2003 Sony Computer Entertainment America`). The same library
family runs under other PS2 titles, and OpenGOAL's `game/sound/989snd/` (ISC) reimplements it. This note records what Sly 2 shares
with that reimplementation and what is still unchecked.

## Split between EE and IOP

- The EE half is an RPC client inside the game code (source path string `989snd.cpp`): `snd_BankLoad`, `snd_BankLoadByLoc`,
  `snd_BankLoadFromEE`, `snd_BankLoadFromIOP`, `snd_BankLoadFromIOPPartialEx`, `snd_MMDLoad*`, `snd_StopAllStreams`,
  `snd_SendIOPCommandNoWait`. Commands larger than 500 bytes are refused.
- The engine itself is the IOP module `snd989` (library string `989snd_Library`), one of the IOP modules embedded in the
  executable (`irx` piece, see [executable-layout.md](executable-layout.md)). `IOPRP300.IMG` on the disc holds only the IOP
  operating system modules.
- The library build has no MIDI: the startup banner says `NO MIDI VERSION! No MIDI, AME, or basic VAG sounds (banks and streams
  only)`. A port needs the bank, grain and voice code; the MIDI and AME handlers are not needed.

## Where banks sit

The disc's ISO 9660 listing has four files (`SYSTEM.CNF`, the executable, `IOPRP300.IMG`, `Z6TAIL.DUP`). Banks are read by raw
sector (`snd_BankLoadByLoc`), so they are not files. Scanning a disc image for the bank magic finds 86 `SBlk` headers, all
Version 3 with Flags `0x4` (neither the names flag `0x100` nor the user-data flag `0x200`), BankID 0. No `SBv2` (music bank) or
`MMID` magic is present, which agrees with the no-MIDI build.

## SBlk header

A header read with the OpenGOAL layout (little endian) is consistent on 74 of the 86 hits:

| Offset | Field | Observed |
| :--- | :--- | :--- |
| `0x00` | magic `SBlk` | |
| `0x04` | Version | 3 |
| `0x08` | Flags | `0x4` |
| `0x0C` | BankID | 0 |
| `0x10` | BankNum (s8), 5 bytes padding | 0 |
| `0x16` | NumSounds, NumGrains, NumVAGs (s16 each) | e.g. 296, 2490, 351 |
| `0x1C` | FirstSound | `0x40`, directly after the header |
| `0x20` | FirstGrain | |
| `0x24` | VagsInSR, VagDataSize, SRAMAllocSize, NextBlock | NextBlock 0 |
| `0x34` | GrainData | |
| `0x38` | BlockNames, SFXUserData (u32 each) | both 0 |

The sound table starts at `FirstSound`; the 8-byte grain table (opcode word with the grain type in the top byte, then a signed
delay) satisfies `FirstGrain + NumGrains * 8 == GrainData` in all 74. Tone, LFO, play-sound and plugin parameters live in the
`GrainData` area at the offset held in the low 24 bits of the opcode, as in OpenGOAL's version 2 reader.

Grain types seen: 0-9 and 20-44, every one of them in OpenGOAL's grain enum (null, tone, tone2, xref id and number, LFO, start and
stop child sound, plugin message, branch, control null, loops, stop, random play, delay and pitch bend, pitch bend, registers,
markers, goto, wait for voices, play cycle, key off and kill voices, on-stop marker, copy register).

## Not checked yet

- 12 of the 86 hits (the magic at odd sector offsets) do not fit the layout: their grain tables run past `GrainData` or carry
  types above 44. They may be copies inside packed data rather than real headers.
- OpenGOAL only branches on Version below or at least 2. Whether version 3 changes the size or meaning of the tone, LFO,
  play-sound and plugin structures is open until a bank is parsed to the end.
- The behaviour of the `snd989` module (voice allocation, tick rate, command set) against OpenGOAL's handlers.
- Sly 2's plugin messages (`PLUGIN_MESSAGE` grains, 85 in the banks) and what the game registers for them.

## Method

Scan the image for `SBlk`, read the 0x40-byte header, check that the table offsets are consistent with the counts, then tally
the grain type bytes. Nothing from the banks is stored here: the table above holds header field meanings and counts only.

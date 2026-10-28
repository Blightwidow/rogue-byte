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

The 86 are 43 pairs with identical headers:

- 43 sit 24 bytes into a sector (the bank is the raw standalone copy, loaded from a sector number).
- 43 sit at arbitrary offsets inside other data, 300 to 2,000 sectors later. After a literal prefix that equals the raw bank
  they turn into a high-entropy stream (7.6 bits per byte, against 3.6 in the raw bank), so they are compressed copies of the
  same banks (5 of them equal the raw bank in the part that was checked, i.e. stored without compression). They fail the table
  checks below only because the bytes after the prefix are compressed.

All figures below are for the 43 raw banks.

## SBlk header

A header read with the OpenGOAL layout (little endian) is consistent in all 43 raw banks:

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

The sound table (12 bytes per sound: volume, volume group, pan, grain count, instance limit, flags, first grain) runs from
`FirstSound` to `FirstGrain`; the 8-byte grain table (opcode word with the grain type in the top byte, then a signed delay) runs
from `FirstGrain` to `GrainData` (`FirstGrain + NumGrains * 8 == GrainData`). Tone, LFO and play-sound parameters live in the
`GrainData` area at the offset held in the low 24 bits of the opcode, as in OpenGOAL's version 2 reader. Read that way, the 43 banks
(12,995 sounds, 100,677 grains) give:

- 65,557 tone structures (24 bytes): every sample offset lies inside the VAG data, map low never exceeds map high, the reserved
  word is always 0. 0 failures.
- 5,022 LFO structures (16 bytes) and 77 start-child-sound grains (32-byte play-sound structure: every child is by sound id, none
  by name, every id is below the sound count). 0 failures.
- No plugin-message grains; the parameter area ends within the first 49,440 bytes after `GrainData`.

So version 3 uses OpenGOAL's version 2 grain and structure layouts unchanged.

Grain types seen (17, all in OpenGOAL's enum): tone 65,493, random pitch bend 10,968, random play 10,734, random delay 5,525, LFO
5,022, control null 882, play cycle 596, loop start and end 466 each, random register set 249, start child sound 77, stop 75,
tone2 64, add pitch bend 45, set register 13, loop continue 1, on-stop marker 1.

## Not checked yet

- The compressed copies: the codec, and whether the game loads banks from them on the EE side (`snd_BankLoadFromEE`) while the
  raw copies go to the IOP.
- The 24-byte offset: whether a container header precedes each raw bank.
- The behaviour of the `snd989` module (voice allocation, tick rate, command set) against OpenGOAL's handlers.
- Plugin messages: none in the banks, so any plugin hooks are used only by other code.

## Method

`scripts/sound/parse_banks.py <disc image>` scans the image for `SBlk`, reads the 0x40-byte header, checks the table offsets against the
counts and every tone, LFO and play-sound structure against its bounds, and prints one line per bank. Nothing from the banks is stored
here: the table above holds header field meanings and counts only.

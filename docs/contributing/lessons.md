# Lessons

Things that took more than a few minutes to work out here. Read it before matching or touching the tools, and add to it when something
costs you time: a dated heading, one bullet per lesson, what you saw and what fixed it. Fixes that are pure source patterns for a near
miss belong in [matching.md](matching.md); this file is for the surprises around them.

## 2026-10-28: scoring and the assembler

- **The score counts instruction words with relocations masked**, so a function can score 0 and still link to the wrong address; the
  `link` part of the score catches that (see [matching.md](matching.md)). A score recorded before the assembler switch of 2026-10-28
  was measured with GNU `as`: judge it again.
- **The hazard `nop` after `mtc1` and the padding of short loops come from the assembler, never from C.** Chasing them in the source
  wastes hours; `scripts/build/compile_unit.py` assembles every function with SN's `ps2eeas` (under wibo), and
  `config/us/gnu_as.txt` lists the few functions that need GNU `as` instead ([assembler.md](../build/assembler.md)).
- **Compile through the same path the build uses.** `ee-gcc -S`, then the `.extern` lines hoisted, then `ps2eeas`, then `objcopy -L`.
  A source that matches in a hand-run compile can still differ in the image.

- **Flip a callee's declared return type before rewriting a near miss's body.** A discarded result still steers register allocation and
  scheduling around the call. `mutate.py` now tries `void` to `int` on `extern "C"` callee declarations (and back, when every call is a
  statement of its own): on 119 near misses of score 3 or less, with the same seed and 50 compiles each, the earlier rewrites found 0
  matches and the extended set found 4, all four by the return-type flip (one also with an explicit tail `return;`).
- **A save-pattern profile separates compiler builds statistically**, not sharply: `scripts/build/prologue_profile.py` shows the SDK range
  saves registers with `sd` only, game code mixes `sd` and `sq`, but 17 of 366 SDK functions use `sq` and 10 of 52 functions after the
  SDK end are `sd`-only. Use it to spot ranges worth a second look, not to draw unit boundaries.

## 2026-10-28: Sly 2 code is not Sly 1 code

- Different compiler setup (`sd`/`ld` register saves), real C++ (8-byte vtable slots, the vtable pointer at `+0xC`), regrouped classes
  and vectors passed by value in 128-bit registers (`aN_qw`). Expect changed signatures and moved fields; a C++ up- or downcast is
  not a type error.
- **Names and offsets from Sly 1 are leads, not facts.** A field named for a Sly 1 offset (`s1_0x...`) is that offset in Sly 1, not in Sly 2.
- **A decompiler drops VU masks**: `vmul.xy` comes out as a three-component product. Check vector lengths against the disassembly
  before trusting a rewrite.

## 2026-10-28: finding the SDK

- **Library members can be found by comparing code with the relocated fields masked** (call targets, `%hi`/`%lo` halves, `$gp`
  offsets) and a three-word unrelocated anchor. 122 exact members from SDK 2.4 covered 242 of 751 functions in the SDK range.
- **A stub shared by several members names nothing**: a bare `jr $ra` of 28 bytes fits 13 members. Only take a name that is unique at
  its address.
- **Sly 2 was linked against a newer SDK than 2.4**: libdma, libpad, libmc, libmpeg and libpkt have no exact member, so those need a
  later SDK build before they can be named this way ([name-recovery.md](../build/name-recovery.md)).

## 2026-10-28: sound

- The sound library is 989snd, a build **without MIDI**: banks and streams only. The engine runs on the IOP, from a module embedded
  in the executable, not from the disc's `IOPRP300.IMG`.
- The banks are not files: the disc's ISO 9660 listing has four entries and the banks are read by raw sector. A scan for the bank magic
  finds each bank twice, the raw copy and a compressed copy that starts with the same literal bytes. A parser that "mostly works"
  on the second copy is reading compressed data ([sound-banks.md](../game/sound-banks.md)).
- Version 3 banks read with the version 2 layout of OpenGOAL's 989snd (ISC) without changes: tone, LFO and play-sound structures,
  17 grain types.

## 2026-10-28: VU1

- **There is no debug information** in the executable (no DWARF, `.mdebug` or line sections), so names come from the code around.
- **The `.DVP.overlay.*` sections are zero-filled placeholders.** The microcode is in `.vutext`; programs are uploaded as overlay
  chunks of at most 256 instructions, one instruction apart in `.vutext` (pitch 257). To place an uploaded chunk, compare it with every
  instruction offset, not only the 16-byte aligned ones: a program can start on an odd instruction.
- **Entry addresses are not constants in the code.** Only one function builds `MSCAL` words inline, as
  `(byte address) >> 3 | 0x14000000`; the rest come from packets. A run that logs the VIF1 uploads and starts finds them all
  ([vu1-microcode.md](../game/vu1-microcode.md)).
- Lower-word values `0x14000000` and `0x70000000` in the microcode are constants embedded in code, not instructions.

## Tools and environment

- **Slicing a memory-mapped file with an open end copies the rest of it**: `image[offset:]` on a 2.7 GB disc image made a scan run for
  twenty minutes. Slice a bounded window.
- Run scripts with the repository's venv (`.venv/bin/python`) when they need `pyelftools`; the system `python3 -I` runs the ones that do not.
- macOS `sed -E` has no `\s`; use Python for anything non-trivial. zsh has no `mapfile`: use bash 5 for scripts that do.
- A build directory remembers the absolute path it was configured in; moving or renaming the repository breaks it. Configure a new one.

## Reported by other PS2 decompilations, not tested here

Each of these comes from another project's notes (Bokura no Kazoku, Ratchet & Clank 1) built with related compilers. Verify before relying on one. (The callee return-type flip from the same notes is tested, see above.)

- **VIF packet writers are inline functions, not macros**: `inline u32 *PUT(u32 v) { u32 *p = PKT; PKT = p + 1; *p = v; return p; }`
  gives "load pointer, bump, store pointer, store value" with the pointer re-read every time. `*PKT++ = v` reorders. It needs
  `-fno-strict-aliasing`.
- **A loop that retail does not strength-reduce** can be written `goto test; body: ...; test: e = &T[j++]; if (...) goto body;`.
- **A dead store kept in retail is a load-order clue**: write the load before the stores.
- **Clamps**: `v = v < lo ? lo : (v > hi ? hi : v);` gives the branchy shape; `if`/`else if` chains and inline helpers if-convert to `movz`.
- **Re-test every stuck function's best source after any discovery** (a compiler flag, an assembler change, a new rewrite): saved
  snippets re-run in seconds.
- **Check a converted data piece against retail on its own**: compare the object's linked section with the retail bytes at the piece's
  address. It finds every bad conversion in one build where the image diff shows only the first shift. Literal order follows the first
  user in the source, split rodata pieces need their `.align`, and a jump table can land 8 bytes late after an included data block.
- **Compile a library's own source unmodified and compare every function with every unmatched one of the same size**: matches fall out
  without knowing names (libgcc's `fp-bit.c` and `libgcc2.c` did).

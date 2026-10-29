# Compiler identification: Sly 2 (SCUS-97316)

2026-10-22. A feasibility test for proving chosen decompiled functions byte-exact.

**Result: SN Systems ProDG ee-gcc 2.95.3, cc1plus "GNU C++ version 2.95.3 SN BUILD 1.36 for Playstation2 (ee)"
(decomp.me id `ee-gcc2.95.3-136`), flags `-O2 -G0 -ffast-math -fno-exceptions`.** Confidence: high for the
compiler family and build, high for -O2, -G0 and -ffast-math, medium for -fno-exceptions (one piece of evidence, see
below). All 21 hand-written test functions match byte for byte. Sly 1 was built with the earlier SN 2.95.2 v2.73a,
so Sucker Punch stayed with SN ProDG and upgraded it.

Working files are in `work/compiler-test/`, toolchains in `work/toolchains/`. Both are git-ignored and hold
game-derived data.

## Evidence from the binary

Prologue survey (`work/compiler-test/survey.py`) over all game functions, Sly 2 0x100000-0x2319E8 against Sly 1
0x100000-0x1E0000:

| feature | Sly 2 | Sly 1 |
|---|---|---|
| functions with a frame / leaf without one | 4,663 / 1,022 | 2,919 / 856 |
| frame size a multiple of 16 | 4,663 of 4,663 | 2,919 of 2,919 |
| `$ra` saved with `sd` / `sq` | 4,656 / 0 | 0 / 2,909 |
| `$ra` saved below / above the s-registers | 3,741 / 70 | 0 / 2,452 |
| s-register saves with `sq` (count of saves) | 10,795 | 7,711 |
| s0 at the highest offset / the lowest | 2,391 / 0 | 3 / 1,737 |
| `$fp` saved as a callee-saved register / `move $fp,$sp` | 231 / 1 | 186 / 0 |
| `$f20+` saved with `swc1` | 543 functions | 438 |
| `$gp`-relative accesses | 0 | 0 |

(In the 70 "above" cases in Sly 2, the survey counted a later `sw` of an s-register into a local slot as a
save. 0x11C500 is one, and its real prologue has the Sly 2 layout.) Other codegen traits:

- Delay slots are filled. Branch-likely (`beqzl`) is used to put the first epilogue `lq` in the delay slot, and the
  `lq` is repeated in the fall-through path (e.g. 0x12D890, 0x20FA50).
- `c.olt.s` is followed by a `nop` before `bc1t` (an R5900 hazard). The EE's three-operand `mult rd,rs,rt` is used
  for multiplication by a constant (0x15E3A8). llvm-objdump shows it as `<unknown>`.
- Float constants: 2,386 are built inline (`lui`/`ori` + `mtc1`), only 99 are loaded from `.rodata`. The other
  `lwc1 %hi/%lo` loads read globals in `.data`/`.bss`. There are no `.lit4`/`.sdata` sections, so -G0.
- Switch tables: `sltiu` + `sll` + `lui/addiu` of a `.rodata` table + `lw` + `jr`, with the case bodies after the
  `jr` (Ghidra cuts these functions at the `jr`, so their exported sizes are too short).
- C++: virtual calls are `lw vptr,0xC(this)`, `lh delta,8n(vptr)`, `lw fn,8n+4(vptr)`, `jalr` with
  `addu a0,this,delta` in the delay slot. That is the pre-3.0 g++ vtable ({short delta, short index, fn},
  slot n at 8*(n+1)), with the vptr placed after the data members of the first polymorphic class. The this-adjust
  is in the vtable, so there are no thunks (no `j` + `addiu a0` stubs exist). GCC 3.x (Itanium ABI, vptr at 0,
  4-byte slots) and Metrowerks are ruled out by this alone.
- 128-bit values come back in `$v0` (0x1FF4F0: `qmtc2 v0, vf3` after `PosLoWorld`). In SN 2.95.3, `long long` is
  128 bits (TImode): `sizeof(long long)` is 16, `sizeof(long)` is 8, against 8 and 8 in SN 2.95.2. This explains the
  "vectors passed by value in 128-bit registers" seen in earlier rounds.

## Toolchains tried

All are from decomp.me's compiler releases (github.com/decompme/compilers, `values.yaml`). The Sly 1 project's own
bundle (TheOnlyZac/compilers `ee-gcc2.95.2-SN-v2.73a`, which includes the gcc headers) has the same binaries as
decomp.me's `ee-gcc2.95.2-273a` (checked by sha1).

- SN ProDG builds (Win32 .exe): `ee-gcc2.95.2-273a`, `-274`, `ee-gcc2.95.3-107`, `-114`, `-136`. They run on the
  Mac directly through `wibo-macos` (decompals/wibo 1.2.0, x86_64 Mach-O under Rosetta). No Docker or Wine needed.
- Sony/Cygnus builds (Linux i386 ELF): `ee-gcc2.9-990721`, `2.9-991111` (and the a/-01 variants, identical output
  on the probe), `ee-gcc2.96` (2.96-ee-001003-1), `ee-gcc3.2-030926`, `3.2-040921`. These run in Docker under colima
  (`colima start --vm-type vz --vz-rosetta`, i386 binfmt via `tonistiigi/binfmt --install 386`, image
  `i386/debian:bookworm-slim`).
- Metrowerks CodeWarrior: `mwcps2-3.0.1b74-030811`, `mwcps2-3.0b22-020926` through wibo.
- Not run: `ee-gcc3.2-030210-beta2` (Cygwin build) and `ee-gcc2.9-991111b` (Win32; it's the same Sony 2.9 family
  as the Linux 991111 build).

`work/compiler-test/cc.sh <compiler-id> <src> <out.o> <flags>` dispatches to the right runner.

### Probe: saves in a function with calls

For `int f(a,b,c){x=g(a); h(x,b); h(c,a); return x+b+c;}` at -O2 -G0:

| compiler | s-reg width | `$ra` | layout |
|---|---|---|---|
| SN 2.95.2-273a / -274, SN 2.95.3-107 / -114 | sq | sq, top | s0 lowest (Sly 1 layout) |
| **SN 2.95.3-136** | sq | **sd, bottom** | **s0 highest (Sly 2 layout)** |
| Sony 2.9-99xxxx, 2.96, 3.2 | sd | sd | 64-bit saves (neither game) |
| Metrowerks 2.3 / 3.0 / 3.0.1 | sq | sd, top | s3..s0 descending (neither game) |

Only 2.95.3-136 produces the Sly 2 prologue.

## Test 1: Sly 1 decomp sources against Sly 2

The Sly 1 decomp's C sources were compiled with each candidate (`work/compiler-test/build_sly1.sh`). Sly 1's flags
were checked first: with SN 2.73a, 1,182 of 1,242 functions match Sly 1 exactly (the rest are `SKIP_ASM`
placeholders), so the setup reproduces the reference build. Then every function that is exact in Sly 1 and has a
Sly 2 counterpart in `config/recovered/matches.tsv` was compared with Sly 2. Relocated fields are masked. "Shape" means
the same instructions, registers and order with only immediates differing; in the cases checked by hand, those were
struct offsets that moved between the games.

For SN 2.95.3, the Sly 1 headers' `long long` typedefs (ulong, TICK) were changed to `long`
(`sly1_include_long/`). Otherwise those values become 128-bit and 13 files fail with "unsupported wide integer
operation".

| build | exact | shape only | exact + shape | compared |
|---|---|---|---|---|
| **SN 2.95.3-136 -O2 -G0 -ffast-math -fno-exceptions** | **104** | 51 | **155** | 280 |
| SN 2.95.3-136 -O2 -G0 -ffast-math | 102 | 51 | 153 | 280 |
| SN 2.95.3-136 -O2 -G0 (no -ffast-math) | 102 | 51 | 153 | 280 |
| SN 2.95.3-136 -O3 | 82 | 40 | 122 | 280 |
| SN 2.95.3-136 -Os | 88 | 42 | 130 | 280 |
| SN 2.95.3-136 -O1 | 24 | 18 | 42 | 280 |
| SN 2.95.3-107 | 34 | 17 | 51 | 280 |
| SN 2.95.3-114 (original headers) | 30 | 17 | 47 | 247 |
| SN 2.95.2-273a (Sly 1's compiler) / -274 | 42 | 18 | 60 | 306 |
| Sony 2.96 | 26 | 13 | 39 | 251 |
| Sony 2.9-990721 / 991111, 3.2 | mostly fail on the C++ headers, or the Itanium mangling doesn't map | | | |

Every function that matched with 273a also matched with 136 when its file compiled. What 136 misses is code that
changed between the games: different constants, sizes or calls (112 differ in size).

The -fno-exceptions evidence: `vprintf` and `vsprintf` (0x21EBB8, 0x21EC60) have a local object with a
destructor. With exceptions on, 136 adds a cleanup landing pad (40 bytes longer); Sly 2 has none. Sly 1's matching
build has exceptions on, and its copy of these functions has the pad. -ffast-math is needed by FFloatsNear (below);
without it, the comparison takes 92 bytes instead of 56.

## Test 2: hand-written C++ for 21 Sly 2 functions

Sources are in `work/compiler-test/sly2src/t*.cpp` (2003 style: padded structs, 32-bit pointers, `extern "C"` to
keep symbol names plain), the list is in `sly2src/targets.tsv`, and `run_sly2.py` builds and scores them.
E = exact, E* = exact over the whole function where Ghidra's export cuts it short (jump table), S = shape only,
n/m = words differing, szA vs B = size mismatch. Flags are `-O2 -G0 -ffast-math -fno-exceptions` unless noted.

| function | Sly 2 | shape | 136 | 114/107 | 274/273a | 2.96 | 2.9-991111/990721 | 3.2 | MW 3.0.1 |
|---|---|---|---|---|---|---|---|---|---|
| FSwBinocActive | 20F1B8 | getter, compare | E | E | E | E | E | E | E |
| UMinCrv | 1E6610 | float pointer chase | E | E | E | E | E | 2/3 | E |
| AMB_AddRef | 1FC090 | u16 increment | E | E | E | E | E | 3/4 | 3/4 |
| InitTriple (FUN_0020d1b0) | 20D1B0 | store scheduling | E | E | E | E | E | 5/6 | 5/6 |
| SetDefault94 (FUN_001374e0) | 1374E0 | global float copy | E | E | E | E | E | 2/4 | sz |
| PGlobal (FUN_00114220) | 114220 | address of a global | E | E | E | E | E | E | E |
| FindEntry (FUN_001f5ff8) | 1F5FF8 | search loop | E | E | E | sz | sz/E | 13/14 | sz |
| AddWaterExternalAccelerations | 2292D8 | virtual call, slot 71 | E | 2/12 | 2/12 | sz | E | 8/12 | sz |
| DeactivateActadj | 12D890 | virtual call, save, beqzl | E | 6/17 | 6/17 | sz | 6/17 | sz | sz |
| AddJsgeFloat (FUN_001e1088) | 1E1088 | `$f20` saved | E | 4/15 | 4/15 | 11/15 | 6/15 | 10/15 | 10/15 |
| SetBentleyAimState | 1362F8 | branches, global, call | E | 2/15 | 2/15 | E | E | sz | sz |
| EvaluateAcrc | 12B590 | two calls, beqzl | E | sz | sz | sz | sz | sz | 15/19 |
| GetBentleyMode | 135D08 | switch jump table | E* | E* | E* | sz | E* | sz | sz |
| PdlFromSwCid | 15E3A8 | 3-operand mult | E | E | E | sz | E | sz | sz |
| GetSlotValue (FUN_0014ae18) | 14AE18 | mult + load scheduling | E | E | E | sz | E | 7/8 | sz |
| FFloatsNear | 11D4D0 | float abs/max/div/compare | E | E | E | 8/14 | E/sz | sz | sz |
| UCompleteLoop | 1EDD30 | float divides, int to float | E | sz | sz | sz | sz | sz | sz |
| SetSoMass | 1F35C8 | float maths + call | E | 2/11 | 2/11 | sz | sz | sz | sz |
| InitZpr | 1703F8 | 3 saves, memset | E | 10/20 | 10/20 | 18/20 | 10/20 | 13/20 | 14/20 |
| FFilterHitTestDefault | 20FA50 | call + virtual call, repeated lq | E | 5/19 | 5/19 | sz | sz | sz | 14/19 |
| SubPosLo (FUN_001ff4f0) | 1FF4F0 | VU0 asm, 128-bit return | E | 7/18 | 7/18 | 13/18 | 8/18 | 10/18 | 5/18 |
| **exact** | | | **21** | 11 | 11 | 7 | 12 | 2 | 3 |

The sources were tuned against 136, so the other columns weren't given the same chance. The differences in those
columns are structural, though (prologue layout, instruction selection), and source order can't fix them.

Flag variants with 136 on the same 21: -O2 and -O3: 21. -ffast-math dropped: 20 (FFloatsNear). -G8 (default):
19 (globals go `$gp`-relative). -Os: 14. -O1: 6. -fexceptions, -fno-rtti and -g change nothing here.

Matching notes:

- **Statement order matters.** Four functions (InitTriple, AddJsgeFloat, EvaluateAcrc, InitZpr) first matched as
  shape-only: their independent stores came out in a different order. Trying the permutations
  (`work/compiler-test/permute.py`) found the exact order in at most 6 compiles. The order the compiler emits stores
  in doesn't follow the source in any simple way, so this is a permuter job.
- **FFloatsNear needed the original source.** The Sly 1 decomp's version (`g1 > 0 ? g1 : -g1`, `g1 > x ? g1 : x`)
  matches. A hand-written version with `__builtin_fabsf` and `?:` differed in 2 words (`max.s` against a select).
- **VU0 code:** Sly 2's vector code is inline asm with memory and register operands
  (`"lqc2 vf1,%1; qmtc2 %2,vf3; vsub.xyzw vf2,vf3,vf1; sqc2 vf2,%0" : "=m" : "m", "r"`) on a 128-bit
  `long long`, and the values come back in `$v0`. SN's `"j"` (VU_REGS) constraint fails to allocate ("fixed or
  forbidden register vf17 was spilled"), so the original probably doesn't use it.
- Assembler: the SN driver's bundled `as.exe` assembles the VU0 macro ops and produced the exact bytes, so no
  separate assembler is needed.

## Closest build command

```bash
LAB=$PWD  # repository root
TC=$LAB/work/toolchains
$TC/wibo/wibo-macos $TC/ee-gcc2.95.3-136/bin/ee-gcc.exe -c -B$TC/ee-gcc2.95.3-136/lib/gcc-lib/ee/2.95.3/ \
    -O2 -G0 -ffast-math -fno-exceptions -o out.o in.cpp
```

Source: `https://github.com/decompme/compilers/releases/download/compilers/ee-gcc2.95.3-136.tar.gz` (the same files
are in `ps2_compilers.tar.xz`; cc1plus.exe sha1 2e7192cd633a2a04f2a78fe84e4ac0fdbd6867ad). wibo:
`https://github.com/decompals/wibo/releases/download/1.2.0/wibo-macos`. The `.cpp` extension selects cc1plus.
`-x c++` is only needed for `.c` files.

## Functions that matched byte for byte

- **Hand-written:** all 21 above. GetBentleyMode matches over its full 120 bytes, jump-table cases included.
- **Sly 1 decomp sources:** 104 Sly 2 functions are exact when compiled from the Sly 1 decomp's C, and 51 more
  differ only in immediates. The list is in `work/compiler-test/score_detail.tsv` (column
  `ee-gcc2.95.3-136-noeh`). Their sources can be carried over as they are once the Sly 2 struct offsets are in.

Confidence that this is the exact compiler: "SN BUILD 1.36" may not be the exact build Sucker Punch used, since SN
shipped other 2.95.3 builds that decomp.me doesn't have. But a nearby build would have to produce identical code on
every test here, and the earlier SN builds (1.07 and 2.05 of the same 2.95.3) already differ in the prologue.

## What a matching check would need

It looks practical, at a per-function level.

1. **Toolchain**: `wibo-macos` + SN 2.95.3-136, both already in `work/toolchains/`. It runs natively on the Mac
   with no VM, at about 0.1 s per small file. Colima/Docker is only needed for the Sony Linux builds, which are ruled
   out.
2. **A PS2-flavoured header for the function under test.** This is the main cost. Our public C++ is host-oriented
   (64-bit pointers, `VEC4` helpers), so a check needs a 32-bit layout of every struct the function touches, with
   exact offsets (padding). It also needs the vptr after the first polymorphic
   class's members, virtuals declared in vtable order (slot n at 8*(n+1)), `long` for 64-bit and a 128-bit
   `long long`/TImode type for quadwords, plus asm macros for VU0.
3. **Compare**: compile one function per file, mask relocated fields (`R_MIPS_26`/`HI16`/`LO16`), compare against
   the ELF over the export's size (or the object's size for jump-table functions). `work/compiler-test/match.py` and
   `run_sly2.py` do this today. Data and jump-table references are masked, not checked.
4. **Permuting**: independent stores and some scheduling depend on source order, so a small permuter (like
   `permute.py`, or decomp-permuter with this compiler) turns most "shape" results into exact ones.
5. **Scope**: leaf and medium functions (getters, setters, inits, virtual dispatch, float maths, small loops) match
   readily. Large functions will need the usual matching-decomp effort. A realistic target is to prove the
   functions a port relies on (maths, VU0 helpers) rather than everything.

## Unresolved

- Whether other SN 2.95.3 builds (after 1.36) exist and fit better. Only 136 was available.
- -fno-exceptions rests on one file (vprintf/vsprintf). It could be per file in the original build.
- -O2 against -O3 is decided by the Sly 1 sources (155 against 122), not by the 21 hand-written tests.
- **Flag sweep per module (2026-10-28, `scripts/matching/flag_sweep.py`, `flag_report.py`).** 743 unmatched sources and 300 matched ones
  (the control) judged under 16 flag variants. No module prefers other flags: of the controls, -O1, -fno-schedule-insns(2), -G4/-G8,
  -fno-omit-frame-pointer and -fno-delayed-branch each break 78-300 of 300 matched functions; -O3, -fno-peephole and dropping
  -ffast-math break none, so those cannot be told from the base flags with this data (-O3 gives the same code as -O2 on all 300).
  Among the unmatched sources the improvements are one or two functions per module under a different variant each time, which is noise;
  one function (0x1EA6C8) reaches 0, under -fno-schedule-insns, and its module's other functions don't follow. So the build keeps
  `-O2 -G0 -ffast-math -fno-exceptions` for every module.

## SDK range: Sony's gcc 2.9 (2026-10-29)

The libgcc double-precision support (`__adddf3` at 0x23D748, and its neighbours down to `__fixdfsi`) was not built by the
game's compiler. A C analogue of `__adddf3` (`unpack_d(&a,&x); unpack_d(&b,&y); return pack_d(addsub(&x,&y,&z));`, `-O2 -G0`)
gives retail's 22 words exactly with Sony's `ee-gcc2.9-991111b` (Win32, runs under wibo): `s0` saved with `sd` at 0x70,
`$ra` at 0x80, `addiu $a2` in the first delay slot position retail has. SN 2.95.3-136 differs: `sq s0` at 0x80, `$ra` at
0x70, and the `$a0`/`$a2` setup order swapped. So the SDK range needs a per-unit compiler: Sony 2.9-ee-991111 with its
own cc1 and `ee/bin/as.exe`. Reached independently by sly1-decomp's team on Sly 1 (five soft-float functions).
Next: the rest of 0x23D338-0x23E290 and libc/libm units; `compile_unit.py` needs a compiler column in config.

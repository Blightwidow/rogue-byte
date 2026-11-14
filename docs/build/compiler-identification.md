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

- **Second flag sweep (2026-11-06).** Twelve flags the first sweep did not try, chosen because worker reports kept blaming loop hoisting and
  register allocation and because the sister projects (rac3-uya-decomp) use some of them per file: `-fno-force-mem`, `-fno-rerun-loop-opt`,
  `-fno-regmove`, `-fno-expensive-optimizations`, `-fno-defer-pop`, `-fno-thread-jumps`, `-fno-caller-saves`, `-fno-function-cse`,
  `-fno-optimize-sibling-calls` (the compiler rejects it), `-fforce-addr`, `-freduce-all-givs`, `-mno-split-addresses`. Each ran on the 138 near
  misses (best draft 1 to 16, outside the SDK range) and 100 matched controls. None wins: `-no-force-mem` improves 3 near misses and worsens 30, and
  breaks 5 controls; `-mno-split-addresses` worsens 89 and breaks 39; `-freduce-all-givs` brings 2 near misses to 0 but breaks 4 controls, so it
  is a per-function effect and not a setting of the build; the rest change nothing or only hurt. The build keeps `-O2 -G0 -ffast-math
  -fno-exceptions`.
- **The ProDG 3.01 compiler is the one we use (2026-11-06).** The mirror the assembler comes from also ships `ee-gcc2953.exe` and
  `lib/gcc-lib/ee/2.95.3/cc1plus.exe`; its `cc1plus.exe` has the same sha1 as `tools/compilers/ee-gcc2.95.3-136/.../cc1plus.exe`
  (`2e7192cd633a2a...`). So the compiler and the 1.9.25 assembler are one release, and the difference in loop padding (retail pads to five, this
  release to six, [assembler.md](assembler.md) "Short loops") points to a ProDG release that no public mirror has.
- **More flags, the CPU model and the other SN builds (2026-11-06, later).** Thirty-two further options on the same 138 near misses and 100
  controls: `-m5900` and `-mcpu=r5900` give the same code as the build (the default is already the R5900 model); `-mcpu=r4000` breaks 22 controls,
  `-m4650` 14, `-fstrict-aliasing` 16, `-funroll-all-loops` 16, so the scheduler model and these options matter and the build's are right; the
  others (`-mmad`, `-mno-memcpy`, `-fregmove`, `-fschedule-insns`, ...) change nothing. `-fmove-all-movables` and `-freduce-all-givs` over every
  matched non-SDK function (3,257 with a source) and 378 open drafts: `-freduce-all-givs` breaks 183 matched functions, so it is not a build
  setting; `-fmove-all-movables` breaks 12 (0.4%) and takes two open functions to exactly 0 (0x20C0E8 from 62, 0x1BEB28 from 2) and improves 21 more
  (0x17D6C8 from 50 to 5, 0x20F7E0 from 27 to 6), but hurts 22 open ones, and the helped and hurt functions interleave in address order (57
  affected, 35 runs), so it is at most a few files' flag, and per function it is the same kind of exception as `config/us/vu0_regs.txt`
  (docs/contributing/exceptions.md). The other SN compiler builds on disk (2.95.3-107 and -114, 2.95.2-273a and -274) are so far from retail
  that nearly every function changes (158 of 191 controls break, every near miss worsens): the stack layout moves (`sq $s2, 0x20($sp)` against
  `0x40`). `scripts/build/compile_unit.py` reads `EE_GCC_DIR` for such a run (a build never sets it).
- **Two causes ruled out in the source (2026-11-06).** Declaring `g_2dded0` (the frame clock, in 315 drafts) volatile breaks 30 of 145 matched
  drafts and improves 2 of 165 open ones, so it is not volatile. A scan of 564 open drafts for a C that matches up to the end of the shorter
  side finds one real split-boundary error (0x1C7A58: registry size 176, real 180), nine 8-byte SDK stubs whose draft lacks the delay-slot
  instruction, and wrong drafts; boundary errors are not a systematic cause.
- **SDK range under Sony's gcc 2.9 (2026-11-06).** The registry's best score for an SDK-range function comes from the default toolchain, so the
  116 open functions with a draft that are not in `config/us/sony_gcc29.txt` were scored again under `TRY_ASSEMBLER=sony29`: 7 improve, one
  reaches 0 (0x24C360, 192 bytes), the rest stay far. No batch of SDK functions hides there.

## SDK range: Sony's gcc 2.9 (2026-10-29)

The libgcc double-precision support (`__adddf3` at 0x23D748, and its neighbours down to `__fixdfsi`) was not built by the
game's compiler. A C analogue of `__adddf3` (`unpack_d(&a,&x); unpack_d(&b,&y); return pack_d(addsub(&x,&y,&z));`, `-O2 -G0`)
gives retail's 22 words exactly with Sony's `ee-gcc2.9-991111b` (Win32, runs under wibo): `s0` saved with `sd` at 0x70,
`$ra` at 0x80, `addiu $a2` in the first delay slot position retail has. SN 2.95.3-136 differs: `sq s0` at 0x80, `$ra` at
0x70, and the `$a0`/`$a2` setup order swapped. So the SDK range needs a per-unit compiler: Sony 2.9-ee-991111 with its
own cc1 and `ee/bin/as.exe`. Reached independently by sly1-decomp's team on Sly 1 (five soft-float functions).
Next: the rest of 0x23D338-0x23E290 and libc/libm units; `compile_unit.py` needs a compiler column in config.

### SDK soft-float: 12 functions matched (2026-10-29)

`__adddf3`, `__subdf3`, `dpcmp`, `__floatsidf`, `__fixdfsi`, `fptodp` and `func_0023DED0/DF70/DFA0/E108/E1C8/E260` (0x23D748-0x23E290)
match with Sony 2.9-991111b; the byte gate passes with them linked from C. They are libgcc's fp-bit.c: a 0x20-byte `fp_number_type`
(class, sign, exponent, 64-bit fraction at +0x10) on the stack, `unpack_d`/`pack_d` calls. Sources are plain C inside `extern "C"`.
What it took: `double` arguments arrive in GPRs (stored with `sd`); the class field is unsigned (`xori`+`beqz` against 2 and 4
instead of `addiu`+`beq`, `sltiu` for `< 2`), reached through one-line `static inline` predicates (`iszero`, `isnan`, `isinf`)
tested in that order; a `while` loop normalises in `__floatsidf` (a `do`/`while` gives other registers); `in.frac = a` for a
signed `int` keeps the sign-extending `sd`. Still open in the range: 0x23D338 (`pack_d`), 0x23D468 (`unpack_d`), 0x23D508,
0x23D808 (`__muldf3`), 0x23DAB0, 0x23DC18, 0x23DFF8, and the libc/libm units around them.

## Flag sweep over the near misses (2026-10-30)

348 near misses (score 1 to 9) judged under 12 flag sets (`COMPILE_FLAGS`, sources unchanged): `-O2` base; `-O1` and `-O3`; and `-O2` with `-fno-delayed-branch`, `-fno-schedule-insns`, `-fno-schedule-insns2`, `-fno-gcse`, `-fno-strength-reduce`, `-fno-peephole`, `-fno-cse-follow-jumps`, `-fno-rerun-loop-opt`, `-fno-expensive-optimizations`. None helps systematically: `-O1` improved 18 and worsened 270, `-fno-delayed-branch` 4 and 307, `-fno-schedule-insns2` 19 and 240, the rest are neutral or worse. `-fno-schedule-insns` improved 29 (three reached 0) and worsened 193, but 34 of the 53 already matched functions in the same modules break under it, so those three are coincidences, not a per-file flag. The default (`-O2 -G0 -ffast-math -fno-exceptions`) stays.

The diffs of the same 348 near misses by kind (`work/matching/cluster/` is local): 85 differ in branch layout (shared exits, delay-slot content), 83 in order plus register choice, 54 around a `nop`, 41 in instruction selection or extra instructions, 31 involve VU asm, 29 in scheduling order only, 28 in register choice only. Only three differ in the callee-saved save order alone. The commonest moved instructions are the argument setup around calls (`addiu`, `daddu`) and `sw`/`lw`: there is no single dominant wall.

## libmpeg on other Sony builds (2026-11-08)

Hypothesis: the libmpeg functions (`func_0024C670` score 13, `func_0024C4B0` score 94) were built by another Sony gcc, because two volatile hardware
stores sit in delay slots that 2.9-991111b never schedules there. Both drafts were compiled `-O2 -G0` with every Sony Linux build under Docker (colima or
Docker Desktop, `i386/debian:bookworm-slim`, `ee-gcc -x c++`) and judged with `compare.py`:

| Compiler | `func_0024C670` | `func_0024C4B0` |
| :--- | :--- | :--- |
| 2.9-991111b (`try.py`, baseline) | 13 | 94 |
| 2.9-991111, 2.9-991111-01 | 13 | 94 |
| 2.9-990721 | 53 | 111 |
| 2.96 | 345 | 103 |
| 3.2-030926, 3.2-040921 | 285 | 106 |

Negative: the Linux 2.9-991111 output equals the Win32 991111b one, and every other build is worse. The delay-slot stores are not a compiler-version effect.

## SDK range assembled in reorder mode (2026-11-09)

Hypothesis: Sony's SDK objects were
compiled without delay-slot filling and assembled by GNU as in reorder mode, which fills each slot itself. Measured with Sony 2.9-991111b
and its own `as.exe`, `-O2 -G0 -fno-delayed-branch` against the build's `-O2 -G0` (`SONY_COMPILE_FLAGS`, read by `compile_unit.py` and part of
the scorer fingerprint when set; a build never sets it), over every SDK-range function in `config/us/sony_gcc29.txt` matched in `src/` (224
controls, not whole files) and every open SDK draft (109, registry status `tried`):

| Set | Better | Worse | Same | Reach 0 |
| :--- | ---: | ---: | ---: | ---: |
| 224 matched controls (all at 0 with the build's flags) | 0 | 216 | 8 | 8 stay at 0 |
| 109 open drafts (3 errors) | 3 | 81 | 22 | 0 |

Negative: the build's delay-slot filling by the compiler is right for the range. The three that improve (0x23D338 83 to 75, 0x2418C8 77 to
71, 0x243CB0 166 to 148) stay far and are scattered across libraries, so no library hides a reorder-mode build. Under the build's flags none
of the 109 open drafts reaches 0 either; their scores are the drafts', not a toolchain wall.

## SDK range on other Sony 2.9 builds (2026-11-12)

Hypothesis: the SDK range was not all built by one compiler build; libraries may date from different Sony toolchain updates. Komasia's
sly2-decomp (no licence: ideas only) names `ee-gcc2.9-991111-01-dtls13010` in its setup list, the one decomp.me build we did not have
(`work/toolchains/`, from `github.com/decompme/compilers/releases/download/compilers/ee-gcc2.9-991111-01-dtls13010.tar.gz`). Measured with
the Linux builds under Docker (`scripts/matching/cc.sh`, `-O2 -G0`, `-I include`), judged with `compare.py`; the language follows the file
extension (`.c` as C: a `.c` source built as C++ compiles but gives other code). Build 2.9-991111-01 is the control: it reproduces the
Win32 991111b output on every function tried.

The dtls13010 wrappers export `LD_LIBRARY_PATH` to their bundled glibc 2.3.6, which breaks the `env bash` of the nested wrappers under a
modern glibc. The local copy was patched to `ld-2.3.6.so --library-path <dir>` instead (untracked, `work/`).

Matched controls (the 225 functions of `config/us/sony_gcc29.txt` that have a source; 145 from `data/matching/src/fn/`, 80 from `src/`):

| Build | Controls at 0 | Notes |
| :--- | ---: | :--- |
| 2.9-991111-01 (control), 2.9-991111a | 225 | the same output |
| 2.9-991111-01-dtls13010 | 223 | loses `__floatdisf` (0x23C078, 0 to 4) and newlib scalbn `func_00249EE0` (0 to 6); gains none |
| 2.9-990721 | 179 | loses 46, in libc, libm, libpad, libkernel and libmpeg (0x24B828: 7); its gains are SN-built functions and small stubs |
| 2.96 | 10 of 145 | far worse (first run, before the 80 from `src/`) |

Of the 90 matched SDK-range functions built with the default toolchain, 9 (0x256298 up: Construct*, Splice code) cannot compile under
Sony's gcc at all; they are game code, not SDK.

Open drafts (98 registry `tried`, not blockers), control against dtls13010: 94 compile under both, 87 score the same. Better: 0x24C670
13 to 5 (libmpeg), 0x24B480 29 to 27, 0x248CA8 78 to 76, 0x245B58 258 to 257. Worse: 0x247DE8 124 to 132. None reaches 0. Three drafts do
not compile as written (0x2333B4 and 0x256CE8 use a 128-bit `long long`, 0x254CA0 has a parse error at line 9); 0x24BF40 has no draft.

Negative, with one open lead: no matched function needs another build, so there is no evidence that the range was built by more than one
Sony 2.9 compiler. dtls13010 is the same compiler for 223 of 225 controls and differs on exactly two libraries (libgcc fp-bit
`__floatdisf`, newlib scalbn), which is the only sign of a build difference by library. The libmpeg controls (0x24B540, 0x24B760, 0x24B8F8,
0x24C360, 0x24C420) score 0 under both builds, so they do not say which one built libmpeg. `func_0024C670` stops at 5 words under
dtls13010: seven source variants (a `ctrl` or `status` temporary, a hoisted constant, a local volatile pointer, `>> 14 & 1`, a volatile
store) leave the same diff: retail holds the IPU_CTRL address in `$v1` and the value in `$v0` at 0x24C6BC, the build the reverse. That is a
register-allocation order, not a source form. It does not count as a match.

## SDK range: findings of wave A1 and its follow-up (2026-11-12)

Wave A1 attempted every function still untouched on `main` (184, 146 of them in the SDK range); four follow-up agents then took the causes
that came back from more than one function. Evidence: `work/matching/waves/A1*/`, `work/matching/followup/` (local), commits `12ce952a`
to `f5413b76`.

### `nop; nop` before `div.s`: Sony's 2.9-ee-991111-01 writes it (corrected 2026-11-14)

- **Retail:** in the SDK range, all 27 `div.s` have exactly two `nop`s before them, and none sits in a delay slot. They are in eight libm
  functions: atanf, `__ieee754_acosf`, `__ieee754_asinf`, `__ieee754_atan2f`, `__ieee754_fmodf`, `__ieee754_powf`, `__ieee754_sqrtf`,
  `__kernel_tanf`. The matched libm functions (cosf, `__kernel_cosf`, `__kernel_rem_pio2f`, `__kernel_sinf`...) have no `div.s`, so the
  rest of libm is ordinary 2.9-991111b code. Game code differs: of its 408 `div.s`, 331 have no `nop`, 45 one, 32 two.
- **The build:** `2.9-ee-991111-01` and `2.9-ee-991111-01-dtls13010` (decompme/compilers; Linux i386 programs) write `nop; nop; div.s` and keep
  `div.s` out of delay slots; 991111a and 991111b (the build of the rest of the SDK range) write a plain `div.s` and fill delay slots with it.
  Probe: a function with two float divides, `-S -O2 -G0` (`work/matching/divprobe/`, local). Sly 1's `docs/toolchain/still-to-qualify.md`
  found the same for its libm (OpenRAC builds Sony's libm objects with 991111-01 as well). The 2026-11-12 wave A1 wrote that 991111-01 "has no
  such option"; that was wrong, and the eight `toolchain` rows it put in `config/matching/walls.tsv` are removed. The two builds give identical
  objects here.
- **Scores** with 991111-01 on the drafts (`-x c++ -O2 -G0`, before the 991111b score): `__ieee754_acosf` 173 to **0**, `__kernel_tanf` 72 to
  **0** (both landed), atanf 39 to 8, `__ieee754_asinf` 66 to 42, `__ieee754_fmodf` 33 to 26, `__ieee754_atan2f` 184 and `__ieee754_sqrtf` 69
  unchanged; `__ieee754_powf` (0x248038, 2,176 bytes) has no draft yet.
- **In the build:** `config/us/sony_gcc29_01.txt` lists the functions built with it (a function joins once a source matches only with it);
  `compile_unit.py --assembler sony29-01` runs the Linux compiler through `linux_runner()`: nothing on x86 Linux, `docker run --platform linux/386
  i386/debian:bookworm-slim` otherwise (Docker Desktop's CLI is `/Applications/Docker.app/Contents/Resources/bin/docker`), or the command in
  `EE_LINUX_RUNNER`. The toolchain is `tools/compilers/ee-gcc2.9-991111-01` or `work/toolchains/ee-gcc2.9-991111-01` (the decompme archive
  `ee-gcc2.9-991111-01.tar.xz`, not committed). Without the toolchain or a runner `configure.py` leaves those functions' objects out and says so;
  `link_image.py` takes them from assembly and the image still matches (measured: 5,498 functions from C instead of 5,500, `PASS`).

### `mult1` and `multu1` come from plain C

- Sony's gcc 2.9 emits `mult1`, `multu1`, `mfhi1` and `mflo1` itself, from its 3-operand and `multu` patterns (`mulsi3_mult3_r5900`,
  the `%H` suffix of the machine description). No helper is needed; a worker that says "needs a mult1 helper" has not tried the C.
- **Which multiply gets the `1`:** the suffix alternates in RTL emission order within a block. The first independent multiply stays
  `mult`, the next becomes `mult1`; the scheduler may then reorder them, which is why retail 0x242F70 shows `mult1` ahead of `mult`.
  Which one is first follows operand and expression order, so swap the addends before suspecting anything else.
- **Measured:** `__muldi3` (0x23C7C0) 19 to 15 by writing the cross sum as `low(a) * high(b) + high(a) * low(b)`; what is left is register
  choice and scheduling. 0x23A598 (`(u64)a * 0x8CA0000 + (u64)b * 0x8CA0000 / 1000000`, a seconds-and-fraction to tick count) reproduces
  `multu1`, `mfhi1`, `mflo1` and its whole shape from that one line: 8, one temporary in `$v1` where retail has `$a2`. 0x242F70 gets
  `mult` and `mult1` from a typed `Group { Slot slots[4]; }` table (39; the m2c draft had folded both products into one).
- **Scoring caveat:** 0x23C7C0 and 0x23A598 are not in `config/us/sony_gcc29.txt` (an address joins it once a source matches with
  Sony's gcc), so try.py and nonmatching/ score them with SN's compiler, which never emits `mult1`. Measure them with
  `TRY_ASSEMBLER=sony29`.

### `umul_ppmm`: one `multu` with two results

`__divdi3` (0x23B7F8, 17) and `__udivdi3` (0x23C828, 32) have one `multu` followed by `mfhi` and `mflo` into two separate 32-bit
registers (an unsigned 32x32 to 64-bit product read as two words). Plain C always splits it: `(u64)q * d >> 32` gives `multu` and
`mfhi`, the low word `q * d` a 3-operand `mult`, and a `u64` or union product adds `dsll32`/`dsrl32`/`or` (40). The extra `mult` costs a
register, which shifts the quotient from `$a1` to `$a2` across the function. A shared helper (one `multu`, two outputs) would be the
form; it has two users. `__udivdi3` also has a 16-byte frame with no `$sp` access, which no plausible local reproduced.

### Prologue save order

- **0x23FE78 matched** once its callee had its real signature. The draft declared `char *func_0023F850(void)`; the callee reads `$a0`
  (`move $17,$4`), and retail calls it with `limit`, already in `$a0`, so no move shows in the bytes. Declaring
  `char *func_0023F850(unsigned)` and passing `limit` changes the dependence graph, and the `sd s6`/`sd s7` order flips to retail's.
  The drafts whose retail saves the lower register first may have the same missing argument: 0x237EA8, 0x252148, 0x23F2D8, 0x23AE70,
  0x245178, and 0x23F850's own draft.
- **0x237BD8 is a tie.** In the sched2 dump (`-dR -fsched-verbose-5`; this compiler spells it with `-5`, not `=5`), `sd s1` (insn 476)
  and `sd s0` (insn 478) both have priority 12 and three dependents, so insn order picks `s1`; retail's `sd s0` first would need `lui s0`
  at priority 12 or more, and it has 11. Every callee signature checks out, and C, 991111-01 and dtls13010 leave it at 5 (990721: 55).
  Recorded in walls.tsv as `tie`.

### Delay-slot stores under Sony's gcc

- A `volatile` store never fills a delay slot; a plain one does. `sceDmaReset` (0x241468) matched with a volatile read and a plain
  `*(int *)0x1000E010 = ...` for the store retail puts in the `jal memclr` slot (the same as the packet-writer lesson for a read,
  docs/contributing/lessons.md). Its walls.tsv row is gone.
- The other `toolchain` rows of the SDK range (0x24B480, 0x235780, 0x24C4B0, 0x24C670, 0x2540B0) were measured on 2026-11-08, before
  Sony's gcc was found for the range. Re-run them with `TRY_ASSEMBLER=sony29` and the plain-store form before trusting them.
- 0x2539D0's row was not a delay-slot wall: its slot stores are plain field stores the draft already places, and its 37 words are the
  frame (0x50 against 0x60) and an `sra` where retail has `srl` (an unsigned field). The row is removed. InitIpu (0x254CA0) scores 6
  under Sony's gcc (30 under SN), only the `lq`/`sq` register choice.

### `$gp` as an ordinary register

13 SDK functions (3,760 bytes) swap `$gp` around an indirect call or store it as a value; no C form exists without a register pin. They
are the `gp` blocker kind since 2026-11-12: docs/build/vu0-mmi.md.

### Other results

- `pow` (0x2452C0), `__ieee754_pow` (0x246300) and the powf wrapper (0x245B58) matched under Sony's gcc: plain `double` types so the
  compiler makes the soft-float calls, `dpcmp` called explicitly, constants as `static const double` literals the literal pool places,
  `fabs` and scalbn called by address (`func_00249C28`, `func_00249EE0`) so they are not expanded inline. `__ieee754_pow` fails under SN:
  `-ffast-math` folds `y - y`.
- `0x2325E0` was listed in sony_gcc29.txt by mistake: retail saves with `sq`, and SN's compiler matches it (removed from the list).

# Name recovery (the first stage)

Transfers function names from the Sly 1 decomp onto Sly 2 by matching code, as a starting point for reverse
engineering Sly 2.

1. `work/elf/`: `SCUS_971.98` (Sly 1 USA, sha1 57dc305d…) and `SCUS_973.16` (Sly 2 USA, sha1 de2af92a…) from your own discs.
2. Ghidra 12.1.4 + ghidra-emotionengine-reloaded, headless (`JAVA_HOME=/opt/homebrew/opt/openjdk@21`):
   - Sly 1: `-import work/elf/SCUS_971.98 -processor r5900:LE:32:default -preScript ApplySplatSymbols.java config/sly1/sly1_symbol_addrs.txt -postScript ExportFunctions.java work/export/sly1.jsonl`
   - Sly 2: `-import work/elf/SCUS_973.16 ... -postScript ExportFunctions.java work/export/sly2.jsonl`, then
     `-process SCUS_973.16 -noanalysis -preScript CreateFunctionsAt.java config/recovered/sly2_vtable_targets.txt -postScript ExportFunctions.java work/export/sly2.jsonl`
     (the methods only reachable through vtables)
3. BSim features (both programs): `-process <program> -noanalysis -postScript ExportBsimFeatures.java work/export/<game>_bsim.jsonl`
4. `python3 scripts/names/match.py work/export/sly1.jsonl work/export/sly2.jsonl config/recovered/ work/elf/SCUS_971.98 work/elf/SCUS_973.16 work/export/sly1_bsim.jsonl work/export/sly2_bsim.jsonl`,
   then `python3 scripts/names/check.py`.
5. Second name source: `python3 scripts/names/bevy_names.py <sly2-bevy-of-thieves>/bevy_of_thieves/src work/export/sly2.jsonl config/recovered/`, then
   `python3 scripts/names/combine.py config/recovered/` merges the Sly 1 matches (`matches.tsv`), the Rust-port names and the provisional names (`provisional_symbol_addrs.txt`) into `config/recovered/sly2_combined_symbol_addrs.txt` (generated, git-ignored; `make elf` rebuilds it).
6. Into the Sly 2 project: `-process SCUS_973.16 -noanalysis -preScript ApplySplatSymbols.java config/recovered/sly2_combined_symbol_addrs.txt`
   (renames functions, labels globals, and puts each name's source and score in the plate comment).
7. Types: `python3 scripts/names/demangle.py config/recovered/sly2_combined_symbol_addrs.txt config/recovered/` demangles the GCC 2.95 names into `config/recovered/sly2.h`
   (C prototypes, opaque structs; compiles with `clang -fsyntax-only -x c`) and `config/recovered/sly2_signatures.json`, applied with
   `-process SCUS_973.16 -noanalysis -preScript ApplySignatures.java config/recovered/sly2_signatures.json`.
   `python3 scripts/names/demangle.py --test` runs the demangler tests. `DecompileFunctions.java <addresses>` prints decompiled C.
8. Suspect signatures: `-process SCUS_973.16 -noanalysis -postScript FlagSignatures.java config/recovered/sly2_signature_flags.tsv <--annotate|--repair> config/sly1/sly1_inheritance.json`
   (conflict: a parameter passed to a typed callee that expects another type; missing: undeclared argument registers
   read; unused: declared parameters never read), then rerun `scripts/names/demangle.py` to mark them SUSPECT in `sly2.h`. `--repair`
   fixes the clear cases in rounds (adds the missing parameters, retypes a conflicting one when every call agrees and the
   callee is trusted, at most once per parameter) and logs each change to `config/recovered/sly2_signature_flags.tsv.repairs.tsv`.
   `config/sly1/sly1_inheritance.json` (298 classes, from ProjectCane's and the Sly 1 decomp's headers) keeps C++ up/downcasts
   (JT passed as STEP) from counting as conflicts.
9. Struct layouts: type the Sly 1 project too (`python3 scripts/names/demangle.py --all config/sly1/sly1_symbol_addrs.txt config/recovered/sly1/`, then
   ApplySignatures on Sly 1), export field accesses from both (`-readOnly -postScript ExportFieldAccesses.java
   work/export/<game>_fields.jsonl`), then `python3 scripts/names/field_layout.py config/recovered/` (aligns the accesses of matched pairs into
   `config/recovered/field_map.tsv`), `python3 scripts/names/struct_layout.py config/recovered/` (`config/recovered/sly2_structs.json`, `config/recovered/sly2_structs.h`, named from
   `config/sly1/sly1_decomp_fields.json`) and `-preScript ApplyStructs.java config/recovered/sly2_structs.json`.
10. Added parameters: `-postScript TypeParameters.java --evaluate|--apply <log.tsv> config/sly1/sly1_inheritance.json`
    types the in_* parameters from the typed callees they reach and the typed values callers pass.
11. 128-bit parameters: `-postScript QuadwordParameters.java config/recovered/sly2_quadword_parameters.tsv` (back up first), then
    rerun FlagSignatures with `--annotate`.
12b. Methods inside classes: `python3 scripts/names/class_methods.py config/recovered/ [--evaluate]` aligns each mapped class pair's own methods
    in vtable order and writes `config/recovered/class_method_pairs.tsv`; scripts/names/match.py applies them late, as 'slot' seeds.
12c. Sly 2-only code: `python3 scripts/names/sly2_only.py config/recovered/` writes `config/recovered/sly2_only.tsv` and `config/recovered/sly2_only.md` (clusters of
    consecutive functions with no Sly 1 match and best BSim cosine under 0.3, labelled from the Rust port's modules,
    strings, named callees and classes).
12a. Class diff: `python3 scripts/names/class_diff.py config/recovered/` reads Sly 2's class table (0x2BAAE8) and Sly 1's vtable headers and
    writes `config/recovered/class_diff.tsv` / `config/recovered/class_diff.md` (the Sly 2 class tree with each class's Sly 1 counterpart).
12. Struct returns: `-postScript StructReturns.java --detect|--apply <out.tsv>` (back up first): a hidden result buffer
    in a0 when the function returns parameter 0, writes through it, and reads the argument register after its declared
    ones.

Output: `config/recovered/sly2_symbol_addrs.txt` (splat format), `config/recovered/matches.tsv`, `config/recovered/report.md`. Names are unverified.

Findings so far: Sly 2 is built with a different compiler setup (sd/ld register saves vs sq/lq), so only library code
matches word for word; and its object system is real C++ with 8-byte (pointer, 0) vtable slots whose classes were
regrouped (base tables of 89 slots vs Sly 1's 27/46/81), so vtable slots don't transfer by position.

Results (2026-10-20): 770 Sly 2 functions named (12.1% of 6355; 19.3% of the Sly 1 decomp's named functions). Call-graph
consistency 91-98% per method except `class` (71%). Independent check against the address comments of
[sly2-bevy-of-thieves](https://github.com/Campfirecrucifix/sly2-bevy-of-thieves) (MIT): of 18 overlapping functions, 15 agree
in meaning, 1 looks wrong (a `class` match), 2 can't be judged.

BSim cosine is one-sided evidence: true pairs whose body changed between games often score low (bottom quartile
0.04-0.36), unrelated pairs almost never score high, so it only raises a match score.

Combined (2026-10-20): 1217 Sly 2 functions named (19%): 770 Sly 1 names, 91 Rust-port names, 356 Rust module hints
(`bevy_<module>_<address>`), plus 289 globals. Where both sources cover a function (97), the Rust file agrees with the
Sly 1 name's subsystem in almost every case (camera `Cm*` in camera/cm.rs, `Jt*` in player/, math in camera/math.rs).

Types (2026-10-20): 586 prototypes, 220 opaque structs, all Sly 1 names demangled. Parameter lists are Sly 1's and can be
wrong for Sly 2 even when the name is right (CalcCmAdjust's first parameter is used as a VECTOR, not a CM).

Signature flags (2026-10-20): 183 of 588 typed functions flagged, 116 high. None of the 56 byte-identical (`exact`)
functions is flagged, so the checks raise no false alarm on unchanged code. A high flag means the parameters changed in
Sly 2 or the name is wrong; rates follow the match method's risk (vtable 67%, global 31%, bsim 13%).

Signature repair (2026-10-20): the class tree removed 27 false conflicts (116 -> 89 high); repair converges in 5 rounds
with 87 parameters added and 48 retyped in 82 functions, none of them byte-identical to Sly 1; 24 high suspects remain
for a human (they need a different name or a hand-written signature). Example: CalcCmAdjust's first parameter is now
VECTOR *, and its decompiled body no longer casts it.

Struct layouts (2026-10-20): 157 Sly 2 structs, 601 fields mapped from Sly 1 (93 with a decomp name, the rest named
s1_0x<Sly 1 offset>) and 543 seen only in Sly 2 code; 1046 placed in Ghidra. Fields move in blocks (JT's state block:
Sly 1 0x2200-0x2244 is Sly 2 0x18C0-0x18E0). Independent check: the Rust port's comments agree at jts 0x18C8, jtbs
0x18D0, t_jtbs 0x18D4, the cane block from 0x18C0 and the hang SMP at 0x199C. Sly 2 objects carry a GCC 2.95 vtable
pointer at +0xC (virtual calls read a short this-adjustment next to the method pointer). ProjectCane's headers can't
give PS2 offsets (std::shared_ptr, std::vector, 12-byte glm::vec3 members).

## Tools considered

- [rea](https://github.com/morluto/rea) (2026-10-20, v6.5.0): not adopted. Its Ghidra provider refuses the PS2 executable
  ("Machine-specific MIPS variants ... need a separately supported processor profile"), also with
  `REA_GHIDRA_LANGUAGE_ID=r5900:LE:32:default`. Even with a profile, it imports into an ephemeral database (no persistent
  functions, signatures or structs), loads extensions only from the Ghidra install, and matches functions by exact bytes
  only. Revisit if it gains an R5900 / PS2 profile.

ProjectCane names (2026-10-20): member order matches the decomp 95% of the time but raw PS2 offsets only 23% (hidden
vtable pointer, replaced members); anchored to decomp fields and checked against Sly 1 accesses, leave-one-out gives
81% exact. 33 Sly 2 fields now carry a `pc_` name; two agree with the Rust port independently (pc_tJtbs at 0x18D4,
pc_jtbsHangLatch at 0x18F8).

Parameter types (2026-10-20): blind test on the byte-identical functions' parameters: 77 right, 0 wrong, 9 silent
(once the decompiler's generic int/long register types are ignored). Applied to the 83 parameters the repair added:
14 typed (VECTOR *, MATRIX3/4 *, DL *, LSG *...), 69 have no informative use and stay undefined.

128-bit parameters (2026-10-20): Sly 2's math passes vectors by value in 128-bit registers where Sly 1 passed VECTOR *
(CalculateVectorPanTilt builds one value from all of a0 and runs VU instructions on it). 31 parameters moved to aN_qw
storage; high suspects 24 -> 14. VU_FLOAT is a 32-bit scalar (_qmtc2(in_a2_lo)), VU_VECTOR by value a 128-bit register;
a function returning a struct by value takes a hidden return pointer in a0 (operator*(const MATRIX4 &, VU_FLOAT)), not
modelled. Known plugin artifact: the EE plugin describes qmtc2 as reading 32 bits (the hardware moves 128), so three
byte-identical VU helpers (VecCombo, two operator*) stay flagged; they are not signature errors.

Struct returns (2026-10-20): rare. Negative control on Sly 1 (whose signatures are the decomp's): 2 detections, both
true matrix products (MatMulMatTransMat, operator*(MATRIX4, MATRIX4)), nothing else fires. In Sly 2: 1 modelled,
operator*(const MATRIX4 &, VU_FLOAT) -> MATRIX4 *(MATRIX4 *ret, MATRIX4 *, VU_FLOAT); StartGame (no declared parameter)
excluded, its evidence only says it takes a pointer. Sly 2's math mostly passes and returns vectors in registers.

Vetoes (2026-10-20): scripts/names/match.py rejects a game name landing in Sly 2's SDK block
(0x2319E8-0x256CE8; library prefixes like snd_ exempt, Sly 1's 989snd client is mangled too), a BSim match on a stub
under 4 instructions, and a small helper with 10x the callers (config/recovered/vetoed.tsv). Removed: SetSoNoInteract,
CloneLoHierarchy, FOpenFile (and OnRailAdd, re-paired); 13 names appeared as freed slots re-paired (779 Sly 1 names).
ClearNames.java takes withdrawn names off the project (config/recovered/sly2_withdrawn.tsv). Re-running the repair now keeps its
once-per-parameter rule across runs (it reads the repair log), after a re-run flipped AdjustCmCpdefi back.
Lesson: ApplySignatures re-applies Sly 1 signatures over repairs; give it only the newly named functions.

Class diff (2026-10-20): Sly 2 has 199 classes (177 with a vtable), Sly 1 143 vtables. The vtable per Sly 2 class
is the LAST store at +0xC in its factory (constructors run base first); checked against the Rust port's 79
cid -> vtable pairs: 75/79 (taking the first store: 51/79). Fixed-role slots: Init is Sly 1 slot 0 (132 vtables) /
Sly 2 slot 6, LoadFromBrx Sly 1 slot 10 (140) / Sly 2 slot 13. Sly 1 classes are named after their own Init/Load
signature (a vote over all methods named 8 vtables LO). Mapping by role matching + method votes, then checked: 8 high
(our layout ends within 0x20 of the Sly 2 size: SPIRE, VOLBTN, BLIPG, EMITTER, CNVO, ACCMISS, HSHAPE, LASEN), 14
medium, 5 rejected (layout overflows the class, or a weaker duplicate). The Rust port's class descriptions contradict
some medium ones (cid 105 FRAGILE is a motion trail there, cid 113 DART an object-path list, cid 14 a rail polygon).
No own method of any mapped class is byte-identical between the games; 2,612 of 2,739 own methods have no Sly 1
counterpart yet. The bottleneck for the shared engine is method matching inside classes, not the tree.

Order pass (2026-10-20): scripts/names/match.py's `order` pass pairs the functions between two anchors that are
neighbours in both games (Sly 2 keeps the order inside a source file), gated by BSim cosine >= 0.3, with size-ratio and
call-count vetoes. +57 names (779 -> 836 Sly 1 names; 1,274 named functions in all). Every new name the Rust port can
judge agrees (RefEvalIf/Cond/Case -> form_if/cond/case, RefSetBinding -> set_binding, the Jt edge functions in its
player code); the sequences come in source order (RefOpSqrt, Sin, Cos, Tan; CMpeg; CProg::Begin/End). Call-graph
consistency 0.64 (base 0.89-0.98): kept, but the weakest pass. The mutual-best BSim pass is in scripts/names/match.py but
disabled: the sweep showed its pairs disagreeing with the call graph MORE as its threshold rose (cos 0.5: 50% below 0.5
consistency; 0.7: 83%; 0.85: 100%), the clone families BSim can't separate. Sweep: order gate 0.3/0.5/0.7 x mutual
0.5/0.7/0.85, MATCH_SWEEP="order,mutual" reproduces it. After the refresh: 642 typed, 105 repaired, 15 suspects.

Class methods (2026-10-20): Sly 1 vtables were cut to their 11 LO slots (the parser stopped at the first null slot);
with nulls kept they have a median of 72 slots and a readable interface (0 Init, 1 SetDefaults, 2-5 Add/Remove, 8-9
Clone, 10 LoadFromBrx, 13-14 messages, 16 PostLoad, 17-19 Update, 36-38 Render), and the class diff rises to 15 high /
19 medium. Only 4 slots map globally between the games (0->6, 10->13, 16->14, 17->15), so methods are aligned per
class pair in slot order (scripts/names/class_methods.py). Blind test: 19 of 34 hidden known pairs re-paired, 0 differently. +20
names (836 -> 856), all named after the class they sit in (InitHnd, CloneVolbtn, OnHbskAdd/Remove, STEPGUARD's
detect/zap). A slot name is only as good as its class mapping (cid 105 FRAGILE is doubtful).
Lesson: the matcher is greedy and order-sensitive. Applied first, the 18 seeds re-routed the cascade and lost 14
good names (LoadLoFromBrx moved off the base loader 0x231170, which 19 vtables share); applied late, nothing is lost.

Pilot EMITTER (2026-10-20, `docs/pilots/emitter/`): decompiled the 7 Sly 2 methods and compared them with ProjectCane's
Sly 1 C++. The emission logic (kind derivation, per-kind rates, pauses, density) is identical; the own members are the
same list with object references removed (moved into the shared EMITB template) and 20 bytes added, so the own size
is 0x80 in both games; the loader is the real per-game difference. `FUSION.md` has the member table and per-method
verdicts, `emitter_fused.cpp` a fused PostEmitterLoad sketch. Across the 29 mapped classes, own size is identical in
5 and within 0x40 in most; base classes changed most (ALO 0x2D0 -> 0xE0). For a non-matching C++ engine, memory
offsets don't need fusing: members, logic and file formats do.

Sly 2-only map (2026-10-20): of 6,355 functions, 727 matched (out of the SDK), 548 SDK, 2,752 unmatched but similar to
some Sly 1 function (likely changed counterparts not found yet), 2,328 Sly 2-only. 410 clusters, 58 of 10+ functions.
Largest: the generated splice property accessors (385 functions, 0x101608-0x110AB0), aiming and targeting
(player/p5_target), loot and pickpocketing (oidBooty), job flow and character switching (oidPoCurrent, fVault),
binocucom, checkpoints, new file-format readers. Labels are hints from the Rust port and strings, not verified.

Pilot loot (2026-10-20, `docs/pilots/loot/`): first Sly 2-only module. Class 103 (vtable 0x2CBBA0, sizeof 0x190), its 7-state
machine, the guard's pickpocket (class 37 slot 50), Sly's side and the save variables, from 25 functions. `loot.h` /
`loot.cpp` in ProjectCane style (core logic reconstructed, guard/render/save parts summarised); the Rust port agrees on
every state, the 5 s drop return and the flight time. Plugs into the shared engine at a few points (two JT members,
one guard virtual, a world pool, save variables); the cost is the ~25 engine calls still unnamed.

## Name evidence

Names come in two kinds, kept in different files:

- **Evidenced:** `matches.tsv` (a Sly 1 decomp name moved over by code matching: `sly1-exact` is a byte-identical function, the
  strongest; `sly1-<method>` is a heuristic: callers, calls, bsim, global, order, class, slot, strings, vtable) and the Rust port's
  address comments (`bevy_functions.tsv`, `bevy_globals.tsv`; sly2-bevy-of-thieves, MIT).
- **Provisional:** `provisional_symbol_addrs.txt` (3,292 names): readings of the code, reviewed (high and medium confidence only),
  with nothing outside the code behind them unless a line also carries a `sly1:` or `bevy:` tag. They name unnamed functions and
  override a weaker match; treat them as provisional, not as Sucker Punch's own names. `config/matching/symbol_addrs.txt` tags its
  own additions `source:provisional` the same way.

`combine.py` merges both into the generated `sly2_combined_symbol_addrs.txt`, tagging every name with where it came from
(`source:sly1`, `source:bevy`, `source:bevy-module`, `source:provisional`).

## SDK libraries (2026-10-28, `scripts/sdk/identify_sdk.py`)

Retail linked Sony's static libraries into the executable, so a library member (one object file) sits in it as a run of code that
equals the member's `.text` except where the linker filled in a call target, a `%hi`/`%lo` half or a `$gp` offset. The tool reads
libraries from a directory the user keeps (it never copies or publishes them; we used the `sce_ps2_sdk_24` mirror, SDK 2.4 with
GCC 2.95.2/2.95.3 libc, libm and libgcc), masks the fields the member's relocation table marks, and finds each member in the SDK range
by a three-word anchor. `config/recovered/sdk_identified.tsv` lists what matched (address, bytes, library, member, places, symbols).

| | |
| :--- | :--- |
| Exact members | 122 of 237 members with code, from libc, libm, libgcc, libgraph, libcdvd and libkernl |
| SDK functions inside them | 242 of 751 (42.6 of 152 KB) |
| Names | 150 functions without a name get Sony's own (`config/recovered/sdk_symbol_addrs.txt`, `source:sdk`): named 4,104 -> 4,254, SDK range 204 -> 354 of 751 |
| Control | of the 75 SDK functions that already had a name and are in a matched member, 67 agree (the 8 others are aliases or wrappers: `AtoiPchz`/`atoi`, `RFU091`/`GetEntryAddress`, `logf`/`log10`) |

Only a name that is unique at its address is taken: a stub shared by several members (a bare `jr $ra`, 28 bytes at 0x238D40 fits
13 of them) names nothing, and names already used elsewhere (`Copy`, `kCopy`) are left out. Libdma, libpad, libmc, libmpeg and libpkt
have no exact member: Sly 2 was linked against a newer SDK than 2.4, so those need a later SDK build. `--near 0.8` also reports members
that differ in a few words (libgraph `graph028` 0.96, libcdvd `cdvd014` 0.95, libgcc `dp-bit` 0.94): different build or small fixes, to be
looked at by hand before any name is taken from them.

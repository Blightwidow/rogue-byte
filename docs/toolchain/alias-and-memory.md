# Alias and memory: why a load moves past a store

Derived from the Sly 1 decomp's docs/toolchain/alias-classes.md (AGPL-3.0-or-later, same maintainers); mechanisms measured on Sly 1's compiler, not yet re-measured on Sly 2 unless marked **measured here**.

`sly1:func_XXXXXXXX` ids are Sly 1 functions: they show the shape of a case, not a Sly 2 address. Sly 2 is not Sly 1 recompiled
([lessons.md](../contributing/lessons.md) section 3), so every lever below is a hypothesis to try, scored by `try.py`.

## 1. The rule that lets a load pass a store

GCC 2.95 (SN 2.95.3) has no `-fstrict-aliasing`. The first scheduler pass (sched1) may swap a load and a store only when it proves they
cannot overlap. It has three proofs:

1. **Different bases.** `base_alias_check`: two addresses built on different known bases (a different argument register, a global against
   the frame) do not alias.
2. **Same base, constant offsets** that do not overlap.
3. **`fixed_scalar_and_varying_struct_p`.** A memory reference flagged `MEM_SCALAR_P` at a *fixed* address never aliases one flagged
   `MEM_IN_STRUCT_P` at a *varying* address.

Which flag a reference gets comes from the C expression:

| Expression | Flag |
| :--- | :--- |
| member (`p->f`), array element (`a[i]`) | in-struct (`/s`) |
| declared scalar variable: a global `float D`, a scalar local living in memory | scalar (`/f`) |
| dereference of a cast pointer (`*(u128 *)&v`, `((u128 *)&m)[i]`, `*(s32 *)((u8 *)p + 0x40)`) | none: conflicts with everything it cannot separate by base |

Dumps made with `-dS` print `/s` and `/f`, so the flag is checkable.

**What loses a pointer's base.** An argument register has a base (its address is the argument). `(plus R const)` keeps R's base only when
R carries `REGNO_POINTER_FLAG`: a declared pointer local has it; an inline function's copy of `this` or of a pointer parameter does not
(except the element at offset 0). A pointer loaded from memory, a pseudo set more than once, and an index-plus-pointer sum have no
base and are taken to alias every frame store.

**After reload** `sp+n` counts as a varying address, so the fixed-scalar proof is gone and sched2 keeps sched1's order of frame stores
against pointer loads. The order has to be right in the insn stream, before sched1.

Dependences only run forward in insn order. Inline-function arguments expand in two passes: arguments that are themselves inline calls
first (in parameter order), plain memory references (`Q(*p)`) second. So `Vec::Of(x)` loads before a store to a scalar slot and `Q(x)` loads
after it.

## 2. Symptom to source lever (Sly 1 cases)

Try the lever; keep it only if the score drops and the rules in AGENTS.md still hold (section 5).

| Diff symptom | Lever | Sly 1 case |
| :--- | :--- | :--- |
| a global's load stays below a vector store | write the store as `*(Vec *)&x` (in-struct) | `sly1:func_00175170` |
| a global read as an 8-byte member waits | declare it as a scalar `s32 D` (`*(s32 *)&D` does not work) | `sly1:func_00175170` |
| a global array element loads below pointer stores | declare a scalar `float D` | `sly1:func_001CDB70` |
| the opposite on PAL: pointer global hoisted, retail waits | declare it as an array and read `D[0]` | `sly1:func_eu_001AEC90` |
| corner pointer loads wait for a slot store | read them as members of one record (`struct { P *corner[3]; }`) | `sly1:func_00191C78` |
| rows wait for stores through `Mat *frame = &self->rot` | use `self->rot` directly | `sly1:func_001B7D00` |
| pointer field loaded after frame stores | read it first in the source | `sly1:func_001A2D88` |
| inline pointer or reference parameter loads wait | declare a pointer local (`Vec *b = ...`): it is flagged | `sly1:func_001A2830` |
| cse1 reloads a pointer retail shares | declare the pointer once per loop, set once | `sly1:func_001D7778`, `sly1:func_00139740` |
| retail reloads a frame local after a store through a pointer parameter | one pointer variable at the top, set at several places | `sly1:func_00187260` |
| a global record's load placement | struct copy `V b = D;` rises, `Q(b) = Q(D)` waits | `sly1:func_0019ED58` |
| field load before an address calc | a scalar local `Item *cur;` whose address is passed, not a struct member | `sly1:func_00188270` |
| a weight slot stored too early (retail stores it last, in the call's delay slot) | pass `Scalar(x)` straight into the call; helpers return `Q((s128)r)` | `sly1:func_001D87C8` and 7 more |
| three loads of one stack word plus an empty slot | `volatile` type on a DMA copy (a hardware-shared buffer only: AGENTS.md volatile rule) | `sly1:func_001FA6B0` |

**Scalar slot, cast form.** Retail's scalar slot is an expand-time temporary that g++ makes when a type-changing cast (`u128` to `s128`)
is bound to a reference parameter: `Q((s128)r)`. A same-type cast is not an lvalue and makes none; a plain `u128`, `Slot` or `Vec` local passed
the same way is purged to a register or flagged in-struct. The tell: retail's slot store comes last, ours first. A probe with a `volatile u128`
proves a scalar slot is needed; then look for the cast form. The cure usually needs both halves: a scalar store and an in-struct load.

The `volatile` row applies only to data shared with hardware; elsewhere it is steering and not allowed.

## 3. "Store order follows source order" is wrong

It is true only for ties. The sched1 rank is: priority (critical path), `INSN_REG_WEIGHT` (a SET counts +1, stores included; each
`REG_DEAD`/`REG_UNUSED` counts -1, so the store of a dying value goes first), class, number of dependents, then LUID (source order).
A store with no dependents is a filler and sinks. "Source order" also means the *expanded* insn stream, not the lines you typed (inline
arguments expand in two passes, section 1). Consequences:

- a typed member against a cast offset changes the alias flag, so the schedule, not only the style (this agrees with lessons.md "a store
  through `*(s32*)((u8*)self + 0xNNN)` schedules differently");
- the direction varies per case: a global as a scalar helped in one function and as an array in another; try both;
- extra or missing parameters, a `void` against a value-returning callee, named temporaries and dead stores are code inputs, because
  they change the candidates sched1 sees and the anti-dependences sched2 keeps (parameter order sets the order of argument moves);
- a variable set twice goes to global-alloc and merges conflicts and preferences: a fresh named temporary splits it.

## 4. Sony 2.9 against SN 2.95.3

Sony 2.9-ee-991111b (the SDK range) and -01 (libm divides) do have **type-based alias sets**; SN 2.95.3 does not. In Sly 1, the SDK
functions matched when a union member (alias set 0, conflicts with everything) held the packet word and the id sat in a local
(`sly1:func_001F8290`, `sly1:func_001F7BE8`). For the SDK range, a union or `char`-typed access is a second lever, besides the base rules
of section 1. For game code none of the type tricks apply: only the flags and bases above.

## 5. How this meets our rules

The AGENTS.md tie-break says: of two wordings that both score 0, land the typed one (a member over a cast offset, a shared type over a
local one). That is consistent with section 1: a member gets the in-struct flag, so the lever and the rule usually point the same way.
Where they split:

- **Search is free to use a cast offset or a local pointer** to find which flag the retail schedule needs. A match with a cast offset
  stays allowed; add the member to the shared header and re-prove if a typed form also scores 0.
- **A pointer declared once** (a normal local) is ordinary code. A pointer that only moves a register is not (AGENTS.md "Also not allowed").
  The test is whether the original plausibly had that variable.
- **Scalar slot casts** `Q((s128)r)` are shared-helper territory (`include/vu0inline.h`): a helper's body is the only place for the form.
- **Not allowed as a lever:** an empty `asm` barrier, a register pin, a `volatile` outside the hardware rule, a padding local.

## 6. Diagnosing with our tools today, open questions

- `regalloc.py ADDRESS SOURCE` names the pseudo and the allocator behind a register diff. A diff that is only *order* (a load above or
  below a store, the same words) is this page's case; classify with `classify_diffs.py` first.
- `permute_stores.py` and `permute.py` search store orders inside straight-line regions; they find a source order but cannot change
  a flag. `neighborhood.py` / `mutate.py` rewrites do not yet include the flag changes of section 2 (member, scalar global, array global,
  declared pointer, cast offset).
- Reading flags: compile the unit to assembly with the project's own `compile_unit.py` path and dump RTL (`-dS` style) to see `/s` and `/f`.
  Not yet verified for SN 2.95.3 here; **measured here** entries would go in this list when done.
- Open: does SN 2.95.3 on Sly 2 sources set the same flags for a vtable-adjusted `this`? Is the scalar-slot cast form needed by any
  Sly 2 near miss (the Sly 2 passes vectors by value in 128-bit registers)?
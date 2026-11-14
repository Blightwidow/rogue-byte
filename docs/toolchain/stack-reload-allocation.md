# Stack slots, reloads and register allocation

Derived from the Sly 1 decomp's docs/toolchain stack-slots, reloads-and-stores, long-block-constants, large-functions and conditional-moves (AGPL-3.0-or-later, same maintainers); mechanisms measured on Sly 1's compiler, not yet re-measured on Sly 2 unless marked **measured here**.

Ids `sly1:func_XXXXXXXX` are Sly 1 functions, cited as evidence of a mechanism only. Nothing here names a Sly 2 function.
Every lever is plain C++ that AGENTS.md allows unless a row says otherwise. Barriers, register pins, padding arrays and
invented types stay out ([AGENTS.md](../../AGENTS.md), [lessons.md](../contributing/lessons.md) section 2).

Diagnosis, in order: `try.py` diff (which words differ), `scripts/matching/regalloc.py ADDRESS FILE.cpp` (which pseudo holds each
differing register, which allocator placed it), then the raw dumps it keeps (`--keep DIR`): `.lreg` (after local-alloc),
`.greg` (after global-alloc and reload), `-dp` insn numbers.

## 1. Stack slots

- Locals that are BLKmode (structs, arrays) or have their address taken get a slot from `assign_temp`; the slot is freed at
  the end of the block and the free list is reused (best fit). The frame grows in allocation order and is rounded to 16.
- An inline call's frame is one BLKmode temporary of the callee's saved frame size; its unused locals still count
  (`sly1:func_00125138`).
- A by-value result passed to a call: the call's return slot is taken before the arguments' (`sly1:func_001DEBE8`).
- Out-parameters and address-taken scalars are purged after the slots made at expand time, so they sit last.
- A 1-byte object gets a slot at once; an unused `s32` or `bool` gets none. A slot nothing touches means a declared object
  (`sly1:func_00187F40`, `sly1:func_0017D5D8`).
- Vec-like BLKmode types share freed slots; TImode (`u128`) values get their own.
- A later block's locals are placed by best fit in the holes an earlier block left, so a 16-byte difference far above can
  be an earlier local that was bigger (`sly1:func_00125C90`).

| Symptom | Lever |
| :--- | :--- |
| All offsets after one point shifted by 16 | An earlier local or inline frame was bigger or smaller: simulate the free list; try the struct type retail's code implies |
| Untouched 16-byte slot | A declared struct the original plausibly had (AGENTS.md: a type only, never a padding array) |
| Out-parameter slot lands first instead of last | Pass the address of a local declared in a different scope, or return by value instead |
| 1-byte hole | A `bool`/`char` local that is address-taken; unused `s32` will not give one |
| Frame right, body right, slots swapped | Declaration order across blocks; hoist a block's local to function scope or the reverse |

Diagnose: `scripts/matching/frame_diff.py` ([search-tools.md](../contributing/search-tools.md)) prints the frame next to
retail's; read each shifted offset as "which earlier allocation was bigger".

## 2. Reload rotation and spill registers

- No strict aliasing here: a store at a byte offset lets CSE keep `m->flags` in a register, a member store forces a reload
  (`sly1:func_001590A0`).
- `finish_spills` sorts the function's spill registers by number; `allocate_reload_reg` starts one past `last_spill_reg`. One
  extra spill register anywhere shifts every later reload in the rotation (`sly1:func_001E31F0`).
- An `"rV"` style constraint keeps a MEM for the reload instead of a register.
- `reload_cse` turns a repeated add into a move and deletes one of three adds of one address (`sly1:func_001C3C98`).
- jump2 cross-jumping runs after reload and can delete a case that hid a reload (`sly1:func_001F2840`).

| Symptom | Lever |
| :--- | :--- |
| One reload takes `a0` where retail takes `v0`, later ones all shifted | Find who made `a0` a spill register (below); change that pseudo's class costs so global-alloc keeps it |
| Spilled value reloaded into the wrong register after a call | A named stride or local (`s32 slotSize = sizeof(T)`) can swap `v1`/`v0` (`sly1:func_0017ECE8`) |
| Reload where ours has a pseudo | A hidden rotation step: a second spill register from a rematerialised constant (`sly1:func_0014C858`) |
| Reload of `self->field` missing | Member access instead of `*(s32*)((u8*)self + N)`, or the reverse |

Diagnose, **measured on Sly 1**: grep the `.greg` dump for `Spilling reg N.` lines. Each `Spilling for insn K.` block lists
that insn's spill registers; a register number that appears once in the whole function (`Spilling reg 4` is `a0`) points at the
insn that created it. Then check the pseudo's costs in `.lreg` (`regclass` lines) and use regalloc.py's allocator column.

## 3. Local-alloc and global-alloc priorities, long blocks

- local-alloc priority is about `floor_log2(refs) * refs / life`; pseudos it cannot place go to global-alloc `find_reg` in
  its own printed order. A "utilized poorly" scan can evict a whole register.
- `find_equiv_reg` reuses only the nearest earlier load; `REG_N_REFS` is never recounted after CSE.
- `cse_basic_block` restarts every 1001 insns, so in a 9000-insn block the CSE windows decide which constants are shared
  (`sly1:func_00109488`, matched with a source form that holds all ten landmarks).
- In a loop, local-alloc's tie can beat global-alloc's ranking (`sly1:func_00131F60`); a copy preference makes
  global-alloc's first pass skip a register another allocno prefers (`sly1:func_0013A618`).

| Symptom | Lever |
| :--- | :--- |
| Two registers swapped, nothing else differs | A ranking flip: change refs or life of one pseudo (a split variable, one more or fewer use) (`sly1:func_001DEBE8`, `sly1:func_0020CAF8`) |
| Constant held in a register in one half of a long block | Where the 1001-insn window boundary falls: move statements between windows, or macro against table |
| Loop counter shared with the outer variable | A counter of its own for the earlier loop (`sly1:func_001D5678`) |
| Flag and vector swap `v0`/`v1` | Write the flag as a value: `s32 still = a && b && c;` (`sly1:func_001BC978`) |

Diagnose: regalloc.py names the allocator (local, global, reload) and the likely lever per differing register. Method from
Sly 1: score the allocated pseudos, not the bytes.

## 4. Brace-initialiser CLOBBER records

- `static Record r = { ... };` memsets, then stores in field-offset order. A union member at a group's first offset makes
  expr.c emit `(clobber (mem/s:BLK))`, which splits the stores into two sched1 groups; reload deletes the CLOBBER (it is in
  `.lreg`, not in `.greg`). Zero members are skipped before it.
- Hence "source order" seen in near misses is the scheduler's: write the fields in **offset order**.
- A wall of "two constants' `%hi` issue in one cycle" or "one object's stores interleave with another's" can be this, when
  the objects are constant-initialised vectors (`sly1:func_0013A618`, `sly1:func_0013A940`).
- Matched as brace initialisers: `sly1:func_001D5FA8`, `sly1:func_001D60B0`, `sly1:func_001D61C8`, `sly1:func_0018A510`,
  `sly1:func_001EC190`.

Note the tension with [lessons.md](../contributing/lessons.md) ("Struct initialisers call memset: assign fields one by one"):
that holds when retail has no memset; when retail memsets a static or local record then stores constants, the brace form is
the plain C++ that reproduces it.

| Symptom | Lever |
| :--- | :--- |
| Retail memsets the record, then stores | Brace initialiser; fields in offset order |
| Stores of one record split by one insn that emits nothing | A union member at the group's first offset |
| Guard `=1` placed oddly | Guard is set after the constructor, always |

Ruled out on Sly 1: setters, constructor parameters, label tricks, `-g`, sub-records, base class, `volatile`.

## 5. Large functions

- Matrix through an object pointer, `*(u128*)&v = x` for a 128-bit copy, the fallback pointer named first, `>?` and `<?`
  with the constant first; `FillMemory`, `CopyBytes`, `MoveMemory`, `CopyStringBounded` take `void*` (each a separate case in
  the original).
- A running sum crossing calls is a spilled `u128` loaded at each use (`sly1:func_0017E088`).
- A pointer field's type picks its store's partner (`sly1:func_002042C8`).

Diagnose: classify the diff (`classify_diffs.py`), then the sections above by shape; large functions are usually two or
three of these at once.

## 6. jump.c conditional moves

- movsicc is tried before store-flag (R5900 `BRANCH_COST` 1): a single-SET `if (c) x = k;` becomes a conditional move on
  every jump pass; jump.c reruns after cse2 only when `cse_main` returned nonzero.
- `gen_conditional_move` forces the constant into a register for GT and LE and swaps operands (`slt t, K, c`, then
  `movn`/`movz`); `gen_int_relational` uses `slti`.
- `bool`, `char` and `short` promote to SImode and change the shape.

| Retail | Source |
| :--- | :--- |
| `li K; slt t,K,c; movz` (constant in a register) | `s32 v = 99; if (c < 99) v = c;` (`sly1:func_00149190`) |
| `slti 100; movn` | `(c > 98) ? 99 : c` (folds to MIN_EXPR) |
| `slti 99; movz` | `if (c >= 99) c = 99;` (GE, not the clamp above) |
| `beqzl` branch kept | if/else storing in each arm |

Diagnose: look at the `slt` operand: constant in a register as the first operand means LE through movsicc. A preset of the
fallback after cse2 can rerun jump.c (`sly1:func_00156718`).

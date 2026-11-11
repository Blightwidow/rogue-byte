# VU0 and MMI: permanent blockers

Sly 2's vector code uses the R5900's VU0 macro mode (`lqc2`, `sqc2`, `qmtc2`, `qmfc2`, `vadd`, `vmul`, `vmadd`...) and its multimedia
instructions (MMI: `pextuw`, `pcpyld`, `prot3w`...). GCC 2.95.3 for the EE has no C form for them. This page records what that costs,
what was tried, and the decision (2026-11-04): these functions are **permanent blockers**, as in sly1-decomp. Rules: [AGENTS.md](../../AGENTS.md); the earlier allowances:
[contributing/exceptions.md](../contributing/exceptions.md). Since 2026-11-11 a function with the compiler's frame whose VU0, MMI and
system instructions are at most 5% of it is not a blocker: it is compiled C matched with the shared helpers of `include/ps2inline.h` and
`include/vu0inline.h`, listed in `config/us/inline_functions.tsv` and counted as to-do ([inline-asm-helpers.md](inline-asm-helpers.md)).

## The size of it

Measured on the retail disassembly (`build/splat`, 2026-11-04), over the 1,691 functions not matched yet:

| Kind | Functions | Bytes | Share of unmatched bytes |
| :--- | ---: | ---: | ---: |
| VU0 or MMI instruction in the body | 646 | 408,400 | 53% |
| COP0 or system instruction (`mfc0`, `ei`, `sync`, `eret`) | 9 | 1,420 | under 1% |
| Plain code | 1,012 | 354,000 | 46% |

By size the VU/MMI functions are 305 small (up to 400 bytes), 246 medium and 95 large. If every plain function matched and no VU/MMI
function did, matched code would stop at about 70% of the code bytes.

## Why C cannot reach them

- **No C form.** The compiler has no VU0 arithmetic and no MMI builtins. Retail's code contains the instructions, so the original source
  had them in some form, most likely inline asm in macros.
- **Lane moves.** Moving one lane of a 128-bit value to an FP register (`mtc1`/`mfc1` after `lq`) has no C expression either.
- **Scheduling around the asm.** In retail the moves between general registers and VU registers sit in branch delay slots and between
  other instructions. Inline asm blocks keep GCC from scheduling like that, and the saves and frame layout around them differ.
- **Delay slots.** A VU0 instruction in a branch or `jal` delay slot is something an assembler in `.set reorder` mode decides, not the
  compiler. `ps2eeas` would not put a COP2 instruction there (it padded with `nop`s); a plain GNU `as` did, but lacked the hazard `nop`s and loop padding. Not measured for `bin/ee-as.exe`.

## What was tried here (2026-10 to 2026-11-03)

About 540 matched sources used inline asm for these instructions before the rule changed. The constructs, with the evidence for each, are
in [contributing/exceptions.md](../contributing/exceptions.md) ("Allowed before 2026-11-04"):

- inline `asm` blocks with `"r"`, `"m"` and `"=m"` operands, and fence tokens to order blocks;
- `"j"` operands (the compiler's VU register class) on `QW` variables, compiled with `-mvu0-use-vf0-15`
  (`config/us/vu0_regs.txt`): the compiler allocates the `vf` registers and emits the `lqc2`/`sqc2`/`qmtc2`/`qmfc2` moves itself, which
  reproduced retail's delay-slot moves in about 25 functions that no plain asm block reached;
- a pass that moved a VU0 instruction into the delay slot of the branch after it, because `ps2eeas` would not.

All of it is gone since 2026-11-04: 236 matched functions with inline asm (62,632 bytes) and 11 with `volatile` on plain data went back
to assembly.

## The decision: permanent blockers (2026-11-04)

As in sly1-decomp, whose function list tags `vu`, `mmi` and `handwritten` functions as blockers ("permanent for C: no inline asm") and counts
original assembly as finished apart from the exact C:

- `scripts/classify_blockers.py` (`make blockers`, after `make elf`) writes `config/us/blockers.tsv` (address, name, size, kind) from the
  disassembly: `vu` (a VU0 macro instruction), `mmi` (a multimedia instruction), `system` (COP0 or a system instruction: `mfc0`, `ei`, `sync`,
  not `break`, which the compiler emits for a division by zero) and `handwritten` (`config/us/handwritten_asm.txt`). 853 functions on
  2026-11-04.
- Since 2026-11-09 a fifth kind, `remnant`: a chunk of the split that is not a function. Nothing in retail reaches it (no `jal`, `j` or
  branch target, no data word, no `lui`+`addiu`/`ori` pair, not the entry point) and it has no control-transfer instruction, so no
  compiled function can be it: an epilogue left behind (`addiu $sp,$sp,N; nop`) or one or two leftover instructions. 162 chunks, 2,640
  bytes. The control: every one of the 5,333 matched functions is reached or returns (9 are unreached but return), and the same reference
  check reaches 5,325 of them. sly1-decomp's audit of 2026-11-07 calls the same thing remnants. 1,015 blockers in all.
- A blocker stays **assembly**: it is built from the original assembly and is never matched in C. No inline asm, no exception.
- It is **left out of the work queues**: `list_functions.py` skips it (`--blockers` shows it, `--status blocked` lists only them) and
  `claim.py init` skips it. `work/report.json` gives it the status `blocked`.
- It **counts as finished** in the reports, shown apart from the exact C: `make objdiff` runs `scripts/blockers_report.py`, which sets the
  blockers to 100% in `progress/us/report.json` and recomputes the measures; `pal_report.py` does the same for PAL. The README table
  shows the code and function totals, the share that is exact C, and how many functions and bytes are blocked
  (`progress/us/blockers.json`).
- A function leaves the list only if its instructions change: the table is content-based, regenerated from the split.

The other options (a narrow written asm exception like `Sqrt`, a compiler with VU0 builtins, plain-math rewrites for the port) are not
taken. Two facts are still unchecked: whether any toolchain build has VU0 builtins, and what `bin/ee-as.exe` does with a COP2 instruction
in a delay slot.

What counts as finished here is generous on purpose, like sly1's: the exact-C figure is the one to quote for matching progress.

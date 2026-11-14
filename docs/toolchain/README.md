# Compiler notes

How GCC 2.95 and Sony's 2.9 behave on the code we match, by pass: what the pass does, which source shape moves it, how to see it with our tools.
Distilled from the Sly 1 decomp's `docs/toolchain/` (about 1 MB; AGPL-3.0-or-later, same maintainers) and adapted to this project's tools and rules.
Every page marks what is only measured on Sly 1; function ids written `sly1:func_XXXXXXXX` are Sly 1 functions, not ours. Treat each lever as a
hypothesis until it is measured here, and keep to [AGENTS.md](../../AGENTS.md): a lever that needs a barrier, a register pin or a variable that exists
only to move a register is a diagnostic, not a landing form. The things to try are in [../IDEAS.md](../IDEAS.md).

| Page | Pass or topic | Use it when |
| :--- | :--- | :--- |
| [scheduling.md](scheduling.md) | sched1 and sched2: priorities, tie-breaks, invisible insns, delay slots | the diff is instruction order, after `regalloc.py` says registers follow from it (`sched1.py`) |
| [alias-and-memory.md](alias-and-memory.md) | what lets a load pass a store; member against cast offset; pointer bases | two stores or loads are swapped, a value is reloaded, or a store order 'follows the wrong source order' |
| [loops.md](loops.md) | loop.c hoisting thresholds, loop notes, the vf0-NN flag family | a constant or invariant is hoisted differently, a loop is top- or bottom-tested |
| [cse-and-pre.md](cse-and-pre.md) | cse1/cse2, global CSE and PRE, copy propagation, the early `%hi` | an address or constant is shared or recomputed, or a `move` appears |
| [stack-reload-allocation.md](stack-reload-allocation.md) | frame slots, reload rotation, local/global-alloc, brace-initialiser records, jump.c conditional moves | a frame offset or register is off by one slot, a clamp compiles as a branch |
| [vu0-mmi-and-builds.md](vu0-mmi-and-builds.md) | VU0/MMI helper forms and constraints, compiler builds, libm | writing or changing a helper, or a near miss in the SDK range or libm |

Tools: `scripts/matching/regalloc.py` (registers), `sched1.py` (scheduling), `globalalloc.py` (allocation), `try.py` (score and diff),
`neighborhood.py` (one-edit search): [../contributing/search-tools.md](../contributing/search-tools.md).

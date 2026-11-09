# Docs

Folders: `build/` (setup, pipeline, progress, toolchain evidence, name recovery), `contributing/` (rules, matching, workers, tools),
`game/` (notes on the executable and its formats). Top level: the plan and the procedure.

Start with [build/building.md](build/building.md) to build, or [build/name-recovery.md](build/name-recovery.md) to work on names.
Then [CONTRIBUTING.md](../CONTRIBUTING.md) and [AGENTS.md](../AGENTS.md).

| Page | Read it when |
| :--- | :--- |
| [ROADMAP.md](ROADMAP.md) | what is done and the next steps, in order |
| [PRESERVATION_AND_PORT.md](PRESERVATION_AND_PORT.md) | why preservation comes first and what is added for a later port (shared types, the tie-break rule, blocker notes) |
| [AGENT_WORKFLOW.md](AGENT_WORKFLOW.md) | matching a function from pick to land, for people and AI agents |
| [TOOLCHAIN.md](TOOLCHAIN.md) | which compiler, assembler and flags, in one table |
| [build/building.md](build/building.md) | setting up, `make elf` |
| [build/assembler.md](build/assembler.md) | a function is one instruction off and it is a `nop` (SN's assembler, the loop5 patch) |
| [build/compiler-identification.md](build/compiler-identification.md) | how the compilers were identified, and the SDK range's Sony compiler |
| [build/progress.md](build/progress.md) | regenerating the progress reports and what they count |
| [build/vu0-mmi.md](build/vu0-mmi.md) | why VU0, MMI and COP0 functions are permanent blockers, what was tried (measured 2026-11-04) |
| [build/inline-asm-helpers.md](build/inline-asm-helpers.md) | the open question of blockers that are compiled C (sly1-decomp's reclassification) |
| [build/name-recovery.md](build/name-recovery.md) | rebuilding the Ghidra projects and recovered names |
| [build/decompilation.md](build/decompilation.md) | the decompilation inputs and workflow |
| [contributing/matching.md](contributing/matching.md) | judging a function (what `score` counts), fixing a near miss, the rulings, teams of workers |
| [contributing/exceptions.md](contributing/exceptions.md) | what is allowed beyond plain C and why (`Sqrt`, flag lists, `steer-ok`, data in C) |
| [contributing/queue-worker.md](contributing/queue-worker.md) | you are a worker claiming functions from a wave |
| [contributing/search-tools.md](contributing/search-tools.md) | running the tools that search for a near miss's fix |
| [contributing/lessons.md](contributing/lessons.md) | before matching or touching the tools: what cost time before |
| [contributing/code-cleanup.md](contributing/code-cleanup.md) | adding code to `src/` (the rules and warnings `make cleanup` applies) |
| [contributing/commit-messages.md](contributing/commit-messages.md) | writing a commit message |
| [contributing/decompilation-tips.md](contributing/decompilation-tips.md) | before changing a heuristic or applying names |
| [game/executable-layout.md](game/executable-layout.md) | looking for where something sits in `SCUS_973.16` |
| [game/modules-and-units.md](game/modules-and-units.md) | what a module, a unit, a whole file and a data piece are |
| [game/vu1-microcode.md](game/vu1-microcode.md) | the VU1 microcode in `.vutext` |
| [game/sound-banks.md](game/sound-banks.md) | the sound system (989snd) and its bank format |
| [game/slymods-crosscheck.md](game/slymods-crosscheck.md) | cross-checking against the SlyMods wiki |

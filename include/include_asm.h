/* SPDX-License-Identifier: GPL-3.0-or-later */
/* Whole-file sources (config/us/whole_files.tsv): INCLUDE_ASM(address), at file scope and never inside a function, stands for a function
   that is not matched yet. It leaves a marker in the compiler's assembly that scripts/build/compile_unit.py replaces with that function's
   Splat assembly (build/splat/asm, generated locally by make elf, never committed), so the file assembles in retail's order. */
#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H
#define INCLUDE_ASM(ADDRESS) __asm__(".include_asm " #ADDRESS)
#endif

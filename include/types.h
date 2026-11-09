/* SPDX-License-Identifier: GPL-3.0-or-later */
/* Fixed-width types for the EE, one definition for every source (docs/PRESERVATION_AND_PORT.md, "Changes" 2).
   With the game's compilers int is 32 bits, long 64 and a TI-mode int 128 (a quadword in one register). */
#ifndef SLY2_TYPES_H
#define SLY2_TYPES_H
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long s64;
typedef unsigned long u64;
typedef int s128 __attribute__((mode(TI)));
typedef unsigned int u128 __attribute__((mode(TI)));
typedef int QW __attribute__((mode(TI))); /* a quadword in one 128-bit register */
typedef float f32;
typedef double f64;
#endif

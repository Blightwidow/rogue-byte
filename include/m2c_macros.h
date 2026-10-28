/* SPDX-License-Identifier: GPL-3.0-or-later */
/* What m2c's --valid-syntax drafts need (they compile as C) */
#ifndef M2C_MACROS_H
#define M2C_MACROS_H
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long s64;
typedef unsigned long u64;
typedef float f32;
typedef double f64;
typedef int s128 __attribute__((mode(TI)));
#define M2C_FIELD(expr, type, offset) (*(type)((char *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_STRUCT_COPY(dest, src, size) memcpy((dest), (src), (size))
#define M2C_UNK s32
#define M2C_UNK32 s32
#define NULL ((void *)0)
#define M2C_ERROR(...) 0
#define M2C_CARRY 0
#define M2C_MEMCPY_ALIGNED memcpy
#define M2C_MEMCPY_UNALIGNED memcpy
void *memcpy(void *, const void *, unsigned int);
#endif

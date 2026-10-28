/* SPDX-License-Identifier: GPL-3.0-or-later */
/* Shared basics for matching sources (gcc 2.95, SN ProDG ee-gcc 2.95.3 build 1.36). Grows as functions need it. */
#ifndef SLY2_H
#define SLY2_H
typedef int QW __attribute__((mode(TI)));  /* a quadword in one 128-bit register */
/* C++ linkage on purpose: an extern "C" memcpy is a gcc builtin and gets inlined; the game calls it */
void *memcpy(void *, const void *, unsigned int);
void *memset(void *, int, unsigned int);
struct VECTOR { float x, y, z, w; } __attribute__((aligned(16)));
struct MATRIX3 { float mat[3][4]; };                            /* 4-byte aligned: copies call memcpy */
struct MATRIX4 { float mat[4][4]; } __attribute__((aligned(16))); /* copies are lq/sq */
#endif

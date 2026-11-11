/* SPDX-License-Identifier: GPL-3.0-or-later */
/* Shared basics for matching sources (gcc 2.95, SN ProDG ee-gcc 2.95.3 build 1.36). Grows as functions need it. */
#ifndef SLY2_H
#define SLY2_H
#include "types.h"
/* C++ linkage on purpose: an extern "C" memcpy is a gcc builtin and gets inlined; the game calls it */
void *memcpy(void *, const void *, unsigned int);
/* memset is called by its C name: retail's calls link to `memset`, not the C++ `memset__FPviUi` */
#ifdef __cplusplus
extern "C" void *memset(void *, int, unsigned int);
#else
void *memset(void *, int, unsigned int);
#endif
struct VECTOR { float x, y, z, w; } __attribute__((aligned(16)));
struct MATRIX3 { float mat[3][4]; };                            /* 4-byte aligned: copies call memcpy */
/* copies are lq/sq; row n read or written as one quadword (row 3 is the position in an XF's matrices) */
struct MATRIX4 { union { float mat[4][4]; QW row[4]; }; } __attribute__((aligned(16)));
#endif

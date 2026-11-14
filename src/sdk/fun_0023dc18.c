/* SPDX-License-Identifier: GPL-3.0-or-later */
/* source:sly1-decomp soft_float.c (src/lib, AGPL-3.0, same maintainers), a draft that scores 0 */
#include "types.h"

/* A double taken apart: its kind (0 signalling NaN, 1 quiet NaN, 2 zero, 3 finite, 4 infinity), sign, unbiased exponent and fraction. */
typedef struct Unpacked {
    u32 kind;
    s32 sign;
    s32 exponent;
    s32 pad;
    union {
        u64 ll;
        u32 l[2];
    } fraction;
} Unpacked;

#define IS_NAN(p) ((p)->kind < 2)
#define IS_ZERO(p) (((p)->kind ^ 2) == 0)
#define IS_INF(p) (((p)->kind ^ 4) == 0)

s32 func_0023DC18(Unpacked* a, Unpacked* b)
{
    if (a->kind < 2) {
        return 1;
    }
    if (b->kind < 2) {
        return 1;
    }
    if ((a->kind ^ 4) == 0) {
        if ((b->kind ^ 4) == 0) {
            return b->sign - a->sign;
        }
        return a->sign != 0 ? -1 : 1;
    }
    if ((b->kind ^ 4) == 0) {
        return b->sign != 0 ? 1 : -1;
    }
    if ((a->kind ^ 2) == 0) {
        if ((b->kind ^ 2) == 0) {
            return 0;
        }
        return b->sign == 0 ? -1 : 1;
    }
    if ((b->kind ^ 2) == 0) {
        return a->sign != 0 ? -1 : 1;
    }
    if (a->sign != b->sign) {
        return a->sign != 0 ? -1 : 1;
    }
    if (a->exponent > b->exponent) {
        return a->sign != 0 ? -1 : 1;
    }
    if (a->exponent < b->exponent) {
        return a->sign != 0 ? 1 : -1;
    }
    if (a->fraction.ll > b->fraction.ll) {
        return a->sign != 0 ? -1 : 1;
    }
    if (a->fraction.ll < b->fraction.ll) {
        return a->sign != 0 ? 1 : -1;
    }
    return 0;
}

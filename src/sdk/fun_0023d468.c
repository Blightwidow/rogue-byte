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
#define FLUSH_TINY 1

void func_0023D468(u64* in, Unpacked* out)
{
    u64 bits = *in;
    u64 fraction = bits & 0x000FFFFFFFFFFFFFull;
    s32 exponent = (s32)(bits >> 52) & 0x7FF;

    out->sign = (s32)(bits >> 63);
    if (exponent == 0) {
        if (FLUSH_TINY || fraction == 0) {
            out->kind = 2;
        } else {
            out->kind = 3;
            exponent -= 0x3FE;
            fraction <<= 8;
            while (fraction < 0x1000000000000000ull) {
                fraction <<= 1;
                exponent--;
            }
            out->exponent = exponent;
            out->fraction.ll = fraction;
        }
    } else if (exponent == 0x7FF) {
        if (fraction == 0) {
            out->kind = 4;
        } else {
            if (fraction & 0x0008000000000000ull)
                out->kind = 1;
            else
                out->kind = 0;
            out->fraction.ll = fraction;
        }
    } else {
        out->exponent = exponent - 0x3FF;
        out->kind = 3;
        out->fraction.ll = (fraction << 8) | 0x1000000000000000ull;
    }
}

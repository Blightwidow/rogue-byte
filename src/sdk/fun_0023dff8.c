/* SPDX-License-Identifier: GPL-3.0-or-later */
/* source:sly1-decomp soft_float_single.c (src/lib, AGPL-3.0, same maintainers), a draft that scores 0 */
#include "types.h"

/* A single taken apart: its kind (0 signalling NaN, 1 quiet NaN, 2 zero, 3 finite, 4 infinity), sign, unbiased exponent and fraction. */
typedef struct Packed {
    u32 kind;
    s32 sign;
    s32 exp;
    u32 mant;
} Packed;

#define IS_NAN(p) ((p)->kind < 2)
#define IS_ZERO(p) (((p)->kind ^ 2) == 0)
#define IS_INF(p) (((p)->kind ^ 4) == 0)

f32 func_0023DFF8(Packed* p)
{
    union {
        f32 f;
        struct {
            u32 mant : 23;
            u32 expo : 8;
            u32 sign : 1;
        } b;
    } bits;
    u32 mant = p->mant;
    s32 expo = 0;
    u32 sign = p->sign;

    if (IS_NAN(p)) {
        expo = 0xFF;
        mant = mant | 0x100000;
    } else if (IS_INF(p)) {
        expo = 0xFF;
        mant = 0;
    } else if (IS_ZERO(p)) {
        mant = 0;
    } else if (mant != 0) {
        s32 e = p->exp;
        if (e < -0x7E) {
            s32 sh = -0x7E - e;
            if (sh > 0x19) {
                mant = 0;
            } else {
                mant = mant >> sh;
            }
            mant = mant >> 7;
        } else if (e >= 0x80) {
            expo = 0xFF;
            mant = 0;
        } else {
            expo = e + 0x7F;
            if ((mant & 0x7F) == 0x40) {
                if ((mant & 0x80) != 0) {
                    mant = mant + 0x40;
                }
            } else {
                mant = mant + 0x3F;
            }
            if ((s32)mant < 0) {
                mant = mant >> 1;
                expo = expo + 1;
            }
            mant = mant >> 7;
        }
    }

    bits.b.mant = mant;
    bits.b.expo = expo;
    bits.b.sign = sign;
    return bits.f;
}

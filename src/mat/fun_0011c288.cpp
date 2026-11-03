// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct M { QW row[4]; };
struct V4 { float x, y, z, w; } __attribute__((aligned(16)));

/* a float broadcast into a VU0 register; retail keeps a stack copy it never reads */
static inline QW VuFloat(float f)
{
    QW q;
    asm("qmtc2.ni %1, %0" : "=j"(q) : "r"(f));
    V4 copy;
    *(QW *)&copy = q;
    return q;
}

static inline QW MulFloat(QW v, float f)
{
    QW s = VuFloat(f);
    QW r;
    asm("vmulx.xyzw %0, %1, %2x" : "=j"(r) : "j"(v), "j"(s));
    return r;
}

extern "C" M *func_0011C288(M *out, QW row3, M *src, float scale)
{
    out->row[0] = MulFloat(src->row[0], scale);
    out->row[1] = MulFloat(src->row[1], scale);
    out->row[2] = MulFloat(src->row[2], scale);
    out->row[3] = row3;
    float *words = (float *)out;
    words[3] = words[7] = words[11] = 0.0f;
    words[15] = 1.0f;
    return out;
}

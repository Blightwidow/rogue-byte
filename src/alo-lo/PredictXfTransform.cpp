// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct XF;
void PredictXfTransformAdjust(XF *, XF *, float, MATRIX4 *, MATRIX4 *);
static inline void LoadIdentity(MATRIX4 *m)
{
    memset(m, 0, 0x40);
    float one = 1.0f;
    asm volatile("nop");
    m->mat[3][3] = one;
    m->mat[2][2] = one;
    m->mat[1][1] = one;
    m->mat[0][0] = one;
}
void PredictXfTransform(XF *leaf, XF *basis, float dt, MATRIX4 *mat, MATRIX4 *rate)
{
    if (mat != 0)
        LoadIdentity(mat);
    if (rate != 0)
        memset(rate, 0, 0x40);
    PredictXfTransformAdjust(leaf, basis, dt, mat, rate);
}

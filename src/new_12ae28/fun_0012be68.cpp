// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct B12 { int w[3]; };
struct KEYBL { float pos[3]; float t; QW tan; };
struct ACRBL { int pad0; int pad4; KEYBL *akey; };
extern "C" int func_0012BB70(ACRBL *, float);
extern "C" void EvaluateBezierPos__FfffP6VECTORN63(float, float, float, QW, QW, QW, QW, QW *, QW *, QW *);
extern "C" void func_0012BE68(ACRBL *pacrbl, float t, float svt, QW *pvecPos, QW *pvecVel)
{
    QW posPrev;
    QW posNext;
    int ikey = func_0012BB70(pacrbl, t);
    int pkey = ikey * 0x20 + (int)pacrbl->akey;
    *(B12 *)&posPrev = *(B12 *)(pkey - 0x20);
    *(B12 *)&posNext = *(B12 *)pkey;
    float tPrev = *(float *)(pkey - 0x14);
    EvaluateBezierPos__FfffP6VECTORN63(*(float *)(pkey + 0xC) - tPrev, t - tPrev, svt, posPrev, *(QW *)(pkey - 0x10), posNext, *(QW *)(pkey + 0x10), pvecPos, pvecVel, 0);
}

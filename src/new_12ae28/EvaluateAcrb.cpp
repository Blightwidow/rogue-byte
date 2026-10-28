// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct B12 { int w[3]; };
struct KEYB { float pos[3]; float t; QW in; QW out; };
struct ACRB { int pad0; int pad4; KEYB *akey; };
extern "C" int IkeyFindAcrb(ACRB *, float);
extern "C" void EvaluateBezierPos__FfffP6VECTORN63(float, float, float, QW, QW, QW, QW, QW *, QW *, QW *);
extern "C" void EvaluateAcrb(ACRB *pacrb, float t, float svt, QW *pvecPos, QW *pvecVel)
{
    QW posPrev;
    QW posNext;
    int ikey = IkeyFindAcrb(pacrb, t);
    int pkey = ikey * 0x30 + (int)pacrb->akey;
    *(B12 *)&posPrev = *(B12 *)(pkey - 0x30);
    *(B12 *)&posNext = *(B12 *)pkey;
    float tPrev = *(float *)(pkey - 0x24);
    EvaluateBezierPos__FfffP6VECTORN63(*(float *)(pkey + 0xC) - tPrev, t - tPrev, svt, posPrev, *(QW *)(pkey - 0x10), posNext, *(QW *)(pkey + 0x10), pvecPos, pvecVel, 0);
}

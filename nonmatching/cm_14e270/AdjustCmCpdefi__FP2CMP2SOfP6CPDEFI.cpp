// SPDX-License-Identifier: GPL-3.0-or-later
#include "types.h"
#include "vu0inline.h"

struct CM;
struct SO;
struct CPDEFI;

extern "C" QW CalcCmAdjust__FP2CMP2SOP6CPDEFIP6VECTOR(CM *, CPDEFI *);
extern "C" int FIsBasicDerivedFrom(SO *, int);
extern "C" void SpringCm__FfffP2CMP6VECTORP6VECTORP6VECTOR(CM *, char *, char *, QW, float, float);
extern "C" QW g_2a2dd0;

extern "C" void AdjustCmCpdefi__FP2CMP2SOfP6CPDEFI(CM *cm, SO *so, float, CPDEFI *cpdefi)
{
    char *base = (char *)cm;
    QW adjust = CalcCmAdjust__FP2CMP2SOP6CPDEFIP6VECTOR(cm, cpdefi);
    if (FIsBasicDerivedFrom(so, 0x34)) {
        int mode = *(int *)((char *)so + 0x4F4);
        QW target;
        float nearScale;
        float farScale;
        float nearFirst;
        float farFirst;
        switch (mode) {
        case 0:
            nearFirst = 5.0f;
            farFirst = -3.5f;
            SpringCm__FfffP2CMP6VECTORP6VECTORP6VECTOR(cm, base + 0x2C0, base + 0x2D0, adjust, nearFirst, farFirst);
            target = g_2a2dd0;
            nearScale = 5.0f;
            farScale = -3.5f;
            goto second;
        case 1:
            SpringCm__FfffP2CMP6VECTORP6VECTORP6VECTOR(cm, base + 0x2C0, base + 0x2D0, adjust, 1.0f, -10.0f);
            target = *(QW *)(base + 0x2E0);
            nearScale = 0.0f;
            farScale = -10.0f;
        second:
            SpringCm__FfffP2CMP6VECTORP6VECTORP6VECTOR(cm, base + 0x2E0, base + 0x2F0, target, nearScale, farScale);
            break;
        case 2:
            SpringCm__FfffP2CMP6VECTORP6VECTORP6VECTOR(cm, base + 0x2C0, base + 0x2D0, adjust, 5.0f, -3.5f);
            break;
        }
    } else {
        SpringCm__FfffP2CMP6VECTORP6VECTORP6VECTOR(cm, base + 0x2C0, base + 0x2D0, adjust, 5.0f, -3.5f);
        SpringCm__FfffP2CMP6VECTORP6VECTORP6VECTOR(cm, base + 0x2E0, base + 0x2F0, g_2a2dd0, 5.0f, -3.5f);
    }
    *(QW *)((char *)cpdefi + 0x40) = VectorAdd(*(QW *)((char *)cpdefi + 0x10), *(QW *)(base + 0x2C0));
}

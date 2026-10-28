#include "sly2.h"
extern "C" {
int FIsBasicDerivedFrom(void *, int);
QW PosLoWorld(void *);
QW *PmatLoWorld(void *);
}

extern "C" int func_00154770(char *psensor, char *plo)
{
    if (!FIsBasicDerivedFrom(plo, 0x34))
        return 0;
    if (*(int *)(plo + 0x4CC) == -1)
        return 0;
    QW posPlayer = PosLoWorld(plo);
    QW posSensor = PosLoWorld(psensor);
    QW offset;
    asm("qmtc2.ni %0, vf3" : : "r"(posSensor));
    asm("lqc2 vf2, %0" : : "m"(posPlayer));
    asm("vsub.xyzw vf1, vf2, vf3");
    asm("sqc2 vf1, %0" : "=m"(offset));
    int nStatePlayer = *(int *)(plo + 0x4C8);
    switch (nStatePlayer) {
    case 0:
    case 0xd: {
        char *pholder = *(char **)(plo + 0x4D4);
        int nHeld;
        if (FIsBasicDerivedFrom(pholder, 0xC)) {
            nHeld = *(int *)(pholder + 0x194);
        } else if (FIsBasicDerivedFrom(pholder, 0x22)) {
            nHeld = *(int *)(pholder + 0xE4);
        } else {
            return *(int *)(pholder + 0xE4) == 0;
        }
        if (nHeld != 0)
            return 0;
        QW *pmat = PmatLoWorld(plo);
        float gFront;
        int bits;
        asm("lqc2 vf2, %0" : : "m"(offset));
        asm("lqc2 vf1, 0(%0)" : : "r"(pmat));
        asm("vmul.xyz vf2, vf2, vf1");
        asm("vaddw.x vf3, vf0, vf0w");
        asm("vadday.x ACC, vf2, vf2y");
        asm("vmaddz.x vf2, vf3, vf2z");
        asm volatile("qmfc2.ni %0, vf2\n\tmtc1 %0, %1" : "=&r"(bits), "=f"(gFront));
        bool fBehind = gFront <= 0.0f;
        bool fFlag = false;
        if (nStatePlayer == 0)
            fFlag = *(int *)(plo + 0x1040) == 0;
        return fBehind != fFlag;
    }
    case 1:
        return *(int *)(plo + 0x4CC) == 0;
    case 2:
        return 1;
    case 8:
        return (unsigned)(*(int *)(plo + 0x4CC) - 9) < 2u;
    default:
        return 0;
    }
}

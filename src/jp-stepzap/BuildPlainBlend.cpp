// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct VT {
    char pad[0x18];
    short delta;
    short index;
    void (*fn)(void *, float, float, float *, int);
};
struct CHN {
    int unk0;
    void **panim;
};
struct ASEG {
    char pad[0x74];
    float duration;
};
struct ENT { int u0; ASEG *paseg; int u8; int uc; QW vel; };
extern "C" {
CHN *PchnFindAseg(ASEG *, void *, int, int);
void EnsureAsegBlendDynamic(void *, int, int, void *, int, void *, void *, void *);
}
void BuildPlainBlend(void *palo, ENT *aent, int *ppasegbl)
{
    struct { QW start; QW end; QW saved; int pasegbl; } l;
    int i = 7;
    ENT *pent = aent;
    do {
        ASEG *paseg = pent->paseg;
        if (paseg != 0) {
            CHN *pchn = PchnFindAseg(paseg, palo, 1, 1);
            if (pchn != 0) {
                register void *panim asm("$7") = pchn->panim;
                VT *vt = *(VT **)panim;
                vt->fn((char *)panim + vt->delta, 0.0f, 1.0f, (float *)&l.start, 0);
                register void *panim2 asm("$7") = pchn->panim;
                VT *vt2 = *(VT **)panim2;
                vt2->fn((char *)panim2 + vt2->delta, pent->paseg->duration, 1.0f, (float *)&l.end, 0);
                register ASEG *paseg2 asm("$2") = pent->paseg;
                asm volatile("lqc2 vf2, %0" : : "m" (l.start));
                register int bits asm("$2") = *(int *)&paseg2->duration;
                asm volatile("lqc2 vf3, %0" : : "m" (l.end));
                asm volatile("qmtc2.ni %0, vf1" : : "r" (bits));
                asm("vsub.xyzw vf2, vf2, vf3");
                asm("sqc2 vf1, %0" : "=m" (l.saved));
                asm("vdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf2, vf2, Q");
                asm("sqc2 vf2, %0" : "=m" (pent->vel));
            }
        }
        pent++;
    } while (--i >= 0);
    EnsureAsegBlendDynamic(palo, 0x20, 8, aent, 0, 0, 0, &l.pasegbl);
    *ppasegbl = l.pasegbl;
}

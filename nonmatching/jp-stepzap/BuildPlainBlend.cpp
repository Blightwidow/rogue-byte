// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
#include "vu0inline.h"

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
union VU_SCALE { QW q; VECTOR v; };
static inline QW DivideByDuration(QW delta, u32 durationBits)
{
    VU_SCALE scale;
    scale.q = VectorFromWord(durationBits);
    return ScaleByReciprocalX(delta, scale.q);
}
struct ENT { int u0; ASEG *paseg; int u8; int uc; QW vel; };
extern "C" {
CHN *PchnFindAseg(ASEG *, void *, int, int);
void EnsureAsegBlendDynamic(void *, int, int, void *, int, void *, void *, void *);
}

void BuildPlainBlend(void *palo, ENT *aent, int *ppasegbl)
{
    struct { QW start; QW end; } l;
    int i = 7;
    ENT *pent = aent;
    do {
        ASEG *paseg = pent->paseg;
        if (paseg != 0) {
            CHN *pchn = PchnFindAseg(paseg, palo, 1, 1);
            if (pchn != 0) {
                void *panim = pchn->panim;
                VT *vt = *(VT **)panim;
                vt->fn((char *)panim + vt->delta, 0.0f, 1.0f, (float *)&l.start, 0);
                void *panim2 = pchn->panim;
                VT *vt2 = *(VT **)panim2;
                vt2->fn((char *)panim2 + vt2->delta, pent->paseg->duration, 1.0f, (float *)&l.end, 0);
                pent->vel = DivideByDuration(VectorSub(l.start, l.end), *(u32 *)&pent->paseg->duration);
            }
        }
        pent++;
    } while (--i >= 0);
    int pasegbl;
    EnsureAsegBlendDynamic(palo, 0x20, 8, aent, 0, 0, 0, &pasegbl);
    *ppasegbl = pasegbl;
}

/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct TNFN;
struct CPDEFI;
struct TN {
    char pad0[0x10C];
    void *pcrv;
    char pad1[0x12C - 0x110];
    int fFakeCylinder;
    char pad2[0x140 - 0x130];
    float sClosest;
    char pad3[0x150 - 0x144];
    QW posFake;
    float sRadFake;
};
struct CPTN { char pad[0x10]; TN *ptn; TNFN *ptnfn; };
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
void GetTnfnNose__FP4TNFNP6CPDEFIP6VECTORP2TN(TNFN *, CPDEFI *, VECTOR *, TN *);
extern "C" void FindCrvClosestPointFromS(void *, QW, float, int, int, int, int, float *);
extern "C" QW ConvertAloPos(void *, TN *, QW);
extern "C" float atan2f(float, float);
extern "C" void UpdateCptnClosestPoint(CPTN *pcptn, CPDEFI *pcpdefi)
{
    TN *ptn = pcptn->ptn;
    if (ptn) {
        if (ptn->pcrv || ptn->fFakeCylinder) {
            VECTOR posNose;
            GetTnfnNose__FP4TNFNP6CPDEFIP6VECTORP2TN(pcptn->ptnfn, pcpdefi, &posNose, 0);
            if (ptn->pcrv) {
                float *psClosest = &ptn->sClosest;
                float sClosest = ptn->sClosest;
                FindCrvClosestPointFromS(ptn->pcrv, *(QW *)&posNose, sClosest, 0, 0, 0, 0, psClosest);
            } else {
                QW local = ConvertAloPos(0, ptn, *(QW *)&posNose);
                QW delta;
                asm("lqc2 vf1, %2\n\tqmtc2.ni %1, vf2\n\tvsub.xyzw vf2, vf2, vf1\n\tqmfc2.ni %0, vf2" : "=r" (delta) : "r" (local), "m" (ptn->posFake));
                float angle = atan2f(Lane(__builtin_prot3w(delta)), Lane(delta));
                if (angle < 0.0f)
                    angle += 6.2831855f;
                ptn->sClosest = angle * ptn->sRadFake;
            }
        }
    }
}

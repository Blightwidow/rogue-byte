// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct CRef { int tagk; union { int n; QW *pv; }; };
struct CPair { int cref; int pad4; CRef ref; CPair *next; };
struct CFrame;
extern "C" {
void CRef_ConstructVector(CRef *, QW *);
CRef *CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
extern QW g_2a2dd0;
}
extern "C" CRef *RefOpVectorNormalize(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    CRef refNormal;
    CRef_ConstructVector(&refNormal, aref[0].pv);
    if (aref[1].tagk == 0) {
        QW *pvec = refNormal.pv;
        QW *pzero = &g_2a2dd0;
        float gEpsilon = 0.0001f;
        QW vec = *pvec;
        float length;
        asm("qmtc2.ni %0, vf3" : : "r" (vec));
        asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
        asm("qmfc2.ni %0, vf1" : "=r" (length));
        if (length < gEpsilon) {
            *pvec = *pzero;
        } else {
            asm("nop\n\tnop\n\tvdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf1, vf3, Q");
            asm("sqc2 vf1, %0" : "=m" (*pvec));
        }
    } else {
        QW *pvec = refNormal.pv;
        float gEpsilon = 0.0001f;
        float length;
        asm("lqc2 vf3, %0" : : "m" (*pvec));
        asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
        asm("qmfc2.ni %0, vf1" : "=r" (length));
        QW *pdefault = ((CPair *)aref[1].n)->ref.pv;
        if (length < gEpsilon) {
            *pvec = *pdefault;
        } else {
            asm("nop\n\tnop\n\tvdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf1, vf3, Q");
            asm("sqc2 vf1, %0" : "=m" (*pvec));
        }
    }
    CRef_CopyConstruct(pret, &refNormal);
    CRef_Destruct(&refNormal);
    return pret;
}

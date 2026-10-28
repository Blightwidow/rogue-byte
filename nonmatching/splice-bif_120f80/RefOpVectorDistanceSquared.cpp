// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct CRef { int tagk; union { int n; QW *pv; }; };
struct CRefLarge { int tagk; int pad[3]; };
struct CPair { int cref; int pad4; CRef ref; CPair *next; };
struct CFrame;
extern "C" {
void CRef_SetF32(CRefLarge *, float);
CRef *CRef_CopyConstruct(CRef *, CRefLarge *);
void CRef_Destruct(CRefLarge *);
extern QW g_2a2dd0;
}
extern "C" CRef *RefOpVectorDistanceSquared(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    CRefLarge refDistance;
    refDistance.tagk = -1;
    register float value asm("$2");
    if (aref[1].tagk == 0) {
        asm("lqc2 vf2, %2\n\tlqc2 vf1, %1\n\tvsub.xyzw vf1, vf1, vf2\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf3, vf1z\n\tqmfc2.ni %0, vf1" : "=&r" (value) : "m" (*aref[0].pv), "m" (g_2a2dd0));
        CRef_SetF32(&refDistance, value);
    } else {
        QW *pto = ((CPair *)aref[1].n)->ref.pv;
        asm("lqc2 vf1, %1\n\tlqc2 vf2, %2\n\tvsub.xyzw vf1, vf1, vf2\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf3, vf1z\n\tqmfc2.ni %0, vf1" : "=r" (value) : "m" (*aref[0].pv), "m" (*pto));
        CRef_SetF32(&refDistance, value);
    }
    CRef_CopyConstruct(pret, &refDistance);
    CRef_Destruct(&refDistance);
    return pret;
}

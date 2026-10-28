#include "sly2.h"
struct CRef { int tagk; union { int n; float g; void *pv; }; };
struct CPair { int pad[2]; CRef ref; };
struct CFrame;
extern "C" {
void CRef_Destruct(CRef *);
CRef *CRef_CopyConstruct(CRef *, CRef *);
void CRef_SetF32(CRef *, float);
extern QW g_2a2dd0;
}
#define COMPUTE "vsub.xyzw vf1, vf1, vf2\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf3, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1"
static inline float DistToGlobal(const QW *from, const QW *to)
{
    int bits;
    asm("lqc2 vf2, 0(%2)\n\tlqc2 vf1, 0(%1)\n\t" COMPUTE : "=r" (bits) : "r" (from), "r" (to));
    return *(float *)&bits;
}
static inline float DistToRef(const QW *from, const QW *to)
{
    int bits;
    asm("lqc2 vf1, 0(%1)\n\tlqc2 vf2, 0(%2)\n\t" COMPUTE : "=r" (bits) : "r" (from), "r" (to));
    return *(float *)&bits;
}
extern "C" CRef *RefOpVectorDistance(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    CRef refDistance;
    refDistance.tagk = -1;
    if (aref[1].tagk == 0) {
        CRef_SetF32(&refDistance, DistToGlobal((const QW *)aref[0].pv, &g_2a2dd0));
    } else {
        CPair *ppair = (CPair *)aref[1].pv;
        CRef_SetF32(&refDistance, DistToRef((const QW *)aref[0].pv, (const QW *)ppair->ref.pv));
    }
    CRef_CopyConstruct(pret, &refDistance);
    CRef_Destruct(&refDistance);
    return pret;
}

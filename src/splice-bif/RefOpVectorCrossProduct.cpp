#include "sly2.h"
struct CRef { int tagk; union { int n; QW *pv; }; };
struct CFrame;
extern "C" {
void CRef_ConstructVectorValue(CRef *, QW);
CRef *CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
}
extern "C" CRef *RefOpVectorCrossProduct(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    CRef refResult;
    QW result;
    QW *first = aref[0].pv;
    QW *second = aref[1].pv;
    asm("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvopmula.xyz ACC, vf1, vf2\n\tvopmsub.xyz vf3, vf2, vf1\n\tqmfc2.ni %0, vf3" : "=r" (result) : "m" (*second), "m" (*first));
    CRef_ConstructVectorValue(&refResult, result);
    CRef_CopyConstruct(pret, &refResult);
    CRef_Destruct(&refResult);
    return pret;
}

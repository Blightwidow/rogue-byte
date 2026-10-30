#include "sly2.h"
struct CRef { int tagk; union { int n; QW *pv; }; };
struct CFrame;
extern "C" {
QW ConvertAloPos(int, int, QW);
void CRef_ConstructVectorValue(CRef *, QW);
CRef *CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
}
extern "C" CRef *RefOpConvertObjectPosition(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    CRef refResult;
    CRef_ConstructVectorValue(&refResult, ConvertAloPos(aref[0].n, aref[1].n, *aref[2].pv));
    CRef_CopyConstruct(pret, &refResult);
    CRef_Destruct(&refResult);
    return pret;
}

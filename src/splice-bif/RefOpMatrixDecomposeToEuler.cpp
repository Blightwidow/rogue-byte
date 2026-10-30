#include "sly2.h"
struct CRef { int tagk; union { int n; QW *pv; }; };
struct CFrame;
struct Rows3;
extern "C" {
QW DecomposeRotateMatrixEuler(Rows3 *);
void CRef_ConstructVectorValue(CRef *, QW);
CRef *CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
}
extern "C" CRef *RefOpMatrixDecomposeToEuler(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    CRef refResult;
    CRef_ConstructVectorValue(&refResult, DecomposeRotateMatrixEuler((Rows3 *)aref[0].n));
    CRef_CopyConstruct(pret, &refResult);
    CRef_Destruct(&refResult);
    return pret;
}

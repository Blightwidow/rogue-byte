#include "sly2.h"
struct CRef { int tagk; MATRIX4 *pmat; };
struct CFrame;
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_Destruct(CRef *);
extern "C" MATRIX4 ConvertAloMat(int, int, MATRIX4 *);

CRef *RefOpConvertObjectMatrix(CRef *pref, int carg, CRef *aref, CFrame *pframe)
{
    CRef refResult;
    SetTag__4CRef4TAGK(&refResult, 0x1B);
    MATRIX4 *pdest = refResult.pmat;
    MATRIX4 mat = ConvertAloMat((int)aref[0].pmat, (int)aref[1].pmat, aref[2].pmat);
    *pdest = mat;
    CRef_CopyConstruct(pref, &refResult);
    CRef_Destruct(&refResult);
    return pref;
}

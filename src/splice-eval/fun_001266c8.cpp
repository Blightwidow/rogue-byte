#include "sly2.h"
struct CRef { int tagk; int n; CRef &operator=(const CRef &); };
struct CExpr { char pad[0x10]; int body; };
struct CFrame { char pad[0xC]; CExpr *pexpr; };
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_Destruct(CRef *);
extern "C" void RefEval(CRef *, int);

extern "C" CRef *func_001266C8(CRef *pref, CFrame *pframe)
{
    CRef refResult;
    register int minusOne asm("$2") = -1;
    refResult.tagk = minusOne;
    int body = pframe->pexpr->body;
    if (body != 0) {
        CRef refValue;
        RefEval(&refValue, body);
        refResult = refValue;
        CRef_Destruct(&refValue);
    } else {
        CRef_Destruct(&refResult);
        SetTag__4CRef4TAGK(&refResult, 0x24);
    }
    CRef_CopyConstruct(pref, &refResult);
    CRef_Destruct(&refResult);
    return pref;
}

#include "sly2.h"
struct CRef { int tagk; int n; CRef &operator=(const CRef &); };
struct CPair { char pad[0x10]; CPair *next; };
struct CPairHead { char pad[0x10]; CPair *next; };
struct CPair0 { char pad[0xC]; CPairHead *head; };
struct CFrame;
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void RefEval(CRef *, CPair *, CFrame *);

extern "C" CRef *RefEvalBegin(CRef *pref, CPair0 *ppair, CFrame *pframe)
{
    CRef refResult;
    CRef refTemp;
    refResult.tagk = -1;
    CRef_Destruct(&refResult);
    SetTag__4CRef4TAGK(&refResult, 0x24);
    for (CPair *ppairExpr = ppair->head->next; ppairExpr != 0; ppairExpr = ppairExpr->next) {
        RefEval(&refTemp, ppairExpr, pframe);
        refResult = refTemp;
        CRef_Destruct(&refTemp);
    }
    CRef_CopyConstruct(pref, &refResult);
    CRef_Destruct(&refResult);
    return pref;
}

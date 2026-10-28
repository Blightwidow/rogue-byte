#include "sly2.h"
struct CRef { int tagk; int n; CRef &operator=(const CRef &); };
struct CPair2 { char pad[0x10]; CPair2 *next; };
struct CPair0 { char pad[0xC]; CPair2 *pv; };
struct CFrame;
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_Destruct(CRef *);
extern "C" void RefEval(CRef *, CPair2 *, CFrame *);

extern "C" CRef *RefEvalIf__FP5CPairP6CFrame(CRef *pref, CPair0 *ppair, CFrame *pframe)
{
    CRef refResult;
    CRef refTemp;
    refResult.tagk = -1;
    CPair2 *ppairTest = ppair->pv->next;
    CPair2 *ppairThen = ppairTest->next;
    CPair2 *ppairElse = ppairThen->next;
    RefEval(&refTemp, ppairTest, pframe);
    refResult = refTemp;
    CRef_Destruct(&refTemp);
    if (refResult.n == 1) {
        RefEval(&refTemp, ppairThen, pframe);
        refResult = refTemp;
        CRef_Destruct(&refTemp);
    } else if (ppairElse != 0) {
        RefEval(&refTemp, ppairElse, pframe);
        refResult = refTemp;
        CRef_Destruct(&refTemp);
    } else {
        CRef_Destruct(&refResult);
        SetTag__4CRef4TAGK(&refResult, 0x24);
    }
    CRef_CopyConstruct(pref, &refResult);
    CRef_Destruct(&refResult);
    return pref;
}

#include "sly2.h"
struct CRef { int tagk; int n; CRef &operator=(const CRef &); };
struct CPair2 { char pad[0x10]; CPair2 *next; };
struct CPair0 { char pad[0xC]; CPair2 *pv; };
struct CFrame;
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_Destruct(CRef *);
extern "C" void RefEval(CRef *, CPair2 *, CFrame *);

extern "C" CRef *func_001266C8(CRef *pref, CPair0 *ppair, CFrame *pframe)
{
    CRef refResult;
    CRef refTemp;
    refResult.tagk = -1;
    CPair2 *ppairTest = ppair->pv->next;
    if (ppairTest != 0) {
        RefEval(&refTemp, ppairTest, pframe);
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

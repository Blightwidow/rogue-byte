#include "sly2.h"
struct CRef { int tagk; int n; CRef &operator=(const CRef &); };
struct CPair2 { char pad[0x10]; CPair2 *next; };
struct CPair0 { char pad[0xC]; CPair2 *pv; };
struct CFrame;
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_Destruct(CRef *);
extern "C" void RefEval(CRef *, CPair2 *, CFrame *);

extern "C" CRef *RefEvalWhile__FP5CPairP6CFrame(CRef *pref, CPair0 *ppair, CFrame *pframe)
{
    CRef refResult;
    CRef refTemp;
    refResult.tagk = -1;
    CPair2 *ppairTest = ppair->pv->next;
    CPair2 *ppairBody = ppairTest->next;
    while (1) {
        RefEval(&refTemp, ppairTest, pframe);
        refResult = refTemp;
        CRef_Destruct(&refTemp);
        if (refResult.tagk == 0x17 && refResult.n == 0)
            break;
        RefEval(&refTemp, ppairBody, pframe);
        refResult = refTemp;
        CRef_Destruct(&refTemp);
    }
    CRef_Destruct(&refResult);
    SetTag__4CRef4TAGK(&refResult, 0x24);
    CRef_CopyConstruct(pref, &refResult);
    CRef_Destruct(&refResult);
    return pref;
}

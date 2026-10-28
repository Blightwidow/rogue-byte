#include "sly2.h"
struct CRef { int tagk; int n; CRef &operator=(const CRef &); };
struct CPair { char pad[0x10]; CPair *next; };
struct CProc { char pad[0x18]; CPair *code; };
struct CFrame;
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_Destruct(CRef *);
extern "C" void RefEval(CRef *, CPair *, CFrame *);

extern "C" CRef *RefEvalProcBody(CRef *pref, CProc *pproc, CFrame *pframe)
{
    CRef refResult;
    CRef refTemp;
    refResult.tagk = -1;
    CPair *ppair = pproc->code;
    do {
        RefEval(&refTemp, ppair, pframe);
        refResult = refTemp;
        CRef_Destruct(&refTemp);
        ppair = ppair->next;
    } while (ppair != 0);
    CRef_CopyConstruct(pref, &refResult);
    CRef_Destruct(&refResult);
    return pref;
}

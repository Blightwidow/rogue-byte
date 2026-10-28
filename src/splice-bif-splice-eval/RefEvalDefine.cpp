#include "sly2.h"
struct CRef { int tagk; int n; CRef &operator=(const CRef &); };
struct CPair2 { char pad[0xC]; int sym; int expr; };
struct CPair1 { char pad[0x10]; CPair2 *next; };
struct CPair0 { char pad[0xC]; CPair1 *next; };
struct CFrame;
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_Destruct(CRef *);
extern "C" void RefEval(CRef *, int, CFrame *);
extern "C" void CFrame_RefAddBinding(CRef *, CFrame *, int, CRef *);

extern "C" CRef *RefEvalDefine(CRef *pref, CPair0 *ppair, CFrame *pframe)
{
    CRef refResult;
    CRef refTemp;
    refResult.tagk = -1;
    CPair2 *ppairSymbol = ppair->next->next;
    RefEval(&refTemp, ppairSymbol->expr, pframe);
    refResult = refTemp;
    CRef_Destruct(&refTemp);
    CFrame_RefAddBinding(&refTemp, pframe, ppairSymbol->sym, &refResult);
    refResult = refTemp;
    CRef_Destruct(&refTemp);
    CRef_CopyConstruct(pref, &refResult);
    CRef_Destruct(&refResult);
    return pref;
}

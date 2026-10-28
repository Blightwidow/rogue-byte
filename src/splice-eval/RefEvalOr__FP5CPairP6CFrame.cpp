#include "sly2.h"
struct CRef { int tagk; int n; CRef &operator=(const CRef &); };
struct CPair2 { char pad[0x10]; CPair2 *next; };
struct CPair0 { char pad[0xC]; CPair2 *pv; };
struct CFrame;
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_Destruct(CRef *);
extern "C" void CRef_SetBool(CRef *, int);
extern "C" void RefEval(CRef *, CPair2 *, CFrame *);

extern "C" CRef *RefEvalOr__FP5CPairP6CFrame(CRef *pref, CPair0 *ppair, CFrame *pframe)
{
    CRef refResult;
    CRef refTemp;
    refResult.tagk = -1;
    CPair2 *ppairOperand = ppair->pv->next;
    if (ppairOperand != 0) {
        do {
            RefEval(&refTemp, ppairOperand, pframe);
            refResult = refTemp;
            CRef_Destruct(&refTemp);
            if (refResult.tagk != 0x17 || refResult.n != 0) {
                CRef_CopyConstruct(pref, &refResult);
                CRef_Destruct(&refResult);
                goto done;
            }
            ppairOperand = ppairOperand->next;
        } while (ppairOperand != 0);
    }
    CRef_SetBool(&refResult, 0);
    CRef_CopyConstruct(pref, &refResult);
    CRef_Destruct(&refResult);
done:
    return pref;
}

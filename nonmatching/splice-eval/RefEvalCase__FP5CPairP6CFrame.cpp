#include "sly2.h"
struct CRef;
extern "C" void CRef_Destruct(CRef *);
struct CRef { int tagk; int n; CRef() { tagk = -1; } CRef &operator=(const CRef &); ~CRef() { CRef_Destruct(this); } };
struct CRefRaw { int tagk; int n; };
struct CPair2 { char pad[0x8]; int tagk; CPair2 *head; CPair2 *pv; };
struct CPair0 { char pad[0xC]; CPair2 *pv; };
struct CFrame;
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void RefEval(CRefRaw *, CPair2 *, CFrame *);
extern "C" void bevy_splice_bif_ref_op_eqv(CRefRaw *, int, CRef *, CFrame *);
extern "C" void CRefRaw_Destruct(CRefRaw *) asm("CRef_Destruct");
extern "C" void RefAssign(CRef *, CRefRaw *) asm("__as__4CRefRC4CRef");

extern "C" CRef *RefEvalCase__FP5CPairP6CFrame(CRef *pref, CPair0 *ppair, CFrame *pframe)
{
    CRef refResult;
    CRef refKey[2];
    CRef refMatch;
    CRefRaw refTemp;
    CRef_Destruct(&refResult);
    SetTag__4CRef4TAGK(&refResult, 0x24);
    CPair2 *ppairKey = ppair->pv->pv;
    RefEval(&refTemp, ppairKey, pframe);
    RefAssign(&refKey[0], &refTemp);
    CRefRaw_Destruct(&refTemp);
    CPair2 *ppairClause = ppairKey->pv;
    if (ppairClause) {
        do {
            CPair2 *ppairHead = ppairClause->head;
            int fFound;
            if (ppairHead->tagk == 0xB) {
                fFound = 1;
            } else {
                fFound = 0;
                CPair2 *ppairDatum = ppairHead->head;
                if (ppairDatum) {
                    do {
                        refKey[1] = *(CRef *)((char *)ppairDatum + 8);
                        bevy_splice_bif_ref_op_eqv(&refTemp, 2, refKey, pframe);
                        RefAssign(&refMatch, &refTemp);
                        CRefRaw_Destruct(&refTemp);
                        if (refMatch.tagk == 0x17 && refMatch.n != 0) {
                            fFound = 1;
                            ppairDatum = 0;
                        } else {
                            ppairDatum = ppairDatum->pv;
                        }
                    } while (ppairDatum);
                }
            }
            if (fFound) {
                CPair2 *ppairBody = ppairHead->pv;
                if (ppairBody) {
                    do {
                        RefEval(&refTemp, ppairBody, pframe);
                        RefAssign(&refResult, &refTemp);
                        CRefRaw_Destruct(&refTemp);
                        ppairBody = ppairBody->pv;
                    } while (ppairBody);
                }
                ppairClause = 0;
            } else {
                ppairClause = ppairClause->pv;
            }
        } while (ppairClause);
    }
    CRef_CopyConstruct(pref, &refResult);
    return pref;
}

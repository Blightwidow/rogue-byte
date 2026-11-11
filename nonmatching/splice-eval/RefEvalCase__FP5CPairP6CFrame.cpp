#include "cref.h"
struct CFrame;
struct CPair { int m_cref; int m_unknown4; CRef m_ref; CPair *m_ppairNext; };
struct CRefNil : CRef { CRefNil() { m_tagk = TAGK_Nil; } CRefNil &operator=(const CRef &ref) { CRef::operator=(ref); return *this; } };
extern "C" CRef RefEval(CPair *ppair, CFrame *pframe);
extern "C" CRef bevy_splice_bif_ref_op_eqv(int cref, CRef *aref, CFrame *pframe);

extern "C" CRef RefEvalCase__FP5CPairP6CFrame(CPair *ppair, CFrame *pframe)
{
    CRefNil refResult;
    CRefNil refKey[2];
    CRefNil refMatch;
    refResult.Decref();
    refResult.SetTag(TAGK_Void);
    CPair *ppairKey = ((CPair *)ppair->m_ref.m_tag.m_ppair)->m_ppairNext;
    refKey[0] = RefEval(ppairKey, pframe);
    CPair *ppairClause = ppairKey->m_ppairNext;
    if (ppairClause != 0) {
        do {
            CPair *ppairHead = (CPair *)ppairClause->m_ref.m_tag.m_ppair;
            int fFound;
            if (ppairHead->m_ref.m_tagk == 0xB) {
                fFound = 1;
            } else {
                fFound = 0;
                CPair *ppairDatum = (CPair *)ppairHead->m_ref.m_tag.m_ppair;
                if (ppairDatum != 0) {
                    do {
                        refKey[1] = ppairDatum->m_ref;
                        refMatch = bevy_splice_bif_ref_op_eqv(2, refKey, pframe);
                        if (refMatch.m_tagk == TAGK_Bool && refMatch.m_tag.m_bool != 0) {
                            fFound = 1;
                            ppairDatum = 0;
                        } else {
                            ppairDatum = ppairDatum->m_ppairNext;
                        }
                    } while (ppairDatum != 0);
                }
            }
            if (fFound != 0) {
                for (ppairHead = ppairHead->m_ppairNext; ppairHead != 0; ppairHead = ppairHead->m_ppairNext)
                    refResult = RefEval(ppairHead, pframe);
                ppairClause = 0;
            } else {
                ppairClause = ppairClause->m_ppairNext;
            }
        } while (ppairClause != 0);
    }
    return refResult;
}

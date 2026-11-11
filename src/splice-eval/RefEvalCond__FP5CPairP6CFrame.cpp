#include "cref.h"
struct CFrame;
struct CPair { int m_cref; int m_unknown4; CRef m_ref; CPair *m_ppairNext; };
extern "C" CRef RefEval(CPair *ppair, CFrame *pframe);

extern "C" CRef RefEvalCond__FP5CPairP6CFrame(CPair *ppair, CFrame *pframe)
{
    CRef refResult;
    CRef refTest;
    refResult.m_tagk = TAGK_Nil;
    refTest.m_tagk = TAGK_Nil;
    refResult.Decref();
    refResult.SetTag(TAGK_Void);
    CPair *ppairClause = ((CPair *)ppair->m_ref.m_tag.m_ppair)->m_ppairNext;
    if (ppairClause != 0) {
        do {
            CPair *ppairHead = (CPair *)ppairClause->m_ref.m_tag.m_ppair;
            int fMatch;
            if (ppairHead->m_ref.m_tagk == 0xB) {
                fMatch = 1;
            } else {
                refTest = RefEval(ppairHead, pframe);
                fMatch = 0;
                if (refTest.m_tagk != TAGK_Bool || refTest.m_tag.m_bool != 0)
                    fMatch = 1;
                if (fMatch != 0 && ppairHead->m_ppairNext == 0)
                    refResult = refTest;
            }
            if (fMatch != 0) {
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

#include "sly2.h"
#include "cref.h"
struct CPair { int field0; int field4; CRef ref; CPair *next; };
struct CFrame;
extern "C" {
void SetTag__4CRef4TAGK(CRef *, int);
void CRef_CopyConstruct(CRef *, CRef *);
void RefEvalSymbol(CRef *, CPair *, CFrame *);
void RefEvalSet(CRef *, CPair *, CFrame *);
void RefEvalDefine(CRef *, CPair *, CFrame *);
void RefEvalAssert__FP5CPairP6CFrame(CRef *, CPair *, CFrame *);
void func_001266C8(CRef *, CPair *, CFrame *);
void RefEvalIf__FP5CPairP6CFrame(CRef *, CPair *, CFrame *);
void RefEvalOr__FP5CPairP6CFrame(CRef *, CPair *, CFrame *);
void RefEvalAnd__FP5CPairP6CFrame(CRef *, CPair *, CFrame *);
void RefEvalCond__FP5CPairP6CFrame(CRef *, CPair *, CFrame *);
void RefEvalCase__FP5CPairP6CFrame(CRef *, CPair *, CFrame *);
void RefEvalLet(CRef *, CPair *, CFrame *);
void RefEvalWhile__FP5CPairP6CFrame(CRef *, CPair *, CFrame *);
void RefEvalLambda(CRef *, CPair *, CFrame *);
void RefEvalBegin(CRef *, CPair *, CFrame *);
void RefEvalApply(CRef *, CPair *, CFrame *);
}
// One `return pref;` at the end and `default:` written first as its own CRef_CopyConstruct call, case 18 with its own call: gcc then drops
// the no-op a0 = s0 move on the default path, cross-jumps the two copy calls and puts the epilogue in retail's order (ld ra before lq s0).
// A `goto copy` form scored 5.
extern "C" CRef *RefEval(CRef *pref, CPair *ppair, CFrame *pframe)
{
    switch (ppair->ref.m_tagk) {
    default:
        CRef_CopyConstruct(pref, &ppair->ref);
        break;
    case 0x18:
        RefEvalSymbol(pref, ppair, pframe);
        break;
    case 0x1F: {
        CPair *head = (CPair *)ppair->ref.m_tag.m_n;
        switch (head->ref.m_tagk) {
        case 1:
            RefEvalSet(pref, ppair, pframe);
            break;
        case 2:
            RefEvalDefine(pref, ppair, pframe);
            break;
        case 5:
            RefEvalAssert__FP5CPairP6CFrame(pref, ppair, pframe);
            break;
        case 6:
            func_001266C8(pref, ppair, pframe);
            break;
        case 7:
            RefEvalIf__FP5CPairP6CFrame(pref, ppair, pframe);
            break;
        case 8:
            RefEvalOr__FP5CPairP6CFrame(pref, ppair, pframe);
            break;
        case 9:
            RefEvalAnd__FP5CPairP6CFrame(pref, ppair, pframe);
            break;
        case 10:
            RefEvalCond__FP5CPairP6CFrame(pref, ppair, pframe);
            break;
        case 12:
            RefEvalCase__FP5CPairP6CFrame(pref, ppair, pframe);
            break;
        case 13:
            RefEvalLet(pref, ppair, pframe);
            break;
        case 14:
            RefEvalWhile__FP5CPairP6CFrame(pref, ppair, pframe);
            break;
        case 16:
            RefEvalBegin(pref, ppair, pframe);
            break;
        case 15:
            RefEvalLambda(pref, ppair, pframe);
            break;
        case 18:
            CRef_CopyConstruct(pref, &head->next->ref);
            break;
        case 17:
            SetTag__4CRef4TAGK(pref, -1);
            break;
        default:
            RefEvalApply(pref, ppair, pframe);
            break;
        }
        break;
    }
    }
    return pref;
}

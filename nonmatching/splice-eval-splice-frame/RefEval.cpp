#include "sly2.h"
struct CRef { int tagk; int n; };
struct CPair { int pad0; int pad4; CRef ref; CPair *next; };
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
extern "C" CRef *RefEval(CRef *pref, CPair *ppair, CFrame *pframe)
{
    CRef * result;
    switch (ppair->ref.tagk) {
    case 0x18:
        RefEvalSymbol(pref, ppair, pframe);
        { result = pref; goto done; }
    case 0x1F: {
        CPair *head = (CPair *)ppair->ref.n;
        switch (head->ref.tagk) {
        case 1:
            RefEvalSet(pref, ppair, pframe);
            { result = pref; goto done; }
        case 2:
            RefEvalDefine(pref, ppair, pframe);
            { result = pref; goto done; }
        case 5:
            RefEvalAssert__FP5CPairP6CFrame(pref, ppair, pframe);
            { result = pref; goto done; }
        case 6:
            func_001266C8(pref, ppair, pframe);
            { result = pref; goto done; }
        case 7:
            RefEvalIf__FP5CPairP6CFrame(pref, ppair, pframe);
            { result = pref; goto done; }
        case 8:
            RefEvalOr__FP5CPairP6CFrame(pref, ppair, pframe);
            { result = pref; goto done; }
        case 9:
            RefEvalAnd__FP5CPairP6CFrame(pref, ppair, pframe);
            { result = pref; goto done; }
        case 10:
            RefEvalCond__FP5CPairP6CFrame(pref, ppair, pframe);
            { result = pref; goto done; }
        case 12:
            RefEvalCase__FP5CPairP6CFrame(pref, ppair, pframe);
            { result = pref; goto done; }
        case 13:
            RefEvalLet(pref, ppair, pframe);
            { result = pref; goto done; }
        case 14:
            RefEvalWhile__FP5CPairP6CFrame(pref, ppair, pframe);
            { result = pref; goto done; }
        case 16:
            RefEvalBegin(pref, ppair, pframe);
            { result = pref; goto done; }
        case 15:
            RefEvalLambda(pref, ppair, pframe);
            { result = pref; goto done; }
        case 18:
            ppair = head->next;
        copy:
            CRef_CopyConstruct(pref, &ppair->ref);
            { result = pref; goto done; }
        case 17:
            SetTag__4CRef4TAGK(pref, -1);
            { result = pref; goto done; }
        default:
            RefEvalApply(pref, ppair, pframe);
            { result = pref; goto done; }
        }
    }
    }
    goto copy;
done:
    return result;
}

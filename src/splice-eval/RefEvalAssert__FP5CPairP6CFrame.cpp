struct CRef { int tagk; int n; CRef &operator=(const CRef &); };
struct CPair { int count; int pad4; CRef ref; CPair *next; };
struct CFrame;
extern "C" {
void CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
void RefEval(CRef *, CPair *, CFrame *);
CRef *RefOpPrint(CRef *, int, CRef *, CFrame *);
void SetTag__4CRef4TAGK(CRef *, int);
int printf(const char *, ...);
}

extern "C" CRef *RefEvalAssert__FP5CPairP6CFrame(CRef *pref, CPair *ppair, CFrame *pframe)
{
    CRef refResult;
    CRef refTemp;
    refResult.tagk = -1;
    CPair *pexpr = ((CPair *)ppair->ref.n)->next;
    CPair *pmessage = pexpr->next;
    RefEval(&refTemp, pexpr, pframe);
    refResult = refTemp;
    CRef_Destruct(&refTemp);
    if (refResult.n == 0) {
        CPair *pmessageNext = ((CPair *)pmessage->ref.n)->next;
        printf("Splice assert: ");
        RefOpPrint(&refTemp, 1, &pmessageNext->ref, pframe);
        CRef_Destruct(&refTemp);
    }
    CRef_Destruct(&refResult);
    SetTag__4CRef4TAGK(&refResult, 0x24);
    CRef_CopyConstruct(pref, &refResult);
    CRef_Destruct(&refResult);
    return pref;
}

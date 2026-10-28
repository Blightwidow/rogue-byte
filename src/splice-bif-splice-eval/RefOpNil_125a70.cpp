struct CRef { int tagk; int n; };
struct CFrame;
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_Destruct(CRef *);
extern "C" CRef *RefOpNil_125a70(CRef *pref, int carg, CRef *aref, CFrame *pframe)
{
    CRef refResult;
    refResult.tagk = -1;
    CRef_CopyConstruct(pref, &refResult);
    CRef_Destruct(&refResult);
    return pref;
}

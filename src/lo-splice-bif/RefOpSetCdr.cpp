struct CRef { int tagk; int n; };
struct CFrame;
extern "C" CRef *RefOpSetCarOrCdr(CRef *, int, CRef *, CFrame *, int);
extern "C" CRef *RefOpSetCdr(CRef *prefReturn, int carg, CRef *aref, CFrame *pframe)
{
    RefOpSetCarOrCdr(prefReturn, carg, aref, pframe, 0x24);
    return prefReturn;
}

struct CRef { int tagk; int n; };
struct CFrame;
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
CRef *RefOpList__FiP4CRefP6CFrame(CRef *prefReturn, int carg, CRef *aref)
{
    CRef_CopyConstruct(prefReturn, aref);
    return prefReturn;
}

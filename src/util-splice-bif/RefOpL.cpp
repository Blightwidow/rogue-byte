struct CRef { int tagk; int n; };
struct CFrame;
extern "C" CRef *RefCmp(CRef *, CRef *, int);
CRef *RefOpL(CRef *prefReturn, int cref, CRef *aref)
{
    RefCmp(prefReturn, aref, 0);
    return prefReturn;
}

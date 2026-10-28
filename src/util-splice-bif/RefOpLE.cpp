struct CRef { int tagk; int n; };
struct CFrame;
extern "C" CRef *RefCmp(CRef *, CRef *, int);
CRef *RefOpLE(CRef *prefReturn, int cref, CRef *aref)
{
    RefCmp(prefReturn, aref, 1);
    return prefReturn;
}

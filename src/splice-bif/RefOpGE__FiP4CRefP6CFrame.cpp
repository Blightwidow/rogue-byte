struct CRef { int tagk; int n; CRef(const CRef &); ~CRef(); };
struct CFrame;
extern "C" CRef RefCmp(CRef *, int);
CRef RefOpGE__FiP4CRefP6CFrame(int cref, CRef *aref, CFrame *pframe)
{
    return RefCmp(aref, 3);
}

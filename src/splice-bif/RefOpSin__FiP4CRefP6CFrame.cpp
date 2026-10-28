struct CRef { int tagk; int n; CRef(const CRef &); ~CRef(); };
struct CFrame;
enum UFOK { kUfokSqrt };
CRef RefUfo__FP4CRef4UFOK(CRef *, UFOK);
CRef RefOpSin__FiP4CRefP6CFrame(int cref, CRef *aref, CFrame *pframe)
{
    return RefUfo__FP4CRef4UFOK(aref, (UFOK)1);
}

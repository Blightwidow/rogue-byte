struct CRef { int tagk; int n; };
struct CFrame;
extern "C" CRef *RefOpObjectOption__FiP4CRefP6CFrame4BIFK(CRef *, int, CRef *, CFrame *, int);
extern "C" CRef *RefOpGetO(CRef *pref, int carg, CRef *aref, CFrame *pframe)
{
    RefOpObjectOption__FiP4CRefP6CFrame4BIFK(pref, carg, aref, pframe, 0x6F);
    return pref;
}

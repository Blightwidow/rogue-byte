struct CRef { int tagk; int n; };
struct CFrame;
extern "C" CRef *SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *RefOpPrint(CRef *pref, int carg, CRef *aref, CFrame *pframe)
{
    SetTag__4CRef4TAGK(pref, 0x24);
    return pref;
}

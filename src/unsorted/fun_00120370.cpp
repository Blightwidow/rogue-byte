struct CRef { int tagk; int n; };
inline CRef *SetBoolRef(CRef *pref, int f)
{
    pref->tagk = 0x17;
    pref->n = f;
    return pref;
}
extern "C" CRef *func_00120370(CRef *pref, int carg, CRef *aref, void *pframe)
{
    return SetBoolRef(pref, aref[0].n==aref[1].n);
}

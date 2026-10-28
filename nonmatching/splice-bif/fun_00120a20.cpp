struct CRef { int tagk; int n; };
static inline CRef *SetBoolRef(CRef *pref, int fValue)
{
    pref->n = fValue;
    pref->tagk = 0x17;
    return pref;
}
extern "C" CRef *func_00120A20(CRef *prefReturn, int cref, CRef *aref)
{
    return SetBoolRef(prefReturn, aref->tagk == 0x20 || aref->tagk == 0x19);
}

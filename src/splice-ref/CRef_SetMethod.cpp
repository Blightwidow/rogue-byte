struct CRef { int tagk; int *pm; };
extern "C" {
void CRef_Destruct(CRef *);
CRef *CRef_SetMethod(CRef *pref, int *pm)
{
    ++*pm;
    CRef_Destruct(pref);
    pref->pm = pm;
    pref->tagk = 0x22;
    return pref;
}
}

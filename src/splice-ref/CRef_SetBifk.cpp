// 0x129618 CRef_SetBifk
extern "C" {
struct CRef {
    int tagk;   // 0
    int n;      // 4
};
void CRef_Destruct(CRef *pref);
}
CRef* CRef_SetBifk(CRef* pref, int bifk)
{
    CRef_Destruct(pref);
    pref->n = bifk;
    pref->tagk = 0x19;
    return pref;
}
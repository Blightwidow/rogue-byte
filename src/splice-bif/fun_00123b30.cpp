struct CRef { int tagk; int n; };
extern "C" CRef *CRef_ConstructBasic(CRef *, int);
extern "C" int B_003E0FA4;
extern "C" CRef *func_00123B30(CRef *pref)
{
    CRef_ConstructBasic(pref, B_003E0FA4);
    return pref;
}

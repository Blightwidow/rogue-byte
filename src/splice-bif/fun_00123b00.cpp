struct CRef { int tagk; int n; };
extern "C" CRef *CRef_ConstructBasic(CRef *, int);
extern "C" int B_003E0FA0;
extern "C" CRef *func_00123B00(CRef *pref)
{
    CRef_ConstructBasic(pref, B_003E0FA0);
    return pref;
}

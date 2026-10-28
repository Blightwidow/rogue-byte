// SPDX-License-Identifier: GPL-3.0-or-later
struct CRef { int tagk; int n; };
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_Destruct(CRef *);
CRef *RefOpNil_125fb0(CRef *pref)
{
    CRef result;
    result.tagk = -1;
    CRef_CopyConstruct(pref, &result);
    CRef_Destruct(&result);
    return pref;
}

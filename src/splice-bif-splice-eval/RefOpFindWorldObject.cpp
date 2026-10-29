// SPDX-License-Identifier: GPL-3.0-or-later
struct CRef { int tagk; int n; CRef &operator=(const CRef &); };
extern "C" {
CRef *CRef_SetBasic(CRef *, void *);
void CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
extern char B_003DD490[];
}

extern "C" CRef *RefOpFindWorldObject(CRef *pref)
{
    CRef refTemp;
    refTemp.tagk = -1;
    CRef_SetBasic(&refTemp, B_003DD490);
    CRef_CopyConstruct(pref, &refTemp);
    CRef_Destruct(&refTemp);
    return pref;
}

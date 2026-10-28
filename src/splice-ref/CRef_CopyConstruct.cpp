// SPDX-License-Identifier: GPL-3.0-or-later
struct CRef { int tagk; int n; };
extern "C" void CRef_AddRef(CRef *);
extern "C" CRef *CRef_CopyConstruct(CRef *pref, CRef *prefSource)
{
    pref->tagk = prefSource->tagk;
    pref->n = prefSource->n;
    CRef_AddRef(pref);
    return pref;
}

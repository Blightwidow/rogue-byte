// SPDX-License-Identifier: GPL-3.0-or-later
struct CRef { int tagk; void *pv; };
extern "C" CRef *CRef_ConstructPair(CRef *pref, int *pshared)
{
    pref->pv = pshared;
    pref->tagk = 0x1F;
    (*pshared)++;
    return pref;
}

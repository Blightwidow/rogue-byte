// SPDX-License-Identifier: GPL-3.0-or-later
struct CRef { int tagk; int n; };
inline CRef *SetBoolRef(CRef *pref, int f)
{
    pref->tagk = 0x17;
    pref->n = f;
    return pref;
}
extern "C" CRef *func_00120880(CRef *pref, int carg, CRef *aref, void *pframe)
{
    return SetBoolRef(pref, aref[0].tagk == 0x15);
}

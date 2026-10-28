// SPDX-License-Identifier: GPL-3.0-or-later
struct CRef { int tagk; float g; };
struct CRefInt { int tagk; int n; };
inline CRefInt *SetIntRef(CRefInt *pref, int value)
{
    pref->tagk = 0x15;
    pref->n = value;
    return pref;
}
extern "C" CRefInt *func_00123688(CRefInt *pref, int carg, CRef *aref, void *pframe)
{
    return SetIntRef(pref, (int)(aref[0].g + 1.0f));
}

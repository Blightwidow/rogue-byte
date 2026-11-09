// SPDX-License-Identifier: GPL-3.0-or-later
#include "cref.h"
inline CRef *SetBoolRef(CRef *pref, int f)
{
    pref->m_tagk = TAGK_Bool;
    pref->m_tag.m_n = f;
    return pref;
}
extern "C" CRef *func_001208E0(CRef *pref, int carg, CRef *aref, void *pframe)
{
    return SetBoolRef(pref, aref[0].m_tagk == TAGK_Matrix);
}

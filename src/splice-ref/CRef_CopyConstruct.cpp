// SPDX-License-Identifier: GPL-3.0-or-later
#include "cref.h"
extern "C" void CRef_AddRef(CRef *);
extern "C" CRef *CRef_CopyConstruct(CRef *pref, CRef *prefSource)
{
    pref->m_tagk = prefSource->m_tagk;
    pref->m_tag.m_n = prefSource->m_tag.m_n;
    CRef_AddRef(pref);
    return pref;
}

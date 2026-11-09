#include "cref.h"
inline CRef *SetBoolRef(CRef *pref, int f)
{
    pref->m_tagk = TAGK_Bool;
    pref->m_tag.m_n = f;
    return pref;
}
extern "C" CRef *func_00120370(CRef *pref, int carg, CRef *aref, void *pframe)
{
    return SetBoolRef(pref, aref[0].m_tag.m_n==aref[1].m_tag.m_n);
}

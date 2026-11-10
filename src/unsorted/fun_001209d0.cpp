#include "cref.h"
static inline CRef *SetBoolRef(CRef *pref, int fValue)
{
    pref->m_tag.m_n = fValue;
    pref->m_tagk = TAGK_Bool;
    return pref;
}
extern "C" CRef *func_001209D0(CRef *prefReturn, int cref, CRef *aref)
{
    return SetBoolRef(prefReturn, aref->m_tagk == TAGK_Basic && aref->m_tag.m_n == 0);
}

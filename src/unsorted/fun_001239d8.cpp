#include "cref.h"
extern "C" CRef *func_001239D8(CRef *prefReturn, int carg, CRef *aref)
{
    int rem = aref[0].m_tag.m_n % aref[1].m_tag.m_n;
    prefReturn->m_tagk = TAGK_S32;
    prefReturn->m_tag.m_n = rem;
    return prefReturn;
}

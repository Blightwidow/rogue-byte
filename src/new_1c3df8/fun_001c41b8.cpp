// SPDX-License-Identifier: GPL-3.0-or-later
#include "lo.h"
#include "cref.h"

int func_001C41B8(BASIC *pbasic)
{
    int fResult = 1;
    CRef ref;
    ref.m_tag.m_bool = fResult;
    ref.m_tagk = TAGK_Bool;
    pbasic->HandleSpliceEvent(0xD, 0, 0, 0, (int)&ref);
    if (ref.m_tagk == TAGK_Bool) {
        fResult = ref.m_tag.m_bool;
    }
    return fResult;
}

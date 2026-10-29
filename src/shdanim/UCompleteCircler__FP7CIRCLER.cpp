// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"

extern "C" float GModPositive__Fff(float, float);
extern "C" float g_2dded0;

extern "C" float UCompleteCircler__FP7CIRCLER(char *circler)
{
    return GModPositive__Fff(g_2dded0 * *(float *)(circler + 0x50), 6.2831855f) * 0.15915494f;
}

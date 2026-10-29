// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"

extern "C" void RecalcClockRate(void);
extern "C" float g_2dded0;

extern "C" void InitClock(int *clock)
{
    float *rates;
    *clock = 0;
    rates = &g_2dded0;
    rates[0x18 / 4] = 1.0f;
    rates[0x1C / 4] = 1.0f;
    rates[0x20 / 4] = 1.0f;
    rates[0x2C / 4] = 1.0f;
    rates[0x30 / 4] = 1.0f;
    rates[0x38 / 4] = 1.0f;
    rates[0x34 / 4] = 1.0f;
    rates[0x28 / 4] = 1.0f;
    RecalcClockRate();
}

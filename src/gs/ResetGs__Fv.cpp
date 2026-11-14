// SPDX-License-Identifier: GPL-3.0-or-later
// source:sly1-decomp HandleGsFinish (src/main/display.cpp, AGPL-3.0, same maintainers), a draft that scores 0
#include "types.h"
#include "ps2inline.h"
extern s32 D_002DFB54;
extern s32 D_002DFB50;
extern "C" void iSignalSema(s32);
s32 ResetGs(void)
{
    if (D_002DFB54 != 0 && (*(volatile u64*)0x12001000 & 2)) {
        D_002DFB54 = 0;
        iSignalSema(D_002DFB50);
    }
    MemoryBarrier();
    EnableInterrupts();
    return -1;
}

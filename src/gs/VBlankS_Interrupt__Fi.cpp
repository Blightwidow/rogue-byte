// SPDX-License-Identifier: GPL-3.0-or-later
// source:sly1-decomp HandleVblankStart (src/main/display.cpp, AGPL-3.0, same maintainers), a draft that scores 0
#include "types.h"
#include "ps2inline.h"
extern s32 D_002DFB58;
extern s32 D_002DFB4C;
extern s32 D_002DEDBC;
extern s32 D_002DFB5C;
extern s32 D_002BE594;
extern s32 D_002BE590;
extern s32 D_002DEDB0;
extern s32 D_002DFB60;
extern u8 D_002DEB80[];
extern "C" void iSignalSema(s32);
void BlendDisplayOnBufferMismatch(void);
void sceGsPutDispEnv(void*);
s32 VBlankS_Interrupt(s32 cause)
{
    if (D_002DFB58 != 0) {
        D_002DFB58 = 0;
        iSignalSema(D_002DFB4C);
    }
    switch (D_002DEDBC) {
    case 1:
        if (D_002DFB5C == 0) {
            D_002BE594 = D_002BE590;
            BlendDisplayOnBufferMismatch();
        }
        break;
    case 2:
        if (D_002DFB5C == 0) {
            BlendDisplayOnBufferMismatch();
        }
        break;
    case 3: {
        s32 n = D_002DEDB0 + 1;
        D_002DFB60 = 1;
        D_002DEDB0 = n;
        sceGsPutDispEnv(D_002DEB80 + (n & 1) * 0x28);
        break;
    }
    }
    MemoryBarrier();
    EnableInterrupts();
    return 0;
}

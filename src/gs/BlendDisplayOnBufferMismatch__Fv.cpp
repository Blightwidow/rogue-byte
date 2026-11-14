// SPDX-License-Identifier: GPL-3.0-or-later
// source:sly1-decomp ApplyFieldDisplayOffset (src/main/display.cpp, AGPL-3.0, same maintainers), a draft that scores 0
#include "types.h"
struct GsPmode { u32 en1 : 1; u32 rest : 31; u32 hi : 32; };
struct GsDispFb { u32 fbp : 9; u32 fbw : 6; u32 psm : 5; u32 pad0 : 12; u32 dbx : 11; u32 dby : 11; u32 pad1 : 10; };
struct GsDisplay { u32 dx : 12; u32 dy : 11; u32 magh : 4; u32 magv : 2; u32 pad0 : 3; u32 dw : 12; u32 dh : 11; u32 pad1 : 9; };
struct DisplayRegs { GsPmode pmode; u64 pad; GsDispFb dispfb; GsDisplay display; u64 pad2; };
struct GsPrivRegs {
    GsPmode pmode; u8 pad0[0x70 - 8];
    GsDispFb dispfb2; u8 pad1[8];
    GsDisplay display2; u8 pad2[0x1000 - 0x88];
    u32 csr;
};
extern s32 D_002DEDB0;
extern s32 D_002DEDB8;
extern u8 D_002DEB80;
void BlendDisplayOnBufferMismatch(void)
{
    s32 i = D_002DEDB0 & 1;
    s32 field = D_002DEDB8;
    GsPmode pm = ((DisplayRegs*)&D_002DEB80)[i].pmode;

    if (field != (s32)((((GsPrivRegs*)0x12000000)->csr >> 13) & 1)) {
        GsDisplay d = ((DisplayRegs*)&D_002DEB80)[i].display;
        GsDispFb fb = ((DisplayRegs*)&D_002DEB80)[i].dispfb;
        d.dh = d.dh - 1;
        if (field != 0) {
            d.dy = d.dy + 1;
        } else {
            fb.dby = fb.dby + 1;
        }
        ((GsPrivRegs*)0x12000000)->display2 = d;
        ((GsPrivRegs*)0x12000000)->dispfb2 = fb;
        pm.en1 = 1;
    }
    ((GsPrivRegs*)0x12000000)->pmode = pm;
}

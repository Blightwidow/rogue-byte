/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct DESC { char pad0[8]; char *pbufA; int cbA; char pad1[0x18 - 0x10]; char *pbufB; int cbB; char pad2[0x50 - 0x20]; };
extern "C" int B_003D3980;
extern "C" DESC B_002DEA50[2];
extern "C" char B_003CF980[];
extern "C" char B_002F7980[];
extern "C" char B_00303980[];
extern "C" void FlushCache(int);
extern "C" void func_001C2A78(int bufmode)
{
    if (bufmode == B_003D3980)
        return;
    FlushCache(0);
    B_003D3980 = bufmode;
    switch (bufmode) {
    case 3:
        for (int idesc = 0; idesc < 2; idesc++) {
            DESC *pdesc = &B_002DEA50[idesc];
            pdesc->pbufA = B_002F7980 + idesc * 0x6000;
            pdesc->cbA = 0x600;
            pdesc->pbufB = B_00303980 + idesc * 0x58000;
            pdesc->cbB = 0x5800;
        }
        break;
    case 2:
        for (int idesc = 0; idesc < 2; idesc++) {
            DESC *pdesc = &B_002DEA50[idesc];
            pdesc->pbufA = B_003CF980 + idesc * 0x1800;
            pdesc->cbA = 0x180;
            pdesc->pbufB = B_003CF980 + 0x3000 + idesc * 0x800;
            pdesc->cbB = 0x80;
        }
        break;
    default:
        for (int idesc = 0; idesc < 2; idesc++) {
            DESC *pdesc = &B_002DEA50[idesc];
            pdesc->cbA = 0;
            pdesc->pbufA = 0;
            pdesc->cbB = 0;
            pdesc->pbufB = 0;
        }
    }
}

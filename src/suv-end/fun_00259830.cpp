// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct EMITB { char pad[0xC0]; int block; };
struct EMITTER { char pad[0xE4]; EMITB *pemitb; };
struct B16 { char b[16]; };
struct BLK { int kind; char pad[0x2C]; B16 data; };
extern "C" BLK *func_00259330(EMITTER *, int);
extern float g_2bde00;
extern B16 D_002BDDF0;
extern "C" void func_00259830(EMITTER *emitter, int blipmk)
{
    BLK *blk = func_00259330(emitter, 1);
    if (blk->kind == blipmk || emitter->pemitb->block != 0)
        return;
    blk->kind = blipmk;
    if (blipmk != 1) {
        if (blipmk == 2)
            blk->data = D_002BDDF0;
    } else {
        *(float *)&blk->data = g_2bde00;
    }
}

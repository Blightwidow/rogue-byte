// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct DPRIZE {
    char pad0[0x40];
    unsigned grf;
    char pad1[0x150 - 0x44];
    int o150; int pad154; int o158; int o15c;
    char pad2[0x1A4 - 0x160];
    int o1a4; int pad1a8; int o1ac; int pad1b0; int o1b4;
    char pad3[0x1C8 - 0x1B8];
    int collectable; float never;
    char pad4[0x204 - 0x1D0];
    int o204; int pad208; int o20c; int pad210; int o214;
    char pad5[0x21C - 0x218];
    float g21c;
    char pad6[0x224 - 0x220];
    int o224;
};
extern float D_002A7710;
extern "C" void InitSo(DPRIZE *);
extern "C" void SetAloInteract(DPRIZE *, int, int);
extern "C" void InitDprize(DPRIZE *dprize)
{
    InitSo(dprize);
    SetAloInteract(dprize, 0x17E, 8);
    dprize->collectable = 1;
    dprize->g21c = 30.0f;
    dprize->o150 = -1;
    dprize->o158 = 0;
    dprize->o15c = -1;
    dprize->o1a4 = -1;
    dprize->o1ac = -1;
    dprize->o1b4 = -1;
    dprize->o204 = -1;
    dprize->o20c = -1;
    dprize->o214 = -1;
    dprize->never = D_002A7710;
    dprize->o224 = -1;
    int heap = (dprize->grf & 1) == 0;
    if (heap)
        *(unsigned *)dprize->grf |= 2;
    else
        dprize->grf |= 2;
}

// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct B8 { char b[8]; };
extern B8 D_002C4400;
struct TANK {
    char pad0[0x19C];
    float a19c, a1a0, a1a4, a1a8;
    float f1ac, f1b0;
    char pad1b4[8];
    float f1bc;
    char pad1c0[12];
    int f1cc;
    TANK *f1d0;
    int f1d4;
};
extern "C" void InitPo(TANK *);
void InitTank(TANK *t)
{
    InitPo(t);
    *(B8 *)((char *)t + 0x1AC) = D_002C4400;
    t->f1bc = t->f1b0;
    t->a1a4 = -1.5f;
    t->a1a8 = 1.5f;
    t->a19c = -0.7f;
    t->a1a0 = 0.7f;
    t->f1cc = 1;
    t->f1d4 = 1;
    t->f1d0 = t;
}

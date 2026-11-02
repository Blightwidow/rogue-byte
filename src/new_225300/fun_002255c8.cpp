// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct PHYS { char pad[0x80]; QW grav; };
struct SO { char pad[0xE8]; PHYS *phys; };
struct XA { int pad; SO *so; };
struct DYSH { char pad[0x1B0]; void *anchor; };
extern QW g_2a2dd0;
extern char D_002C43D0[], D_002C43E0[];
extern "C" {
void AddSoAcceleration(SO *, QW);
QW PosLoWorld(void *);
void AccelSoTowardPosSpring(SO *, QW, void *, QW, void *);
}
void func_002255C8(DYSH *dysh, XA *xa)
{
    SO *so = xa->so;
    QW accel;
    QW spill;
    float minus = -1.0f;
    PHYS *phys = so->phys;
    asm("qmtc2.ni %0, vf2" : : "r" (minus));
    asm("lqc2 vf1, %1\n\tvmulx.xyzw vf3, vf1, vf2x\n\tsqc2 vf2, %0" : "=m" (spill) : "m" (phys->grav));
    asm("qmfc2.ni %0, vf3" : "=r" (accel));
    AddSoAcceleration(so, accel);
    QW pos;
    void *anchor = dysh->anchor;
    if (anchor != 0) pos = PosLoWorld(anchor);
    else pos = PosLoWorld(dysh);
    AccelSoTowardPosSpring(so, pos, D_002C43D0, g_2a2dd0, D_002C43E0);
}

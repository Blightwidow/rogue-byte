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
static inline void *Anchor(DYSH *d) { return d->anchor; }
void func_002255C8(DYSH *dysh, XA *xa)
{
    SO *so = xa->so;
    PHYS *phys = so->phys;
    int neg;
    QW accel;
    QW spill;
    float minus = -1.0f;
    asm("mfc1 %0, %1" : "=r" (neg) : "f" (minus));
    asm("qmtc2.ni %0, vf2" : : "r" (neg));
    asm("lqc2 vf1, %0" : : "m" (phys->grav));
    asm("vmulx.xyzw vf3, vf1, vf2x");
    asm volatile("sqc2 vf2, %0" : "=m" (spill));
    asm("qmfc2.ni %0, vf3" : "=r" (accel));
    AddSoAcceleration(so, accel);
    void *anchor = Anchor(dysh) != 0 ? Anchor(dysh) : (void *)dysh;
    QW pos = PosLoWorld(anchor);
    AccelSoTowardPosSpring(so, pos, D_002C43D0, g_2a2dd0, D_002C43E0);
}

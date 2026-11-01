#include "sly2.h"
struct PHYS { char pad[0xA0]; int ctTorque; char padA4[0x1C]; int ctForce; };
struct SO { char pad[0xE8]; PHYS *phys; };
struct XP { char pad[0x50]; char *xpd; };
extern "C" QW DvFromImpulse(SO *, QW);
extern "C" QW DwFromImpulseAtPos(SO *, QW, QW);

extern "C" void AdjustSoXpVelocity(SO *so, int a1, XP *xp, int a3, int ixpd)
{
    PHYS *phys = so->phys;
    if (!phys) return;
    asm volatile("lqc2 vf2, 0x40(%0)" : : "r"(xp));
    if (ixpd) {
        float minusOne = -1.0f;
        QW bits;
        QW scratch;
        asm volatile("mfc1 %0, %1" : "=r"(bits) : "f"(minusOne));
        asm volatile("qmtc2.ni %0, vf1" : : "r"(bits));
        asm volatile("sqc2 vf1, %0" : "=m"(scratch));
        asm volatile("vmulx.xyzw vf2, vf2, vf1x");
    }
    char *dvdw = (char *)xp + ixpd * 32;
    if (phys->ctForce != 3) {
        QW dir;
        QW spill;
        asm volatile("qmfc2.ni %0, vf2" : "=r"(dir));
        asm volatile("sqc2 vf2, %0" : "=m"(spill));
        *(QW *)dvdw = DvFromImpulse(so, dir);
        asm volatile("lqc2 vf2, %0" : : "m"(spill));
    }
    if (phys->ctTorque != 3) {
        QW dir;
        asm volatile("qmfc2.ni %0, vf2" : "=r"(dir));
        *(QW *)(dvdw + 0x10) = DwFromImpulseAtPos(so, *(QW *)(xp->xpd + ixpd * 64 + 0x10), dir);
    }
}

#include "sly2.h"
struct GRAB { char pad[0x1C0]; int state; char pad2[0x1CC - 0x1C4]; void *planchor; };
extern "C" {
void UpdateSo(GRAB *);
QW PosLoWorld(void *);
int func_0017F550(GRAB *);
void func_001815E8(GRAB *, int);
extern float g_2be880;
extern void *g_2dfb80;
}
extern "C" void func_00181478(GRAB *pgrab)
{
    int stateBefore;
    UpdateSo(pgrab);
    do {
        stateBefore = pgrab->state;
        switch (stateBefore) {
        case 0:
        {
            if (g_2dfb80) {
                QW posPlayer = PosLoWorld(g_2dfb80);
                QW slot;
                asm("qmtc2.ni %0, vf1" : : "r" (posPlayer));
                asm("sqc2 vf1, %0" : "=m" (slot));
                QW posAnchor = PosLoWorld(pgrab->planchor);
                float length;
                asm("qmtc2.ni %0, vf2" : : "r" (posAnchor));
                asm("lqc2 vf1, %0" : : "m" (slot));
                asm("vsub.xyzw vf1, vf1, vf2\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
                asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
                register int bits asm("$3");
                asm("qmfc2.ni %0, vf1" : "=r" (bits));
                asm("mtc1 %1, %0\n\tnop" : "=f" (length) : "r" (bits));
                float range = g_2be880;
                int close = length < range;
                if (close) {
                    *(void **)((char *)pgrab + 0x1C8) = g_2dfb80;
                    func_001815E8(pgrab, 1);
                }
            }
        }
        break;
        case 1:
            if (func_0017F550(pgrab))
                func_001815E8(pgrab, 2);
            break;
        }
    } while (pgrab->state != stateBefore);
}

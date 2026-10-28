// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct Alo { char pad0[0x10C]; int fNoReach; };
struct Jt { char pad0[0x240]; QW grab; char pad250[0xDEC]; float reach; int flipped; };
extern "C" QW PosLoWorld(Alo *);
extern "C" QW *PmatLoWorld(Alo *);
extern "C" float atan2f(float, float);
extern "C" void AttachFlat_GetPosFromParam(Alo *alo, Jt *jt, QW *ppos, float *pheading)
{
    float reach = 0.0f;
    if (alo->fNoReach == 0)
        reach = jt->reach;
    QW axis = *PmatLoWorld(alo);
    if (ppos) {
        QW tmp;
        int bits;
        QW center = PosLoWorld(alo);
        asm("" : : "r" (jt));
        asm("" : : "r" (jt));

        asm volatile("lqc2 vf1, 0x240(%2)\n\tqmtc2.ni %3, vf4\n\tmfc1 %1, %6\n\tvsub.xyzw vf2, vf4, vf1\n\tqmtc2.ni %1, vf3\n\tqmtc2.ni %4, vf1\n\tsqc2 vf3, %0\n\tvadda.xyzw ACC, vf0, vf2\n\tvmaddx.xyzw vf2, vf1, vf3x\n\tsqc2 vf2, 0(%5)" : "=m" (tmp), "=&r" (bits) : "r" (jt), "r" (center), "r" (axis), "r" (ppos), "f" (reach));
    }
    if (pheading) {
        int rot;
        asm("prot3w %0, %1" : "=r" (rot) : "r" (axis));
        float x, y;
        asm("mtc1 %1, %0" : "=f" (x) : "r" (axis));
        asm("mtc1 %1, %0" : "=f" (y) : "r" (rot));
        float angle = atan2f(y, x);
        if (jt->flipped == 1)
        {
            float pi;
            asm("li.s %0, 3.1415927\n\tnop" : "=f" (pi));
            angle = angle + pi;
        }
        *pheading = angle;
    }
}

// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct VOL { char pad0[0xEC]; void *cbsp; char pad1[0x20]; QW center; float radius; };
extern "C" {
QW ConvertAloPos(void *, VOL *, QW);
int PcgtPointInCbspQuick__FP4CBSPP6VECTOR(void *, int, QW);
}
static inline int Lt(float a, float b) { return a < b; }
int func_00227C90(VOL *vol, QW pos)
{
    QW local = ConvertAloPos(0, vol, pos);
    float fdist;
    float radius = vol->radius;
    int outside = 1;
    asm("qmtc2.ni %0, vf3" : : "r" (local));
    asm("lqc2 vf1, %0" : : "m" (vol->center));
    asm("vsub.xyzw vf1, vf3, vf1\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tqmfc2.ni $3, vf1\n\tmtc1 $3, %0" : "=f" (fdist) : : "$3");
    outside = Lt(radius, fdist);
    if (outside)
        return 0;
    QW again;
    asm("qmfc2.ni %0, vf3" : "=r" (again));
    return PcgtPointInCbspQuick__FP4CBSPP6VECTOR(vol->cbsp, 0x7FFFFFFF, again) != 0;
}

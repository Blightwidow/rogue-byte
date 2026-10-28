// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct Alo { char pad[0x10C]; float radius; };
extern "C" float GRandInRange(float, float);
extern "C" QW PosLoWorld(Alo *);
extern "C" QW SetVectorCylind__FP6VECTORfff(float, float, float);
extern float g_2be8c4;
extern QW g_2a2dc0;

extern "C" void AttachCyl_GetRandomPos(Alo *alo, QW *pos, QW *normal)
{
    float angle = GRandInRange(-3.1415927f, 3.1415927f);
    float extra = GRandInRange(0.0f, g_2be8c4);
    float radius = extra + alo->radius;
    QW center = PosLoWorld(alo);
    asm("" : "+m" (center));
    QW offset = SetVectorCylind__FP6VECTORfff(angle, radius, 0.0f);
    asm("lqc2 vf2, %0" : "+m" (center));
    asm("qmtc2.ni %1, vf3" : "+m" (center) : "r" (offset));
    asm("vadd.xyzw vf1, vf2, vf3" : "+m" (center));
    asm("sqc2 vf1, %0" : "=m" (*pos) : "m" (center));
    *normal = g_2a2dc0;
}

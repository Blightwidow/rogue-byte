// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct MVT { char pad[0x30]; short delta; short index; void *(*fn)(void *); };
struct MEMBER { char pad[0x20]; MVT *vt; };
extern "C" float GRandInRange(float, float);
extern "C" QW PosLoWorld(void *);
extern "C" QW SetVectorSphere__FP6VECTORfff(float, float, float);
extern float g_2be8b0;
extern QW g_2a2dc0;


extern "C" void Member_GetRandomPos(MEMBER *pmember, QW *ppos, QW *pnormal)
{
    void *plo = pmember->vt->fn((char *)pmember + pmember->vt->delta);
    float azimuth = GRandInRange(-3.1415927f, 3.1415927f);
    float g = GRandInRange(-1.0f, 1.0f);
    float elevation = __builtin_fabsf(g) * g * 1.5707964f;
    float radius = GRandInRange(0.0f, g_2be8b0);
    QW center = PosLoWorld(plo);
    asm("" : "+m" (center));
    QW offset = SetVectorSphere__FP6VECTORfff(azimuth, elevation, radius);
    asm("lqc2 vf2, %0" : "+m" (center));
    asm("qmtc2.ni %1, vf3" : "+m" (center) : "r" (offset));
    asm("vadd.xyzw vf1, vf2, vf3" : "+m" (center));
    asm("sqc2 vf1, %0" : "=m" (*ppos) : "m" (center));
    *pnormal = g_2a2dc0;
}

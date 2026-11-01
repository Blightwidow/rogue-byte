// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct SMP { char pad[0x10]; };
struct VT { char pad[0x108]; short delta; short index; QW (*fn)(void *); };
struct OBJ { char pad[0xC]; VT *vptr; char pad2[0xE8 - 0x10]; char *pextra; };
struct SOB { char pad[0x1BC]; int fActive; float sLimit; float gGain; };
struct JT { OBJ *pobj; char pad[4]; int state; char pad2[8]; SOB *pso; char pad3[4]; float u; };
struct Locals { QW up; QW curve; QW scaled; QW scratch; float sMax; float sMin; };
extern "C" {
void EvaluateCrvFromU(void *, int, QW *, float);
float GSmooth__FfffP3SMPPf(float, float, float, SMP *, float *);
void AddSoAcceleration(void *, QW);
extern SMP D_002BF700;
extern float g_2dded0[];
}
// lane 0 of a QW into an FP register (mtc1 reads the low word)
static inline float LaneX(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
extern "C" void PresetJtAccelHide__FP2JT(JT *pjt)
{
    if (pjt->state == 3) {
        SOB *pso = pjt->pso;
        if (pso->fActive != 0) {
            Locals l;
            l.up = pjt->pobj->vptr->fn((char *)pjt->pobj + pjt->pobj->vptr->delta);
            EvaluateCrvFromU(pso, 0, &l.curve, pjt->u);
            QW dotUp;
            asm volatile("lqc2 vf3, %0" : : "m" (l.curve));
            asm volatile("lqc2 vf1, %0" : : "m" (l.up));
            asm volatile("vmul.xyz vf1, vf3, vf1\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf4, vf1z");
            asm volatile("lqc2 vf2, 0x80(%0)" : : "r" (pjt->pobj->pextra));
            QW bitsUp;
            asm("qmfc2.ni %0, vf1" : "=r" (bitsUp));
            asm volatile("vmul.xyz vf3, vf3, vf2\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf3, vf3y\n\tvmaddz.x vf3, vf4, vf3z");
            QW bitsSide;
            asm("qmfc2.ni %0, vf3" : "=r" (bitsSide));
            float dotU = LaneX(bitsUp);
            float dotS = LaneX(bitsSide);
            GSmooth__FfffP3SMPPf(dotU, pso->sLimit, g_2dded0[1], &D_002BF700, &l.sMax);
            GSmooth__FfffP3SMPPf(dotU, -pso->sLimit, g_2dded0[1], &D_002BF700, &l.sMin);
            float sMin = l.sMin;
            float sMax = l.sMax;
            float target = pso->gGain * dotS;
            if (target < sMin)
                target = sMin;
            else if (sMax < target)
                target = sMax;
            float delta = target - dotS;
            asm volatile("lqc2 vf1, %0" : : "m" (l.curve));
            asm volatile("qmtc2.ni %0, vf2" : : "r" (delta));
            asm volatile("vmulx.xyzw vf1, vf1, vf2x");
            asm volatile("sqc2 vf2, %0" : "=m" (l.scratch));
            asm volatile("sqc2 vf1, %0" : "=m" (l.scaled));
            QW accel;
            asm volatile("qmfc2.ni %0, vf1" : "=r" (accel));
            AddSoAcceleration(pjt->pobj, accel);
        }
    }
}

#include "sly2.h"
struct Alo { char pad[0x110]; QW point; };
extern "C" float GRandInRange(float, float);
extern "C" QW ConvertAloPos(Alo *, int, QW);
extern "C" QW SetVectorCylind__FP6VECTORfff(float, float, float);
extern float g_2be90c;
extern QW g_2a2dc0;

extern "C" void AttachZone_GetRandomPos(Alo *zone, QW *pos, QW *normal)
{
    float angle = GRandInRange(-3.1415927f, 3.1415927f);
    float radius = GRandInRange(0.0f, g_2be90c);
    QW center = ConvertAloPos(zone, 0, zone->point);
    QW offset = SetVectorCylind__FP6VECTORfff(angle, radius, 0.0f);
    int step1, step2, step3;
    asm("lqc2 vf2, %1" : "=r" (step1) : "m" (center));
    asm("qmtc2.ni %2, vf3" : "=r" (step2) : "r" (step1), "r" (offset));
    asm("vadd.xyzw vf1, vf2, vf3" : "=r" (step3) : "r" (step2));
    asm("sqc2 vf1, %0" : "=m" (*pos) : "r" (step3));
    *normal = g_2a2dc0;
}

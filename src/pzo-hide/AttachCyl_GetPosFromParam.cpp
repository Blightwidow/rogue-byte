#include "sly2.h"
struct Alo { char pad0[0x10C]; float radius; };
struct Jt { char pad0[0x240]; QW grab; char pad250[0xDEC]; float reach; int flipped; };
extern "C" QW PosLoWorld(Alo *);
extern "C" QW SetVectorCylind__FP6VECTORfff(float, float, float);
extern "C" void AttachCyl_GetPosFromParam(Alo *alo, float arc, Jt *jt, QW *pos, float *heading)
{
    float radius = alo->radius;
    float angle = arc / radius;
    float hang = radius + jt->reach;
    if (pos) {
        QW tmp;
        QW center = PosLoWorld(alo);
        asm volatile("qmtc2.ni %0, vf2" : : "r" (center));
        float zero;
        asm volatile("mtc1 $0, %0" : "=f" (zero));
        asm volatile("sqc2 vf2, %0" : "=m" (tmp));
        QW cyl = SetVectorCylind__FP6VECTORfff(angle, hang, zero);
        asm volatile("lqc2 vf2, %1\n\tqmtc2.ni %2, vf1\n\tvadd.xyzw vf2, vf2, vf1\n\tlqc2 vf1, 0x240(%3)\n\tvsub.xyzw vf2, vf2, vf1\n\tsqc2 vf2, 0(%0)" : : "r" (pos), "m" (tmp), "r" (cyl), "r" (jt));
    }
    if (heading) {
        if (jt->flipped == 1)
        {
            float pi;
            asm("li.s %0, 3.1415927\n\tnop" : "=f" (pi));
            angle = angle + pi;
        }
        *heading = angle;
    }
}

#include "sly2.h"
extern "C" {
void PostLoLoad(void *);
QW PosLoWorld(void *);
QW ConvertAloPos(void *, int, QW);
extern float D_FLT_002BE904;
}
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0\n\tnop" : "=f" (f) : "r" (q)); return f; }
struct Alo { char pad[0x38]; float radius; char pad2[0xD4]; QW point; };

void func_001843F0(Alo *palo)
{
    PostLoLoad(palo);
    float radius = palo->radius;
    float unset;
    asm(".set noat\n\tlui $1, 0x5015\n\tori $1, $1, 0x2F9\n\tmtc1 $1, %0\n\tnop\n\t.set at" : "=f" (unset));
    if (radius == unset) {
        QW spill;
        QW posObject = PosLoWorld(palo);
        asm volatile("qmtc2.ni %0, vf1" : : "r" (posObject));
        QW point = palo->point;
        asm volatile("sqc2 vf1, %0" : "=m" (spill));
        QW posPoint = ConvertAloPos(palo, 0, point);
        asm volatile("qmtc2.ni %0, vf2" : : "r" (posPoint));
        int dummy;
        asm volatile("lqc2 vf1, %0" : : "m" (spill));
        asm("vsub.xyzw vf1, vf1, vf2" : "=r" (dummy));
        float offset = D_FLT_002BE904;
        asm volatile("vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : : "r" (dummy));
        asm volatile("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
        QW result;
        asm volatile("qmfc2.ni %0, vf1" : "=r" (result));
        palo->radius = Lane(result) + offset;
    }
}

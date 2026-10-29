#include "sly2.h"
extern "C" QW PosLoWorld(void *);
extern "C" void DwFromTorque(void *, QW);
extern "C" void DwFromImpulseAtPos(void *lo, QW pos, QW impulse)
{
    QW torque;
    QW lever = PosLoWorld(lo);
    int fence;
    asm("lqc2 vf2, %1" : "=r" (fence) : "m" (pos));
    asm("qmtc2.ni %2, vf3\n\tvsub.xyzw vf1, vf2, vf3\n\tlqc2 vf2, %3\n\tvopmula.xyz ACC, vf1, vf2\n\tvopmsub.xyz vf2, vf2, vf1\n\tqmfc2.ni %0, vf2"
        : "=r" (torque) : "r" (fence), "r" (lever), "m" (impulse));
    DwFromTorque(lo, torque);
}

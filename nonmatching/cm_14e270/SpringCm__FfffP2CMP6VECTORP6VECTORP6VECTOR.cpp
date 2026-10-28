#include "sly2.h"
extern "C" float g_2dded0;
struct Cm { char pad[0x300]; int cut; };
struct V3 { float x, y, z, w; };
extern "C" void SpringCm__FfffP2CMP6VECTORP6VECTORP6VECTOR(float spring, float damping, Cm *cm, V3 *pos, V3 *vel, QW target)
{
    QW junk;
    int cut = cm->cut;
    asm volatile("qmtc2.ni %0, vf2" : : "r" (target));
    if (cut) {
        asm volatile("sqc2 vf2, %0" : "=m" (*pos));
        vel->z = 0.0f;
        vel->y = 0.0f;
        vel->x = 0.0f;
    } else {
        int *pdt = (int *)&g_2dded0;
        asm volatile("qmtc2.ni %0, vf3" : : "r" (spring));
        asm volatile("lqc2 vf1, %0" : : "m" (*pos));
        asm volatile("qmtc2.ni %0, vf4" : : "r" (damping));
        asm volatile("vsub.xyzw vf1, vf2, vf1");
        asm volatile("lqc2 vf2, %2\n\tqmtc2.ni %3, vf5\n\tvmulax.xyzw ACC, vf1, vf3x\n\tvmaddx.xyzw vf1, vf2, vf4x\n\tsqc2 vf3, %0\n\tvadda.xyzw ACC, vf0, vf2\n\tvmaddx.xyzw vf2, vf1, vf5x\n\tsqc2 vf4, %0\n\tsqc2 vf2, %1" : "=m" (junk), "=m" (*vel) : "m" (*vel), "r" (pdt[1]));
        asm volatile("qmtc2.ni %0, vf3\n\tlqc2 vf1, %1" : : "r" (pdt[1]), "m" (*pos));
        asm volatile("sqc2 vf5, %0\n\tvadda.xyzw ACC, vf0, vf1\n\tvmaddx.xyzw vf1, vf2, vf3x\n\tsqc2 vf3, %0\n\tsqc2 vf1, %1" : "=m" (junk), "=m" (*pos));
    }
}

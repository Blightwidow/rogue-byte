#include "sly2.h"
extern "C" QW __ml__FRC7MATRIX4G10VU_VECTOR4(QW *m, QW v)
{
    QW result;
    asm("lqc2 vf4, %2\n\tlqc2 vf3, %3\n\tlqc2 vf2, %4\n\tlqc2 vf1, %5\n\tqmtc2.ni %1, vf5\n\tvmulax.xyzw ACC, vf3, vf5x\n\tvmadday.xyzw ACC, vf2, vf5y\n\tvmaddaz.xyzw ACC, vf1, vf5z\n\tvmaddw.xyzw vf5, vf4, vf5w\n\tqmfc2.ni %0, vf5"
        : "=r" (result) : "r" (v), "m" (m[3]), "m" (m[0]), "m" (m[1]), "m" (m[2]));
    return result;
}

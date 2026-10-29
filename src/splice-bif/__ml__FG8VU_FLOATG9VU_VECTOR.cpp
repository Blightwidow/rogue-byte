#include "sly2.h"
// VU_FLOAT * VU_VECTOR: vector scaled by the float in x of the first argument.
extern "C" QW __ml__FG8VU_FLOATG9VU_VECTOR(QW scale, QW vec) {
    QW result;
    asm("qmtc2.ni %1, vf1\n\tqmtc2.ni %2, vf2\n\tvmulx.xyzw vf1, vf2, vf1x\n\tqmfc2.ni %0, vf1" : "=r" (result) : "r" (scale), "r" (vec));
    return result;
}

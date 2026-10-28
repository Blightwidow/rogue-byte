#include "sly2.h"
struct VU_FLOAT { QW q; };
struct VU_VECTOR { QW q; };
VU_VECTOR VecCombo(VU_FLOAT gA, VU_VECTOR vecA, VU_FLOAT gB, VU_VECTOR vecB)
{
    register QW result asm("$2");
    asm("qmtc2 %1, vf1\n\tqmtc2 %2, vf2\n\tqmtc2 %3, vf3\n\tqmtc2 %4, vf4\n\tvmulax.xyzw ACC, vf2, vf1x\n\tvmaddx.xyzw vf1, vf4, vf3x\n\tqmfc2 %0, vf1"
        : "=r" (result) : "r" (gA.q), "r" (vecA.q), "r" (gB.q), "r" (vecB.q));
    return *(VU_VECTOR *)&result;
}

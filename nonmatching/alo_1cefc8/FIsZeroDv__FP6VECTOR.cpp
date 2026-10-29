#include "sly2.h"
extern "C" int FIsZeroDv__FP6VECTOR(QW v)
{
    int sum;
    asm volatile("qmtc2.ni %0, vf3" : : "r" (v));
    float limit = 25.0f;
    asm volatile("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tqmfc2.ni %0, vf1"
        : "=r" (sum) : "f" (limit));
    float lengthSquared = *(float *)&sum;
    return lengthSquared < limit;
}

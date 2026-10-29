#include "sly2.h"
extern "C" int FIsZeroW__FP6VECTOR(QW v)
{
    float sum;
    int fence;
    asm volatile("qmtc2.ni %1, vf3" : "=r"(fence) : "r"(v));
    float eps = 4e-4f;
    asm volatile("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tqmfc2.ni %0, vf1"
        : "=r"(sum) : "f"(eps), "r"(fence));
    if (eps > sum)
        return 1;
    return 0;
}

#include "sly2.h"
extern "C" float SProjectVector__FP6VECTORT0(QW vector, QW onto, QW *projection, QW *rejection)
{
    QW projected;
    int dot;
    asm volatile("qmtc2.ni %0, vf1\n\tqmtc2.ni %1, vf3\n\tvmul.xyz vf4, vf3, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf4, vf4y\n\tvmaddz.x vf4, vf2, vf4z\n\tvmulx.xyzw vf1, vf1, vf4x" : : "r" (onto), "r" (vector));
    asm("qmfc2.ni %0, vf1" : "=r" (projected));
    if (projection)
        *projection = projected;
    if (rejection)
        asm volatile("vsub.xyzw vf1, vf3, vf1\n\tsqc2 vf1, %0" : "=m" (*rejection));
    asm("qmfc2.ni %0, vf4" : "=r" (dot));
    return *(float *)&dot;
}

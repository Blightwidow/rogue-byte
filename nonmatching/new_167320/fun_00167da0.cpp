#include "sly2.h"
static inline float Lane(int q) { float f; asm("mtc1 %1, %0\n\tnop" : "=f" (f) : "r" (q)); return f; }
extern QW D_002BE570;
extern "C" QW func_00167DA0(QW *block, QW center, float *radius)
{
    QW ret;
    asm volatile("lqc2 vf3, %0" : : "m" (block[1]));
    asm volatile("lqc2 vf1, %0" : : "m" (block[2]));
    asm volatile("lqc2 vf4, %0" : : "m" (D_002BE570));
    asm volatile("lqc2 vf5, %0" : : "m" (block[3]));
    asm volatile("lqc2 vf2, %0" : : "m" (block[0]));
    asm volatile("vmulax.xyz ACC, vf2, vf4x\n\tvmadday.xyz ACC, vf3, vf4y\n\tvmaddaz.xyz ACC, vf1, vf4z\n\tvmaddw.xyz vf2, vf5, vf0w");
    asm volatile("qmtc2.ni %0, vf6" : : "r" (center));
    asm volatile("vsub.xyzw vf2, vf2, vf6");
    float oldRadius = *radius;
    int dist;
    asm volatile("vmul.xyz vf1, vf2, vf2\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf3, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r" (dist));
    float distance = Lane(dist);
    if (oldRadius < distance) {
        float half = 0.5f;
        float diff = (distance - oldRadius) * half;
        float sum = (distance + oldRadius) * half;
        *radius = sum;
        float move = diff / distance;
        QW junk;
        int bits;
        asm volatile("mfc1 %0, %1" : "=r" (bits) : "f" (move));
        asm volatile("qmtc2.ni %1, vf1\n\tsqc2 vf1, %0\n\tvadda.xyzw ACC, vf0, vf6\n\tvmaddx.xyzw vf6, vf2, vf1x" : "=m" (junk) : "r" (bits));
    }
    asm volatile("qmfc2.ni %0, vf6" : "=r" (ret));
    return ret;
}

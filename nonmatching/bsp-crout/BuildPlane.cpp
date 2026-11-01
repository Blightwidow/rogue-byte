#include "sly2.h"
struct PLANE { float x, y, z; int w; };
void BuildPlane(PLANE *pplane, QW pos0, QW pos1, QW pos2)
{
    float normal[4] __attribute__((aligned(16)));
    int dist;
    int f1, f2, f3, f4, f5, f6, f7;
    asm("qmtc2.ni %1, vf4" : "=r" (f1) : "r" (pos0));
    asm("qmtc2.ni %1, vf1" : "=r" (f2) : "r" (pos1), "r" (f1));
    asm("vsub.xyzw vf2, vf1, vf4" : "=r" (f3) : "r" (f2));
    asm("qmtc2.ni %1, vf1" : "=r" (f4) : "r" (pos2), "r" (f3));
    asm("vsub.xyzw vf3, vf1, vf4" : "=r" (f5) : "r" (f4));
    asm("vopmula.xyz ACC, vf2, vf3\n\tvopmsub.xyz vf2, vf3, vf2\n\tvmul.xyz vf1, vf2, vf2\n\tvaddw.x vf5, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf5, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tvdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf1, vf2, Q" : "=r" (f6) : "r" (f5));
    asm("sqc2 vf1, %1" : "=r" (f7), "=m" (normal) : "r" (f6));
    asm("vmul.xyz vf1, vf1, vf4\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : : "r" (f7));
    asm volatile("qmfc2.ni %0, vf1" : "=r" (dist));
    pplane->w = dist;
    pplane->y = normal[1];
    pplane->z = normal[2];
    pplane->x = normal[0];
}

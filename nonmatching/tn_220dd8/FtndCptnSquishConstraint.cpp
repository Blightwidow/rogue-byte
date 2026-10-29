#include "sly2.h"
extern "C" int func_002564B8(void *);
static inline float Lane(int bits) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (bits)); return f; }
extern "C" float FtndCptnSquishConstraint(void *unused, QW normal, void *unused2, QW *plane)
{
    QW n = normal;
    QW tmp0, tmp1, p = plane[1];
    int bits, fence;
    func_002564B8(&tmp0);
    func_002564B8(&tmp1);
    asm("lqc2 vf3, %2\n\tlqc2 vf4, %1\n\tvmul.xyz vf2, vf3, vf4\n\tvaddw.x vf1, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddaz.x ACC, vf1, vf2z\n\tvmsubw.x vf2, vf1, vf3w" : "=r" (fence) : "m" (n), "m" (p));
    asm("qmfc2.ni %0, vf2" : "=r" (bits) : "r" (fence));
    asm("sqc2 vf2, %0" : "=m" (tmp0) : "r" (fence));
    float result = Lane(bits);
    asm("sqc2 vf1, %0" : "=m" (tmp1) : "r" (fence));
    return result;
}

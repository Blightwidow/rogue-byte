#include "sly2.h"
extern "C" void GetNormalVectors__FP6VECTORN30(QW normal, QW ref, QW refAlt, QW *pout)
{
    float lengthSquared;
    register QW v1 asm("vf1");
    asm("qmtc2.ni %0, vf1" : : "r" (ref));
    float limit = 0.0001f;
    register QW v3 asm("vf3") = normal;
    register QW v2 asm("vf2");
    register QW v4 asm("vf4");
    asm("vopmula.xyz ACC, vf1, vf3\n\tvopmsub.xyz vf6, vf3, vf1" : : "j" (v1), "j" (v3));
    asm("qmtc2.ni %0, vf4" : : "r" (refAlt));
    asm("vmul.xyz vf1, vf6, vf6\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "=j" (v1));
    asm("qmfc2.ni $2, vf1\n\tmtc1 $2, %0\n\tnop" : "=f" (lengthSquared) : "j" (v1) : "$2");
    asm("c.lt.s %0, %1\n\tnop\n\tbc1f 1f\n\tvopmula.xyz ACC, vf4, vf3\n\tvopmsub.xyz vf6, vf3, vf4\n1:" : : "f" (lengthSquared), "f" (limit), "j" (v3));
    asm("vopmula.xyz ACC, vf3, vf6\n\tvopmsub.xyz vf1, vf6, vf3\n\tvmul.xyz vf2, vf6, vf6\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf4, vf2z\n\tvmul.xyz vf3, vf1, vf1\n\tvaddw.x vf5, vf0, vf0w\n\tvadday.x ACC, vf3, vf3y\n\tvmaddz.x vf3, vf5, vf3z\n\tvsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q\n\tvsqrt Q, vf3x\n\tvwaitq\n\tvaddq.x vf3, vf0, Q\n\tvdiv Q, vf0w, vf2x\n\tvwaitq\n\tvmulq.xyzw vf2, vf6, Q\n\tvdiv Q, vf0w, vf3x\n\tvwaitq\n\tvmulq.xyzw vf3, vf1, Q" : "=j" (v2), "=j" (v3) : "j" (v3));
    pout[1] = v3;
    pout[0] = v2;
}

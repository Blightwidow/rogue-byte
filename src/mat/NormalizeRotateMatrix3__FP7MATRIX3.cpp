#include "sly2.h"
void NormalizeRotateMatrix3__FP7MATRIX3(MATRIX3 *pmat)
{
    asm("lqc2 vf2, 0(%0)\n\tvmul.xyz vf3, vf2, vf2\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf3, vf3y\n\tvmaddz.x vf3, vf4, vf3z\n\t"
        "lqc2 vf1, 0x10(%0)\n\tvsqrt Q, vf3x\n\tvwaitq\n\tvaddq.x vf3, vf0, Q\n\tvdiv Q, vf0w, vf3x\n\tvwaitq\n\tvmulq.xyzw vf3, vf2, Q\n\t"
        "vopmula.xyz ACC, vf3, vf1\n\tvopmsub.xyz vf1, vf1, vf3\n\tsqc2 vf3, 0(%0)\n\t"
        "vmul.xyz vf2, vf1, vf1\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf4, vf2z\n\t"
        "vsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q\n\tvdiv Q, vf0w, vf2x\n\tvwaitq\n\tvmulq.xyzw vf2, vf1, Q\n\t"
        "vopmula.xyz ACC, vf2, vf3\n\tvopmsub.xyz vf3, vf3, vf2\n\tsqc2 vf2, 0x20(%0)\n\t"
        "vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf4, vf1z\n\t"
        "vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tvdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf1, vf3, Q\n\t"
        "sqc2 vf1, 0x10(%0)" : : "r" (pmat) : "memory");
}

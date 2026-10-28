#include "sly2.h"
extern "C" const MATRIX3 RO_002A2D00;
extern "C" MATRIX3 *LoadRotateMatrixRad(MATRIX3 *, QW, float);
extern "C" MATRIX3 *LoadRotateMatrix(MATRIX3 *pmat, QW vec)
{
    float rad;
    int token1, token2, token3;
    asm("qmtc2.ni %1, vf3" : "=r" (token1) : "r" (vec));
    asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "=r" (token2) : "r" (token1));
    asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=r" (token3) : "r" (token2));
    register int bits asm("$2");
    asm("qmfc2.ni %0, vf1" : "=r" (bits) : "r" (token3));
    asm("mtc1 %1, %0\n\tnop" : "=f" (rad) : "r" (bits));
    if (rad < 0.0001f) {
        memcpy(pmat, &RO_002A2D00, 0x30);
    } else {
        MATRIX3 matRotate;
        QW saved;
        QW axis;
        int token4, token5, token6;
        asm("qmtc2.ni %1, vf1" : "=r" (token4) : "r" (rad));
        asm("vdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf2, vf3, Q" : "=r" (token5) : "r" (token4));
        asm("sqc2 vf1, %1" : "=r" (token6), "=m" (saved) : "r" (token5));
        asm("qmfc2.ni %0, vf2" : "=r" (axis) : "r" (token6));
        LoadRotateMatrixRad(&matRotate, axis, rad);
        memcpy(pmat, &matRotate, 0x30);
    }
    return pmat;
}

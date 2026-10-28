#include "sly2.h"
extern QW g_2a2dc0;
extern QW g_2a2db0;
extern "C" void LoadRotateMatrixRad(MATRIX3 *, QW, float);
extern "C" MATRIX3 *LoadRotateMatrixPanTilt(MATRIX3 *pmat, float radPan, float radTilt)
{
    struct Frame { QW product[3]; QW pan[3]; QW tilt[3]; QW junk[3]; } frame;
    int t12, t13, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11;
    LoadRotateMatrixRad((MATRIX3 *)frame.pan, g_2a2dc0, radPan);
    LoadRotateMatrixRad((MATRIX3 *)frame.tilt, g_2a2db0, -radTilt);
    asm("lqc2 vf6, %1" : "=r" (t1) : "m" (frame.pan[0]));
    asm("lqc2 vf5, %1" : "=r" (t2) : "m" (frame.pan[1]), "r" (t1));
    asm("lqc2 vf1, %1" : "=r" (t3) : "m" (frame.pan[2]), "r" (t2));
    asm("lqc2 vf2, %1" : "=r" (t4) : "m" (frame.tilt[0]), "r" (t3));
    asm("lqc2 vf3, %1" : "=r" (t5) : "m" (frame.tilt[1]), "r" (t4));
    asm("vmulax.xyz ACC, vf6, vf2x\n\tvmadday.xyz ACC, vf5, vf2y\n\tvmaddz.xyz vf2, vf1, vf2z\n\tvmulax.xyz ACC, vf6, vf3x\n\tvmadday.xyz ACC, vf5, vf3y\n\tvmaddz.xyz vf3, vf1, vf3z" : "=r" (t6) : "r" (t1), "r" (t2), "r" (t3), "r" (t4), "r" (t5));
    asm("lqc2 vf4, %1" : "=r" (t7) : "m" (frame.tilt[2]), "r" (t6));
    asm("vmulax.xyz ACC, vf6, vf4x\n\tvmadday.xyz ACC, vf5, vf4y\n\tvmaddz.xyz vf6, vf1, vf4z" : "=r" (t8) : "r" (t6), "r" (t7));
    asm("sqc2 vf2, %1" : "=r" (t9), "=m" (frame.product[0]) : "r" (t8));
    asm("sqc2 vf3, %1" : "=r" (t10), "=m" (frame.product[1]) : "r" (t9));
    asm("sqc2 vf6, %1" : "=r" (t11), "=m" (frame.product[2]) : "r" (t10));
    asm("sqc2 vf2, %1" : "=r" (t12), "=m" (frame.junk[0]) : "r" (t11));
    asm("sqc2 vf3, %1" : "=r" (t13), "=m" (frame.junk[1]) : "r" (t12));
    asm("sqc2 vf6, %0" : "=m" (frame.junk[2]) : "r" (t13));
    memcpy(pmat, frame.product, 0x30);
    return pmat;
}

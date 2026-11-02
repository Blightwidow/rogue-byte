#include "sly2.h"
extern "C" MATRIX3 *LoadRotateMatrixSinCos(MATRIX3 *pmat, int sinBits, int cosBits, int axisBits)
{
    // t1..t9 chain the VU0 blocks in retail's order (fence tokens); junk is the dead frame area retail stores vf1..vf3 into
    QW junk[3];
    int t1, t2, t3, t4, t5, t6, t7, t8, t9;
    asm("qmtc2.ni %1, vf6" : "=r" (t1) : "r" (cosBits));
    asm("qmtc2.ni %1, vf7" : "=r" (t2) : "r" (sinBits), "r" (t1));
    asm("qmtc2.ni %1, vf8" : "=r" (t3) : "r" (axisBits), "r" (t2));
    asm("vsubx.w vf5, vf0, vf6x\n\tvsub.w vf1, vf0, vf0\n\tvsub.w vf2, vf0, vf0\n\tvsub.w vf3, vf0, vf0\n\tvmulw.xyz vf5, vf8, vf5w\n\tvmulx.xyz vf4, vf8, vf7x\n\tvmulx.xyz vf1, vf5, vf8x\n\tvmuly.xyz vf2, vf5, vf8y\n\tvmulz.xyz vf3, vf5, vf8z\n\tvaddx.x vf1, vf1, vf6x\n\tvaddx.y vf2, vf2, vf6x\n\tvaddx.z vf3, vf3, vf6x\n\tvaddz.y vf1, vf1, vf4z\n\tvsubz.x vf2, vf2, vf4z\n\tvsuby.z vf1, vf1, vf4y\n\tvaddy.x vf3, vf3, vf4y\n\tvaddx.z vf2, vf2, vf4x\n\tvsubx.y vf3, vf3, vf4x" : "=r" (t4) : "r" (t3));
    asm("sqc2 vf2, %1" : "=r" (t5), "=m" (((QW *)pmat)[1]) : "r" (t4));
    asm("sqc2 vf3, %1" : "=r" (t6), "=m" (((QW *)pmat)[2]) : "r" (t5));
    asm("sqc2 vf1, %1" : "=r" (t7), "=m" (((QW *)pmat)[0]) : "r" (t6));
    asm("sqc2 vf1, %1" : "=r" (t8), "=m" (junk[0]) : "r" (t7));
    asm("sqc2 vf2, %1" : "=r" (t9), "=m" (junk[1]) : "r" (t8));
    asm("sqc2 vf3, %0" : "=m" (junk[2]) : "r" (t9));
    return pmat;
}

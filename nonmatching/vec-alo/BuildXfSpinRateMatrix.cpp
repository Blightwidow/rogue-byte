#include "sly2.h"
struct Rows { QW row[3]; };
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
extern "C" Rows *BuildXfSpinRateMatrix(Rows *pmatResult, void *pxf, Rows *pmat, QW vecW)
{
    register QW zeroReg asm("$0");
    Rows junkA, junkB;
    float  x;
    x = Lane(vecW);
    memset(pmatResult, 0, 0x40);
    float z = Lane(__builtin_pextuw(zeroReg, vecW));
    float y = Lane(__builtin_prot3w(vecW));
    float *ag = (float *)pmatResult;
    ag[1] = z;
    ag[6] = x;
    ag[9] = -x;
    ag[4] = -z;
    ag[2] = -y;
    ag[8] = y;
    asm("lqc2 vf2, %0" : : "m" (pmatResult->row[1]));
    asm("lqc2 vf5, %0" : : "m" (pmat->row[2]));
    asm("lqc2 vf4, %0" : : "m" (pmat->row[0]));
    asm("lqc2 vf3, %0" : : "m" (pmatResult->row[0]));
    asm("lqc2 vf1, %0" : : "m" (pmatResult->row[2]));
    asm("lqc2 vf6, %0" : : "m" (pmat->row[1]));
    asm("vmulax.xyz ACC, vf3, vf5x\n\tvmadday.xyz ACC, vf2, vf5y\n\tvmaddz.xyz vf5, vf1, vf5z\n\tvmulax.xyz ACC, vf3, vf4x\n\tvmadday.xyz ACC, vf2, vf4y\n\tvmaddz.xyz vf4, vf1, vf4z");
    asm("sqc2 vf5, %0" : "=m" (pmatResult->row[2]));
    asm("vmulax.xyz ACC, vf3, vf6x\n\tvmadday.xyz ACC, vf2, vf6y\n\tvmaddz.xyz vf3, vf1, vf6z");
    asm("sqc2 vf4, %0" : "=m" (pmatResult->row[0]));
    asm("sqc2 vf3, %0" : "=m" (pmatResult->row[1]));
    asm("sqc2 vf4, %0" : "=m" (junkB.row[0]));
    asm("sqc2 vf4, %0" : "=m" (junkA.row[0]));
    asm("sqc2 vf3, %0" : "=m" (junkB.row[1]));
    asm("sqc2 vf3, %0" : "=m" (junkA.row[1]));
    asm("sqc2 vf5, %0" : "=m" (junkB.row[2]));
    asm("sqc2 vf5, %0" : "=m" (junkA.row[2]));
    ag[11] = 0;
    ag[7] = 0;
    ag[3] = 0;
    return pmatResult;
}

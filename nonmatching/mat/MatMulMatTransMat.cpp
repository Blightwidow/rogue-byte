#include "sly2.h"
struct Rows { QW row[3]; };
extern "C" Rows *MatMulMatTransMat(Rows *pmatResult, Rows *pmatA, Rows *pmatB)
{
    Rows result;
    Rows junk;
    asm("lqc2 vf6, %0" : : "m" (pmatB->row[2]));
    asm("lqc2 vf5, %0" : : "m" (pmatA->row[2]));
    asm("lqc2 vf3, %0" : : "m" (pmatB->row[1]));
    asm("lqc2 vf2, %0" : : "m" (pmatA->row[0]));
    asm("lqc2 vf1, %0" : : "m" (pmatA->row[1]));
    asm("lqc2 vf4, %0" : : "m" (pmatB->row[0]));
    asm("vmulaz.xyzw ACC, vf4, vf2z\n\tvmaddaz.xyzw ACC, vf3, vf1z\n\tvmaddz.xyzw vf8, vf6, vf5z\n\tvmulax.xyzw ACC, vf4, vf2x\n\tvmaddax.xyzw ACC, vf3, vf1x\n\tvmaddx.xyzw vf7, vf6, vf5x\n\tvmulay.xyzw ACC, vf4, vf2y\n\tvmadday.xyzw ACC, vf3, vf1y\n\tvmaddy.xyzw vf4, vf6, vf5y");
    asm("sqc2 vf7, %0\n\tsqc2 vf4, %1\n\tsqc2 vf8, %2\n\tsqc2 vf7, %3\n\tsqc2 vf4, %4\n\tsqc2 vf8, %5" : "=m" (result.row[0]), "=m" (result.row[1]), "=m" (result.row[2]), "=m" (junk.row[0]), "=m" (junk.row[1]), "=m" (junk.row[2]));
    memcpy(pmatResult, &result, 0x30);
    return pmatResult;
}

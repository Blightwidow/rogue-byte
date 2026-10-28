#include "sly2.h"
struct Rows { QW row[3]; };
extern "C" Rows *InvertMatrix3(Rows *pmatResult, Rows *pmat)
{
    Rows junk;
    asm("lqc2 vf3, %0" : : "m" (pmat->row[2]));
    asm("lqc2 vf1, %0" : : "m" (pmat->row[1]));
    asm("lqc2 vf2, %0" : : "m" (pmat->row[0]));
    asm("vopmula.xyz ACC, vf1, vf3\n\tvopmsub.xyz vf4, vf3, vf1\n\tvopmula.xyz ACC, vf3, vf2\n\tvopmsub.xyz vf5, vf2, vf3\n\tvopmula.xyz ACC, vf2, vf1\n\tvopmsub.xyz vf6, vf1, vf2");
    asm("vmul.xyz vf9, vf2, vf4\n\tvmulax.w ACC, vf0, vf9x\n\tvmadday.w ACC, vf0, vf9y\n\tvmaddz.w vf9, vf0, vf9z");
    asm("vadd.xyz vf8, vf0, vf4\n\tvadd.xyz vf7, vf0, vf5\n\tvdiv Q, vf0w, vf9w");
    asm("vaddx.y vf4, vf0, vf5x\n\tvaddx.z vf4, vf0, vf6x\n\tvaddy.x vf5, vf0, vf8y\n\tvaddy.z vf5, vf0, vf6y\n\tvaddz.x vf6, vf0, vf8z\n\tvaddz.y vf6, vf0, vf7z");
    asm("vwaitq\n\tvmulq.xyz vf4, vf4, Q\n\tvmulq.xyz vf5, vf5, Q\n\tvmulq.xyz vf6, vf6, Q");
    asm("sqc2 vf5, %0" : "=m" (pmatResult->row[1]));
    asm("sqc2 vf6, %0" : "=m" (pmatResult->row[2]));
    asm("sqc2 vf4, %0" : "=m" (pmatResult->row[0]));
    asm("sqc2 vf4, %0" : "=m" (junk.row[0]));
    asm("sqc2 vf5, %0" : "=m" (junk.row[1]));
    asm("sqc2 vf6, %0" : "=m" (junk.row[2]));
    return pmatResult;
}

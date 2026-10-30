#include "sly2.h"
struct Rows { QW row[3]; };
extern "C" Rows *InvertMatrix3(Rows *pmatResult, Rows *pmat)
{
    Rows junk;
    int f1, f2, f3, f4, f5, f6, f7, f8, f9;
    asm("lqc2 vf3, %1" : "=r" (f1) : "m" (pmat->row[2]));
    asm("lqc2 vf1, %1" : "=r" (f2) : "m" (pmat->row[1]), "r" (f1));
    asm("lqc2 vf2, %1" : "=r" (f3) : "m" (pmat->row[0]), "r" (f2));
    asm("vopmula.xyz ACC, vf1, vf3\n\tvopmsub.xyz vf4, vf3, vf1\n\tvopmula.xyz ACC, vf3, vf2\n\tvopmsub.xyz vf5, vf2, vf3\n\tvopmula.xyz ACC, vf2, vf1\n\tvopmsub.xyz vf6, vf1, vf2\n\tvmul.xyz vf9, vf2, vf4\n\tvmulax.w ACC, vf0, vf9x\n\tvmadday.w ACC, vf0, vf9y\n\tvmaddz.w vf9, vf0, vf9z\n\tvadd.xyz vf8, vf0, vf4\n\tvadd.xyz vf7, vf0, vf5\n\tvdiv Q, vf0w, vf9w\n\tvaddx.y vf4, vf0, vf5x\n\tvaddx.z vf4, vf0, vf6x\n\tvaddy.x vf5, vf0, vf8y\n\tvaddy.z vf5, vf0, vf6y\n\tvaddz.x vf6, vf0, vf8z\n\tvaddz.y vf6, vf0, vf7z\n\tvwaitq\n\tvmulq.xyz vf4, vf4, Q\n\tvmulq.xyz vf5, vf5, Q\n\tvmulq.xyz vf6, vf6, Q" : "=r" (f4) : "r" (f3));
    asm("sqc2 vf5, %1" : "=r" (f5), "=m" (pmatResult->row[1]) : "r" (f4));
    asm("sqc2 vf6, %1" : "=r" (f6), "=m" (pmatResult->row[2]) : "r" (f5));
    asm("sqc2 vf4, %1" : "=r" (f7), "=m" (pmatResult->row[0]) : "r" (f6));
    asm("sqc2 vf4, %1" : "=r" (f8), "=m" (junk.row[0]) : "r" (f7));
    asm("sqc2 vf5, %1" : "=r" (f9), "=m" (junk.row[1]) : "r" (f8));
    asm("sqc2 vf6, %0" : "=m" (junk.row[2]) : "r" (f9));
    return pmatResult;
}

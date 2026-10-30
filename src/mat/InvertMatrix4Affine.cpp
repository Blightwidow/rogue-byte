#include "sly2.h"
struct Rows4 { QW row[4]; };
extern "C" Rows4 *InvertMatrix4Affine(Rows4 *presult, Rows4 *pmat)
{
    Rows4 junk;
    int f1, f2, f3, f4, f5, f6, f7, f8;
    asm("lqc2 vf4, %1" : "=r" (f1) : "m" (pmat->row[3]));
    asm("lqc2 vf2, %1" : "=r" (f2) : "m" (pmat->row[1]), "r" (f1));
    asm("lqc2 vf1, %1" : "=r" (f3) : "m" (pmat->row[2]), "r" (f2));
    asm("lqc2 vf3, %1" : "=r" (f4) : "m" (pmat->row[0]), "r" (f3));
    asm("vopmula.xyz ACC, vf2, vf1\n\tvopmsub.xyz vf5, vf1, vf2\n\tvopmula.xyz ACC, vf1, vf3\n\tvopmsub.xyz vf6, vf3, vf1\n\tvopmula.xyz ACC, vf3, vf2\n\tvopmsub.xyz vf7, vf2, vf3\n"
        "vmul.xyz vf10, vf3, vf5\n\tvmulax.w ACC, vf0, vf10x\n\tvmadday.w ACC, vf0, vf10y\n\tvmaddz.w vf10, vf0, vf10z\n"
        "vadd.xyz vf10, vf0, vf5\n\tvadd.xyz vf9, vf0, vf6\n\tvsub.xyz vf4, vf0, vf4\n\tvdiv Q, vf0w, vf10w\n"
        "vaddx.y vf5, vf0, vf6x\n\tvaddx.z vf5, vf0, vf7x\n\tvaddy.x vf6, vf0, vf10y\n\tvaddy.z vf6, vf0, vf7y\n\tvaddz.x vf7, vf0, vf10z\n\tvaddz.y vf7, vf0, vf9z\n"
        "vmulq.xyz vf5, vf5, Q\n\tvsub.w vf5, vf0, vf0\n\tvmulq.xyz vf6, vf6, Q\n\tvsub.w vf6, vf0, vf0\n\tvmulq.xyz vf7, vf7, Q\n\tvsub.w vf7, vf0, vf0\n"
        "vmulax.xyz ACC, vf5, vf4x\n\tvmadday.xyz ACC, vf6, vf4y\n\tvmaddz.xyz vf8, vf7, vf4z\n\tvaddx.w vf8, vf0, vf0x" : "=r" (f5) : "r" (f4));
    asm("sqc2 vf6, %1\n\tsqc2 vf7, %2\n\tsqc2 vf8, %3\n\tsqc2 vf5, %4" : "=r" (f6), "=m" (presult->row[1]), "=m" (presult->row[2]), "=m" (presult->row[3]), "=m" (presult->row[0]) : "r" (f5));
    asm("sqc2 vf5, %1\n\tsqc2 vf6, %2\n\tsqc2 vf7, %3\n\tsqc2 vf8, %4" : "=r" (f7), "=m" (junk.row[0]), "=m" (junk.row[1]), "=m" (junk.row[2]), "=m" (junk.row[3]) : "r" (f6));
    return presult;
}

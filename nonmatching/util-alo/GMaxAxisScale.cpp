#include "sly2.h"
struct Rows { QW row[3]; };
extern "C" float GMaxAxisScale(Rows *pmat)
{
    float sq0, sq1, sq2;
    asm("lqc2 vf1, %0\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf3, vf1z" : : "m" (pmat->row[0]));
    asm("lqc2 vf2, %0" : : "m" (pmat->row[1]));
    asm("qmfc2.ni %0, vf1" : "=r" (sq0));
    asm("vmul.xyz vf2, vf2, vf2\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z");
    asm("lqc2 vf1, %0" : : "m" (pmat->row[2]));
    asm("qmfc2.ni %0, vf2" : "=r" (sq1));
    asm("vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
    asm("qmfc2.ni %0, vf1" : "=r" (sq2));
    float max = sq2;
    if (sq1 < sq0 && sq2 < sq0)
        max = sq0;
    else if (sq2 < sq1)
        max = sq1;
    register float result asm("$f1");
    asm("nop\n\tnop\n\tsqrt.s %0, %1" : "=f" (result) : "f" (max));
    return result;
}

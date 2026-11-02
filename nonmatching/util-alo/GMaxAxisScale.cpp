#include "sly2.h"
static inline float Lane0(QW v) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (v)); return f; }
static inline float SquareRoot(float value) { float result; asm("sqrt.s %0, %1" : "=f" (result) : "f" (value)); return result; }
extern "C" float GMaxAxisScale__Fv(QW *matrix)
{
    int fence;
    QW bits0, bits1, bits2;
    asm("lqc2 vf1, %0\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf3, vf1z" : : "m" (matrix[0]));
    asm("lqc2 vf2, %1\n\tqmfc2.ni %0, vf1" : "=r" (bits0) : "m" (matrix[1]));
    asm("vmul.xyz vf2, vf2, vf2\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z");
    float first = Lane0(bits0);
    asm("lqc2 vf1, %1" : "=r" (fence) : "m" (matrix[2]), "f" (first));
    asm("qmfc2.ni %0, vf2" : "=r" (bits1) : "r" (fence));
    float second = Lane0(bits1);
    asm("vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "=r" (fence));
    asm("qmfc2.ni %0, vf1" : "=r" (bits2) : "r" (fence));
    float third = Lane0(bits2);
    if (second < first && third < first) third = first;
    else if (third < second) third = second;
    return SquareRoot(third);
}

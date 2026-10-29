#include "sly2.h"
struct M { QW row[4]; };
extern "C" M *func_0011C288(M *out, QW row3, M *src, float scale)
{
    QW junk;
    int bits, f1, f2, f3, f4, f5, f6, f7;
    asm("mfc1 %0, %1" : "=r" (bits) : "f" (scale));
    asm("lqc2 vf1, %2\n\tqmtc2.ni %1, vf2\n\tvmulx.xyzw vf1, vf1, vf2x" : "=r" (f1) : "r" (bits), "m" (src->row[0]));
    asm volatile("sqc2 vf2, %0" : "=m" (junk) : "r" (f1));
    asm volatile("sqc2 vf1, %0" : "=m" (out->row[0]) : "r" (f1));
    float zero = 0.0f, one = 1.0f;
    asm("lqc2 vf1, %1\n\tvmulx.xyzw vf1, vf1, vf2x" : "=r" (f2) : "m" (src->row[1]), "r" (f1), "f" (zero), "f" (one));
    asm volatile("sqc2 vf1, %0" : "=m" (out->row[1]) : "r" (f2));
    asm volatile("sqc2 vf2, %0" : "=m" (junk) : "r" (f2));
    asm("lqc2 vf1, %1" : "=r" (f3) : "m" (src->row[2]), "r" (f2));
    out->row[3] = row3;
    asm("vmulx.xyzw vf1, vf1, vf2x" : "=r" (f4) : "r" (f3));
    asm volatile("sqc2 vf1, %0" : "=m" (out->row[2]) : "r" (f4));
    volatile float *words = (volatile float *)out;
    words[3] = zero; words[15] = one;
    asm volatile("sqc2 vf2, %0" : "=m" (junk) : "r" (f4));
    words[11] = zero;
    words[7] = zero;
    return out;
}

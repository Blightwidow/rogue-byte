#include "sly2.h"
static inline float Lane(QW q) { float f; asm volatile("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline float LaneNop(QW q) { float f; asm volatile("mtc1 %1, %0\n\tnop" : "=f" (f) : "r" (q)); return f; }
static inline QW Word(float f) { QW r; asm volatile("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
extern "C" int func_0011EA60(QW posA0, QW posA1, QW posB0, QW posB1, float *params, QW *normalOut)
{
    QW junk;
    QW normalSquaredBits;
    QW dotBits;
    QW dotBits2;
    register QW v1 asm("vf1");
    register QW v2 asm("vf2");
    register QW v3 asm("vf3");
    register QW v4 asm("vf4");
    register QW v6 asm("vf6");
    register QW v7 asm("vf7");
    register QW v8 asm("vf8");
    register QW v9 asm("vf9");
    asm("qmtc2.ni %1, vf1" : "=j" (v1) : "r" (posA0));
    float epsilon = 1e-6f;
    asm("qmtc2.ni %1, vf2" : "=j" (v2) : "r" (posB0), "j" (v1), "f" (epsilon));
    asm("qmtc2.ni %1, vf4" : "=j" (v4) : "r" (posA1), "j" (v2));
    asm("vsub.xyzw vf3, vf4, vf1" : "=j" (v3) : "j" (v4), "j" (v1));
    asm("vsub.xyzw vf7, vf2, vf1" : "=j" (v7) : "j" (v2), "j" (v1));
    asm volatile("qmtc2.ni %1, vf1" : "=j" (v1) : "r" (posB1));
    asm volatile("vsub.xyzw vf4, vf1, vf2\n\tvopmula.xyz ACC, vf3, vf4\n\tvopmsub.xyz vf9, vf4, vf3\n\tvmove.xyzw vf2, vf7\n\tvmove.xyzw vf6, vf9\n\tvopmula.xyz ACC, vf2, vf3\n\tvopmsub.xyz vf8, vf3, vf2\n\tvmul.xyz vf1, vf6, vf6\n\tvaddw.x vf5, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf5, vf1z\n\tvopmula.xyz ACC, vf2, vf4\n\tvopmsub.xyz vf2, vf4, vf2" : "=j" (v1), "=j" (v2), "=j" (v6), "=j" (v8), "=j" (v9) : "j" (v1), "j" (v2), "j" (v3), "j" (v4), "j" (v7));
    asm volatile("qmfc2.ni %0, vf1" : "=r" (normalSquaredBits));
    float normalSquared = LaneNop(normalSquaredBits);
    if (normalSquared < epsilon)
        return 0;
    if (params != 0) {
        asm volatile("vmul.xyz vf1, vf2, vf6\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf3, vf1z");
        asm volatile("qmfc2.ni %0, vf1" : "=r" (dotBits));
        asm volatile("vmul.xyz vf2, vf8, vf6\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf4, vf2z");
        float first = Lane(dotBits);
        asm volatile("qmfc2.ni %0, vf2" : "=r" (dotBits2));
        float quotient0 = first / normalSquared;
        asm volatile("" : : "f" (quotient0));
        float second = LaneNop(dotBits2);
        params[0] = quotient0;
        params[1] = second / normalSquared;
    }
    asm volatile("vmul.xyz vf1, vf7, vf6\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
    float zeroF = 0.0f;
    asm volatile("qmfc2.ni %0, vf1" : "=r" (dotBits));
    register float sign asm("$f3") = 1.0f;
    float toB0Dot = LaneNop(dotBits);
    asm volatile("c.lt.s %1, %2\n\tnop\n\tbc1f 1f\n\tlui $1, 0xBF80\n\tmtc1 $1, %0\n1:" : "+f"(sign) : "f"(toB0Dot), "f"(zeroF) : "$1");
    if (normalOut == 0)
        return 1;
    register float root asm("$f0");
    asm volatile("nop\n\tnop\n\tsqrt.s %0, %1" : "=f" (root) : "f" (normalSquared));
    QW scaleBits = Word(sign / root);
    asm volatile("qmtc2.ni %0, vf1" : : "r" (scaleBits));
    asm volatile("vmulx.xyzw vf2, vf9, vf1x");
    asm volatile("sqc2 vf1, %0" : "=m" (junk));
    asm volatile("sqc2 vf2, %0" : "=m" (*normalOut));
    return 1;
}

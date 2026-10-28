#include "sly2.h"
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
extern "C" QW GCosAngle(QW vecA, QW vecB)
{
    QW junk;
    register QW bits asm("$3");
    QW zero;
    float lengthA, lengthB, dot;
    register QW v1 asm("vf1");
    register QW v3 asm("vf3");
    register QW v4 asm("vf4") = vecA;
    asm("vmul.xyz vf1, vf4, vf4\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=j" (v1) : "j" (v4));
    v3 = vecB;
    asm("qmfc2.ni $2, vf1\n\tmtc1 $2, %0\n\tnop" : "=f" (lengthA) : "j" (v1) : "$2");
    float result;
    if (lengthA < 0.0001f) {
        result = 0.0f;
    } else {
        asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=j" (v1) : "j" (v3));
        asm("qmfc2.ni $2, vf1\n\tmtc1 $2, %0\n\tnop" : "=f" (lengthB) : "j" (v1) : "$2");
        if (lengthB < 0.0001f) {
            goto zeroPath;
        }
        asm("vmul.xyz vf1, vf4, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "=j" (v1) : "j" (v3), "j" (v4));
        asm("qmfc2.ni $2, vf1\n\tmtc1 $2, %0\n\tnop" : "=f" (dot) : "j" (v1) : "$2");
        result = dot / (lengthA * lengthB);
    }
    bits = Word(result);
    junk = bits;
    asm("" : : "m" (junk));
    return bits;
zeroPath:
    zero = Word(0.0f);
    junk = zero;
    asm("" : : "m" (junk));
    return zero;
}

#include "sly2.h"
extern "C" QW GetPerpendicularVector(QW v);
extern const QW g_2a2da0;
extern "C" MATRIX3 *BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(MATRIX3 *out, QW forward, QW up)
{
    QW dead;
    register QW v1 asm("vf1");
    register QW v2 asm("vf2");
    register QW v3 asm("vf3");
    register QW v4 asm("vf4");
    float limit = 0.0001f;
    asm("qmtc2.ni %2, vf3\n\tvmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "=j" (v1), "=j" (v3) : "r" (forward));
    asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=j" (v1) : "j" (v1));
    float length;
    asm("qmfc2.ni $2, vf1\n\tmtc1 $2, %0" : "=f" (length) : "j" (v1) : "$2");
    asm("qmtc2.ni %1, vf2" : "=j" (v2) : "r" (up));
    if (length < limit) {
        asm("qmtc2.ni %1, vf4" : "=j" (v4) : "r" (g_2a2da0));
    } else {
        asm("vdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf4, vf3, Q" : "=j" (v4) : "j" (v1), "j" (v3));
    }
    asm("vopmula.xyz ACC, vf2, vf4\n\tvopmsub.xyz vf1, vf4, vf2\n\tvmul.xyz vf2, vf1, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z" : "=j" (v1), "=j" (v2), "=j" (v3) : "j" (v2), "j" (v4));
    asm("sqc2 vf1, 0x10(%0)" : : "r" (out), "j" (v1) : "memory");
    asm("vsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q" : "=j" (v2) : "j" (v2));
    asm("sqc2 vf4, 0(%0)" : : "r" (out), "j" (v4) : "memory");
    float length2;
    asm("qmfc2.ni $2, vf2\n\tmtc1 $2, %0" : "=f" (length2) : "j" (v2) : "$2");
    asm("vdiv Q, vf0w, vf2x\n\tvwaitq\n\tvmulq.xyzw vf2, vf1, Q" : "=j" (v2) : "j" (v1), "j" (v2));
    asm("sqc2 vf2, 0x10(%0)" : : "r" (out), "j" (v2) : "memory");
    asm("sqc2 vf1, %0" : "=m" (dead) : "j" (v1));
    if (length2 < limit) {
        QW tangent;
        asm("qmfc2.ni %0, vf4" : "=r" (tangent) : "j" (v4));
        *(QW *)((char *)out + 0x10) = GetPerpendicularVector(tangent);
    }
    asm("lqc2 vf1, 0(%0)\n\tlqc2 vf2, 0x10(%0)\n\tvopmula.xyz ACC, vf1, vf2\n\tvopmsub.xyz vf1, vf2, vf1\n\tsqc2 vf1, 0x20(%0)" : : "r" (out) : "memory");
    return out;
}

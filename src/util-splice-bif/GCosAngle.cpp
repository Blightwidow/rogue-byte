#include "sly2.h"
/* a float into lane 0 of a 128-bit general register (mfc1) */
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
struct Frame_11F198 { QW dead[1]; };
extern "C" QW GCosAngle(QW vecA, QW vecB)
{
    Frame_11F198 frame;
    QW result;
    int fenceA, fenceB, fenceC;
    float lengthA, lengthB, dot;
    asm("qmtc2.ni %1, vf4" : "=r" (fenceA) : "r" (vecA));
    asm("vmul.xyz vf1, vf4, vf4\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "=r" (fenceB) : "r" (fenceA));
    asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=r" (fenceA) : "r" (fenceB));
    asm("qmtc2.ni %1, vf3" : "=r" (fenceC) : "r" (vecB), "r" (fenceA));
    {
        QW bits;
        asm("qmfc2.ni %1, vf1\n\tmtc1 %1, %0\n\tnop" : "=f" (lengthA), "=r" (bits) : "r" (fenceC));
    }
    float scalar;
    if (lengthA < 0.0001f) {
        scalar = 0.0f;
    } else {
        asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=r" (fenceA) : "r" (fenceC));
        asm("qmfc2.ni %1, vf1\n\tmtc1 %1, %0\n\tnop" : "=f" (lengthB), "=r" (fenceB) : "r" (fenceA));
        if (lengthB < 0.0001f) {
            goto zeroPath;
        }
        asm("vmul.xyz vf1, vf4, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "=r" (fenceB) : "r" (fenceA));
        asm("qmfc2.ni %1, vf1\n\tmtc1 %1, %0\n\tnop" : "=f" (dot), "=r" (fenceB) : "r" (fenceB));
        scalar = dot / (lengthA * lengthB);
    }
    result = Word(scalar);
    frame.dead[0] = result;
    return result;
zeroPath:
    frame.dead[0] = Word(0.0f);
    return frame.dead[0];
}

#include "sly2.h"
/* lane 0 of a QW to an FP register */
static inline float Lane0(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
/* lane 1 of a QW (prot3w rotates it down) to an FP register */
static inline float Lane1(QW q) { float f; QW t; asm("prot3w %1, %2\n\tmtc1 %1, %0" : "=f" (f), "=r" (t) : "r" (q)); return f; }
/* lane 2 of a QW (pextuw with zero) to an FP register */
static inline float Lane2(QW q) { float f; QW t; asm("pextuw %1, $0, %2\n\tmtc1 %1, %0" : "=f" (f), "=r" (t) : "r" (q)); return f; }
/* lanes 0 and 1 of a QW from two floats: mfc1 each, then pextlw */
static inline QW PairLow(float lane0, float lane1) { QW r; QW t; asm("mfc1 %0, %2\n\tmfc1 %1, %3\n\tpextlw %0, %1, %0" : "=r" (r), "=r" (t) : "f" (lane0), "f" (lane1)); return r; }
/* lane 2 of a QW from a float: mfc1, then pcpyld */
static inline QW WithLane2(QW low, float lane2) { QW t; asm("mfc1 %1, %2\n\tpcpyld %0, %1, %0" : "+r" (low), "=r" (t) : "f" (lane2)); return low; }
static inline QW Vec3(float a, float b, float c) { return WithLane2(PairLow(a, b), c); }
struct Frame_11E390 { QW dead[1]; };
extern "C" QW GetPerpendicularVector(QW vec)
{
    Frame_11E390 frame;
    int fenceV;
    asm("qmtc2.ni %1, vf2" : "=r" (fenceV) : "r" (vec));
    float x = Lane0(vec);
    float y = Lane1(vec);
    float z = Lane2(vec);
    float absX = __builtin_fabsf(x);
    float absY = __builtin_fabsf(y);
    float absZ = __builtin_fabsf(z);
    float zero = 0.0f;
    QW helper;
    int fence;
    if (absX <= absY) {
        if (absX <= absZ) {
            helper = Vec3(zero, z, -y);
            asm("qmtc2.ni %1, vf1" : "=r" (fence) : "r" (helper));
        } else {
            helper = Vec3(y, -x, zero);
            asm("qmtc2.ni %1, vf1" : "=r" (fence) : "r" (helper));
        }
    } else if (absY <= absZ) {
        helper = Vec3(z, zero, -x);
        asm("qmtc2.ni %1, vf1" : "=r" (fence) : "r" (helper));
        frame.dead[0] = helper;
    } else {
        helper = Vec3(y, -x, zero);
        frame.dead[0] = helper;
        asm("qmtc2.ni %1, vf1" : "=r" (fence) : "r" (helper));
    }
    QW result;
    asm("vopmula.xyz ACC, vf2, vf1\n\tvopmsub.xyz vf1, vf1, vf2\n\tvmul.xyz vf2, vf1, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z\n\tvsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q\n\tvdiv Q, vf0w, vf2x\n\tvwaitq\n\tvmulq.xyzw vf3, vf1, Q\n\tqmfc2.ni %0, vf3" : "=r" (result) : "r" (fence));
    return result;
}

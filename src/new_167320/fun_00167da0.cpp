#include "sly2.h"
struct M4 { QW row[4]; };
extern QW D_002BE570;
// lane 0 of a QW into an FP register (mtc1 reads the low word)
static inline float LaneX(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
// a float into lane 0 of a VU0 register
static inline QW Splat(float f) { QW q; asm("qmtc2.ni %1, %0" : "=j"(q) : "r"(f)); return q; }

// m.row[0] * v.x + m.row[1] * v.y + m.row[2] * v.z + m.row[3]
static inline QW XformPoint(const M4 &m, QW v)
{
    QW result;
    asm("vmulax.xyz ACC, %1, %5x\n\tvmadday.xyz ACC, %2, %5y\n\tvmaddaz.xyz ACC, %3, %5z\n\tvmaddw.xyz %0, %4, vf0w"
        : "=j"(result) : "j"(m.row[0]), "j"(m.row[1]), "j"(m.row[2]), "j"(m.row[3]), "j"(v));
    return result;
}

extern "C" QW func_00167DA0(M4 *pmat, QW pos, float *pradius)
{
    QW scratch[1];
    QW delta;
    asm("vsub.xyzw %0, %1, %2" : "=j"(delta) : "j"(XformPoint(*pmat, D_002BE570)), "j"(pos));
    float radius = *pradius;
    QW length;
    QW one;
    asm("vmul.xyz %0, %2, %2\n\tvaddw.x %1, vf0, vf0w\n\tvadday.x ACC, %0, %0y\n\tvmaddz.x %0, %1, %0z"
        : "=j"(length), "=j"(one) : "j"(delta));
    asm("vsqrt Q, %1x\n\tvwaitq\n\tvaddq.x %0, vf0, Q" : "=j"(length) : "j"(length));
    float distance = LaneX(length);
    if (radius < distance) {
        float scale = ((distance - radius) * 0.5f) / distance;
        *pradius = (distance + radius) * 0.5f;
        QW scaleVu = Splat(scale);
        scratch[0] = scaleVu;
        asm("vadda.xyzw ACC, %1, vf0\n\tvmaddx.xyzw %0, %2, %3x" : "=j"(pos) : "j"(pos), "j"(delta), "j"(scaleVu));
    }
    return pos;
}

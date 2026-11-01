#include "sly2.h"
/* a QW from three floats: mfc1 x and y, pextlw into lanes 0 and 1, mfc1 z, pcpyld into the upper doubleword */
static inline QW Vec3(float x, float y, float z) { QW r; int t; asm("mfc1 %0, %2\n\tmfc1 %1, %3\n\tpextlw %0, %1, %0\n\tmfc1 %1, %4\n\tpcpyld %0, %1, %0" : "=&r" (r), "=&r" (t) : "f" (x), "f" (y), "f" (z)); return r; }
/* lane 0 of a QW */
static inline float Lane0(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
/* lane 1 of a QW (prot3w then lane 0) */
static inline float Lane1(QW q) { QW t; float f; asm("prot3w %1, %2\n\tmtc1 %1, %0" : "=f" (f), "=&r" (t) : "r" (q)); return f; }
/* lane 2 of a QW (pextuw then lane 0) */
static inline float Lane2(QW q) { QW t; float f; asm("pextuw %1, $0, %2\n\tmtc1 %1, %0" : "=f" (f), "=&r" (t) : "r" (q)); return f; }
struct Frame_1A6340 { QW dead[1]; };
extern "C" float *PmatLoWorld();
extern "C" QW DecomposeRotateMatrixEuler(float *pmat);
extern "C" QW GetLoEulerDegrees()
{
    Frame_1A6340 frame;
    QW euler = DecomposeRotateMatrixEuler(PmatLoWorld());
    float x = Lane0(euler) * 57.295776f;
    float y = Lane1(euler) * 57.295776f;
    float z = Lane2(euler) * 57.295776f;
    QW result = Vec3(x, y, z);
    frame.dead[0] = result;
    return result;
}

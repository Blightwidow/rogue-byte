#include "sly2.h"
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
struct Frame_11BFF0 { QW dead[1]; };
extern "C" float GLimitAbs__Fff(float, float);
extern "C" float asinf(float);
extern "C" float atan2f(float, float);
static inline QW PairLow(float lane0, float lane1) { QW r; QW t; asm("mfc1 %0, %2\n\tmfc1 %1, %3\n\tpextlw %0, %1, %0" : "=r" (r), "=r" (t) : "f" (lane0), "f" (lane1)); return r; }
static inline QW WithLane2(QW low, float lane2) { QW t; asm("mfc1 %1, %2\n\tpcpyld %0, %1, %0" : "+r" (low), "=r" (t) : "f" (lane2)); return low; }
static inline QW Euler(float x, float y, float z) { return WithLane2(PairLow(x, y), z); }
extern "C" QW DecomposeRotateMatrixEuler(float *pmat)
{
    Frame_11BFF0 frame;
    QW result;
    float eulY = asinf(GLimitAbs__Fff(-pmat[2], 1.0f));
    if (eulY < 1.5706964f) {
        if (-1.5706964f < eulY) {
            float a = atan2f(pmat[6], pmat[10]);
            float b = atan2f(pmat[1], pmat[0]);
            { QW t = Euler(a, eulY, b); frame.dead[0] = t; result = t; }
        } else {
            float b = atan2f(-pmat[4], -pmat[8]);
            { QW t = Euler(0.0f, eulY, b); frame.dead[0] = t; result = t; }
        }
    } else {
        float b = atan2f(-pmat[4], pmat[8]);
        { QW t = Euler(0.0f, eulY, b); frame.dead[0] = t; result = t; }
    }
    return result;
}

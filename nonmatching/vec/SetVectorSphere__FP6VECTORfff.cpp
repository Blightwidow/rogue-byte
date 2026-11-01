#include "sly2.h"
void CalculateSinCos(float rad, float *psin, float *pcos);
/* lanes 0 and 1 of a QW from two floats: mfc1 each, then pextlw */
static inline QW PairLow(float lane0, float lane1) { QW r; int t; asm("mfc1 %0, %2\n\tmfc1 %1, %3\n\tpextlw %0, %1, %0" : "=r" (r), "=r" (t) : "f" (lane0), "f" (lane1)); return r; }
/* lane 2 of a QW from a float: mfc1, then pcpyld into the upper doubleword */
static inline QW WithLane2(QW low, float lane2) { QW t; asm("mfc1 %1, %2\n\tpcpyld %0, %1, %0" : "+r" (low), "=r" (t) : "f" (lane2)); return low; }
struct Frame_11E208 { QW dead; float sc[4]; };
extern "C" QW SetVectorSphere(float radPan, float radTilt, float sRadius)
{
    Frame_11E208 frame;
    CalculateSinCos(radPan, &frame.sc[0], &frame.sc[1]);
    CalculateSinCos(radTilt, &frame.sc[2], &frame.sc[3]);
    float x = frame.sc[3] * frame.sc[1] * sRadius;
    float y = frame.sc[3] * frame.sc[0] * sRadius;
    float z = frame.sc[2] * sRadius;
    QW result = WithLane2(PairLow(x, y), z);
    frame.dead = result;
    return result;
}

#include "sly2.h"
static inline float Lane1BC208(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline float RotLane1BC208(QW q) { float f; int t; asm volatile("prot3w %1, %2\n\tmtc1 %1, %0" : "=f" (f), "=r" (t) : "r" (q)); return f; }
extern "C" int CmpPosXy(QW a, QW b)
{
    float ax = Lane1BC208(a);
    float bx = Lane1BC208(b);
    if (ax < bx) return -1;
    if (bx < ax) return 1;
    float ay = RotLane1BC208(a);
    float by = RotLane1BC208(b);
    if (ay < by) return -1;
    if (by < ay) return 1;
    return 0;
}

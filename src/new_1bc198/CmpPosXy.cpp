#include "sly2.h"
static inline float Lane1BC208(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
// lane 1 of two QW values into FP registers (prot3w + mtc1 each), sharing one scratch register
static inline void RotLanes1BC208(QW q, QW r, float *fq, float *fr) {
    float x, y; int t;
    asm volatile("prot3w %2, %3\n\tmtc1 %2, %1\n\tprot3w %2, %4\n\tmtc1 %2, %0" : "=f" (y), "=f" (x), "=&r" (t) : "r" (q), "r" (r));
    *fq = x; *fr = y;
}
extern "C" int CmpPosXy(QW a, QW b)
{
    float ax = Lane1BC208(a);
    float bx = Lane1BC208(b);
    if (ax < bx) return -1;
    if (bx < ax) return 1;
    float ay, by;
    RotLanes1BC208(a, b, &ay, &by);
    if (ay < by) return -1;
    if (by < ay) return 1;
    return 0;
}

#include "sly2.h"
extern "C" float atan2f(float, float);
extern "C" float RadNormalize__Ff(float);
extern "C" void CalculateVectorPanTilt__FP6VECTORPfT1(QW vec, float *pan, float *tilt)
{
    if (pan) {
        float x, y;
        asm("prot3w $2, %2\n\tmtc1 %2, %0\n\tmtc1 $2, %1" : "=f" (x), "=f" (y) : "r" (vec) : "$2");
        *pan = RadNormalize__Ff(atan2f(y, x));
    }
    if (tilt) {
        int yb, zb;
        float x;
        asm("prot3w %0, %1" : "=r" (yb) : "r" (vec));
        asm("mtc1 %1, %0" : "=f" (x) : "r" (vec));
        asm("pextuw %0, $0, %1" : "=r" (zb) : "r" (vec));
        float y = *(float *)&yb;
        float z = *(float *)&zb;
        *tilt = RadNormalize__Ff(atan2f(z, __builtin_sqrtf(x * x + y * y)));
    }
}

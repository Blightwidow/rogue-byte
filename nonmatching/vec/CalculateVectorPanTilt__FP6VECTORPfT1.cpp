#include "sly2.h"
static inline float Sqrt(float x) { float r; asm volatile("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
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
        float x, y;
        int zb;
        asm("prot3w $2, %2\n\tmtc1 %2, %0\n\tmtc1 $2, %1" : "=f" (x), "=f" (y) : "r" (vec) : "$2");
        asm("pextuw %0, $0, %1" : "=r" (zb) : "r" (vec));
        float z = *(float *)&zb;
        float yy = y * y;
        float xx = x * x;
        *tilt = RadNormalize__Ff(atan2f(z, Sqrt(xx + yy)));
    }
}

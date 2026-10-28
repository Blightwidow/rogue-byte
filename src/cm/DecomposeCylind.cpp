// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
extern "C" float atan2f(float, float);
extern "C" float RadNormalize__Ff(float);
extern "C" void DecomposeCylind(QW vec, float *pradTheta, float *pdRadius, float *pdz)
{
    if (pradTheta) {
        float x, y;
        asm("prot3w $2, %2\n\tmtc1 %2, %0\n\tmtc1 $2, %1" : "=f" (x), "=f" (y) : "r" (vec) : "$2");
        *pradTheta = RadNormalize__Ff(atan2f(y, x));
    }
    asm volatile("qmtc2.ni %0, vf2" : : "r" (vec));
    if (pdRadius) {
        int radiusBits;
        asm("vmul.xy vf1, vf2, vf2\n\tvaddy.x vf1, vf1, vf1y\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r" (radiusBits) : "r" (vec));
        *(int *)pdRadius = radiusBits;
    }
    if (pdz) {
        float z;
        asm("pextuw $2, $0, %1\n\tmtc1 $2, %0\n\tnop" : "=f" (z) : "r" (vec) : "$2");
        *pdz = z;
    }
}

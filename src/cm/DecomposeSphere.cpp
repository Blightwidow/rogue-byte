#include "sly2.h"
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
extern "C" float atan2f(float, float);
extern "C" float RadNormalize__Ff(float);
extern "C" void DecomposeSphere(QW vec, float *pradTheta, float *pradPhi, float *pdDistance)
{
    if (pradTheta) {
        float x, y;
        asm("por $2, $0, %2\n\tprot3w $2, $2\n\tmtc1 $2, %1\n\tpor $2, $0, %2\n\tmtc1 $2, %0" : "=f" (x), "=f" (y) : "r" (vec) : "$2");
        *pradTheta = RadNormalize__Ff(atan2f(y, x));
    }
    asm volatile("lqc2 vf2, %0" : : "m" (vec));
    if (pradPhi) {
        float z, radius;
        asm("vmul.xy vf1, vf2, vf2\n\tvaddy.x vf1, vf1, vf1y\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni $2, vf2\n\tpextuw $2, $0, $2\n\tmtc1 $2, %0\n\tqmfc2.ni $2, vf1\n\tmtc1 $2, %1" : "=f" (z), "=f" (radius) : : "$2");
        *pradPhi = RadNormalize__Ff(atan2f(z, radius));
    }
    asm volatile(".set push\n\t.set noreorder\n\tbeqz %0, 1f\n\tlqc2 vf3, 0(%1)\n\tvmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni $2, vf1\n\tsw $2, 0(%0)\n1:\n\t.set pop" : : "r" (pdDistance), "r" (&vec) : "$2", "memory");
}

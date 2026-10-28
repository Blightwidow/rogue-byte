#include "sly2.h"
extern "C" int D_002C3C20[];
extern "C" QW D_002C3BA0[];
extern "C" QW g_2a2dd0;
void ConstrFromCnstr(void *pso, QW *m, int cnstr, QW *out)
{
    int chain;
    float len;
    float eps = 0.0001f;
    ((int *)out)[4] = D_002C3C20[cnstr];
    asm("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tlqc2 vf4, %3\n\tlqc2 vf3, %4\n\tvmulax.xyz ACC, vf2, vf4x\n\tvmadday.xyz ACC, vf1, vf4y\n\tvmaddz.xyz vf3, vf3, vf4z"
        : "=r" (chain) : "m" (m[0]), "m" (m[1]), "m" (D_002C3BA0[cnstr]), "m" (m[2]));
    asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r" (len) : "r" (chain));
    if (len < eps) {
        QW zero = g_2a2dd0;
        asm("qmtc2.ni %0, vf1" : : "r" (zero));
    } else {
        asm("vdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf1, vf3, Q");
    }
    asm("sqc2 vf1, %0" : "=m" (*out));
}

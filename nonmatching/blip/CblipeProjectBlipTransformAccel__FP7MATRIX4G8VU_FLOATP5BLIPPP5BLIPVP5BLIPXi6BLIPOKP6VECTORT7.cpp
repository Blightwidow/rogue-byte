#include "sly2.h"
struct BLIPV { float x, y, z, tDestroy; };
struct BLIPX { float x, y, swRoll, radRoll; };
extern "C" float RadNormalize__Ff(float);
extern float g_2dded0;
extern "C" int CblipeProjectBlipTransformAccel__FP7MATRIX4G8VU_FLOATP5BLIPPP5BLIPVP5BLIPXi6BLIPOKP6VECTORT7(MATRIX4 *pmatDv, QW vecDt, QW *ablipp, BLIPV *ablipv, BLIPX *ablipx, int cblipe,
                                    int blipok, QW *pposMin, QW *pposMax)
{
    register int cdead asm("$22") = 0;
    int iout = -1;
    asm volatile("qmtc2.ni %0, vf27" : : "r" (vecDt));
    asm volatile("lqc2 vf28, 0x30(%0)" : : "r" (pmatDv));
    asm volatile("lqc2 vf25, 0(%0)" : : "r" (pposMax));
    float clock = g_2dded0;
    asm volatile("lqc2 vf31, 0x0(%0)" : : "r" (pmatDv));
    asm volatile("lqc2 vf30, 0x10(%0)" : : "r" (pmatDv));
    asm volatile("lqc2 vf29, 0x20(%0)" : : "r" (pmatDv));
    asm volatile("lqc2 vf26, 0(%0)" : : "r" (pposMin));
    float dt;
    asm("mtc1 %1, %0" : "=f" (dt) : "r" (vecDt));
    for (int iblipe = 0; iblipe < cblipe; iblipe++) {
        if (ablipv[iblipe].tDestroy <= clock) {
            cdead++;
            continue;
        }
        asm volatile("lqc2 vf24, 0(%0)" : : "r" (&ablipv[iblipe]));
        asm volatile("lqc2 vf23, 0(%0)" : : "r" (&ablipp[iblipe]));
        asm volatile("vcallms 0x10");
        iout++;
        *(QW *)&ablipx[iout] = *(QW *)&ablipx[iblipe];
        if (blipok == 2)
            ablipx[iout].radRoll = RadNormalize__Ff(ablipx[iblipe].radRoll + ablipx[iblipe].swRoll * dt);
        int status;
        asm volatile("cfc2.i %0, $vi0" : "=r" (status));
        asm volatile("sqc2 vf22, 0(%0)" : : "r" (&ablipv[iout]) : "memory");
        asm volatile("sqc2 vf21, 0(%0)" : : "r" (&ablipp[iout]) : "memory");
    }
    asm volatile("sqc2 vf26, 0(%0)" : : "r" (pposMin) : "memory");
    asm volatile("sqc2 vf25, 0(%0)" : : "r" (pposMax) : "memory");
    return cdead;
}

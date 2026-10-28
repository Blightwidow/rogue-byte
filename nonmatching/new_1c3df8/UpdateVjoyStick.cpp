/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct VJOY;
extern "C" float atan2f(float, float);
extern "C" float RadNormalize__Ff(float);
extern "C" void CalculateSinCos__FfPfT1(float, float *, float *);
extern "C" void UpdateVjoyStick(float radPan, VJOY *pvjoy, float *px, float *py, float *prad, float *ps, float *psHold)
{
    float gSin, gCos;
    *ps = __builtin_sqrtf(*px * *px + *py * *py);
    float sHold;
    asm("max.s %0, %1, %2" : "=f" (sHold) : "f" (*psHold - 0.2f), "f" (0.0f));
    *psHold = sHold;
    if (*ps < sHold || *ps == 0.0f) {
        CalculateSinCos__FfPfT1((*prad - radPan) + 1.5707964f, &gSin, &gCos);
        *ps = *psHold;
        *px = *psHold * gCos;
        *py = *ps * gSin;
    } else {
        *prad = RadNormalize__Ff((atan2f(*py, *px) + radPan) - 1.5707964f);
        *psHold = *ps;
    }
}

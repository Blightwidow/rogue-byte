/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct SAPEP1C1A38 { float g; short fMin; short islot; };
extern "C" void *memmove(void *, const void *, unsigned);
extern "C" void InsertPathzoneEndpoints(int cep, SAPEP1C1A38 *aep, int islot, float gMin, float gMax)
{
    int iepMin;
    int iepMax;
    for (iepMin = 0; iepMin < cep; iepMin++) {
        if (gMin <= aep[iepMin].g)
            break;
    }
    for (iepMax = iepMin; iepMax < cep; iepMax++) {
        if (gMax < aep[iepMax].g)
            break;
    }
    SAPEP1C1A38 *pMax = &aep[iepMax];
    memmove((char *)pMax + 0x10, pMax, (cep - iepMax) * 8);
    pMax[1].g = gMax;
    pMax++;
    pMax[0].islot = islot;
    pMax[0].fMin = 0;
    SAPEP1C1A38 *pMin = &aep[iepMin];
    memmove((char *)pMin + 8, pMin, (iepMax - iepMin) * 8);
    pMin->islot = islot;
    pMin->g = gMin;
    pMin->fMin = 1;
}

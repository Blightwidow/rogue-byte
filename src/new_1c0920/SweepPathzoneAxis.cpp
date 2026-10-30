/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct SAPEP { float g; int islot; };
extern "C" int IepSweepPathzoneCursor(SAPEP *, float, int, unsigned *, int);
extern "C" void SweepPathzoneAxis(float gMin, float gMax, SAPEP *aep, int *piepMin, int *piepMax, unsigned *agrf)
{
    int iepMin = *piepMin;
    int iepMax = *piepMax;
    if (aep[iepMin].g < gMin) {
        iepMax = IepSweepPathzoneCursor(aep, gMax, iepMax, agrf, 1);
        iepMin = IepSweepPathzoneCursor(aep, gMin, iepMin, agrf, 0);
    } else {
        iepMin = IepSweepPathzoneCursor(aep, gMin, iepMin, agrf, 0);
        iepMax = IepSweepPathzoneCursor(aep, gMax, iepMax, agrf, 1);
    }
    *piepMin = iepMin;
    *piepMax = iepMax;
}

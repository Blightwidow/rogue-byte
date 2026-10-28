#include "sly2.h"
struct SAPEP { float g; int islot; };
extern "C" int IepSweepPathzoneCursor(float, SAPEP *, int, unsigned *, int);
extern "C" void SweepPathzoneAxis(float gMin, float gMax, SAPEP *aep, int *piepMin, int *piepMax, unsigned *agrf)
{
    int iepMin = *piepMin;
    int iepMax = *piepMax;
    if (aep[iepMin].g < gMin) {
        iepMax = IepSweepPathzoneCursor(gMax, aep, iepMax, agrf, 1);
        iepMin = IepSweepPathzoneCursor(gMin, aep, iepMin, agrf, 0);
    } else {
        iepMin = IepSweepPathzoneCursor(gMin, aep, iepMin, agrf, 0);
        iepMax = IepSweepPathzoneCursor(gMax, aep, iepMax, agrf, 1);
    }
    *piepMin = iepMin;
    *piepMax = iepMax;
}

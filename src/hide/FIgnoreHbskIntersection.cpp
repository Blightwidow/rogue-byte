#include "sly2.h"
extern "C" int FIgnoreSoIntersection(void *, void *);
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" int IMax(int, int);

int FIgnoreHbskIntersection(void *phbsk, void *pother)
{
    int ignore = FIgnoreSoIntersection(phbsk, pother);
    if (FIsBasicDerivedFrom(pother, 0x34) != 0) {
        int *pint = (int *)pother;
        if (pint[0x4C8 / 4] == 1 && phbsk == (void *)pint[0x4D4 / 4])
            ignore = IMax(ignore, 1);
        if ((unsigned)(pint[0x2DC / 4] - 6) < 2 && phbsk == (void *)pint[0x2CC / 4])
            ignore = IMax(ignore, 1);
    }
    return ignore;
}

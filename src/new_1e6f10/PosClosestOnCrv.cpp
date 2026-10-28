#include "sly2.h"
extern "C" void FindCrvClosestPointAll(void *, QW, void *, QW *, void *, void *, void *);
extern "C" QW PosClosestOnCrv(void *curve, QW pos)
{
    QW closest;
    FindCrvClosestPointAll(curve, pos, 0, &closest, 0, 0, 0);
    return closest;
}

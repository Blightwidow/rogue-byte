#include "sly2.h"
extern "C" QW PosLoWorld(void *);
extern "C" void AttachPt_GetAimPos(void *pattach, void *unused, QW *pvec)
{
    if (pvec != 0)
        *pvec = PosLoWorld(pattach);
}

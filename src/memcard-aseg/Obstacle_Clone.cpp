#include "sly2.h"
struct QB { char b[8]; };
struct ALLOCREQ { int cb; int cbAlign; };
struct OBSTACLE { char pad[0xE8]; int cpos; char pad2[0x1D0 - 0xEC]; QB link; char pad4[8]; QB state; char pad5[4]; void *pplanes; };
extern "C" void CloneCrv(OBSTACLE *, OBSTACLE *);
extern "C" void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
void Obstacle_Clone(OBSTACLE *pobstacle, OBSTACLE *pbase)
{
    QB linkSaved = pobstacle->link;
    QB stateSaved = pobstacle->state;
    CloneCrv(pobstacle, pbase);
    pobstacle->link = linkSaved;
    pobstacle->state = stateSaved;
    ALLOCREQ req;
    ALLOCREQ *preq = &req;
    int align = 0x10;
    preq->cb = pobstacle->cpos * 0x10 - 0x10;
    preq->cbAlign = align;
    pobstacle->pplanes = PvAllocSwClearImpl__Fi(preq);
}

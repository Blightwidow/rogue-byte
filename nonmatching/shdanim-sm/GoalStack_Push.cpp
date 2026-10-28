#include "sly2.h"
struct GOAL;
struct VT { char pad[0x38]; short delta; short index; void (*fn)(void *); };
struct GOAL { char pad[0xC]; VT *vt; GOAL *pstep; GOAL *pparent; GOAL *pchild; };
struct GOALSTACK { int pstepOwner; int cgoal; GOAL *apgoal[1]; };
extern "C" int CbGoalMax();
extern "C" GOAL *PgoalConstruct(int, GOAL *);

GOAL *GoalStack_Push(GOALSTACK *pgoalstack, int cid)
{
    GOAL *pparent;
    if (pgoalstack->cgoal == 0)
        pparent = 0;
    else
        pparent = pgoalstack->apgoal[pgoalstack->cgoal - 1];
    int count = *(volatile int *)&pgoalstack->cgoal;
    GOAL *pbuffer = pgoalstack->apgoal[count];
    pgoalstack->cgoal = count + 1;
    memset(pbuffer, 0, CbGoalMax());
    GOAL *pgoal = PgoalConstruct(cid, pbuffer);
    pgoal->pstep = (GOAL *)pgoalstack->pstepOwner;
    pgoal->pparent = pparent;
    if (pparent)
        pparent->pchild = pgoal;
    VT *vt = pgoal->vt;
    vt->fn((char *)pgoal + vt->delta);
    return pgoal;
}

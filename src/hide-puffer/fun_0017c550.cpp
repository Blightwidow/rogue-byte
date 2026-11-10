// SPDX-License-Identifier: GPL-3.0-or-later
struct VT { char pad[0x40]; short delta; short index; void (*fn)(void *); };
struct ALERT { char pad[0xC]; int palo; };
struct GUARD { char pad[0x294]; void *pcrv; char pad2[0x134]; ALERT *palert; };
struct OBJ { char pad[0xC]; VT *vt; };
#include "goal.h"
struct GOAL_17C550 : GOAL {
    int state;
};
extern "C" void Goal_Pop(void *);
extern "C" OBJ *func_00205438(GUARD *, int);
extern "C" void GoalFollowCrv_SetCrv(OBJ *, void *, int);
#define F(o, off, T) (*(T *)((char *)(o) + (off)))
void func_0017C550(GOAL_17C550 *pgoal, int nState)
{
    if (nState == pgoal->state)
        return;
    Goal_Pop(&pgoal->pgoalChild);
    pgoal->state = nState;
    switch (nState) {
    case 0: {
        OBJ *pobj = func_00205438(((GUARD *)pgoal->pstep), 0x9E);
        F(pobj, 0x38, int) = ((GUARD *)pgoal->pstep)->palert->palo;
        VT *vt = pobj->vt;
        vt->fn((char *)pobj + vt->delta);
        break;
    }
    case 1: {
        OBJ *pobj = func_00205438(((GUARD *)pgoal->pstep), 0xA7);
        GoalFollowCrv_SetCrv(pobj, ((GUARD *)pgoal->pstep)->pcrv, 0);
        F(pobj, 0xC0, int) = 8;
        F(pobj, 0xC8, int) = ((GUARD *)pgoal->pstep)->palert->palo;
        VT *vt = pobj->vt;
        vt->fn((char *)pobj + vt->delta);
        break;
    }
    }
}

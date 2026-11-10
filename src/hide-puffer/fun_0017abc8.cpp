// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct QUERY { int fFound; char pad[0x2C]; };
#include "xf.h"
#include "so.h"
struct ACT { char pad[0x1C]; float t; };
#include "goal.h"
struct GOAL_17ABC8 : GOAL {
    char pad_30[0x2C];
    void *ptarget;
    int fHeld;
    ACT *pact;
};
struct VT { char pad[0x300]; short delta; short index; void (*fn)(void *, QUERY *, float); };
struct OBJ { char pad[0xC]; VT *vptr; };
extern "C" float g_2dded0;
extern "C" void func_0017AA78(GOAL_17ABC8 *, QUERY *, QW *, QW *);
extern "C" QW ConvertXfPos(int, XF *, QW);
extern "C" QW ConvertXfVec(int, XF *, QW);
extern "C" void SetActvalGoal(ACT *, QW, QW);
void func_0017ABC8(GOAL_17ABC8 *pgoal)
{
    QUERY query;
    QW posAim, vecAim;
    if (pgoal->fHeld == 0)
        return;
    OBJ *target = (OBJ *)pgoal->ptarget;
    VT *vt = target->vptr;
    vt->fn((char *)target + vt->delta, &query, pgoal->pact->t - g_2dded0);
    if (query.fFound == 0) {
        pgoal->fHeld = 0;
        return;
    }
    XF *xf = ((SO *)pgoal->pstep)->pxfLinear;
    func_0017AA78(pgoal, &query, &posAim, &vecAim);
    QW pos = ConvertXfPos(0, xf->pxfParent, posAim);
    QW vec = ConvertXfVec(0, xf->pxfParent, vecAim);
    SetActvalGoal(pgoal->pact, pos, vec);
}

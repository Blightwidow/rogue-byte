// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct QUERY { int fFound; char pad[0x2C]; };
struct XF { char pad[0xA0]; int parent; };
struct SO { char pad[0x58]; XF *linear; };
struct ACT { char pad[0x1C]; float t; };
struct GOAL { char pad[0x10]; SO *pguard; char pad2[0x48]; void *ptarget; int fHeld; ACT *pact; };
struct VT { char pad[0x300]; short delta; short index; void (*fn)(void *, QUERY *, float); };
struct OBJ { char pad[0xC]; VT *vptr; };
extern "C" float g_2dded0;
extern "C" void func_0017AA78(GOAL *, QUERY *, QW *, QW *);
extern "C" QW ConvertXfPos(int, int, QW);
extern "C" QW ConvertXfVec(int, int, QW);
extern "C" void SetActvalGoal(ACT *, QW, QW);
void func_0017ABC8(GOAL *pgoal)
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
    XF *xf = pgoal->pguard->linear;
    func_0017AA78(pgoal, &query, &posAim, &vecAim);
    QW pos = ConvertXfPos(0, xf->parent, posAim);
    QW vec = ConvertXfVec(0, xf->parent, vecAim);
    SetActvalGoal(pgoal->pact, pos, vec);
}

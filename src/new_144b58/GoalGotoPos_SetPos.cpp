#include "sly2.h"
struct PZ { char pad[0x10]; void *zone; };
struct OWN { char pad0[0xDC]; PZ *pz; };
struct CRV { char pad[0xE8]; int count; char pad1[0xF4 - 0xEC]; QW *nodes; };
struct JT { char pad0[0xE8]; OWN *own; char pad1[0x294 - 0xEC]; CRV *crv; };
struct GOAL { char pad0[0x10]; JT *jt; char pad1[4]; GOAL *child; char pad2[0x30 - 0x1C]; int fSimple; char pad3[0x40 - 0x34]; QW posGoal; };
extern "C" QW PosLoWorld(JT *);
extern "C" void FFindPathzoneCrv(void *, QW, QW, CRV *);
extern "C" void MeasureCrv(CRV *);
extern "C" void GoalFollowCrv_SetCrv(GOAL *, CRV *, int);

void GoalGotoPos_SetPos(GOAL *goal, QW posGoal)
{
    goal->posGoal = posGoal;
    if (goal->child == 0)
        return;
    JT *jt = goal->jt;
    CRV *crv = jt->crv;
    PZ *pz = 0;
    if (jt->own)
        pz = jt->own->pz;
    void *zone = 0;
    if (pz)
        zone = pz->zone;
    QW posOwner = PosLoWorld(jt);
    if (zone == 0 || goal->fSimple != 0) {
        crv->count = 2;
        QW *nodes = crv->nodes;
        nodes[0] = posOwner;
        crv->nodes[1] = goal->posGoal;
        MeasureCrv(crv);
    } else {
        FFindPathzoneCrv(zone, posOwner, goal->posGoal, crv);
    }
    GoalFollowCrv_SetCrv(goal->child, crv, 0);
}

#include "sly2.h"
struct PZ { char pad[0x10]; void *zone; };
struct OWN { char pad0[0xDC]; PZ *pz; };
struct CRV { char pad[0xE8]; int count; char pad1[0xF4 - 0xEC]; QW *nodes; };
struct ALERT { char pad0[0xC]; void *palo; char pad1[0x18 - 0x10]; float radCone; };
struct JT { char pad0[0xE8]; OWN *own; char pad1[0x294 - 0xEC]; CRV *crv; char pad2[0x324 - 0x298]; char lm[4]; char pad3[0x3CC - 0x328]; ALERT *alert; };
struct GOAL { char pad0[0x10]; JT *jt; char pad1[4]; GOAL *child; char pad2[0x30 - 0x1C]; int state; char pad3[0x70 - 0x34]; float dist; };
extern "C" void func_001EEF98(GOAL *);
extern "C" float GetAlertPan(ALERT *);
extern "C" QW PosLoWorld(void *);
extern "C" void DecomposeCylind(QW, float *, float *, float *);
extern "C" float RadNormalize__Ff(float);
extern "C" int FCheckLm__FP2LMf(void *, float);
extern "C" QW func_0017BFF8(GOAL *, void *, QW, float);
extern "C" void FFindPathzoneCrv(void *, QW, QW, CRV *);
extern "C" void GoalFollowCrv_SetCrv(GOAL *, CRV *, int);
extern "C" const float D_FLT_002BE748;
extern "C" void func_0017C3E8(GOAL *goal)
{
    func_001EEF98(goal);
    if (goal->state == 0)
        return;
    JT *jt = goal->jt;
    CRV *crv = jt->crv;
    PZ *pz = 0;
    if (jt->own)
        pz = jt->own->pz;
    void *zone = 0;
    if (pz)
        zone = pz->zone;
    ALERT *alert = jt->alert;
    void *palo = alert->palo;
    float pan = GetAlertPan(alert);
    QW posAlert = PosLoWorld(palo);
    asm volatile("" : : "m" (posAlert));
    GOAL *child = goal->child;
    float angles[2];
    if (D_FLT_002BE748 < child->dist)
        goto replan;
    {
        QW vec;
        asm("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvsub.xyzw vf2, vf1, vf2\n\tqmfc2.ni %0, vf2" : "=r" (vec) : "m" (posAlert), "m" (crv->nodes[crv->count - 1]));
        DecomposeCylind(vec, &angles[0], &angles[1], 0);
        float offset = RadNormalize__Ff(angles[0] - pan);
        if (alert->radCone < __builtin_fabsf(offset))
            goto replan;
        if (FCheckLm__FP2LMf(goal->jt->lm, angles[1]))
            return;
    }
replan:
    QW posGuard = PosLoWorld(goal->jt);
    QW posStand = func_0017BFF8(goal, zone, posAlert, pan);
    FFindPathzoneCrv(zone, posGuard, posStand, crv);
    GoalFollowCrv_SetCrv(child, crv, 0);
}

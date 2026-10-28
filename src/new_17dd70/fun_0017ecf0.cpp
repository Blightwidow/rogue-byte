#include "sly2.h"
struct CRV { char pad[0xE4]; int closed; char pad2[0x180 - 0xE8]; void *ranges; };
struct GOAL { char pad[0x10]; void *pguard; char pad1[4]; void *child; char pad2[0x30 - 0x1C]; CRV *crv; int fwd; float s; char pad3[0x40 - 0x3C]; QW pos; char pad4[0x58 - 0x50]; int param; };
struct TARGET { int a[4]; QW pos; };
extern float D_FLT_002BE7BC;
extern float D_FLT_002BE7C0;
extern float D_FLT_002BE7C4;
extern "C" {
int FIsBasicDerivedFrom(void *, int);
float SMinCrv(CRV *);
float SMaxCrv(CRV *);
float SWrapCrv(CRV *, float);
void UpdateCrvExcludedRanges(void *);
float *PgFindCrvExcludedRange(void *, float);
void GetPathPosFromS(CRV *, QW *, void *, float);
void func_002562A8(TARGET *);
void SetGoalTarget(void *, TARGET *);
}
extern "C" void func_0017ECF0(GOAL *pgoal, int force)
{
    float step;
    if (FIsBasicDerivedFrom(pgoal->pguard, 0x3A) != 0)
        step = D_FLT_002BE7BC;
    else
        step = D_FLT_002BE7C0;
    if (pgoal->fwd == 0)
        step = -step;
    float snew = pgoal->s + step;
    if (pgoal->crv->closed == 0) {
        float smin = SMinCrv(pgoal->crv);
        float smax = SMaxCrv(pgoal->crv);
        if (snew < smin)
            snew = smin;
        else if (snew > smax)
            snew = smax;
    } else {
        snew = SWrapCrv(pgoal->crv, snew);
    }
    if (pgoal->param == 0) {
        UpdateCrvExcludedRanges(pgoal->crv->ranges);
        float *range = PgFindCrvExcludedRange(pgoal->crv->ranges, snew);
        if (range != 0) {
            float edge;
            if (pgoal->fwd != 0)
                edge = range[1];
            else
                edge = range[0];
            snew = SWrapCrv(pgoal->crv, edge);
        }
    }
    if (force == 0) {
        float d = pgoal->s - snew;
        if (__builtin_fabsf(d) < D_FLT_002BE7C4)
            return;
    }
    pgoal->s = snew;
    GetPathPosFromS(pgoal->crv, &pgoal->pos, 0, snew);
    void *child = pgoal->child;
    TARGET t;
    func_002562A8(&t);
    t.pos = pgoal->pos;
    SetGoalTarget(child, &t);
}

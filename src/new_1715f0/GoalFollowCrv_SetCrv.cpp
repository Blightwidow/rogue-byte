#include "sly2.h"
struct Crv { char pad0[0xE4]; int closed; };
struct Goal { char pad0[0x10]; void *guard; char pad14[0x1C]; Crv *crv; float s; int reverse; int open; int pad40; float end; float sHint; };
extern "C" char B_003DD020;
extern "C" QW PosLoWorld(void *);
extern "C" void FindCrvClosestPointFromS(Crv *, QW, void *, int, int, int, float *, float);
extern "C" void FindCrvClosestPointAll(Crv *, QW, void *, int, int, int, float *);
extern "C" float SMinCrv(Crv *);
extern "C" float SMaxCrv(Crv *);
extern "C" void GetPathPosFromS(Crv *, void *, int, float);
extern "C" void GoalFollowCrv_SetCrv(Goal *goal, Crv *crv, int reverse)
{
    goal->reverse = reverse;
    goal->crv = crv;
    if (goal->sHint >= 0.0f) {
        FindCrvClosestPointFromS(crv, PosLoWorld(goal->guard), &B_003DD020, 0, 0, 0, &goal->s, goal->sHint);
        goal->sHint = -1.0f;
    } else {
        FindCrvClosestPointAll(crv, PosLoWorld(goal->guard), &B_003DD020, 0, 0, 0, &goal->s);
    }
    if (crv->closed != 0) {
        goal->open = 0;
        return;
    }
    goal->open = 1;
    if (goal->reverse != 0)
        goal->end = SMinCrv(crv);
    else
        goal->end = SMaxCrv(crv);
    GetPathPosFromS(crv, (char *)goal + 0xB0, 0, goal->end);
}

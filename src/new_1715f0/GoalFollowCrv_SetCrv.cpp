#include "sly2.h"
struct Crv { char pad0[0xE4]; int closed; };
#include "goal.h"
struct GOAL_178D90 : GOAL {
    Crv *crv;
    float s;
    int reverse;
    int open;
    char pad_40[0x4];
    float end;
    float sHint;
};
extern "C" char B_003DD020;
extern "C" QW PosLoWorld(void *);
extern "C" void FindCrvClosestPointFromS(Crv *, QW, void *, int, int, int, float *, float);
extern "C" void FindCrvClosestPointAll(Crv *, QW, void *, int, int, int, float *);
extern "C" float SMinCrv(Crv *);
extern "C" float SMaxCrv(Crv *);
extern "C" void GetPathPosFromS(Crv *, void *, int, float);
extern "C" void GoalFollowCrv_SetCrv(GOAL_178D90 *goal, Crv *crv, int reverse)
{
    goal->reverse = reverse;
    goal->crv = crv;
    if (goal->sHint >= 0.0f) {
        FindCrvClosestPointFromS(crv, PosLoWorld(((void *)goal->pstep)), &B_003DD020, 0, 0, 0, &goal->s, goal->sHint);
        goal->sHint = -1.0f;
    } else {
        FindCrvClosestPointAll(crv, PosLoWorld(((void *)goal->pstep)), &B_003DD020, 0, 0, 0, &goal->s);
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

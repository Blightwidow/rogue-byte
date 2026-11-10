#include "sly2.h"
struct Sma { int kind; int pad4; int oid; };
struct Guard { char pad0[0xE7C]; float lo; float hi; };
#include "goal.h"
struct GOAL_17A5B0 : GOAL {
    char pad_30[0x10];
    Sma *sma;
    char pad_44[0xC];
    int state;
    float stateF;
    float timer;
};
extern "C" float g_2dded0;
extern "C" float GRandInRange(float, float);
extern "C" void SetSmaGoal__FP3SMA3OID(int, int);
extern "C" void GoalFlinch_SetState(GOAL_17A5B0 *goal, int state)
{
    if (state == goal->state)
        return;
    goal->state = state;
    goal->stateF = (float)state;
    switch (state) {
    case 0: {
        if (goal->sma->kind == 1)
            SetSmaGoal__FP3SMA3OID(goal->sma->oid, 0x44);
        float base = g_2dded0;
        Guard *guard = ((Guard *)goal->pstep);
        goal->timer = base + GRandInRange(guard->lo, guard->hi);
        break;
    }
    case 1:
        if (goal->sma->kind == state)
            SetSmaGoal__FP3SMA3OID(goal->sma->oid, 0x43);
        break;
    }
}

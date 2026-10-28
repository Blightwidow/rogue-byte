#include "sly2.h"
struct Sma { int kind; int pad4; int oid; };
struct Guard { char pad0[0xE7C]; float lo; float hi; };
struct Goal { char pad0[0x10]; Guard *guard; char pad14[0x2C]; Sma *sma; char pad44[0xC]; int state; float stateF; float timer; };
extern "C" float g_2dded0;
extern "C" float GRandInRange(float, float);
extern "C" void SetSmaGoal__FP3SMA3OID(int, int);
extern "C" void GoalFlinch_SetState(Goal *goal, int state)
{
    if (state == goal->state)
        return;
    goal->state = state;
    float stateFloat;
    asm("mtc1 %1, %0\n\tnop\n\tcvt.s.w %0, %0" : "=f" (stateFloat) : "r" (state));
    goal->stateF = stateFloat;
    switch (state) {
    case 0: {
        if (goal->sma->kind == 1)
            SetSmaGoal__FP3SMA3OID(goal->sma->oid, 0x44);
        float base = g_2dded0;
        Guard *guard = goal->guard;
        goal->timer = base + GRandInRange(guard->lo, guard->hi);
        break;
    }
    case 1:
        if (goal->sma->kind == state)
            SetSmaGoal__FP3SMA3OID(goal->sma->oid, 0x43);
        break;
    }
}

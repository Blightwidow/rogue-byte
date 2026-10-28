#include "sly2.h"
struct Guard { char pad0[0x2DC]; int cmdPos; char pad2e0[8]; int cmd; int cmd2; char pad2f0[0xCF8]; unsigned flags; };
struct Goal { char pad0[0x10]; Guard *guard; char pad14[0x2C]; int cmd; };
extern "C" void func_001EEF70();
extern "C" void GoalIdle_SetState(Goal *, int);
extern "C" QW PosLoWorld(Guard *);
extern "C" void FindClosestScriptCmd(int, QW, void *);
extern "C" int func_00209098(Guard *);
extern "C" void GoalIdle_Activate(Goal *goal)
{
    func_001EEF70();
    Guard * guard;
    guard = goal->guard;
    int cmd = guard->cmd;
    if (cmd != 0) {
        goal->cmd = cmd;
    } else if ((guard->flags & 2) != 0) {
        goal->cmd = guard->cmd2; asm volatile("");
    } else {
        GoalIdle_SetState(goal, 2);
        goal->cmd = 0;
        return;
    }
    if (goal->guard->cmdPos != 0)
        FindClosestScriptCmd(goal->cmd, PosLoWorld(goal->guard), &goal->guard->cmdPos);
    if (func_00209098(goal->guard) != 0) {
        GoalIdle_SetState(goal, 3);
        return;
    }
    GoalIdle_SetState(goal, 0);
}

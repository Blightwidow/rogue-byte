/* SPDX-License-Identifier: GPL-3.0-or-later */
struct Guard { char pad0[0xFE8]; unsigned flags; };
struct Goal { char pad0[0x10]; Guard *guard; char pad1[4]; void *child; char pad2[0x30 - 0x1C]; char target[1]; };
extern "C" void func_001EEF98(Goal *);
extern "C" int FGoalAnimDone(void *);
extern "C" int func_001C1FA0(void *, Guard *, float);
extern "C" void func_0017E9B0(Goal *);
void func_0017E918(Goal *goal)
{
    func_001EEF98(goal);
    Guard *guard = goal->guard;
    if ((guard->flags & 1) != 0) {
        if (FGoalAnimDone(goal->child) != 0) {
            if (func_001C1FA0(goal->target, goal->guard, 25.0f) == 0)
                func_0017E9B0(goal);
        }
    } else {
        if (func_001C1FA0(goal->target, guard, 25.0f) == 0)
            func_0017E9B0(goal);
    }
}

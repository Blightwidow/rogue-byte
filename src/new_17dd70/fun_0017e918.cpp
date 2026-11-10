/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "stepguard.h"
#include "goal.h"
struct GOAL_17E918 : GOAL {
    char target[1];
};
extern "C" void func_001EEF98(GOAL_17E918 *);
extern "C" int FGoalAnimDone(void *);
extern "C" int func_001C1FA0(void *, STEPGUARD *, float);
extern "C" void func_0017E9B0(GOAL_17E918 *);
void func_0017E918(GOAL_17E918 *goal)
{
    func_001EEF98(goal);
    STEPGUARD *guard = ((STEPGUARD *)goal->pstep);
    if ((guard->grf & 1) != 0) {
        if (FGoalAnimDone(((void *)goal->pgoalChild)) != 0) {
            if (func_001C1FA0(goal->target, ((STEPGUARD *)goal->pstep), 25.0f) == 0)
                func_0017E9B0(goal);
        }
    } else {
        if (func_001C1FA0(goal->target, guard, 25.0f) == 0)
            func_0017E9B0(goal);
    }
}

#include "sly2.h"
#include "goal.h"
struct GOAL_175600 : GOAL {
    char pad_30[0x4];
    int state;
    char pad_38[0x8];
    int target;
};
extern "C" void func_001EEF98();
extern "C" int func_001EF0A8(GOAL_175600 *);
extern "C" int FGoalAnimDone(int);
extern "C" void func_00175488(GOAL_175600 *, int);
extern "C" void func_00175600(GOAL_175600 *goal)
{
    func_001EEF98();
    for (;;) {
        if (func_001EF0A8(goal) != 0)
            return;
        int state = goal->state;
        switch (state) {
        case 0:
            if (goal->target != 0)
                func_00175488(goal, 1);
            else if (FGoalAnimDone(((int)goal->pgoalChild)) != 0)
                func_00175488(goal, -1);
            break;
        case 1:
            if (FGoalAnimDone(((int)goal->pgoalChild)) != 0)
                func_00175488(goal, -1);
            break;
        }
        if (state == goal->state)
            break;
    }
}

#include "sly2.h"
struct Goal { char pad0[0x18]; int anim; char pad1c[0x18]; int state; char pad38[8]; int target; };
extern "C" void func_001EEF98();
extern "C" int func_001EF0A8(Goal *);
extern "C" int FGoalAnimDone(int);
extern "C" void func_00175488(Goal *, int);
extern "C" void func_00175600(Goal *goal)
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
            else if (FGoalAnimDone(goal->anim) != 0)
                func_00175488(goal, -1);
            break;
        case 1:
            if (FGoalAnimDone(goal->anim) != 0)
                func_00175488(goal, -1);
            break;
        }
        if (state == goal->state)
            break;
    }
}

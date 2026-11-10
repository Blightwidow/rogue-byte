#include "goal.h"
struct GOAL_174B68 : GOAL {
    int state;
    char pad_34[0xC];
    int anim;
};
extern "C" void func_001EEF98();
extern "C" int FDoneAnimref(int);
extern "C" void GoalAnim_SetState(GOAL_174B68 *, int);
extern "C" void GoalAnim_Update(GOAL_174B68 *goal)
{
    func_001EEF98();
    int state; do { state = goal->state; if (state == 0 && FDoneAnimref(goal->anim)) GoalAnim_SetState(goal, 1); } while (state != goal->state);
}

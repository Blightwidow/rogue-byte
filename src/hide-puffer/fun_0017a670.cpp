#include "sly2.h"
extern "C" void GoalAnim_Update(void*);
extern "C" void GoalFlinch_SetState(void*, int);
extern "C" QW PosLoWorld(void*);
extern "C" float g_2dded0;
struct Track { char pad[0x20]; QW pos; };
struct Guard { char pad[0x35C]; Track* track; };
struct Goal { char pad0[0x10]; Guard* guard; char pad1[0x50 - 0x14]; int state; char pad2[4]; float tNext; };
extern "C" void func_0017A670(Goal* goal)
{
    GoalAnim_Update(goal);
    int state;
    do {
        state = goal->state;
        if (state == 0 && g_2dded0 > goal->tNext) {
            GoalFlinch_SetState(goal, 1);
        }
    } while (goal->state != state);
    Guard* guard = goal->guard;
    Track* track = guard->track;
    track->pos = PosLoWorld(guard);
}

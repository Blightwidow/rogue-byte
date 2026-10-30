#include "sly2.h"
struct VCall { short delta; short index; void (*fn)(void *); };
struct Obj { char pad0[0xC]; char *vtable; };
struct Goal { char pad0[0x10]; void *guard; char pad14[4]; char child[0x34]; int state; char pad50[0x70]; int kind; char padC4[4]; int target; char padCC[4]; QW posLast; float stuck; };
extern "C" float g_2be694;
extern "C" void GoalFollowCrv_SetState(Goal *, int);
extern "C" void Goal_Pop(void *);
extern "C" Obj *func_00205438(void *, int);
extern "C" QW PosLoWorld(void *);
extern "C" void GoalFollowCrvAnim_SetState(Goal *goal, int state)
{
    unsigned old = goal->state;
    if (state == old)
        return;
    GoalFollowCrv_SetState(goal, state);
    switch (goal->state) {
    case 0:
    case 1:
        if (old > 1) {
            Goal_Pop(goal->child);
            Obj *idle = func_00205438(goal->guard, 0x9D);
            *(int *)((char *)idle + 0x3C) = goal->kind;
            if (goal->kind == 8)
                *(int *)((char *)idle + 0x38) = goal->target;
            VCall *activate = (VCall *)(idle->vtable + 0x40);
            activate->fn((char *)idle + activate->delta);
            goal->posLast = PosLoWorld(goal->guard);
            goal->stuck = g_2be694;
        }
        break;
    case 2:
    case 3:
    case 4:
        if (old != 2 && old != 4 && old != 3) {
            Goal_Pop(goal->child);
            Obj *alert = func_00205438(goal->guard, 0x9E);
            *(int *)((char *)alert + 0x38) = goal->target;
            VCall *activate = (VCall *)(alert->vtable + 0x40);
            activate->fn((char *)alert + activate->delta);
        }
        break;
    }
}

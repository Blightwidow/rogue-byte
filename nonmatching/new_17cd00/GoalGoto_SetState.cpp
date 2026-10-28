#include "sly2.h"
struct VT { char pad[0x40]; short delta; short index; void (*fn)(void *); };
struct OBJ { char pad[0xC]; VT *vptr; };
struct GUARD { char pad[0x294]; void *crv; char pad1[0xFE8 - 0x298]; unsigned grf; };
struct GOAL { char pad0[0x10]; GUARD *guard; char pad1[4]; OBJ *child; char pad2[0x30 - 0x1C]; int state; float tState; char pad3[0xA8 - 0x38]; int face; int pzlink; int faceFlag; int straight; char pad4[0xB8 - 0xB0 + 0]; };
extern "C" void Goal_Pop(void *);
extern "C" OBJ *func_00205438(GUARD *, int);
extern "C" void GoalFollowCrv_SetCrv(OBJ *, void *, int);
extern float g_2dded0;
extern "C" void GoalGoto_SetState(GOAL *goal, int newState)
{
    int previous = goal->state;
    if (newState == previous)
        return;
    if (newState >= 0 && newState < 3 && previous >= 0 && previous < 3) {
        goal->state = newState;
    } else {
        Goal_Pop(&goal->child);
        goal->state = newState;
    }
    goal->tState = g_2dded0;
    switch (newState + 1) {
    case 0:
    case 1:
        break;
    case 5: {
        OBJ *hold = func_00205438(goal->guard, 0x9E);
        *(int *)((char *)hold + 0x38) = *(int *)((char *)goal + 0xA8);
        VT *vtable = hold->vptr;
        vtable->fn((char *)hold + vtable->delta);
        break;
    }
    case 4: {
        OBJ *route = func_00205438(goal->guard, 0xBE);
        *(int *)((char *)route + 0x30) = *(int *)((char *)goal + 0xB8);
        VT *vtable = route->vptr;
        vtable->fn((char *)route + vtable->delta);
        break;
    }
    case 2:
    case 3: {
        OBJ *follow = goal->child;
        if (follow == 0) {
            follow = func_00205438(goal->guard, 0xA7);
            *(int *)((char *)follow + 0xC8) = *(int *)((char *)goal + 0xA8);
            *(int *)((char *)follow + 0x40) = *(int *)((char *)goal + 0xBC);
            int mode = 8;
            if (*(int *)((char *)goal + 0xA8) == 0 || *(int *)((char *)goal + 0xAC) != 0 || (goal->guard->grf & 4) == 0)
                mode = 9;
            *(int *)((char *)follow + 0xC0) = mode;
            GoalFollowCrv_SetCrv(follow, goal->guard->crv, 0);
            VT *vtable = follow->vptr;
            vtable->fn((char *)follow + vtable->delta);
            break;
        }
        GoalFollowCrv_SetCrv(follow, goal->guard->crv, 0);
        break;
    }
    case 6: {
        OBJ *snap = func_00205438(goal->guard, 0xBF);
        *(QW *)((char *)snap + 0x30) = *(QW *)((char *)goal + 0x80);
        *(QW *)((char *)snap + 0x40) = *(QW *)((char *)goal + 0x90);
        VT *vtable = snap->vptr;
        vtable->fn((char *)snap + vtable->delta);
        break;
    }
    }
}

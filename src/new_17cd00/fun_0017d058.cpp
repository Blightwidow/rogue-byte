#include "sly2.h"
struct VCall { short delta; short index; void (*fn)(void *); };
struct Obj { char pad0[0xC]; char *vtable; };
struct Goal { char pad0[0x10]; void *guard; char pad14[4]; char child[0x18]; int state; float time; int pad38; int extra; };
extern "C" float g_2dded0;
extern "C" void Goal_Pop(void *);
extern "C" Obj *func_00205438(void *, int);
extern "C" void func_0017D058(Goal *goal, int state)
{
    if (state == goal->state)
        return;
    Goal_Pop(goal->child);
    goal->state = state;
    goal->time = *(volatile float *)&g_2dded0;
    switch (state) {
    case 1: {
        Obj *idle = func_00205438(goal->guard, 0x9D);
        *(int *)((char *)idle + 0x3C) = 2;
        VCall *activate = (VCall *)(idle->vtable + 0x40);
        activate->fn((char *)idle + activate->delta);
        goal->extra = 0;
        break;
    }
    case 0: {
        Obj *idle = func_00205438(goal->guard, 0x9D);
        *(int *)((char *)idle + 0x3C) = 9;
        VCall *activate = (VCall *)(idle->vtable + 0x40);
        activate->fn((char *)idle + activate->delta);
        break;
    }
    }
}

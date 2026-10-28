#include "sly2.h"
struct VEntry { short delta; short index; void *(*fn)(void *, void *); };
struct VCall { short delta; short index; void (*fn)(void *); };
struct Obj { char pad0[0xC]; char *vtable; };
struct Rec { char padA0[0xA0]; int hasPose; char pad0xA4[0x1C]; int value; };
struct Goal { char pad0[0x10]; void *guard; char pad14[4]; char child[0x18]; Obj *target; int state; float time; Rec *rec; };
extern "C" float g_2dded0;
extern "C" QW g_2a2dd0;
extern "C" void UnsubscribeLoObject(Obj *, void *);
extern "C" void SubscribeLoObject(Obj *, void *);
extern "C" void Goal_Pop(void *);
extern "C" Obj *func_00205438(void *, int);
extern "C" void func_0020AC28(void *, void *, void *, QW);
extern "C" void func_001EF038(Goal *);
extern "C" void func_00175488(Goal *goal, int state)
{
    if (state == goal->state)
        return;
    if (goal->state == 0) {
        UnsubscribeLoObject(goal->target, goal->guard);
        goal->target = 0;
        func_0020AC28(goal->guard, 0, 0, g_2a2dd0);
    }
    Goal_Pop(goal->child);
    goal->state = state;
    goal->time = *(volatile float *)&g_2dded0;
    switch (state) {
    case 0: {
        SubscribeLoObject(goal->target, goal->guard);
        Obj *look = func_00205438(goal->guard, 0x9F);
        *(Obj **)((char *)look + 0x38) = goal->target;
        *(int *)((char *)look + 0x40) = goal->rec->value;
        if (goal->rec->hasPose != 0) {
            char pose[0x40];
            Obj *target = goal->target;
            VEntry *entry = (VEntry *)(target->vtable + 0x100);
            void *pvPose = entry->fn((char *)target + entry->delta, pose);
            func_0020AC28(goal->guard, goal->rec, pvPose, *(QW *)(pose + 0x30));
        }
        VCall *activate = (VCall *)(look->vtable + 0x40);
        activate->fn((char *)look + activate->delta);
        break;
    }
    case 1: {
        Obj *react = func_00205438(goal->guard, 0x9D);
        *(int *)((char *)react + 0x3C) = 4;
        *(Obj **)((char *)react + 0x38) = goal->target;
        VCall *activate = (VCall *)(react->vtable + 0x40);
        activate->fn((char *)react + activate->delta);
        break;
    }
    case -1:
        func_001EF038(goal);
        break;
    }
}

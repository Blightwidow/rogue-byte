#include "sly2.h"
struct VT { char pad[0x40]; short delta; short index; void (*fn)(void *); };
struct OBJ { char pad[0xC]; VT *vptr; };
struct TARGET { int a[4]; QW pos; };
struct BEH { char pad0[0x10]; void *pactor; char pad1[0x18 - 0x14]; char sub[0x18]; int state; float tState; };
extern "C" {
void Goal_Pop(void *);
OBJ *func_00205438(void *, int);
QW PosLoWorld(void *);
QW func_00172760(void *);
void func_00172560(void *);
void func_001728B0(void *);
void func_00172F10(void *);
void func_00209818(void *, float);
float atan2f(float, float);
void func_002562A8(TARGET *);
void SetGoalTarget(void *, TARGET *);
void SetSearchGoal(void *, void *);
}
extern float g_2dded0;
extern "C" const float RO_FLT_002A5398;
extern "C" void SetSearchState(BEH *beh, int newState)
{
    if (newState == beh->state)
        return;
    Goal_Pop(&beh->sub);
    beh->state = newState;
    asm volatile("");
    beh->tState = g_2dded0;
    switch (newState) {
    case 0: {
        OBJ *idle = func_00205438(beh->pactor, 0x9D);
        *(int *)((char *)idle + 0x3C) = 0xC;
        VT *vtable = idle->vptr;
        vtable->fn((char *)idle + vtable->delta);
        break;
    }
    case 1: {
        OBJ *go = func_00205438(beh->pactor, 0xBA);
        *(int *)((char *)go + 0xC0) = 1;
        QW pos = func_00172760(beh);
        TARGET t;
        func_002562A8(&t);
        t.pos = pos;
        SetGoalTarget(go, &t);
        VT *vtable = go->vptr;
        vtable->fn((char *)go + vtable->delta);
        *(float *)((char *)beh + 0x38) = RO_FLT_002A5398;
        break;
    }
    case 2: {
        QW goalPos = func_00172760(beh);
        QW pos = PosLoWorld(beh->pactor);
        register QW bits asm("$2");
        register QW rotated asm("$3");
        float fx, fy;
        asm("qmtc2.ni %0, vf2" : : "r" (pos));
        char *actor = (char *)beh->pactor;
        asm("lqc2 vf1, %0" : : "m" (goalPos));
        asm("vsub.xyzw vf1, vf1, vf2");
        actor += 0xFD0;
        asm volatile("qmfc2.ni %0, vf1\n\tprot3w %1, %0\n\tmtc1 %0, %2\n\tmtc1 %1, %3" : "=&r" (bits), "=&r" (rotated), "=f" (fx), "=f" (fy));
        func_00209818(actor, atan2f(fy, fx));
        OBJ *alert = func_00205438(beh->pactor, 0x9E);
        VT *vtable = alert->vptr;
        vtable->fn((char *)alert + vtable->delta);
        func_00172560(beh);
        break;
    }
    case 3: {
        OBJ *go = func_00205438(beh->pactor, 0xBA);
        *(int *)((char *)go + 0xC0) = 1;
        func_001728B0(beh);
        func_00172F10(beh);
        VT *vtable = go->vptr;
        vtable->fn((char *)go + vtable->delta);
        break;
    }
    case 4: {
        OBJ *idle = func_00205438(beh->pactor, 0x9D);
        *(int *)((char *)idle + 0x3C) = 0xE;
        VT *vtable = idle->vptr;
        vtable->fn((char *)idle + vtable->delta);
        SetSearchGoal(beh, 0);
        *(int *)((char *)beh + 0x48) = 0;
        break;
    }
    case 5: {
        OBJ *alert = func_00205438(beh->pactor, 0x9E);
        *(int *)((char *)alert + 0x3C) = 1;
        VT *vtable = alert->vptr;
        vtable->fn((char *)alert + vtable->delta);
        break;
    }
    }
}

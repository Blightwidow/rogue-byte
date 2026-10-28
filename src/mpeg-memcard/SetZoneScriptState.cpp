/* SPDX-License-Identifier: GPL-3.0-or-later */
struct VT { char pad[0x40]; short delta; short index; void (*fn)(void *); };
struct OBJ { char pad[0xC]; VT *vptr; };
struct GOAL { char pad0[0x10]; char *pguard; char pad1[0x18 - 0x14]; void *pchild; char pad2[0x30 - 0x1C]; int state; float tState; void *pscript; };
extern "C" {
void func_00171C18(void *, void *);
void Goal_Pop(void *);
OBJ *func_00205438(void *, int);
void SetGuardScript(OBJ *, void *, int, void *);
void bevy_camera_follow_activity(void *, int, void *);
}
extern float g_2dded0;
extern int g_2e1e40;
extern char B_002DEB30;
extern "C" void SetZoneScriptState(GOAL *pgoal, int newState)
{
    if (newState == pgoal->state)
        return;
    if (pgoal->state == 0)
        func_00171C18(pgoal->pchild, pgoal->pguard + 0x1090);
    Goal_Pop(&pgoal->pchild);
    pgoal->state = newState;
    asm volatile("");
    pgoal->tState = g_2dded0;
    switch (newState) {
    case 0: {
        OBJ *pscriptGoal = func_00205438(pgoal->pguard, 0xA9);
        SetGuardScript(pscriptGoal, *(void **)((char *)pgoal + 0x38), 0, pgoal->pguard + 0x1090);
        VT *vtable = pscriptGoal->vptr;
        vtable->fn((char *)pscriptGoal + vtable->delta);
        break;
    }
    case 1: {
        OBJ *palert = func_00205438(pgoal->pguard, 0x9E);
        *(int *)((char *)palert + 0x38) = g_2e1e40;
        VT *vtable = palert->vptr;
        vtable->fn((char *)palert + vtable->delta);
        break;
    }
    case 2: {
        OBJ *pidle = func_00205438(pgoal->pguard, 0x9D);
        *(char **)((char *)pidle + 0x40) = pgoal->pguard + 0x1060;
        VT *vtable = pidle->vptr;
        vtable->fn((char *)pidle + vtable->delta);
        bevy_camera_follow_activity(&B_002DEB30, 0x33, pgoal->pguard);
        break;
    }
    }
}

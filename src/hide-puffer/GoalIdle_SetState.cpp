struct VT { char pad[0x40]; short delta; short index; void (*fn)(void *); };
struct OBJ { char pad[0xC]; VT *vptr; };
struct GOAL { char pad0[0x10]; char *pguard; char pad1[0x18 - 0x14]; void *pchild; char pad2[0x30 - 0x1C]; float tEnd; float tStart; int state; float tState; void *pscript; };
extern "C" {
void func_00171C18(void *, void *);
void Goal_Pop(void *);
OBJ *func_00205438(void *, int);
void SetGuardScript(OBJ *, void *, int, void *);
void func_00179E80(GOAL *);
void func_00179EF8(GOAL *);
}
extern const float D_002A5590;
extern float g_2dded0;
extern "C" void GoalIdle_SetState(GOAL *pgoal, int newState)
{
    if (newState == pgoal->state)
        return;
    if (pgoal->state == 0)
        func_00171C18(pgoal->pchild, pgoal->pguard + 0x2DC);
    Goal_Pop(&pgoal->pchild);
    pgoal->state = newState;
    asm volatile("");
    pgoal->tState = g_2dded0;
    switch (newState) {
    case 1:
    case 2: {
        OBJ *pwait = func_00205438(pgoal->pguard, 0x9E);
        VT *vtable = pwait->vptr;
        vtable->fn((char *)pwait + vtable->delta);
        func_00179EF8(pgoal);
        pgoal->tEnd = D_002A5590;
        break;
    }
    case 0: {
        OBJ *pscriptGoal = func_00205438(pgoal->pguard, 0xA9);
        SetGuardScript(pscriptGoal, pgoal->pscript, 0, pgoal->pguard + 0x2DC);
        VT *vtable = pscriptGoal->vptr;
        vtable->fn((char *)pscriptGoal + vtable->delta);
        func_00179E80(pgoal);
        pgoal->tStart = D_002A5590;
        break;
    }
    case 3: {
        OBJ *pwait = func_00205438(pgoal->pguard, 0x9E);
        VT *vtable = pwait->vptr;
        *(int *)((char *)pwait + 0x3C) = 1;
        vtable->fn((char *)pwait + vtable->delta);
        break;
    }
    }
}

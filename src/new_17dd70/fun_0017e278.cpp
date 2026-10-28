struct VT { char pad[0x40]; short delta; short index; void (*fn)(void *); };
struct OBJ { char pad[0xC]; VT *vptr; };
struct GOAL { char pad0[0x10]; void *pguard; char pad1[0x18 - 0x14]; void *pchild; char pad2[0x30 - 0x1C]; int state; float tState; int target; };
extern "C" {
void Goal_Pop(void *);
OBJ *func_00205438(void *, int);
void func_0017E0E0(GOAL *);
}
extern float g_2dded0;
extern "C" void func_0017E278(GOAL *pgoal, int newState)
{
    if (newState == pgoal->state)
        return;
    Goal_Pop(&pgoal->pchild);
    pgoal->state = newState;
    pgoal->tState = *(float *)&g_2dded0;
    switch (newState) {
    case 0: {
        OBJ *pidle = func_00205438(pgoal->pguard, 0x9D);
        VT *vtable = pidle->vptr;
        *(int *)((char *)pidle + 0x3C) = 0xB;
        *(int *)((char *)pidle + 0x38) = pgoal->target;
        vtable->fn((char *)pidle + vtable->delta);
        break;
    }
    case 1: {
        OBJ *pgoto = func_00205438(pgoal->pguard, 0xBA);
        *(int *)((char *)pgoto + 0xC0) = 1;
        *(int *)((char *)pgoto + 0x38) = 0x1C;
        func_0017E0E0(pgoal);
        VT *vtable = pgoto->vptr;
        vtable->fn((char *)pgoto + vtable->delta);
        break;
    }
    case 2: {
        OBJ *palert = func_00205438(pgoal->pguard, 0x9E);
        *(int *)((char *)palert + 0x3C) = 1;
        VT *vtable = palert->vptr;
        vtable->fn((char *)palert + vtable->delta);
        break;
    }
    }
}

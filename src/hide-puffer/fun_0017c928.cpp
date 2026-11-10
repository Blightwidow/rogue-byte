#include "sly2.h"
struct VT { char pad[0x40]; short delta; short index; void (*fn)(void *); };
struct OBJ { char pad[0xC]; VT *vptr; };
struct TARGET { int a[4]; QW pos; };
#include "goal.h"
struct GOAL_17C928 : GOAL {
    int target;
    char pad_34[0xC];
    QW offset;
    int state;
    float tState;
    char pad_58[0x8];
    QW pos;
};
extern "C" {
void Goal_Pop(void *);
OBJ *func_00205438(void *, int);
QW PosLoWorld(void *);
QW ConvertAloPos(void *, void *, QW);
void func_002562A8(TARGET *);
void SetGoalTarget(void *, TARGET *);
}
extern float g_2dded0;
extern "C" void func_0017C928(GOAL_17C928 *pgoal, int newState)
{
    if (newState == pgoal->state)
        return;
    Goal_Pop(&((void *)pgoal->pgoalChild));
    pgoal->state = newState;
    pgoal->tState = *(float *)&g_2dded0;
    switch (newState) {
    case 1: {
        OBJ *pgoto = func_00205438(((void *)pgoal->pstep), 0xBA);
        QW pos = PosLoWorld((void *)pgoal->target);
        pgoal->pos = pos;
        *(int *)((char *)pgoto + 0xC0) = 1;
        *(int *)((char *)pgoto + 0xA8) = pgoal->target;
        *(int *)((char *)pgoto + 0xAC) = 1;
        TARGET t;
        func_002562A8(&t);
        t.pos = pos;
        SetGoalTarget(pgoto, &t);
        *(int *)((char *)pgoto + 0x38) = 0x1C;
        VT *vtable = pgoto->vptr;
        vtable->fn((char *)pgoto + vtable->delta);
        break;
    }
    case 2: {
        OBJ *palert = func_00205438(((void *)pgoal->pstep), 0x9E);
        int tgt = pgoal->target;
        *(int *)((char *)palert + 0x3C) = 1;
        *(int *)((char *)palert + 0x38) = tgt;
        VT *vtable = palert->vptr;
        vtable->fn((char *)palert + vtable->delta);
        break;
    }
    case 0: {
        OBJ *pgoto = func_00205438(((void *)pgoal->pstep), 0xBA);
        pgoal->pos = PosLoWorld((void *)pgoal->target);
        QW off = ConvertAloPos((void *)pgoal->target, 0, pgoal->offset);
        *(int *)((char *)pgoto + 0xC0) = 1;
        TARGET t;
        func_002562A8(&t);
        t.pos = off;
        SetGoalTarget(pgoto, &t);
        *(int *)((char *)pgoto + 0xA8) = pgoal->target;
        VT *vtable = pgoto->vptr;
        vtable->fn((char *)pgoto + vtable->delta);
        break;
    }
    }
}

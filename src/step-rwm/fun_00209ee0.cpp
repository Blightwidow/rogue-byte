#include "sly2.h"
typedef int QW __attribute__((mode(TI)));
extern "C" int FIsGuardInSgs(void *, int);
extern "C" char *func_00205458(void *, int);
extern "C" void func_0017A8C8(void *, int);
extern "C" void GoalAnimLeap_SetState(void *, int);
extern "C" QW LimitVectorLength__FP6VECTORfT0(QW, float);
extern "C" float D_002C3DA8;
struct VT { char pad[0x108]; short d108; short i108; QW (*f108)(void *); char pad2[0x118 - 0x110]; short d118; short i118; void (*f118)(void *, QW); };
struct GUARD { char pad[0xC]; VT *vt; };
void func_00209EE0(GUARD *g)
{
    if (FIsGuardInSgs(g, 0x12) || FIsGuardInSgs(g, 0x13)) {
        func_0017A8C8(func_00205458(g, 0xB0), 2);
    } else if (FIsGuardInSgs(g, 0x17)) {
        char *goal = func_00205458(g, 0xB1);
        int s = *(int *)(goal + 0x50);
        if (s != 3 && s != 6) GoalAnimLeap_SetState(goal, 2);
    } else {
        return;
    }
    QW v = g->vt->f108((char *)g + g->vt->d108);
    QW l = LimitVectorLength__FP6VECTORfT0(v, D_002C3DA8);
    g->vt->f118((char *)g + g->vt->d118, l);
}

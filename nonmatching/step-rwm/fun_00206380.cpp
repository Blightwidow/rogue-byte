#include "sly2.h"
struct VT { char p0[0x1F0]; short d1F0; short i1F0; int (*f1F0)(void *); };
struct OBJ { char p0[0xC]; VT *vt; char p10[0xEC - 0x10]; void *fEC; };
struct GOAL { char p0[0x50]; int f50; char p54[0x5C - 0x54]; OBJ *pobj5C; };
extern "C" {
int FIgnoreSoIntersection(void *, OBJ *);
int FIsGuardInSgs(void *, int);
GOAL *GoalStack_PgoalFind(void *, int);
int IMax(int, int);
}
extern "C" int func_00206380(void *pthis, OBJ *pobj)
{
    int result = FIgnoreSoIntersection(pthis, pobj);
    if (FIsGuardInSgs(pthis, 7)) {
        if (!pobj->vt->f1F0((char *)pobj + pobj->vt->d1F0))
            result = IMax(result, 1);
    } else if (FIsGuardInSgs(pthis, 0x17)) {
        GOAL *pgoal = GoalStack_PgoalFind((char *)pthis + 0x26C, 0xB1);
        if (pobj->fEC == pgoal->pobj5C->fEC) {
            int v1 = pgoal->f50;
            if (v1 == 0 || (v1 >= 4 && v1 < 6))
                result = IMax(result, 1);
        }
    }
    return result;
}

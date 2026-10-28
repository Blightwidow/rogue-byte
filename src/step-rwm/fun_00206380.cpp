#include "sly2.h"
extern "C" int FIgnoreSoIntersection();
extern "C" int FIsGuardInSgs(void *, int);
extern "C" char *GoalStack_PgoalFind(void *, int);
extern "C" int IMax(int, int);
struct VT { char pad[0x1F0]; short delta; short index; int (*fn)(void *); };
struct SO { char pad[0xC]; VT *vt; };
int func_00206380(char *guard, SO *so)
{
    int r = FIgnoreSoIntersection();
    register int s asm("$3");
    register int keep asm("$2");
    char *goal;
    if (FIsGuardInSgs(guard, 7)) {
        keep = so->vt->fn((char *)so + so->vt->delta);
        goto chk;
    }
    if (FIsGuardInSgs(guard, 0x17)) {
        goal = GoalStack_PgoalFind(guard + 0x26C, 0xB1);
        if (*(int *)((char *)so + 0xEC) == *(int *)(*(char **)(goal + 0x5C) + 0xEC)) {
            s = *(int *)(goal + 0x50);
            if (s != 0) {
                if (s >= 0) {
                    if (s < 6) {
                        keep = s < 4;
chk:
                        if (keep) return r;
                    } else return r;
                } else return r;
            }
            r = IMax(r, 1);
        }
    }
    return r;
}

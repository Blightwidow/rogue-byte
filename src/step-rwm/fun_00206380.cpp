#include "stepguard.h"
#include "sly2.h"
extern "C" int FIgnoreSoIntersection();
extern "C" int FIsGuardInSgs(void *, int);
extern "C" char *GoalStack_PgoalFind(void *, int);
extern "C" int IMax(int, int);
#include "so.h"
int func_00206380(STEPGUARD *guard, SO *so)
{
    int r = FIgnoreSoIntersection();
    int s;
    int keep;
    char *goal;
    if (FIsGuardInSgs(guard, 7)) {
        keep = so->FIsLocked();
        goto chk;
    }
    if (FIsGuardInSgs(guard, 0x17)) {
        goal = GoalStack_PgoalFind((char *)guard + 0x26C, 0xB1);
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

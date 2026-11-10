struct PATH { char pad0[0x58]; char *anode; };
#include "goal.h"
struct GOAL_14AD70 : GOAL {
    char pad_30[0x8];
    PATH *path;
    int inodeCur;
    int inodeTarget;
};
extern "C" void func_0014AE38(GOAL_14AD70 *, int);
void func_0014AD70(GOAL_14AD70 *goal)
{
    int inodeCur = goal->inodeCur;
    int kind;
    if (inodeCur < goal->inodeTarget) {
        int inodeNew = inodeCur + 1;
        goal->inodeCur = inodeNew;
        kind = *(int *)(goal->path->anode + inodeNew * 12);
    } else {
        kind = *(int *)(goal->path->anode + inodeCur * 12);
        goal->inodeCur = inodeCur - 1;
    }
    switch (kind) {
    case 0:
        func_0014AE38(goal, 1);
        break;
    case 1:
        func_0014AE38(goal, 2);
        break;
    }
}

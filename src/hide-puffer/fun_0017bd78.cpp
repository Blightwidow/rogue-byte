#include "sly2.h"
#include "goal.h"
struct GOAL_17BD78 : GOAL {
    int state;
    char pad_34[0xC];
    int pick;
};
extern "C" {
void func_001EEF98(GOAL_17BD78 *);
int func_00209098(void *);
void func_0017B9C0(GOAL_17BD78 *);
void func_0017B8B0(GOAL_17BD78 *, int);
int func_001EF0A8(GOAL_17BD78 *);
int FGoalNoticeDone(GOAL_17BD78 *);
}
void func_0017BD78(GOAL_17BD78 *pgoal)
{
    func_001EEF98(pgoal);
    int fCan = func_00209098(((void *)pgoal->pstep));
    func_0017B9C0(pgoal);
    while (func_001EF0A8(pgoal) == 0) {
        int nState = pgoal->state;
        switch (nState) {
        case 0:
            if (fCan != 0)
                func_0017B8B0(pgoal, 2);
            else if (pgoal->pick != 0)
                func_0017B8B0(pgoal, 1);
            break;
        case 1:
            if (fCan != 0)
                func_0017B8B0(pgoal, 2);
            else if (pgoal->pick != 0) {
                if (pgoal->pick != ((GOAL_17BD78 *)pgoal->pgoalChild)->state) {
                    func_0017B8B0(pgoal, -1);
                    func_0017B8B0(pgoal, 1);
                } else if (FGoalNoticeDone(((GOAL_17BD78 *)pgoal->pgoalChild)) != 0)
                    func_0017B8B0(pgoal, 0);
            } else
                func_0017B8B0(pgoal, 0);
            break;
        case 2:
            if (fCan == 0)
                func_0017B8B0(pgoal, 0);
            break;
        }
        if (nState == pgoal->state)
            break;
    }
}

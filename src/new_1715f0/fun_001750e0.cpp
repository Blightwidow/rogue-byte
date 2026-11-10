// SPDX-License-Identifier: GPL-3.0-or-later
struct GUARD { char pad[0x1A4]; int fLock; };
#include "goal.h"
struct GOAL_1750E0 : GOAL {
    char pad_30[0x8];
    int field_38;
    int field_3c;
    void *panim;
};
extern "C" int GoalAnim_FHandleMessage(GOAL_1750E0 *, int, int *);
extern "C" void SetXfKind(GUARD *, int, int);
extern "C" int func_00209518(void *);
int func_001750E0(GOAL_1750E0 *pgoal, int nMsg, int *pmsg)
{
    if (nMsg == 9 && pgoal->panim != 0 && func_00209518(pgoal->panim) == pmsg[0]) {
        switch (pmsg[2]) {
        case 0x29:
            ((GUARD *)pgoal->pstep)->fLock = 1;
            SetXfKind(((GUARD *)pgoal->pstep), *(int *)((char *)((GUARD *)pgoal->pstep) + 0x5C), 2);
            return 1;
        case 0x2a:
            ((GUARD *)pgoal->pstep)->fLock = 0;
            if (pgoal->field_38 == 0)
                SetXfKind(((GUARD *)pgoal->pstep), *(int *)((char *)((GUARD *)pgoal->pstep) + 0x5C), 1);
            return 1;
        }
    }
    return GoalAnim_FHandleMessage(pgoal, nMsg, pmsg);
}

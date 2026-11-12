#include "sly2.h"
#include "stepguard.h"
struct PZGRAPH { char pad[0x28]; int stamp; };
#include "goal.h"
struct GOAL_17D6C8 : GOAL {
    int state;
    char pad_34[0x4C];
    int snap0;
    int snap1;
    char pad_88[0x8];
    QW snapPos;
    float tPlan;
    int stamp;
};
struct FOLLOW { char pad[0x30]; void *crv; float s; };
struct POSREC { char pad[8]; float z; };
#include "sw.h"
struct GG { char pad[0x218]; POSREC *rec; };
extern "C" SW B_003DD490;
extern "C" float g_2dded0;
extern "C" float D_FLT_002BE758;
extern "C" float D_FLT_002BE75C;
extern "C" float func_001EEF98(GOAL_17D6C8 *);
extern "C" int func_001EF0A8(GOAL_17D6C8 *);
extern "C" int GoalFollowCrv_FAtEnd(GOAL_17D6C8 *);
extern "C" void GoalGoto_SetState(GOAL_17D6C8 *, int);
extern "C" int func_001792E8(GOAL_17D6C8 *);
extern "C" float SMaxCrv(void);
extern "C" void GetPathPosFromS(void *, float, void *, void *);
extern "C" int func_0017E570(GOAL_17D6C8 *);
extern "C" int func_0017EAE8(GOAL_17D6C8 *);
extern "C" void GoalGoto_Replan(GOAL_17D6C8 *);
extern "C" void GoalGoto_Update(GOAL_17D6C8 *goal)
{
    int previous;
    func_001EEF98(goal);
    if ((((STEPGUARD *)goal->pstep)->grf & 2) == 0)
        return;
    while (!func_001EF0A8(goal)) {
        previous = goal->state;
        switch (previous) {
        case 1:
        case 2: {
            GOAL_17D6C8 *follow = ((GOAL_17D6C8 *)goal->pgoalChild);
            if (previous == 2 && GoalFollowCrv_FAtEnd(follow)) {
                GoalGoto_SetState(goal, 3);
            } else if (D_FLT_002BE758 < g_2dded0 - goal->tPlan || goal->stamp != B_003DD490.ppzgraph->stamp) {
                GoalGoto_Replan(goal);
            } else if (func_001792E8(follow)) {
                float ahead = ((FOLLOW *)follow)->s + D_FLT_002BE75C;
                float max = SMaxCrv();
                goal->snap0 = 0;
                goal->snap1 = 0;
                GetPathPosFromS(((FOLLOW *)follow)->crv, ahead < max ? ahead : max, &goal->snapPos, 0);
                *(float *)((char *)goal + 0x98) = ((GG *)((STEPGUARD *)goal->pstep))->rec->z;
                GoalGoto_SetState(goal, 5);
            }
            break;
        }
        case 3:
            if (func_0017E570(((GOAL_17D6C8 *)goal->pgoalChild)))
                GoalGoto_Replan(goal);
            break;
        case 5:
            if (func_0017EAE8(((GOAL_17D6C8 *)goal->pgoalChild)))
                GoalGoto_Replan(goal);
            break;
        }
        if (previous == goal->state)
            break;
    }
}

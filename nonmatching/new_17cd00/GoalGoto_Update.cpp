#include "sly2.h"
struct GUARD { char pad[0xFE8]; unsigned grf; };
struct GRAPH { char pad[0x28]; int stamp; };
struct GOAL { char pad0[0x10]; GUARD *guard; char pad1[4]; GOAL *child; char pad2[0x30 - 0x1C]; int state; char pad3[0x80 - 0x34]; int snap0; int snap1; char pad4[0x90 - 0x88]; QW snapPos; float tPlan; int stamp; };
struct FOLLOW { char pad[0x30]; void *crv; float s; };
struct POSREC { char pad[8]; float z; };
struct SW { char pad[0x45CC]; GRAPH *graph; };
struct GG { char pad[0x218]; POSREC *rec; };
extern "C" SW B_003DD490;
extern "C" float g_2dded0;
extern "C" float D_FLT_002BE758;
extern "C" float D_FLT_002BE75C;
extern "C" void func_001EEF98(GOAL *);
extern "C" int func_001EF0A8(GOAL *);
extern "C" int GoalFollowCrv_FAtEnd(GOAL *);
extern "C" void GoalGoto_SetState(GOAL *, int);
extern "C" int func_001792E8(GOAL *);
extern "C" float SMaxCrv(void *);
extern "C" void GetPathPosFromS(void *, float, void *, void *);
extern "C" int func_0017E570(GOAL *);
extern "C" int func_0017EAE8(GOAL *);
extern "C" void GoalGoto_Replan(GOAL *);
extern "C" void GoalGoto_Update(GOAL *goal)
{
    int previous;
    func_001EEF98(goal);
    if ((goal->guard->grf & 2) == 0)
        return;
    while (!func_001EF0A8(goal)) {
        previous = goal->state;
        switch (previous) {
        case 1:
        case 2: {
            GOAL *follow = goal->child;
            if (previous == 2 && GoalFollowCrv_FAtEnd(follow)) {
                GoalGoto_SetState(goal, 3);
            } else if (D_FLT_002BE758 < g_2dded0 - goal->tPlan || goal->stamp != B_003DD490.graph->stamp) {
                GoalGoto_Replan(goal);
            } else if (func_001792E8(follow)) {
                float ahead = ((FOLLOW *)follow)->s + D_FLT_002BE75C;
                float max = SMaxCrv(((FOLLOW *)follow)->crv);
                goal->snap0 = 0;
                goal->snap1 = 0;
                GetPathPosFromS(((FOLLOW *)follow)->crv, ahead < max ? ahead : max, &goal->snapPos, 0);
                *(float *)((char *)goal + 0x98) = ((GG *)goal->guard)->rec->z;
                GoalGoto_SetState(goal, 5);
            }
            break;
        }
        case 3:
            if (func_0017E570(goal->child))
                GoalGoto_Replan(goal);
            break;
        case 5:
            if (func_0017EAE8(goal->child))
                GoalGoto_Replan(goal);
            break;
        }
        if (previous == goal->state)
            break;
    }
}

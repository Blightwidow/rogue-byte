struct ROUTE { char pad0[0x120]; int mode; char pad1[0x128 - 0x124]; int pathzone; };
struct LINK { char pad[0x10]; int zone; };
struct PHYS { char pad[0xDC]; LINK *plink; };
struct GUARD { char pad[0xE8]; PHYS *pphys; };
#include "goal.h"
struct GOAL_17E458 : GOAL {
    ROUTE *proute;
    char pad_34[0x4];
    int state;
    char pad_3C[0x4];
    float tTimeout;
};
extern "C" {
void func_001EEF98();
int func_0017E570(GOAL_17E458 *);
int func_0017EAE8(void *);
int func_0017E5F0(GOAL_17E458 *);
void func_0017E580(GOAL_17E458 *);
void func_0017E6B0(GOAL_17E458 *, int);
int FGoalAnimDone(void *, ROUTE *);
int GoalFollowCrv_FAtEnd(void *, ROUTE *);
}
extern float g_2dded0;
extern "C" void func_0017E458(GOAL_17E458 *pgoal)
{
    ROUTE *proute;
    PHYS *pphys;
    LINK *plink;
    int zone;
    func_001EEF98();
    if (func_0017E570(pgoal))
        return;
    switch (pgoal->state) {
    case 1:
        if (func_0017EAE8(((void *)pgoal->pgoalChild)) == 0)
            break;
        goto next;
    case 0: {
        proute = pgoal->proute;
        switch (proute->mode) {
        case 1:
            if (FGoalAnimDone(((void *)pgoal->pgoalChild), proute)) {
                if (func_0017E5F0(pgoal)) {
                next:
                    func_0017E580(pgoal);
                    return;
                }
                goto enter;
            }
            break;
        case 0: {
            if (pgoal->tTimeout < g_2dded0) {
            enter:
                func_0017E6B0(pgoal, 1);
                return;
            }
            pphys = ((GUARD *)pgoal->pstep)->pphys;
            plink = 0;
            if (pphys)
                plink = pphys->plink;
            zone = 0;
            if (plink)
                zone = plink->zone;
            if (zone == proute->pathzone) {
                if (GoalFollowCrv_FAtEnd(((void *)pgoal->pgoalChild), proute))
                    func_0017E580(pgoal);
            }
            break;
        }
        }
        break;
    }
    }
}

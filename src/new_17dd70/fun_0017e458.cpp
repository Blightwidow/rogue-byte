struct ROUTE { char pad0[0x120]; int mode; char pad1[0x128 - 0x124]; int pathzone; };
struct LINK { char pad[0x10]; int zone; };
struct PHYS { char pad[0xDC]; LINK *plink; };
struct GUARD { char pad[0xE8]; PHYS *pphys; };
struct GOAL { char pad0[0x10]; GUARD *pguard; char pad1[0x18 - 0x14]; void *pchild; char pad2[0x30 - 0x1C]; ROUTE *proute; char pad3[0x38 - 0x34]; int state; char pad4[0x40 - 0x3C]; float tTimeout; };
extern "C" {
void func_001EEF98();
int func_0017E570(GOAL *);
int func_0017EAE8(void *);
int func_0017E5F0(GOAL *);
void func_0017E580(GOAL *);
void func_0017E6B0(GOAL *, int);
int FGoalAnimDone(void *, ROUTE *);
int GoalFollowCrv_FAtEnd(void *, ROUTE *);
}
extern float g_2dded0;
extern "C" void func_0017E458(GOAL *pgoal)
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
        if (func_0017EAE8(pgoal->pchild) == 0)
            break;
        goto next;
    case 0: {
        proute = pgoal->proute;
        switch (proute->mode) {
        case 1:
            if (FGoalAnimDone(pgoal->pchild, proute)) {
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
            pphys = pgoal->pguard->pphys;
            plink = 0;
            if (pphys)
                plink = pphys->plink;
            zone = 0;
            if (plink)
                zone = plink->zone;
            if (zone == proute->pathzone) {
                if (GoalFollowCrv_FAtEnd(pgoal->pchild, proute))
                    func_0017E580(pgoal);
            }
            break;
        }
        }
        break;
    }
    }
}

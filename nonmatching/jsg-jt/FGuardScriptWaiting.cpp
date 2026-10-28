struct CMD { int op; int pad4; float duration; };
struct ACTOR { char pad[0xF80]; int state; };
struct BEH { char pad0[0x10]; ACTOR *pactor; char pad1[0x18 - 0x14]; void *pgoal; char pad2[0x38 - 0x1C]; CMD *pcmd; float tStart; int fWaiting; char pad3[0x48 - 0x44]; float yaw; };
extern "C" {
int func_0017EE78(void *, CMD *);
int func_0017CE30(void *, CMD *);
int func_0017D188(void *, CMD *);
int GoalGoto_FArrived(void *, CMD *);
int FGoalAnimDone(void *, CMD *);
void func_00209818(void *, float);
void Goal_Pop(void *);
}
extern float g_2dded0;
extern "C" int FGuardScriptWaiting(BEH *pbeh)
{
    if (pbeh->fWaiting == 0)
        return 0;
    CMD *pcmd = pbeh->pcmd;
    switch (pcmd->op) {
    case 6:
        switch (pbeh->pactor->state) {
        case -1:
            if (func_0017EE78(pbeh->pgoal, pcmd))
                pbeh->fWaiting = 0;
            break;
        case 0:
            if (func_0017CE30(pbeh->pgoal, pcmd))
                pbeh->fWaiting = 0;
            break;
        case 1:
            if (func_0017D188(pbeh->pgoal, pcmd))
                pbeh->fWaiting = 0;
            break;
        }
        break;
    case 7:
        if (GoalGoto_FArrived(pbeh->pgoal, pcmd)) {
            pbeh->fWaiting = 0;
            func_00209818((char *)pbeh->pactor + 0xFD0, pbeh->yaw);
        }
        break;
    case 5:
        if (pcmd->duration < g_2dded0 - pbeh->tStart)
            pbeh->fWaiting = 0;
        break;
    case 13:
    case 14:
        if (FGoalAnimDone(pbeh->pgoal, pcmd))
            pbeh->fWaiting = 0;
        break;
    }
    if (pbeh->fWaiting == 0)
        Goal_Pop(&pbeh->pgoal);
    return pbeh->fWaiting;
}

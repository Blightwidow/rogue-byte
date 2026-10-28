#include "sly2.h"
struct GOAL { char pad[0x30]; int kind; };
struct GOALCMD { int kind; char pad[0x6C]; };
struct GUARD { char pad0[0x26C]; char goalstack[0x70]; char scratch[0xC]; int variant; };
extern "C" GOAL *GoalStack_PgoalFind(void *, int);
extern "C" void GoalBrain_SetCommand(GOAL *, GOALCMD *);

void func_0020A540(GUARD *pguard, int variant)
{
    if (pguard->variant == variant)
        return;
    pguard->variant = variant;
    memset(pguard->scratch, 0, 0xC);
    GOAL *pgoal = GoalStack_PgoalFind(pguard->goalstack, 0x9C);
    if (pgoal != 0) {
        int kind = pgoal->kind;
        if (kind == 1) {
            GOALCMD cmd;
            memset(&cmd, 0, sizeof(cmd));
            cmd.kind = -1;
            GoalBrain_SetCommand(pgoal, &cmd);
            memset(pguard->scratch, 0, 0xC);
            cmd.kind = kind;
            GoalBrain_SetCommand(pgoal, &cmd);
        }
    }
}

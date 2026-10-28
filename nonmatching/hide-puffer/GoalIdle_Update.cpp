#include "sly2.h"
extern "C" {
void func_001EEF98(char *);
int func_00209098(char *);
int func_001EF0A8(char *);
void GoalIdle_SetState(char *, int);
int FGuardScriptDone(char *);
extern float g_2dded0;
}

extern "C" void GoalIdle_Update(char *pgoal)
{
    func_001EEF98(pgoal);
    int fCanAlert = func_00209098(*(char **)(pgoal + 0x10));
    for (;;) {
        if (func_001EF0A8(pgoal) != 0)
            return;
        int nState = *(int *)(pgoal + 0x38);
        if (nState == 1) {
            if (fCanAlert != 0) {
                GoalIdle_SetState(pgoal, 3);
            } else if (*(float *)(pgoal + 0x34) < g_2dded0) {
                GoalIdle_SetState(pgoal, 0);
            }
        } else if (nState < 2) {
            if (nState == 0) {
                if (fCanAlert != 0) {
                    GoalIdle_SetState(pgoal, 3);
                } else if (*(float *)(pgoal + 0x30) < g_2dded0) {
                    GoalIdle_SetState(pgoal, 1);
                } else if (FGuardScriptDone(*(char **)(pgoal + 0x18)) != 0) {
                    *(int *)(pgoal + 0x40) = 0;
                    GoalIdle_SetState(pgoal, 2);
                }
            }
        } else if (nState == 2) {
            if (fCanAlert != 0)
                GoalIdle_SetState(pgoal, 3);
        } else if (nState == 3) {
            if (fCanAlert == 0) {
                if (*(char **)(pgoal + 0x40) != 0)
                    GoalIdle_SetState(pgoal, 1);
                else
                    GoalIdle_SetState(pgoal, 2);
            }
        }
        if (*(int *)(pgoal + 0x38) == nState)
            return;
    }
}

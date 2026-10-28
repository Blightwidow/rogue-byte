#include "sly2.h"
extern "C" void GoalAnimLeap_SetState(void *, int);
extern "C" void func_00174B28(void *);
void GoalAnimLeap_Deactivate(void *pgoal)
{
    GoalAnimLeap_SetState(pgoal, -1);
    func_00174B28(pgoal);
}

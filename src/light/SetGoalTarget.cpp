typedef int QW __attribute__((mode(TI)));
extern "C" void GoalGoto_Replan(char *);
void SetGoalTarget(char *pgoal, QW *pvecTarget)
{
    *(QW *)(pgoal + 0x40) = pvecTarget[0];
    *(QW *)(pgoal + 0x50) = pvecTarget[1];
    *(float *)(pgoal + 0xA0) = -3.402823466e+38f;
    GoalGoto_Replan(pgoal);
}

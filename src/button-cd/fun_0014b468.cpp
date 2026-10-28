#include "sly2.h"
extern "C" {
void *func_00205458(void *, int);
void GoalBrain_SetCommand(void *, int *);
}
void func_0014B468(void *guard, int object)
{
    int message[0x1c];
    memset(message, 0, 0x70);
    void *behavior = func_00205458(guard, 0x9C);
    if (object) {
        message[4] = object;
        message[0] = 0xE;
        GoalBrain_SetCommand(behavior, message);
    } else {
        if (func_00205458(guard, 0xB6)) {
            message[0] = 1;
            GoalBrain_SetCommand(behavior, message);
        }
    }
}

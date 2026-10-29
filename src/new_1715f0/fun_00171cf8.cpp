// SPDX-License-Identifier: GPL-3.0-or-later
typedef int s32;

extern "C" {
void *memset(void *dest, int value, unsigned int size);
void *func_00205458(void *guard, int id);
void GoalBrain_SetCommand(void *behavior, int *message);

void func_00171CF8(void *arg0, s32 arg1) {
    int message[0x1c];
    void *behavior;

    behavior = func_00205458(arg0, 0x9C);
    if (behavior != 0) {
        memset(message, 0, 0x70);
        message[0] = 5;
        message[4] = arg1;
        GoalBrain_SetCommand(behavior, message);
    }
}
}

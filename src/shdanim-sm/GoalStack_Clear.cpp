/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
extern "C" void Goal_Pop(int *popped, void *stack);
extern "C" void GoalStack_Clear(char *self, void *stack) {
    if (*(int *)(self + 0x4) > 0) {
        int popped = *(int *)(self + 0x8);
        Goal_Pop(&popped, stack);
    }
    *(int *)(self + 0x4) = 0;
}

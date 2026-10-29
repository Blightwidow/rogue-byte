/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
extern "C" int GoalGoto_FArrived(int goal);
extern "C" int func_0017EEB8(void *self);
extern "C" int func_0017EE78(char *self) {
    if (!func_0017EEB8(self)) {
        return 0;
    }
    return GoalGoto_FArrived(*(int *)(self + 0x18));
}

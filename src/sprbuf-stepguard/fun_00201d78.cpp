// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"

extern "C" void func_00201D78(char *arg0, int arg1)
{
    char *tail = arg0 + 0x10;
    float oldField10;
    float oldField14;
    *(float *)(arg0 + 0x10) = 0.0f;
    *(int *)(arg0 + 0xA8) = arg1;
    ((int *)tail)[1] = 0;
    ((int *)tail)[2] = 0;
    oldField10 = *(float *)(arg0 + 0x10);
    oldField14 = *(float *)(tail + 4);
    *(float *)(arg0 + 0x10) = (oldField10 * 320.0f) + 320.0f;
    *(float *)(tail + 4) = 246.40001f;
    *(float *)(tail + 8) = oldField14;
    *(int *)arg0 = -1;
}

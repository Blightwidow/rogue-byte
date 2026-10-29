// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"

typedef int s128 __attribute__((mode(TI)));

extern "C" void func_00174B28(char *);
extern "C" void ReplaceSwHitFx(char *, int, s128, int, int);
extern "C" char B_003DD490[];
extern "C" s128 g_2a2dd0;

extern "C" void GoalHit_Deactivate(char *goalHit)
{
    func_00174B28(goalHit);
    ReplaceSwHitFx(B_003DD490, -1, g_2a2dd0, 0, *(int *)(goalHit + 0x10) + 0x35C);
}

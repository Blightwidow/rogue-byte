// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct LO { char pad[0x35C]; char *p35C; };
struct GOAL { char pad[0x10]; LO *lo; char pad2[0xB0 - 0x14]; float t0; float t1; };
struct CMOBJ;
extern float g_2dded0;
extern CMOBJ B_002DDF40;
void GoalAnim_Update(GOAL *);
QW PosLoWorld(LO *);
void JoltCm(CMOBJ *, int);
void func_001F7A68(LO *, int);
void GoalHit_Update(GOAL *goal)
{
    GoalAnim_Update(goal);
    LO *lo = goal->lo;
    char *target = lo->p35C;
    *(QW *)(target + 0x20) = PosLoWorld(lo);
    float limit = g_2dded0 + 0.0001f;
    if (goal->t0 < limit) {
        goal->t0 = 3.402823466e+38f;
        JoltCm(&B_002DDF40, 0);
    }
    if (goal->t1 < limit) {
        goal->t1 = 3.402823466e+38f;
        func_001F7A68(goal->lo, 2);
    }
}

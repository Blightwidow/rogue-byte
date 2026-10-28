// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct VT { char pad[0x40]; short delta; short index; void (*fn)(void *); };
struct OBJ { char pad[0xC]; VT *vt; };
struct GUARD { char pad[0xF64 - 0]; void *alarm; char pad2[0x84]; OBJ *fx; };
struct GOAL { char pad[0x10]; GUARD *guard; char pad2[0x2C]; int *entry; char pad3[0xC]; void *hitter; char pad4[8]; int index; };
struct CAM;
extern CAM B_002DEB30;
extern "C" int func_001F78A0(int);
extern "C" void GoalHit_Activate(GOAL *);
extern "C" void bevy_camera_follow_activity(CAM *, int, GUARD *);
extern "C" void func_00154038(void *, void *, int);
void func_00179780(GOAL *goal)
{
    int index = func_001F78A0(goal->index);
    int *entry = (int *)((char *)goal->guard + ((index << 4) + 0x8D0));
    goal->entry = entry;
    if (*entry == -1)
        goal->entry = 0;
    GoalHit_Activate(goal);
    bevy_camera_follow_activity(&B_002DEB30, 0x15, goal->guard);
    func_00154038(goal->guard->alarm, goal->hitter, 2);
    OBJ *fx = goal->guard->fx;
    if (fx)
        fx->vt->fn((char *)fx + fx->vt->delta);
}

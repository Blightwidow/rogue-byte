// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct VT { char pad[0x40]; short delta; short index; void (*fn)(void *); };
struct OBJ { char pad[0xC]; VT *vt; };
#include "stepguard.h"
#include "goal.h"
struct GOAL_179780 : GOAL {
    char pad_30[0x10];
    int *entry;
    char pad_44[0xC];
    void *hitter;
    char pad_54[0x8];
    int index;
};
struct CAM;
extern CAM B_002DEB30;
extern "C" int func_001F78A0(int);
extern "C" void GoalHit_Activate(GOAL_179780 *);
extern "C" void bevy_camera_follow_activity(CAM *, int, STEPGUARD *);
extern "C" void func_00154038(void *, void *, int);
void func_00179780(GOAL_179780 *goal)
{
    int index = func_001F78A0(goal->index);
    int *entry = (int *)((char *)((STEPGUARD *)goal->pstep) + ((index << 4) + 0x8D0));
    goal->entry = entry;
    if (*entry == -1)
        goal->entry = 0;
    GoalHit_Activate(goal);
    bevy_camera_follow_activity(&B_002DEB30, 0x15, ((STEPGUARD *)goal->pstep));
    func_00154038(((STEPGUARD *)goal->pstep)->psensor, goal->hitter, 2);
    OBJ *fx = (OBJ *)((STEPGUARD *)goal->pstep)->field_0xFEC;
    if (fx)
        fx->vt->fn((char *)fx + fx->vt->delta);
}

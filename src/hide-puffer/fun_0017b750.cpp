// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct VT { char pad[0x40]; short delta; short index; void (*fn)(void *); };
struct GUARD { char pad[0xF60]; int flag; };
struct GOALANIM { char pad[0xC]; VT *vt; char pad2[0x28]; int field38; int field3C; };
#include "goal.h"
struct GOAL_17B750 : GOAL {
    int state;
    float time;
    int field38;
};
extern float g_2dded0;
extern "C" void Goal_Pop(void *);
extern "C" GOALANIM *func_00205438(GUARD *, int);
void func_0017B750(GOAL_17B750 *goal, int state)
{
    if (state == goal->state)
        return;
    Goal_Pop((char *)goal + 0x18);
    if (goal->state == 0) {
        ((GUARD *)goal->pstep)->flag = 0;
        goal->state = state;
    } else
        goal->state = state;
    goal->time = g_2dded0;
    if (state == 0) {
        GOALANIM *anim = func_00205438(((GUARD *)goal->pstep), 0x9D);
        VT *vt = anim->vt;
        anim->field3C = 0x11;
        anim->field38 = goal->field38;
        vt->fn((char *)anim + vt->delta);
        ((GUARD *)goal->pstep)->flag = 1;
    }
}

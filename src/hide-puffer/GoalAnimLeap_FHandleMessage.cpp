#include "sly2.h"
#include "goal.h"
struct GOAL_17AF30 : GOAL {
    char pad_30[0x10];
    char *animref;
    char pad_44[0xC];
    int state;
    char pad_54[0x4];
    int hits;
};
struct VT { char pad[0x198]; short delta; short index; void (*fn)(void *, void *); };
struct OBJ { char pad[0xC]; VT *vptr; };
extern "C" char B_003DD490;
extern "C" int D_002BE6D0[];
extern "C" int D_002BE6E8[];
extern "C" int GoalAnim_FHandleMessage(GOAL_17AF30 *, int, int *);
extern "C" void *func_00209518(void *);
extern "C" int FDoneAnimref(void *);
extern "C" void StopAnimref(void *);
extern "C" void StartAnimref(void *, void *, unsigned, float);
extern "C" float *PeaFindAsegLabel(void *, int);
extern "C" void SeekAsega(void *, int, float, float);
extern "C" void GoalAnimLeap_SetState(GOAL_17AF30 *, int);
extern "C" OBJ *PloFindSwObject_thunk(void *, int, int, int);
extern "C" void PhitfxSpawn(void *, QW, void *);
extern "C" QW PosLoWorld(void *);
// StartAnimref takes (void *, void *, unsigned, float) with the float last, as in GoalAnim_SetState; the draft put the float first, which
// moved the mtc1 and a lw before the other argument loads (score 4). No temporaries: the arguments are computed inline.
extern "C" int GoalAnimLeap_FHandleMessage(GOAL_17AF30 *goal, int message, int *data)
{
    int hits, index, total;
    float seek;
    OBJ *effect;
    if (GoalAnim_FHandleMessage(goal, message, data))
        return 1;
    switch (message) {
    case 9:
        if (goal->animref == 0)
            return 0;
        if (func_00209518(goal->animref) != (void *)data[0])
            return 0;
        if (data[2] == 0x3D) {
            goal->hits = 0;
            goto zero;
        }
        return 0;
    case 0xC:
        break;
    default:
        return 0;
    }
    if (data[3] != 0x200000)
        return 0;
    if ((data[0x11] & 8) == 0)
        return 0;
    if (goal->state == 0)
        return 0;
    if (FDoneAnimref(goal->animref)) {
        StopAnimref(goal->animref);
        StartAnimref(goal->animref, ((char *)goal->pstep), *(unsigned *)(goal->animref + 0xC) | 1, 0.0f);
    }
    hits = goal->hits + 1;
    goal->hits = hits;
    seek = 0.0f;
    index = 4;
    if (hits < 4)
        index = hits;
    for (; index > 0; index--) {
        float *label = PeaFindAsegLabel(*(void **)(goal->animref + 4), D_002BE6D0[index]);
        if (label) {
            seek = *label;
            break;
        }
    }
    SeekAsega(*(void **)(goal->animref + 8), 0, seek, 1.0f);
    GoalAnimLeap_SetState(goal, 0);
    effect = PloFindSwObject_thunk(&B_003DD490, 5, D_002BE6E8[index], 0);
    if (effect) {
        int packet[16];
        memset(packet, 0, 0x40);
        packet[0] = 5;
        *(QW *)((char *)packet + 0x20) = PosLoWorld(((char *)goal->pstep));
        effect->vptr->fn((char *)effect + effect->vptr->delta, packet);
    }
    total = *(int *)(((char *)goal->pstep) + 0x33C) + data[4];
    *(int *)(((char *)goal->pstep) + 0x33C) = total > 4 ? total : 5;
    PhitfxSpawn(*(void **)(&B_003DD490 + 0x4028), PosLoWorld(((char *)goal->pstep)), ((char *)goal->pstep));
    return 1;
zero:
    return 0;
}

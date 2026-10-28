#include "sly2.h"
extern "C" float D_FLT_002BE62C;
extern "C" float D_FLT_002BE624;
extern "C" float D_FLT_002BE628;
extern "C" void func_001EEF70(void*);
extern "C" QW PosLoWorld(void*);
struct Goal;
struct GoalVt { char pad[0x78]; short delta; short idx; void (*setState)(void*, int); };
struct Goal {
    char pad0[0xC]; GoalVt* vt; void* guard; char pad1[0x64 - 0x14];
    float radiusEnd, tolMove, tolAlt; char pad2[0x80 - 0x70]; QW posPrev;
};
extern "C" void GoalFollowCrv_Activate(Goal* goal)
{
    func_001EEF70(goal);
    goal->posPrev = PosLoWorld(goal->guard);
    float radius = goal->radiusEnd;
    radius = (radius > D_FLT_002BE62C) ? radius : D_FLT_002BE62C;
    float quarter = radius * 0.25f;
    goal->radiusEnd = radius;
    goal->tolMove = (quarter < D_FLT_002BE624) ? quarter : D_FLT_002BE624;
    goal->tolAlt = (radius < D_FLT_002BE628) ? radius : D_FLT_002BE628;
    goal->vt->setState((char*)goal + goal->vt->delta, 0);
}

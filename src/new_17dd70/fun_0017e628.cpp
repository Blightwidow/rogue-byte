#include "sly2.h"
extern "C" void* func_00205438(void*, int);
extern "C" QW PosLoWorld(void*);
extern "C" QW func_001C1EC0(void*, QW);
struct MoveGoalVt { char pad[0x40]; short delta; short idx; void (*activate)(void*); };
struct MoveGoal { char pad0[0xC]; MoveGoalVt* vt; char pad1[0x50 - 0x10]; QW pos; char pad2[0x68 - 0x60]; int mode; };
struct Route { char pad0[0x10]; void* guard; char pad1[0x30 - 0x14]; char* waypoints; int index; };
extern "C" void func_0017E628(Route* route)
{
    MoveGoal* move = (MoveGoal*)func_00205438(route->guard, 0xAC);
    move->mode = 1;
    char* waypoint = route->waypoints + (route->index * 0x20 + 0x60);
    move->pos = func_001C1EC0(waypoint, PosLoWorld(route->guard));
    move->vt->activate((char*)move + move->vt->delta);
}

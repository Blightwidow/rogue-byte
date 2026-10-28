#include "sly2.h"
struct Guard { char pad0[0x58]; void *xfLinear; void *xfAngular; char pad1[0xF64 - 0x60]; int sensors; char pad2[0xFCC - 0xF68]; int aim; };
struct Goal { char pad0[0x10]; Guard *guard; char pad1[0x38 - 0x14]; int aim; };
extern "C" QW g_2a2dd0;
extern "C" void func_00174950(Goal *);
extern "C" int FIsGuardInSgs(Guard *, int);
extern "C" void func_0020AB68(Guard *, int, int, QW);
extern "C" void ResetSensorStates(int);
extern "C" void SetXfKind(Guard *, void *, int);
void func_00174FF8(Goal *goal)
{
    func_00174950(goal);
    if (FIsGuardInSgs(goal->guard, 1)) {
        func_0020AB68(goal->guard, 0, 0, g_2a2dd0);
        ResetSensorStates(goal->guard->sensors);
        int aim = goal->guard->aim;
        if (aim != 0) goal->aim = aim;
    }
    SetXfKind(goal->guard, goal->guard->xfLinear, 1);
    if (goal->aim == 0) {
        SetXfKind(goal->guard, goal->guard->xfAngular, 1);
    }
}

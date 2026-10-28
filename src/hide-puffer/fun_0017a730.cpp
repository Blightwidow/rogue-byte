#include "sly2.h"
extern "C" void func_001EEF70(void*);
extern "C" void func_0017A8C8(void*, int);
extern "C" void ClearGuardPathMode(void*);
extern "C" void func_0020AB68(void*, int, int, QW);
extern "C" void DiscardSoXps(void*);
extern "C" void func_001EEFC0(void*);
extern "C" void ResetSensorStates(void*);
extern "C" void func_00154038(void*, void*, int);
extern "C" QW g_2a2dd0;
struct Guard { char pad[0xF64]; void* alarm; };
struct Goal { char pad0[0x10]; Guard* guard; char pad1[0x3C - 0x14]; void* hitter; };
extern "C" void func_0017A730(Goal* goal)
{
    func_001EEF70(goal);
    func_0017A8C8(goal, 0);
    ClearGuardPathMode(goal->guard);
    func_0020AB68(goal->guard, 0, 0, g_2a2dd0);
    DiscardSoXps(goal->guard);
    func_001EEFC0(goal);
    ResetSensorStates(goal->guard->alarm);
    if (goal->hitter) {
        func_00154038(goal->guard->alarm, goal->hitter, 2);
    }
}

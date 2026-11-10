#include "sly2.h"
struct Guard { char pad0[0x58]; void *xfLinear; void *xfAngular; char pad1[0xF64 - 0x60]; int sensors; char pad2[0xFCC - 0xF68]; int aim; };
#include "goal.h"
struct GOAL_174FF8 : GOAL {
    char pad_30[0x8];
    int aim;
};
extern "C" QW g_2a2dd0;
extern "C" void func_00174950(GOAL_174FF8 *);
extern "C" int FIsGuardInSgs(Guard *, int);
extern "C" void func_0020AB68(Guard *, int, int, QW);
extern "C" void ResetSensorStates(int);
extern "C" void SetXfKind(Guard *, void *, int);
void func_00174FF8(GOAL_174FF8 *goal)
{
    func_00174950(goal);
    if (FIsGuardInSgs(((Guard *)goal->pstep), 1)) {
        func_0020AB68(((Guard *)goal->pstep), 0, 0, g_2a2dd0);
        ResetSensorStates(((Guard *)goal->pstep)->sensors);
        int aim = ((Guard *)goal->pstep)->aim;
        if (aim != 0) goal->aim = aim;
    }
    SetXfKind(((Guard *)goal->pstep), ((Guard *)goal->pstep)->xfLinear, 1);
    if (goal->aim == 0) {
        SetXfKind(((Guard *)goal->pstep), ((Guard *)goal->pstep)->xfAngular, 1);
    }
}

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
#include "stepguard.h"
#include "goal.h"
struct GOAL_17A730 : GOAL {
    char pad_30[0xC];
    void* hitter;
};
extern "C" void func_0017A730(GOAL_17A730* goal)
{
    func_001EEF70(goal);
    func_0017A8C8(goal, 0);
    ClearGuardPathMode(((STEPGUARD*)goal->pstep));
    func_0020AB68(((STEPGUARD*)goal->pstep), 0, 0, g_2a2dd0);
    DiscardSoXps(((STEPGUARD*)goal->pstep));
    func_001EEFC0(goal);
    ResetSensorStates(((STEPGUARD*)goal->pstep)->psensor);
    if (goal->hitter) {
        func_00154038(((STEPGUARD*)goal->pstep)->psensor, goal->hitter, 2);
    }
}

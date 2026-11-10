#include "types.h"
#include "stepguard.h"
extern "C" void UpdateStep(STEPGUARD *);
extern "C" void UpdateGuardModeTimeout(STEPGUARD *);
extern "C" void UpdateGuardSensor(STEPGUARD *);
extern "C" int FDoneAnimref(void *);
extern "C" void func_0020AB68(STEPGUARD *, int, int, QW);
extern "C" void func_0020ACC0(STEPGUARD *);
extern "C" void func_001F1CF8(STEPGUARD *);
extern "C" void UpdateFallCheck(void *);
extern "C" void UpdateGuardDamage(void *);
extern "C" void GoalStack_Update(void *);
extern "C" void func_002097E0(void *);
extern "C" int FAsegaGone(void *);
extern "C" void ReleaseAsegaHandle(void *);
extern "C" QW g_2a2dd0;

#define F(type, off) (*(type *)((char *)guard + (off)))

void UpdateGuard(STEPGUARD *guard)
{
    UpdateStep(guard);
    if (((guard->grfo >> 60) & 1) == 0 || F(int, 0xFBC) == 0xE)
        return;
    UpdateGuardModeTimeout(guard);
    UpdateGuardSensor(guard);
    if (F(void *, 0xF00) != 0 && FDoneAnimref(*(void **)((char *)F(void *, 0xF00) + 0xC0)))
        func_0020AB68(guard, 0, 0, g_2a2dd0);
    if (F(int, 0xF0C) != 0)
        func_0020ACC0(guard);
    if (F(int, 0x48C) != 0)
        func_001F1CF8(guard);
    UpdateFallCheck(F(void *, 0x498));
    UpdateGuardDamage(F(void *, 0x49C));
    GoalStack_Update((char *)guard + 0x26C);
    func_002097E0((char *)guard + 0xFD0);
    if (F(void *, 0x34C) != 0 && FAsegaGone(F(void *, 0x34C)))
        ReleaseAsegaHandle((char *)guard + 0x34C);
    if (F(int, 0x4A4) != 0 && F(int, 0x208) != 0)
        F(QW, 0x4B0) = *F(QW *, 0x218);
}

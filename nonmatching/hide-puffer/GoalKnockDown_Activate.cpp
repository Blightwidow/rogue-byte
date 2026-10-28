#include "sly2.h"
struct GOAL { char pad0[0x10]; char *guard; char pad1[0x30 - 0x14]; int unk30[4]; char *anim; char pad2[0x50 - 0x44]; char *hitter; char pad3[0x5C - 0x54]; int type; };
extern "C" char B_003DD490;
extern "C" char B_002DEB30;
extern "C" char B_002DE578;
extern "C" int func_001F78A0(int);
extern "C" void GoalHit_Activate(GOAL *);
extern "C" void *PpoSwFocusBase(void *);
extern "C" void bevy_camera_follow_activity(void *, int, void *);
extern "C" QW ConvertAloPos(void *, int, QW);
extern "C" void OnDifficultyBreak(void *, QW, int, int, void *);
extern "C" void RecalcSwOxfFilterForObject(void *, void *);
extern "C" void ResetSensorStates(void *);
extern "C" void GoalKnockDown_Activate(GOAL *goal)
{
    int index = func_001F78A0(goal->type);
    int *entry = (int *)(goal->guard + (index * 16 + 0xC10));
    *(int **)((char *)goal + 0x40) = entry;
    if (*entry == -1)
        *(int *)((char *)goal + 0x40) = 0;
    GoalHit_Activate(goal);
    char *guard = goal->guard;
    if (*(int *)(guard + 0x330) == 0) {
        *(int *)(guard + 0x330) = 1;
        char *focus = (char *)PpoSwFocusBase(&B_003DD490);
        if (goal->hitter == focus)
            bevy_camera_follow_activity(&B_002DEB30, 0x18, goal->guard);
        else
            bevy_camera_follow_activity(&B_002DEB30, 0x17, goal->guard);
        char *current = goal->guard;
        int coins = *(int *)(current + 0x3D8);
        if (coins < 0) {
            int lootIndex = *(int *)(current + 0x488);
            coins = 0;
            for (; lootIndex < *(int *)(current + 0x484); lootIndex++) {
                int *loot = (int *)(current + 0x404 + lootIndex * 16);
                if (loot[0] == 0x2B3)
                    coins += loot[3];
            }
            coins = (coins + 1) / 2;
        }
        QW pos = ConvertAloPos(goal->guard, 0, *(QW *)(current + 0x3E0));
        OnDifficultyBreak(&B_002DE578, pos, coins, *(int *)(goal->guard + 0x3F0), goal->guard);
        RecalcSwOxfFilterForObject(&B_003DD490, goal->guard);
        ResetSensorStates(*(void **)(goal->guard + 0xF64));
    }
}

#include "sly2.h"
struct LOOTDEF { char pad[0xC]; int timed; };
struct LOOT { char pad[0x158]; LOOTDEF *pdef; char pad2[4]; int thief; char pad3[0x20]; int state; float t; };
extern "C" void UpdateSo(LOOT *, float);
extern "C" void ReturnLootToGuard(LOOT *, int);
extern "C" void DropJtLoot(int);
extern float g_2dded0;
extern float B_003E1BFC;
void UpdatePickLoot(LOOT *loot, float dt)
{
    UpdateSo(loot, dt);
    int state = loot->state;
    if (state != 4) {
        if (state == 5) {
            if (5.0f <= g_2dded0 - loot->t)
                ReturnLootToGuard(loot, 0);
        }
    } else {
        if (loot->pdef->timed != 0 && g_2dded0 >= B_003E1BFC)
            DropJtLoot(loot->thief);
    }
}

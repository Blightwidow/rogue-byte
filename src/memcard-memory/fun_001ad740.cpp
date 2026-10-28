#include "sly2.h"
struct ITEM { int unk0; int unk4; int islot; };
struct SLOTENT { int unk0; int unk4; void *pblot; char pad[0x14 - 0xC]; int selected; char pad2[0x1C - 0x18]; };
struct SLOTSCREEN { char pad[0x24]; int icur; };
extern int g_2e6594;
extern SLOTSCREEN B_003D9ED0;
extern SLOTENT B_003D9EDC[];
extern "C" void PauseMenu_Pop(SLOTSCREEN *);
extern "C" int func_001B0108(SLOTSCREEN *);
extern "C" void func_00213B00(void *, int);
void func_001AD740(ITEM *pitem)
{
    if (g_2e6594 != 1) {
        PauseMenu_Pop(&B_003D9ED0);
        return;
    }
    if (func_001B0108(&B_003D9ED0) != 0) {
        int islot = pitem->islot;
        SLOTENT *pent = &B_003D9EDC[B_003D9ED0.icur];
        if (pent->selected == islot)
            func_00213B00(pent->pblot, islot + 0x5C8);
        else
            func_00213B00(pent->pblot, islot + 0x5C5);
    }
}

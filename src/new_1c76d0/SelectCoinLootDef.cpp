#include "sly2.h"
struct LOOTDEF { int id; char pad[0x18]; int cmesh; int ameshShown[3]; };
struct COIN { char pad[0x23C]; int cloot; LOOTDEF *aloot; LOOTDEF *cur; };
extern "C" void func_001F6A68(COIN *);
extern "C" void func_001F6978(COIN *, int);
// Retail: a search loop over coin->aloot (stride 0x2C) whose fall-through stores aloot[0] to cur
// and whose hit stores the entry, then one call and a per-mesh call loop over cur->ameshShown.
// The for(;;) with both stores inside it reproduces retail's two `sw 0x244` sites and branch layout.
// All 44 instructions retail's split shows are identical; score 1 is the epilogue delay slot
// `addiu $sp,$sp,0x30` at 0x1C7B08, which the registry cuts off (size 0xB0, real size 0xB4; 0x1C7B08 is
// registered as the fragment func_001C7B08).
extern "C" void SelectCoinLootDef(COIN *coin, int id)
{
    int iloot = 0;
    for (;;) {
        if (!(iloot < coin->cloot)) {
            coin->cur = coin->aloot;
            break;
        }
        LOOTDEF *loot = &coin->aloot[iloot];
        if (id == loot->id) {
            coin->cur = loot;
            break;
        }
        iloot++;
    }
    func_001F6A68(coin);
    for (int imesh = 0; imesh < coin->cur->cmesh; imesh++)
        func_001F6978(coin, coin->cur->ameshShown[imesh]);
}

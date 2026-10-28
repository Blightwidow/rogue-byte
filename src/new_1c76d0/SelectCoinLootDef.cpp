#include "sly2.h"
struct LOOTDEF { int id; char pad[0x18]; int cmesh; int ameshShown[3]; };
struct COIN { char pad[0x23C]; int cloot; LOOTDEF *aloot; LOOTDEF *cur; };
extern "C" void func_001F6A68(COIN *);
extern "C" void func_001F6978(COIN *, int);
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

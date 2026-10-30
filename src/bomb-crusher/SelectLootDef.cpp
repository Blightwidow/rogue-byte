// SPDX-License-Identifier: GPL-3.0-or-later
struct LOOTDEF_13C490 { int id; char pad[0x28]; };
struct LOOT_13C490 { char pad[0x150]; int clootdef; LOOTDEF_13C490 *alootdef; LOOTDEF_13C490 *plootdefSel; };
extern "C" void SelectLootDef(LOOT_13C490 *ploot, int id)
{
    for (int i = 0; i < ploot->clootdef; i++) {
        if (id == ploot->alootdef[i].id) {
            ploot->plootdefSel = &ploot->alootdef[i];
            return;
        }
    }
    ploot->plootdefSel = ploot->alootdef;
}

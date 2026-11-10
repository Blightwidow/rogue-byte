#include "jt.h"
/* The loot object GiveJtLoot leases: its thief at 0x160, as Crfodb_OnGrab reads it. */
struct LOOT { char pad0[0x160]; JT *pjt; };
extern "C" int LootId(LOOT *);
extern "C" void DropJtLoot(JT *);
extern "C" LO *PloLeaseCloneObject(void *, int);
extern "C" void SelectLootDef(LOOT *, int);
extern "C" void SetLootState(LOOT *, int);
extern "C" void *B_003E1AC8;
void GiveJtLoot(JT *pjt, int id)
{
    LOOT *held = pjt->plootHeld;
    if (held == 0 || LootId(held) != id) {
        DropJtLoot(pjt);
        if (id != -1) {
            if (B_003E1AC8 != 0) {
                LOOT *ploot = (LOOT *)PloLeaseCloneObject(B_003E1AC8, 1);
                SelectLootDef(ploot, id);
                ploot->pjt = pjt;
                SetLootState(ploot, 6);
                SetLootState(ploot, 4);
            }
        }
    }
}

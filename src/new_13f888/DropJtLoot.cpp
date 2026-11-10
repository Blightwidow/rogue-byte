#include "jt.h"
extern "C" {
void SetLootState(LOOT *, int);
void UpdateJtLootSave(JT *, int, int);

void DropJtLoot(JT *pjt) {
    if (pjt->plootHeld != 0) {
        UpdateJtLootSave(pjt, 2, 0);
        SetLootState(pjt->plootHeld, 5);
    }
}

}

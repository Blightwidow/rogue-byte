#include "jt.h"
extern "C" {
void SetLootState(LOOT *, int);
void UpdateJtLootSave(JT *, int, int);

void DeliverJtLoot(JT *pjt) {
    if (pjt->plootHeld != 0) {
        UpdateJtLootSave(pjt, 1, 0);
        SetLootState(pjt->plootHeld, 0);
    }
}

}

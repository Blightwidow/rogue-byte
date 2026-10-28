#include "m2c_macros.h"

M2C_UNK SetLootState(s32, M2C_UNK);                 /* extern */
M2C_UNK UpdateJtLootSave(M2C_UNK, M2C_UNK);         /* extern */

void DeliverJtLoot(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x11A8) != 0) {
        UpdateJtLootSave(1, 0);
        SetLootState(M2C_FIELD(arg0, s32 *, 0x11A8), 0);
    }
}

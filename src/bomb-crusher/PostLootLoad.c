#include "m2c_macros.h"

M2C_UNK PostSoLoad();                               /* extern */
M2C_UNK SetLootState(s32, M2C_UNK);                 /* extern */

void PostLootLoad(s32 arg0) {
    PostSoLoad();
    SetLootState(arg0, 0);
}

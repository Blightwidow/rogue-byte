#include "m2c_macros.h"

s32 GetGameCoins(M2C_UNK *);                        /* extern */
M2C_UNK SetGameCoins(M2C_UNK *, s32);               /* extern */
extern M2C_UNK B_002DEB30;

void func_001C67A0(void) {
    SetGameCoins(&B_002DEB30, GetGameCoins(&B_002DEB30) + 1);
}

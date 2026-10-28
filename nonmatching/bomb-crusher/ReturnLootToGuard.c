#include "m2c_macros.h"

s32 FIsLoInWorld();                              /* extern */
M2C_UNK SetLootState();              /* extern */

void ReturnLootToGuard(void *arg0) {
    s32 temp_s1;
    s32 temp_s2;

    if (M2C_FIELD(arg0, s32 *, 0x184) == 5) {
        temp_s1 = M2C_FIELD(arg0, s32 *, 0x15C);
        M2C_FIELD(arg0, s32 *, 0x15C) = 0;
        temp_s2 = M2C_FIELD(arg0, s32 *, 0x158);
        SetLootState(NULL);
        if ((temp_s1 != 0) && (FIsLoInWorld(temp_s1) != 0)) {
            M2C_FIELD(arg0, s32 *, 0x15C) = temp_s1;
            M2C_FIELD(arg0, s32 *, 0x158) = temp_s2;
            SetLootState(arg0, 1);
        }
    }
}

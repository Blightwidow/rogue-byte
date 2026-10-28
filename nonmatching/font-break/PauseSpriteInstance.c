#include "m2c_macros.h"

M2C_UNK PauseAmb(s32, s32);                         /* extern */

void PauseSpriteInstance(void *arg0, s32 arg1) {
    s32 temp_a1;
    s32 temp_v1;

    temp_a1 = arg1 * 0x18;
    M2C_FIELD((temp_a1 + M2C_FIELD(arg0, s32 *, 8)), s32 *, 0x10) = 1;
    temp_v1 = M2C_FIELD((temp_a1 + M2C_FIELD(arg0, s32 *, 8)), s32 *, 0x14);
    if (temp_v1 != 0) {
        PauseAmb(temp_v1, temp_a1);
    }
}

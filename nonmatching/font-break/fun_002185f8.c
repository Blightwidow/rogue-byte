#include "m2c_macros.h"

M2C_UNK QueueSpriteInstanceSlots(s32, M2C_UNK);     /* extern */

void func_002185F8(void *arg0, s32 arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(((arg1 * 0x18) + M2C_FIELD(arg0, s32 *, 8)), s16 *, 8);
    if (temp_v0 >= 0) {
        QueueSpriteInstanceSlots(M2C_FIELD(arg0, s32 *, 4) + (temp_v0 * 0x18), 0x18);
    }
}

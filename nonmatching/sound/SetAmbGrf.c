#include "m2c_macros.h"

M2C_UNK ActivateAmb(s32, s32);                      /* extern */
M2C_UNK DeactivateAmb(s32, s32);                    /* extern */

void SetAmbGrf(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_a1;
    s32 temp_a2;
    u16 temp_v0;

    temp_a1 = arg1 & 0xFFFF;
    temp_a2 = arg2 & 0xFFFF & temp_a1;
    temp_v0 = (M2C_FIELD(arg0, u16 *, 0x50) & ~temp_a1) | temp_a2;
    M2C_FIELD(arg0, u16 *, 0x50) = temp_v0;
    if (temp_v0 != 0) {
        ActivateAmb(temp_a1, temp_a2);
        return;
    }
    DeactivateAmb(temp_a1, temp_a2);
}

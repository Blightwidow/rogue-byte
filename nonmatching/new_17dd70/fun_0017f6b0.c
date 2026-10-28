#include "m2c_macros.h"

M2C_UNK CancelSwCallbacks(M2C_UNK *, M2C_UNK, void *, M2C_UNK); /* extern */
extern M2C_UNK B_003DD490;

void func_0017F6B0(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x184) = (s32) M2C_FIELD(arg0, s32 *, 0x180);
    if (M2C_FIELD(arg0, s32 *, 0x18C) != 0) {
        M2C_ERROR(/* unknown instruction: ldl $a3, %lo(RO_002A563F)($v0) */);
        CancelSwCallbacks(&B_003DD490, 1, arg0, M2C_ERROR(/* unknown instruction: ldr $a3, %lo(RO_002A5638)($v0) */));
    }
}

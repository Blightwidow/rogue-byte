#include "m2c_macros.h"

M2C_UNK QueueSwCallback(M2C_UNK *, void *, M2C_UNK, s32); /* extern */
extern M2C_UNK B_003DD490;

void func_0017F5B0(void *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s32 *, 0x18C) == 0) {
        M2C_ERROR(/* unknown instruction: ldl $a2, %lo(RO_002A5637)($v0) */);
        M2C_FIELD(arg0, s32 *, 0x18C) = 1;
        QueueSwCallback(&B_003DD490, arg0, M2C_ERROR(/* unknown instruction: ldr $a2, %lo(RO_002A5630)($v0) */), arg1);
    }
}

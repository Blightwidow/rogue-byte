#include "m2c_macros.h"

M2C_UNK JT_OnPoActive();                            /* extern */
M2C_UNK QueueSwCallbackOnce(M2C_UNK *, s32, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK B_003DD490;

void func_0018E3A0(s32 arg0) {
    JT_OnPoActive();
    M2C_ERROR(/* unknown instruction: ldl $a2, %lo(RO_002A5F9F)($v0) */);
    QueueSwCallbackOnce(&B_003DD490, arg0, M2C_ERROR(/* unknown instruction: ldr $a2, %lo(RO_002A5F98)($v0) */), 0);
}

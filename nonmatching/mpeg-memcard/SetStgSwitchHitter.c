#include "m2c_macros.h"

M2C_UNK QueueSwCallbackOnce(M2C_UNK *, void *, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK B_003DD490;

void SetStgSwitchHitter(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x170) = arg2;
    M2C_FIELD(arg0, s32 *, 0x16C) = arg1;
    M2C_ERROR(/* unknown instruction: ldl $a2, %lo(RO_002A7637)($v1) */);
    QueueSwCallbackOnce(&B_003DD490, arg0, M2C_ERROR(/* unknown instruction: ldr $a2, %lo(RO_002A7630)($v1) */), 0);
}

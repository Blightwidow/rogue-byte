#include "m2c_macros.h"

M2C_UNK CancelSwCallbacks(M2C_UNK *, M2C_UNK, s32, M2C_UNK); /* extern */
M2C_UNK RemoveLoHierarchy();                        /* extern */
extern M2C_UNK B_003DD490;

void RemoveTn(s32 arg0) {
    RemoveLoHierarchy();
    M2C_ERROR(/* unknown instruction: ldl $a3, %lo(RO_002A96EF)($v0) */);
    CancelSwCallbacks(&B_003DD490, 1, arg0, M2C_ERROR(/* unknown instruction: ldr $a3, %lo(RO_002A96E8)($v0) */));
}

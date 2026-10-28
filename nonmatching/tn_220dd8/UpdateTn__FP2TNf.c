#include "m2c_macros.h"

M2C_UNK *QueueSwCallback(M2C_UNK *, void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK UpdateLo();                                 /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK RO_002A96F7;

M2C_UNK *UpdateTn__FP2TNf(void *arg0) {
    M2C_UNK *var_v0;

    UpdateLo();
    var_v0 = &RO_002A96F7;
    if (M2C_FIELD(arg0, s32 *, 0x13C) != 0) {
        M2C_ERROR(/* unknown instruction: ldl $a2, %lo(RO_002A96F7)($v0) */);
        var_v0 = QueueSwCallback(&B_003DD490, arg0, M2C_ERROR(/* unknown instruction: ldr $a2, %lo(RO_002A96F0)($v0) */), 0);
    }
    return var_v0;
}

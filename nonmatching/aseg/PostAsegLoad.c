#include "m2c_macros.h"

M2C_UNK PostLoLoad();                               /* extern */
M2C_UNK *QueueSwCallback(M2C_UNK *, void *, M2C_UNK, s32); /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK RO_002A46CF;

M2C_UNK *PostAsegLoad(void *arg0) {
    M2C_UNK *var_v0;
    s32 temp_a3;

    PostLoLoad();
    temp_a3 = M2C_FIELD(arg0, s32 *, 0xB0);
    var_v0 = &RO_002A46CF;
    if (temp_a3 != 0) {
        M2C_ERROR(/* unknown instruction: ldl $a2, %lo(RO_002A46CF)($v0) */);
        var_v0 = QueueSwCallback(&B_003DD490, arg0, M2C_ERROR(/* unknown instruction: ldr $a2, %lo(RO_002A46C8)($v0) */), temp_a3);
    }
    return var_v0;
}

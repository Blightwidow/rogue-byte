#include "m2c_macros.h"

s32 PrefFindBinding__6CFrameUii(s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK *QueueSwCallbackOnce(M2C_UNK *, s32 *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK *func_001F4FB0();                           /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK RO_002A4797;

M2C_UNK *AdjustBarrierNewXp(s32 *arg0) {
    M2C_UNK *var_v0;
    s32 temp_a0;

    var_v0 = func_001F4FB0();
    temp_a0 = *arg0;
    if (temp_a0 != 0) {
        var_v0 = &RO_002A4797;
        if (PrefFindBinding__6CFrameUii(temp_a0, 5, 1) != 0) {
            M2C_ERROR(/* unknown instruction: ldl $a2, %lo(RO_002A4797)($v0) */);
            var_v0 = QueueSwCallbackOnce(&B_003DD490, arg0, M2C_ERROR(/* unknown instruction: ldr $a2, %lo(RO_002A4790)($v0) */), 0);
        }
    }
    return var_v0;
}

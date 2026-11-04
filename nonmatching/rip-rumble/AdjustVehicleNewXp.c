#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
M2C_UNK *QueueSwCallbackOnce(M2C_UNK *, s32, M2C_UNK, s32); /* extern */
M2C_UNK func_001F4FB0();                            /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK RO_002A7847;

M2C_UNK *AdjustVehicleNewXp(s32 arg0, void *arg1, s32 arg2) {
    M2C_UNK *var_v0;
    s32 temp_s2;

    func_001F4FB0();
    temp_s2 = M2C_FIELD((arg1 + ((1 - arg2) << 6)), s32 *, 8);
    if (arg2 == 0) {

    } else {
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x80($s1) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf3, $vf2, $vf1x */);
        M2C_ERROR(/* unknown instruction: qmfc2.ni $s0, $vf3 */);
    }
    if ((FIsBasicDerivedFrom(temp_s2, 0x4D) != 0) || (M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s0 */) < 0.7f)) {
        M2C_FIELD(arg1, M2C_UNK32 *, 0x94) = 0;
        M2C_FIELD(arg1, f32 *, 0x98) = 0.1f;
    } else {
        M2C_FIELD(arg1, M2C_UNK32 *, 0x94) = 0x3F000000;
        M2C_FIELD(arg1, f32 *, 0x98) = 0.1f;
    }
    var_v0 = &RO_002A7847;
    if (FIsBasicDerivedFrom(temp_s2, 0x6C) != 0) {
        M2C_ERROR(/* unknown instruction: ldl $a2, %lo(RO_002A7847)($v0) */);
        var_v0 = QueueSwCallbackOnce(&B_003DD490, arg0, M2C_ERROR(/* unknown instruction: ldr $a2, %lo(RO_002A7840)($v0) */), temp_s2);
    }
    return var_v0;
}

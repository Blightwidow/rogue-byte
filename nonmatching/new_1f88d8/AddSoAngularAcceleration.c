#include "m2c_macros.h"

M2C_UNK ConvertXfVec(M2C_UNK, s32, M2C_UNK, s128);  /* extern */
s32 FXfKindDynamic(s16);                            /* extern */

s32 AddSoAngularAcceleration(void *arg0) {
    s32 var_v0;
    void *temp_s0;

    M2C_ERROR(/* unknown instruction: por $s1, $zero, $a1 */);
    var_v0 = FXfKindDynamic(M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s16 *, 0x98));
    if (var_v0 != 0) {
        temp_s0 = M2C_FIELD(arg0, void **, 0x5C);
        ConvertXfVec(0, M2C_FIELD(temp_s0, s32 *, 0xA0), M2C_ERROR(/* unknown instruction: por $a2, $zero, $s1 */), M2C_FIELD(temp_s0, s128 *, 0xF0));
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
        var_v0 = M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf2, $vf3 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xf0($s0) */);
    }
    return var_v0;
}

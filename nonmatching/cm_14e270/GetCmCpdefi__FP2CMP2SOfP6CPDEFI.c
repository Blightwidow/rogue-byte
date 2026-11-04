#include "m2c_macros.h"

M2C_UNK CalcCmAdjust__FP2CMP2SOP6CPDEFIP6VECTOR(void *, s128 *); /* extern */

s128 GetCmCpdefi__FP2CMP2SOfP6CPDEFI(void *arg0, void *arg1, s128 *arg2) {
    s128 *var_a0;
    s128 *var_a1;
    s128 temp_v0;
    void *temp_v0_2;

    if (arg1 == M2C_FIELD(arg0, s32 *, 0x260)) {
        var_a1 = arg2;
        var_a0 = arg0 + 0x270;
        do {
            M2C_FIELD(var_a1, s128 *, 0) = M2C_FIELD(var_a0, s128 *, 0);
            M2C_FIELD(var_a1, s128 *, 0x10) = (s128) M2C_FIELD(var_a0, s128 *, 0x10);
            var_a0 += 0x20;
            var_a1 += 0x20;
        } while (var_a0 != (arg0 + 0x2B0));
        temp_v0 = *var_a0;
        *var_a1 = temp_v0;
        return temp_v0;
    }
    temp_v0_2 = M2C_FIELD(arg1, void **, 0xC);
    M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, s128 *, void *), 0x194)(arg1 + M2C_FIELD(temp_v0_2, s16 *, 0x190), arg2, arg1);
    CalcCmAdjust__FP2CMP2SOP6CPDEFIP6VECTOR(arg0, arg2);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($s0) */);
    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x40($s0) */);
    return M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
}

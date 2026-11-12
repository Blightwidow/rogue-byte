#include "m2c_macros.h"

M2C_UNK func_002564B8(M2C_UNK *);                   /* extern */

void *PcgtPointInCbspQuick__FP4CBSPP6VECTOR(void *arg0, u32 arg1, s128 arg2) {
    char sp[0x40];
    M2C_UNK sp10;
    s128 sp20;
    u32 temp_v1;
    u32 temp_v1_2;
    u32 temp_v1_3;
    void *var_s0;

    var_s0 = arg0;
    sp20 = arg2;
    if (var_s0 != NULL) {
loop_2:
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x30($sp) */);
        func_002564B8(sp);
        func_002564B8(&sp10);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf3 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddaz.x $acc, $vf2, $vf1z */);
        M2C_ERROR(/* unknown instruction: vmsubw.x $vf1, $vf2, $vf1w */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
        if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < 0.0001f) {
            temp_v1 = M2C_FIELD(var_s0, u32 *, 0);
            temp_v1_2 = (temp_v1 >= arg1) ? 0U : temp_v1;
            if (temp_v1_2 != 0) {
                var_s0 = (void *) temp_v1_2;
                goto loop_2;
            }
            return var_s0;
        }
        temp_v1_3 = M2C_FIELD(var_s0, u32 *, 4);
        var_s0 = (void *) ((temp_v1_3 < arg1) ? temp_v1_3 : 0U);
        if (var_s0 == NULL) {
            goto block_8;
        }
        goto loop_2;
    }
block_8:
    return NULL;
}

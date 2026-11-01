#include "m2c_macros.h"

s32 PcgtPointInCbspQuick__FP4CBSPP6VECTOR(s32, M2C_UNK, M2C_UNK); /* extern */

s32 FPointInAloParts(void *arg0) {
    f32 temp_f1;
    s32 temp_a0_2;
    s32 var_s0;
    s32 var_s2;
    s32 var_v0;
    s32 var_v1;
    s64 temp_v1;
    void *temp_a0;

    M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf3 */);
    var_s0 = 0;
    if (M2C_FIELD(arg0, s32 *, 0xE0) > 0) {
        var_s2 = 0;
loop_2:
        temp_a0 = M2C_FIELD(arg0, s32 *, 0xE4) + var_s2;
        temp_v1 = M2C_FIELD(temp_a0, s64 *, 0x10);
        if (!(temp_v1 & (0x8000 << 0x23))) {
            var_v1 = 1;
            if (temp_v1 & (0x8000 << 0x22)) {
                temp_f1 = M2C_FIELD(temp_a0, f32 *, 8);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($v0) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf3, $vf1 */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < (temp_f1 * temp_f1))) {
                    var_v1 = 0;
                }
                var_v0 = 1;
                if (var_v1 == 0) {
                    goto block_7;
                }
                /* Duplicate return node #12. Try simplifying control flow for better match */
                return var_v0;
            }
block_7:
            temp_a0_2 = M2C_FIELD(temp_a0, s32 *, 0x74);
            if (temp_a0_2 != 0) {
                M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($sp) */);
                if (PcgtPointInCbspQuick__FP4CBSPP6VECTOR(temp_a0_2, 0x7FFFFFFF, M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf3 */)) != 0) {
                    return 1;
                }
            }
            goto block_10;
        }
block_10:
        var_s0 += 1;
        var_s2 += 0xB0;
        if (var_s0 >= M2C_FIELD(arg0, s32 *, 0xE0)) {
            goto block_11;
        }
        goto loop_2;
    }
block_11:
    var_v0 = 0;
    return var_v0;
}

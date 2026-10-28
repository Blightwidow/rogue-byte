#include "m2c_macros.h"

extern f32 D_FLT_002C0C00;

s32 PcgtPointInCgSafe(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    f32 temp_f2;
    f32 temp_v0;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s5;
    s32 var_a1;
    s32 var_v0;
    u16 var_a1_2;
    void *temp_a1;
    void *var_s0;

    var_s0 = arg1;
    M2C_ERROR(/* unknown instruction: por $s2, $zero, $a2 */);
    M2C_ERROR(/* unknown instruction: prot3w $v1, $s2 */);
    M2C_ERROR(/* unknown instruction: pextlw $a0, $v1, $a0 */);
    M2C_ERROR(/* unknown instruction: pcpyld $a0, $v1, $a0 */);
    temp_s4 = M2C_FIELD(arg0, s32 *, 0x14);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $a0, $vf3 */);
    temp_s3 = temp_s4 + (M2C_FIELD(arg0, s32 *, 0x10) * 0x10);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
    temp_s5 = (arg3 & 1) ? 0x8000 : 0x4000;
    if (var_s0 != temp_s3) {
        temp_f2 = D_FLT_002C0C00;
loop_2:
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($s0) */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf3 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
        if (!(temp_v0 < -temp_f2)) {
            var_a1_2 = M2C_FIELD(var_s0, u16 *, 0xE);
            if (temp_f2 < temp_v0) {
                goto block_11;
            }
            if (var_a1_2 & 0x8000) {
                var_a1 = var_a1_2 & 0x3FFF;
                if (var_a1_2 & temp_s5) {
                    goto block_13;
                }
                goto block_10;
            }
            temp_a1 = temp_s4 + (var_a1_2 * 0x10);
            if ((temp_a1 == temp_s3) || (M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x10($sp) */), var_v0 = PcgtPointInCgSafe(arg0, temp_a1, M2C_ERROR(/* unknown instruction: por $a2, $zero, $s2 */), arg3), M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($sp) */), (var_v0 == 0))) {
                goto block_10;
            }
            /* Duplicate return node #16. Try simplifying control flow for better match */
            return var_v0;
        }
block_10:
        var_a1_2 = M2C_FIELD(var_s0, u16 *, 0xC);
block_11:
        if (var_a1_2 & 0x8000) {
            var_a1 = var_a1_2 & 0x3FFF;
            if (var_a1_2 & temp_s5) {
block_13:
                return M2C_FIELD(arg0, s32 *, 0xC) + (var_a1 * 0xC);
            }
            goto block_15;
        }
        var_s0 = temp_s4 + (var_a1_2 * 0x10);
        if (var_s0 == temp_s3) {
            goto block_15;
        }
        goto loop_2;
    }
block_15:
    var_v0 = 0;
    return var_v0;
}

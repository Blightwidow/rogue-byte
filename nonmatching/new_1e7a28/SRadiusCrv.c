#include "m2c_macros.h"

M2C_UNK UpdateXfmMatWorld();                        /* extern */

s32 SRadiusCrv(void *arg0) {
    f32 temp_t2;
    f32 temp_v0;
    f32 temp_v0_2;
    f32 temp_v0_3;
    f32 var_f2;
    f32 var_f2_2;
    s32 temp_t1;
    s32 var_a0;
    s32 var_v0;
    s32 var_v1;

    UpdateXfmMatWorld();
    var_f2 = 0.0f;
    if (M2C_FIELD(arg0, s32 *, 0xE0) != 0) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x20($v0) */);
        var_a0 = 0;
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xa0($s0) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf1x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf6, $vf5, $vf1z */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf6, $vf6 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        var_v0 = M2C_FIELD(arg0, s32 *, 0xE8) - 1;
        var_f2_2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */);
        if (var_v0 > 0) {
            M2C_ERROR(/* unknown instruction: vmove.xyzw $vf10, $vf3 */);
            M2C_ERROR(/* unknown instruction: vmove.xyzw $vf9, $vf4 */);
            M2C_ERROR(/* unknown instruction: vmove.xyzw $vf8, $vf5 */);
            temp_t1 = var_v0;
            do {
                M2C_ERROR(/* unknown instruction: vmove.xyzw $vf5, $vf6 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a2) */);
                M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf10, $vf1x */);
                M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf9, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf7, $vf8, $vf1z */);
                M2C_ERROR(/* unknown instruction: vmove.xyzw $vf6, $vf7 */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $t2, $vf4 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a3) */);
                M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf10, $vf1x */);
                M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf9, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf1, $vf8, $vf1z */);
                M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf5 */);
                M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf1, $vf4x */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
                temp_v0_2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
                if (var_f2_2 < temp_v0_2) {
                    var_f2_2 = temp_v0_2;
                }
                M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0xa0($s0) */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $t2, $vf4 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($t0) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($v0) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($t0) */);
                M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf1x */);
                M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf1, $vf2, $vf1z */);
                M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf7 */);
                M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf1, $vf4x */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
                temp_v0_3 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
                if (var_f2_2 < temp_v0_3) {
                    var_f2_2 = temp_v0_3;
                }
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf6, $vf6 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                temp_t2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $t2, $vf1 */);
                if (var_f2_2 < temp_t2) {
                    var_f2_2 = temp_t2;
                }
                var_a0 += 1;
                var_v0 = var_a0 < temp_t1;
            } while (var_v0 != 0);
        }
        /* Duplicate return node #18. Try simplifying control flow for better match */
        M2C_ERROR(/* unknown instruction: c1 0x20004 */);
        return var_v0;
    }
    var_v1 = M2C_FIELD(arg0, s32 *, 0xE8);
    var_v0 = (s32) (arg0 + 0xA0);
    if (var_v1 > 0) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xa0($s0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x20($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($v0) */);
        do {
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a0) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf1x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf1, $vf5, $vf1z */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
            temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
            if (var_f2 < temp_v0) {
                var_f2 = temp_v0;
            }
            var_v1 -= 1;
        } while (var_v1 != 0);
        M2C_ERROR(/* unknown instruction: c1 0x20004 */);
        return M2C_BITWISE(s32, temp_v0);
    }
    M2C_ERROR(/* unknown instruction: c1 0x20004 */);
    return var_v0;
}

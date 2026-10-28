#include "m2c_macros.h"

M2C_UNK UpdateXfmMatWorld();                        /* extern */

void GetCrvBounds(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;
    s32 temp_a3;
    s32 var_v0;
    s32 var_v0_2;

    UpdateXfmMatWorld();
    M2C_ERROR(/* unknown instruction: lqc2 $vf11, 0x30($v0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($v0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x20($v0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xa0($s0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a1) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf1x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf4, $vf1z */);
    M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf5, $vf11, $vf0w */);
    M2C_ERROR(/* unknown instruction: vmove.xyzw $vf6, $vf5 */);
    if (M2C_FIELD(arg0, s32 *, 0xE0) == 0) {
        temp_a0 = M2C_FIELD(arg0, s32 *, 0xE8);
        if (temp_a0 > 1) {
            M2C_ERROR(/* unknown instruction: vmove.xyzw $vf8, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmove.xyzw $vf7, $vf3 */);
            var_v0 = temp_a0 - 1;
            M2C_ERROR(/* unknown instruction: vmove.xyzw $vf3, $vf4 */);
            M2C_ERROR(/* unknown instruction: vmove.xyzw $vf2, $vf11 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
loop_3:
            var_v0 -= 1;
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf8, $vf1x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf7, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf3, $vf1z */);
            M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf1, $vf2, $vf0w */);
            M2C_ERROR(/* unknown instruction: vmax.xyz $vf5, $vf5, $vf1 */);
            M2C_ERROR(/* unknown instruction: vmini.xyz $vf6, $vf6, $vf1 */);
            if (var_v0 != 0) {
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
                goto loop_3;
            }
            M2C_ERROR(/* unknown instruction: sqc2 $vf6, ($s1) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf5, ($s2) */);
            return;
        }
        /* Duplicate return node #10. Try simplifying control flow for better match */
        M2C_ERROR(/* unknown instruction: sqc2 $vf6, ($s1) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf5, ($s2) */);
        return;
    }
    temp_a3 = M2C_FIELD(arg0, s32 *, 0xE8) - 1;
    M2C_ERROR(/* unknown instruction: vmove.xyzw $vf7, $vf5 */);
    if (temp_a3 > 0) {
        M2C_ERROR(/* unknown instruction: vmove.xyzw $vf10, $vf2 */);
        M2C_ERROR(/* unknown instruction: vmove.xyzw $vf9, $vf3 */);
        M2C_ERROR(/* unknown instruction: vmove.xyzw $vf8, $vf4 */);
        var_v0_2 = temp_a3;
        do {
            M2C_ERROR(/* unknown instruction: vmove.xyzw $vf4, $vf7 */);
            var_v0_2 -= 1;
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a1) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf10, $vf1x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf9, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf8, $vf1z */);
            M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf7, $vf11, $vf0w */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $a3, $vf3 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $a3, $vf2 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a0) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf10, $vf1x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf9, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf1, $vf8, $vf1z */);
            M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf4 */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf4, $vf1, $vf3x */);
            M2C_ERROR(/* unknown instruction: vmax.xyz $vf5, $vf5, $vf4 */);
            M2C_ERROR(/* unknown instruction: vmini.xyz $vf6, $vf6, $vf4 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a2) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf10, $vf1x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf9, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf1, $vf8, $vf1z */);
            M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf7 */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf1, $vf2x */);
            M2C_ERROR(/* unknown instruction: vmax.xyz $vf5, $vf5, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmini.xyz $vf6, $vf6, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmini.xyz $vf6, $vf6, $vf7 */);
            M2C_ERROR(/* unknown instruction: vmax.xyz $vf5, $vf5, $vf7 */);
        } while (var_v0_2 != 0);
    }
    M2C_ERROR(/* unknown instruction: sqc2 $vf6, ($s1) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, ($s2) */);
}

#include "m2c_macros.h"

M2C_UNK ReblendAsegbl(s32, s32 *, f32);             /* extern */

void SolvePlainBlendWeights(void *arg0, s32 *arg1, s32 arg2) {
    s32 sp0;
    s32 sp4;
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp20;
    s32 sp24;
    s32 sp28;
    f32 *temp_v0_2;
    f32 *temp_v0_4;
    f32 temp_f0;
    f32 var_f2;
    s32 *var_a1;
    s32 *var_v0_2;
    s32 *var_v1_3;
    s32 *var_v1_4;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a3;
    s32 var_v0;
    s32 var_v0_3;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_5;

    var_a1 = arg1;
    if (arg2 != 0) {
        if (M2C_FIELD(var_a1, s32 *, 0xC4) != 0) {
            if (M2C_FIELD(var_a1, s32 *, 0xE4) != 0) {
                if (M2C_FIELD(arg0, s32 *, 0x1038) == -1) {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x190($t0) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($a1) */);
                    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf2, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
                    if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */) < 0.0f)) {
                        M2C_FIELD(arg0, s32 *, 0x1038) = 0;
                    } else {
                        var_v0 = 1;
                        goto block_11;
                    }
                }
            } else {
                goto block_5;
            }
        } else {
block_5:
            var_v0 = -1;
block_11:
            M2C_FIELD(arg0, s32 *, 0x1038) = var_v0;
        }
        var_v1 = 7;
        M2C_ERROR(/* unknown instruction: qmtc2.ni $a3, $vf6 */);
        var_v0_2 = var_a1 + 0xE0;
        do {
            *var_v0_2 = 0;
            var_v1 -= 1;
            var_v0_2 -= 0x20;
        } while (var_v1 >= 0);
        var_a3 = M2C_FIELD(arg0, s32 *, 0x1038);
        switch (var_a3) {                           /* irregular */
        case -1:
            var_v0_3 = 7;
            if (M2C_FIELD(var_a1, s32 *, 0xE4) == 0) {
                var_v0_3 = 6;
                var_v1_2 = 2;
                var_a0 = 4;
            } else {
                var_v1_2 = 3;
                var_a0 = 5;
            }
            sp0 = var_v0_3;
            sp4 = var_v1_2;
            sp8 = var_a0;
            spC = 0;
            sp10 = 1;
            break;
        case 0:
            sp0 = 6;
            sp4 = 2;
            sp8 = 4;
            spC = 0;
            break;
        case 1:
            sp0 = 7;
            sp4 = 3;
            sp8 = 5;
            spC = var_a3;
            break;
        }
        var_f2 = 0.0f;
        if ((M2C_FIELD(M2C_FIELD(arg0, void **, 0x1030), f32 *, 0x40) > 0.0f) && (M2C_ERROR(/* Read from unset register $t1 */) > 1)) {
            var_v1_3 = &sp4;
            var_a0_2 = M2C_ERROR(/* Read from unset register $t1 */) - 1;
            do {
                temp_v0 = *var_v1_3;
                var_a0_2 -= 1;
                M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x190($t0) */);
                var_v1_3 += 4;
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($v0) */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf3, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf3, $vf3y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf3, $vf2, $vf3z */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf5, $vf5, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf5, $vf5y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf5, $vf4, $vf5z */);
                M2C_ERROR(/* unknown instruction: qmfc2.ni $a3, $vf3 */);
                var_a3 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a3, $vf5 */);
                temp_f0 = M2C_ERROR(/* unknown instruction: max.s $f0, $f0, $f3 */);
                *(var_a1 + (temp_v0 << 5)) = temp_f0;
                var_f2 += temp_f0;
            } while (var_a0_2 != 0);
        }
        temp_v0_2 = var_a1 + (sp0 << 5);
        if (var_f2 < 1.0f) {
            *temp_v0_2 = 1.0f - var_f2;
        } else {
            *temp_v0_2 = 0.0f;
            var_v1_4 = &sp4;
            if (M2C_ERROR(/* Read from unset register $t1 */) > 1) {
                var_a0_3 = M2C_ERROR(/* Read from unset register $t1 */) - 1;
                do {
                    temp_v0_3 = *var_v1_4;
                    var_a0_3 -= 1;
                    var_v1_4 += 4;
                    temp_v0_4 = (temp_v0_3 << 5) + var_a1;
                    *temp_v0_4 /= var_f2;
                } while (var_a0_3 != 0);
            }
        }
        sp28 = 0;
        var_v1_5 = 7;
        sp24 = 0;
        sp20 = 0;
        do {
            var_v1_5 -= 1;
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($a1) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
            var_a1 += 0x20;
            M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf1, $vf3x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x30($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x20($sp) */);
        } while (var_v1_5 >= 0);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf6x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x190($t0) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x30($sp) */);
        ReblendAsegbl(arg2, var_a1, M2C_BITWISE(f32, var_a3));
    }
}

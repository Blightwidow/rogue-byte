#include "m2c_macros.h"

s128 ConvertXfPos();              /* extern */

void RecalcSwXpPos(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_s2;
    u8 *var_v0;
    s32 var_v1;
    void *temp_s1;
    void *var_s0;

    var_v1 = 0;
    if (arg1 > 0) {
        var_v0 = 0 * 4;
        do {
            var_s2 = 0;
            temp_s1 = *(var_v0 + arg2);
            var_s0 = temp_s1;
loop_3:
            temp_a0 = M2C_FIELD(var_s0, s32 *, 4);
            if (temp_a0 != 0) {
                if (var_s2 != 0) {
                    temp_v0 = M2C_FIELD(temp_s1, s32 *, 0x9C);
                    if ((temp_v0 == 7) || (temp_v0 == 9)) {
                        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x70($a0) */);
                        goto block_13;
                    }
                    goto block_14;
                }
                temp_v1 = M2C_FIELD(temp_s1, s32 *, 0x9C);
                if ((temp_v1 < 7) && (temp_v1 >= 4)) {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x70($a0) */);
block_13:
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x80($s1) */);
                    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
                    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf3, $vf1, $vf2x */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x10($s0) */);
                } else {
block_14:
                    M2C_FIELD(var_s0, s128 *, 0x10) = ConvertXfPos(temp_a0, 0, M2C_FIELD(var_s0, s128 *, 0x20));
                }
            }
            var_s2 += 1;
            var_s0 += 0x40;
            if (var_s2 < 2) {
                goto loop_3;
            }
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x50($s1) */);
            var_v1 += 1;
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($s1) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf3 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x80($s1) */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf2 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
            M2C_FIELD(temp_s1, s32 *, 0x90) = (s32) M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf1 */);
            var_v0 = var_v1 * 4;
        } while (var_v1 < arg1);
    }
}

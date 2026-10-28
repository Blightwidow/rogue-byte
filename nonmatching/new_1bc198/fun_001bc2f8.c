#include "m2c_macros.h"

s32 CmpPosXy(M2C_UNK, M2C_UNK);                     /* extern */
s32 Obstacle_IposWrap(void *, s32);                 /* extern */
s32 OrientXy(s128, M2C_UNK, M2C_UNK);               /* extern */

s32 func_001BC2F8(void *arg0) {
    M2C_UNK sp40;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s3;
    s32 var_s4;
    s32 var_s5;
    s32 var_s6;
    s32 var_v0;
    void *temp_v1;

    var_v0 = 2;
    if (M2C_FIELD(arg0, s32 *, 0xE8) >= 2) {
        temp_v1 = M2C_FIELD(arg0, void **, 0xC);
        var_s6 = 0;
        var_s5 = 0;
        var_s3 = 0;
        M2C_FIELD(temp_v1, M2C_UNK (**)(void *), 0xFC)(arg0 + M2C_FIELD(temp_v1, s16 *, 0xF8));
        M2C_ERROR(/* unknown instruction: lqc2 $vf6, ($v0) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf6, ($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x10($v0) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($v0) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($v0) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($v1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, ($v1) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf6, $vf3x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf3y */);
        M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf2, $vf3z */);
        M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf7, $vf1, $vf0w */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf6, $vf4x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf4y */);
        M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf2, $vf4z */);
        M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf8, $vf1, $vf0w */);
        var_s4 = CmpPosXy(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf8 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf7 */));
        if ((M2C_FIELD(arg0, s32 *, 0xE8) - 1) > 0) {
loop_3:
            Obstacle_IposWrap(arg0, Obstacle_IposWrap(arg0, Obstacle_IposWrap(arg0, var_s5) + 1) + 1);
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($v0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf3x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf3y */);
            M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf2, $vf3z */);
            M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf7, $vf1, $vf0w */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf6, ($s0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($s1) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf6x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf6y */);
            M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf2, $vf6z */);
            M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf6, $vf1, $vf0w */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf3x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf3y */);
            M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf2, $vf3z */);
            M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf8, $vf1, $vf0w */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x50($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf7, 0x60($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf8, 0x40($sp) */);
            temp_v0 = CmpPosXy(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf6 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf7 */));
            M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x50($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf7, 0x60($sp) */);
            if (temp_v0 != 0) {
                var_s6 = ((temp_v0 ^ -var_s4) == 0) ? (var_s6 + 1) : var_s6;
            }
            var_s4 = temp_v0;
            temp_v0_2 = OrientXy(sp40, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf6 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf7 */));
            if ((temp_v0_2 == 0) || (var_s3 = temp_v0_2, (temp_v0_2 != -var_s3))) {
                var_s5 += 1;
                if (var_s5 >= (M2C_FIELD(arg0, s32 *, 0xE8) - 1)) {
                    goto block_8;
                }
                goto loop_3;
            }
            var_v0 = 0;
            /* Duplicate return node #16. Try simplifying control flow for better match */
            return var_v0;
        }
block_8:
        if (var_s6 >= 3) {
            return var_s3 == 0;
        }
        switch (var_s3) {                           /* irregular */
        case -1:
            return 4;
        case 1:
            return 3;
        default:
            return 2;
        }
    } else {
        return var_v0;
    }
}

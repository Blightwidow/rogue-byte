#include "m2c_macros.h"

M2C_UNK ConvertCmWorldToScreen(); /* extern */
s32 FInScreenBox();                /* extern */
s32 PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(); /* extern */
extern M2C_UNK B_002DDF40;
extern f32 D_FLT_002BE5B8;
extern f32 D_FLT_002BE5BC;
extern f32 D_FLT_002BE5C0;
extern f32 D_FLT_002BE5C4;
extern f32 D_FLT_002BE5C8;

s32 func_00173768(void *arg0, s128 arg1, s32 arg2, s32 arg3, f32 fparg0) {
    M2C_UNK unksp8;
    s128 sp0;
    s128 sp10;
    s128 sp20;
    f32 temp_a1;
    f32 temp_f12;
    s32 var_v0;
    s32 var_v0_2;

    sp20 = arg1;
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
    sp10 = M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x30($sp) */);
    temp_f12 = fparg0 * D_FLT_002BE5B8;
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    if (!(temp_f12 < M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */))) {
        ConvertCmWorldToScreen(&B_002DDF40, sp20, temp_f12);
        M2C_ERROR(/* unknown instruction: por $s0, $zero, $v0 */);
        temp_a1 = M2C_ERROR(/* unknown instruction: pextuw $a1, $zero, $s0 */);
        var_v0 = 0;
        if (!(temp_a1 < D_FLT_002BE5BC)) {
            var_v0 = 0;
            if (FInScreenBox(M2C_ERROR(/* unknown instruction: por $a0, $zero, $s0 */), temp_a1, D_FLT_002BE5C0) != 0) {
                if ((M2C_FIELD(arg0, s32 *, 0x84) != 0) && (FInScreenBox(M2C_ERROR(/* unknown instruction: por $a0, $zero, $s0 */), D_FLT_002BE5C4) == 0)) {
                    return 1;
                }
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
                if (M2C_FIELD(arg0, s32 *, 0x88) != 0) {
                    var_v0_2 = 1;
                    M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf2, $vf2 */);
                    M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                    if (!(M2C_FIELD(arg0, f32 *, 0x80) < M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */))) {
                        var_v0_2 = 0;
                    }
                    var_v0 = 2;
                    if (var_v0_2 == 0) {
                        goto block_10;
                    }
                } else {
block_10:
                    if ((M2C_FIELD(arg0, s32 *, 0x8C) == 0) || (sp0 = sp20, unksp8 += D_FLT_002BE5C8, var_v0 = 3, (PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, sp10, sp0, arg2) == 0))) {
                        goto block_12;
                    }
                }
                /* Duplicate return node #13. Try simplifying control flow for better match */
                return var_v0;
            }
        }
        /* Duplicate return node #13. Try simplifying control flow for better match */
        return var_v0;
    }
block_12:
    var_v0 = 0;
    return var_v0;
}

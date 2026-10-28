#include "m2c_macros.h"

M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
s128 ConvertCmScreenToWorld(M2C_UNK *, s128);       /* extern */
s128 ConvertCmWorldToScreen(M2C_UNK *, s128);       /* extern */
s32 FFindCmClearInterval(s32, s32, s128, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK PosLoWorld(s32);                            /* extern */
M2C_UNK SetResetFlag__FP2CM(M2C_UNK *);             /* extern */
M2C_UNK bevy_camera_follow_push_out(M2C_UNK *, s128, s128, M2C_UNK *); /* extern */
extern M2C_UNK B_002DDF40;
extern s32 B_002DFBC4;
extern M2C_UNK B_003DD490;
extern s32 D_002C4118;
extern f32 D_FLT_002C4110;
extern f32 D_FLT_002C4114;
extern M2C_UNK func_0014F030;
extern s128 g_2a2dc0;
extern f32 g_2dded0;

void UpdateCptnSquishCut(void *arg0) {
    M2C_UNK unksp28;
    s128 sp0;
    s128 sp10;
    s128 sp20;
    s128 sp30;
    s128 spA0;
    M2C_UNK spB0;
    s32 spB4;
    s32 spB8;
    f32 spBC;
    s128 spC0;
    s128 *var_s0;
    s32 temp_s4;
    u32 var_s1;
    u32 var_s1_2;
    void *temp_v0;

    temp_s4 = M2C_FIELD(arg0, s32 *, 0);
    if (B_002DFBC4 & 2) {
        M2C_FIELD(arg0, f32 *, 0x80) = (f32) g_2dded0;
    } else {
        temp_v0 = M2C_FIELD(arg0, void **, 0x10);
        if (((temp_v0 == NULL) || (M2C_FIELD(temp_v0, s32 *, 0x18C) == 0)) && (D_002C4118 == 0)) {
            if (!((g_2dded0 - M2C_FIELD(arg0, f32 *, 0x80)) < D_FLT_002C4110)) {
                if (M2C_FIELD(&B_002DDF40, s32 *, 0x300) != 0) {
                    return;
                }
                sp0 = M2C_FIELD(&B_002DDF40, s128 *, 0x90);
                sp10 = M2C_FIELD(&B_002DDF40, s128 *, 0x90);
                spC0 = g_2a2dc0;
                spA0 = g_2a2dc0;
                PosLoWorld(temp_s4);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x90($s0) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf3, $vf1 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xc0($sp) */);
                M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf1, $vf2 */);
                M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf3, $vf2, $vf1 */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
                if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < 0.0001f) {

                } else {
                    M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf3, $q */);
                }
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xa0($sp) */);
                M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf1, $vf2 */);
                M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf1, $vf2, $vf1 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x90($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x80($sp) */);
                var_s1 = 0;
                do {
                    var_s1 += 1;
                    PosLoWorld(temp_s4);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf4, ($s2) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x90($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xa0($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x80($sp) */);
                    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf4x */);
                    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf4y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf4, $vf1, $vf4z */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf3, $vf4 */);
                    M2C_ERROR(/* unknown instruction: vmini.xyz $vf2, $vf2, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vmax.xyz $vf3, $vf2, $vf1 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x10($sp) */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($s0) */);
                } while (var_s1 < 5U);
                var_s0 = &sp30;
                CStackFrame_Construct(&spB0);
                var_s1_2 = 0;
                bevy_camera_follow_push_out(&B_003DD490, sp0, sp10, &func_0014F030);
loop_16:
                sp20 = ConvertCmWorldToScreen(&B_002DDF40, *var_s0);
                unksp28 = M2C_FIELD(&B_002DDF40, f32 *, 0x4C);
                sp20 = ConvertCmScreenToWorld(&B_002DDF40, sp20);
                if ((FFindCmClearInterval(spB4, spB8, *var_s0, M2C_ERROR(/* unknown instruction: por $a3, $zero, $v0 */), 0) == 0) || !(spBC >= 1.0f)) {
                    var_s1_2 += 1;
                    var_s0 += 0x10;
                    if (var_s1_2 < 5U) {
                        goto loop_16;
                    }
                } else {
                    M2C_FIELD(arg0, f32 *, 0x80) = (f32) g_2dded0;
                }
                if (D_FLT_002C4114 < (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x80))) {
                    SetResetFlag__FP2CM(&B_002DDF40);
                }
                CStackFrame_Destructor(&spB0, 2);
            }
        }
    }
}

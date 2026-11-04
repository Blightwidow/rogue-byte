#include "m2c_macros.h"

f32 GModPositive__Fff(f32, f32);                    /* extern */
M2C_UNK PosLoWorld(s32);                            /* extern */

void ModifyEmitterParticles__FP7EMITTER(void *arg0) {
    M2C_UNK sp10;
    M2C_UNK sp14;
    M2C_UNK sp18;
    M2C_UNK sp20;
    M2C_UNK sp24;
    M2C_UNK sp28;
    f32 sp0;
    f32 sp4;
    f32 sp8;
    f32 sp30;
    f32 sp34;
    f32 sp38;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f12_3;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    s32 temp_a0;
    s32 var_s2;
    s32 var_v1;
    void *temp_a0_2;
    void *var_s0;
    void *var_s1;

    temp_f1 = M2C_FIELD(arg0, f32 *, 0x140);
    if (temp_f1 > 0.0001f) {
        sp0 = temp_f1;
        sp8 = temp_f1;
        sp4 = temp_f1;
        temp_a0 = *M2C_FIELD(M2C_FIELD(arg0, void **, 0xE4), s32 **, 8);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($sp) */);
        if (temp_a0 != 0) {
            PosLoWorld(temp_a0);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf3, $vf1 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
            PosLoWorld(*M2C_FIELD(M2C_FIELD(arg0, void **, 0xE4), s32 **, 8));
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
            M2C_ERROR(/* unknown instruction: vadd.xyzw $vf2, $vf3, $vf1 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x20($sp) */);
        } else {
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf3, $vf1x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x30($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x20($sp) */);
        }
        temp_f0 = 2.0f * M2C_FIELD(arg0, f32 *, 0x140);
        sp0 = temp_f0;
        sp8 = temp_f0;
        sp4 = temp_f0;
        if (M2C_FIELD(M2C_FIELD(arg0, void **, 0xE4), s32 *, 4) == 0) {
            temp_a0_2 = M2C_FIELD(arg0, void **, 0x150);
            if (temp_a0_2 != NULL) {
                var_s1 = M2C_FIELD(temp_a0_2, void **, 0x448);
                if (var_s1 != NULL) {
                    var_v1 = M2C_FIELD(var_s1, s32 *, 0x1080);
loop_8:
                    var_s2 = 0;
                    if (M2C_FIELD(var_s1, s32 *, 0x1084) > 0) {
                        var_s0 = (var_v1 * 0x840) + var_s1;
                        do {
                            temp_f12 = M2C_FIELD(var_s0, f32 *, 0);
                            if ((temp_f12 < sp10) || (sp20 < temp_f12)) {
                                temp_f1_2 = (sp10 + GModPositive__Fff(temp_f12 - sp10, sp0)) - M2C_FIELD(var_s0, f32 *, 0);
                                sp30 = temp_f1_2;
                                M2C_FIELD(var_s0, f32 *, 0) = (f32) (M2C_FIELD(var_s0, f32 *, 0) + temp_f1_2);
                            }
                            temp_f12_2 = M2C_FIELD(var_s0, f32 *, 4);
                            if ((temp_f12_2 < sp14) || (sp24 < temp_f12_2)) {
                                temp_f1_3 = (sp14 + GModPositive__Fff(temp_f12_2 - sp14, sp4)) - M2C_FIELD(var_s0, f32 *, 4);
                                sp34 = temp_f1_3;
                                M2C_FIELD(var_s0, f32 *, 4) = (f32) (M2C_FIELD(var_s0, f32 *, 4) + temp_f1_3);
                            }
                            temp_f12_3 = M2C_FIELD(var_s0, f32 *, 8);
                            if ((temp_f12_3 < sp18) || (sp28 < temp_f12_3)) {
                                temp_f1_4 = (sp18 + GModPositive__Fff(temp_f12_3 - sp18, sp8)) - M2C_FIELD(var_s0, f32 *, 8);
                                sp38 = temp_f1_4;
                                M2C_FIELD(var_s0, f32 *, 8) = (f32) (M2C_FIELD(var_s0, f32 *, 8) + temp_f1_4);
                            }
                            var_s2 += 1;
                            var_s0 += 0x10;
                        } while (var_s2 < M2C_FIELD(var_s1, s32 *, 0x1084));
                    }
                    var_s1 = M2C_FIELD(var_s1, void **, 0x1090);
                    if (var_s1 != NULL) {
                        var_v1 = M2C_FIELD(var_s1, s32 *, 0x1080);
                        goto loop_8;
                    }
                }
            }
        }
    }
}

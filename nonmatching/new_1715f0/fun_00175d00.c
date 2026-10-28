#include "m2c_macros.h"

M2C_UNK CStackFrame_Construct(void *);              /* extern */
M2C_UNK CStackFrame_Destructor(void *, M2C_UNK);    /* extern */
M2C_UNK CalculateVectorPanTilt__FP6VECTORPfT1(s128, M2C_UNK, f32 *); /* extern */
M2C_UNK DecomposeSphere(s128, f32 *, f32 *, f32 *); /* extern */
s32 FCheckLm__FP2LMf(void *, f32);                  /* extern */
s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
s128 *PmatLoWorld(void *);                          /* extern */
s128 PosLoWorld(void *);                            /* extern */
void *PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(M2C_UNK, s128, s128, s32); /* extern */
f32 RadNormalize__Ff(f32);                          /* extern */
f32 RadYawSo(void *);                               /* extern */
M2C_UNK bevy_camera_follow_push_out(M2C_UNK *, s128, s128, M2C_UNK *); /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK FFilterOxaBasic;
extern f32 g_2dded0;

s32 func_00175D00(void *arg0) {
    char sp[0x400];
    M2C_UNK spB0;
    M2C_UNK sp10;
    f32 sp70;
    f32 sp74;
    f32 sp78;
    f32 sp7C;
    s32 sp80;
    s32 sp84;
    s128 sp90;
    s128 spA0;
    f32 temp_f20;
    s32 temp_a0_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 var_s2;
    s32 var_v0;
    void *temp_a0;
    void *temp_a1;
    void *temp_s0;
    void *temp_v0;
    void *temp_v1;
    void *temp_v1_2;

    temp_v1 = M2C_FIELD(arg0, void **, 0x10);
    var_v0 = 0;
    if ((M2C_FIELD(temp_v1, s32 *, 0xFE8) & 8) && (var_v0 = 0, (M2C_FIELD(temp_v1, s32 *, 0xF00) == 0)) && (var_v0 = 0, (M2C_FIELD(arg0, s32 *, 0x3C) == 0))) {
        temp_a0 = M2C_FIELD(arg0, void **, 0x30);
        if (temp_a0 != NULL) {
            var_v0 = 0;
            if (((u64) M2C_FIELD(temp_a0, u64 *, 0x28) >> 0x3C) & 1) {
                if ((FIsBasicDerivedFrom(temp_a0, 0x32) == 0) || (temp_a1 = M2C_FIELD(arg0, void **, 0x30), temp_v1_2 = M2C_FIELD(temp_a1, void **, 0xC), var_v0 = 0, (M2C_FIELD(temp_v1_2, s32 (**)(void *, void *), 0x26C)(temp_a1 + M2C_FIELD(temp_v1_2, s16 *, 0x268), temp_a1) != 2))) {
                    var_s2 = 0;
                    if (FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0x30), 0x34) != 0) {
                        temp_s0 = M2C_FIELD(arg0, void **, 0x30);
                        if (M2C_FIELD(temp_s0, s32 *, 0x4CC) != -1) {
                            temp_v1_3 = M2C_FIELD(temp_s0, s32 *, 0x4C8);
                            if (temp_v1_3 < 5) {
                                var_s2 = temp_v1_3 >= 3;
                            }
                        }
                        temp_v1_4 = M2C_FIELD(temp_s0, s32 *, 0x2DC);
                        if (temp_v1_4 != -1) {
                            var_s2 = ((temp_v1_4 ^ 0x11) == 0) ? 1 : var_s2;
                        }
                        var_s2 = (~M2C_FIELD(temp_s0, s32 *, 0xF54) != 0) ? 1 : var_s2;
                        if ((FIsBasicDerivedFrom(temp_s0, 0x35) != 0) && ((temp_a0_2 = M2C_FIELD(temp_s0, s32 *, 0x18C8), (temp_a0_2 == 3)) || ((temp_a0_2 >= 3) && (temp_a0_2 < 0x17) && (temp_a0_2 >= 0x15)))) {
                            var_s2 = 1;
                        }
                    }
                    sp90 = PosLoWorld(M2C_FIELD(arg0, void **, 0x10));
                    spA0 = PosLoWorld(M2C_FIELD(arg0, void **, 0x30));
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x90($sp) */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xb0($sp) */);
                    temp_f20 = RadYawSo(M2C_FIELD(arg0, void **, 0x10));
                    DecomposeSphere(spB0, &sp70, &sp74, &sp78);
                    if (FCheckLm__FP2LMf(M2C_FIELD(arg0, void **, 0x10) + 0xF48, sp78) != 0) {
                        var_v0 = 0;
                        if (FCheckLm__FP2LMf(M2C_FIELD(arg0, void **, 0x10) + 0xF50, RadNormalize__Ff(sp70 - temp_f20)) != 0) {
                            CalculateVectorPanTilt__FP6VECTORPfT1(*PmatLoWorld(M2C_FIELD(arg0, void **, 0x10)), 0, &sp7C);
                            if (FCheckLm__FP2LMf(M2C_FIELD(arg0, void **, 0x10) + 0xF58, RadNormalize__Ff(sp74 - sp7C)) == 0) {
                                var_v0 = 0;
                            } else if (var_s2 == 0) {
                                temp_v1_5 = M2C_FIELD(arg0, s32 *, 0x34);
                                if (temp_v1_5 == 0) {
                                    if ((g_2dded0 - M2C_FIELD(arg0, f32 *, 0x38)) < 3.0f) {
                                        goto block_27;
                                    }
                                    goto block_29;
                                }
                                var_v0 = 0;
                                if (temp_v1_5 == 2) {
                                    goto block_29;
                                }
                            } else {
block_29:
                                CStackFrame_Construct(sp);
                                bevy_camera_follow_push_out(&B_003DD490, sp90, spA0, &FFilterOxaBasic);
                                temp_v0 = PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, sp90, spA0, sp80);
                                if ((temp_v0 != NULL) && (*M2C_FIELD(M2C_FIELD(temp_v0, void **, 4), s32 **, 0x14) != M2C_FIELD(arg0, void **, 0x30))) {
                                    CStackFrame_Destructor(sp, 2);
                                    var_v0 = 0;
                                } else {
                                    CStackFrame_Destructor(sp, 2);
                                    var_v0 = 1;
                                }
                            }
                        }
                    } else {
block_27:
                        var_v0 = 0;
                    }
                }
            }
        }
    }
    return var_v0;
}

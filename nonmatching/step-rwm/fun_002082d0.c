#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
s32 FIsGuardPriorityClass(void *, void *);          /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
s32 func_002089F0(void *, void *);                  /* extern */
s32 func_00208B38(void *, void *);                  /* extern */
extern M2C_UNK D_FLT_002C3D70;
extern M2C_UNK D_FLT_002C3D80;

void *func_002082D0(void *arg0) {
    f32 var_f20;
    f32 var_f21;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_s3;
    s32 var_s4;
    void *temp_s0;
    void *temp_v0;
    void *temp_v1;
    void *var_s2;
    void *var_v0;

    temp_v1 = M2C_FIELD(arg0, void **, 0x390);
    var_s2 = NULL;
    if (temp_v1 != NULL) {
        if (((u64) M2C_FIELD(temp_v1, u64 *, 0x28) >> 0x3C) & 1) {
            var_s2 = temp_v1;
            goto block_31;
        }
        goto block_4;
    }
block_4:
    var_f21 = 3.4028235e38f;
    var_s3 = 0;
    PosLoWorld(arg0);
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0xF64), s32 *, 0xFC) > 0) {
        var_s4 = 0x100;
loop_6:
        temp_v0 = M2C_FIELD(arg0, void **, 0xF64) + var_s4;
        temp_s0 = M2C_FIELD(temp_v0, void **, 0);
        if (temp_s0 != NULL) {
            if (M2C_FIELD(temp_v0, s32 *, 4) == 0) {
                temp_v0_2 = M2C_FIELD(arg0, s32 *, 0xFBC);
                if (temp_v0_2 != 0x22) {
                    if (temp_v0_2 == 0x25) {
                        goto block_11;
                    }
                    goto block_30;
                }
block_11:
                if (FIsBasicDerivedFrom(temp_s0, 0x38) != 0) {
                    goto block_12;
                }
                goto block_30;
            }
block_12:
            if (func_002089F0(arg0, temp_s0) == 0) {
                var_v0 = temp_s0;
                if (func_00208B38(arg0, temp_s0) == 0) {
                    PosLoWorld(temp_s0);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
                    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                    var_f20 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */);
                    if (temp_s0 == M2C_FIELD(arg0, s32 *, 0x38C)) {
                        var_f20 = M2C_FIELD(&D_FLT_002C3D70, f32 *, 0) + (var_f20 * (M2C_FIELD(&D_FLT_002C3D70, f32 *, 4) + (var_f20 * M2C_FIELD(&D_FLT_002C3D70, f32 *, 8))));
                    }
                    temp_v0_3 = M2C_FIELD(arg0, s32 *, 0xFBC);
                    if (temp_v0_3 != 0x22) {
                        if (temp_v0_3 == 0x25) {
                            goto block_19;
                        }
                    } else {
block_19:
                        if (FIsBasicDerivedFrom(temp_s0, 0x38) != 0) {
                            var_f20 = M2C_FIELD(&D_FLT_002C3D80, f32 *, 0) + (var_f20 * (M2C_FIELD(&D_FLT_002C3D80, f32 *, 4) + (var_f20 * M2C_FIELD(&D_FLT_002C3D80, f32 *, 8))));
                        }
                    }
                    if (FIsGuardPriorityClass(arg0, temp_s0) != 0) {
                        if ((var_s2 != NULL) && (FIsGuardPriorityClass(arg0, var_s2) == 0)) {
                            goto block_29;
                        }
                        goto block_28;
                    }
                    if ((var_s2 == NULL) || (FIsGuardPriorityClass(arg0, var_s2) == 0)) {
block_28:
                        if (var_f20 < var_f21) {
block_29:
                            var_f21 = var_f20;
                            var_s2 = temp_s0;
                        }
                    }
                    goto block_30;
                }
            } else {
                goto block_30;
            }
        } else {
block_30:
            var_s3 += 1;
            var_s4 += 0x10;
            if (var_s3 >= M2C_FIELD(M2C_FIELD(arg0, void **, 0xF64), s32 *, 0xFC)) {
                goto block_31;
            }
            goto loop_6;
        }
    } else {
block_31:
        var_v0 = var_s2;
    }
    return var_v0;
}

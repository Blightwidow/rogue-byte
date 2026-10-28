#include "m2c_macros.h"

s32 FFindSurfaceAlongUp(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
s32 FSwHandsOff(M2C_UNK *);                         /* extern */
M2C_UNK FadeAloOut(void *, M2C_UNK);                /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK WarpJtToPoint(void *, s128);                /* extern */
M2C_UNK bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, void *); /* extern */
s32 bevy_player_p4_144068(void *);                  /* extern */
s32 func_0017D608(void *);                          /* extern */
void *func_00205458(void *, M2C_UNK);               /* extern */
extern M2C_UNK B_002DEB30;
extern M2C_UNK B_003DD490;
extern f32 D_FLT_002BD2D0;
extern f32 D_FLT_002BD2D4;
extern f32 g_2dded0;

void func_00144640(void *arg0) {
    char sp[0x400];
    M2C_UNK sp0;
    f32 temp_v0_4;
    s32 temp_v1;
    s32 var_s5;
    void **var_s2;
    void *temp_a0;
    void *temp_s0;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *var_s1;

    if (M2C_FIELD(arg0, s32 *, 0x28) != 0) {
        if (M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x2DC) == -1) {
            M2C_FIELD(arg0, s32 *, 0x28) = 0;
        }
    } else if (bevy_player_p4_144068(M2C_FIELD(arg0, void **, 0)) != 0) {
        if (!(g_2dded0 < M2C_FIELD(arg0, f32 *, 0x24))) {
            M2C_FIELD(arg0, f32 *, 0x24) = (f32) (g_2dded0 + D_FLT_002BD2D0);
            if (FSwHandsOff(&B_003DD490) != 0) {
                var_s2 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0xEC), void ***, 0x64);
                var_s5 = 0;
                if (var_s2 != NULL) {
                    var_s1 = *var_s2;
loop_10:
                    if (var_s1 != NULL) {
                        do {
                            temp_s0 = M2C_FIELD((var_s1 + ((1 - ((s32) M2C_FIELD(arg0, void **, 0) != M2C_FIELD(var_s1, s32 *, 8))) << 6)), void **, 8);
                            if ((FIsBasicDerivedFrom(temp_s0, 0x38) != 0) && ((temp_v0 = func_00205458(temp_s0, 0xA9), (temp_v0 == NULL)) || (M2C_FIELD(temp_v0, s32 *, 0x4C) == 0))) {
                                if (M2C_FIELD(temp_s0, f32 *, 0x130) >= 0.0f) {
                                    bevy_camera_follow_activity(&B_002DEB30, 0x17, temp_s0);
                                }
                                var_s5 = 1;
                                FadeAloOut(temp_s0, 0x3F000000);
                            }
                            var_s1 = M2C_FIELD(var_s1, void **, 0xAC);
                        } while (var_s1 != NULL);
                    }
                    var_s2 = M2C_FIELD(var_s2, void ***, 4);
                    if (var_s2 != NULL) {
                        var_s1 = *var_s2;
                        goto loop_10;
                    }
                }
                if (var_s5 == 0) {
                    goto block_23;
                }
            } else {
block_23:
                temp_a0 = M2C_FIELD(arg0, void **, 0);
                temp_v0_2 = M2C_FIELD(temp_a0, void **, 0x1084);
                if (temp_v0_2 != NULL) {
                    if (*M2C_FIELD(temp_v0_2, s32 **, 0x40) == 0x24) {
                        goto block_29;
                    }
                } else {
                    temp_v0_3 = func_00205458(temp_a0, 0xA8);
                    if (temp_v0_3 != NULL) {
                        temp_v1 = M2C_FIELD(temp_v0_3, s32 *, 0x4C);
                        if (temp_v1 < 2) {
                            if (temp_v1 >= 0) {
block_29:
                                PosLoWorld(M2C_FIELD(arg0, void **, 0));
                                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                                M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($s3) */);
                                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
                                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                                M2C_ERROR(/* unknown instruction: vwaitq */);
                                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                                temp_v0_4 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
                                if (((M2C_FIELD(arg0, f32 *, 0x20) - temp_v0_4) < (D_FLT_002BD2D4 * D_FLT_002BD2D0)) && ((M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */), (FFindSurfaceAlongUp(sp, 0, 0, 0x42C80000, 0xC3160000) != 0)) || (func_0017D608(sp) != 0))) {
                                    WarpJtToPoint(M2C_FIELD(arg0, void **, 0), sp0);
                                    M2C_FIELD(arg0, s32 *, 0x28) = 1;
                                }
                                M2C_FIELD(arg0, f32 *, 0x20) = temp_v0_4;
                            }
                        }
                    }
                }
            }
        }
    }
}

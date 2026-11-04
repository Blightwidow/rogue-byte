#include "m2c_macros.h"

M2C_UNK EnsureAloSfx__FP3ALO(void *);               /* extern */
s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
M2C_UNK FMatchJtXmg(void *, void *, s32);           /* extern */
M2C_UNK FindClosestPointBetweenLineSegments__FP6VECTORN40PfT0(s128, s128, s128, s128); /* extern */
M2C_UNK FindCrvClosestPointFromS(void *, s128, M2C_UNK, s128 *, f32); /* extern */
s128 PosLoWorld(void *);                            /* extern */
M2C_UNK RebuildJtXmg__FP2JTP3ALOfT1P6ACTADJP3XMG(void *, s32, s32, s32, f32); /* extern */
M2C_UNK SetJtState(void *, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK SetRunBlendU(void *, M2C_UNK);              /* extern */
M2C_UNK SetStepRadTarget(void *, f32);              /* extern */
M2C_UNK SolvePlainBlendWeights(void *, void *, s32); /* extern */
M2C_UNK UpdateJt();                                 /* extern */
M2C_UNK UpdateJtBalance(void *);                    /* extern */
M2C_UNK UpdateJtHangPose(void *);                   /* extern */
M2C_UNK UpdateJtRide(void *);                       /* extern */
M2C_UNK UpdateJtStand__FP2JT(void *);               /* extern */
M2C_UNK UpdateJtSurfaceWalk(void *);                /* extern */
M2C_UNK UpdateRunBlendFootsteps(void *);            /* extern */
M2C_UNK bevy_player_input_from_pad_cm(void *);      /* extern */
extern f32 D_FLT_002BF3DC;

void bevy_player_p5_states_18bce0(void *arg0) {
    s128 sp10;
    s128 sp20;
    s128 sp30;
    M2C_UNK sp40;
    f32 sp50;
    s128 *var_s0;
    s128 *var_s1;
    s128 *var_s1_2;
    s128 temp_v0;
    s32 temp_a3;
    s32 var_s2;
    s32 var_s2_2;
    u32 temp_v1;
    void *temp_s0;
    void *temp_s4;
    void *temp_v1_2;
    void *var_s0_2;

    UpdateJt();
    if (((u64) M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1) {
        if (M2C_FIELD(arg0, void **, 0x150) != NULL) {
            bevy_player_input_from_pad_cm(arg0);
        }
        temp_v1 = M2C_FIELD(arg0, u32 *, 0x18C8);
        switch (temp_v1) {
        case 1:
            temp_s0 = arg0 + 0x1320;
            SetStepRadTarget(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x18));
            SetRunBlendU(temp_s0, 0x3F800000);
            UpdateRunBlendFootsteps(temp_s0);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x190($s3) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf2x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x190($s3) */);
            break;
        case 5:
            if (M2C_FIELD(arg0, s32 *, 0x18D0) == 5) {
                SolvePlainBlendWeights(arg0, arg0 + 0x13D0, M2C_FIELD(arg0, s32 *, 0x14D0));
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x190($s3) */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
                M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf2x */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x190($s3) */);
                M2C_FIELD(arg0, f32 *, 0x180) = 1.0f;
            }
            break;
        case 10:
            SolvePlainBlendWeights(arg0, arg0 + 0x1AC0, M2C_FIELD(arg0, s32 *, 0x1BC0));
            break;
        case 0:
            UpdateJtStand__FP2JT(arg0);
            break;
        case 3:
            UpdateJtHangPose(arg0);
            break;
        case 12:
            UpdateRunBlendFootsteps(arg0 + 0x1C30);
            break;
        case 21:
            UpdateJtSurfaceWalk(arg0);
            break;
        case 22:
            UpdateJtRide(arg0);
            break;
        case 24:
            temp_a3 = M2C_FIELD(arg0, s32 *, 0x19F0);
            if (temp_a3 != 0) {
                RebuildJtXmg__FP2JTP3ALOfT1P6ACTADJP3XMG(arg0, M2C_FIELD(arg0, s32 *, 0x19D8), M2C_FIELD(arg0, s32 *, 0x19E0), temp_a3, D_FLT_002BF3DC);
                RebuildJtXmg__FP2JTP3ALOfT1P6ACTADJP3XMG(arg0, M2C_FIELD(arg0, s32 *, 0x19D4), M2C_FIELD(arg0, s32 *, 0x19DC), M2C_FIELD(arg0, s32 *, 0x19F4), D_FLT_002BF3DC);
                FMatchJtXmg(arg0, arg0 + 0x1520, M2C_FIELD(arg0, s32 *, 0x19F0));
                FMatchJtXmg(arg0, arg0 + 0x1620, M2C_FIELD(arg0, s32 *, 0x19F4));
            }
            break;
        }
        EnsureAloSfx__FP3ALO(arg0);
        if (M2C_FIELD(arg0, s32 *, 0x18D8) == 0) {
            var_s1 = &sp10;
            if (FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0x1854), 0xB) != 0) {
                temp_s4 = M2C_FIELD(arg0, void **, 0x1854);
                var_s0 = arg0 + 0x1890;
                var_s2 = 2;
                do {
                    FindCrvClosestPointFromS(temp_s4, *var_s0, 0, var_s1, M2C_FIELD(arg0, f32 *, 0x1858));
                    var_s1 += 0x10;
                    var_s2 -= 1;
                    var_s0 += 0x10;
                } while (var_s2 >= 0);
                goto block_24;
            }
            if (FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0x1854), 0x13) != 0) {
                temp_v0 = PosLoWorld(M2C_FIELD(arg0, void **, 0x1854));
                sp10 = temp_v0;
                sp30 = temp_v0;
                sp20 = temp_v0;
block_24:
                var_s2_2 = 1;
                if (M2C_FIELD(arg0, s32 *, 0x1880) > 1) {
                    var_s1_2 = &sp10;
                    var_s0_2 = arg0 + 0x18A0;
loop_26:
                    FindClosestPointBetweenLineSegments__FP6VECTORN40PfT0(M2C_FIELD(var_s0_2, s128 *, -0x10), M2C_FIELD(var_s0_2, s128 *, 0), M2C_FIELD(var_s1_2, s128 *, 0), M2C_FIELD(var_s1_2, s128 *, 0x10));
                    if (!(sp50 < M2C_FIELD(arg0, f32 *, 0x19AC))) {
                        var_s2_2 += 1;
                        var_s1_2 += 0x10;
                        var_s0_2 += 0x10;
                        if (var_s2_2 < M2C_FIELD(arg0, s32 *, 0x1880)) {
                            goto loop_26;
                        }
                    } else if (FIsBasicDerivedFrom(M2C_FIELD(arg0, void **, 0x1854), 0x13) == 0) {
                        M2C_FIELD(arg0, void **, 0xF5C) = (void *) M2C_FIELD(arg0, void **, 0x1854);
                        M2C_FIELD(arg0, f32 *, 0xF60) = (f32) M2C_FIELD(arg0, f32 *, 0x1858);
                        SetJtState(arg0, 8, -1);
                    } else {
                        temp_v1_2 = M2C_FIELD(arg0, void **, 0x1854);
                        M2C_FIELD(arg0, void **, 0x18C4) = temp_v1_2;
                        if (M2C_FIELD(temp_v1_2, s32 *, 0x124) != 3) {
                            SetJtState(arg0, 3, 1);
                        } else {
                            SetJtState(arg0, 0x16, -1);
                        }
                    }
                }
            }
        }
        UpdateJtBalance(arg0);
    }
}

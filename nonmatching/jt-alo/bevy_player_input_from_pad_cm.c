#include "m2c_macros.h"

M2C_UNK BuildJtTargetList(); /* extern */
M2C_UNK DrainJtPower();                  /* extern */
s32 FAsegaGone();                                /* extern */
s32 FGadgetAcquired();                       /* extern */
f32 GLimitAbs__Fff();                   /* extern */
void *PchnFindAseg();  /* extern */
f32 RadNormalize__Ff();                          /* extern */
f32 RadYawSo();                               /* extern */
M2C_UNK ReblendAsegbl();                         /* extern */
M2C_UNK ReleaseAsegaHandle();                 /* extern */
M2C_UNK SetAsegaSpeed();                 /* extern */
M2C_UNK SetJtGoalVelocityFromStick(); /* extern */
M2C_UNK SetJtState();       /* extern */
M2C_UNK SetRunBlendU();                  /* extern */
M2C_UNK SetStepRadTarget();              /* extern */
s128 SetVectorCylind__FP6VECTORfff(); /* extern */
M2C_UNK UpdateAttachMotion();                 /* extern */
M2C_UNK UpdateJtActiveHang__FP2JTP3JOY();     /* extern */
M2C_UNK UpdateJtBinocInput();                 /* extern */
M2C_UNK UpdateJtCaneInput();                  /* extern */
M2C_UNK UpdateJtSafePoints();                 /* extern */
M2C_UNK UpdateJtStateTransitions();           /* extern */
M2C_UNK UpdateZapPost();                      /* extern */
s128 bevy_camera_follow_track_heading_weight(); /* extern */
M2C_UNK bevy_player_p18_gadget_glide_steer(); /* extern */
M2C_UNK bevy_player_p25_137218();             /* extern */
M2C_UNK func_0018B460();                      /* extern */
M2C_UNK func_0018E1E0();                      /* extern */
M2C_UNK func_002046F0();                 /* extern */
M2C_UNK func_00204E38();         /* extern */
extern M2C_UNK B_003DD490;
extern f32 D_FLT_002BF35C;
extern f32 D_FLT_002BF3C0;
extern f32 D_FLT_002BF3C4;
extern f32 D_FLT_002BF3C8;
extern f32 D_FLT_002BF3CC;
extern s128 g_2a2dd0;

void bevy_player_input_from_pad_cm(void *arg0) {
    M2C_UNK jtbl_002A5A10;
    char sp[0x400];
    f32 temp_f3;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_v1_2;
    s32 var_a2;
    u32 temp_v1;
    void **temp_a3;
    void **temp_t0;
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_a1_4;
    void *temp_a3_2;
    void *temp_s1;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v1_3;
    void *temp_v1_4;
    void *temp_v1_5;
    void *var_a1;

    RadNormalize__Ff(M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x18) - RadYawSo());
    BuildJtTargetList(&B_003DD490, arg0, 0xFFFF);
    UpdateJtBinocInput(arg0);
    UpdateJtStateTransitions(arg0);
    UpdateJtCaneInput(arg0);
    temp_v1 = M2C_FIELD(arg0, u32 *, 0x18C8);
    switch (temp_v1) {                              /* switch 1 */
    case 4:                                         /* switch 1 */
    case 9:                                         /* switch 1 */
        temp_s1 = M2C_FIELD(arg0, void **, 0x1030);
        M2C_FIELD(arg0, s128 *, 0x190) = (s128) g_2a2dd0;
        if (temp_s1 != NULL) {
            temp_v0 = PchnFindAseg(M2C_FIELD(temp_s1, s32 *, 0x14), arg0, 1, 1);
            if (temp_v0 != NULL) {
                temp_a3 = M2C_FIELD(temp_v0, void ***, 4);
                temp_v0_2 = *temp_a3;
                M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *, M2C_UNK, void *, void **, f32, f32), 0x1C)(temp_a3 + M2C_FIELD(temp_v0_2, s16 *, 0x18), 0, sp, temp_a3, M2C_FIELD(temp_s1, f32 *, 0x1C), M2C_FIELD(temp_s1, f32 *, 0x40));
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
block_33:
                M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf2x */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x190($s0) */);
            }
        }
        break;
    case 3:                                         /* switch 1 */
        UpdateJtActiveHang__FP2JTP3JOY(arg0);
        break;
    case 2:                                         /* switch 1 */
        bevy_player_p18_gadget_glide_steer(arg0 + 0x2C0);
        break;
    case 7:                                         /* switch 1 */
        UpdateAttachMotion(arg0 + 0x4C0);
        break;
    case 6:                                         /* switch 1 */
        bevy_player_p25_137218(arg0 + 0x1FF0);
        break;
    case 10:                                        /* switch 1 */
        var_a2 = M2C_FIELD(arg0, s32 *, 0x1BC0);
        var_a1 = arg0 + 0x1AC0;
block_24:
        SetJtGoalVelocityFromStick(arg0, var_a1, var_a2, M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x18), M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x1C));
        break;
    case 11:                                        /* switch 1 */
        func_0018B460(arg0);
        break;
    case 12:                                        /* switch 1 */
        SetRunBlendU(arg0 + 0x1C30, M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x1C));
block_36:
        SetStepRadTarget(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x18));
        break;
    case 5:                                         /* switch 1 */
        temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x18D0);
        switch (temp_v1_2) {                        /* switch 2; irregular */
        case 4:                                     /* switch 2 */
            temp_a1 = M2C_FIELD(arg0, s32 *, 0x10DC);
            if (temp_a1 != 0) {
                func_002046F0(arg0, temp_a1);
            }
            break;
        default:                                    /* switch 2 */
            temp_v1_3 = M2C_FIELD(arg0, void **, 0x150);
            M2C_FIELD(arg0, s128 *, 0x190) = bevy_camera_follow_track_heading_weight(0, arg0, M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */), SetVectorCylind__FP6VECTORfff(*((temp_v1 * 4) + &jtbl_002A5A10), M2C_FIELD(temp_v1_3, f32 *, 0x18) + 3.1415927f, M2C_FIELD(temp_v1_3, f32 *, 0x1C) * D_FLT_002BF3C0, 0));
            break;
        case 5:                                     /* switch 2 */
            var_a2 = M2C_FIELD(arg0, s32 *, 0x14D0);
            var_a1 = arg0 + 0x13D0;
            goto block_24;
        }
        break;
    case 16:                                        /* switch 1 */
        if (FGadgetAcquired(0x1C) == 0) {
            if (M2C_FIELD(arg0, s32 *, 0x1D2C) != 0) {
                temp_v0_3 = PchnFindAseg(M2C_FIELD(arg0, s32 *, 0x1D1C), arg0, 1, 1);
                if (temp_v0_3 != NULL) {
                    temp_t0 = M2C_FIELD(temp_v0_3, void ***, 4);
                    temp_a3_2 = M2C_FIELD(arg0, void **, 0x1030);
                    temp_v0_4 = *temp_t0;
                    M2C_FIELD(temp_v0_4, M2C_UNK (**)(void *, M2C_UNK, void *, void *, f32, f32), 0x1C)(temp_t0 + M2C_FIELD(temp_v0_4, s16 *, 0x18), 0, sp, temp_a3_2, M2C_FIELD(temp_a3_2, f32 *, 0x1C), M2C_FIELD(temp_a3_2, f32 *, 0x40));
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
                    goto block_33;
                }
            }
        } else {
            func_0018E1E0(arg0);
        }
        break;
    case 19:                                        /* switch 1 */
        temp_a1_2 = M2C_FIELD(arg0, void **, 0x1030);
        func_00204E38(arg0, temp_a1_2, M2C_FIELD(temp_a1_2, f32 *, 0x1C));
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $a0, $vf1 */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf3, $vf1x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x190($s0) */);
        break;
    case 20:                                        /* switch 1 */
        temp_a1_3 = M2C_FIELD(arg0, void **, 0x1030);
        func_00204E38(arg0, temp_a1_3, M2C_FIELD(temp_a1_3, f32 *, 0x1C));
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf3, $vf2x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x190($s0) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
        SetAsegaSpeed(M2C_FIELD(arg0, void **, 0x1030), M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x1C));
        goto block_36;
    case 17:                                        /* switch 1 */
        temp_a1_4 = M2C_FIELD(arg0, void **, 0x1030);
        func_00204E38(arg0, temp_a1_4, M2C_FIELD(temp_a1_4, f32 *, 0x1C));
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        temp_v1_4 = M2C_FIELD(arg0, void **, 0x150);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $a0, $vf1 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf3, $vf1x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x190($s0) */);
        if (M2C_FIELD(temp_v1_4, f32 *, 0x1C) > 0.0f) {
            SetStepRadTarget(arg0, M2C_FIELD(temp_v1_4, f32 *, 0x18));
        }
        break;
    case 24:                                        /* switch 1 */
        DrainJtPower(arg0, D_FLT_002BF3C4);
        if (M2C_FIELD(arg0, s32 *, 0x18D0) != 0xC) {
            SetStepRadTarget(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x18));
        } else if (fabsf(RadNormalize__Ff(RadYawSo(arg0) - M2C_FIELD(arg0, f32 *, 0x1A8))) < D_FLT_002BF3C8) {
            SetJtState(arg0, 0x18, 0xD);
        }
        temp_v1_5 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v1_5, M2C_UNK (**)(void *), 0x114)(arg0 + M2C_FIELD(temp_v1_5, s16 *, 0x110));
        temp_f3 = fabsf(D_FLT_002BF3CC * GLimitAbs__Fff(M2C_ERROR(/* unknown instruction: pextuw $v1, $zero, $v0 */) / (M2C_FIELD(arg0, f32 *, 0x1F4) * D_FLT_002BF35C), 0x3F800000));
        M2C_FIELD(arg0, f32 *, 0x2014) = (f32) M2C_ERROR(/* unknown instruction: max.s $f0, $f2, $f1 */);
        M2C_FIELD(arg0, f32 *, 0x202C) = (f32) M2C_ERROR(/* unknown instruction: max.s $f2, $f2, $f1 */);
        M2C_FIELD(arg0, f32 *, 0x2020) = (f32) (1.0f - temp_f3);
        ReblendAsegbl(M2C_FIELD(arg0, s32 *, 0x2038));
        break;
    }
    UpdateZapPost(arg0 + 0xDF0);
    UpdateJtSafePoints(arg0);
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x1310);
    if ((temp_a0 != 0) && (FAsegaGone(temp_a0) != 0)) {
        ReleaseAsegaHandle(arg0 + 0x1310);
        M2C_FIELD(arg0, s32 *, 0x1314) = -1;
    }
}

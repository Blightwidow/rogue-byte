#include "m2c_macros.h"

M2C_UNK BuildJtTargetList(M2C_UNK *, void *, M2C_UNK); /* extern */
f32 GLimitAbs__Fff(f32, f32);                       /* extern */
f32 RadNormalize__Ff(M2C_UNK *, void *, f32, f32);  /* extern */
M2C_UNK SetAsegaSpeed(void *, f32);                 /* extern */
M2C_UNK SetRunBlendU(void *, f32);                  /* extern */
M2C_UNK SetSmaMask(s32, s32);                       /* extern */
M2C_UNK SetStepRadTarget(void *, f32);              /* extern */
M2C_UNK SetVectorCylind__FP6VECTORfff(f32, f32, f32, M2C_UNK); /* extern */
M2C_UNK SolvePlainBlendWeights(void *, void *, s32); /* extern */
M2C_UNK UpdateAttachMotion(void *);                 /* extern */
M2C_UNK UpdateBentleyActive(void *);                /* extern */
M2C_UNK UpdateBentleyBinoc(void *);                 /* extern */
M2C_UNK UpdateJt();                                 /* extern */
M2C_UNK UpdateRunBlendFootsteps(void *);            /* extern */
M2C_UNK UpdateZapPost(void *);                      /* extern */
M2C_UNK bevy_player_p18_gadget_glide_steer(void *); /* extern */
M2C_UNK func_00135EB0(void *);                      /* extern */
s32 func_001430C8(void *);                          /* extern */
M2C_UNK func_002046F0(void *, s32);                 /* extern */
M2C_UNK func_00204E38(void *, void *, f32);         /* extern */
extern M2C_UNK B_003DD490;
extern f32 D_FLT_002BC934;
extern M2C_UNK D_FLT_002BC940;
extern M2C_UNK D_FLT_002BC950;
extern f32 D_FLT_002BC960;
extern M2C_UNK g_2bbb60;
extern f32 g_2dded4;

void UpdateBentley(void *arg0) {
    f32 temp_a0;
    f32 temp_a0_2;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 var_f12;
    f32 var_f20;
    f32 var_f21;
    s32 var_a2;
    u32 temp_v1;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_v0;
    void *temp_v1_2;
    void *temp_v1_3;
    void *var_a0;
    void *var_a1;
    void *var_s0;

    UpdateJt();
    if (((u64) M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1) {
        BuildJtTargetList(&B_003DD490, arg0, 0xF8FE);
        UpdateBentleyBinoc(arg0);
        UpdateBentleyActive(arg0);
        temp_v1 = M2C_FIELD(arg0, u32 *, 0x13D0);
        switch (temp_v1) {
        case 0:
            if (M2C_FIELD(arg0, s32 *, 0x181C) != 0) {
                SetStepRadTarget(arg0, D_FLT_002BC934);
            } else {
                SetSmaMask(M2C_FIELD(arg0, s32 *, 0x1034), func_001430C8(arg0));
            }
            break;
        case 1:
            var_s0 = arg0 + 0x1320;
            SetStepRadTarget(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x18));
            var_f12 = 1.0f;
            var_a0 = var_s0;
block_8:
            SetRunBlendU(var_a0, var_f12);
            UpdateRunBlendFootsteps(var_s0);
            break;
        case 7:
            var_s0 = arg0 + 0x1600;
            SetStepRadTarget(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x18));
            var_a0 = var_s0;
            var_f12 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x1C);
            goto block_8;
        case 2:
            bevy_player_p18_gadget_glide_steer(arg0 + 0x2C0);
            break;
        case 3:
            UpdateAttachMotion(arg0 + 0x4C0);
            break;
        case 5:
            func_002046F0(arg0, M2C_FIELD(arg0, s32 *, 0x10DC));
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x1410($s1) */);
            temp_v1_2 = M2C_FIELD(arg0, void **, 0x150);
            M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
            temp_a0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf1 */);
            SetVectorCylind__FP6VECTORfff(temp_a0, M2C_FIELD(temp_v1_2, f32 *, 0x18) + 3.1415927f, M2C_FIELD(temp_v1_2, f32 *, 0x1C) * temp_a0 * M2C_FIELD(M2C_FIELD(arg0, void **, 0x1030), f32 *, 0x40), 0);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x190($s1) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x1b0($s1) */);
            var_a2 = M2C_FIELD(arg0, s32 *, 0x14E0);
            var_a1 = arg0 + 0x13E0;
block_24:
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($v0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($v0) */);
            M2C_ERROR(/* unknown instruction: vmul.xyzw $vf7, $vf3, $vf4 */);
            M2C_ERROR(/* unknown instruction: vmaxw.xyzw $vf8, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vmul.xyzw $vf6, $vf1, $vf4 */);
            M2C_ERROR(/* unknown instruction: vmul.xyzw $vf5, $vf2, $vf4 */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf7, $vf7y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf3, $vf8, $vf7z */);
            M2C_ERROR(/* unknown instruction: vaddax.y $acc, $vf6, $vf6x */);
            M2C_ERROR(/* unknown instruction: vmaddz.y $vf3, $vf8, $vf6z */);
            M2C_ERROR(/* unknown instruction: vaddax.z $acc, $vf5, $vf5x */);
            M2C_ERROR(/* unknown instruction: vmaddy.z $vf3, $vf8, $vf5y */);
            M2C_FIELD(arg0, s32 *, 0x1038) = -1;
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x190($s1) */);
            SolvePlainBlendWeights(arg0, var_a1, var_a2);
            break;
        case 6:
            if (M2C_FIELD(arg0, s32 *, 0x16B0) == 1) {
                temp_v1_3 = M2C_FIELD(arg0, void **, 0x150);
                temp_f2 = M2C_FIELD(temp_v1_3, f32 *, 0x1C);
                temp_f3 = M2C_FIELD(&D_FLT_002BC940, f32 *, 0) + (temp_f2 * (M2C_FIELD(&D_FLT_002BC940, f32 *, 4) + (temp_f2 * M2C_FIELD(&D_FLT_002BC940, f32 *, 8))));
                if (temp_f3 < M2C_FIELD(&g_2bbb60, f32 *, 0)) {
                    var_f21 = M2C_FIELD(&g_2bbb60, f32 *, 0);
                } else {
                    var_f21 = temp_f3;
                    if (M2C_FIELD(&g_2bbb60, f32 *, 4) < temp_f3) {
                        var_f21 = M2C_FIELD(&g_2bbb60, f32 *, 4);
                    }
                }
                temp_f2_2 = M2C_FIELD(temp_v1_3, f32 *, 0x1C);
                temp_f3_2 = M2C_FIELD(&D_FLT_002BC950, f32 *, 0) + (temp_f2_2 * (M2C_FIELD(&D_FLT_002BC950, f32 *, 4) + (temp_f2_2 * M2C_FIELD(&D_FLT_002BC950, f32 *, 8))));
                if (temp_f3_2 < M2C_FIELD(&g_2bbb60, f32 *, 0)) {
                    var_f20 = M2C_FIELD(&g_2bbb60, f32 *, 0);
                } else {
                    var_f20 = temp_f3_2;
                    if (M2C_FIELD(&g_2bbb60, f32 *, 4) < temp_f3_2) {
                        var_f20 = M2C_FIELD(&g_2bbb60, f32 *, 4);
                    }
                }
                temp_v0 = M2C_FIELD(arg0, void **, 0x150);
                if (M2C_FIELD(temp_v0, f32 *, 0x1C) > 0.0f) {
                    SetStepRadTarget(arg0, M2C_FIELD(arg0, f32 *, 0x1A8) + GLimitAbs__Fff(RadNormalize__Ff(&g_2bbb60, temp_v1_3, M2C_FIELD(temp_v0, f32 *, 0x18) - M2C_FIELD(arg0, f32 *, 0x1A8), M2C_FIELD(&g_2bbb60, f32 *, 0)), var_f20 * D_FLT_002BC960 * g_2dded4));
                }
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x1520($s1) */);
                M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                temp_a0_2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf1 */);
                SetVectorCylind__FP6VECTORfff(temp_a0_2, M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x18) + 3.1415927f, var_f21 * temp_a0_2 * M2C_FIELD(M2C_FIELD(arg0, void **, 0x1030), f32 *, 0x40), 0);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x190($s1) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x1b0($s1) */);
                var_a2 = M2C_FIELD(arg0, s32 *, 0x15F0);
                var_a1 = arg0 + 0x14F0;
                goto block_24;
            }
            break;
        case 10:
            temp_a1 = M2C_FIELD(arg0, void **, 0x1030);
            func_00204E38(arg0, temp_a1, M2C_FIELD(temp_a1, f32 *, 0x1C));
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf3, $vf1x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x190($s1) */);
            break;
        case 11:
            temp_a1_2 = M2C_FIELD(arg0, void **, 0x1030);
            func_00204E38(arg0, temp_a1_2, M2C_FIELD(temp_a1_2, f32 *, 0x1C));
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf3, $vf2x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x190($s1) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
            SetAsegaSpeed(M2C_FIELD(arg0, void **, 0x1030), M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x1C));
            SetStepRadTarget(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x18));
            break;
        case 14:
            temp_a1_3 = M2C_FIELD(arg0, void **, 0x1030);
            func_00204E38(arg0, temp_a1_3, M2C_FIELD(temp_a1_3, f32 *, 0x1C));
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf3, $vf1x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x190($s1) */);
            SetStepRadTarget(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x18));
            break;
        }
        func_00135EB0(arg0);
        UpdateZapPost(arg0 + 0xDF0);
    }
}

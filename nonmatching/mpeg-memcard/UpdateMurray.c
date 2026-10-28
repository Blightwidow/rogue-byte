#include "m2c_macros.h"

M2C_UNK BuildJtTargetList(M2C_UNK *, void *, M2C_UNK); /* extern */
s32 FAsegaGone(s32);                                /* extern */
s32 FPoxaPairInteracts(M2C_UNK *, s32, s32);        /* extern */
M2C_UNK MoveMurrayAttack(void *);                   /* extern */
M2C_UNK RecalcSwOxfFilterForObject(M2C_UNK *, void *); /* extern */
M2C_UNK ReleaseAsegaHandle(void *);                 /* extern */
M2C_UNK SetAsegaSpeed(void *, f32);                 /* extern */
M2C_UNK SetRunBlendU(void *, f32);                  /* extern */
M2C_UNK SetSmaMask(s32, s32);                       /* extern */
M2C_UNK SetStepRadTarget(void *, f32);              /* extern */
M2C_UNK UpdateAttachMotion(void *);                 /* extern */
M2C_UNK UpdateJt();                                 /* extern */
M2C_UNK UpdateMurrayActive(void *);                 /* extern */
M2C_UNK UpdateMurrayBinoc(void *);                  /* extern */
M2C_UNK UpdateMurrayStandOn(void *);                /* extern */
M2C_UNK UpdateRunBlendFootsteps(void *);            /* extern */
M2C_UNK UpdateZapPost(void *);                      /* extern */
M2C_UNK bevy_player_p18_gadget_glide_steer(void *); /* extern */
M2C_UNK func_0012D108(s32, s128);                   /* extern */
s32 func_001430C8(void *);                          /* extern */
M2C_UNK func_001B90B8(void *);                      /* extern */
M2C_UNK func_00204E38(void *, void *, f32);         /* extern */
extern M2C_UNK B_003DD490;
extern s128 D_002C08F0;
extern f32 D_FLT_002C08E4;
extern s128 RO_002A2DE0;
extern f32 g_2dded0;

void UpdateMurray(void *arg0) {
    f32 var_f12;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a2_2;
    u32 temp_v1;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_a2;
    void *var_a0;
    void *var_s0;

    UpdateJt();
    if (((u64) M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1) {
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x190C);
        if ((temp_a0 != 0) && (FAsegaGone(temp_a0) != 0)) {
            ReleaseAsegaHandle(arg0 + 0x190C);
        }
        BuildJtTargetList(&B_003DD490, arg0, 0xF8FA);
        UpdateMurrayBinoc(arg0);
        UpdateMurrayActive(arg0);
        temp_v1 = M2C_FIELD(arg0, u32 *, 0x13D0);
        switch (temp_v1) {
        case 0:
            SetSmaMask(M2C_FIELD(arg0, s32 *, 0x1034), func_001430C8(arg0));
            break;
        case 1:
            var_s0 = arg0 + 0x1320;
            SetStepRadTarget(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x18));
            var_f12 = 1.0f;
            var_a0 = var_s0;
block_9:
            SetRunBlendU(var_a0, var_f12);
            UpdateRunBlendFootsteps(var_s0);
            break;
        case 10:
            var_s0 = arg0 + 0x1540;
            SetStepRadTarget(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x18));
            var_a0 = var_s0;
            var_f12 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x1C);
            goto block_9;
        case 2:
            bevy_player_p18_gadget_glide_steer(arg0 + 0x2C0);
            break;
        case 13:
            UpdateAttachMotion(arg0 + 0x4C0);
            break;
        case 11:
            MoveMurrayAttack(arg0);
            break;
        case 12:
            func_001B90B8(arg0);
            break;
        case 17:
            temp_a1 = M2C_FIELD(arg0, void **, 0x1030);
            func_00204E38(arg0, temp_a1, M2C_FIELD(temp_a1, f32 *, 0x1C));
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf3, $vf1x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x190($s1) */);
            break;
        case 18:
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
        }
        UpdateMurrayStandOn(arg0);
        UpdateZapPost(arg0 + 0xDF0);
        temp_a2 = M2C_FIELD(arg0, void **, 0x1430);
        if ((temp_a2 != NULL) && ((M2C_FIELD(arg0, f32 *, 0x1434) + 0.1f) < g_2dded0)) {
            temp_a2_2 = M2C_FIELD(temp_a2, s32 *, 0xEC);
            if ((temp_a2_2 == 0) || (FPoxaPairInteracts(&B_003DD490, M2C_FIELD(arg0, s32 *, 0xEC), temp_a2_2) == 0)) {
                M2C_FIELD(arg0, void **, 0x1430) = NULL;
            }
            if (M2C_FIELD(arg0, void **, 0x1430) == NULL) {
                RecalcSwOxfFilterForObject(&B_003DD490, arg0);
            }
        }
        temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x1ACC);
        if (temp_a0_2 != 0) {
            if ((g_2dded0 - M2C_FIELD(arg0, f32 *, 0x1AC8)) < D_FLT_002C08E4) {
                func_0012D108(temp_a0_2, D_002C08F0);
            } else {
                func_0012D108(temp_a0_2, RO_002A2DE0);
            }
        }
    }
}

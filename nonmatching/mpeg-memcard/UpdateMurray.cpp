typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateMurray {
    /* 0x00 */ char pad0[0x50];
};                                                  /* size = 0x50 */
void BuildJtTargetList(M2C_UNK *, s8 *, M2C_UNK);
s32 FAsegaGone(s32);
s32 FPoxaPairInteracts(M2C_UNK *, s32, s32);
void MoveMurrayAttack(s8 *);
void RecalcSwOxfFilterForObject(M2C_UNK *, s8 *);
void ReleaseAsegaHandle(s8 *);
f32 SetAsegaSpeed(s8 *, f32);
void SetRunBlendU(s8 *, f32);
void SetSmaMask(s32, s32);
void SetStepRadTarget(s8 *, f32);
void UpdateAttachMotion(s8 *);
void UpdateJt();
void UpdateMurrayActive(s8 *);
void UpdateMurrayBinoc(s8 *);
void UpdateMurrayStandOn(s8 *);
void UpdateRunBlendFootsteps(s8 *);
void UpdateZapPost(s8 *);
void bevy_player_p18_gadget_glide_steer(s8 *);
void func_0012D108(s32, s128);
s32 func_001430C8(s8 *);
void func_001B90B8(s8 *);
s32 func_00204E38(s8 *, s8 *, f32);
extern M2C_UNK B_003DD490;
extern s128 D_002C08F0;
extern f32 D_FLT_002C08E4;
extern s128 RO_002A2DE0;
extern f32 g_2dded0;
void UpdateMurray(s8 *arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    f32 var_f12;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a2_2;
    u32 temp_v1;
    s8 *temp_a1;
    s8 *temp_a1_2;
    s8 *temp_a2;
    s8 *var_a0;
    s8 *var_s0;
    UpdateJt();
    if ((int)((u64) M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1) {
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
            SetStepRadTarget(arg0, M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), f32 *, 0x18));
            var_f12 = 1.0f;
            var_a0 = var_s0;
block_9:
            SetRunBlendU(var_a0, var_f12);
            UpdateRunBlendFootsteps(var_s0);
            break;
        case 10:
            var_s0 = arg0 + 0x1540;
            SetStepRadTarget(arg0, M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), f32 *, 0x18));
            var_a0 = var_s0;
            var_f12 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), f32 *, 0x1C);
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
            temp_a1 = M2C_FIELD(arg0, s8 **, 0x1030);
            asm volatile("qmtc2.ni %0, vf3" : : "r"(func_00204E38(arg0, temp_a1, M2C_FIELD(temp_a1, f32 *, 0x1C))));
            asm volatile("qmtc2.ni %0, vf1" : : "r"(0xBF800000));
            asm volatile("vmulx.xyzw vf2, vf3, vf1x");
            asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
            asm volatile("sqc2 vf2, 0x190(%0)" : : "r"(arg0));
            break;
        case 18:
            temp_a1_2 = M2C_FIELD(arg0, s8 **, 0x1030);
            asm volatile("qmtc2.ni %0, vf3" : : "r"(func_00204E38(arg0, temp_a1_2, M2C_FIELD(temp_a1_2, f32 *, 0x1C))));
            asm volatile("qmtc2.ni %0, vf2" : : "r"(0xBF800000));
            asm volatile("vmulx.xyzw vf1, vf3, vf2x");
            asm volatile("sqc2 vf1, 0x190(%0)" : : "r"(arg0));
            asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
            SetAsegaSpeed(M2C_FIELD(arg0, s8 **, 0x1030), M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), f32 *, 0x1C));
            SetStepRadTarget(arg0, M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x150), f32 *, 0x18));
            break;
        }
        UpdateMurrayStandOn(arg0);
        UpdateZapPost(arg0 + 0xDF0);
        temp_a2 = M2C_FIELD(arg0, s8 **, 0x1430);
        if ((temp_a2 != NULL) && ((M2C_FIELD(arg0, f32 *, 0x1434) + 0.1f) < g_2dded0)) {
            temp_a2_2 = M2C_FIELD(temp_a2, s32 *, 0xEC);
            if ((temp_a2_2 == 0) || (FPoxaPairInteracts(&B_003DD490, M2C_FIELD(arg0, s32 *, 0xEC), temp_a2_2) == 0)) {
                M2C_FIELD(arg0, s8 **, 0x1430) = NULL;
            }
            if (M2C_FIELD(arg0, s8 **, 0x1430) == NULL) {
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
}

typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateSw {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ s32 *sp4;                            /* inferred */
    /* 0x08 */ s32 sp8;                             /* inferred */
    /* 0x0C */ s8 **spC;                          /* inferred */
    /* 0x10 */ s8 *sp10;                          /* inferred */
    /* 0x14 */ s32 *sp14;                           /* inferred */
    /* 0x18 */ s32 sp18;                            /* inferred */
    /* 0x1C */ s8 **sp1C;                         /* inferred */
    /* 0x20 */ s32 sp20;                            /* inferred */
    /* 0x24 */ char pad24[0xAC];
};                                                  /* size = 0xD0 */
void AssignObstaclesToPathzones();
void ExpireSwWkrs(s8 *);
void HitFx_CheckExpiry(s32, s32);
void SolveSw(s8 *);
void UpdateAsega(s32, s32);
void UpdateCmLast(M2C_UNK *);
void UpdateSaas();
void UpdateSave__FP4SAVE(M2C_UNK *);
void UpdateSnd(M2C_UNK *);
void UpdateSwCallbacks(...);
void UpdateSwGuardsFrozen(s8 *, s32);
void UpdateSwHudBlots(s8 *);
void UpdateSwPaused(s8 *);
void UpdateVjoy(s8 *);
void func_00128148(M2C_UNK *);
void func_00147F40(s8 *);
extern M2C_UNK B_002DDF40;
extern M2C_UNK B_002E65E0;
extern M2C_UNK B_003DD040;
extern s8 **g_2dd2fc;
extern M2C_UNK g_2dd598;
extern M2C_UNK g_2dded0;
void UpdateSw(s8 *arg0) {
    s8 sp[0x20] __attribute__((aligned(16)));
    s32 *sp4;
    s32 sp8;
    s8 **spC;
    s8 *sp10;
    s32 *sp14;
    s32 sp18;
    s8 **sp1C;
    s32 sp20;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_v0_2;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a1_3;
    s8 *temp_a1;
    s8 *temp_s5;
    s8 *temp_v0;
    s8 *temp_v1;
    s8 *var_s0;
    UpdateSwCallbacks();
    func_00147F40(arg0);
    if (M2C_FIELD(&g_2dded0, f32 *, 4) <= 0.0f) {
        UpdateSwPaused(arg0);
    } else {
        var_s0 = M2C_FIELD(arg0, s8 **, 0x3EAC);
        temp_s5 = arg0 + 0x3FFC;
        if (var_s0 != NULL) {
            do {
                UpdateVjoy(var_s0);
                var_s0 = M2C_FIELD(var_s0, s8 **, 0x84);
            } while (var_s0 != NULL);
        }
        ExpireSwWkrs(arg0);
        var_a1 = 0;
        M2C_FIELD(arg0, s32 **, 0x3F1C) = &sp20;
        sp20 = 0;
        if (M2C_FIELD(arg0, s32 *, 0x3F14) > 0) {
            do {
                temp_v1 = (s8 *)(M2C_FIELD(arg0, s32 *, 0x3F20) + (var_a1 * 8));
                if (M2C_FIELD(temp_v1, s32 *, 0) & 2) {
                    temp_a1 = M2C_FIELD(temp_v1, s8 **, 4);
                    temp_v0 = M2C_FIELD(temp_a1, s8 **, 0xC);
                    M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, s8 *), 0x84)(temp_a1 + M2C_FIELD(temp_v0, s16 *, 0x80), temp_a1);
                }
                temp_v0_2 = sp20 + 1;
                var_a1 = temp_v0_2;
                sp20 = temp_v0_2;
            } while (var_a1 < M2C_FIELD(arg0, s32 *, 0x3F14));
        }
        M2C_FIELD(arg0, s32 **, 0x3F1C) = NULL;
        UpdateSwGuardsFrozen(arg0, var_a1);
        temp_a0 = M2C_FIELD((arg0 + 0x3D88), s32 *, 8);
        spC = g_2dd2fc;
        g_2dd2fc = (s8 **)(sp);
        temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x3D88);
        var_a1_2 = temp_v1_2;
        sp4 = (s32 *)(temp_v1_2 + temp_a0);
        sp8 = temp_a0;
        if (var_a1_2 != 0) {
            do {
                UpdateAsega(var_a1_2, var_a1_2);
                temp_a0_2 = *sp4;
                var_a1_2 = temp_a0_2;
                sp4 = (s32 *)(temp_a0_2 + sp8);
            } while (var_a1_2 != 0);
        }
        temp_a0_3 = M2C_FIELD(temp_s5, s32 *, 8);
        sp1C = g_2dd2fc;
        g_2dd2fc = &sp10;
        temp_v1_3 = M2C_FIELD(arg0, s32 *, 0x3FFC);
        sp10 = temp_s5;
        var_a1_3 = temp_v1_3;
        sp14 = (s32 *)(temp_v1_3 + temp_a0_3);
        sp18 = temp_a0_3;
        if (var_a1_3 != 0) {
            do {
                HitFx_CheckExpiry(var_a1_3, var_a1_3);
                temp_a0_4 = *sp14;
                var_a1_3 = temp_a0_4;
                sp14 = (s32 *)(temp_a0_4 + sp18);
            } while (var_a1_3 != 0);
        }
        UpdateSwCallbacks(arg0, var_a1_3);
        SolveSw(arg0);
        AssignObstaclesToPathzones();
        UpdateSaas();
        UpdateSwCallbacks(arg0);
        g_2dd2fc = spC;
    }
    UpdateSave__FP4SAVE(&B_002E65E0);
    UpdateSnd(&B_003DD040);
    if (M2C_FIELD(&g_2dded0, f32 *, 0x10) > 0.0f) {
        UpdateCmLast(&B_002DDF40);
    }
    UpdateSwHudBlots(arg0);
    func_00128148(&g_2dd598);
}
}

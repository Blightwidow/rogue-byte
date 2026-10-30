typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateSwTargetList {
    /* 0x00 */ f32 sp0;                             /* inferred */
    /* 0x04 */ f32 sp4;                             /* inferred */
    /* 0x08 */ char pad8[8];                        /* maybe part of sp4[3]? */
    /* 0x10 */ s128 sp10;                           /* inferred */
    /* 0x20 */ s8 *sp20;                          /* inferred */
    /* 0x24 */ s8 *sp24;                          /* inferred */
    /* 0x28 */ char pad28[0xB8];
};                                                  /* size = 0xE0 */
#define sp0 (*(f32 *)(sp + 0x00))
#define sp4 (*(f32 *)(sp + 0x04))
M2C_UNK FadeAloOut(s8 *, M2C_UNK);                /* extern */
f32 GSmooth__FfffP3SMPPf(M2C_UNK *, s8 *, f32, f32, f32); /* extern */
s32 PloSpawnTargetIndicator(s8 *, s32, s8 *);   /* extern */
M2C_UNK bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, s32, s32); /* extern */
M2C_UNK memmove(s8 *, s8 *, s32);               /* extern */
M2C_UNK qsort(s8 *, s32, M2C_UNK, M2C_UNK *);     /* extern */
extern M2C_UNK B_002DEB30;
extern s32 B_002E1E50;
extern M2C_UNK D_002BF718;
extern f32 D_FLT_002BF710;
extern f32 D_FLT_002BF714;
extern M2C_UNK func_00194F48;
extern M2C_UNK g_2dded0;
void UpdateSwTargetList(s8 *arg0, s8 *arg1, s32 arg2, s8 *arg3) {
    f32 saved_reg_f20;
    s8 sp[0x10] __attribute__((aligned(16)));
    s128 sp10;
    s8 *sp20;
    s8 *sp24;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f6;
    f32 var_f0;
    f32 var_f20;
    f32 var_f2;
    s32 temp_a1;
    s32 temp_a2_3;
    s32 temp_a2_6;
    s32 temp_a3;
    s32 temp_a3_2;
    s32 temp_v0_3;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s3;
    s32 var_s3_2;
    s32 var_s5;
    s32 var_v0;
    s8 *temp_a0;
    s8 *temp_a2;
    s8 *temp_a2_2;
    s8 *temp_a2_4;
    s8 *temp_a2_5;
    s8 *temp_s0;
    s8 *temp_s2;
    s8 *temp_t0;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v1;
    s8 *var_s0;
    var_f20 = saved_reg_f20;
    var_s5 = arg2;
    sp20 = arg1;
    if (var_s5 > 0) {
        qsort(arg3, var_s5, 0x30, &func_00194F48);
        if (M2C_FIELD(M2C_FIELD(arg3, s8 **, 4), s32 *, 0x14) != -1) {
            M2C_FIELD(arg3, s32 *, 0xC) = 1;
        }
    }
    var_s1 = M2C_FIELD(arg0, s32 *, 0x4678) - 1;
    sp24 = arg0 + 0x4680;
    if (var_s1 >= 0) {
        var_v0 = var_s1 * 0x30;
        do {
            var_s3 = var_s5;
            temp_s0 = arg0 + (var_v0 + 0x4680);
loop_29:
            var_s3 -= 1;
            if (var_s3 < 0) {
                temp_a0 = M2C_FIELD(temp_s0, s8 **, 0x10);
                if (temp_a0 != NULL) {
                    FadeAloOut(temp_a0, 0x3F000000);
                }
                memmove(temp_s0, temp_s0 + 0x30, (3 - var_s1) * 0x30);
                M2C_FIELD(arg0, s32 *, 0x4678) = (s32) (M2C_FIELD(arg0, s32 *, 0x4678) - 1);
            } else {
                temp_s2 = (var_s3 * 0x30) + arg3;
                if (M2C_FIELD(temp_s0, s32 *, 0) == M2C_FIELD(temp_s2, s32 *, 0)) {
                    M2C_FIELD(temp_s0, f32 *, 8) = (f32) M2C_FIELD(temp_s2, f32 *, 8);
                    if (M2C_FIELD(temp_s0, s8 **, 0x10) == NULL) {
                        M2C_FIELD(temp_s0, f32 *, 0x1C) = 0.0f;
                        M2C_FIELD(temp_s0, f32 *, 0x18) = (f32) M2C_FIELD(temp_s2, f32 *, 0x18);
                    } else {
                        temp_a2 = M2C_FIELD(temp_s2, s8 **, 4);
                        temp_v1 = M2C_FIELD(temp_a2, s8 **, 0x20);
                        var_s1_2 = M2C_FIELD(temp_v1, s32 (**)(s8 *, s8 *, s8 *), 0xC)(temp_a2 + M2C_FIELD(temp_v1, s16 *, 8), sp, temp_a2);
                        if (var_s1_2 != 0) {
                            var_f20 = sp4 - sp0;
                            temp_f1 = M2C_FIELD(temp_s0, f32 *, 0x18);
                            temp_f2 = M2C_FIELD(temp_s2, f32 *, 0x18) - temp_f1;
                            if ((var_f20 * 0.5f) < temp_f2) {
                                var_f2 = temp_f2 - var_f20;
                                goto block_17;
                            }
                            if (!(temp_f2 < (var_f20 * -0.5f))) {
                                var_s1_2 = 0;
                            } else {
                                var_f2 = temp_f2 + var_f20;
block_17:
                                M2C_FIELD(temp_s2, f32 *, 0x18) = (f32) (temp_f1 + var_f2);
                            }
                        }
                        if (B_002E1E50 != 0) {
                            temp_f2_2 = M2C_FIELD(temp_s0, f32 *, 0x1C);
                            temp_f6 = M2C_FIELD(temp_s0, f32 *, 0x18);
                            temp_f0 = temp_f2_2 + (M2C_FIELD(&g_2dded0, f32 *, 4) * (((M2C_FIELD(temp_s2, f32 *, 0x18) - temp_f6) * D_FLT_002BF710) + ((M2C_FIELD(temp_s2, f32 *, 0x1C) - temp_f2_2) * D_FLT_002BF714)));
                            M2C_FIELD(temp_s0, f32 *, 0x1C) = temp_f0;
                            M2C_FIELD(temp_s0, f32 *, 0x18) = (f32) (temp_f6 + (M2C_FIELD(&g_2dded0, f32 *, 4) * ((temp_f2_2 + temp_f0) * 0.5f)));
                        } else {
                            M2C_FIELD(temp_s0, f32 *, 0x18) = GSmooth__FfffP3SMPPf(&D_002BF718, temp_s0 + 0x1C, M2C_FIELD(temp_s0, f32 *, 0x18), M2C_FIELD(temp_s2, f32 *, 0x18), M2C_FIELD(&g_2dded0, f32 *, 4));
                        }
                        if (var_s1_2 != 0) {
                            temp_f1_2 = M2C_FIELD(temp_s0, f32 *, 0x18);
                            if (sp4 < temp_f1_2) {
                                var_f0 = temp_f1_2 - var_f20;
                                goto block_26;
                            }
                            if (temp_f1_2 < sp0) {
                                var_f0 = temp_f1_2 + var_f20;
block_26:
                                M2C_FIELD(temp_s0, f32 *, 0x18) = var_f0;
                            }
                        }
                        temp_t0 = M2C_FIELD(temp_s0, s8 **, 4);
                        temp_v0 = M2C_FIELD(temp_t0, s8 **, 0x20);
                        M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, s8 *, s128 *, M2C_UNK, f32), 0x1C)(temp_t0 + M2C_FIELD(temp_v0, s16 *, 0x18), sp20, &sp10, 0, M2C_FIELD(temp_s0, f32 *, 0x18));
                        temp_a2_2 = M2C_FIELD(temp_s0, s8 **, 0x10);
                        temp_v0_2 = M2C_FIELD(temp_a2_2, s8 **, 0xC);
                        M2C_FIELD(temp_v0_2, M2C_UNK (**)(s8 *, s128, s8 *), 0xEC)(temp_a2_2 + M2C_FIELD(temp_v0_2, s16 *, 0xE8), sp10, temp_a2_2);
                    }
                    temp_a2_3 = (var_s5 - var_s3) * 0x30;
                    var_s5 -= 1;
                    memmove(temp_s2, temp_s2 + 0x30, temp_a2_3 - 0x30);
                } else {
                    goto loop_29;
                }
            }
            var_s1 -= 1;
            var_v0 = var_s1 * 0x30;
        } while (var_s1 >= 0);
    }
    var_s0 = arg3;
    var_s3_2 = 0;
loop_36:
    if (var_s3_2 < var_s5) {
        temp_a1 = M2C_FIELD(sp20, s32 *, 0x9C4);
        if ((temp_a1 != 0) && (M2C_FIELD(var_s0, s32 *, 0xC) == 1)) {
            temp_v0_3 = PloSpawnTargetIndicator(arg0, temp_a1, var_s0);
            if (temp_v0_3 != 0) {
                M2C_FIELD(var_s0, s128 *, 0x10) = temp_v0_3;
                goto block_35;
            }
        } else {
block_35:
            temp_a3 = M2C_FIELD(arg0, s32 *, 0x4678);
            var_s3_2 += 1;
            temp_a3_2 = temp_a3 + 1;
            temp_a2_4 = (temp_a3 * 0x30) + arg0;
            M2C_FIELD(temp_a2_4, s128 *, 0x4680) = (s128) M2C_FIELD(var_s0, s128 *, 0);
            temp_a2_5 = temp_a2_4 + 0x4680;
            M2C_FIELD(temp_a2_5, s128 *, 0x10) = (s128) M2C_FIELD(var_s0, s128 *, 0x10);
            M2C_FIELD(temp_a2_5, s128 *, 0x20) = (s128) M2C_FIELD(var_s0, s128 *, 0x20);
            M2C_FIELD(arg0, s32 *, 0x4678) = temp_a3_2;
            temp_a2_6 = (s32) M2C_FIELD(var_s0, s128 *, 0);
            var_s0 += 0x30;
            bevy_camera_follow_activity(&B_002DEB30, 0x3D, temp_a2_6, temp_a3_2);
            goto loop_36;
        }
    }
    qsort(sp24, M2C_FIELD(arg0, s32 *, 0x4678), 0x30, &func_00194F48);
}
}

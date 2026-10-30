typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetJmpState {
    /* 0x00 */ s128 sp0;                            /* inferred */
    /* 0x10 */ char pad10[0x80];
};                                                  /* size = 0x90 */
M2C_UNK DecomposeCylind(s128, s8 *, s8 *, M2C_UNK); /* extern */
s32 FIsBasicDerivedFrom(s8 *, M2C_UNK);           /* extern */
s128 GetJmpLaunchVelocity(s8 *, u32);             /* extern */
s32 PosLoWorld(s8 *);                             /* extern */
M2C_UNK SetJmpBodyState(s8 *, M2C_UNK, s32);      /* extern */
M2C_UNK SetStepGravityRatio__FP4STEPf(s8 *, f32); /* extern */
s32 SetVectorCylind__FP6VECTORfff(s8 *, f32, f32, M2C_UNK); /* extern */
M2C_UNK func_00140C88(s8 *, s32);                 /* extern */
extern M2C_UNK D_002BF770;
extern f32 D_FLT_002BF730;
extern f32 D_FLT_002BF750;
extern f32 D_FLT_002BF754;
extern f32 D_FLT_002BF758;
extern M2C_UNK32 D_FLT_002BF75C;
extern f32 D_FLT_002BF760;
extern M2C_UNK32 D_FLT_002BF764;
extern f32 D_FLT_002BF768;
extern M2C_UNK32 D_FLT_002BF76C;
extern M2C_UNK g_2a2dc0;
extern f32 g_2dded0;
void SetJmpState(s8 *arg0, u32 arg1, s32 arg2, s32 arg3) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s128 sp0;
    M2C_UNK var_a1;
    s128 temp_v0_2;
    u32 temp_v1;
    s8 *temp_a0;
    s8 *temp_a0_2;
    s8 *temp_a0_3;
    s8 *temp_a2;
    s8 *temp_a2_2;
    s8 *temp_a2_3;
    s8 *temp_a2_4;
    s8 *temp_a2_5;
    s8 *temp_v0;
    s8 *temp_v0_3;
    s8 *temp_v0_4;
    s8 *temp_v0_5;
    s8 *temp_v0_6;
    if (arg1 != 6) {
        M2C_FIELD(arg0, u32 *, 4) = arg1;
    }
    M2C_FIELD(arg0, s32 *, 8) = arg2;
    temp_a2 = M2C_FIELD(arg0, s8 **, 0);
    temp_v0 = M2C_FIELD(temp_a2, s8 **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, M2C_UNK, s8 *), 0x2C4)(temp_a2 + M2C_FIELD(temp_v0, s16 *, 0x2C0), 1, temp_a2);
    if (arg1 != 6) {
        M2C_FIELD(arg0, s32 *, 0x40) = 0;
        M2C_FIELD(arg0, f32 *, 0x44) = (f32) g_2dded0;
        M2C_FIELD(arg0, f32 *, 0x4C) = (f32) g_2dded0;
        M2C_FIELD(arg0, f32 *, 0x48) = (f32) g_2dded0;
    }
    if (arg1 == 9) {
        temp_a0 = M2C_FIELD(arg0, s8 **, 0);
        M2C_FIELD(arg0, f32 *, 0x168) = (f32) M2C_FIELD(temp_a0, f32 *, 0x260);
        SetStepGravityRatio__FP4STEPf(temp_a0, D_FLT_002BF750);
    }
    temp_v0_2 = GetJmpLaunchVelocity(arg0, arg1);
    sp0 = temp_v0_2;
    temp_a2_2 = M2C_FIELD(arg0, s8 **, 0);
    temp_v0_3 = M2C_FIELD(temp_a2_2, s8 **, 0xC);
    s64 vu_1;
    asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(temp_v0_2));
    M2C_FIELD(temp_v0_3, M2C_UNK (**)(s8 *, M2C_UNK, s8 *), 0x11C)(temp_a2_2 + M2C_FIELD(temp_v0_3, s16 *, 0x118), vu_1, temp_a2_2);
    M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), f32 *, 0x131C) = (f32) g_2dded0;
    if (arg1 != 6) {
        M2C_FIELD(arg0, f32 *, 0x18) = (f32) g_2dded0;
    }
    switch (arg1) {
    case 0:
        SetJmpBodyState(arg0, 4, arg3);
        M2C_FIELD(arg0, s32 *, 0x28) = 1;
        M2C_FIELD(arg0, f32 *, 0x38) = 1.0f;
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
block_32:
        M2C_FIELD(arg0, M2C_UNK32 *, 0x34) = 0x3F800000;
        break;
    case 11:
        SetJmpBodyState(arg0, 4, arg3);
        M2C_FIELD(arg0, s32 *, 0x24) = 1;
        M2C_FIELD(arg0, f32 *, 0x38) = 1.0f;
        M2C_FIELD(arg0, s32 *, 0x28) = 0;
        goto block_32;
    case 3:
        temp_a0_2 = M2C_FIELD(arg0, s8 **, 0);
        if (M2C_FIELD(M2C_FIELD(temp_a0_2, s8 **, 0x150), f32 *, 0x1C) < 0.2f) {
            M2C_FIELD(arg0, s32 *, 0x40) = 3;
            temp_a2_3 = M2C_FIELD(arg0, s8 **, 0);
            asm volatile("qmtc2.ni %0, vf2" : : "r"(SetVectorCylind__FP6VECTORfff(temp_a0_2, M2C_FIELD(temp_a0_2, f32 *, 0x1A8), D_FLT_002BF754, 0)));
            asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
            temp_v0_4 = M2C_FIELD(temp_a2_3, s8 **, 0xC);
            asm volatile("vadd.xyzw vf1, vf1, vf2");
            s32 vu_2;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
            M2C_FIELD(temp_v0_4, M2C_UNK (**)(s8 *, M2C_UNK, s8 *), 0x11C)(temp_a2_3 + M2C_FIELD(temp_v0_4, s16 *, 0x118), vu_2, temp_a2_3);
        }
        SetJmpBodyState(arg0, 0, arg3);
        M2C_FIELD(arg0, s32 *, 0x28) = 1;
        M2C_FIELD(arg0, M2C_UNK32 *, 0x34) = 0x3F800000;
        M2C_FIELD(arg0, f32 *, 0x38) = 0.6f;
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        break;
    case 1:
    case 2:
    case 18:
        SetJmpBodyState(arg0, 0, arg3);
        M2C_FIELD(arg0, s32 *, 0x28) = 1;
        M2C_FIELD(arg0, f32 *, 0x38) = 1.0f;
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        goto block_32;
    case 9:
        SetJmpBodyState(arg0, 0, arg3);
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        M2C_FIELD(arg0, s32 *, 0x28) = 1;
        func_00140C88(M2C_FIELD(arg0, s8 **, 0), M2C_FIELD(arg0, s32 *, 0x16C));
        M2C_FIELD(arg0, f32 *, 0x38) = (f32) D_FLT_002BF758;
        M2C_FIELD(arg0, M2C_UNK32 *, 0x34) = (M2C_UNK32) D_FLT_002BF75C;
        M2C_FIELD(arg0, s32 *, 0x174) = 1;
        break;
    case 7:
        SetJmpBodyState(arg0, 7, arg3);
        M2C_FIELD(arg0, s32 *, 0x28) = 1;
        M2C_FIELD(arg0, M2C_UNK32 *, 0x34) = 0x3F800000;
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        M2C_FIELD(arg0, f32 *, 0x38) = 1.0f;
        break;
    case 8:
        SetJmpBodyState(arg0, 5, arg3);
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        M2C_FIELD(arg0, M2C_UNK32 *, 0x34) = 0x3F800000;
        M2C_FIELD(arg0, f32 *, 0x38) = 1.0f;
        M2C_FIELD(arg0, s32 *, 0x28) = 1;
        DecomposeCylind(sp0, arg0 + 0xB0, arg0 + 0xB8, 0);
        M2C_FIELD(arg0, f32 *, 0xB4) = 1.0f;
        break;
    case 6:
        temp_v1 = M2C_FIELD(arg0, u32 *, 4);
        var_a1 = 2;
        if ((s32) temp_v1 < 0xF) {
            var_a1 = ((s32) temp_v1 >= 0xD) ? 3 : 2;
        }
        SetJmpBodyState(arg0, var_a1, arg3);
        break;
    case 14:
        SetJmpBodyState(arg0, 1, arg3);
        M2C_FIELD(arg0, s32 *, 0x28) = 1;
        M2C_FIELD(arg0, M2C_UNK32 *, 0x34) = (M2C_UNK32) D_FLT_002BF764;
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        M2C_FIELD(arg0, f32 *, 0x38) = (f32) D_FLT_002BF760;
        temp_a0_3 = M2C_FIELD(arg0, s8 **, 0);
        if (M2C_FIELD(M2C_FIELD(temp_a0_3, s8 **, 0x150), f32 *, 0x1C) < 0.2f) {
            M2C_FIELD(arg0, s32 *, 0x40) = 3;
            temp_a2_4 = M2C_FIELD(arg0, s8 **, 0);
            asm volatile("qmtc2.ni %0, vf1" : : "r"(SetVectorCylind__FP6VECTORfff(temp_a0_3, M2C_FIELD(M2C_FIELD(temp_a0_3, s8 **, 0x150), f32 *, 0x18), D_FLT_002BF730 * D_FLT_002BF760, 0)));
            asm volatile("lqc2 vf4, (%0)" : : "r"(sp));
            temp_v0_5 = M2C_FIELD(temp_a2_4, s8 **, 0xC);
            asm volatile("vadd.xyzw vf4, vf4, vf1");
            s32 vu_3;
            asm volatile("qmfc2.ni %0, vf4" : "=r"(vu_3));
            M2C_FIELD(temp_v0_5, M2C_UNK (**)(s8 *, M2C_UNK, s8 *), 0x11C)(temp_a2_4 + M2C_FIELD(temp_v0_5, s16 *, 0x118), vu_3, temp_a2_4);
        }
        break;
    case 13:
        SetJmpBodyState(arg0, 1, arg3);
        M2C_FIELD(arg0, s32 *, 0x28) = 1;
        M2C_FIELD(arg0, f32 *, 0x38) = (f32) D_FLT_002BF768;
        M2C_FIELD(arg0, M2C_UNK32 *, 0x34) = (M2C_UNK32) D_FLT_002BF76C;
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        break;
    case 10:
        M2C_FIELD(arg0, s32 *, 0x40) = -1;
        SetJmpBodyState(arg0, 0x15, arg3);
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        M2C_FIELD(arg0, s32 *, 0x28) = 0;
        M2C_FIELD(arg0, M2C_UNK32 *, 0x34) = 0;
        M2C_FIELD(arg0, f32 *, 0x38) = 0.0f;
        break;
    case 12:
        SetJmpBodyState(arg0, 1, arg3);
        M2C_FIELD(arg0, s32 *, 0x40) = 3;
        M2C_FIELD(arg0, s32 *, 0x28) = 1;
        M2C_FIELD(arg0, f32 *, 0x38) = 1.0f;
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        goto block_32;
    case 16:
        SetJmpBodyState(arg0, 4, arg3);
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        M2C_FIELD(arg0, f32 *, 0x38) = 1.0f;
        M2C_FIELD(arg0, s32 *, 0x28) = 0;
        goto block_32;
    case 15:
        SetJmpBodyState(arg0, 0, arg3);
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        M2C_FIELD(arg0, f32 *, 0x38) = 1.0f;
        M2C_FIELD(arg0, s32 *, 0x28) = 0;
        goto block_32;
    case 17:
        if (M2C_FIELD(arg0, s32 *, 0x1C) == -1) {
            temp_a2_5 = M2C_FIELD(arg0, s8 **, 0);
            asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(sp));
            asm volatile("lqc2 vf1, (%0)" : : "r"(&g_2a2dc0));
            temp_v0_6 = M2C_FIELD(temp_a2_5, s8 **, 0xC);
            asm volatile("vmul.xyz vf2, vf4, vf1");
            asm volatile("vaddw.x vf3, vf0, vf0w");
            asm volatile("vadday.x ACC, vf2, vf2y");
            asm volatile("vmaddz.x vf2, vf3, vf2z");
            asm volatile("vmulx.xyzw vf2, vf1, vf2x");
            asm volatile("lqc2 vf3, (%0)" : : "r"(&D_002BF770));
            asm volatile("vsub.xyzw vf2, vf4, vf2");
            asm volatile("vadd.xyzw vf1, vf2, vf3");
            s32 vu_4;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_4));
            M2C_FIELD(temp_v0_6, M2C_UNK (**)(s8 *, M2C_UNK, s8 *), 0x11C)(temp_a2_5 + M2C_FIELD(temp_v0_6, s16 *, 0x118), vu_4, temp_a2_5);
            M2C_FIELD(arg0, s32 *, 0x28) = 1;
        }
        SetJmpBodyState(arg0, 0x16, 0);
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
        M2C_FIELD(arg0, f32 *, 0x38) = 1.0f;
        M2C_FIELD(arg0, s32 *, 0x2C) = 0;
        goto block_32;
    }
    if (arg1 != 6) {
        if (arg1 != 0x11) {
            M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
        }
        if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s8 **, 0), 0x35) != 0) {
            M2C_FIELD(M2C_FIELD(arg0, s8 **, 0), s32 *, 0x18F0) = -1;
        }
        s64 vu_5;
        asm volatile("pextuw %0, %1, %2" : "=r"(vu_5) : "r"(0), "r"(PosLoWorld(M2C_FIELD(arg0, s8 **, 0))));
        M2C_FIELD(arg0, f32 *, 0x3C) = vu_5;
    }
}
}

typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ActivateCptn__FP4CPTNPv {
    /* 0x000 */ char pad0[0x50];
    /* 0x050 */ s128 sp50;                          /* inferred */
    /* 0x060 */ M2C_UNK sp60;                       /* inferred */
    /* 0x060 */ char pad60[0x20];
    /* 0x080 */ s8 *sp80;                         /* inferred */
    /* 0x084 */ char pad84[0xAC];
};                                                  /* size = 0x130 */
f32 ActivateCplcy();
void DecomposeSphere(M2C_UNK, s8 *, s8 *, s8 *);
s32 FIsBasicDerivedFrom(s32, s32);
s32 FIsCidDerivedFrom(s32, s32);
void FindCrvClosestPointAll(s32, s128, M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, s8 *);
void GetCmCpdefi__FP2CMP2SOfP6CPDEFI(M2C_UNK *, s32, s8 *);
void GetTnfnNose__FP4TNFNP6CPDEFIP6VECTORP2TN(s32 *, s8 *, s128 *, s8 *);
s32 SetResetFlag__FP2CM(s8 *);
s32 SetVectorSphere__FP6VECTORfff(f32, f32, f32);
f32 UpdateCptnClosestPoint(s8 *, s8 *);
void UpdateStepXfWorld__FP4STEP(s32 *);
extern M2C_UNK B_002DDF40;
extern M2C_UNK B_002DE220;
extern s32 D_002C4120;
extern f32 D_FLT_002C41DC;
extern f32 g_2dded0;
void ActivateCptn__FP4CPTNPv(s8 *arg0, s32 arg1, s8 *arg2) {
    s8 sp[0x70] __attribute__((aligned(16)));
    s128 sp50;
    M2C_UNK sp60;
    s8 *sp80;
    f32 temp_f0;
    f32 temp_f1;
    s32 *temp_s0;
    s32 *var_s2;
    s32 temp_a0;
    s32 var_s3;
    s32 var_s4;
    s8 *temp_a6;
    s8 *temp_s0_2;
    s8 *temp_v0;
    s8 *temp_v1;
    s8 *var_fp;
    s8 *var_s7;
    ActivateCplcy();
    M2C_FIELD(arg0, s8 **, 0x10) = arg2;
    if (arg2 == NULL) {
        var_fp = arg0 + 0x1C;
        M2C_FIELD(arg0, s32 **, 0x14) = &D_002C4120;
        var_s7 = arg0 + 0x20;
        sp80 = arg0 + 0x18;
    } else {
        var_s3 = 1;
        var_s2 = M2C_FIELD(arg2, s32 **, 0x114);
        sp80 = arg0 + 0x18;
        var_fp = arg0 + 0x1C;
        var_s7 = arg0 + 0x20;
        if (M2C_FIELD(arg2, s32 *, 0x110) > 1) {
            var_s4 = 0x90;
            do {
                temp_s0 = (s32 *)(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s32 *, 0x114) + var_s4);
                if (FIsBasicDerivedFrom(arg1, *temp_s0) != 0) {
                    var_s2 = (FIsCidDerivedFrom(*temp_s0, *var_s2) != 0) ? temp_s0 : var_s2;
                }
                var_s3 += 1;
                var_s4 += 0x90;
            } while (var_s3 < M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s32 *, 0x110));
        }
        M2C_FIELD(arg0, s32 **, 0x14) = var_s2;
    }
    M2C_FIELD(arg0, s32 *, 0x38) = 1;
    UpdateStepXfWorld__FP4STEP(M2C_FIELD(arg0, s32 **, 0x14));
    GetCmCpdefi__FP2CMP2SOfP6CPDEFI(&B_002DDF40, arg1, sp);
    GetTnfnNose__FP4TNFNP6CPDEFIP6VECTORP2TN(M2C_FIELD(arg0, s32 **, 0x14), sp, &sp50, NULL);
    temp_a6 = M2C_FIELD(arg0, s8 **, 0x10);
    if (temp_a6 != NULL) {
        temp_a0 = M2C_FIELD(temp_a6, s32 *, 0x10C);
        if (temp_a0 != 0) {
            FindCrvClosestPointAll(temp_a0, sp50, 0, &sp60, 0, 0, temp_a6 + 0x140);
        } else if (M2C_FIELD(temp_a6, s32 *, 0x12C) != 0) {
            UpdateCptnClosestPoint(arg0, sp);
        }
        GetTnfnNose__FP4TNFNP6CPDEFIP6VECTORP2TN(M2C_FIELD(arg0, s32 **, 0x14), sp, &sp50, M2C_FIELD(arg0, s8 **, 0x10));
    }
    asm volatile("lqc2 vf2, 0x50(%0)" : : "r"(sp));
    asm volatile("lqc2 vf1, (%0)" : : "r"(&B_002DE220));
    temp_s0_2 = (s8 *)(&B_002DE220 - 0x2E0);
    asm volatile("vadd.xyzw vf3, vf2, vf1");
    asm volatile("sqc2 vf3, 0x70(%0)" : : "r"(sp));
    asm volatile("lqc2 vf2, -0x250(%0)" : : "r"(&B_002DE220));
    asm volatile("vsub.xyzw vf3, vf2, vf3");
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_1));
    DecomposeSphere(vu_1, sp80, var_fp, var_s7);
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x20) - M2C_FIELD(temp_s0_2, f32 *, 0x4C);
    M2C_FIELD(arg0, f32 *, 0x20) = temp_f0;
    asm volatile("lqc2 vf2, 0x70(%0)" : : "r"(sp));
    asm volatile("qmtc2.ni %0, vf3" : : "r"(SetVectorSphere__FP6VECTORfff(M2C_FIELD(arg0, f32 *, 0x18), M2C_FIELD(arg0, f32 *, 0x1C), temp_f0)));
    temp_v1 = M2C_FIELD(arg0, s8 **, 0x10);
    asm volatile("vadd.xyzw vf1, vf2, vf3");
    asm volatile("sqc2 vf1, 0x70(%0)" : : "r"(arg0));
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    M2C_FIELD(arg0, f32 *, 0x24) = (f32) M2C_FIELD(M2C_FIELD(arg0, s32 **, 0x14), f32 *, 0x5C);
    if (temp_v1 != NULL) {
        if (M2C_FIELD(temp_v1, s32 *, 0x184) != 0) {
            SetResetFlag__FP2CM(temp_s0_2);
        }
    }
    M2C_FIELD(arg0, f32 *, 0x80) = (f32) g_2dded0;
    temp_v0 = M2C_FIELD(arg0, s8 **, 0x10);
    M2C_FIELD(arg0, f32 *, 0x60) = (f32) g_2dded0;
    M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    M2C_FIELD(arg0, f32 *, 0x48) = (f32) (g_2dded0 - D_FLT_002C41DC);
    if (temp_v0 != NULL) {
        temp_f1 = M2C_FIELD(temp_v0, f32 *, 0x188);
        if (temp_f1 != 0.0f) {
            M2C_FIELD(&B_002DDF40, f32 *, 0x24) = temp_f1;
        }
    }
}
}

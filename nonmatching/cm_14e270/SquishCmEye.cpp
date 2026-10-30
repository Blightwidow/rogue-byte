typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SquishCmEye {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ M2C_UNK sp10;                       /* inferred */
    /* 0x010 */ char pad10[0xBF0];
    /* 0xC00 */ M2C_UNK spC00;                      /* inferred */
    /* 0xC00 */ char padC00[0x10];
    /* 0xC10 */ s32 spC10;                          /* inferred */
    /* 0xC14 */ char padC14[0xC];                   /* maybe part of spC10[4]? */
    /* 0xC20 */ s32 spC20;                          /* inferred */
    /* 0xC24 */ f32 (*spC24)(s32, M2C_UNK, s128, s8 *); /* inferred */
    /* 0xC28 */ char padC28[8];                     /* maybe part of spC24[3]? */
    /* 0xC30 */ s128 spC30;                         /* inferred */
    /* 0xC40 */ s128 spC40;                         /* inferred */
    /* 0xC50 */ char padC50[0xC0];
};                                                  /* size = 0xD10 */
#define spC40 (*(s128 *)(sp + 0xC40))
M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
s32 CsbiIntersectSphereBsp__FP6VECTORfiP3BSPT3P4GEOMiP3SBI(M2C_UNK, s8 *, s32, M2C_UNK, M2C_UNK, s32, s8 *, f32); /* extern */
s32 LimitVectorLength__FP6VECTORfT0(M2C_UNK, f32);  /* extern */
f32 *PvAllocStackImpl__Fi(s32 *);                   /* extern */
M2C_UNK SolveInequalities(s32, f32 *, f32 *, f32 *, f32); /* extern */
extern f32 D_FLT_002BD8D4;
s128 SquishCmEye(s32 arg0, s32 arg1, s8 **arg2, f32 (*arg3)(s32, M2C_UNK, s128, s8 *), s32 arg4, s128 arg5, f32 fparg0, f32 fparg1) {
    s8 sp[0x100] __attribute__((aligned(16)));
    M2C_UNK sp10;
    M2C_UNK spC00;
    s32 spC10;
    s32 spC20;
    f32 (*spC24)(s32, M2C_UNK, s128, s8 *);
    s128 spC30;
    M2C_UNK *var_a0;
    M2C_UNK *var_v0;
    M2C_UNK temp_s6;
    f32 *temp_s1;
    f32 *temp_v0_2;
    f32 *temp_v0_3;
    f32 *var_s4;
    f32 *var_s4_2;
    f32 *var_s4_3;
    f32 temp_f0;
    s32 temp_a2;
    s32 temp_s2;
    s32 temp_v1;
    s32 var_s0;
    s32 var_s3;
    s32 var_s3_2;
    s32 var_s3_3;
    s32 var_s5;
    s32 var_v1;
    s8 **var_s1;
    s8 *temp_a1;
    s8 *temp_a3;
    s8 *temp_v0;
    s8 *var_s0_2;
    var_s5 = 0;
    s64 vu_1;
    asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(arg4));
    temp_s6 = vu_1;
    spC20 = arg0;
    spC24 = arg3;
    spC30 = arg5;
    if (arg1 > 0) {
        var_s1 = arg2;
        var_s0 = arg1;
        do {
            temp_v0 = *var_s1;
            temp_a1 = temp_v0;
            temp_a2 = M2C_FIELD(temp_v0, s32 *, 0x70) * 0xC;
            temp_v1 = M2C_FIELD(temp_v0, s32 *, 0x74);
            var_s1 += 4;
            var_s0 -= 1;
            s64 vu_2;
            asm volatile("por %0, %1, %2" : "=r"(vu_2) : "r"(0), "r"(temp_s6));
            var_s5 += CsbiIntersectSphereBsp__FP6VECTORfiP3BSPT3P4GEOMiP3SBI(vu_2, temp_a1, temp_v1 + temp_a2, 0, 0, 0x40 - var_s5, (var_s5 * 0x30) + sp, fparg0);
        } while (var_s0 != 0);
    }
    if (var_s5 == 0) {
        return spC30;
    }
    CStackFrame_Construct(&spC00);
    temp_s2 = var_s5 * 4;
    asm volatile("vsub.xyzw vf1, vf0, vf0");
    asm volatile("sqc2 vf1, 0xc50(%0)" : : "r"(sp));
    var_s3 = 0;
    spC10 = var_s5 * var_s5 * 4;
    M2C_FIELD(&spC10, s32 *, 4) = 0x10;
    temp_v0_2 = PvAllocStackImpl__Fi(&spC10);
    spC10 = temp_s2;
    M2C_FIELD(&spC10, s32 *, 4) = 0x10;
    temp_v0_3 = PvAllocStackImpl__Fi(&spC10);
    var_s4 = temp_v0_2;
    spC10 = temp_s2;
    M2C_FIELD(&spC10, s32 *, 4) = 0x10;
    temp_s1 = PvAllocStackImpl__Fi(&spC10);
    if (var_s5 > 0) {
        do {
            if (var_s5 > 0) {
                var_a0 = &sp10;
                var_v1 = var_s5;
                do {
                    asm volatile("lqc2 vf1, (%0)" : : "r"(var_a0));
                    var_v1 -= 1;
                    asm volatile("lqc2 vf2, (%0)" : : "r"((var_s3 * 0x30) + sp + 0x10));
                    var_a0 += 0x30;
                    asm volatile("vmul.xyz vf2, vf2, vf1");
                    asm volatile("vaddw.x vf3, vf0, vf0w");
                    asm volatile("vadday.x ACC, vf2, vf2y");
                    asm volatile("vmaddz.x vf2, vf3, vf2z");
                    s32 vu_3;
                    asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_3));
                    *var_s4 = vu_3;
                    var_s4 += 4;
                } while (var_v1 != 0);
            }
            var_s3 += 1;
        } while (var_s3 < var_s5);
    }
    var_s4_2 = temp_v0_3;
    if (var_s5 > 0) {
        var_s0_2 = sp;
        var_s3_2 = var_s5;
        do {
            temp_a3 = var_s0_2;
            var_s0_2 += 0x30;
            var_s3_2 -= 1;
            s64 vu_4;
            asm volatile("por %0, %1, %2" : "=r"(vu_4) : "r"(0), "r"(temp_s6));
            *var_s4_2 = spC24(spC20, vu_4, spC30, temp_a3);
            var_s4_2 += 4;
        } while (var_s3_2 != 0);
    }
    var_s4_3 = temp_s1;
    SolveInequalities(var_s5, temp_v0_2, temp_v0_3, temp_s1, D_FLT_002BD8D4 * fparg1);
    asm volatile("lqc2 vf3, 0xc50(%0)" : : "r"(sp));
    if (var_s5 > 0) {
        var_s3_3 = var_s5;
        var_v0 = &sp10;
        do {
            temp_f0 = *var_s4_3;
            var_s3_3 -= 1;
            var_s4_3 += 4;
            asm volatile("qmtc2.ni %0, vf2" : : "r"(temp_f0));
            asm volatile("sqc2 vf2, 0xc10(%0)" : : "r"(sp));
            asm volatile("lqc2 vf1, (%0)" : : "r"(var_v0));
            asm volatile("vadda.xyzw ACC, vf0, vf3");
            asm volatile("vmaddx.xyzw vf3, vf1, vf2x");
            var_v0 += 0x30;
        } while (var_s3_3 != 0);
    }
    s32 vu_5;
    asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_5));
    asm volatile("qmtc2.ni %0, vf2" : : "r"(LimitVectorLength__FP6VECTORfT0(vu_5, fparg1)));
    asm volatile("lqc2 vf1, 0xc30(%0)" : : "r"(sp));
    asm volatile("vadd.xyzw vf2, vf1, vf2");
    asm volatile("sqc2 vf2, 0xc40(%0)" : : "r"(sp));
    CStackFrame_Destructor(&spC00, 2);
    return spC40;
}
}

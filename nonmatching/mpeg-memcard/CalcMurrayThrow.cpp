typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_CalcMurrayThrow {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ s128 sp20;                           /* inferred */
    /* 0x30 */ s128 sp30;                           /* inferred */
    /* 0x40 */ char pad40[0xA0];
};                                                  /* size = 0xE0 */
s32 CSolveQuadratic__FfffPf(s8 *, f32, M2C_UNK, f32); /* extern */
s128 ConvertXfVec(M2C_UNK, s32, s128);              /* extern */
M2C_UNK SeekAsega(s8 *, M2C_UNK, f32, f32);       /* extern */
extern f32 D_FLT_002C09C8;
extern M2C_UNK g_2a2dc0;
void CalcMurrayThrow(s8 *arg0, s32 arg1, f32 *arg2, f32 *arg3, s128 *arg4, s32 arg5) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s128 sp20;
    s128 sp30;
    M2C_UNK temp_s1_2;
    M2C_UNK temp_s3;
    f32 temp_f0;
    f32 temp_f13;
    f32 temp_f1;
    f32 var_f20;
    s128 temp_s2;
    s128 temp_v1_3;
    s32 temp_s1;
    s32 temp_v0_2;
    s32 temp_v1;
    s8 *temp_a0;
    s8 *temp_v0;
    s8 *temp_v1_2;
    s64 vu_1;
    asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(arg1));
    temp_s3 = vu_1;
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x144C);
    switch (temp_v1) {                              /* irregular */
    case 0:
        asm volatile("qmtc2.ni %0, vf2" : : "r"(0x451C4000));
        asm volatile("lqc2 vf1, (%0)" : : "r"(&g_2a2dc0));
        asm volatile("vmulx.xyzw vf3, vf1, vf2x");
        temp_s1 = M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x13F0), s8 **, 0x180), s8 **, 0x58), s32 *, 0xA0);
        asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
        s32 vu_2;
        asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_2));
        sp20 = ConvertXfVec(0, temp_s1, vu_2);
        asm volatile("qmtc2.ni %0, vf2" : : "r"(0xC4FA0000));
        asm volatile("lqc2 vf1, (%0)" : : "r"(&g_2a2dc0));
        asm volatile("vmulx.xyzw vf3, vf1, vf2x");
        asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
        s32 vu_3;
        asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_3));
        asm volatile("qmtc2.ni %0, vf2" : : "r"(ConvertXfVec(0, temp_s1, vu_3)));
        break;
    case 1:
        temp_v1_2 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x13F0), s8 **, 0x180);
        temp_v0 = M2C_FIELD(temp_v1_2, s8 **, 0x58);
        temp_v1_3 = M2C_FIELD(temp_v0, s128 *, 0xB0);
        temp_s2 = M2C_FIELD(temp_v0, s128 *, 0x30);
        sp30 = temp_v1_3;
        s64 vu_4;
        asm volatile("por %0, %1, %2" : "=r"(vu_4) : "r"(0), "r"(ConvertXfVec(0, M2C_FIELD(temp_v0, s32 *, 0xA0), M2C_FIELD(M2C_FIELD(temp_v1_2, s8 **, 0xE8), s128 *, 0x80))));
        temp_s1_2 = vu_4;
        s64 vu_5;
        asm volatile("pextuw %0, %1, %2" : "=r"(vu_5) : "r"(0), "r"(temp_s3));
        s64 vu_6;
        asm volatile("pextuw %0, %1, %2" : "=r"(vu_6) : "r"(0), "r"(temp_s2));
        s64 vu_7;
        asm volatile("pextuw %0, %1, %0" : "=r"(vu_7) : "r"(0), "r"(temp_v1_3));
        s64 vu_8;
        asm volatile("pextuw %0, %1, %2" : "=r"(vu_8) : "r"(0), "r"(temp_s1_2));
        temp_v0_2 = CSolveQuadratic__FfffPf(sp, vu_8 * 0.5f, vu_7, vu_6 - vu_5);
        if (temp_v0_2 == 0) {
            var_f20 = D_FLT_002C09C8;
        } else {
            temp_f0 = *(sp + ((temp_v0_2 - 1) * 4));
            temp_f1 = *arg3;
            if (temp_f0 < D_FLT_002C09C8) {
                var_f20 = D_FLT_002C09C8;
            } else {
                var_f20 = temp_f0;
                if (temp_f1 < temp_f0) {
                    var_f20 = temp_f1;
                }
            }
        }
        temp_a0 = M2C_FIELD(arg0, s8 **, 0x1030);
        temp_f13 = M2C_FIELD(temp_a0, f32 *, 0x40);
        SeekAsega(temp_a0, 0, *arg2 - (var_f20 * temp_f13), temp_f13);
        asm volatile("qmtc2.ni %0, vf3" : : "r"(temp_s1_2));
        asm volatile("qmtc2.ni %0, vf1" : : "r"(var_f20));
        asm volatile("lqc2 vf2, 0x30(%0)" : : "r"(sp));
        asm volatile("vadda.xyzw ACC, vf0, vf2");
        asm volatile("vmaddx.xyzw vf4, vf3, vf1x");
        asm volatile("lqc2 vf5, 0x30(%0)" : : "r"(sp));
        asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(sp));
        asm volatile("vadd.xyzw vf2, vf5, vf4");
        asm volatile("qmtc2.ni %0, vf5" : : "r"(temp_s2));
        *arg3 = var_f20;
        asm volatile("qmtc2.ni %0, vf3" : : "r"(var_f20 * 0.5f));
        asm volatile("vadda.xyzw ACC, vf0, vf5");
        asm volatile("vmaddx.xyzw vf2, vf2, vf3x");
        asm volatile("sqc2 vf3, 0x10(%0)" : : "r"(sp));
        asm volatile("qmtc2.ni %0, vf3" : : "r"(temp_s3));
        asm volatile("vsub.xyzw vf2, vf3, vf2");
        asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(sp));
        asm volatile("vdiv Q, vf0w, vf1x");
        asm volatile("vwaitq");
        asm volatile("vmulq.xyzw vf1, vf2, Q");
        asm volatile("lqc2 vf5, 0x30(%0)" : : "r"(sp));
        asm volatile("vadd.xyzw vf5, vf5, vf1");
        asm volatile("vadd.xyzw vf2, vf4, vf1");
        asm volatile("sqc2 vf5, 0x20(%0)" : : "r"(sp));
        break;
    }
    *arg4 = sp20;
    asm volatile("sqc2 vf2, (%0)" : : "r"(arg5));
}
}

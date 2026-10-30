typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetSoAngularVelocityVec {
    /* 0x000 */ char pad0[0x60];
    /* 0x060 */ M2C_UNK sp60;                       /* inferred */
    /* 0x060 */ char pad60[0x60];
    /* 0x0C0 */ s128 spC0;                          /* inferred */
    /* 0x0D0 */ s128 spD0;                          /* inferred */
    /* 0x0E0 */ char padE0[0x40];
};                                                  /* size = 0x120 */
s32 ConvertXfVec(M2C_UNK, s32, M2C_UNK);
s32 FXfKindHasVelocity(void);
void InvertMatrix3(M2C_UNK *, s8 *);
void NormalizeRotateMatrix3__FP7MATRIX3(s8 *, s128, s128, s128);
void SetXfKind(s8 *, s8 *, M2C_UNK);
void WakeXf(s8 *, s8 *);
void func_001F4BF8(s8 *);
void func_001F5078(s8 *);
void func_001F8668(s8 *, M2C_UNK);
void SetSoAngularVelocityVec(s8 *arg0, s128 arg1) {
    s8 sp[0xc0] __attribute__((aligned(16)));
    M2C_UNK sp60;
    s128 spC0;
    s128 spD0;
    s8 *temp_s0;
    s8 *temp_s1;
    s8 *temp_v1;
    s8 *var_v0;
    spD0 = arg1;
    temp_s1 = M2C_FIELD(arg0, s8 **, 0x5C);
    if (temp_s1 != NULL) {
        if (M2C_FIELD(temp_s1, s32 *, 0x94) == 6) {
            var_v0 = temp_s1 + 0xB0;
            if (FXfKindHasVelocity() == 0) {
                SetXfKind(arg0, temp_s1, 1);
                var_v0 = temp_s1 + 0xB0;
            }
            temp_s0 = temp_s1 + 0x40;
            M2C_FIELD(var_v0, s32 *, 4) = 0;
            M2C_FIELD(var_v0, s32 *, 8) = 0;
            M2C_FIELD(temp_s1, s32 *, 0xB0) = 0;
            temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
            spC0 = M2C_FIELD(temp_v1, s128 (**)(s8 *), 0x114)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x110));
            NormalizeRotateMatrix3__FP7MATRIX3(sp, M2C_FIELD(temp_s1, s128 *, 0x40), M2C_FIELD(temp_s0, s128 *, 0x10), M2C_FIELD(temp_s0, s128 *, 0x20));
            InvertMatrix3(&sp60, sp);
            asm volatile("lqc2 vf1, 0xd0(%0)" : : "r"(sp));
            asm volatile("lqc2 vf2, 0xc0(%0)" : : "r"(sp));
            asm volatile("vsub.xyzw vf7, vf1, vf2");
            asm volatile("lqc2 vf6, 0x20(%0)" : : "r"(temp_s0));
            asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(temp_s0));
            asm volatile("lqc2 vf1, 0x40(%0)" : : "r"(temp_s1));
            asm volatile("lqc2 vf3, 0x60(%0)" : : "r"(sp));
            asm volatile("lqc2 vf4, 0x70(%0)" : : "r"(sp));
            asm volatile("vmulax.xyz ACC, vf1, vf3x");
            asm volatile("vmadday.xyz ACC, vf2, vf3y");
            asm volatile("vmaddz.xyz vf3, vf6, vf3z");
            asm volatile("vmulax.xyz ACC, vf1, vf4x");
            asm volatile("vmadday.xyz ACC, vf2, vf4y");
            asm volatile("vmaddz.xyz vf4, vf6, vf4z");
            asm volatile("lqc2 vf5, 0x80(%0)" : : "r"(sp));
            asm volatile("vmulax.xyz ACC, vf1, vf5x");
            asm volatile("vmadday.xyz ACC, vf2, vf5y");
            asm volatile("vmaddz.xyz vf1, vf6, vf5z");
            asm volatile("sqc2 vf3, 0x30(%0)" : : "r"(sp));
            asm volatile("sqc2 vf4, 0x40(%0)" : : "r"(sp));
            asm volatile("vmulax.xyz ACC, vf3, vf7x");
            asm volatile("vmadday.xyz ACC, vf4, vf7y");
            asm volatile("vmaddz.xyz vf2, vf1, vf7z");
            asm volatile("sqc2 vf1, 0x50(%0)" : : "r"(sp));
            asm volatile("sqc2 vf3, 0x90(%0)" : : "r"(sp));
            asm volatile("sqc2 vf4, 0xa0(%0)" : : "r"(sp));
            asm volatile("sqc2 vf1, 0xb0(%0)" : : "r"(sp));
            s32 vu_1;
            asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_1));
            M2C_FIELD(temp_s1, s32 *, 0xB0) = ConvertXfVec(0, M2C_FIELD(temp_s1, s32 *, 0xA0), vu_1);
            WakeXf(arg0, temp_s1);
            func_001F4BF8(arg0);
            func_001F5078(arg0);
            func_001F8668(arg0, 0);
        }
    }
}
}

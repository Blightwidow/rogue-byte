typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SleepSo {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ s128 sp10;                          /* inferred */
    /* 0x020 */ s128 sp20;                          /* inferred */
    /* 0x030 */ s128 sp30;                          /* inferred */
    /* 0x040 */ char pad40[0x30];                   /* maybe part of sp30[4]? */
    /* 0x070 */ M2C_UNK sp70;                       /* inferred */
    /* 0x070 */ char pad70[0xF0];
};                                                  /* size = 0x160 */
#define sp20 (*(s128 *)(sp + 0x020))
#define sp30 (*(s128 *)(sp + 0x030))
M2C_UNK LoadRotateMatrix(M2C_UNK *, M2C_UNK);       /* extern */
M2C_UNK NormalizeRotateMatrix3__FP7MATRIX3(s128 *); /* extern */
M2C_UNK SleepXf(...);                    /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(s8 *, M2C_UNK);  /* extern */
M2C_UNK func_001F38A8(s8 *);                      /* extern */
M2C_UNK func_001F3900(s8 *);                      /* extern */
M2C_UNK func_001F4D50(s8 *);                      /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK g_2dded0;
void SleepSo(s8 *arg0) {
    s8 sp[0xd0] __attribute__((aligned(16)));
    s128 sp10;
    M2C_UNK sp70;
    s32 temp_v0;
    s32 temp_v0_2;
    s8 *temp_a0;
    s8 *temp_s0;
    s8 *temp_s1;
    s8 *temp_s4;
    s8 *temp_s5;
    s8 *temp_v0_3;
    s8 *var_s0;
    temp_s0 = M2C_FIELD(arg0, s8 **, 0x58);
    temp_s1 = M2C_FIELD(arg0, s8 **, 0x5C);
    SleepXf(arg0, temp_s0);
    temp_s4 = temp_s0 + 0xB0;
    SleepXf(arg0, arg0, temp_s1);
    temp_s5 = temp_s1 + 0xB0;
    asm volatile("lqc2 vf3, 0x30(%0)" : : "r"(temp_s0));
    asm volatile("qmtc2.ni %0, vf2" : : "r"(M2C_FIELD(&g_2dded0, f32 *, 4) * -0.5f));
    asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
    asm volatile("lqc2 vf1, 0xb0(%0)" : : "r"(temp_s0));
    asm volatile("vadda.xyzw ACC, vf0, vf3");
    asm volatile("vmaddx.xyzw vf4, vf1, vf2x");
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf4" : "=r"(vu_1));
    __as__6VECTORG9VU_VECTOR(temp_s0 + 0x30, vu_1);
    M2C_FIELD(temp_s0, f32 *, 0x3C) = 1.0f;
    temp_v0 = M2C_FIELD(&B_003DD490, s32 *, 0x3D58) + 1;
    M2C_FIELD(&B_003DD490, s32 *, 0x3D58) = temp_v0;
    M2C_FIELD(temp_s0, s32 *, 0xA4) = temp_v0;
    M2C_FIELD(temp_s4, s32 *, 4) = 0;
    M2C_FIELD(temp_s4, s32 *, 8) = 0;
    M2C_FIELD(temp_s0, s32 *, 0xB0) = 0;
    asm volatile("qmtc2.ni %0, vf2" : : "r"(M2C_FIELD(&g_2dded0, f32 *, 4) * -0.5f));
    asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
    asm volatile("lqc2 vf1, 0xb0(%0)" : : "r"(temp_s1));
    asm volatile("vmulx.xyzw vf3, vf1, vf2x");
    s32 vu_2;
    asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_2));
    LoadRotateMatrix(&sp70, vu_2);
    asm volatile("lqc2 vf5, (%0)" : : "r"(temp_s1));
    asm volatile("lqc2 vf3, 0x70(%0)" : : "r"(sp));
    asm volatile("lqc2 vf6, 0x80(%0)" : : "r"(sp));
    asm volatile("lqc2 vf4, 0x90(%0)" : : "r"(sp));
    asm volatile("vmulax.xyz ACC, vf3, vf5x");
    asm volatile("vmadday.xyz ACC, vf6, vf5y");
    asm volatile("vmaddz.xyz vf5, vf4, vf5z");
    asm volatile("sqc2 vf5, 0x40(%0)" : : "r"(sp));
    asm volatile("sqc2 vf5, 0xa0(%0)" : : "r"(sp));
    asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(temp_s1));
    asm volatile("vmulax.xyz ACC, vf3, vf2x");
    asm volatile("vmadday.xyz ACC, vf6, vf2y");
    asm volatile("vmaddz.xyz vf2, vf4, vf2z");
    asm volatile("sqc2 vf2, 0x50(%0)" : : "r"(sp));
    asm volatile("sqc2 vf2, 0xb0(%0)" : : "r"(sp));
    asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(temp_s1));
    asm volatile("vmulax.xyz ACC, vf3, vf1x");
    asm volatile("vmadday.xyz ACC, vf6, vf1y");
    asm volatile("vmaddz.xyz vf3, vf4, vf1z");
    asm volatile("sqc2 vf5, 0x10(%0)" : : "r"(sp));
    asm volatile("sqc2 vf2, 0x20(%0)" : : "r"(sp));
    asm volatile("sqc2 vf3, 0x30(%0)" : : "r"(sp));
    asm volatile("sqc2 vf3, 0xc0(%0)" : : "r"(sp));
    asm volatile("sqc2 vf3, 0x60(%0)" : : "r"(sp));
    NormalizeRotateMatrix3__FP7MATRIX3(&sp10);
    M2C_FIELD(temp_s1, s128 *, 0) = sp10;
    M2C_FIELD(temp_s1, s128 *, 0x10) = sp20;
    M2C_FIELD(temp_s1, s32 *, 0x1C) = 0;
    M2C_FIELD(temp_s1, s128 *, 0x20) = sp30;
    M2C_FIELD(temp_s1, s32 *, 0x2C) = 0;
    M2C_FIELD(temp_s1, s32 *, 0xC) = 0;
    temp_v0_2 = M2C_FIELD(&B_003DD490, s32 *, 0x3D58) + 1;
    M2C_FIELD(&B_003DD490, s32 *, 0x3D58) = temp_v0_2;
    M2C_FIELD(temp_s1, s32 *, 0xA4) = temp_v0_2;
    M2C_FIELD(temp_s5, s32 *, 4) = 0;
    M2C_FIELD(temp_s5, s32 *, 8) = 0;
    M2C_FIELD(temp_s1, s32 *, 0xB0) = 0;
    temp_v0_3 = M2C_FIELD(arg0, s8 **, 0xC);
    M2C_FIELD(temp_v0_3, M2C_UNK (**)(s8 *), 0x94)(arg0 + M2C_FIELD(temp_v0_3, s16 *, 0x90));
    func_001F3900(arg0);
    temp_a0 = M2C_FIELD(arg0, s8 **, 0xEC);
    if (temp_a0 != NULL) {
        var_s0 = M2C_FIELD(temp_a0, s8 **, 0x34);
        if (var_s0 != NULL) {
            do {
                if (!(M2C_FIELD(var_s0, s64 *, 0x10) & (0x8000L << 0x23))) {
                    func_001F38A8(var_s0);
                }
                var_s0 = M2C_FIELD(var_s0, s8 **, 0x60);
            } while (var_s0 != NULL);
        }
    }
    func_001F4D50(arg0);
}
}

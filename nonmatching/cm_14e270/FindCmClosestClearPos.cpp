typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_FindCmClosestClearPos {
    /* 0x000 */ char pad0[0x10];
    /* 0x010 */ f32 sp10;                           /* inferred */
    /* 0x014 */ M2C_UNK sp14;                       /* inferred */
    /* 0x014 */ char pad14[0xC];
    /* 0x020 */ s128 sp20;                          /* inferred */
    /* 0x030 */ char pad30[0x100];
};                                                  /* size = 0x130 */
#define sp20 (*(s128 *)(sp + 0x020))
s32 FFindCmClearInterval(s32, s32, M2C_UNK, M2C_UNK, f32); /* extern */
s32 SetVectorSphere__FP6VECTORfff(f32, f32, M2C_UNK); /* extern */
extern M2C_UNK D_002BD8B0;
s128 FindCmClosestClearPos(s32 arg0, s32 arg1, s32 arg2, f32 fparg0) {
    s8 sp[0x70] __attribute__((aligned(16)));
    f32 sp10;
    M2C_UNK sp14;
    f32 temp_f0;
    f32 temp_f20;
    f32 var_f0;
    f32 var_f21;
    s32 temp_s1;
    s32 var_a0;
    s32 var_s0;
    s32 var_v0;
    asm volatile("qmtc2.ni %0, vf6" : : "r"(arg2));
    temp_f20 = 5.0f / fparg0;
    asm volatile("sqc2 vf6, 0x20(%0)" : : "r"(sp));
    var_a0 = 0;
    var_f21 = 3.4028235e38f;
    var_v0 = -4;
    do {
        temp_s1 = *((var_a0 * 4) + &D_002BD8B0);
        var_s0 = 0;
        if (temp_s1 > 0) {
            do {
                asm volatile("sqc2 vf6, 0x50(%0)" : : "r"(sp));
                asm volatile("lqc2 vf6, 0x50(%0)" : : "r"(sp));
                asm volatile("qmtc2.ni %0, vf1" : : "r"(fparg0));
                asm volatile("qmtc2.ni %0, vf5" : : "r"(SetVectorSphere__FP6VECTORfff(((f32) var_s0 * 3.1415927f) / (f32) temp_s1, (f32) var_v0 * 0.3926991f, 0x3F800000)));
                asm volatile("vadda.xyzw ACC, vf0, vf6");
                asm volatile("vmaddx.xyzw vf4, vf5, vf1x");
                asm volatile("sqc2 vf5, 0x40(%0)" : : "r"(sp));
                asm volatile("sqc2 vf4, 0x30(%0)" : : "r"(sp));
                asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
                asm volatile("lqc2 vf4, 0x30(%0)" : : "r"(sp));
                asm volatile("lqc2 vf5, 0x40(%0)" : : "r"(sp));
                asm volatile("lqc2 vf6, 0x50(%0)" : : "r"(sp));
                s32 vu_1;
                asm volatile("qmfc2.ni %0, vf4" : "=r"(vu_1));
                s32 vu_2;
                asm volatile("qmfc2.ni %0, vf6" : "=r"(vu_2));
                if (FFindCmClearInterval(arg0, arg1, vu_2, vu_1, 2.0f * temp_f20) != 0) {
                    var_f0 = sp10;
                    if (var_f0 > 0.0f) {
                        temp_f0 = var_f0 + temp_f20;
                        sp10 = temp_f0;
                        var_f0 = temp_f0;
                    }
                    if (var_f0 < var_f21) {
                        var_f21 = var_f0;
                        asm volatile("qmtc2.ni %0, vf3" : : "r"(0xBF800000));
                        asm volatile("qmtc2.ni %0, vf2" : : "r"(var_f21));
                        asm volatile("qmtc2.ni %0, vf1" : : "r"(1.0f - var_f21));
                        asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
                        asm volatile("vmulax.xyzw ACC, vf6, vf1x");
                        asm volatile("vmaddax.xyzw ACC, vf4, vf2x");
                        asm volatile("vmaddx.xyzw vf7, vf5, vf3x");
                        asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
                        asm volatile("sqc2 vf7, 0x20(%0)" : : "r"(sp));
                        asm volatile("sqc2 vf3, (%0)" : : "r"(sp));
                    }
                }
                var_s0 += 1;
            } while (var_s0 < temp_s1);
        }
        var_a0 += 1;
        var_v0 = var_a0 - 4;
    } while (var_a0 < 9);
    return sp20;
}
}

typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_GetCrvBounds {
    /* 0x00 */ char pad0[0x50];
};                                                  /* size = 0x50 */
M2C_UNK UpdateXfmMatWorld();                        /* extern */
void GetCrvBounds(s8 *arg0, s32 arg1, s32 arg2) {
    s8 sp[0x10] __attribute__((aligned(16)));
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a3;
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1;
    s8 *temp_v0;
    s8 *var_v1_2;
    UpdateXfmMatWorld();
    temp_a1 = M2C_FIELD(arg0, s32 *, 0xF4);
    temp_v0 = arg0 + 0xA0;
    asm volatile("lqc2 vf11, 0x30(%0)" : : "r"(temp_v0));
    asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(temp_v0));
    asm volatile("lqc2 vf4, 0x20(%0)" : : "r"(temp_v0));
    asm volatile("lqc2 vf2, 0xa0(%0)" : : "r"(arg0));
    asm volatile("lqc2 vf1, (%0)" : : "r"(temp_a1));
    asm volatile("vmulax.xyz ACC, vf2, vf1x");
    asm volatile("vmadday.xyz ACC, vf3, vf1y");
    asm volatile("vmaddaz.xyz ACC, vf4, vf1z");
    asm volatile("vmaddw.xyz vf5, vf11, vf0w");
    asm volatile("vmove.xyzw vf6, vf5");
    if (M2C_FIELD(arg0, s32 *, 0xE0) == 0) {
        temp_a0 = M2C_FIELD(arg0, s32 *, 0xE8);
        if (temp_a0 > 1) {
            asm volatile("vmove.xyzw vf8, vf2");
            var_v1 = temp_a1 + 0x10;
            asm volatile("vmove.xyzw vf7, vf3");
            var_v0 = temp_a0 - 1;
            asm volatile("vmove.xyzw vf3, vf4");
            asm volatile("vmove.xyzw vf2, vf11");
            asm volatile("lqc2 vf1, (%0)" : : "r"(var_v1));
loop_3:
            var_v0 -= 1;
            asm volatile("vmulax.xyz ACC, vf8, vf1x");
            asm volatile("vmadday.xyz ACC, vf7, vf1y");
            asm volatile("vmaddaz.xyz ACC, vf3, vf1z");
            asm volatile("vmaddw.xyz vf1, vf2, vf0w");
            var_v1 += 0x10;
            asm volatile("vmax.xyz vf5, vf5, vf1");
            asm volatile("vmini.xyz vf6, vf6, vf1");
            if (var_v0 != 0) {
                asm volatile("lqc2 vf1, (%0)" : : "r"(var_v1));
                goto loop_3;
            }
            asm volatile("sqc2 vf6, (%0)" : : "r"(arg1));
            asm volatile("sqc2 vf5, (%0)" : : "r"(arg2));
            return;
        }
        /* Duplicate return node #10. Try simplifying control flow for better match */
        asm volatile("sqc2 vf6, (%0)" : : "r"(arg1));
        asm volatile("sqc2 vf5, (%0)" : : "r"(arg2));
        return;
    }
    temp_a3 = M2C_FIELD(arg0, s32 *, 0xE8) - 1;
    asm volatile("vmove.xyzw vf7, vf5");
    if (temp_a3 > 0) {
        asm volatile("vmove.xyzw vf10, vf2");
        var_v1_2 = M2C_FIELD(arg0, s8 **, 0xEC);
        asm volatile("vmove.xyzw vf9, vf3");
        var_a2 = M2C_FIELD(arg0, s32 *, 0x140) + 0x10;
        asm volatile("vmove.xyzw vf8, vf4");
        var_a0 = M2C_FIELD(arg0, s32 *, 0x144);
        var_a1 = temp_a1 + 0x10;
        var_v0_2 = temp_a3;
        do {
            temp_f0 = M2C_FIELD(var_v1_2, f32 *, 0);
            asm volatile("vmove.xyzw vf4, vf7");
            temp_f1 = M2C_FIELD(var_v1_2, f32 *, 4);
            var_v0_2 -= 1;
            asm volatile("lqc2 vf1, (%0)" : : "r"(var_a1));
            var_v1_2 += 4;
            temp_f1_2 = temp_f1 - temp_f0;
            asm volatile("vmulax.xyz ACC, vf10, vf1x");
            asm volatile("vmadday.xyz ACC, vf9, vf1y");
            asm volatile("vmaddaz.xyz ACC, vf8, vf1z");
            asm volatile("vmaddw.xyz vf7, vf11, vf0w");
            var_a1 += 0x10;
            asm volatile("qmtc2.ni %0, vf3" : : "r"(temp_f1_2 * 0.33333334f));
            asm volatile("sqc2 vf3, (%0)" : : "r"(sp));
            asm volatile("qmtc2.ni %0, vf2" : : "r"(temp_f1_2 * -0.33333334f));
            asm volatile("lqc2 vf1, (%0)" : : "r"(var_a0));
            asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
            asm volatile("vmulax.xyz ACC, vf10, vf1x");
            asm volatile("vmadday.xyz ACC, vf9, vf1y");
            asm volatile("vmaddz.xyz vf1, vf8, vf1z");
            asm volatile("vadda.xyzw ACC, vf0, vf4");
            asm volatile("vmaddx.xyzw vf4, vf1, vf3x");
            var_a0 += 0x10;
            asm volatile("vmax.xyz vf5, vf5, vf4");
            asm volatile("vmini.xyz vf6, vf6, vf4");
            asm volatile("lqc2 vf1, (%0)" : : "r"(var_a2));
            asm volatile("vmulax.xyz ACC, vf10, vf1x");
            asm volatile("vmadday.xyz ACC, vf9, vf1y");
            asm volatile("vmaddz.xyz vf1, vf8, vf1z");
            var_a2 += 0x10;
            asm volatile("vadda.xyzw ACC, vf0, vf7");
            asm volatile("vmaddx.xyzw vf2, vf1, vf2x");
            asm volatile("vmax.xyz vf5, vf5, vf2");
            asm volatile("vmini.xyz vf6, vf6, vf2");
            asm volatile("vmini.xyz vf6, vf6, vf7");
            asm volatile("vmax.xyz vf5, vf5, vf7");
        } while (var_v0_2 != 0);
    }
    asm volatile("sqc2 vf6, (%0)" : : "r"(arg1));
    asm volatile("sqc2 vf5, (%0)" : : "r"(arg2));
}
}

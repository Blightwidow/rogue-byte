typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001F9240 {
    /* 0x000 */ char pad0[0x150];
};                                                  /* size = 0x150 */
M2C_UNK SolveSwGroup(s32, s32, s32, s32, s32, s8 **); /* extern */
s32 func_001F90D0(M2C_UNK, s8 **);                /* extern */
void func_001F9240(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s8 sp[0xf0] __attribute__((aligned(16)));
    f32 temp_f0;
    s32 temp_a1;
    s32 temp_a4;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_condition_bit;
    s32 var_s0;
    s32 var_v0;
    s32 var_v0_2;
    s8 **var_a0;
    s8 **var_a0_2;
    s8 *temp_v1;
    s8 *temp_v1_2;
    var_s0 = arg1;
    temp_a4 = func_001F90D0(0x40, (s8 **)(sp));
    if (var_s0 & 1) {
        var_s0 = (temp_a4 == 0) ? 0 : var_s0;
    } else {
        var_v0 = var_s0 & 2;
        if (var_s0 & 4) {
            var_a2 = 0;
            var_a0 = (s8 **)(sp);
loop_5:
            temp_a1 = var_a2 < temp_a4;
            if (temp_a1 != 0) {
                temp_v1 = *var_a0;
                temp_f0 = M2C_FIELD(temp_v1, f32 *, 0x90);
                if (M2C_FIELD(temp_v1, s32 *, 0x9C) == 0xB) {
                    if (!(fabsf(temp_f0) > 0.1f)) {
                        var_a0 += 4;
                        goto block_4;
                    }
                    goto block_12;
                }
                if (!(temp_f0 < -2.0f)) {
                    var_a0 += 4;
block_4:
                    var_a2 += 1;
                    goto loop_5;
                }
block_12:
                var_v0 = var_s0 & 2;
                if (temp_a1 == 0) {
                    goto block_14;
                }
            } else {
block_14:
                var_s0 &= ~4;
                var_v0 = var_s0 & 2;
            }
        }
        if (var_v0 != 0) {
            var_a2_2 = 0;
            if (temp_a4 > 0) {
                var_a0_2 = (s8 **)(sp);
loop_18:
                temp_v1_2 = *var_a0_2;
                asm volatile("lqc2 vf2, 0x80(%0)" : : "r"(temp_v1_2));
                if (M2C_FIELD(temp_v1_2, s32 *, 0x9C) == 0xB) {
                    asm volatile("lqc2 vf1, 0xb0(%0)" : : "r"(temp_v1_2));
                    asm volatile("vmul.xyz vf1, vf1, vf2");
                    asm volatile("vaddw.x vf3, vf0, vf0w");
                    asm volatile("vadday.x ACC, vf1, vf1y");
                    asm volatile("vmaddz.x vf1, vf3, vf1z");
                    s32 vu_1;
                    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
                    var_condition_bit = fabsf(vu_1) > 5.0f;
                } else {
                    asm volatile("lqc2 vf1, 0xb0(%0)" : : "r"(temp_v1_2));
                    asm volatile("vmul.xyz vf1, vf1, vf2");
                    asm volatile("vaddw.x vf3, vf0, vf0w");
                    asm volatile("vadday.x ACC, vf1, vf1y");
                    asm volatile("vmaddz.x vf1, vf3, vf1z");
                    s32 vu_2;
                    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
                    var_condition_bit = vu_2 < -5.0f;
                }
                var_v0_2 = var_a2_2 < temp_a4;
                if (!var_condition_bit) {
                    var_a2_2 += 1;
                    var_a0_2 += 4;
                    if (var_a2_2 >= temp_a4) {
                        var_v0_2 = var_a2_2 < temp_a4;
                    } else {
                        goto loop_18;
                    }
                }
                if (var_v0_2 == 0) {
                    goto block_25;
                }
            } else {
block_25:
                var_s0 &= ~2;
            }
        }
    }
    if (var_s0 != 0) {
        SolveSwGroup(arg0, var_s0, arg2, arg3, temp_a4, (s8 **)(sp));
    }
}
}

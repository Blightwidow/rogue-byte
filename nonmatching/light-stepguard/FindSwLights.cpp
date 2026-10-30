typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_FindSwLights {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ M2C_UNK sp20;                        /* inferred */
    /* 0x20 */ char pad20[0x10];
    /* 0x30 */ M2C_UNK sp30;                        /* inferred */
    /* 0x30 */ char pad30[0x10];
    /* 0x40 */ s128 sp40;                           /* inferred */
    /* 0x50 */ char pad50[0xA0];
};                                                  /* size = 0xF0 */
M2C_UNK func_002564B8(M2C_UNK *);                   /* extern */
M2C_UNK memset(s32, M2C_UNK, s32);                  /* extern */
void FindSwLights(s8 *arg0, s128 arg1, s32 arg2, s32 arg3) {
    s32 saved_reg_s2;
    s8 sp[0x50] __attribute__((aligned(16)));
    M2C_UNK sp20;
    M2C_UNK sp30;
    s128 sp40;
    M2C_UNK temp_a2;
    f32 temp_f2;
    s32 *var_a1;
    s32 *var_a3;
    s32 *var_s2;
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_t1;
    s32 temp_t6;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v1;
    s32 var_a0;
    s32 var_t0;
    s32 var_v0;
    s32 var_v0_2;
    u32 var_a2;
    u32 var_a2_2;
    s8 *temp_a0;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v0_7;
    s8 *temp_v0_8;
    s8 *var_s0;
    s8 *var_v1;
    var_s2 = (s32 *)(saved_reg_s2);
    sp40 = arg1;
    memset(arg3, 0, arg2 * 8);
    temp_a0 = M2C_FIELD(arg0, s8 **, 0x455C);
    if (temp_a0 != NULL) {
        var_s0 = temp_a0;
        asm volatile("lqc2 vf1, (%0)" : : "r"(var_s0));
loop_2:
        asm volatile("sqc2 vf1, 0x50(%0)" : : "r"(sp));
        func_002564B8(&sp20);
        func_002564B8(&sp30);
        asm volatile("lqc2 vf1, 0x50(%0)" : : "r"(sp));
        asm volatile("lqc2 vf3, 0x40(%0)" : : "r"(sp));
        asm volatile("vmul.xyz vf1, vf1, vf3");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddaz.x ACC, vf2, vf1z");
        asm volatile("vmsubw.x vf1, vf2, vf1w");
        asm volatile("sqc2 vf2, 0x30(%0)" : : "r"(sp));
        asm volatile("sqc2 vf1, 0x20(%0)" : : "r"(sp));
        s32 vu_1;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
        if (vu_1 < 0.0f) {
            temp_v0 = M2C_FIELD(var_s0, s8 **, 0x10);
            if (temp_v0 != NULL) {
                var_s0 = temp_v0;
                goto block_12;
            }
            var_v0 = M2C_FIELD(var_s0, s32 *, 0x18);
            goto block_11;
        }
        temp_v0_2 = M2C_FIELD(var_s0, s8 **, 0x14);
        if (temp_v0_2 != NULL) {
            var_s0 = temp_v0_2;
block_12:
            if (var_s0 != NULL) {
                asm volatile("lqc2 vf1, (%0)" : : "r"(var_s0));
                goto loop_2;
            }
        } else {
            var_v0 = M2C_FIELD(var_s0, s32 *, 0x1C);
block_11:
            var_s2 = (s32 *)(M2C_FIELD(arg0, s32 *, 0x4564) + (var_v0 << 5));
        }
        var_a3 = var_s2;
        var_a2 = 0;
        var_a1 = (s32 *)(sp);
        do {
            var_a2 += 1;
            temp_v1 = *var_a3;
            var_a3 += 4;
            *var_a1 |= temp_v1;
            var_a1 += 4;
        } while (var_a2 < 8U);
    }
    var_a2_2 = 0;
    do {
        var_a0 = *(sp + (var_a2_2 * 4));
        if (var_a0 != 0) {
            asm volatile("lqc2 vf3, 0x40(%0)" : : "r"(sp));
            temp_t6 = var_a2_2 << 5;
            do {
                temp_t1 = var_a0 & (var_a0 - 1);
                var_t0 = arg2;
                temp_a1 = var_a0 & ~temp_t1;
                temp_v0_3 = !(temp_a1 & 0xAAAAAAAA) ? temp_t6 : (temp_t6 + 1);
                temp_v0_4 = (temp_a1 & 0xCCCCCCCC) ? (temp_v0_3 + 2) : temp_v0_3;
                temp_v0_5 = (temp_a1 & 0xF0F0F0F0) ? (temp_v0_4 + 4) : temp_v0_4;
                temp_v0_6 = (temp_a1 & 0xFF00FF00) ? (temp_v0_5 + 8) : temp_v0_5;
                temp_a0_2 = *(arg0 + 0x4154 + (((temp_a1 & 0xFFFF0000) ? (temp_v0_6 + 0x10) : temp_v0_6) * 4));
                asm volatile("lqc2 vf1, 0x100(%0)" : : "r"(temp_a0_2));
                temp_v0_7 = (s8 *)(temp_a0_2 + 0x100);
                asm volatile("vsub.xyzw vf1, vf3, vf1");
                asm volatile("vmul.xyz vf1, vf1, vf1");
                asm volatile("vaddw.x vf2, vf0, vf0w");
                asm volatile("vadday.x ACC, vf1, vf1y");
                asm volatile("vmaddz.x vf1, vf2, vf1z");
                asm volatile("vsqrt Q, vf1x");
                asm volatile("vwaitq");
                asm volatile("vaddq.x vf1, vf0, Q");
                s32 vu_2;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
                temp_f2 = M2C_FIELD(temp_v0_7, f32 *, 0x10) + (M2C_FIELD(temp_v0_7, f32 *, 0x14) * vu_2);
                if (var_t0 > 0) {
                    var_v0_2 = var_t0 < arg2;
                    if (!(temp_f2 < M2C_FIELD(((arg2 * 8) + arg3), f32 *, -8))) {
                        var_v1 = (s8 *)((arg2 * 8) + arg3);
loop_23:
                        var_t0 -= 1;
                        if (var_v0_2 != 0) {
                            s32 vu_3;
                            asm volatile("ldl %0, -0x1(%1)" : "=r"(vu_3) : "r"(var_v1));
                            s32 vu_4;
                            asm volatile("ldr %0, -0x8(%1)" : "=r"(vu_4) : "r"(var_v1), "0"(vu_3));
                            temp_a2 = vu_4;
                            asm volatile("sdl %0, 0x7(%1)" : : "r"(temp_a2), "r"(var_v1));
                            asm volatile("sdr %0, (%1)" : : "r"(temp_a2), "r"(var_v1));
                        }
                        var_v1 -= 8;
                        if (var_t0 > 0) {
                            var_v0_2 = var_t0 < arg2;
                            if (!(temp_f2 < M2C_FIELD(var_v1, f32 *, -8))) {
                                goto loop_23;
                            }
                        }
                        goto block_27;
                    }
                } else {
block_27:
                    var_v0_2 = var_t0 < arg2;
                }
                if (var_v0_2 != 0) {
                    temp_v0_8 = (s8 *)((var_t0 * 8) + arg3);
                    M2C_FIELD(temp_v0_8, s32 *, 4) = temp_a0_2;
                    M2C_FIELD(temp_v0_8, f32 *, 0) = temp_f2;
                }
                var_a0 = temp_t1;
            } while (var_a0 != 0);
        }
        var_a2_2 += 1;
    } while (var_a2_2 < 8U);
}
}

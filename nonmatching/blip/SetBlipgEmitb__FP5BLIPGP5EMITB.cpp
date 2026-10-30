typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetBlipgEmitb__FP5BLIPGP5EMITB {
    /* 0x00 */ f32 sp0;                             /* inferred */
    /* 0x04 */ f32 sp4;                             /* inferred */
    /* 0x08 */ f32 sp8;                             /* inferred */
    /* 0x0C */ char padC[0xB4];
};                                                  /* size = 0xC0 */
s32 FFloatsNear__Ffff(s128, s128, M2C_UNK);         /* extern */
M2C_UNK PrescaleClq__FP3CLQffT0(s8 *, s8 *, f32, M2C_UNK); /* extern */
M2C_UNK PropagateBlipgShader__FP5BLIPG(s8 *, s32, s32, s8 *); /* extern */
M2C_UNK SetEmitdvEmitb__FP6EMITDVP5EMITB(s8 *, s8 *); /* extern */
M2C_UNK memset(s8 *, M2C_UNK, M2C_UNK);           /* extern */
extern s128 g_2a2dd0;
void SetBlipgEmitb__FP5BLIPGP5EMITB(s8 *arg0, s8 *arg1, s32 arg2, s8 *arg3) {
    f32 sp0;
    f32 sp4;
    f32 sp8;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f3;
    f32 temp_f4;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f1;
    s128 temp_s0_2;
    s128 temp_s1;
    s32 *temp_v1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_4;
    s32 temp_v1_2;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a2;
    s32 var_s4;
    s32 var_s5;
    s8 *var_v1;
    u8 *var_a1;
    u8 temp_v0_3;
    s8 *temp_fp;
    s8 *temp_s0;
    s8 *temp_s7;
    s8 *var_a3;
    var_a2 = arg2;
    var_a3 = arg3;
    var_f0 = 1.0f;
    temp_v0 = M2C_FIELD(arg1, s32 *, 0xC0);
    M2C_FIELD(arg0, s32 *, 0x43C) = temp_v0;
    if (temp_v0 == 1) {
        var_f0 = M2C_FIELD(arg1, f32 *, 0xF0);
    }
    M2C_FIELD(arg0, f32 *, 0x440) = var_f0;
    temp_v1 = M2C_FIELD(arg1, s32 **, 0xDC);
    temp_s0 = arg0 + 0x110;
    temp_s7 = arg0 + 0x150;
    temp_fp = arg0 + 0x170;
    if (temp_v1 != NULL) {
        temp_v0_2 = *temp_v1;
        var_a0 = 0;
        M2C_FIELD(arg0, s32 *, 0x3B0) = temp_v0_2;
        if (temp_v0_2 > 0) {
            var_a3 = arg0 + 0x3B4;
loop_5:
            var_a2 = var_a0 + 1;
            var_a1 = (u8 *)((var_a0 * 4) + (temp_v1 + 4));
            var_a0_2 = 3;
            var_v1 = (((M2C_FIELD(arg0, s32 *, 0x3B0) - var_a0) - 1) * 4) + var_a3;
            do {
                temp_v0_3 = *var_a1;
                var_a0_2 -= 1;
                var_a1 += 1;
                *var_v1 = (s8) ((s32) (temp_v0_3 + 1) >> 1);
                var_v1 += 1;
            } while (var_a0_2 >= 0);
            var_a0 = var_a2;
            if (var_a0 < M2C_FIELD(arg0, s32 *, 0x3B0)) {
                goto loop_5;
            }
        }
        M2C_FIELD(arg0, s32 *, 0x434) = (s32) M2C_FIELD(arg1, s32 *, 0xCC);
    }
    PropagateBlipgShader__FP5BLIPG(arg0, M2C_FIELD(arg1, s32 *, 0xD0), var_a2, var_a3);
    memset(arg0 + 0x140, 0, 0x10);
    temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x1A0);
    if (temp_v1_2 >= 2) {
        var_f1 = M2C_FIELD(arg1, f32 *, 0xD8);
        if (var_f1 == 0.0f) {
            var_f1 = M2C_FIELD(arg1, f32 *, 0x8C);
            var_f0_2 = (f32) temp_v1_2;
        } else {
            var_f0_2 = (f32) temp_v1_2;
        }
        M2C_FIELD(arg0, f32 *, 0x144) = (f32) (var_f0_2 / var_f1);
    }
    PrescaleClq__FP3CLQffT0(arg1 + 0xB0, arg0 + 0x130, 1.0f / M2C_FIELD(arg1, f32 *, 0x8C), 0);
    PrescaleClq__FP3CLQffT0(arg1 + 0xE0, temp_s0, 1.0f / M2C_FIELD(arg1, f32 *, 0x8C), 0);
    if (M2C_FIELD(arg0, f32 *, 0x114) != 0.0f) {
        goto block_25;
    }
    if (M2C_FIELD(arg0, f32 *, 0x118) != 0.0f) {
block_25:
        sp4 = 0.0f;
        temp_f4 = M2C_FIELD(arg0, f32 *, 0x110);
        temp_f1 = M2C_FIELD(arg0, f32 *, 0x118);
        sp0 = temp_f4;
        sp8 = temp_f4 + (M2C_FIELD(arg1, f32 *, 0x8C) * (M2C_FIELD(temp_s0, f32 *, 4) + (M2C_FIELD(arg1, f32 *, 0x8C) * M2C_FIELD(temp_s0, f32 *, 8))));
        if (temp_f1 != sp4) {
            temp_f2 = -M2C_FIELD(arg0, f32 *, 0x114) / (2.0f * temp_f1);
            if ((sp4 < temp_f2) && (temp_f2 < M2C_FIELD(arg1, f32 *, 0x8C))) {
                sp4 = temp_f4 + (temp_f2 * (M2C_FIELD(temp_s0, f32 *, 4) + (temp_f2 * M2C_FIELD(temp_s0, f32 *, 8))));
            }
        }
        temp_f3 = fabsf(sp0);
        temp_f2_2 = fabsf(sp4);
        var_f0_3 = fabsf(sp8);
        if ((temp_f2_2 < temp_f3) && (var_f0_3 < temp_f3)) {
            var_f0_3 = temp_f3;
        } else if (var_f0_3 < temp_f2_2) {
            var_f0_3 = temp_f2_2;
        }
    } else {
        var_f0_3 = fabsf(M2C_FIELD(arg0, f32 *, 0x110));
    }
    M2C_FIELD(arg0, f32 *, 0x120) = var_f0_3;
    var_s5 = 0;
    M2C_FIELD(arg0, s32 *, 0x150) = 0;
    M2C_FIELD(temp_s7, s32 *, 8) = 0;
    M2C_FIELD(temp_s7, f32 *, 4) = (f32) (1.0f / M2C_FIELD(arg1, f32 *, 0x8C));
    temp_v0_4 = M2C_FIELD(arg1, s32 *, 0xC4);
    M2C_FIELD(arg0, s32 *, 0x160) = temp_v0_4;
    if (temp_v0_4 == 0) {
        temp_s1 = M2C_FIELD(arg1, s128 *, 0x60);
        temp_s0_2 = g_2a2dd0;
        var_s4 = 0;
        s64 vu_1;
        asm volatile("prot3w %0, %1" : "=r"(vu_1) : "r"(temp_s1));
        s64 vu_2;
        asm volatile("prot3w %0, %1" : "=r"(vu_2) : "r"(temp_s0_2));
        if ((FFloatsNear__Ffff(temp_s0_2, temp_s1, 0x38D1B717) != 0) && (FFloatsNear__Ffff(vu_2, vu_1, 0x38D1B717) != 0)) {
            s64 vu_3;
            asm volatile("pextuw %0, %1, %2" : "=r"(vu_3) : "r"(0), "r"(temp_s1));
            s64 vu_4;
            asm volatile("pextuw %0, %1, %2" : "=r"(vu_4) : "r"(0), "r"(temp_s0_2));
            var_s4 = FFloatsNear__Ffff(vu_4, vu_3, 0x38D1B717) != 0;
        }
        if ((var_s4 != 0) && (M2C_FIELD(arg1, f32 *, 0x58) == 0.0f) && (M2C_FIELD(arg1, f32 *, 0x80) == 0.0f)) {
            var_s5 = 1;
        }
    }
    if (var_s5 != 0) {
        M2C_FIELD(arg0, s32 *, 0x160) = 1;
    }
    memset(temp_fp, 0, 0x30);
    if (M2C_FIELD(arg0, s32 *, 0x160) == 0) {
        SetEmitdvEmitb__FP6EMITDVP5EMITB(temp_fp, arg1);
    }
}
}

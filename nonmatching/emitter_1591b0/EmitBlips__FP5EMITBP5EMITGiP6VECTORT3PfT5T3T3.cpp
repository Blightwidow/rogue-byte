typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_EmitBlips__FP5EMITBP5EMITGiP6VECTORT3PfT5T3T3 {
    /* 0x00 */ s32 sp0;                             /* inferred */
    /* 0x04 */ s32 sp4;                             /* inferred */
    /* 0x08 */ s32 sp8;                             /* inferred */
    /* 0x0C */ s32 spC;                             /* inferred */
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ s32 sp14;                            /* inferred */
    /* 0x18 */ s32 sp18;                            /* inferred */
    /* 0x1C */ s8 *sp1C;                          /* inferred */
    /* 0x20 */ s128 *sp20;                          /* inferred */
    /* 0x24 */ f32 *sp24;                           /* inferred */
    /* 0x28 */ s128 *sp28;                          /* inferred */
    /* 0x2C */ char pad2C[0xA4];
};                                                  /* size = 0xD0 */
f32 GRandInRange(...);                 /* extern */
s32 NRandInRange(M2C_UNK, s32);                     /* extern */
s8 *PblipNew__FP5BLIPG(M2C_UNK *, s8 *);        /* extern */
s8 *PblipgNew(M2C_UNK *);                         /* extern */
M2C_UNK SetBlipgEmitb__FP5BLIPGP5EMITB(s8 *, s8 *); /* extern */
M2C_UNK memset(s8 *, M2C_UNK, M2C_UNK);           /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK B_003DD490;
void EmitBlips__FP5EMITBP5EMITGiP6VECTORT3PfT5T3T3(s8 *arg0, s8 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg_sp0) {
    s32 sp0;
    s32 sp4;
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s8 *sp1C;
    s128 *sp20;
    f32 *sp24;
    s128 *sp28;
    f32 *var_s7;
    f32 temp_f0;
    s128 *var_fp;
    s128 *var_s6;
    s128 temp_v0_5;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_v0_4;
    s32 temp_v1;
    u32 var_s3;
    s8 **temp_v0;
    s8 **temp_v0_2;
    s8 *temp_a0_2;
    s8 *temp_v0_3;
    s8 *var_s0;
    s8 *var_s1;
    s8 *var_s2;
    s8 *var_s4;
    var_s4 = NULL;
    sp0 = arg2;
    sp4 = arg3;
    sp8 = arg4;
    spC = arg5;
    sp10 = arg6;
    sp14 = arg7;
    if (arg1 != NULL) {
        temp_v0 = M2C_FIELD(arg1, s8 ***, 0);
        if (temp_v0 != NULL) {
            var_s4 = *temp_v0;
        }
    }
    if (var_s4 != NULL) {
        var_s1 = M2C_FIELD(var_s4, s8 **, 0x448);
        goto block_17;
    }
    var_s4 = PblipgNew(&B_003DD490);
    if (var_s4 != NULL) {
        if (arg1 != NULL) {
            temp_v0_2 = M2C_FIELD(arg1, s8 ***, 0);
            if (temp_v0_2 != NULL) {
                *temp_v0_2 = var_s4;
            }
        }
        SetBlipgEmitb__FP5BLIPGP5EMITB(var_s4, arg0);
        if (arg1 != NULL) {
            temp_a1 = M2C_FIELD(arg1, s32 *, 8);
            if (temp_a1 != 0) {
                temp_v0_3 = M2C_FIELD(var_s4, s8 **, 0xC);
                M2C_FIELD(temp_v0_3, M2C_UNK (**)(s8 *, s32), 0x19C)(var_s4 + M2C_FIELD(temp_v0_3, s16 *, 0x198), temp_a1);
            }
        }
        if (var_s4 != NULL) {
            var_s1 = M2C_FIELD(var_s4, s8 **, 0x448);
block_17:
            sp18 = 0;
loop_36:
            if (sp18 < sp0) {
                if (var_s1 != NULL) {
                    var_s3 = M2C_FIELD(var_s1, u32 *, 0x1084);
                    goto block_18;
                }
                var_s1 = PblipNew__FP5BLIPG(&B_003DD490, var_s4);
                if (var_s1 != NULL) {
                    var_s3 = M2C_FIELD(var_s1, u32 *, 0x1084);
block_18:
                    if (var_s3 < 0x2BU) {
                        temp_v1 = var_s3 * 0x10;
                        if (sp18 < sp0) {
                            var_s2 = temp_v1 + (var_s1 + 0x840);
                            temp_a0 = sp18 * 0x10;
                            temp_a2 = sp18 * 4;
                            var_s0 = temp_v1 + 0x560 + var_s1;
                            sp24 = (f32 *)(temp_a2 + spC);
                            sp28 = (s128 *)(temp_a0 + sp4);
                            sp1C = arg0 + 0xF8;
                            sp20 = (s128 *)(temp_a0 + arg_sp0);
                            var_fp = (s128 *)(temp_a0 + sp14);
                            var_s7 = (f32 *)(temp_a2 + sp10);
                            var_s6 = (s128 *)(temp_a0 + sp8);
loop_21:
                            M2C_FIELD(var_s0, s128 *, -0x560) = (s128) *sp28;
                            M2C_FIELD(var_s0, f32 *, -0x554) = (f32) *sp24;
                            M2C_FIELD(var_s0, s128 *, -0x2B0) = (s128) *var_s6;
                            M2C_FIELD(var_s0, f32 *, -0x2A4) = (f32) *var_s7;
                            memset(var_s0, 0, 0x10);
                            temp_v0_4 = NRandInRange(0, M2C_FIELD(var_s4, s32 *, 0x3B0) - 1);
                            M2C_FIELD(var_s0, s32 *, 0) = temp_v0_4;
                            if (M2C_FIELD(var_s4, s32 *, 0x434) != 0) {
                                M2C_FIELD(var_s0, s32 *, 0) = (s32) (temp_v0_4 & 0xFFFFFFFE);
                            }
                            if (M2C_FIELD(arg0, s32 *, 0xC8) != 0) {
                                M2C_FIELD(var_s0, s32 *, 4) = NRandInRange(0, M2C_FIELD(var_s4, s32 *, 0x1A0) - 1);
                            }
                            if (M2C_FIELD(var_s4, s32 *, 0x43C) == 2) {
                                temp_f0 = GRandInRange(arg0, sp1C, M2C_FIELD(arg0, f32 *, 0xF8), M2C_FIELD(sp1C, f32 *, 4));
                                M2C_FIELD(var_s0, f32 *, 8) = temp_f0;
                                if (M2C_FIELD(arg0, s32 *, 0xF0) == 0) {
                                    asm volatile("lqc2 vf1, -0x2b0(%0)" : : "r"(var_s0));
                                    asm volatile("lqc2 vf2, 0x70(%0)" : : "r"(&B_002DDF40));
                                    asm volatile("vmul.xyz vf2, vf2, vf1");
                                    asm volatile("vaddw.x vf3, vf0, vf0w");
                                    asm volatile("vadday.x ACC, vf2, vf2y");
                                    asm volatile("vmaddz.x vf2, vf3, vf2z");
                                    s32 vu_1;
                                    asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_1));
                                    if (vu_1 > 0.0f) {
                                        M2C_FIELD(var_s0, f32 *, 8) = (f32) -temp_f0;
                                    }
                                }
                                if (M2C_FIELD(arg0, s32 *, 0xF4) != 0) {
                                    M2C_FIELD(var_s0, f32 *, 0xC) = GRandInRange(arg0, (s8 *)0xC0490FDB, 3.1415927f);
                                }
                            }
                            if (M2C_FIELD(var_s4, s32 *, 0x160) == 2) {
                                temp_a0_2 = (s8 *)(M2C_FIELD(var_s1, s32 *, 0x1088) + (var_s3 << 5));
                                M2C_FIELD(temp_a0_2, s128 *, 0) = (s128) *var_fp;
                                M2C_FIELD(temp_a0_2, s128 *, 0x10) = (s128) *sp20;
                            }
                            var_s3 += 1;
                            var_fp += 0x10;
                            var_s7 += 4;
                            sp20 += 0x10;
                            var_s6 += 0x10;
                            M2C_FIELD(var_s2, s128 *, 0) = (s128) M2C_FIELD(var_s0, s128 *, -0x560);
                            sp24 += 4;
                            sp28 += 0x10;
                            sp18 += 1;
                            M2C_FIELD(var_s2, s128 *, 0x2B0) = (s128) M2C_FIELD(var_s0, s128 *, -0x2B0);
                            temp_v0_5 = (s128) M2C_FIELD(var_s0, s32 *, 0);
                            var_s0 += 0x10;
                            M2C_FIELD(var_s2, s128 *, 0x560) = temp_v0_5;
                            var_s2 += 0x10;
                            M2C_FIELD(var_s1, s32 *, 0x1084) = (s32) (M2C_FIELD(var_s1, s32 *, 0x1084) + 1);
                            M2C_FIELD(var_s4, s32 *, 0x444) = (s32) (M2C_FIELD(var_s4, s32 *, 0x444) + 1);
                            if ((var_s3 < 0x2BU) && (sp18 < sp0)) {
                                goto loop_21;
                            }
                        }
                    }
                    var_s1 = M2C_FIELD(var_s1, s8 **, 0x1090);
                    goto loop_36;
                }
            }
        }
    }
}
}

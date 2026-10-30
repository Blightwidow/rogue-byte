typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_002082D0 {
    /* 0x00 */ char pad0[0xC0];
};                                                  /* size = 0xC0 */
s32 FIsBasicDerivedFrom(s8 *, M2C_UNK);           /* extern */
s32 FIsGuardPriorityClass(s8 *, s8 *);          /* extern */
s32 PosLoWorld(s8 *);                             /* extern */
s32 func_002089F0(s8 *, s8 *);                  /* extern */
s32 func_00208B38(s8 *, s8 *);                  /* extern */
extern M2C_UNK D_FLT_002C3D70;
extern M2C_UNK D_FLT_002C3D80;
s8 *func_002082D0(s8 *arg0) {
    s8 sp[0x40] __attribute__((aligned(16)));
    f32 var_f20;
    f32 var_f21;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_s3;
    s32 var_s4;
    s8 *temp_s0;
    s8 *temp_v0;
    s8 *temp_v1;
    s8 *var_s2;
    s8 *var_v0;
    temp_v1 = M2C_FIELD(arg0, s8 **, 0x390);
    var_s2 = NULL;
    if (temp_v1 != NULL) {
        if ((int)((u64) M2C_FIELD(temp_v1, u64 *, 0x28) >> 0x3C) & 1) {
            var_s2 = temp_v1;
            goto block_31;
        }
        goto block_4;
    }
block_4:
    var_f21 = 3.4028235e38f;
    var_s3 = 0;
    PosLoWorld(arg0);
    if (M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xF64), s32 *, 0xFC) > 0) {
        var_s4 = 0x100;
loop_6:
        temp_v0 = M2C_FIELD(arg0, s8 **, 0xF64) + var_s4;
        temp_s0 = M2C_FIELD(temp_v0, s8 **, 0);
        if (temp_s0 != NULL) {
            if (M2C_FIELD(temp_v0, s32 *, 4) == 0) {
                temp_v0_2 = M2C_FIELD(arg0, s32 *, 0xFBC);
                if (temp_v0_2 != 0x22) {
                    if (temp_v0_2 == 0x25) {
                        goto block_11;
                    }
                    goto block_30;
                }
block_11:
                if (FIsBasicDerivedFrom(temp_s0, 0x38) != 0) {
                    goto block_12;
                }
                goto block_30;
            }
block_12:
            if (func_002089F0(arg0, temp_s0) == 0) {
                var_v0 = temp_s0;
                if (func_00208B38(arg0, temp_s0) == 0) {
                    asm volatile("lqc2 vf2, (%0)" : : "r"(sp));
                    asm volatile("qmtc2.ni %0, vf3" : : "r"(PosLoWorld(temp_s0)));
                    asm volatile("vsub.xyzw vf1, vf2, vf3");
                    asm volatile("vmul.xyz vf1, vf1, vf1");
                    asm volatile("vaddw.x vf2, vf0, vf0w");
                    asm volatile("vadday.x ACC, vf1, vf1y");
                    asm volatile("vmaddz.x vf1, vf2, vf1z");
                    asm volatile("vsqrt Q, vf1x");
                    asm volatile("vwaitq");
                    asm volatile("vaddq.x vf1, vf0, Q");
                    s32 vu_1;
                    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
                    var_f20 = vu_1;
                    if ((s32)temp_s0 == M2C_FIELD(arg0, s32 *, 0x38C)) {
                        var_f20 = M2C_FIELD(&D_FLT_002C3D70, f32 *, 0) + (var_f20 * (M2C_FIELD(&D_FLT_002C3D70, f32 *, 4) + (var_f20 * M2C_FIELD(&D_FLT_002C3D70, f32 *, 8))));
                    }
                    temp_v0_3 = M2C_FIELD(arg0, s32 *, 0xFBC);
                    if (temp_v0_3 != 0x22) {
                        if (temp_v0_3 == 0x25) {
                            goto block_19;
                        }
                    } else {
block_19:
                        if (FIsBasicDerivedFrom(temp_s0, 0x38) != 0) {
                            var_f20 = M2C_FIELD(&D_FLT_002C3D80, f32 *, 0) + (var_f20 * (M2C_FIELD(&D_FLT_002C3D80, f32 *, 4) + (var_f20 * M2C_FIELD(&D_FLT_002C3D80, f32 *, 8))));
                        }
                    }
                    if (FIsGuardPriorityClass(arg0, temp_s0) != 0) {
                        if ((var_s2 != NULL) && (FIsGuardPriorityClass(arg0, var_s2) == 0)) {
                            goto block_29;
                        }
                        goto block_28;
                    }
                    if ((var_s2 == NULL) || (FIsGuardPriorityClass(arg0, var_s2) == 0)) {
block_28:
                        if (var_f20 < var_f21) {
block_29:
                            var_f21 = var_f20;
                            var_s2 = temp_s0;
                        }
                    }
                    goto block_30;
                }
            } else {
                goto block_30;
            }
        } else {
block_30:
            var_s3 += 1;
            var_s4 += 0x10;
            if (var_s3 >= M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xF64), s32 *, 0xFC)) {
                goto block_31;
            }
            goto loop_6;
        }
    } else {
block_31:
        var_v0 = var_s2;
    }
    return var_v0;
}
}

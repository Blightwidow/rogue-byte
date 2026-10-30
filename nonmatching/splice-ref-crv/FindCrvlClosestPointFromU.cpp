typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_FindCrvlClosestPointFromU {
    /* 0x000 */ s128 sp0;                           /* inferred */
    /* 0x010 */ s128 sp10;                          /* inferred */
    /* 0x020 */ s128 sp20;                          /* inferred */
    /* 0x030 */ s128 sp30;                          /* inferred */
    /* 0x040 */ s128 sp40;                          /* inferred */
    /* 0x050 */ char pad50[0x10];
    /* 0x060 */ M2C_UNK sp60;                       /* inferred */
    /* 0x060 */ char pad60[4];
    /* 0x064 */ M2C_UNK sp64;                       /* inferred */
    /* 0x064 */ char pad64[4];
    /* 0x068 */ f32 *sp68;                          /* inferred */
    /* 0x06C */ f32 *sp6C;                          /* inferred */
    /* 0x070 */ s128 sp70;                          /* inferred */
    /* 0x080 */ char pad80[0xB0];
};                                                  /* size = 0x130 */
s128 ApplyConstr(s32, s128);                        /* extern */
s32 IcvFindCrvU(M2C_UNK *, M2C_UNK *);              /* extern */
f32 SFromCrvU(s8 *, f32);                         /* extern */
void FindCrvlClosestPointFromU(s8 *arg0, s128 arg1, s32 arg2, s32 arg3, s32 arg4, f32 *arg5, f32 *arg6) {
    s32 saved_reg_s2;
    s8 sp[0x60] __attribute__((aligned(16)));
    s128 sp0;
    s128 sp10;
    s128 sp20;
    s128 sp30;
    s128 sp40;
    M2C_UNK sp60;
    M2C_UNK sp64;
    f32 *sp68;
    f32 *sp6C;
    s128 sp70;
    f32 temp_a0;
    f32 temp_f12;
    f32 temp_f1;
    f32 var_f12;
    s128 temp_a1;
    s32 temp_a0_2;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_s0;
    s32 var_s2;
    s32 var_s5;
    s32 var_s6;
    s8 *temp_v0;
    s8 *temp_v0_4;
    s8 *temp_v1;
    var_s2 = saved_reg_s2;
    sp70 = arg1;
    var_s6 = 0;
    var_s5 = 0;
    sp68 = arg5;
    sp6C = arg6;
    temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
    var_s0 = IcvFindCrvU(&sp60, &sp64);
    temp_v0 = M2C_FIELD(temp_v1, s8 *(**)(s8 *), 0xFC)(arg0 + M2C_FIELD(temp_v1, s16 *, 0xF8));
    sp10 = M2C_FIELD(temp_v0, s128 *, 0);
    sp20 = M2C_FIELD(temp_v0, s128 *, 0x10);
    sp30 = M2C_FIELD(temp_v0, s128 *, 0x20);
    sp40 = M2C_FIELD(temp_v0, s128 *, 0x30);
loop_21:
    asm volatile("lqc2 vf1, 0x20(%0)" : : "r"(&sp10));
    temp_v0_2 = (var_s0 * 0x10) + M2C_FIELD(arg0, s32 *, 0xF4);
    asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(sp));
    asm volatile("lqc2 vf6, (%0)" : : "r"(temp_v0_2));
    asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(temp_v0_2));
    asm volatile("lqc2 vf7, 0x10(%0)" : : "r"(&sp10));
    asm volatile("vsub.xyzw vf2, vf2, vf6");
    asm volatile("vmulax.xyz ACC, vf4, vf2x");
    asm volatile("vmadday.xyz ACC, vf7, vf2y");
    asm volatile("vmaddz.xyz vf2, vf1, vf2z");
    asm volatile("lqc2 vf5, 0x20(%0)" : : "r"(sp));
    asm volatile("lqc2 vf1, 0x40(%0)" : : "r"(sp));
    asm volatile("lqc2 vf3, 0x30(%0)" : : "r"(sp));
    asm volatile("vmulax.xyz ACC, vf4, vf6x");
    asm volatile("vmadday.xyz ACC, vf5, vf6y");
    asm volatile("vmaddaz.xyz ACC, vf3, vf6z");
    asm volatile("vmaddw.xyz vf4, vf1, vf0w");
    asm volatile("sqc2 vf2, (%0)" : : "r"(sp));
    asm volatile("lqc2 vf1, 0x70(%0)" : : "r"(sp));
    asm volatile("vsub.xyzw vf4, vf1, vf4");
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf4" : "=r"(vu_1));
    temp_a1 = vu_1;
    if (arg2 != 0) {
        asm volatile("qmtc2.ni %0, vf4" : : "r"(ApplyConstr(arg2, temp_a1)));
        asm volatile("sqc2 vf4, 0x80(%0)" : : "r"(sp));
        asm volatile("lqc2 vf4, 0x80(%0)" : : "r"(sp));
        sp0 = ApplyConstr(arg2, sp0);
    }
    asm volatile("lqc2 vf2, (%0)" : : "r"(sp));
    asm volatile("vmul.xyz vf1, vf2, vf2");
    asm volatile("vaddw.x vf3, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf3, vf1z");
    var_f12 = 0.0f;
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    asm volatile("vdiv Q, vf0w, vf1x");
    asm volatile("vwaitq");
    asm volatile("vmulq.xyzw vf1, vf2, Q");
    asm volatile("sqc2 vf2, 0x50(%0)" : : "r"(sp));
    asm volatile("vmul.xyz vf4, vf1, vf4");
    asm volatile("vaddw.x vf3, vf0, vf0w");
    asm volatile("vadday.x ACC, vf4, vf4y");
    asm volatile("vmaddz.x vf4, vf3, vf4z");
    s32 vu_2;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
    temp_f1 = vu_2;
    s32 vu_3;
    asm volatile("qmfc2.ni %0, vf4" : "=r"(vu_3));
    temp_a0 = vu_3;
    asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
    if (temp_a0 < 0.0f) {
        if (var_s5 != 0) {
            var_f12 = 1.0f;
            goto block_26;
        }
        if (var_s0 <= 0) {
            if (M2C_FIELD(arg0, s32 *, 0xE4) != 0) {
                var_s0 = M2C_FIELD(arg0, s32 *, 0xE8) - 2;
                goto block_8;
            }
        } else {
            var_s0 -= 1;
block_8:
            var_s6 = 1;
            var_s2 = var_s0;
            goto loop_21;
        }
    } else if (temp_f1 < temp_a0) {
        if (var_s6 == 0) {
            if (var_s0 >= (M2C_FIELD(arg0, s32 *, 0xE8) - 2)) {
                if (M2C_FIELD(arg0, s32 *, 0xE4) != 0) {
                    var_s0 = 0;
                    goto block_19;
                }
                var_f12 = 1.0f;
            } else {
                var_s0 += 1;
block_19:
                var_s5 = 1;
                var_s2 = var_s0;
                goto loop_21;
            }
        } else {
block_26:
            var_s0 = var_s2;
        }
    } else {
        var_f12 = temp_a0 / temp_f1;
    }
    if (arg3 != 0) {
        asm volatile("qmtc2.ni %0, vf8" : : "r"(var_f12));
        asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(sp));
        temp_v0_3 = (var_s0 * 0x10) + M2C_FIELD(arg0, s32 *, 0xF4);
        asm volatile("qmtc2.ni %0, vf3" : : "r"(1.0f - var_f12));
        asm volatile("lqc2 vf7, 0x20(%0)" : : "r"(sp));
        asm volatile("sqc2 vf3, 0x50(%0)" : : "r"(sp));
        asm volatile("lqc2 vf6, 0x30(%0)" : : "r"(sp));
        asm volatile("lqc2 vf2, 0x40(%0)" : : "r"(sp));
        asm volatile("lqc2 vf5, (%0)" : : "r"(temp_v0_3));
        asm volatile("sqc2 vf8, 0x50(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(temp_v0_3));
        asm volatile("vmulax.xyzw ACC, vf5, vf3x");
        asm volatile("vmaddx.xyzw vf3, vf1, vf8x");
        asm volatile("vmulax.xyz ACC, vf4, vf3x");
        asm volatile("vmadday.xyz ACC, vf7, vf3y");
        asm volatile("vmaddaz.xyz ACC, vf6, vf3z");
        asm volatile("vmaddw.xyz vf4, vf2, vf0w");
        asm volatile("sqc2 vf4, (%0)" : : "r"(arg3));
    }
    if (arg4 != 0) {
        asm volatile("lqc2 vf5, 0x20(%0)" : : "r"(&sp10));
        temp_a0_2 = (var_s0 * 0x10) + M2C_FIELD(arg0, s32 *, 0xF4);
        asm volatile("lqc2 vf4, 0x10(%0)" : : "r"(sp));
        asm volatile("lqc2 vf1, (%0)" : : "r"(temp_a0_2));
        asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(temp_a0_2));
        asm volatile("vsub.xyzw vf2, vf2, vf1");
        asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(&sp10));
        asm volatile("vmulax.xyz ACC, vf4, vf2x");
        asm volatile("vmadday.xyz ACC, vf3, vf2y");
        asm volatile("vmaddz.xyz vf2, vf5, vf2z");
        asm volatile("vmul.xyz vf1, vf2, vf2");
        asm volatile("vaddw.x vf6, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf6, vf1z");
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        asm volatile("vdiv Q, vf0w, vf1x");
        asm volatile("vwaitq");
        asm volatile("vmulq.xyzw vf1, vf2, Q");
        asm volatile("sqc2 vf1, (%0)" : : "r"(arg4));
    }
    temp_v0_4 = (s8 *)((var_s0 * 4) + M2C_FIELD(arg0, s32 *, 0xEC));
    temp_f12 = ((1.0f - var_f12) * M2C_FIELD(temp_v0_4, f32 *, 0)) + (var_f12 * M2C_FIELD(temp_v0_4, f32 *, 4));
    if (sp68 != NULL) {
        *sp68 = temp_f12;
    }
    if (sp6C != NULL) {
        *sp6C = SFromCrvU(arg0, temp_f12);
    }
}
}

typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00147F40 {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ s8 ***sp4;                         /* inferred */
    /* 0x08 */ s32 sp8;                             /* inferred */
    /* 0x0C */ s8 *spC;                           /* inferred */
    /* 0x10 */ s128 sp10;                           /* inferred */
    /* 0x20 */ s128 sp20;                           /* inferred */
    /* 0x30 */ char pad30[0xB0];
};                                                  /* size = 0xE0 */
s32 AppendDlEntry(s8 *, s8 **);
s32 FFindDlEntry(s8 *, s8 **);
s32 PosLoWorld(...);
s32 *PpoSwFocusBase();
void RemoveDlEntry(s8 *, s8 **);
void RemoveSwRootRaw(s8 *, s8 **);
void RetractSwRoot(s8 *, s8 **);
extern M2C_UNK B_002DDF40;
extern f32 D_FLT_002BD450;
extern s8 *g_2dd2fc;
void func_00147F40(s8 *arg0) {
    s32 saved_reg_s4;
    s8 sp[0xE0] __attribute__((aligned(16)));
    s8 ***sp4;
    s32 sp8;
    s8 *spC;
    s128 sp10;
    s128 sp20;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f20;
    f32 temp_v0_2;
    s128 var_v0;
    s32 temp_s5;
    s32 var_a1;
    s32 var_s4;
    s64 temp_a0_2;
    s8 ***var_v0_2;
    s8 **temp_a0_3;
    s8 **temp_v0_3;
    s8 **var_s2;
    s8 *temp_a0;
    s8 *temp_s1;
    s8 *temp_v0;
    s8 *temp_v0_4;
    s8 *temp_v0_5;
    s8 *var_s0;
    var_s4 = saved_reg_s4;
    temp_s5 = M2C_FIELD(&B_002DDF40, s32 *, 0x14);
    sp10 = M2C_FIELD(&B_002DDF40, s128 *, 0x90);
    temp_v0 = (s8 *)(PpoSwFocusBase());
    if (temp_v0 == NULL) {
        var_v0 = sp10;
    } else {
        var_v0 = PosLoWorld(temp_v0);
    }
    sp20 = var_v0;
    asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(sp));
    asm volatile("lqc2 vf2, 0x39b0(%0)" : : "r"(arg0));
    asm volatile("vsub.xyzw vf2, vf1, vf2");
    asm volatile("vmul.xyz vf2, vf2, vf2");
    asm volatile("vaddw.x vf1, vf0, vf0w");
    asm volatile("vadday.x ACC, vf2, vf2y");
    asm volatile("vmaddz.x vf2, vf1, vf2z");
    asm volatile("vsqrt Q, vf2x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf2, vf0, Q");
    asm volatile("lqc2 vf1, 0x39c0(%0)" : : "r"(arg0));
    s32 vu_1;
    asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_1));
    temp_v0_2 = vu_1;
    asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(sp));
    asm volatile("vsub.xyzw vf1, vf2, vf1");
    asm volatile("vmul.xyz vf1, vf1, vf1");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    s32 vu_2;
    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
    temp_f20 = vu_2;
    if ((D_FLT_002BD450 < temp_v0_2) || (D_FLT_002BD450 < temp_f20) || (var_v0_2 = (s8 ***)(arg0 + 0x20), (temp_s5 != M2C_FIELD(arg0, s32 *, 0x39A8)))) {
        M2C_FIELD(arg0, s32 *, 0x39A4) = 0;
        M2C_FIELD(arg0, s32 *, 0x39A8) = temp_s5;
        M2C_FIELD(arg0, s128 *, 0x39B0) = sp10;
        M2C_FIELD(arg0, s128 *, 0x39C0) = sp20;
        var_v0_2 = (s8 ***)(arg0 + 0x20);
    }
    sp4 = var_v0_2;
    temp_a0 = g_2dd2fc;
    var_a1 = M2C_FIELD(var_v0_2, s32 *, 8);
    g_2dd2fc = sp;
    temp_v0_3 = M2C_FIELD(arg0, s8 ***, 0x20);
    spC = temp_a0;
    var_s2 = temp_v0_3;
    sp4 = (s8 ***)(temp_v0_3 + var_a1);
    sp8 = var_a1;
    if ((s32)var_s2 != M2C_FIELD(arg0, s32 *, 0x39A4)) {
        do {
            temp_s1 = *var_s2;
            temp_a0_2 = (s64) (M2C_FIELD(temp_s1, s64 *, 0x28) << 8) >> 0x3C;
            if (temp_a0_2 != 1) {
                if (temp_a0_2 < 2) {
                    var_s0 = arg0 + 0x2C;
                    if (temp_a0_2 != 0) {
                    } else {
                        if (!(temp_s5 & M2C_FIELD(temp_s1, u8 *, 0x2D))) {
                            var_s4 = 0;
                            goto block_25;
                        }
                        var_s4 = 1;
                        asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(temp_s1, var_a1)));
                        asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(sp));
                        asm volatile("vsub.xyzw vf1, vf2, vf3");
                        asm volatile("vmul.xyz vf1, vf1, vf1");
                        asm volatile("vaddw.x vf2, vf0, vf0w");
                        asm volatile("vadday.x ACC, vf1, vf1y");
                        asm volatile("vmaddz.x vf1, vf2, vf1z");
                        asm volatile("vsqrt Q, vf1x");
                        asm volatile("vwaitq");
                        asm volatile("vaddq.x vf1, vf0, Q");
                        s32 vu_3;
                        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_3));
                        temp_f0 = vu_3 - M2C_FIELD(temp_s1, f32 *, 0x38);
                        if (!(temp_f0 < 0.0f)) {
                            var_s4 = 0;
                        }
                        var_s0 = arg0 + 0x2C;
                        if (D_FLT_002BD450 < (fabsf(temp_f0) - temp_v0_2)) {
block_25:
                            RetractSwRoot(arg0, var_s2);
                            goto block_32;
                        }
                    }
                } else if (temp_a0_2 != 2) {
                    var_s0 = arg0 + 0x2C;
                    if (temp_a0_2 != 3) {
                    } else {
                        if (!(temp_s5 & M2C_FIELD(temp_s1, u8 *, 0x2D))) {
                            var_s4 = 0;
                        } else {
                            var_s4 = 1;
                            asm volatile("qmtc2.ni %0, vf2" : : "r"(PosLoWorld(temp_s1, var_a1)));
                            asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(sp));
                            asm volatile("vsub.xyzw vf1, vf2, vf3");
                            asm volatile("vmul.xyz vf1, vf1, vf1");
                            asm volatile("vaddw.x vf2, vf0, vf0w");
                            asm volatile("vadday.x ACC, vf1, vf1y");
                            asm volatile("vmaddz.x vf1, vf2, vf1z");
                            asm volatile("vsqrt Q, vf1x");
                            asm volatile("vwaitq");
                            asm volatile("vaddq.x vf1, vf0, Q");
                            s32 vu_4;
                            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_4));
                            temp_f0_2 = vu_4 - M2C_FIELD(temp_s1, f32 *, 0x38);
                            if (!(temp_f0_2 < 0.0f)) {
                                var_s4 = 0;
                            }
                            if (D_FLT_002BD450 < (fabsf(temp_f0_2) - temp_f20)) {
                                RetractSwRoot(arg0, var_s2);
                            }
                        }
                        goto block_32;
                    }
                } else {
                    var_s4 = 0;
                    goto block_19;
                }
            } else {
                var_s4 = 1;
block_19:
                RemoveSwRootRaw(arg0, var_s2);
block_32:
                var_s0 = arg0 + 0x2C;
            }
            if (var_s4 != FFindDlEntry(var_s0, var_s2)) {
                if (var_s4 == 0) {
                    temp_v0_4 = M2C_FIELD(temp_s1, s8 **, 0xC);
                    M2C_FIELD(temp_v0_4, M2C_UNK (**)(s8 *), 0xB4)(temp_s1 + M2C_FIELD(temp_v0_4, s16 *, 0xB0));
                    RemoveDlEntry(var_s0, var_s2);
                } else {
                    AppendDlEntry(var_s0, var_s2);
                    temp_v0_5 = M2C_FIELD(temp_s1, s8 **, 0xC);
                    M2C_FIELD(temp_v0_5, M2C_UNK (**)(s8 *), 0xBC)(temp_s1 + M2C_FIELD(temp_v0_5, s16 *, 0xB8));
                }
            }
            temp_a0_3 = *sp4;
            var_a1 = M2C_FIELD(arg0, s32 *, 0x39A4);
            var_s2 = temp_a0_3;
            sp4 = (s8 ***)(temp_a0_3 + sp8);
        } while ((s32)var_s2 != var_a1);
    }
    g_2dd2fc = spC;
}
}

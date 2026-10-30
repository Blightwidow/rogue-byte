typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_FJtStuck {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ char pad14[0x9C];
};                                                  /* size = 0xB0 */
s32 CStackFrame_Construct(s8 *, s8 **, f32);
void CStackFrame_Destructor(s8 *, M2C_UNK, s8 **, M2C_UNK32 *);
s32 *PvAllocStackImpl__Fi(s32 *);
void SolveInequalities(s32, M2C_UNK32 *, M2C_UNK32 *, M2C_UNK32 *, f32);
extern M2C_UNK g_2a2dc0;
extern f32 g_2dded0;
s32 FJtStuck(s8 *arg0, f32 *arg1, f32 fparg0) {
    s8 sp[0x20] __attribute__((aligned(16)));
    s32 sp10;
    M2C_UNK32 *temp_s0;
    M2C_UNK32 *temp_v0;
    M2C_UNK32 *temp_v0_2;
    M2C_UNK32 *var_a3;
    M2C_UNK32 *var_a3_2;
    M2C_UNK32 *var_a3_3;
    M2C_UNK32 temp_f0;
    f32 temp_f12;
    s32 temp_s2;
    s32 var_s0;
    s32 var_s4;
    s32 var_v0;
    s8 **var_a1;
    s8 **var_a2;
    s8 **var_a2_2;
    s8 **var_a2_3;
    s8 *var_a0;
    s8 *var_a0_2;
    s8 *var_a0_3;
    s8 *var_a0_4;
    s8 *var_v1;
    temp_f12 = g_2dded0 - fparg0;
    if (!(temp_f12 < 1.0f)) {
        if (arg1 != NULL) {
            var_v0 = 0;
            if (!((g_2dded0 - *arg1) < 1.0f)) {
                *arg1 = g_2dded0;
                goto block_4;
            }
            /* Duplicate return node #57. Try simplifying control flow for better match */
            return var_v0;
        }
block_4:
        if (M2C_FIELD(arg0, s32 *, 0x208) == 0) {
            var_a2 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xEC), s8 ***, 0x64);
            var_s4 = 0;
            if (var_a2 != NULL) {
                var_a0 = *var_a2;
loop_10:
                if (var_a0 != NULL) {
                    do {
                        var_a0 = M2C_FIELD(var_a0, s8 **, 0xAC);
                        var_s4 += 1;
                    } while (var_a0 != NULL);
                }
                var_a2 = M2C_FIELD(var_a2, s8 ***, 4);
                if (var_a2 != NULL) {
                    var_a0 = *var_a2;
                    goto loop_10;
                }
            }
            if (var_s4 != 0) {
                CStackFrame_Construct(sp, var_a2, temp_f12);
                temp_s2 = var_s4 * 4;
                asm volatile("qmtc2.ni %0, vf2" : : "r"(0xBF800000));
                asm volatile("sqc2 vf2, 0x10(%0)" : : "r"(sp));
                asm volatile("lqc2 vf1, (%0)" : : "r"(&g_2a2dc0));
                asm volatile("vmulx.xyzw vf3, vf1, vf2x");
                sp10 = var_s4 * var_s4 * 4;
                asm volatile("sqc2 vf3, 0x20(%0)" : : "r"(sp));
                M2C_FIELD(&sp10, s32 *, 4) = 0x10;
                temp_v0 = PvAllocStackImpl__Fi(&sp10);
                sp10 = temp_s2;
                M2C_FIELD(&sp10, s32 *, 4) = 0x10;
                temp_v0_2 = PvAllocStackImpl__Fi(&sp10);
                sp10 = temp_s2;
                M2C_FIELD(&sp10, s32 *, 4) = 0x10;
                temp_s0 = PvAllocStackImpl__Fi(&sp10);
                var_a2_2 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xEC), s8 ***, 0x64);
                var_a3 = temp_v0;
                if (var_a2_2 != NULL) {
                    var_a0_2 = *var_a2_2;
loop_18:
                    if (var_a0_2 != NULL) {
                        do {
                            asm volatile("lqc2 vf4, 0x80(%0)" : : "r"(var_a0_2));
                            if (M2C_FIELD(var_a0_2, s32 *, 8) != (s32)arg0) {
                                asm volatile("qmtc2.ni %0, vf1" : : "r"(0xBF800000));
                                asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(sp));
                                asm volatile("vmulx.xyzw vf4, vf4, vf1x");
                            }
                            var_a1 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xEC), s8 ***, 0x64);
                            if (var_a1 != NULL) {
                                do {
                                    var_v1 = M2C_FIELD(var_a1, s8 **, 0);
                                    if (var_v1 != NULL) {
                                        asm volatile("vmove.xyzw vf3, vf4");
                                        do {
                                            asm volatile("lqc2 vf2, 0x80(%0)" : : "r"(var_v1));
                                            if (M2C_FIELD(var_v1, s32 *, 8) != (s32)arg0) {
                                                asm volatile("qmtc2.ni %0, vf1" : : "r"(0xBF800000));
                                                asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(sp));
                                                asm volatile("vmulx.xyzw vf2, vf2, vf1x");
                                            }
                                            asm volatile("vmul.xyz vf1, vf3, vf2");
                                            asm volatile("vaddw.x vf2, vf0, vf0w");
                                            asm volatile("vadday.x ACC, vf1, vf1y");
                                            asm volatile("vmaddz.x vf1, vf2, vf1z");
                                            s32 vu_1;
                                            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
                                            *var_a3 = vu_1;
                                            var_v1 = M2C_FIELD(var_v1, s8 **, 0xAC);
                                            var_a3 += 4;
                                        } while (var_v1 != NULL);
                                    }
                                    var_a1 = M2C_FIELD(var_a1, s8 ***, 4);
                                } while (var_a1 != NULL);
                            }
                            var_a0_2 = M2C_FIELD(var_a0_2, s8 **, 0xAC);
                        } while (var_a0_2 != NULL);
                    }
                    var_a2_2 = M2C_FIELD(var_a2_2, s8 ***, 4);
                    if (var_a2_2 != NULL) {
                        var_a0_2 = *var_a2_2;
                        goto loop_18;
                    }
                    var_a2_2 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xEC), s8 ***, 0x64);
                }
                var_a3_2 = temp_v0_2;
                if (var_a2_2 != NULL) {
                    var_a0_3 = *var_a2_2;
loop_36:
                    if (var_a0_3 != NULL) {
                        asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(sp));
                        do {
                            asm volatile("lqc2 vf2, 0x80(%0)" : : "r"(var_a0_3));
                            if (M2C_FIELD(var_a0_3, s32 *, 8) != (s32)arg0) {
                                asm volatile("qmtc2.ni %0, vf1" : : "r"(0xBF800000));
                                asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(sp));
                                asm volatile("vmulx.xyzw vf2, vf2, vf1x");
                            }
                            asm volatile("vmul.xyz vf1, vf2, vf3");
                            asm volatile("vaddw.x vf2, vf0, vf0w");
                            asm volatile("vadday.x ACC, vf1, vf1y");
                            asm volatile("vmaddz.x vf1, vf2, vf1z");
                            s32 vu_2;
                            asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
                            *var_a3_2 = vu_2;
                            var_a0_3 = M2C_FIELD(var_a0_3, s8 **, 0xAC);
                            var_a3_2 += 4;
                        } while (var_a0_3 != NULL);
                    }
                    var_a2_2 = M2C_FIELD(var_a2_2, s8 ***, 4);
                    if (var_a2_2 != NULL) {
                        var_a0_3 = *var_a2_2;
                        goto loop_36;
                    }
                }
                SolveInequalities(var_s4, temp_v0, temp_v0_2, temp_s0, 3.4028235e38f);
                var_a3_3 = temp_s0;
                var_a2_3 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xEC), s8 ***, 0x64);
                asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(sp));
                if (var_a2_3 != NULL) {
                    var_a0_4 = *var_a2_3;
loop_46:
                    if (var_a0_4 != NULL) {
                        do {
                            asm volatile("lqc2 vf2, 0x80(%0)" : : "r"(var_a0_4));
                            if (M2C_FIELD(var_a0_4, s32 *, 8) != (s32)arg0) {
                                asm volatile("qmtc2.ni %0, vf1" : : "r"(0xBF800000));
                                asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(sp));
                                asm volatile("vmulx.xyzw vf2, vf2, vf1x");
                            }
                            temp_f0 = *var_a3_3;
                            var_a0_4 = M2C_FIELD(var_a0_4, s8 **, 0xAC);
                            var_a3_3 += 4;
                            asm volatile("qmtc2.ni %0, vf1" : : "r"(temp_f0));
                            asm volatile("vadda.xyzw ACC, vf0, vf3");
                            asm volatile("vmaddx.xyzw vf3, vf2, vf1x");
                            asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(sp));
                        } while (var_a0_4 != NULL);
                    }
                    var_a2_3 = M2C_FIELD(var_a2_3, s8 ***, 4);
                    if (var_a2_3 != NULL) {
                        var_a0_4 = *var_a2_3;
                        goto loop_46;
                    }
                }
                var_s0 = 1;
                s32 vu_3;
                asm volatile("qmfc2.ni %0, vf3" : "=r"(vu_3));
                s64 vu_4;
                asm volatile("pextuw %0, %1, %0" : "=r"(vu_4) : "r"(0), "r"(vu_3));
                if (!(vu_4 > -0.1f)) {
                    var_s0 = 0;
                }
                CStackFrame_Destructor(sp, 2, var_a2_3, var_a3_3);
                var_v0 = var_s0;
                return var_v0;
            }
            goto block_7;
        }
        goto block_7;
    }
block_7:
    return 0;
}
}

typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void AddSoGeomsToOxa(s8 *);
void CLo_Clone();
s32 CStackFrame_Construct(s8 *, s8 *);
void CStackFrame_Destructor(s8 *, M2C_UNK);
void ClearDle__FP3DLE(s8 *);
void CloneBspc__FP4GEOMP4BSPCT0T1(s32, s32, s8 *, s8 *);
void CloneGeom(s8 *, M2C_UNK, s8 *);
void CloneGlobset(s8 *, s8 *, s8 *);
void InsertXfAct(s8 *, s8 *, s32);
s32 PactClone(s8 *, s8 *, s8 *);
s8 **PvAllocStackImpl__Fi(s8 *);
s8 *PvAllocSwCopyImpl__FiPv(s8 *, s8 *);
void func_001F2500(s8 *);
extern s32 D_002C44F0;
void CSo_Clone(s8 *arg0, s8 *arg1) {
    s8 sp[0x40] __attribute__((aligned(16)));
    void (*temp_a3_2)(s8 *, s8 *, s8 *);
    s8 *temp_a1;
    s8 *temp_a1_2;
    s8 *temp_a1_3;
    s8 *temp_a1_4;
    s8 *temp_a2_3;
    s8 *temp_s0_3;
    s8 *temp_s1_2;
    s8 *temp_s1_3;
    s8 *temp_s1_4;
    s8 *temp_v0_11;
    s8 *temp_v0_12;
    s8 *temp_v0_3;
    s8 *temp_v0_6;
    s8 *temp_v0_8;
    s8 *temp_v1_2;
    s8 *var_a2;
    M2C_UNK temp_a0_3;
    M2C_UNK temp_v0;
    M2C_UNK temp_v0_10;
    M2C_UNK temp_v0_2;
    M2C_UNK temp_v1_11;
    s16 temp_v1;
    s32 temp_a0_4;
    s32 temp_a3;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_v0_4;
    s32 temp_v1_10;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s3;
    s32 var_s3_2;
    s32 var_s4;
    s32 var_s4_2;
    s32 var_s7;
    s32 var_s7_2;
    s8 **temp_a0;
    s8 **var_a2_2;
    s8 **var_s1;
    s8 *temp_a0_2;
    s8 *temp_a2;
    s8 *temp_a2_2;
    s8 *temp_a3_3;
    s8 *temp_s0_2;
    s8 *temp_s5;
    s8 *temp_v0_5;
    s8 *temp_v0_7;
    s8 *temp_v0_9;
    s8 *temp_v1_3;
    s8 *temp_v1_4;
    s8 *temp_v1_5;
    s8 *temp_v1_6;
    s8 *temp_v1_7;
    s8 *temp_v1_8;
    s8 *temp_v1_9;
    s8 *var_a1;
    s8 *var_a1_2;
    temp_s0 = M2C_FIELD(arg0, s32 *, 0xEC);
    temp_s1 = M2C_FIELD(arg0, s32 *, 0x70);
    s32 vu_1;
    asm volatile("ldl %0, 0x6b(%1)" : "=r"(vu_1) : "r"(arg0));
    s32 vu_2;
    asm volatile("ldr %0, 0x64(%1)" : "=r"(vu_2) : "r"(arg0), "0"(vu_1));
    temp_v0 = vu_2;
    asm volatile("sdl %0, 0x7(%1)" : : "r"(temp_v0), "r"(sp));
    asm volatile("sdr %0, (%1)" : : "r"(temp_v0), "r"(sp));
    (*(s32 *)(sp + 0x8)) = M2C_FIELD(arg0, s32 *, 0x6C);
    var_s3 = 0;
    CLo_Clone();
    M2C_FIELD(arg0, s32 *, 0xEC) = temp_s0;
    s32 vu_3;
    asm volatile("ldl %0, 0x7(%1)" : "=r"(vu_3) : "r"(sp));
    s32 vu_4;
    asm volatile("ldr %0, (%1)" : "=r"(vu_4) : "r"(sp), "0"(vu_3));
    temp_v0_2 = vu_4;
    asm volatile("sdl %0, 0x6b(%1)" : : "r"(temp_v0_2), "r"(arg0));
    asm volatile("sdr %0, 0x64(%1)" : : "r"(temp_v0_2), "r"(arg0));
    M2C_FIELD(arg0, s32 *, 0x6C) = (*(s32 *)(sp + 0x8));
    M2C_FIELD(arg0, s32 *, 0x70) = temp_s1;
    M2C_FIELD(arg0, s32 *, 0x134) = 0;
    (*(s32 *)(sp + 0x10)) = M2C_FIELD(arg0, s32 *, 0x50) << 8;
    M2C_FIELD((sp + 0x10), s32 *, 4) = 0x10;
    M2C_FIELD(arg0, s8 **, 0x54) = PvAllocSwCopyImpl__FiPv((sp + 0x10), M2C_FIELD(arg0, s8 **, 0x54));
    if (M2C_FIELD(arg0, s32 *, 0x50) > 0) {
        do {
            temp_a2 = M2C_FIELD(arg0, s8 **, 0xC);
            temp_a3 = var_s3 << 8;
            temp_s5 = (s8 *)(M2C_FIELD(arg0, s8 **, 0x54) + temp_a3);
            M2C_FIELD((s8 *)(temp_a2), void (**)(s8 *, s8 *, s8 *), 0x1A4)((s8 *)(arg0 + M2C_FIELD((s8 *)(temp_a2), s16 *, 0x1A0)), arg1, (s8 *)(temp_s5 + 0xA0));
            temp_v1 = M2C_FIELD(temp_s5, s16 *, 0x98);
            if (temp_v1 != 0xD) {
                if (temp_v1 < 0xE) {
                    var_s7 = var_s3 + 1;
                    if (temp_v1 != 4) {
                    } else {
                        var_a2 = (s8 *)(temp_s5 + 0xA8);
                        goto block_14;
                    }
                } else if (temp_v1 != 0xF) {
                    var_s7 = var_s3 + 1;
                    if (temp_v1 != 0x10) {
                    } else {
                        temp_v1_2 = M2C_FIELD(temp_s5, s8 **, 0xA8);
                        temp_s1_2 = M2C_FIELD(temp_v1_2, s8 **, 0x60);
                        if ((s32)temp_v1_2 == M2C_FIELD(temp_s1_2, s32 *, 4)) {
                            (*(s32 *)(sp + 0x10)) = 0x50;
                            M2C_FIELD((sp + 0x10), s32 *, 4) = 0x10;
                            temp_v0_3 = PvAllocSwCopyImpl__FiPv((sp + 0x10), temp_s1_2);
                            var_s3_2 = 0;
                            temp_s1_3 = temp_v0_3;
                            temp_a1 = M2C_FIELD(temp_s1_3, s8 **, 4);
                            temp_v0_4 = M2C_FIELD(temp_s1_3, s32 *, 0) * 0x70;
                            M2C_FIELD((sp + 0x10), s32 *, 4) = 0x10;
                            (*(s32 *)(sp + 0x10)) = temp_v0_4;
                            M2C_FIELD(temp_s1_3, s8 **, 4) = PvAllocSwCopyImpl__FiPv((sp + 0x10), temp_a1);
                            if ((s32) M2C_FIELD(temp_s1_3, s8 **, 0) > 0) {
                                var_s4 = 0;
loop_18:
                                var_s3_2 += 1;
                                temp_s0_2 = (s8 *)(M2C_FIELD(temp_s1_3, s8 **, 4) + var_s4);
                                M2C_FIELD(temp_s0_2, s8 **, 0x60) = temp_s1_3;
                                var_s4 += 0x70;
                                temp_v0_5 = M2C_FIELD(arg0, s8 **, 0xC);
                                temp_a3_2 = M2C_FIELD(temp_v0_5, void (**)(s8 *, s8 *, s8 *), 0x1A4);
                                temp_a3_2((s8 *)(arg0 + M2C_FIELD(temp_v0_5, s16 *, 0x1A0)), arg1, temp_s0_2 + 0x64);
                                M2C_FIELD(M2C_FIELD(temp_s0_2, s8 **, 0x64), s8 **, 0xA8) = temp_s0_2;
                                if (var_s3_2 < (s32) M2C_FIELD(temp_s1_3, s8 **, 0)) {
                                    goto loop_18;
                                }
                            }
                        }
                    }
                } else {
                    (*(s32 *)(sp + 0x10)) = 0x10;
                    M2C_FIELD((sp + 0x10), s32 *, 4) = 0x10;
                    temp_v0_6 = PvAllocSwCopyImpl__FiPv((sp + 0x10), M2C_FIELD(temp_s5, s8 **, 0xA8));
                    M2C_FIELD(temp_s5, s8 **, 0xA8) = temp_v0_6;
                    if ((s32)*temp_v0_6 != (s32)&D_002C44F0) {
                        temp_v0_7 = M2C_FIELD(arg0, s8 **, 0xC);
                        M2C_FIELD(temp_v0_7, void (**)(s8 *, s8 *, s8 *), 0x1A4)(arg0 + M2C_FIELD(temp_v0_7, s16 *, 0x1A0), arg1, temp_v0_6);
                    }
                    var_a2 = temp_v0_6 + 4;
block_14:
                    var_s7 = var_s3 + 1;
                    M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xC), M2C_UNK (**)(s8 *, s8 *, s8 *), 0x1A4)(arg0 + M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xC), s16 *, 0x1A0), arg1, var_a2);
                }
            } else {
                (*(s32 *)(sp + 0x10)) = 0xE0;
                M2C_FIELD((sp + 0x10), s32 *, 4) = 0x10;
                temp_v0_8 = PvAllocSwCopyImpl__FiPv((sp + 0x10), M2C_FIELD(temp_s5, s8 **, 0xA8));
                var_s7 = var_s3 + 1;
                temp_v1_3 = M2C_FIELD(arg0, s8 **, 0xC);
                M2C_FIELD(temp_v1_3, void (**)(s8 *, s8 *, s8 *), 0x1A4)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0x1A0), arg1, temp_v0_8);
                temp_v1_4 = M2C_FIELD(arg0, s8 **, 0xC);
                M2C_FIELD(temp_v1_4, void (**)(s8 *, s8 *, s8 *), 0x1A4)(arg0 + M2C_FIELD(temp_v1_4, s16 *, 0x1A0), arg1, temp_v0_8 + 4);
                temp_v1_5 = M2C_FIELD(arg0, s8 **, 0xC);
                M2C_FIELD(temp_v1_5, void (**)(s8 *, s8 *, s8 *), 0x1A4)(arg0 + M2C_FIELD(temp_v1_5, s16 *, 0x1A0), arg1, temp_v0_8 + 8);
                temp_a3_3 = M2C_FIELD(arg0, s8 **, 0xC);
                M2C_FIELD(temp_a3_3, void (**)(s8 *, s8 *, s8 *), 0x1A4)(arg0 + M2C_FIELD(temp_a3_3, s16 *, 0x1A0), arg1, temp_v0_8 + 0xC);
                M2C_FIELD(M2C_FIELD(temp_v0_8, s8 **, 4), s8 **, 0xA8) = temp_v0_8;
                M2C_FIELD(M2C_FIELD(temp_v0_8, s8 **, 8), s8 **, 0xA8) = temp_v0_8;
            }
            temp_v0_9 = M2C_FIELD(temp_s5, s8 **, 0x90);
            var_a1 = temp_v0_9;
            if (temp_v0_9 != NULL) {
                var_s0 = 0;
                do {
                    var_a1 = M2C_FIELD(var_a1, s8 **, 0x10);
                    var_s0 += 1;
                } while (var_a1 != NULL);
                CStackFrame_Construct((sp + 0x20), var_a1);
                M2C_FIELD((sp + 0x10), s32 *, 4) = 0x10;
                (*(s32 *)(sp + 0x10)) = var_s0 * 4;
                temp_a0 = PvAllocStackImpl__Fi((sp + 0x10));
                var_a1_2 = M2C_FIELD(temp_s5, s8 **, 0x90);
                if (var_a1_2 != NULL) {
                    var_a2_2 = temp_a0;
                    do {
                        *var_a2_2 = var_a1_2;
                        var_a1_2 = M2C_FIELD(var_a1_2, s8 **, 0x10);
                        var_a2_2 += 4;
                    } while (var_a1_2 != NULL);
                }
                var_s0_2 = var_s0 - 1;
                M2C_FIELD(temp_s5, s8 **, 0x90) = NULL;
                if (var_s0_2 >= 0) {
                    var_s1 = &temp_a0[var_s0_2];
                    do {
                        temp_a0_2 = *var_s1;
                        var_s1 -= 4;
                        var_s0_2 -= 1;
                        InsertXfAct(arg0, temp_s5, PactClone(temp_a0_2, arg0, temp_s5));
                    } while (var_s0_2 >= 0);
                }
                CStackFrame_Destructor((sp + 0x20), 2);
            }
            var_s3 = var_s7;
        } while (var_s3 < M2C_FIELD(arg0, s32 *, 0x50));
    }
    temp_v1_6 = M2C_FIELD(arg0, s8 **, 0xC);
    var_s7_2 = 0;
    M2C_FIELD(temp_v1_6, void (**)(s8 *, s8 *, s8 *), 0x1A4)(arg0 + M2C_FIELD(temp_v1_6, s16 *, 0x1A0), arg1, arg0 + 0x58);
    temp_v1_7 = M2C_FIELD(arg0, s8 **, 0xC);
    M2C_FIELD(temp_v1_7, void (**)(s8 *, s8 *, s8 *), 0x1A4)(arg0 + M2C_FIELD(temp_v1_7, s16 *, 0x1A0), arg1, arg0 + 0x5C);
    temp_v1_8 = M2C_FIELD(arg0, s8 **, 0xC);
    M2C_FIELD(temp_v1_8, void (**)(s8 *, s8 *, s8 *), 0x1A4)(arg0 + M2C_FIELD(temp_v1_8, s16 *, 0x1A0), arg1, arg0 + 0x60);
    CloneGlobset(arg0 + 0x80, arg0, arg1);
    temp_v1_9 = M2C_FIELD(arg0, s8 **, 0xC);
    temp_v1_10 = M2C_FIELD(arg0, s32 *, 0xE0) + M2C_FIELD(temp_v1_9, s32 (**)(s8 *), 0x1FC)(arg0 + M2C_FIELD(temp_v1_9, s16 *, 0x1F8));
    (*(s32 *)(sp + 0x14)) = 0x10;
    (*(s32 *)(sp + 0x10)) = temp_v1_10 * 0xB0;
    M2C_FIELD(arg0, s8 **, 0xE4) = PvAllocSwCopyImpl__FiPv((sp + 0x10), M2C_FIELD(arg0, s8 **, 0xE4));
    if (M2C_FIELD(arg0, s32 *, 0xE0) > 0) {
        var_s4_2 = 0;
        do {
            temp_a2_2 = M2C_FIELD(arg0, s8 **, 0xC);
            temp_s1_4 = M2C_FIELD(arg0, s8 **, 0xE4) + var_s4_2;
            M2C_FIELD(temp_a2_2, void (**)(s8 *, s8 *, s8 *), 0x1A4)(arg0 + M2C_FIELD(temp_a2_2, s16 *, 0x1A0), arg1, temp_s1_4);
            temp_s0_3 = temp_s1_4 + 0x90;
            M2C_FIELD(temp_s1_4, s8 **, 4) = arg0;
            ClearDle__FP3DLE(temp_s1_4 + 0x60);
            CloneGeom(temp_s0_3, 0, (sp + 0x30));
            s32 vu_5;
            asm volatile("ldl %0, 0x37(%1)" : "=r"(vu_5) : "r"(sp));
            s32 vu_6;
            asm volatile("ldr %0, 0x30(%1)" : "=r"(vu_6) : "r"(sp), "0"(vu_5));
            temp_v0_10 = vu_6;
            s32 vu_7;
            asm volatile("ldl %0, 0x3f(%1)" : "=r"(vu_7) : "r"(sp));
            s32 vu_8;
            asm volatile("ldr %0, 0x38(%1)" : "=r"(vu_8) : "r"(sp), "0"(vu_7));
            temp_v1_11 = vu_8;
            s32 vu_9;
            asm volatile("ldl %0, 0x47(%1)" : "=r"(vu_9) : "r"(sp));
            s32 vu_10;
            asm volatile("ldr %0, 0x40(%1)" : "=r"(vu_10) : "r"(sp), "0"(vu_9));
            temp_a0_3 = vu_10;
            asm volatile("sdl %0, 0x97(%1)" : : "r"(temp_v0_10), "r"(temp_s1_4));
            asm volatile("sdr %0, 0x90(%1)" : : "r"(temp_v0_10), "r"(temp_s1_4));
            asm volatile("sdl %0, 0x9f(%1)" : : "r"(temp_v1_11), "r"(temp_s1_4));
            asm volatile("sdr %0, 0x98(%1)" : : "r"(temp_v1_11), "r"(temp_s1_4));
            asm volatile("sdl %0, 0xa7(%1)" : : "r"(temp_a0_3), "r"(temp_s1_4));
            asm volatile("sdr %0, 0xa0(%1)" : : "r"(temp_a0_3), "r"(temp_s1_4));
            temp_a0_4 = M2C_FIELD(arg1, s32 *, 0xE4) + var_s4_2;
            CloneBspc__FP4GEOMP4BSPCT0T1(temp_a0_4 + 0x68, temp_a0_4 + 0x90, temp_s1_4 + 0x68, temp_s0_3);
            temp_a1_2 = M2C_FIELD(temp_s1_4, s8 **, 0x10);
            if (temp_a1_2 != NULL) {
                (*(s32 *)(sp + 0x10)) = 0xC;
                M2C_FIELD((sp + 0x10), s32 *, 4) = 0x10;
                temp_v0_11 = PvAllocSwCopyImpl__FiPv((sp + 0x10), temp_a1_2);
                M2C_FIELD(temp_s1_4, s8 **, 0x10) = temp_v0_11;
                (*(s32 *)(sp + 0x10)) = M2C_FIELD(temp_s1_4, s32 *, 0x78) * 0x10;
                M2C_FIELD((sp + 0x10), s32 *, 4) = 0x10;
                M2C_FIELD(M2C_FIELD(temp_s1_4, s8 **, 0x10), s8 **, 0) = PvAllocSwCopyImpl__FiPv((sp + 0x10), (s8 *)*temp_v0_11);
                temp_a2_3 = M2C_FIELD(temp_s1_4, s8 **, 0x10);
                M2C_FIELD((sp + 0x10), s32 *, 4) = 0x10;
                (*(s32 *)(sp + 0x10)) = M2C_FIELD(temp_s1_4, s32 *, 0x78) * 0x10;
                M2C_FIELD(M2C_FIELD(temp_s1_4, s8 **, 0x10), s8 **, 4) = PvAllocSwCopyImpl__FiPv((sp + 0x10), M2C_FIELD(temp_a2_3, s8 **, 4));
                M2C_FIELD((sp + 0x10), s32 *, 4) = 0x10;
                (*(s32 *)(sp + 0x10)) = M2C_FIELD(temp_s1_4, s32 *, 0x80) * 0xC;
                M2C_FIELD(M2C_FIELD(temp_s1_4, s8 **, 0x10), s8 **, 8) = PvAllocSwCopyImpl__FiPv((sp + 0x10), M2C_FIELD(M2C_FIELD(temp_s1_4, s8 **, 0x10), s8 **, 8));
            }
            var_s7_2 += 1;
            var_s4_2 += 0xB0;
        } while (var_s7_2 < M2C_FIELD(arg0, s32 *, 0xE0));
    }
    temp_a1_3 = M2C_FIELD(arg0, s8 **, 0xE8);
    if (temp_a1_3 != NULL) {
        (*(s32 *)(sp + 0x10)) = 0xE0;
        (*(s32 *)(sp + 0x14)) = 0x10;
        temp_v0_12 = PvAllocSwCopyImpl__FiPv((sp + 0x10), temp_a1_3);
        M2C_FIELD(arg0, s8 **, 0xE8) = temp_v0_12;
        temp_a1_4 = M2C_FIELD(temp_v0_12, s8 **, 0xDC);
        if (temp_a1_4 != NULL) {
            (*(s32 *)(sp + 0x14)) = 0x10;
            (*(s32 *)(sp + 0x10)) = 0x70;
            M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xE8), s8 **, 0xDC) = PvAllocSwCopyImpl__FiPv((sp + 0x10), temp_a1_4);
            *(s8 **)M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xE8), s8 **, 0xDC) = arg0;
        }
    }
    if (((u64) M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1) {
        AddSoGeomsToOxa(arg0);
    }
    func_001F2500(arg0);
}
}

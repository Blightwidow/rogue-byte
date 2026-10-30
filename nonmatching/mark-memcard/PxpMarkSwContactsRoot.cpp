typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_PxpMarkSwContactsRoot {
    /* 0x00 */ char pad0[2];
    /* 0x02 */ M2C_UNK sp2;                         /* inferred */
    /* 0x02 */ char pad2[0xE];
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ char pad14[0xC];                     /* maybe part of sp10[4]? */
    /* 0x20 */ s32 sp20;                            /* inferred */
    /* 0x24 */ M2C_UNK *sp24;                       /* inferred */
    /* 0x28 */ s32 sp28;                            /* inferred */
    /* 0x2C */ s32 sp2C;                            /* inferred */
    /* 0x30 */ s32 sp30;                            /* inferred */
    /* 0x34 */ M2C_UNK *sp34;                       /* inferred */
    /* 0x38 */ s32 sp38;                            /* inferred */
    /* 0x3C */ M2C_UNK *sp3C;                       /* inferred */
    /* 0x40 */ s32 sp40;                            /* inferred */
    /* 0x44 */ s32 sp44;                            /* inferred */
    /* 0x48 */ s32 *sp48;                           /* inferred */
    /* 0x4C */ M2C_UNK *sp4C;                       /* inferred */
    /* 0x50 */ char pad50[0xA0];
};                                                  /* size = 0xF0 */
s32 CStackFrame_Construct(M2C_UNK *);
void CStackFrame_Destructor(M2C_UNK *, M2C_UNK);
s32 CloneMqList(s32, s32);
void MarkSoContactsBspBsp(s32, s8 *, s8 *, s32);
void MarkSoContactsSphereBsp(s32, s8 *, s8 *, s32);
void MarkSoContactsSphereSphere(s32, s8 *, s8 *, s32 *);
void MarkSoContactsSweptPoints(s32, s8 *, s8 *, s32 *);
void MarkSoCustomContacts(s32, s8 *, s8 *, s8 *);
s32 PaloFindWkrAbsorber(s32, s32);
void PrependMqList(s32, s32, s32 *);
s32 PruneBsp__FP3BSPP6VECTORfPP3BSP(s32, M2C_UNK, s128, s32 *, f32);
s32 *PvAllocStackImpl__Fi(s32 *, M2C_UNK);
extern M2C_UNK D_002BBB20;
s32 PxpMarkSwContactsRoot(s32 arg0, s8 *arg1, s8 *arg2) {
    s8 sp[0x50] __attribute__((aligned(16)));
#define sp2 (*(M2C_UNK *)(sp + 0x02))
#define sp10 (*(s32 *)(sp + 0x10))
#define sp20 (*(s32 *)(sp + 0x20))
#define sp24 (*(M2C_UNK **)(sp + 0x24))
#define sp28 (*(s32 *)(sp + 0x28))
#define sp2C (*(s32 *)(sp + 0x2C))
#define sp30 (*(s32 *)(sp + 0x30))
#define sp34 (*(M2C_UNK **)(sp + 0x34))
#define sp38 (*(s32 *)(sp + 0x38))
#define sp3C (*(M2C_UNK **)(sp + 0x3C))
#define sp40 (*(s32 *)(sp + 0x40))
#define sp44 (*(s32 *)(sp + 0x44))
#define sp48 (*(s32 **)(sp + 0x48))
#define sp4C (*(M2C_UNK **)(sp + 0x4C))
    s32 *var_s2;
    s32 temp_s4;
    s32 temp_s6;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 var_s2_2;
    s32 var_v1;
    s64 temp_a0;
    s64 temp_a0_2;
    s64 temp_v0_2;
    s64 temp_v1_7;
    s64 temp_v1_8;
    s64 temp_v1_9;
    s64 var_v0;
    s8 *temp_v0;
    s8 *var_fp;
    s8 *var_s0;
    s8 *var_s0_2;
    s8 *var_s1;
    s8 *var_s1_2;
    s8 *var_s5;
    var_s5 = arg1;
    var_fp = arg2;
    temp_v0 = var_s5;
    sp28 = 0;
    if (M2C_FIELD(var_fp, f32 *, 0x30) < M2C_FIELD(var_s5, f32 *, 0x30)) {
        var_s5 = var_fp;
        var_fp = temp_v0;
    }
    var_s1 = M2C_FIELD(var_fp, s8 **, 0x34);
    sp30 = 0;
    sp4C = &sp2;
    if (var_s1 != NULL) {
        do {
            temp_v1 = M2C_FIELD(var_s1, s32 *, 0x6C);
            var_s1 = M2C_FIELD(var_s1, s8 **, 0x60);
            sp30 = (sp30 < temp_v1) ? temp_v1 : sp30;
        } while (var_s1 != NULL);
    }
    CStackFrame_Construct(sp4C);
    sp30 = (sp30 > 0x1554) ? 0x1555 : sp30;
    sp10 = sp30 * 0xC;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    sp34 = PvAllocStackImpl__Fi(&sp10, 0x10);
    var_s1_2 = M2C_FIELD(var_fp, s8 **, 0x34);
    if (var_s1_2 != NULL) {
        do {
            temp_a0 = M2C_FIELD(var_s1_2, s64 *, 0x10);
            temp_v1_2 = M2C_FIELD(var_s1_2, s32 *, 0x18) != 0;
            sp38 = temp_v1_2;
            if (!(temp_a0 & (0x8000L << 0x21)) || (temp_v1_2 != 0)) {
                sp44 = 2;
                if ((temp_a0 & (0x8000L << 0x22)) || (M2C_FIELD(var_s5, s64 *, 0x70) & 0x20)) {
                    sp24 = NULL;
                    sp3C = NULL;
                    sp40 = 0;
                    goto block_15;
                }
                sp20 = sp30;
                sp24 = sp34;
                sp3C = sp34;
                sp44 = PruneBsp__FP3BSPP6VECTORfPP3BSP(M2C_FIELD(var_s1_2, s32 *, 0x74), 0x7FFFFFFF, M2C_FIELD(var_s5, s128 *, 0x20), &sp20, M2C_FIELD(var_s5, f32 *, 0x30));
                if (sp44 != 1) {
                    if (sp44 == 0) {
                        sp40 = 0;
                        sp24 = &D_002BBB20;
                        sp3C = &D_002BBB20;
                    } else {
                        temp_v1_3 = (sp24 - sp3C) * 0xAAAAAAAB;
                        sp24 -= 0xC;
                        sp40 = temp_v1_3 >> 2;
                    }
block_15:
                    var_s0 = M2C_FIELD(var_s5, s8 **, 0x34);
                    if (var_s0 != NULL) {
                        sp48 = &sp2C;
                        do {
                            temp_v1_4 = M2C_FIELD(var_s0, s64 *, 0x10) & (0x8000L << 0x21);
                            temp_s6 = M2C_FIELD(var_s0, s32 *, 0x18) != 0;
                            if ((temp_v1_4 == 0) || (temp_s6 != 0)) {
                                if (M2C_FIELD(var_s1_2, s64 *, 0x10) & (0x8000L << 0x21)) {
                                    if (temp_v1_4 == 0) {
                                        goto block_22;
                                    }
                                } else {
block_22:
                                    sp2C = 0;
                                    var_s2 = &sp28;
                                    if (sp38 != 0) {
                                        temp_v1_5 = PaloFindWkrAbsorber(M2C_FIELD(var_s0, s32 *, 4), M2C_FIELD(var_s1_2, s32 *, 0x18)) != 0;
                                        if (M2C_FIELD(var_s1_2, s64 *, 0x10) & (0x8000L << 0x21)) {
                                            var_s2 = &sp2C;
                                            if (temp_v1_5 != 0) {
                                                goto block_28;
                                            }
                                        } else {
                                            if (temp_v1_5 != 0) {
                                                var_s2 = (M2C_FIELD(var_s0, s64 *, 0x10) & (0x8000L << 0x21)) ? &sp28 : sp48;
                                            }
                                            goto block_28;
                                        }
                                    } else {
block_28:
                                        if (temp_s6 != 0) {
                                            temp_v1_6 = PaloFindWkrAbsorber(M2C_FIELD(var_s1_2, s32 *, 4), M2C_FIELD(var_s0, s32 *, 0x18)) != 0;
                                            temp_a0_2 = 0x8000L << 0x21;
                                            if (M2C_FIELD(var_s0, s64 *, 0x10) & temp_a0_2) {
                                                var_s2 = &sp2C;
                                                if (temp_v1_6 != 0) {
                                                    goto block_34;
                                                }
                                            } else {
                                                if (temp_v1_6 != 0) {
                                                    var_s2 = !(M2C_FIELD(var_s1_2, s64 *, 0x10) & temp_a0_2) ? sp48 : var_s2;
                                                }
                                                goto block_34;
                                            }
                                        } else {
block_34:
                                            temp_s4 = *var_s2;
                                            if ((M2C_FIELD(var_s0, s32 *, 0xAC) != M2C_FIELD(var_s0, s32 *, 0xA8)) || (M2C_FIELD(var_s1_2, s32 *, 0xAC) != M2C_FIELD(var_s1_2, s32 *, 0xA8))) {
                                                if (M2C_FIELD(var_s0, s32 *, 0x1C) < M2C_FIELD(var_s0, s32 *, 0x78)) {
                                                    MarkSoContactsSweptPoints(arg0, var_s0, var_s1_2, var_s2);
                                                }
                                                if (M2C_FIELD(var_s1_2, s32 *, 0x1C) < M2C_FIELD(var_s1_2, s32 *, 0x78)) {
                                                    MarkSoContactsSweptPoints(arg0, var_s1_2, var_s0, var_s2);
                                                }
                                            }
                                            if (*var_s2 == temp_s4) {
                                                temp_v1_7 = 0x8000L << 0x22;
                                                temp_v0_2 = M2C_FIELD(var_s0, s64 *, 0x10);
                                                if (M2C_FIELD(var_s1_2, s64 *, 0x10) & temp_v1_7) {
                                                    if (temp_v0_2 & temp_v1_7) {
                                                        MarkSoContactsSphereSphere(arg0, var_s0, var_s1_2, var_s2);
                                                    } else {
                                                        MarkSoContactsSphereBsp(arg0, var_s1_2, var_s0, 0);
                                                    }
                                                } else if (temp_v0_2 & temp_v1_7) {
                                                    var_v1 = 0;
                                                    s32 vu_1;
                                                    asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
                                                    asm volatile("vmaddz.x vf1, vf2, vf1z");
                                                    asm volatile("vadday.x ACC, vf1, vf1y");
                                                    asm volatile("vaddw.x vf2, vf0, vf0w");
                                                    asm volatile("vmul.xyz vf1, vf1, vf1");
                                                    asm volatile("vsub.xyzw vf1, vf1, vf2");
                                                    asm volatile("lqc2 vf1, 0x70(%0)" : : "r"(M2C_FIELD(var_s1_2, s32 *, 0)));
                                                    asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(var_s5));
                                                    if ((sp44 == 0) || ((float)vu_1 > 1.0f) || (fabsf(M2C_FIELD(var_s1_2, f32 *, 8) - M2C_FIELD(var_s5, f32 *, 0x30)) > 1.0f)) {
                                                        var_v1 = 1;
                                                    }
                                                    MarkSoContactsSphereBsp(arg0, var_s0, var_s1_2, (var_v1 != 0) ? 0 : sp40);
                                                } else {
                                                    MarkSoContactsBspBsp(arg0, var_s0, var_s1_2, sp40);
                                                }
                                            }
                                            if (sp2C != 0) {
                                                var_s2_2 = 0;
                                                if (sp38 != 0) {
                                                    temp_v1_8 = 0x8000L << 0x21;
                                                    if (M2C_FIELD(var_s1_2, s64 *, 0x10) & temp_v1_8) {
                                                        PrependMqList(arg0, sp2C, (s32 *)(var_fp + 0x6C));
                                                    } else if (!(M2C_FIELD(var_s0, s64 *, 0x10) & temp_v1_8)) {
                                                        var_s2_2 = 1;
                                                        PrependMqList(arg0, CloneMqList(arg0, sp2C), (s32 *)(var_fp + 0x6C));
                                                    }
                                                }
                                                if (temp_s6 != 0) {
                                                    temp_v1_9 = 0x8000L << 0x21;
                                                    if (M2C_FIELD(var_s0, s64 *, 0x10) & temp_v1_9) {
                                                        PrependMqList(arg0, sp2C, (s32 *)(var_s5 + 0x6C));
                                                    } else if (!(M2C_FIELD(var_s1_2, s64 *, 0x10) & temp_v1_9)) {
                                                        var_s2_2 = 1;
                                                        PrependMqList(arg0, CloneMqList(arg0, sp2C), (s32 *)(var_s5 + 0x6C));
                                                    }
                                                }
                                                if (var_s2_2 != 0) {
                                                    PrependMqList(arg0, sp2C, &sp28);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            var_s0 = M2C_FIELD(var_s0, s8 **, 0x60);
                        } while (var_s0 != NULL);
                    }
                    if (!(M2C_FIELD(var_s1_2, s64 *, 0x10) & (0x8000L << 0x21))) {
                        MarkSoCustomContacts(arg0, var_s5, var_fp, var_s1_2);
                    }
                }
            }
            var_s1_2 = M2C_FIELD(var_s1_2, s8 **, 0x60);
        } while (var_s1_2 != NULL);
    }
    var_s0_2 = M2C_FIELD(var_s5, s8 **, 0x34);
    if (var_s0_2 != NULL) {
        var_v0 = M2C_FIELD(var_s0_2, s64 *, 0x10);
loop_72:
        if (!(var_v0 & (0x8000L << 0x21))) {
            MarkSoCustomContacts(arg0, var_fp, var_s5, var_s0_2);
        }
        var_s0_2 = M2C_FIELD(var_s0_2, s8 **, 0x60);
        if (var_s0_2 != NULL) {
            var_v0 = M2C_FIELD(var_s0_2, s64 *, 0x10);
            goto loop_72;
        }
    }
    CStackFrame_Destructor(sp4C, 2);
    return sp28;
}
}

#include "m2c_macros.h"

M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
s32 CloneMqList(s32, s32);                          /* extern */
M2C_UNK MarkSoContactsBspBsp(s32, void *, void *, s32); /* extern */
M2C_UNK MarkSoContactsSphereBsp(s32, void *, void *, s32); /* extern */
M2C_UNK MarkSoContactsSphereSphere(s32, void *, void *, s32 *); /* extern */
M2C_UNK MarkSoContactsSweptPoints(s32, void *, void *, s32 *); /* extern */
M2C_UNK MarkSoCustomContacts(s32, void *, void *, void *); /* extern */
s32 PaloFindWkrAbsorber(s32, s32);                  /* extern */
M2C_UNK PrependMqList(s32, s32, s32 *);             /* extern */
s32 PruneBsp__FP3BSPP6VECTORfPP3BSP(s32, M2C_UNK, s128, s32 *, f32); /* extern */
M2C_UNK *PvAllocStackImpl__Fi(s32 *, M2C_UNK);      /* extern */
extern M2C_UNK D_002BBB20;

s32 PxpMarkSwContactsRoot(s32 arg0, void *arg1, void *arg2) {
    M2C_UNK sp2;
    s32 sp10;
    s32 sp20;
    M2C_UNK *sp24;
    s32 sp28;
    s32 sp2C;
    s32 sp30;
    M2C_UNK *sp34;
    s32 sp38;
    M2C_UNK *sp3C;
    s32 sp40;
    s32 sp44;
    s32 *sp48;
    M2C_UNK *sp4C;
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
    void *temp_v0;
    void *var_fp;
    void *var_s0;
    void *var_s0_2;
    void *var_s1;
    void *var_s1_2;
    void *var_s5;

    var_s5 = arg1;
    var_fp = arg2;
    temp_v0 = var_s5;
    sp28 = 0;
    if (M2C_FIELD(var_fp, f32 *, 0x30) < M2C_FIELD(var_s5, f32 *, 0x30)) {
        var_s5 = var_fp;
        var_fp = temp_v0;
    }
    var_s1 = M2C_FIELD(var_fp, void **, 0x34);
    sp30 = 0;
    sp4C = &sp2;
    if (var_s1 != NULL) {
        do {
            temp_v1 = M2C_FIELD(var_s1, s32 *, 0x6C);
            var_s1 = M2C_FIELD(var_s1, void **, 0x60);
            sp30 = (sp30 < temp_v1) ? temp_v1 : sp30;
        } while (var_s1 != NULL);
    }
    CStackFrame_Construct(sp4C);
    sp30 = (sp30 > 0x1554) ? 0x1555 : sp30;
    sp10 = sp30 * 0xC;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    sp34 = PvAllocStackImpl__Fi(&sp10, 0x10);
    var_s1_2 = M2C_FIELD(var_fp, void **, 0x34);
    if (var_s1_2 != NULL) {
        do {
            temp_a0 = M2C_FIELD(var_s1_2, s64 *, 0x10);
            temp_v1_2 = M2C_FIELD(var_s1_2, s32 *, 0x18) != 0;
            sp38 = temp_v1_2;
            if (!(temp_a0 & (0x8000 << 0x21)) || (temp_v1_2 != 0)) {
                sp44 = 2;
                if ((temp_a0 & (0x8000 << 0x22)) || (M2C_FIELD(var_s5, s64 *, 0x70) & 0x20)) {
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
                    var_s0 = M2C_FIELD(var_s5, void **, 0x34);
                    if (var_s0 != NULL) {
                        sp48 = &sp2C;
                        do {
                            temp_v1_4 = M2C_FIELD(var_s0, s64 *, 0x10) & (0x8000 << 0x21);
                            temp_s6 = M2C_FIELD(var_s0, s32 *, 0x18) != 0;
                            if ((temp_v1_4 == 0) || (temp_s6 != 0)) {
                                if (M2C_FIELD(var_s1_2, s64 *, 0x10) & (0x8000 << 0x21)) {
                                    if (temp_v1_4 == 0) {
                                        goto block_22;
                                    }
                                } else {
block_22:
                                    sp2C = 0;
                                    var_s2 = &sp28;
                                    if (sp38 != 0) {
                                        temp_v1_5 = PaloFindWkrAbsorber(M2C_FIELD(var_s0, s32 *, 4), M2C_FIELD(var_s1_2, s32 *, 0x18)) != 0;
                                        if (M2C_FIELD(var_s1_2, s64 *, 0x10) & (0x8000 << 0x21)) {
                                            var_s2 = &sp2C;
                                            if (temp_v1_5 != 0) {
                                                goto block_28;
                                            }
                                        } else {
                                            if (temp_v1_5 != 0) {
                                                var_s2 = (M2C_FIELD(var_s0, s64 *, 0x10) & (0x8000 << 0x21)) ? &sp28 : sp48;
                                            }
                                            goto block_28;
                                        }
                                    } else {
block_28:
                                        if (temp_s6 != 0) {
                                            temp_v1_6 = PaloFindWkrAbsorber(M2C_FIELD(var_s1_2, s32 *, 4), M2C_FIELD(var_s0, s32 *, 0x18)) != 0;
                                            temp_a0_2 = 0x8000 << 0x21;
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
                                                temp_v1_7 = 0x8000 << 0x22;
                                                temp_v0_2 = M2C_FIELD(var_s0, s64 *, 0x10);
                                                if (M2C_FIELD(var_s1_2, s64 *, 0x10) & temp_v1_7) {
                                                    if (temp_v0_2 & temp_v1_7) {
                                                        MarkSoContactsSphereSphere(arg0, var_s0, var_s1_2, var_s2);
                                                    } else {
                                                        MarkSoContactsSphereBsp(arg0, var_s1_2, var_s0, 0);
                                                    }
                                                } else if (temp_v0_2 & temp_v1_7) {
                                                    var_v1 = 0;
                                                    if ((sp44 == 0) || (M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($s5) */), M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($v0) */), M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */), M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */), M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */), M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */), M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */), (M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */) > 1.0f)) || (fabsf(M2C_FIELD(var_s1_2, f32 *, 8) - M2C_FIELD(var_s5, f32 *, 0x30)) > 1.0f)) {
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
                                                    temp_v1_8 = 0x8000 << 0x21;
                                                    if (M2C_FIELD(var_s1_2, s64 *, 0x10) & temp_v1_8) {
                                                        PrependMqList(arg0, sp2C, var_fp + 0x6C);
                                                    } else if (!(M2C_FIELD(var_s0, s64 *, 0x10) & temp_v1_8)) {
                                                        var_s2_2 = 1;
                                                        PrependMqList(arg0, CloneMqList(arg0, sp2C), var_fp + 0x6C);
                                                    }
                                                }
                                                if (temp_s6 != 0) {
                                                    temp_v1_9 = 0x8000 << 0x21;
                                                    if (M2C_FIELD(var_s0, s64 *, 0x10) & temp_v1_9) {
                                                        PrependMqList(arg0, sp2C, var_s5 + 0x6C);
                                                    } else if (!(M2C_FIELD(var_s1_2, s64 *, 0x10) & temp_v1_9)) {
                                                        var_s2_2 = 1;
                                                        PrependMqList(arg0, CloneMqList(arg0, sp2C), var_s5 + 0x6C);
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
                            var_s0 = M2C_FIELD(var_s0, void **, 0x60);
                        } while (var_s0 != NULL);
                    }
                    if (!(M2C_FIELD(var_s1_2, s64 *, 0x10) & (0x8000 << 0x21))) {
                        MarkSoCustomContacts(arg0, var_s5, var_fp, var_s1_2);
                    }
                }
            }
            var_s1_2 = M2C_FIELD(var_s1_2, void **, 0x60);
        } while (var_s1_2 != NULL);
    }
    var_s0_2 = M2C_FIELD(var_s5, void **, 0x34);
    if (var_s0_2 != NULL) {
        var_v0 = M2C_FIELD(var_s0_2, s64 *, 0x10);
loop_72:
        if (!(var_v0 & (0x8000 << 0x21))) {
            MarkSoCustomContacts(arg0, var_fp, var_s5, var_s0_2);
        }
        var_s0_2 = M2C_FIELD(var_s0_2, void **, 0x60);
        if (var_s0_2 != NULL) {
            var_v0 = M2C_FIELD(var_s0_2, s64 *, 0x10);
            goto loop_72;
        }
    }
    CStackFrame_Destructor(sp4C, 2);
    return sp28;
}

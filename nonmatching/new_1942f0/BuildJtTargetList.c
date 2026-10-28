#include "m2c_macros.h"

M2C_UNK ClearHudLabel(M2C_UNK *, s32);              /* extern */
M2C_UNK EmitTargetSparkles(M2C_UNK *, s32, s32, void *); /* extern */
s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
s32 FIsPoSwFocusBase(s32);                          /* extern */
M2C_UNK InsertTargetCandidate(s32, s32, s128, void *); /* extern */
s128 PosLoWorld(s32, M2C_UNK);                      /* extern */
void *PpoolFromLoClone(s32);                        /* extern */
M2C_UNK ShowHudLabel(M2C_UNK *, s32, M2C_UNK);      /* extern */
M2C_UNK UpdateSwTargetList(M2C_UNK *, s32, s32, void *); /* extern */
s32 func_001DA5B0(M2C_UNK *);                       /* extern */
M2C_UNK memset(void *, M2C_UNK, M2C_UNK);           /* extern */
extern M2C_UNK B_003DA0C0;
extern M2C_UNK B_003DD490;
extern void *B_003E13B4;
extern void *B_003E13C0;
extern void *B_003E13CC;
extern void *B_003E13D8;
extern void *B_003E13F0;
extern void *B_003E13FC;
extern void *B_003E1408;
extern void *B_003E1414;
extern void *B_003E1438;
extern f32 D_FLT_002BF660;
extern f32 D_FLT_002BF664;
extern f32 D_FLT_002BF70C;

void BuildJtTargetList(s32 arg0, s32 arg1, s32 arg2) {
    char sp[0x400];
    s32 sp90;
    s128 spC0;
    s32 spD0;
    s32 spD4;
    s32 spD8;
    s32 *var_v1_2;
    s32 temp_v0;
    s32 var_s0_10;
    s32 var_s0_11;
    s32 var_v0;
    void *var_s0;
    void *var_s0_2;
    void *var_s0_3;
    void *var_s0_4;
    void *var_s0_5;
    void *var_s0_6;
    void *var_s0_7;
    void *var_s0_8;
    void *var_s0_9;
    void *var_v0_2;
    void *var_v1;

    if (FIsPoSwFocusBase(arg1) != 0) {
        spD8 = arg2 & 0x20;
        memset(sp, 0, 0xC0);
        spD4 = arg2 & 2;
        spD0 = arg2 & 1;
        var_v1 = sp;
        M2C_FIELD(sp, s32 *, 0xC) = -1;
loop_2:
        M2C_FIELD(var_v1, f32 *, 8) = (f32) D_FLT_002BF664;
        var_v1 += 0x30;
        if ((u32) var_v1 < (u32) &spC0) {
            M2C_FIELD(var_v1, s32 *, 0xC) = -1;
            goto loop_2;
        }
        spC0 = PosLoWorld(arg1, -1);
        if (arg2 & 8) {
            var_s0 = B_003E13F0;
            if (var_s0 != NULL) {
                do {
                    InsertTargetCandidate(arg0, arg1, spC0, var_s0);
                    var_s0 = M2C_FIELD(var_s0, void **, 0x1B4);
                } while (var_s0 != NULL);
            }
        }
        if (arg2 & 0x10) {
            var_s0_2 = B_003E13FC;
            if (var_s0_2 != NULL) {
                do {
                    InsertTargetCandidate(arg0, arg1, spC0, var_s0_2);
                    var_s0_2 = M2C_FIELD(var_s0_2, void **, 0x104);
                } while (var_s0_2 != NULL);
            }
        }
        if (arg2 & 0x80) {
            var_s0_3 = B_003E1414;
            if (var_s0_3 != NULL) {
                do {
                    InsertTargetCandidate(arg0, arg1, spC0, var_s0_3);
                    var_s0_3 = M2C_FIELD(var_s0_3, void **, 0x104);
                } while (var_s0_3 != NULL);
            }
        }
        if (arg2 & 4) {
            var_s0_4 = B_003E1438;
            if (var_s0_4 != NULL) {
                do {
                    InsertTargetCandidate(arg0, arg1, spC0, var_s0_4);
                    var_s0_4 = M2C_FIELD(var_s0_4, void **, 0x154);
                } while (var_s0_4 != NULL);
            }
        }
        if (arg2 & 0x400) {
            var_s0_5 = B_003E13D8;
            if (var_s0_5 != NULL) {
                do {
                    InsertTargetCandidate(arg0, arg1, spC0, var_s0_5);
                    var_s0_5 = M2C_FIELD(var_s0_5, void **, 0x104);
                } while (var_s0_5 != NULL);
            }
        }
        if (arg2 & 0x200) {
            var_s0_6 = B_003E13CC;
            if (var_s0_6 != NULL) {
                do {
                    InsertTargetCandidate(arg0, arg1, spC0, var_s0_6);
                    var_s0_6 = M2C_FIELD(var_s0_6, void **, 0x1B4);
                } while (var_s0_6 != NULL);
            }
        }
        if (spD4 != 0) {
            var_s0_7 = B_003E13C0;
            if (var_s0_7 != NULL) {
                do {
                    InsertTargetCandidate(arg0, arg1, spC0, var_s0_7);
                    var_s0_7 = M2C_FIELD(var_s0_7, void **, 0x1B4);
                } while (var_s0_7 != NULL);
            }
        }
        if (spD0 != 0) {
            var_s0_8 = B_003E13B4;
            if (var_s0_8 != NULL) {
                do {
                    if ((M2C_FIELD(var_s0_8, s32 *, 0xE8) & 1) && (FIsBasicDerivedFrom(var_s0_8, 0x13) != 0)) {
                        InsertTargetCandidate(arg0, arg1, spC0, var_s0_8);
                    }
                    var_s0_8 = M2C_FIELD(var_s0_8, void **, 0xE0);
                } while (var_s0_8 != NULL);
            }
        }
        if (spD8 != 0) {
            var_s0_9 = B_003E1408;
            if (var_s0_9 != NULL) {
                do {
                    InsertTargetCandidate(arg0, arg1, spC0, var_s0_9);
                    var_s0_9 = M2C_FIELD(var_s0_9, void **, 0x104);
                } while (var_s0_9 != NULL);
            }
        }
        var_s0_10 = 4;
        if (sp90 == 0) {
            var_v1_2 = &sp90;
loop_44:
            var_s0_10 -= 1;
            var_v1_2 -= 0x30;
            if (var_s0_10 > 0) {
                if (*var_v1_2 == 0) {
                    goto loop_44;
                }
            }
        }
        EmitTargetSparkles(&B_003DD490, arg1, var_s0_10, sp);
        UpdateSwTargetList(&B_003DD490, arg1, var_s0_10, sp);
        temp_v0 = func_001DA5B0(&B_003DA0C0);
        if ((temp_v0 == -1) || (temp_v0 == M2C_FIELD(&B_003DD490, s32 *, 0x4740))) {
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xc0($sp) */);
            if (M2C_FIELD(&B_003DD490, s32 *, 0x4678) != 0) {
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x46a0($s2) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf1 */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                var_v0 = 1;
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                if (!(D_FLT_002BF660 < M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */))) {
                    var_v0 = 0;
                }
                if (var_v0 == 0) {
                    var_v0_2 = NULL;
                    if (M2C_FIELD(&B_003DD490, s32 *, 0x4690) != 0) {
                        var_v0_2 = PpoolFromLoClone(M2C_FIELD(&B_003DD490, s32 *, 0x4690));
                    }
                    if (var_v0_2 != NULL) {
                        if ((M2C_FIELD(var_v0_2, s32 *, 0x18) != 0x624) || (var_s0_11 = 0x125, !(D_FLT_002BF70C < M2C_FIELD(&B_003DD490, f32 *, 0x4694)))) {
                            goto block_61;
                        }
                    } else {
block_61:
                        var_s0_11 = M2C_FIELD(M2C_FIELD(&B_003DD490, void **, 0x4684), s32 *, 0x14);
                    }
                } else {
                    goto block_54;
                }
            } else {
block_54:
                var_s0_11 = -1;
            }
            if (var_s0_11 != temp_v0) {
                if (var_s0_11 == -1) {
                    ClearHudLabel(&B_003DA0C0, M2C_FIELD(&B_003DD490, s32 *, 0x4740));
                } else {
                    ShowHudLabel(&B_003DA0C0, var_s0_11, 0xBF800000);
                }
                M2C_FIELD(&B_003DD490, s32 *, 0x4740) = var_s0_11;
            }
        }
    }
}

#include "m2c_macros.h"

s32 ClsgClipEdgeToBsp(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK ConvertAloPos(M2C_UNK, void *, s128);       /* extern */
s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
s32 FIsLoInWorld(void *);                           /* extern */
s32 FSensorSightBlocked(void *, void *);            /* extern */
s32 FSwBinocActive(M2C_UNK *);                      /* extern */
s128 PosLoWorld(void *);                            /* extern */
void *PpoSwFocusBase(M2C_UNK *);                    /* extern */
M2C_UNK func_00153E60(void *);                      /* extern */
s32 func_00154770(void *, void *);                  /* extern */
s32 func_00227C90(s32, s128);                       /* extern */
extern M2C_UNK B_003DD490;
extern void *B_003E1480;

s32 NNextSensorState(void *arg0, void *arg1, s32 arg2) {
    s128 sp180;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 var_s2;
    s32 var_v0;
    void *temp_s0;
    void *temp_v0;
    void *temp_v1;
    void *var_s1;
    void *var_v1;

    var_s2 = arg2;
    temp_s0 = PpoSwFocusBase(&B_003DD490);
    if ((arg1 != NULL) && (FIsLoInWorld(arg1) != 0) && ((FIsBasicDerivedFrom(arg1, 0x32) == 0) || (temp_v1 = M2C_FIELD(arg1, void **, 0xC), (M2C_FIELD(temp_v1, s32 (**)(void *), 0x26C)(arg1 + M2C_FIELD(temp_v1, s16 *, 0x268)) != 2)))) {
        if ((FIsBasicDerivedFrom(arg1, 0x34) != 0) && (temp_s0 != NULL)) {
            if (FIsBasicDerivedFrom(temp_s0, 0x46) != 0) {
                var_s2 = 0;
                goto block_72;
            }
            goto block_9;
        }
block_9:
        if (FSwBinocActive(&B_003DD490) != 0) {
            var_s2 = 0;
            goto block_72;
        }
        if (M2C_FIELD(arg0, s32 *, 0xF4) != 0) {
            var_s2 = 0;
            goto block_72;
        }
        if (FIsBasicDerivedFrom(arg1, 0x34) != 0) {
            if (M2C_FIELD(arg1, s32 *, 0x11AC) != 0) {
                var_s2 = 0;
                goto block_72;
            }
            goto block_19;
        }
block_19:
        if (M2C_FIELD(arg0, s32 *, 0xF0) != 0) {
            var_s2 = 1;
            goto block_72;
        }
        if (FIsBasicDerivedFrom(arg1, 0x33) != 0) {
            PosLoWorld(arg1);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x240($s4) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: vadd.xyzw $vf2, $vf2, $vf1 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x180($sp) */);
        } else {
            sp180 = PosLoWorld(arg1);
        }
        var_s1 = B_003E1480;
        if (var_s1 != NULL) {
loop_27:
            func_00153E60(arg0);
            ConvertAloPos(0, var_s1, M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */));
            M2C_ERROR(/* unknown instruction: por $s0, $zero, $v0 */);
            ConvertAloPos(0, var_s1, sp180);
            if (ClsgClipEdgeToBsp(M2C_FIELD(var_s1, s32 *, 0xEC), 0x7FFFFFFF, M2C_ERROR(/* unknown instruction: por $a2, $zero, $s0 */), M2C_ERROR(/* unknown instruction: por $a3, $zero, $v0 */)) > 0) {
                var_s2 = 0;
                goto block_72;
            }
            var_s1 = M2C_FIELD(var_s1, void **, 0x130);
            if (var_s1 == NULL) {
                goto block_31;
            }
            goto loop_27;
        }
block_31:
        if (var_s2 != 1) {
            if (var_s2 < 2) {
                if (var_s2 != 0) {
                    return var_s2;
                }
                temp_v0 = M2C_FIELD(arg0, void **, 0xE4);
                if (temp_v0 != NULL) {
                    var_v1 = M2C_FIELD(temp_v0, void **, 0x64);
loop_39:
                    if (var_v1 != NULL) {
                        if (M2C_FIELD(var_v1, s32 *, 0xC) != arg1) {
                            var_v1 = M2C_FIELD(var_v1, void **, 4);
                            goto loop_39;
                        }
                        var_s2 = 1;
                        if (M2C_FIELD(var_v1, s32 *, 0) == 0) {
                            goto block_44;
                        }
                    } else {
                        goto block_44;
                    }
                } else {
block_44:
                    var_s2 = 0;
                    if ((func_00227C90(M2C_FIELD(arg0, s32 *, 0xE8), sp180) != 0) && ((temp_a0 = M2C_FIELD(arg0, s32 *, 0xEC), (temp_a0 == 0)) || (var_s2 = 0, (func_00227C90(temp_a0, sp180) != 0))) && ((M2C_FIELD(arg0, s32 *, 0xF8) & 1) || (var_s2 = 0, (func_00154770(arg0, arg1) == 0)))) {
                        var_s2 = 1;
                        if (!(M2C_FIELD(arg0, s32 *, 0xF8) & 2)) {
                            var_s2 = FSensorSightBlocked(arg0, arg1) == 0;
                        }
                    }
                }
                goto block_72;
            }
            if (var_s2 != 2) {
                return var_s2;
            }
            temp_a0_2 = M2C_FIELD(arg0, s32 *, 0xEC);
            if (temp_a0_2 != 0) {
                if (func_00227C90(temp_a0_2, sp180) == 0) {
                    var_s2 = 0;
                    goto block_72;
                }
                goto block_63;
            }
block_63:
            if (func_00227C90(M2C_FIELD(arg0, s32 *, 0xE8), sp180) != 0) {
                if (M2C_FIELD(arg0, s32 *, 0xF8) & 2) {
                    var_s2 = 1;
                    goto block_72;
                }
                var_v0 = var_s2;
                if (FSensorSightBlocked(arg0, arg1) == 0) {
                    var_s2 = 1;
                    goto block_72;
                }
            } else {
                goto block_70;
            }
            /* Duplicate return node #73. Try simplifying control flow for better match */
            return var_v0;
        }
        temp_a0_3 = M2C_FIELD(arg0, s32 *, 0xEC);
        if (temp_a0_3 != 0) {
            if (func_00227C90(temp_a0_3, sp180) == 0) {
                var_s2 = 0;
            } else {
                goto block_55;
            }
        } else {
block_55:
            if (func_00227C90(M2C_FIELD(arg0, s32 *, 0xE8), sp180) != 0) {
block_70:
                if (M2C_FIELD(arg0, s32 *, 0xF8) & 8) {
                    var_s2 = (FSensorSightBlocked(arg0, arg1) != 0) ? 0 : var_s2;
                }
            } else {
                var_s2 = 2;
            }
        }
        goto block_72;
    }
    var_s2 = 0;
block_72:
    var_v0 = var_s2;
    return var_v0;
}

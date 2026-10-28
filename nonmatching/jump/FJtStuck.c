#include "m2c_macros.h"

M2C_UNK CStackFrame_Construct(void *, void **, f32); /* extern */
M2C_UNK CStackFrame_Destructor(void *, M2C_UNK, void **, M2C_UNK32 *); /* extern */
M2C_UNK32 *PvAllocStackImpl__Fi(s32 *);             /* extern */
M2C_UNK SolveInequalities(s32, M2C_UNK32 *, M2C_UNK32 *, M2C_UNK32 *, f32); /* extern */
extern f32 g_2dded0;

s32 FJtStuck(void *arg0, f32 *arg1, f32 fparg0) {
    char sp[0x400];
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
    void **var_a1;
    void **var_a2;
    void **var_a2_2;
    void **var_a2_3;
    void *var_a0;
    void *var_a0_2;
    void *var_a0_3;
    void *var_a0_4;
    void *var_v1;

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
            var_a2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xEC), void ***, 0x64);
            var_s4 = 0;
            if (var_a2 != NULL) {
                var_a0 = *var_a2;
loop_10:
                if (var_a0 != NULL) {
                    do {
                        var_a0 = M2C_FIELD(var_a0, void **, 0xAC);
                        var_s4 += 1;
                    } while (var_a0 != NULL);
                }
                var_a2 = M2C_FIELD(var_a2, void ***, 4);
                if (var_a2 != NULL) {
                    var_a0 = *var_a2;
                    goto loop_10;
                }
            }
            if (var_s4 != 0) {
                CStackFrame_Construct(sp, var_a2, temp_f12);
                temp_s2 = var_s4 * 4;
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
                M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf3, $vf1, $vf2x */);
                sp10 = var_s4 * var_s4 * 4;
                M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x20($sp) */);
                M2C_FIELD(&sp10, s32 *, 4) = 0x10;
                temp_v0 = PvAllocStackImpl__Fi(&sp10);
                sp10 = temp_s2;
                M2C_FIELD(&sp10, s32 *, 4) = 0x10;
                temp_v0_2 = PvAllocStackImpl__Fi(&sp10);
                sp10 = temp_s2;
                M2C_FIELD(&sp10, s32 *, 4) = 0x10;
                temp_s0 = PvAllocStackImpl__Fi(&sp10);
                var_a2_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xEC), void ***, 0x64);
                var_a3 = temp_v0;
                if (var_a2_2 != NULL) {
                    var_a0_2 = *var_a2_2;
loop_18:
                    if (var_a0_2 != NULL) {
                        do {
                            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x80($a0) */);
                            if (M2C_FIELD(var_a0_2, s32 *, 8) != arg0) {
                                M2C_ERROR(/* unknown instruction: qmtc2.ni $t1, $vf1 */);
                                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
                                M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf4, $vf4, $vf1x */);
                            }
                            var_a1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xEC), void ***, 0x64);
                            if (var_a1 != NULL) {
                                do {
                                    var_v1 = M2C_FIELD(var_a1, void **, 0);
                                    if (var_v1 != NULL) {
                                        M2C_ERROR(/* unknown instruction: vmove.xyzw $vf3, $vf4 */);
                                        do {
                                            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x80($v1) */);
                                            if (M2C_FIELD(var_v1, s32 *, 8) != arg0) {
                                                M2C_ERROR(/* unknown instruction: qmtc2.ni $t0, $vf1 */);
                                                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
                                                M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf2, $vf1x */);
                                            }
                                            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf2 */);
                                            M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                                            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                                            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                                            *var_a3 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
                                            var_v1 = M2C_FIELD(var_v1, void **, 0xAC);
                                            var_a3 += 4;
                                        } while (var_v1 != NULL);
                                    }
                                    var_a1 = M2C_FIELD(var_a1, void ***, 4);
                                } while (var_a1 != NULL);
                            }
                            var_a0_2 = M2C_FIELD(var_a0_2, void **, 0xAC);
                        } while (var_a0_2 != NULL);
                    }
                    var_a2_2 = M2C_FIELD(var_a2_2, void ***, 4);
                    if (var_a2_2 != NULL) {
                        var_a0_2 = *var_a2_2;
                        goto loop_18;
                    }
                    var_a2_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xEC), void ***, 0x64);
                }
                var_a3_2 = temp_v0_2;
                if (var_a2_2 != NULL) {
                    var_a0_3 = *var_a2_2;
loop_36:
                    if (var_a0_3 != NULL) {
                        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
                        do {
                            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x80($a0) */);
                            if (M2C_FIELD(var_a0_3, s32 *, 8) != arg0) {
                                M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
                                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
                                M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf2, $vf1x */);
                            }
                            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf2, $vf3 */);
                            M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                            *var_a3_2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
                            var_a0_3 = M2C_FIELD(var_a0_3, void **, 0xAC);
                            var_a3_2 += 4;
                        } while (var_a0_3 != NULL);
                    }
                    var_a2_2 = M2C_FIELD(var_a2_2, void ***, 4);
                    if (var_a2_2 != NULL) {
                        var_a0_3 = *var_a2_2;
                        goto loop_36;
                    }
                }
                SolveInequalities(var_s4, temp_v0, temp_v0_2, temp_s0, 3.4028235e38f);
                var_a3_3 = temp_s0;
                var_a2_3 = M2C_FIELD(M2C_FIELD(arg0, void **, 0xEC), void ***, 0x64);
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
                if (var_a2_3 != NULL) {
                    var_a0_4 = *var_a2_3;
loop_46:
                    if (var_a0_4 != NULL) {
                        do {
                            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x80($a0) */);
                            if (M2C_FIELD(var_a0_4, s32 *, 8) != arg0) {
                                M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
                                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
                                M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf2, $vf1x */);
                            }
                            temp_f0 = *var_a3_3;
                            var_a0_4 = M2C_FIELD(var_a0_4, void **, 0xAC);
                            var_a3_3 += 4;
                            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                            M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
                            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf3, $vf2, $vf1x */);
                            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
                        } while (var_a0_4 != NULL);
                    }
                    var_a2_3 = M2C_FIELD(var_a2_3, void ***, 4);
                    if (var_a2_3 != NULL) {
                        var_a0_4 = *var_a2_3;
                        goto loop_46;
                    }
                }
                M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf3 */);
                var_s0 = 1;
                if (!(M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $v0 */) > -0.1f)) {
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

#include "m2c_macros.h"

M2C_UNK JoltCm();            /* extern */
s32 PpoSwFocusBase();                 /* extern */
M2C_UNK TriggerJoyRumbleRumk__FP3JOY4RUMKf(); /* extern */
s32 func_001A6AF8();                        /* extern */
M2C_UNK func_001EEFC0();                 /* extern */
M2C_UNK func_001EF038();                 /* extern */
M2C_UNK func_001F7A68();             /* extern */
M2C_UNK func_00204E38();            /* extern */
void *func_00205458();               /* extern */
s32 func_00209518();                             /* extern */
M2C_UNK func_002097C8();                 /* extern */
M2C_UNK func_002097D8();                 /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK B_002DFC00;
extern M2C_UNK B_003DD490;
extern s32 g_2f7900;

s32 GoalAnim_FHandleMessage(void *arg0, s32 arg1, void *arg2) {
    M2C_UNK (*temp_a2_2)(void *, M2C_UNK, M2C_UNK);
    s32 temp_a0;
    s32 temp_a2;
    s32 temp_s2;
    s32 temp_v0;
    s32 temp_v1;
    void *temp_a0_2;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;

    if (arg1 == 9) {
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x40);
        if ((temp_a0 != 0) && (temp_v0 = func_00209518(temp_a0), (temp_v0 == M2C_FIELD(arg2, s32 *, 0)))) {
            temp_v1 = M2C_FIELD(arg2, s32 *, 8);
            if (temp_v1 != 0x2A) {
                if (temp_v1 < 0x2B) {
                    if (temp_v1 != 0x27) {
                        if (temp_v1 < 0x28) {
                            switch (temp_v1) {      /* switch 1; irregular */
                            case 37:                /* switch 1 */
                                func_002097C8(M2C_FIELD(arg0, void **, 0x10) + 0xFD0, arg0);
                                return 1;
                            case 38:                /* switch 1 */
                                func_002097D8(M2C_FIELD(arg0, void **, 0x10) + 0xFD0, arg0);
                                return 1;
                            default:                /* switch 1 */
                                return 0;
                            }
                        } else {
                            switch (temp_v1) {      /* switch 2; irregular */
                            case 41:                /* switch 2 */
                                M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x1A4) = 1;
                                return 1;
                            case 40:                /* switch 2 */
                                func_001EF038(arg0, temp_v0);
                                return 1;
                            default:                /* switch 2 */
                                return 0;
                            }
                        }
                    } else {
                        func_001EEFC0(arg0, temp_v0);
                        return 1;
                    }
                } else {
                    if (temp_v1 < 0x36) {
                        if (temp_v1 < 0x34) {
                            if (temp_v1 != 0x2F) {
                                return 0;
                            }
                            temp_v0_2 = func_00205458(M2C_FIELD(arg0, void **, 0x10), 0xA5);
                            if (temp_v0_2 != NULL) {
                                if (M2C_FIELD(temp_v0_2, s32 *, 0x30) == PpoSwFocusBase(&B_003DD490)) {
                                    TriggerJoyRumbleRumk__FP3JOY4RUMKf(&B_002DFC00, 8, 0x3F800000);
                                }
                            }
                            /* Duplicate return node #38. Try simplifying control flow for better match */
                            return 0;
                        }
                        temp_s2 = PpoSwFocusBase(&B_003DD490, temp_v0);
                        temp_v0_3 = func_00205458(M2C_FIELD(arg0, void **, 0x10), 0xA0);
                        if ((temp_v0_3 != NULL) && (func_001A6AF8(M2C_FIELD(temp_v0_3, s32 *, 0x50), temp_s2) != 0)) {
                            if (temp_s2 == g_2f7900) {
                                temp_a2 = M2C_FIELD(arg2, s32 *, 8);
                                if (temp_a2 != 0x34) {
                                    if (temp_a2 == 0x35) {
                                        JoltCm(&B_002DDF40, 0, temp_a2);
                                    }
                                } else {
                                    TriggerJoyRumbleRumk__FP3JOY4RUMKf(&B_002DFC00, 3, temp_a2, 0x3E19999A);
                                }
                            }
                        }
                        /* Duplicate return node #38. Try simplifying control flow for better match */
                        return 0;
                    }
                    if (temp_v1 != 0x36) {
                        if (temp_v1 == 0x15E) {
                            func_00204E38(M2C_FIELD(arg0, void **, 0x10), temp_v0, M2C_FIELD(arg2, f32 *, 4));
                            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
                            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf4, $vf1x */);
                            M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
                            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x190($v0) */);
                            temp_a0_2 = M2C_FIELD(arg0, void **, 0x10);
                            temp_v0_4 = M2C_FIELD(temp_a0_2, void **, 0xC);
                            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($a1) */);
                            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x1b0($a0) */);
                            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($a1) */);
                            temp_a2_2 = M2C_FIELD(temp_v0_4, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK), 0x11C);
                            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf4x */);
                            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf1, $vf4y */);
                            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf5, $vf3, $vf4z */);
                            temp_a2_2(temp_a0_2 + M2C_FIELD(temp_v0_4, s16 *, 0x118), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf5 */), temp_a2_2);
                            return 1;
                        }
                        goto block_37;
                    }
                    func_001F7A68(M2C_FIELD(arg0, void **, 0x10), 2);
                    goto block_37;
                }
            } else {
                M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x1A4) = 0;
                return 1;
            }
        } else {
            /* Duplicate return node #38. Try simplifying control flow for better match */
            return 0;
        }
    } else {
block_37:
        return 0;
    }
}

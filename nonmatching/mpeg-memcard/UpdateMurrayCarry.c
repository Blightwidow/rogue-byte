#include "m2c_macros.h"

M2C_UNK ClearVjoyPresses(void *, M2C_UNK);          /* extern */
M2C_UNK DetachMurrayObject(void *);                 /* extern */
s32 FButtonPressedWithin(void *, M2C_UNK, M2C_UNK); /* extern */
s32 FGadgetAcquired(M2C_UNK);                       /* extern */
s32 GrfbtnVjoyPressedWithin(void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SetJmpState(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SetMurrayCarryState(void *, M2C_UNK);       /* extern */
M2C_UNK SetMurrayState(void *, M2C_UNK);            /* extern */
M2C_UNK SetRunBlendU(void *, f32);                  /* extern */
M2C_UNK SetStepRadTarget(void *, f32);              /* extern */
M2C_UNK StartBinoc(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 UpdateRunBlendFootsteps(void *);                /* extern */
M2C_UNK func_00204E38(void *, void *, f32);         /* extern */

s32 UpdateMurrayCarry(void *arg0) {
    f32 temp_f1;
    s32 temp_a0;
    s32 temp_s0;
    s32 var_v0;
    void *temp_a1;
    void *temp_s0_2;
    void *temp_v0;
    void *temp_v1;

loop_1:
    temp_s0 = M2C_FIELD(arg0, s32 *, 0x1458);
    if ((temp_s0 < 3) && (temp_s0 >= 0)) {
        if (((u64) M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x13F0), void **, 0x180), u64 *, 0x28) >> 0x3C) & 1) {
            if (GrfbtnVjoyPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x40, 0x3DCCCCCD) == 0) {
                goto block_12;
            }
            if (FGadgetAcquired(0x12) != 0) {
                ClearVjoyPresses(M2C_FIELD(arg0, void **, 0x150), 0x40);
                SetJmpState(arg0 + 0x2C0, 0xF, 0, 0);
            } else {
block_12:
                if (FButtonPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0xA0, 0) != 0) {
                    SetMurrayState(arg0, 7);
                } else if ((FButtonPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x10, 0) != 0) && (M2C_FIELD(arg0, s32 *, 0x1438) != 0)) {
                    M2C_FIELD(arg0, s32 *, 0x143C) = 0;
                    SetMurrayState(arg0, 8);
                } else if ((GrfbtnVjoyPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x400, 0x3E19999A) != 0) && (temp_v1 = M2C_FIELD(arg0, void **, 0xC), (M2C_FIELD(temp_v1, s32 (**)(void *, M2C_UNK), 0x31C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x318), 3) != 0))) {
                    ClearVjoyPresses(M2C_FIELD(arg0, void **, 0x150), 0x400);
                    StartBinoc(arg0 + 0xF00, 0, 0, 0);
                } else {
                    temp_v0 = M2C_FIELD(arg0, void **, 0x150);
                    temp_f1 = M2C_FIELD(temp_v0, f32 *, 0x1C);
                    if (M2C_FIELD(arg0, s32 *, 0x1458) == 0) {
                        if (!(temp_f1 > 0.1f)) {
                            goto block_30;
                        }
                        goto block_26;
                    }
                    if (!(temp_f1 > 0.0f)) {
block_30:
                        SetMurrayCarryState(arg0, 0);
                    } else {
block_26:
                        if ((M2C_FIELD(temp_v0, s32 *, 0x30) & 8) && (FGadgetAcquired(0x12) != 0)) {
                            SetMurrayCarryState(arg0, 2);
                        } else {
                            SetMurrayCarryState(arg0, 1);
                        }
                    }
                }
            }
        } else {
            DetachMurrayObject(arg0);
            M2C_FIELD(arg0, void **, 0x13F0) = NULL;
            SetMurrayState(arg0, 0);
        }
    }
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x1458);
    if ((temp_a0 != temp_s0) && (M2C_FIELD(arg0, s32 *, 0x13D0) == 5)) {
        goto loop_1;
    }
    var_v0 = temp_a0 < 2;
    if (temp_a0 != 1) {
        if (var_v0 == 0) {
            if (temp_a0 == 2) {
                SetStepRadTarget(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x18));
                temp_a1 = M2C_FIELD(arg0, void **, 0x1030);
                func_00204E38(arg0, temp_a1, M2C_FIELD(temp_a1, f32 *, 0x1C));
                var_v0 = M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf3, $vf1x */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x190($s1) */);
                goto block_41;
            }
            return 2;
        }
        /* Duplicate return node #42. Try simplifying control flow for better match */
        return var_v0;
    }
    temp_s0_2 = arg0 + 0x1460;
    SetStepRadTarget(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x18));
    SetRunBlendU(temp_s0_2, M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x1C));
    var_v0 = UpdateRunBlendFootsteps(temp_s0_2);
block_41:
    return var_v0;
}

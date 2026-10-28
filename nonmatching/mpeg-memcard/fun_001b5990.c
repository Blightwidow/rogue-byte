#include "m2c_macros.h"

M2C_UNK ClearVjoyPresses(void *, M2C_UNK);          /* extern */
s32 FAttachGroundTarget(void *, M2C_UNK, M2C_UNK);  /* extern */
s32 FButtonPressedWithin(void *, M2C_UNK, f32);     /* extern */
s32 FJtInFocusRange(void *, M2C_UNK);               /* extern */
s32 FMurrayAttackCanChain(void *);                  /* extern */
s32 FMurrayTryGrabGuard(void *);                    /* extern */
s32 GrfbtnVjoyPressedWithin(void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SetJmpState(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SetMurrayState(void *, M2C_UNK);            /* extern */
M2C_UNK SetRunBlendU(void *, f32);                  /* extern */
M2C_UNK SetStepRadTarget(void *, f32);              /* extern */
M2C_UNK SetVectorCylind__FP6VECTORfff(f32, f32, f32, M2C_UNK); /* extern */
M2C_UNK SolvePlainBlendWeights(void *, void *, s32); /* extern */
M2C_UNK StartBinoc(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK StartMurrayAttackA(void *);                 /* extern */
M2C_UNK StartMurrayAttackB(void *);                 /* extern */
M2C_UNK UpdateRunBlendFootsteps(void *);            /* extern */
M2C_UNK func_001B5D30(void *, M2C_UNK);             /* extern */
M2C_UNK func_002046F0(void *, s32);                 /* extern */
extern f32 D_FLT_002C08DC;

void func_001B5990(void *arg0) {
    f32 temp_a0_2;
    f32 temp_f1;
    s32 temp_a0;
    s32 temp_s0;
    void *temp_s0_2;
    void *temp_v1;
    void *temp_v1_2;

loop_1:
    temp_s0 = M2C_FIELD(arg0, s32 *, 0x17F4);
    if ((temp_s0 < 3) && (temp_s0 >= 0)) {
        if (!(M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), s32 *, 0x30) & 8)) {
            if (FJtInFocusRange(arg0, 1) != 0) {
                if (FButtonPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x40, 0.1f) != 0) {
                    SetJmpState(arg0 + 0x2C0, 1, 0, 0);
                } else if (FMurrayTryGrabGuard(arg0) == 0) {
                    if (FButtonPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x20, 0.2f) != 0) {
                        if ((FAttachGroundTarget(arg0 + 0x4C0, 0x80, 0) == 0) && (M2C_FIELD(arg0, s32 *, 0x13EC) != 0)) {
                            M2C_FIELD(arg0, s32 *, 0x144C) = 0;
                            SetMurrayState(arg0, 4);
                        }
                    } else if ((FMurrayAttackCanChain(arg0) != 0) && (FButtonPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x80, D_FLT_002C08DC) != 0)) {
                        StartMurrayAttackA(arg0);
                    } else if ((GrfbtnVjoyPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x400, 0x3E19999A) != 0) && (temp_v1 = M2C_FIELD(arg0, void **, 0xC), (M2C_FIELD(temp_v1, s32 (**)(void *, M2C_UNK), 0x31C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x318), 3) != 0))) {
                        ClearVjoyPresses(M2C_FIELD(arg0, void **, 0x150), 0x400);
                        StartBinoc(arg0 + 0xF00, 0, 0, 0);
                    } else if ((FMurrayAttackCanChain(arg0) != 0) && (FButtonPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x10, D_FLT_002C08DC) != 0)) {
                        StartMurrayAttackB(arg0);
                    } else {
                        temp_f1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x1C);
                        if (M2C_FIELD(arg0, s32 *, 0x13D0) == 0) {
                            if (!(temp_f1 > 0.1f)) {
                                goto block_30;
                            }
                            goto block_29;
                        }
                        if (temp_f1 > 0.0f) {
block_29:
                            func_001B5D30(arg0, 2);
                        } else {
block_30:
                            func_001B5D30(arg0, 0);
                        }
                    }
                }
            } else {
                goto block_8;
            }
        } else {
block_8:
            SetMurrayState(arg0, 0);
        }
    }
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x17F4);
    if ((temp_a0 != temp_s0) && (M2C_FIELD(arg0, s32 *, 0x13D0) == 9)) {
        goto loop_1;
    }
    switch (temp_a0) {                              /* irregular */
    case 0:
        func_002046F0(arg0, M2C_FIELD(arg0, s32 *, 0x10DC));
        return;
    case 2:
        func_002046F0(arg0, M2C_FIELD(arg0, s32 *, 0x10DC));
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x1720($s1) */);
        temp_v1_2 = M2C_FIELD(arg0, void **, 0x150);
        M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        temp_a0_2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf1 */);
        SetVectorCylind__FP6VECTORfff(temp_a0_2, M2C_FIELD(temp_v1_2, f32 *, 0x18) + 3.1415927f, M2C_FIELD(temp_v1_2, f32 *, 0x1C) * temp_a0_2 * M2C_FIELD(M2C_FIELD(arg0, void **, 0x1030), f32 *, 0x40), 0);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x190($s1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x1b0($s1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($v0) */);
        M2C_ERROR(/* unknown instruction: vmul.xyzw $vf7, $vf3, $vf4 */);
        M2C_ERROR(/* unknown instruction: vmaxw.xyzw $vf8, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vmul.xyzw $vf6, $vf1, $vf4 */);
        M2C_ERROR(/* unknown instruction: vmul.xyzw $vf5, $vf2, $vf4 */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf7, $vf7y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf3, $vf8, $vf7z */);
        M2C_ERROR(/* unknown instruction: vaddax.y $acc, $vf6, $vf6x */);
        M2C_ERROR(/* unknown instruction: vmaddz.y $vf3, $vf8, $vf6z */);
        M2C_ERROR(/* unknown instruction: vaddax.z $acc, $vf5, $vf5x */);
        M2C_ERROR(/* unknown instruction: vmaddy.z $vf3, $vf8, $vf5y */);
        M2C_FIELD(arg0, s32 *, 0x1038) = -1;
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x190($s1) */);
        SolvePlainBlendWeights(arg0, arg0 + 0x16F0, M2C_FIELD(arg0, s32 *, 0x17F0));
        break;
    case 1:
        temp_s0_2 = arg0 + 0x1630;
        SetStepRadTarget(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x18));
        SetRunBlendU(temp_s0_2, M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x1C));
        UpdateRunBlendFootsteps(temp_s0_2);
        break;
    }
}

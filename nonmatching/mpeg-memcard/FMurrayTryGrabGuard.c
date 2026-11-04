#include "m2c_macros.h"

s32 FButtonPressedWithin();    /* extern */
s32 FCheckLm__FP2LMf();           /* extern */
s32 FIsGuardInSgs();                 /* extern */
M2C_UNK GoalAnimLeap_SetState();     /* extern */
void *GoalStack_PgoalFind();         /* extern */
s32 GrfbtnVjoyPressedWithin(); /* extern */
s128 PosLoWorld();                      /* extern */
M2C_UNK SetMurrayAttackState();      /* extern */
M2C_UNK SetMurrayState();            /* extern */
M2C_UNK StartMurrayLiftGuard();          /* extern */
extern M2C_UNK D_002C09B0;
extern M2C_UNK D_002C09C0;
extern f32 D_FLT_002C09AC;
extern f32 D_FLT_002C09B8;

s32 FMurrayTryGrabGuard(void *arg0) {
    s32 var_s1;
    s32 var_s2;
    s32 var_v0;
    void *temp_a0;
    void *temp_v0;

    temp_a0 = M2C_FIELD(arg0, void **, 0x10DC);
    var_v0 = 0;
    if (temp_a0 != NULL) {
        if ((FIsGuardInSgs(temp_a0, 0x17) != 0) && (GrfbtnVjoyPressedWithin(M2C_FIELD(arg0, s32 *, 0x150), 0xA0, 0x3E19999A) != 0)) {
            temp_v0 = GoalStack_PgoalFind(M2C_FIELD(arg0, void **, 0x10DC) + 0x26C, 0xB1);
            if (M2C_FIELD(temp_v0, s32 *, 0x50) < 3) {
                var_v0 = 0;
                if (M2C_FIELD(temp_v0, s32 *, 0x5C) == arg0) {
                    var_s2 = 0;
                    PosLoWorld(arg0, PosLoWorld(M2C_FIELD(arg0, void **, 0x10DC)));
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($sp) */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf1, $vf2 */);
                    M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf2, $vf2 */);
                    M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                    M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
                    if ((M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < D_FLT_002C09AC) && (FCheckLm__FP2LMf(&D_002C09B0, M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $v0 */)) != 0) && (M2C_FIELD(M2C_FIELD(arg0, void **, 0x10DC), s32 *, 0xFEC) != 0)) {
                        var_s2 = FButtonPressedWithin(M2C_FIELD(arg0, s32 *, 0x150), 0x20, 0x3E19999A) != 0;
                    }
                    if (var_s2 != 0) {
                        GoalAnimLeap_SetState(temp_v0, 2);
                        StartMurrayLiftGuard(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x10DC), s32 *, 0xFEC));
                        goto block_20;
                    }
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
                    M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf2, $vf2 */);
                    M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                    var_s1 = 0;
                    M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
                    if ((M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < D_FLT_002C09B8) && (FCheckLm__FP2LMf(&D_002C09C0, M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $v0 */)) != 0) && (M2C_FIELD(arg0, s32 *, 0x180C) != 0)) {
                        var_s1 = FButtonPressedWithin(M2C_FIELD(arg0, s32 *, 0x150), 0x80, 0x3E19999A) != 0;
                    }
                    if (var_s1 != 0) {
                        SetMurrayState(arg0, 0xB);
                        SetMurrayAttackState(arg0, 4);
block_20:
                        var_v0 = 1;
                        /* Duplicate return node #21. Try simplifying control flow for better match */
                        return var_v0;
                    }
                    goto block_6;
                }
                /* Duplicate return node #21. Try simplifying control flow for better match */
                return var_v0;
            }
            goto block_6;
        }
block_6:
        return 0;
    }
    return var_v0;
}

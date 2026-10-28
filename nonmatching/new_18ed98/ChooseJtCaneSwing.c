#include "m2c_macros.h"

s32 FCheckJtCaneSide();                       /* extern */
s32 FCheckLm__FP2LMf();           /* extern */
void *GoalStack_PgoalFind();         /* extern */
s128 PosLoWorld();                      /* extern */
f32 RadNormalize__Ff();                          /* extern */
M2C_UNK SetJtState();       /* extern */
f32 atan2f();                               /* extern */
extern M2C_UNK D_002BF4B0;
extern f32 D_FLT_002BF4AC;

s32 ChooseJtCaneSwing(void *arg0) {
    f32 *temp_s0;
    f32 temp_f0;
    f32 temp_f1;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_s0;
    s32 var_v0;
    void *temp_a0;
    void *temp_v0;
    void *temp_v1_2;
    void *temp_v1_3;

    temp_a0 = M2C_FIELD(arg0, void **, 0x10DC);
    if (temp_a0 != NULL) {
        PosLoWorld(arg0, PosLoWorld(temp_a0));
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf1, $vf3 */);
        M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf2, $vf2 */);
        M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        var_v0 = 0;
        if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < D_FLT_002BF4AC) {
            M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
            var_v0 = FCheckLm__FP2LMf(&D_002BF4B0, M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $v0 */)) != 0;
        }
        if (var_v0 != 0) {
            temp_v0 = GoalStack_PgoalFind(M2C_FIELD(arg0, void **, 0x10DC) + 0x26C, 0xB1);
            if ((temp_v0 != NULL) && (M2C_FIELD(temp_v0, s32 *, 0x5C) == arg0)) {
                temp_v1 = M2C_FIELD(temp_v0, s32 *, 0x50);
                if ((temp_v1 < 2) && (temp_v1 >= 0)) {
                    SetJtState(arg0, 0x10, -1);
                    return -1;
                }
            }
        }
        goto block_9;
    }
block_9:
    if (M2C_FIELD(arg0, s32 *, 0x18D0) != 5) {
        var_s0 = (M2C_FIELD(arg0, s32 *, 0x18C8) == 0) ? 0xC : 0xE;
    } else {
        temp_v1_2 = M2C_FIELD(arg0, void **, 0xC);
        temp_v1_3 = M2C_FIELD(arg0, void **, 0xC);
        temp_s0 = M2C_FIELD(temp_v1_2, f32 *(**)(void *), 0xFC)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0xF8));
        temp_f0 = RadNormalize__Ff(M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), f32 *, 0x18) - atan2f(M2C_FIELD(temp_s0, f32 *, 4), *M2C_FIELD(temp_v1_3, f32 *(**)(void *), 0xFC)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0xF8))));
        temp_f1 = fabsf(temp_f0);
        var_s0 = 0xE;
        if (!(temp_f1 < 0.7853982f)) {
            var_s0 = 0x10;
            if (!(temp_f1 > 2.3561945f)) {
                var_s0 = 0x14;
                if (temp_f0 > 0.0f) {
                    var_s0 = 0x12;
                }
            }
        }
    }
    temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x18D8);
    switch (temp_v0_2) {
    case 12:
    case 14:
    case 16:
    case 18:
    case 20:
        var_s0 += 1;
        break;
    default:
        var_s0 = (FCheckJtCaneSide(arg0) != 0) ? (var_s0 + 1) : var_s0;
        break;
    }
    return var_s0;
}

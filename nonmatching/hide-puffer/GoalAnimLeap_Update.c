#include "m2c_macros.h"

M2C_UNK GoalAnimLeap_SetState();     /* extern */
M2C_UNK GoalAnim_Update();                          /* extern */
s128 PosLoWorld();                       /* extern */
M2C_UNK PredictXfTransform(); /* extern */
M2C_UNK func_0017ABC8();                 /* extern */
extern f32 D_FLT_002BE6C8;
extern f32 D_FLT_002BE6CC;
extern M2C_UNK g_2dded0;

void GoalAnimLeap_Update(void *arg0) {
    char sp[0x400];
    M2C_UNK sp30;
    M2C_UNK sp70;
    M2C_UNK unksp48;
    M2C_UNK unksp58;
    M2C_UNK unksp68;
    s128 sp40;
    s128 sp50;
    s128 sp60;
    f32 sp78;
    void *temp_a0;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_a2;
    void *temp_v0;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;

    GoalAnim_Update();
    temp_a1 = M2C_FIELD(arg0, void **, 0x10);
    temp_v1 = M2C_FIELD(temp_a1, void **, 0xC);
    M2C_FIELD(temp_v1, M2C_UNK (**)(void *, void *), 0x10C)(temp_a1 + M2C_FIELD(temp_v1, s16 *, 0x108), temp_a1);
    M2C_ERROR(/* unknown instruction: por $s4, $zero, $v0 */);
loop_1:
    switch (M2C_FIELD(arg0, u32 *, 0x50)) {
    case 0:
    case 1:
        temp_v1_2 = M2C_FIELD(arg0, void **, 0x10);
        if ((M2C_FIELD(arg0, u32 *, 0x50) != 1) || (M2C_FIELD(temp_v1_2, s32 *, 0x208) == 0)) {
            temp_a0 = M2C_FIELD(M2C_FIELD(temp_v1_2, void **, 0x58), void **, 0x90);
            if ((temp_a0 != M2C_FIELD(arg0, s32 *, 0x64)) || (M2C_FIELD(temp_a0, f32 *, 0x1C) < M2C_FIELD(&g_2dded0, f32 *, 0))) {
                GoalAnimLeap_SetState(arg0, 2);
            } else if ((M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s4 */) < 0.0f) && (M2C_FIELD(arg0, u32 *, 0x50) == 0)) {
                GoalAnimLeap_SetState(arg0, 1);
            } else {
                func_0017ABC8(arg0, M2C_FIELD(arg0, u32 *, 0x50));
            }
        } else {
block_13:
            GoalAnimLeap_SetState(arg0, 3);
        }
        break;
    case 2:
        if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x208) != 0) {
            goto block_13;
        }
        break;
    case 4:
    case 5:
        sp40 = PosLoWorld(M2C_FIELD(arg0, void **, 0x10), M2C_FIELD(arg0, u32 *, 0x50));
        temp_a1_2 = M2C_FIELD(arg0, void **, 0x10);
        temp_v1_3 = M2C_FIELD(temp_a1_2, void **, 0xC);
        sp50 = M2C_FIELD(temp_v1_3, s128 (**)(void *, void *), 0x10C)(temp_a1_2 + M2C_FIELD(temp_v1_3, s16 *, 0x108), temp_a1_2);
        PredictXfTransform(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), void **, 0x19A4), s32 *, 0x60), 0, sp, 0, M2C_FIELD(&g_2dded0, M2C_UNK32 *, 4));
        sp60 = sp30;
        unksp68 += D_FLT_002BE6C8;
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x60($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x90($sp) */);
        PosLoWorld(M2C_FIELD(arg0, void **, 0x10));
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x90($sp) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $s0, $vf2 */);
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf1, $q */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x80($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x70($sp) */);
        if (M2C_FIELD(arg0, u32 *, 0x50) == 4) {
            if ((unksp48 < unksp68) || (D_FLT_002BE6CC < (M2C_FIELD(&g_2dded0, f32 *, 0) - M2C_FIELD(arg0, f32 *, 0x54)))) {
                GoalAnimLeap_SetState(arg0, 5);
            } else {
                sp78 = unksp58;
                goto block_19;
            }
        } else {
block_19:
            temp_a2 = M2C_FIELD(arg0, void **, 0x10);
            temp_v0 = M2C_FIELD(temp_a2, void **, 0xC);
            M2C_FIELD(temp_v0, M2C_UNK (**)(void *, s128, void *), 0x11C)(temp_a2 + M2C_FIELD(temp_v0, s16 *, 0x118), sp70, temp_a2);
        }
        break;
    case 6:
        if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x208) != 0) {
            GoalAnimLeap_SetState(arg0, -1);
        }
        break;
    }
    if (M2C_FIELD(arg0, u32 *, 0x50) != M2C_FIELD(arg0, u32 *, 0x50)) {
        goto loop_1;
    }
}

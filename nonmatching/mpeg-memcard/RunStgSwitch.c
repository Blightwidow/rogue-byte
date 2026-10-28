#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
s32 FStgSwitchDone();                               /* extern */
s32 FStgSwitchInStageRange(void *);                 /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
s32 PpoSwFocusBase(M2C_UNK *);                      /* extern */
M2C_UNK RunStgSwitchStage(void *, void *);          /* extern */
M2C_UNK SpawnSwHitFx(void *, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK bevy_camera_follow_activity(M2C_UNK *, M2C_UNK, void *); /* extern */
extern M2C_UNK B_002DEB30;
extern M2C_UNK B_003DD490;

void RunStgSwitch(void *arg0) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a1;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 temp_v1_4;
    s32 var_a0;
    s32 var_v0;
    void *temp_s2;
    void *temp_v0;
    void *temp_v1_2;
    void *temp_v1_3;

    if (FStgSwitchDone() == 0) {
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x16C);
        if (temp_a0 != PpoSwFocusBase(&B_003DD490)) {
            temp_v1 = M2C_FIELD(arg0, s32 *, 0x170);
            if ((temp_v1 != 0x100) && (temp_v1 != 0x10000)) {
                var_v0 = 8;
                if (temp_v1 != 0x20000) {
                    if (temp_a0 == 0) {
                        M2C_FIELD(arg0, s32 *, 0x168) = 0;
                    } else if (FIsBasicDerivedFrom(temp_a0, 0x3B) == 0) {
                        M2C_FIELD(arg0, s32 *, 0x168) = 0;
                    } else {
                        goto block_14;
                    }
                } else {
                    goto block_15;
                }
            } else {
block_14:
                var_v0 = 8;
                goto block_15;
            }
        } else {
            var_v0 = 0xE;
block_15:
            M2C_FIELD(arg0, s32 *, 0x168) = var_v0;
        }
        temp_v0 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x18), 0x10, 0, 0);
        if (!(M2C_FIELD(arg0, s32 *, 0x168) & 1)) {
            temp_a1 = M2C_FIELD(arg0, s32 *, 0x164);
            temp_s2 = temp_a1 + (M2C_FIELD(arg0, s32 *, 0x15C) * 0x10);
            RunStgSwitchStage(arg0, temp_a1 - 0x10);
            RunStgSwitchStage(arg0, temp_s2);
            temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x16C);
            if (temp_a0_2 != 0) {
                if (FIsBasicDerivedFrom(temp_a0_2, 0x38) != 0) {
                    if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s32 *, 0x16C), 0x3C) != 0) {
                        goto block_20;
                    }
                } else {
                    goto block_21;
                }
            } else {
block_20:
block_21:
                PosLoWorld(arg0);
                SpawnSwHitFx(&B_003DD490 - 0x2B70, 0, M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */), M2C_FIELD(arg0, s32 *, 0x16C));
            }
            if (M2C_FIELD(temp_s2, s32 *, 4) > 0) {
                temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x158) + 1;
                M2C_FIELD(arg0, s32 *, 0x158) = temp_v0_2;
                if (temp_v0_2 >= M2C_FIELD(temp_s2, s32 *, 4)) {
                    temp_v0_3 = M2C_FIELD(arg0, s32 *, 0x15C) + 1;
                    M2C_FIELD(arg0, s32 *, 0x158) = 0;
                    M2C_FIELD(arg0, s32 *, 0x15C) = temp_v0_3;
                    if (temp_v0_3 >= M2C_FIELD(arg0, s32 *, 0x160)) {
                        temp_v1_2 = M2C_FIELD(arg0, void **, 0xC);
                        M2C_FIELD(temp_v1_2, M2C_UNK (**)(void *, M2C_UNK, void *), 0x24)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x20), 0x10, arg0);
                        temp_v1_3 = M2C_FIELD(arg0, void **, 0xC);
                        M2C_FIELD(temp_v1_3, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v1_3, s16 *, 0x18), 5, 0, 0);
                        bevy_camera_follow_activity(&B_002DEB30, 0x11, arg0);
                    }
                }
            }
            if ((FStgSwitchInStageRange(arg0) != 0) && (M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x164) + (M2C_FIELD(arg0, s32 *, 0x15C) * 0x10)), s32 *, 4) <= 0)) {
                var_a0 = 0;
                if (M2C_FIELD(arg0, s32 *, 0x150) > 0) {
loop_30:
                    temp_v1_4 = var_a0 * 8;
                    var_a0 += 1;
                    M2C_FIELD((temp_v1_4 + M2C_FIELD(arg0, s32 *, 0x154)), s32 *, 4) = 0;
                    if (var_a0 < M2C_FIELD(arg0, s32 *, 0x150)) {
                        goto loop_30;
                    }
                }
            }
        }
    }
}

#include "m2c_macros.h"

M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK SetGuardDamageState(void *, M2C_UNK);       /* extern */
extern f32 D_FLT_002C3E58;
extern f32 g_2dded0;

void UpdateGuardDamage(void *arg0) {
    s32 temp_s3;
    s32 var_s4;
    void *temp_a0;
    void *temp_a1;
    void *temp_a2;
    void *temp_a2_2;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_s1;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;

    if (M2C_FIELD(arg0, s32 *, 0x10) != 0) {
        do {
            temp_s3 = M2C_FIELD(arg0, s32 *, 4);
            switch (temp_s3) {                      /* irregular */
            case 0:
                temp_v0 = M2C_FIELD(arg0, void **, 0xC);
                var_s4 = 0;
                if (temp_v0 != NULL) {
                    temp_s0 = M2C_FIELD(temp_v0, void **, 0xC);
                    temp_s0_2 = temp_s0 + 0x248;
                    temp_s1 = temp_v0 + M2C_FIELD(temp_s0, s16 *, 0x248);
                    PosLoWorld(M2C_FIELD(arg0, void **, 0));
                    if (M2C_FIELD(temp_s0_2, s32 (**)(void *, M2C_UNK), 4)(temp_s1, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */)) != 0) {
                        temp_a1 = M2C_FIELD(arg0, void **, 0);
                        temp_v1 = M2C_FIELD(temp_a1, void **, 0xC);
                        M2C_FIELD(temp_v1, M2C_UNK (**)(void *, void *), 0x10C)(temp_a1 + M2C_FIELD(temp_v1, s16 *, 0x108), temp_a1);
                        if (M2C_ERROR(/* unknown instruction: pextuw $v1, $zero, $v0 */) < 0.0f) {
                            var_s4 = 1;
                        }
                    }
                    if (var_s4 != 0) {
                        SetGuardDamageState(arg0, 1);
                    }
                }
                break;
            case 2:
                temp_v0_2 = M2C_FIELD(arg0, void **, 0xC);
                if ((temp_v0_2 == NULL) || (temp_a2 = M2C_FIELD(arg0, void **, 0), temp_v1_2 = M2C_FIELD(temp_a2, void **, 0xC), (M2C_FIELD(temp_v1_2, s32 (**)(void *, s32, void *), 0x264)(temp_a2 + M2C_FIELD(temp_v1_2, s16 *, 0x260), M2C_FIELD(temp_v0_2, s32 *, 0x188), temp_a2) != 0))) {
                    SetGuardDamageState(arg0, 0);
                }
                break;
            case 1:
                temp_a0 = M2C_FIELD(arg0, void **, 0xC);
                if (temp_a0 == NULL) {
                    SetGuardDamageState(arg0, 0);
                } else if (D_FLT_002C3E58 < (g_2dded0 - M2C_FIELD(arg0, f32 *, 8))) {
                    temp_a2_2 = M2C_FIELD(arg0, void **, 0);
                    temp_v1_3 = M2C_FIELD(temp_a2_2, void **, 0xC);
                    if (M2C_FIELD(temp_v1_3, s32 (**)(void *, s32, void *), 0x264)(temp_a2_2 + M2C_FIELD(temp_v1_3, s16 *, 0x260), M2C_FIELD(temp_a0, s32 *, 0x188), temp_a2_2) == 0) {
                        SetGuardDamageState(arg0, 2);
                    }
                }
                break;
            }
        } while (M2C_FIELD(arg0, s32 *, 4) != temp_s3);
    }
}

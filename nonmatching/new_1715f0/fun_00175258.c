#include "m2c_macros.h"

M2C_UNK GoalAnim_Update();                          /* extern */
M2C_UNK PosLoWorld(s32);                            /* extern */
M2C_UNK SetJumperTarget(s32, M2C_UNK);              /* extern */

void func_00175258(void *arg0) {
    void *temp_s0;
    void *temp_v0;

    GoalAnim_Update();
    temp_v0 = M2C_FIELD(arg0, void **, 0x40);
    if ((temp_v0 == NULL) || (M2C_FIELD(temp_v0, s32 *, 8) == 0)) {
        M2C_FIELD(arg0, s32 *, 0x50) = 0;
    }
    if (M2C_FIELD(arg0, s32 *, 0x50) != 0) {
        temp_s0 = M2C_FIELD(arg0, void **, 0x40);
        PosLoWorld(M2C_FIELD(arg0, s32 *, 0x38));
        SetJumperTarget(M2C_FIELD(temp_s0, s32 *, 8), M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
    }
}

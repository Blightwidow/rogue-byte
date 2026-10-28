#include "m2c_macros.h"

M2C_UNK AddGuardSgs(s32, s32);                      /* extern */
M2C_UNK GoalAnim_SetState(void *, M2C_UNK);         /* extern */
s32 PguardanimCurrent(s32);                         /* extern */
M2C_UNK func_001EEF70();                            /* extern */

void func_00174950(void *arg0) {
    s32 temp_v0;

    func_001EEF70();
    AddGuardSgs(M2C_FIELD(arg0, s32 *, 0x10), M2C_FIELD(arg0, s32 *, 0x3C));
    if (M2C_FIELD(arg0, s32 *, 0x40) == 0) {
        temp_v0 = PguardanimCurrent(M2C_FIELD(arg0, s32 *, 0x10));
        M2C_FIELD(arg0, s32 *, 0x40) = temp_v0;
        if (temp_v0 == 0) {
            GoalAnim_SetState(arg0, 1);
            return;
        }
        goto block_4;
    }
block_4:
    GoalAnim_SetState(arg0, 0);
}

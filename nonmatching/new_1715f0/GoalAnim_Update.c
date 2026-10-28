#include "m2c_macros.h"

s32 FDoneAnimref(s32);                              /* extern */
M2C_UNK GoalAnim_SetState(void *, M2C_UNK);         /* extern */
M2C_UNK func_001EEF98();                            /* extern */

void GoalAnim_Update(void *arg0) {
    func_001EEF98();
loop_1:
    if ((M2C_FIELD(arg0, s32 *, 0x30) == 0) && (FDoneAnimref(M2C_FIELD(arg0, s32 *, 0x40)) != 0)) {
        GoalAnim_SetState(arg0, 1);
    }
    if (M2C_FIELD(arg0, s32 *, 0x30) != M2C_FIELD(arg0, s32 *, 0x30)) {
        goto loop_1;
    }
}

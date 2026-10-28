#include "m2c_macros.h"

M2C_UNK GoalNotice_SetState(void *, M2C_UNK);       /* extern */
M2C_UNK func_001EEF70();                            /* extern */
M2C_UNK func_00208540(s32, s32);                    /* extern */

void func_00175790(void *arg0) {
    func_001EEF70();
    GoalNotice_SetState(arg0, 3);
    func_00208540(M2C_FIELD(arg0, s32 *, 0x10), M2C_FIELD(arg0, s32 *, 0x30));
}

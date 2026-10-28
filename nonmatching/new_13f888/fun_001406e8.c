#include "m2c_macros.h"

M2C_UNK GoalStack_Clear(s32);                       /* extern */
M2C_UNK SetPoPlayable();                            /* extern */
M2C_UNK func_001F82B8(s32, M2C_UNK, M2C_UNK);       /* extern */

void func_001406E8(s32 arg0, s32 arg1) {
    SetPoPlayable();
    func_001F82B8(arg0, ((arg1 ^ 1) == 0) ? 0 : -1, 0);
    if (arg1 == 1) {
        GoalStack_Clear(arg0 + 0x26C);
    }
}

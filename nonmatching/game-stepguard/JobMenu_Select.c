#include "m2c_macros.h"

M2C_UNK Menu_ClearDialog();                         /* extern */

void JobMenu_Select(void *arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_v1;
    s32 var_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x48);
    temp_v1 = temp_v0 - 1;
    if (temp_v0 == 0) {
        var_v0 = -1;
    } else {
        var_v0 = 0;
        if (arg1 >= 0) {
            var_v0 = (temp_v1 >= arg1) ? arg1 : temp_v1;
        }
    }
    M2C_FIELD(arg0, s32 *, 0x118) = var_v0;
    Menu_ClearDialog();
}

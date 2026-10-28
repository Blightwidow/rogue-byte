#include "m2c_macros.h"

M2C_UNK Chaser_SetState(s32, M2C_UNK);              /* extern */
M2C_UNK func_0017F170();                            /* extern */

void Chaser_OnAdd(s32 arg0) {
    func_0017F170();
    Chaser_SetState(arg0, 0);
}

#include "m2c_macros.h"

M2C_UNK Chaser_SetState(s32, M2C_UNK);              /* extern */
M2C_UNK func_0017F6B0();                            /* extern */

void Chaser_Reset(s32 arg0) {
    func_0017F6B0();
    Chaser_SetState(arg0, 0);
}

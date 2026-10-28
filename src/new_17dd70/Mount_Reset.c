#include "m2c_macros.h"

M2C_UNK Mount_SetState(s32, M2C_UNK);               /* extern */
M2C_UNK func_0017F110();                            /* extern */

void Mount_Reset(s32 arg0) {
    func_0017F110();
    Mount_SetState(arg0, -1);
}

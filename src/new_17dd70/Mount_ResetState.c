#include "m2c_macros.h"

s32 FIsPoSwFocus(s32);                              /* extern */
M2C_UNK Mount_SetState(s32, M2C_UNK);               /* extern */
M2C_UNK Mount_UpdateHealthBlot(s32);                /* extern */
M2C_UNK func_0017F6B0();                            /* extern */

void Mount_ResetState(s32 arg0) {
    func_0017F6B0();
    if (FIsPoSwFocus(arg0) != 0) {
        Mount_SetState(arg0, 1);
    } else {
        Mount_SetState(arg0, 0);
    }
    Mount_UpdateHealthBlot(arg0);
}

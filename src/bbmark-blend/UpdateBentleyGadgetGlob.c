#include "m2c_macros.h"

s32 FIsPoSwFocusBase(s32);                          /* extern */
s32 GrfbtnJtGadget(s32, M2C_UNK);                   /* extern */
M2C_UNK func_00141E70();                            /* extern */
M2C_UNK func_001F6978(s32, M2C_UNK);                /* extern */
M2C_UNK func_001F69F8(s32, M2C_UNK);                /* extern */

void UpdateBentleyGadgetGlob(s32 arg0) {
    func_00141E70();
    if ((FIsPoSwFocusBase(arg0) != 0) && (GrfbtnJtGadget(arg0, 0xC) != 0)) {
        func_001F6978(arg0, 0x24D);
        return;
    }
    func_001F69F8(arg0, 0x24D);
}

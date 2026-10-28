#include "m2c_macros.h"

M2C_UNK SetAmmopickupState(s32, M2C_UNK);           /* extern */
M2C_UNK func_001CB518();                            /* extern */

void OnAmmopickupPoolClaim(s32 arg0) {
    func_001CB518();
    SetAmmopickupState(arg0, -1);
    SetAmmopickupState(arg0, 0);
}

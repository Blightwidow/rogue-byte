#include "m2c_macros.h"

M2C_UNK SetAmmopickupState(void *, M2C_UNK);        /* extern */
M2C_UNK UpdateSo();                                 /* extern */

void UpdateAmmopickup(void *arg0) {
    UpdateSo();
    if ((M2C_FIELD(arg0, s32 *, 0x150) == 0) && (M2C_FIELD(M2C_FIELD(arg0, void **, 0x58), s16 *, 0x98) == 3)) {
        SetAmmopickupState(arg0, 1);
    }
}

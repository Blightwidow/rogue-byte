#include "m2c_macros.h"

M2C_UNK RemoveSoLoHierarchy();                      /* extern */
M2C_UNK SetButtonButtons(void *, M2C_UNK);          /* extern */

void func_001492B0(void *arg0) {
    RemoveSoLoHierarchy();
    if ((u32) (M2C_FIELD(arg0, s32 *, 0x1E0) - 1) < 2U) {
        SetButtonButtons(arg0, 0);
    }
}

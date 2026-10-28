#include "m2c_macros.h"

M2C_UNK SetSearchState(s32, M2C_UNK);               /* extern */
M2C_UNK func_001EEF70();                            /* extern */

void func_00171FA0(s32 arg0) {
    func_001EEF70();
    SetSearchState(arg0, 0);
}

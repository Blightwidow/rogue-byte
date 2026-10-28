#include "m2c_macros.h"

M2C_UNK SetXfKind(void *, s32, M2C_UNK);            /* extern */
M2C_UNK func_00174B28();                            /* extern */

void func_00175090(void *arg0) {
    void *temp_a0;
    void *temp_a0_2;

    func_00174B28();
    temp_a0 = M2C_FIELD(arg0, void **, 0x10);
    SetXfKind(temp_a0, M2C_FIELD(temp_a0, s32 *, 0x58), 2);
    if (M2C_FIELD(arg0, s32 *, 0x38) == 0) {
        temp_a0_2 = M2C_FIELD(arg0, void **, 0x10);
        SetXfKind(temp_a0_2, M2C_FIELD(temp_a0_2, s32 *, 0x5C), 2);
    }
}

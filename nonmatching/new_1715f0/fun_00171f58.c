#include "m2c_macros.h"

M2C_UNK AddGuardSgs(s32, M2C_UNK);                  /* extern */
M2C_UNK func_001EEF68();                            /* extern */

void func_00171F58(void *arg0) {
    func_001EEF68();
    AddGuardSgs(M2C_FIELD(arg0, s32 *, 0x10), 0x1F);
    M2C_FIELD(arg0, s32 *, 0x30) = -1;
    M2C_FIELD(arg0, f32 *, 0x40) = 3.4028235e38f;
    M2C_FIELD(arg0, f32 *, 0x38) = 3.4028235e38f;
}

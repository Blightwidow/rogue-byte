#include "m2c_macros.h"

M2C_UNK AddGuardSgs(s32, M2C_UNK);                  /* extern */
M2C_UNK func_001EEF68();                            /* extern */

void func_0017EB48(void *arg0) {
    func_001EEF68();
    M2C_FIELD(arg0, f32 *, 0x38) = -1.0f;
    AddGuardSgs(M2C_FIELD(arg0, s32 *, 0x10), 0x2E);
}

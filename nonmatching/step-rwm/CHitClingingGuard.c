#include "m2c_macros.h"

s32 FIsGuardInSgs(M2C_UNK);                         /* extern */
void *func_00205458(s32, M2C_UNK);                  /* extern */

s32 CHitClingingGuard(s32 arg0) {
    if (FIsGuardInSgs(0x17) == 0) {
        return 0;
    }
    return M2C_FIELD(func_00205458(arg0, 0xB1), s32 *, 0x58);
}

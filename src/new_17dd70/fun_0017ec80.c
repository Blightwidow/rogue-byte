#include "m2c_macros.h"

M2C_UNK Goal_Deactivate();                          /* extern */
M2C_UNK RemoveGuardSgs(s32, M2C_UNK);               /* extern */

void func_0017EC80(void *arg0) {
    Goal_Deactivate();
    RemoveGuardSgs(M2C_FIELD(arg0, s32 *, 0x10), 0x2E);
}

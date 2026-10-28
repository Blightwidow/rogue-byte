#include "m2c_macros.h"

M2C_UNK AddGuardSgs(s32, M2C_UNK);                  /* extern */
M2C_UNK func_001EEF68();                            /* extern */

void InitGuardScriptBeh(void *arg0) {
    func_001EEF68();
    AddGuardSgs(M2C_FIELD(arg0, s32 *, 0x10), 0x21);
}

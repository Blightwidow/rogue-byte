#include "m2c_macros.h"

M2C_UNK Goal_Deactivate();                          /* extern */
M2C_UNK RemoveGuardSgs(s32, M2C_UNK);               /* extern */
M2C_UNK SetGuardScript(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_001EF038(void *);                      /* extern */

void ExitGuardScriptBeh(void *arg0) {
    Goal_Deactivate();
    func_001EF038(arg0);
    SetGuardScript(arg0, 0, 0, 0);
    RemoveGuardSgs(M2C_FIELD(arg0, s32 *, 0x10), 0x21);
}

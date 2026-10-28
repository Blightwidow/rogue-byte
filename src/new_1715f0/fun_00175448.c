#include "m2c_macros.h"

M2C_UNK Goal_Deactivate();                          /* extern */
M2C_UNK RemoveGuardSgs(s32, M2C_UNK);               /* extern */
M2C_UNK func_00175488(void *, M2C_UNK);             /* extern */

void func_00175448(void *arg0) {
    Goal_Deactivate();
    func_00175488(arg0, -1);
    RemoveGuardSgs(M2C_FIELD(arg0, s32 *, 0x10), 0x18);
}

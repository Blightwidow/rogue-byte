#include "m2c_macros.h"

M2C_UNK Goal_Deactivate();                          /* extern */
M2C_UNK RemoveGuardSgs(s32, M2C_UNK);               /* extern */
M2C_UNK func_00155788(void *, M2C_UNK);             /* extern */
M2C_UNK func_00208540(s32, M2C_UNK);                /* extern */

void func_00155598(void *arg0) {
    Goal_Deactivate();
    func_00155788(arg0, -1);
    RemoveGuardSgs(M2C_FIELD(arg0, s32 *, 0x10), 0x22);
    func_00208540(M2C_FIELD(arg0, s32 *, 0x10), 0);
}

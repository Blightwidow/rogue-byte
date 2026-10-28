#include "m2c_macros.h"

M2C_UNK Goal_Deactivate();                          /* extern */
M2C_UNK RemoveGuardSgs(void *, M2C_UNK);            /* extern */
M2C_UNK ResetSensorStates(s32);                     /* extern */
M2C_UNK func_0017E278(void *, M2C_UNK);             /* extern */
M2C_UNK func_00208540(void *, M2C_UNK);             /* extern */

void func_0017DDE8(void *arg0) {
    Goal_Deactivate();
    func_0017E278(arg0, -1);
    ResetSensorStates(M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0xF64));
    func_00208540(M2C_FIELD(arg0, void **, 0x10), 0);
    RemoveGuardSgs(M2C_FIELD(arg0, void **, 0x10), 0x2B);
}

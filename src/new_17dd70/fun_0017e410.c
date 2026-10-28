#include "m2c_macros.h"

M2C_UNK Goal_Deactivate();                          /* extern */
M2C_UNK RemoveGuardSgs(s32, M2C_UNK);               /* extern */
M2C_UNK func_0017E6B0(void *, M2C_UNK);             /* extern */
M2C_UNK func_001EF038(void *);                      /* extern */

void func_0017E410(void *arg0) {
    Goal_Deactivate();
    func_0017E6B0(arg0, -1);
    func_001EF038(arg0);
    RemoveGuardSgs(M2C_FIELD(arg0, s32 *, 0x10), 0x2C);
}

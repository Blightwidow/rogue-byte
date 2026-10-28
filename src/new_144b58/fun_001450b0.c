#include "m2c_macros.h"

M2C_UNK Goal_Deactivate();                          /* extern */
M2C_UNK func_00145B18(s32, M2C_UNK);                /* extern */

void func_001450B0(s32 arg0) {
    Goal_Deactivate();
    func_00145B18(arg0, -1);
}

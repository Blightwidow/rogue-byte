#include "m2c_macros.h"

M2C_UNK Carry_Attach(s32, s32);                     /* extern */
M2C_UNK Carry_Detach(s32);                          /* extern */
M2C_UNK SetJtAttach5(M2C_UNK);                      /* extern */

void func_001421A0(s32 arg0, s32 arg1) {
    SetJtAttach5(0);
    if (arg1 != 0) {
        Carry_Attach(arg0 + 0x900, arg1);
        return;
    }
    Carry_Detach(arg0 + 0x900);
}

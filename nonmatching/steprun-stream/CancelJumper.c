#include "m2c_macros.h"

M2C_UNK ApplyAsegToHandle(M2C_UNK, M2C_UNK, M2C_UNK, s32, M2C_UNK, M2C_UNK); /* extern */
s32 FJumperDone();                                  /* extern */
M2C_UNK SetJumperState(s32, M2C_UNK);               /* extern */

void CancelJumper(s32 arg0) {
    if (FJumperDone() == 0) {
        SetJumperState(arg0, 4);
        ApplyAsegToHandle(0, 0, 0, arg0 + 0x38, 0, 0x3F800000);
    }
}

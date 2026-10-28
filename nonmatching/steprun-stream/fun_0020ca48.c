#include "m2c_macros.h"

M2C_UNK ApplyAsegToHandle(M2C_UNK, M2C_UNK, M2C_UNK, s32, M2C_UNK, M2C_UNK); /* extern */
s32 func_0020CA98();                                /* extern */

void func_0020CA48(s32 arg0) {
    if (func_0020CA98() == 0) {
        ApplyAsegToHandle(0, 0, 0, arg0 + 0x24, 0, 0x3F800000);
    }
}

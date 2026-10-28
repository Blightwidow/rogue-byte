#include "m2c_macros.h"

M2C_UNK InitXfm();                                  /* extern */

void func_00203568(void *arg0) {
    InitXfm();
    M2C_FIELD(arg0, s32 *, 0xF4) = -1;
    M2C_FIELD(arg0, s32 *, 0x110) = -1;
    M2C_FIELD(arg0, s32 *, 0xFC) = -1;
    M2C_FIELD(arg0, s32 *, 0xF8) = -2;
}

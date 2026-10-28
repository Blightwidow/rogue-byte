#include "m2c_macros.h"

M2C_UNK SetCmFov(M2C_UNK *, f32);                   /* extern */
extern M2C_UNK B_002DDF40;

void func_0014FE28(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
    SetCmFov(&B_002DDF40, M2C_FIELD(arg0, f32 *, 0x2C));
}

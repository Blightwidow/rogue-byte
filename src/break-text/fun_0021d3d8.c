#include "m2c_macros.h"

M2C_UNK InitXfm();                                  /* extern */

void func_0021D3D8(void *arg0) {
    InitXfm();
    M2C_FIELD(arg0, f32 *, 0xE8) = 2000.0f;
    M2C_FIELD(arg0, f32 *, 0xEC) = -800.0f;
    M2C_FIELD(arg0, f32 *, 0xF0) = 800.0f;
    M2C_FIELD(arg0, s32 *, 0xF4) = 1;
}

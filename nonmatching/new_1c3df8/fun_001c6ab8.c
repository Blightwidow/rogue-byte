#include "m2c_macros.h"

M2C_UNK InitDprize();                               /* extern */

void func_001C6AB8(void *arg0) {
    InitDprize();
    M2C_FIELD(arg0, f32 *, 0x1DC) = 35.0f;
    M2C_FIELD(arg0, f32 *, 0x1A0) = 0.75f;
    M2C_FIELD(arg0, f32 *, 0x1D0) = 500.0f;
    M2C_FIELD(arg0, f32 *, 0x1D4) = 250.0f;
    M2C_FIELD(arg0, f32 *, 0x1E0) = 0.6f;
    M2C_FIELD(arg0, f32 *, 0x1D8) = 35.0f;
    M2C_FIELD(arg0, f32 *, 0x1E4) = 0.6f;
}

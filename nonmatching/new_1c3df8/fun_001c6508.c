#include "m2c_macros.h"

M2C_UNK InitDprize();                               /* extern */

void func_001C6508(void *arg0) {
    InitDprize();
    M2C_FIELD(arg0, f32 *, 0x234) = 5.0f;
    M2C_FIELD(arg0, f32 *, 0x1D8) = 45.0f;
    M2C_FIELD(arg0, f32 *, 0x1DC) = 65.0f;
    M2C_FIELD(arg0, f32 *, 0x1D0) = 250.0f;
    M2C_FIELD(arg0, f32 *, 0x1D4) = 150.0f;
    M2C_FIELD(arg0, f32 *, 0x1E0) = 0.5f;
    M2C_FIELD(arg0, f32 *, 0x1A0) = 0.25f;
    M2C_FIELD(arg0, f32 *, 0x1E4) = 0.25f;
    M2C_FIELD(arg0, f32 *, 0x230) = 5.0f;
}

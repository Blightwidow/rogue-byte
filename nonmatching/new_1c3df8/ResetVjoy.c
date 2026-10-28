#include "m2c_macros.h"

M2C_UNK ClearVjoyPresses(M2C_UNK);                  /* extern */

void ResetVjoy(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, f32 *, 0x20) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x1C) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x18) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x14) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x10) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x2C) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x28) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x24) = 0.0f;
    ClearVjoyPresses(0xFFFF);
}

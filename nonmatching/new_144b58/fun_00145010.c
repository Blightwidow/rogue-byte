#include "m2c_macros.h"

M2C_UNK func_001EEF68();                            /* extern */

void func_00145010(void *arg0) {
    func_001EEF68();
    M2C_FIELD(arg0, s32 *, 0x60) = -1;
    M2C_FIELD(arg0, f32 *, 0x78) = 1.2f;
    M2C_FIELD(arg0, f32 *, 0x68) = 0.25f;
    M2C_FIELD(arg0, f32 *, 0x6C) = 250.0f;
    M2C_FIELD(arg0, f32 *, 0x70) = 350.0f;
    M2C_FIELD(arg0, f32 *, 0x74) = 1.0f;
}

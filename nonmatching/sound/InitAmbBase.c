#include "m2c_macros.h"

extern M2C_UNK D_002D9D00;

void *InitAmbBase(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = &D_002D9D00;
    M2C_FIELD(arg0, f32 *, 0x44) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x30) = 300.0f;
    M2C_FIELD(arg0, f32 *, 0x34) = 3000.0f;
    M2C_FIELD(arg0, f32 *, 0x10) = 1.0f;
    return arg0;
}

#include "m2c_macros.h"

M2C_UNK InitLo();                                   /* extern */
M2C_UNK InitSl(s32, M2C_UNK);                       /* extern */

void InitJob(void *arg0) {
    InitLo();
    M2C_FIELD(arg0, f32 *, 0x9C) = 480.0f;
    M2C_FIELD(arg0, f32 *, 0xA0) = 720.0f;
    M2C_FIELD(arg0, s32 *, 0xB4) = -1;
    M2C_FIELD(arg0, s32 *, 0x6C) = -1;
    M2C_FIELD(arg0, s32 *, 0x70) = -1;
    M2C_FIELD(arg0, s32 *, 0xAC) = -1;
    M2C_FIELD(arg0, s32 *, 0xB0) = -1;
    InitSl(arg0 + 0x80, 0x84);
}

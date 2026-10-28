#include "m2c_macros.h"

M2C_UNK InitCplcy();                                /* extern */
extern M2C_UNK D_002CD498;

void *func_00150728(void *arg0) {
    InitCplcy();
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = &D_002CD498;
    M2C_FIELD(arg0, f32 *, 0xB4) = 7.0f;
    M2C_FIELD(arg0, f32 *, 0x18) = -1.0f;
    M2C_FIELD(arg0, s32 *, 0xC0) = 0;
    M2C_FIELD(arg0, s32 *, 0xC4) = 0;
    return arg0;
}

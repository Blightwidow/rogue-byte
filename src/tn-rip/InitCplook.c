#include "m2c_macros.h"

M2C_UNK InitCplcy();                                /* extern */
extern M2C_UNK D_002CD4E0;

void *InitCplook(void *arg0) {
    InitCplcy();
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = &D_002CD4E0;
    M2C_FIELD(arg0, f32 *, 0x28) = 7.0f;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
    return arg0;
}

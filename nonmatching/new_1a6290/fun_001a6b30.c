#include "m2c_macros.h"

M2C_UNK memset(void *, M2C_UNK, M2C_UNK);           /* extern */
extern M2C_UNK D_002C44F0;

M2C_UNK *func_001A6B30(s32 arg0, void *arg1) {
    if (arg1 != NULL) {
        memset(arg1, 0, 0x40);
        M2C_FIELD(arg1, f32 *, 0x3C) = 1.0f;
        M2C_FIELD(arg1, f32 *, 0x28) = 1.0f;
        M2C_FIELD(arg1, f32 *, 0x14) = 1.0f;
        M2C_FIELD(arg1, f32 *, 0) = 1.0f;
    }
    return &D_002C44F0;
}

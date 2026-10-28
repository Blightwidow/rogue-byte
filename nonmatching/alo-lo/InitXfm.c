#include "m2c_macros.h"

M2C_UNK InitLo();                                   /* extern */
M2C_UNK InvalidateXfmMatWorld(void *);              /* extern */
M2C_UNK memset(void *, M2C_UNK, M2C_UNK);           /* extern */

void InitXfm(void *arg0) {
    void *temp_s0;
    void *temp_v0;

    InitLo();
    temp_v0 = M2C_FIELD(arg0, void **, 0x10);
    temp_s0 = arg0 + 0x60;
    if (temp_v0 != NULL) {
        M2C_FIELD(arg0, s32 *, 0x50) = (s32) M2C_FIELD(temp_v0, s32 *, 0x60);
    }
    memset(temp_s0, 0, 0x40);
    M2C_FIELD(temp_s0, f32 *, 0x14) = 1.0f;
    M2C_FIELD(temp_s0, f32 *, 0x3C) = 1.0f;
    M2C_FIELD(temp_s0, f32 *, 0x28) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x60) = 1.0f;
    InvalidateXfmMatWorld(arg0);
}

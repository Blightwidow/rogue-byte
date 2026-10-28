#include "m2c_macros.h"

M2C_UNK PaloAbsorbWkr(void *, s32, s32, s32, s32);  /* extern */
M2C_UNK memset(void *, M2C_UNK, M2C_UNK);           /* extern */
extern f32 g_2dded0;

void SetFallCheckState(void *arg0, s32 arg1) {
    char sp[0x400];
    s32 temp_v1;

    if (M2C_FIELD(arg0, s32 *, 4) != arg1) {
        M2C_FIELD(arg0, s32 *, 4) = arg1;
        M2C_FIELD(arg0, f32 *, 8) = (f32) g_2dded0;
        if (arg1 == 2) {
            memset(sp, 0, 0x60);
            temp_v1 = M2C_FIELD(arg0, s32 *, 0);
            PaloAbsorbWkr(sp, temp_v1, temp_v1, 0x4000, 0);
        }
    }
}

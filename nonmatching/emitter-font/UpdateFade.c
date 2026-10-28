#include "m2c_macros.h"

M2C_UNK UpdateLo();                                 /* extern */
extern f32 g_2dded0;

void UpdateFade(void *arg0) {
    void *temp_v0;

    UpdateLo();
    if ((M2C_FIELD(arg0, f32 *, 0x5C) + M2C_FIELD(arg0, f32 *, 0x60) + M2C_FIELD(arg0, f32 *, 0x64)) < (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x68))) {
        temp_v0 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *), 0x4C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x48));
    }
}

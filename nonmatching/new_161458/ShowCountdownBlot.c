#include "m2c_macros.h"

extern f32 g_2dded0;

void ShowCountdownBlot(void *arg0, f32 fparg0) {
    void *temp_a2;
    void *temp_v0;

    temp_a2 = M2C_FIELD(arg0, void **, 0x3BC4);
    if (temp_a2 != NULL) {
        M2C_FIELD(temp_a2, s32 *, 0x8C) = 0;
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK, void *), 0x18C)(temp_a2 + M2C_FIELD(temp_v0, s16 *, 0x188), -1, temp_a2);
        temp_v0 = M2C_FIELD(temp_a2, void **, 0xC);
    }
    M2C_FIELD(arg0, f32 *, 0x476C) = (f32) (g_2dded0 + fparg0);
}

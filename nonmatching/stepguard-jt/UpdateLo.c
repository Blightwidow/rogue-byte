#include "m2c_macros.h"

extern f32 g_2dded0;

void UpdateLo(void *arg0) {
    void *temp_v0;

    if (M2C_FIELD(arg0, f32 *, 0x30) <= g_2dded0) {
        temp_v0 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK), 0x1C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x18), 1, 1, 0);
    }
}

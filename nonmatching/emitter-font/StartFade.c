#include "m2c_macros.h"

extern f32 g_2dded0;

void StartFade(void *arg0) {
    void *temp_v1;

    if (!(((u64) M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1)) {
        temp_v1 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(arg0, f32 *, 0x68) = (f32) g_2dded0;
        M2C_FIELD(temp_v1, M2C_UNK (**)(void *, void *), 0x44)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x40), arg0);
    }
}

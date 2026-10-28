#include "m2c_macros.h"

void ReleaseGadgetObj(void *arg0) {
    void *temp_v0;

    temp_v0 = M2C_FIELD(arg0, void **, 0xC);
    if (M2C_FIELD(arg0, s32 *, 0x15C) == 0xB) {
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK, void *), 0x264)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x260), 5, arg0);
        return;
    }
    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK, void *), 0x264)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x260), 3, arg0);
}

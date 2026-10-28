#include "m2c_macros.h"

s32 FReleaseGadgetObj(void *arg0) {
    s32 temp_v1;
    void *temp_v0;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x150);
    if ((temp_v1 < 3) && (temp_v1 > 0)) {
        temp_v0 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK, void *), 0x264)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x260), 3, arg0);
    }
    return 1;
}

#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(M2C_UNK);                   /* extern */

void SetAloAlpha(void *arg0, f32 fparg0) {
    void *temp_v0;
    void *temp_v0_2;

    if (fparg0 <= 0.0f) {
        if (FIsBasicDerivedFrom(0x69) == 0) {
            temp_v0 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v0, M2C_UNK (**)(void *), 0x4C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x48));
        }
    } else {
        temp_v0_2 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *), 0x44)(arg0 + M2C_FIELD(temp_v0_2, s16 *, 0x40));
    }
    M2C_FIELD(arg0, f32 *, 0x12C) = fparg0;
}

#include "m2c_macros.h"

M2C_UNK SetAmbGrf(void *, M2C_UNK, M2C_UNK);        /* extern */

void SetAmbSilent(void *arg0, s32 arg1) {
    void *temp_v0;
    void *temp_v1;

    if (arg1 == 0) {
        temp_v0 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *), 0x3C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x38));
        return;
    }
    temp_v1 = M2C_FIELD(arg0, void **, 0xC);
    SetAmbGrf(arg0, ((M2C_FIELD(temp_v1, s32 (**)(void *), 0x44)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x40)) ^ 2) == 0) ? 0x1FF : 0x3FF, 8);
}

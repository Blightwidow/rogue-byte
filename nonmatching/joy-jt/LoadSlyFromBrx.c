#include "m2c_macros.h"

M2C_UNK LoadStepFromBrx();                          /* extern */
M2C_UNK SetSoProperties(void *, M2C_UNK, M2C_UNK *); /* extern */
extern M2C_UNK D_002BE990;

void LoadSlyFromBrx(void *arg0) {
    void *temp_v0;

    LoadStepFromBrx();
    temp_v0 = arg0 + 0x240;
    M2C_FIELD(arg0, s32 *, 0x240) = 0;
    M2C_FIELD(temp_v0, f32 *, 8) = -75.0f;
    M2C_FIELD(temp_v0, s32 *, 4) = 0;
    SetSoProperties(arg0, 0xAD, &D_002BE990);
}

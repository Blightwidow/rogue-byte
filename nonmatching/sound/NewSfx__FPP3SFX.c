#include "m2c_macros.h"

void *PvAllocSwClearImpl__Fi(void *, s32, s32);     /* extern */

void NewSfx__FPP3SFX(void) {
    char sp[0x400];
    void *temp_v0;

    temp_v0 = PvAllocSwClearImpl__Fi(sp, 0x14, 0x10);
    M2C_FIELD(temp_v0, s32 *, 0) = -1;
    M2C_FIELD(temp_v0, f32 *, 4) = 300.0f;
    M2C_FIELD(temp_v0, f32 *, 8) = 3000.0f;
    M2C_FIELD(temp_v0, f32 *, 0xC) = 1.0f;
}

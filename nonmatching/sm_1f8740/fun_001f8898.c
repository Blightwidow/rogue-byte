#include "m2c_macros.h"

M2C_UNK WakeXf(s32, void *, f32);                   /* extern */

void func_001F8898(void *arg0, f32 fparg0) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), s16 *, 0xAC) = 0x447A0000;
    WakeXf(M2C_FIELD(arg0, s32 *, 0x20), M2C_FIELD(arg0, void **, 0x24), fparg0 * 1000.0f);
}

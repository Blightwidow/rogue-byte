#include "m2c_macros.h"

M2C_UNK ApplyAseg(s32, void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_001B9DB8(void *arg0) {
    void *temp_a2;
    void *temp_v0;

    temp_a2 = M2C_FIELD(arg0, void **, 0x1AD8);
    if (!(((u64) M2C_FIELD(temp_a2, u64 *, 0x28) >> 0x3C) & 1)) {
        temp_v0 = M2C_FIELD(temp_a2, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *), 0xEC)(temp_a2 + M2C_FIELD(temp_v0, s16 *, 0xE8), temp_a2);
        ApplyAseg(M2C_FIELD(arg0, s32 *, 0x1ADC), M2C_FIELD(arg0, void **, 0x1AD8), 0, 0, 0, 0x3F800000);
    }
}

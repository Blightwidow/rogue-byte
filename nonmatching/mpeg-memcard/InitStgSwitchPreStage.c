#include "m2c_macros.h"

s32 PvAllocStackImpl__Fi(void *, M2C_UNK, s32, s32); /* extern */

void InitStgSwitchPreStage(void *arg0) {
    char sp[0x400];
    void *temp_s0;
    void *temp_v0;

    M2C_FIELD(arg0, s32 *, 0x15C) = -1;
    temp_v0 = M2C_FIELD(arg0, void **, 0x164);
    M2C_FIELD(temp_v0, s32 *, -0x10) = -1;
    temp_s0 = temp_v0 - 0x10;
    M2C_FIELD(temp_s0, s32 *, 4) = 1;
    if (M2C_FIELD(temp_s0, s32 *, 0xC) == 0) {
        M2C_FIELD(temp_s0, s32 *, 0xC) = PvAllocStackImpl__Fi(sp, 1, 0x200, 0x10);
    }
}

#include "m2c_macros.h"

s32 PvAllocStackImpl__Fi(void *, s32, s32, s32);    /* extern */

void AddStgSwitchStage(void *arg0, s32 arg1) {
    char sp[0x400];
    s32 temp_a2;
    void *temp_s0;

    temp_a2 = M2C_FIELD(arg0, s32 *, 0x160);
    if (temp_a2 < 0x20) {
        M2C_FIELD(arg0, s32 *, 0x15C) = temp_a2;
        temp_s0 = M2C_FIELD(arg0, s32 *, 0x164) + (temp_a2 * 0x10);
        M2C_FIELD(arg0, s32 *, 0x160) = (s32) (temp_a2 + 1);
        M2C_FIELD(temp_s0, s32 *, 0) = arg1;
        M2C_FIELD(temp_s0, s32 *, 4) = 1;
        M2C_FIELD(temp_s0, s32 *, 0xC) = PvAllocStackImpl__Fi(sp, temp_a2, 0x200, 0x10);
    }
}

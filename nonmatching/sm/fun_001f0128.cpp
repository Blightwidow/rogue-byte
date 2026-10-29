#include "m2c_macros.h"
extern "C" {

void *PvAllocSwImpl__Fi(void *, s32, s32);          /* extern */

void func_001F0128(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    char sp[0x10];
    void *temp_v0;

    temp_v0 = PvAllocSwImpl__Fi(sp, 0xC, 0x10);
    M2C_FIELD(arg0, void **, 0x74) = temp_v0;
    M2C_FIELD(temp_v0, s32 *, 8) = arg3;
    M2C_FIELD(temp_v0, s32 *, 0) = arg1;
    M2C_FIELD(temp_v0, s32 *, 4) = arg2;
}
}

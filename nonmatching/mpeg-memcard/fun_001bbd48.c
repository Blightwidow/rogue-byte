#include "m2c_macros.h"

void *PactAddStgAction(M2C_UNK);                    /* extern */
s32 *PvAllocStackImpl__Fi(void *, s32, s32);        /* extern */

void func_001BBD48(s32 arg1, s32 arg2) {
    char sp[0x400];
    s32 *temp_v0;
    void *temp_s0;

    temp_s0 = PactAddStgAction(0xC);
    temp_v0 = PvAllocStackImpl__Fi(sp, 8, 0x10);
    M2C_FIELD(temp_s0, s32 **, 4) = temp_v0;
    *temp_v0 = arg1;
    M2C_FIELD(M2C_FIELD(temp_s0, s32 **, 4), s32 *, 4) = arg2;
}

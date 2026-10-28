#include "m2c_macros.h"

void *PemitbEnsureEmitter(s32, M2C_UNK, void *);    /* extern */
s32 PvAllocSwClearImpl__Fi(void *, s32, s32);       /* extern */

void func_001C4848(void *arg0, s32 arg1) {
    char sp[0x400];
    u32 temp_v1;
    void *temp_v0;

    temp_v1 = M2C_FIELD(arg0, u32 *, 0x4778);
    if (temp_v1 < 4U) {
        M2C_FIELD((arg0 + (temp_v1 * 4)), s32 *, 0x477C) = arg1;
        M2C_FIELD(arg0, u32 *, 0x4778) = (u32) (temp_v1 + 1);
        temp_v0 = PemitbEnsureEmitter(arg1, 1, arg0);
        if (M2C_FIELD(temp_v0, s32 *, 8) == 0) {
            M2C_FIELD(temp_v0, s32 *, 8) = PvAllocSwClearImpl__Fi(sp, 0x14, 0x10);
        }
    }
}

#include "m2c_macros.h"

s32 PvAllocSwImpl__Fi(void *, s32, s32);            /* extern */

void InitSymtab(void *arg0, s32 arg1) {
    char sp[0x400];
    M2C_FIELD(arg0, s32 *, 0xD4) = arg1;
    M2C_FIELD(arg0, s32 *, 0xD8) = PvAllocSwImpl__Fi(sp, arg1 * 0x10, 0x10);
}

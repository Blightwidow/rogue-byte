#include "m2c_macros.h"

M2C_UNK PrependSlEntry(void *, void *);             /* extern */
M2C_UNK func_002185F8(s32, s32, u8, void *);        /* extern */

void func_00215960(void *arg0, void *arg1, u8 arg2) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 4);
    switch (temp_v1) {
    case 4:
        func_002185F8(M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 0x84) + (M2C_FIELD(arg0, s32 *, 0x10) * 0x30), M2C_FIELD(arg1, s32 *, 0x58), M2C_FIELD(arg1, u8 *, 0x61), arg0);
        return;
    case 1:
    case 3:
    case 6:
    case 7:
        M2C_FIELD(arg1, u8 *, 0x61) = arg2;
        PrependSlEntry(M2C_FIELD(arg0, void **, 8) + 0xFC, arg0);
        /* fallthrough */
    default:
        return;
    }
}

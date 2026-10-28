#include "m2c_macros.h"

M2C_UNK Blot_Construct();                           /* extern */
extern M2C_UNK D_002C9670;

void *func_00211C58(void *arg0) {
    Blot_Construct();
    M2C_FIELD(arg0, s32 *, 0x120) = -1;
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = &D_002C9670;
    M2C_FIELD(arg0, s32 *, 0x110) = -1;
    M2C_FIELD(arg0, s32 *, 0x114) = -1;
    M2C_FIELD(arg0, s32 *, 0x118) = -1;
    M2C_FIELD(arg0, s32 *, 0x11C) = -1;
    return arg0;
}

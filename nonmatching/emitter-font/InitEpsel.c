#include "m2c_macros.h"

M2C_UNK InitLo();                                   /* extern */
extern void *B_003E1C04;

void InitEpsel(void *arg0) {
    InitLo();
    M2C_FIELD(arg0, s32 *, 0x120) = -1;
    M2C_FIELD(arg0, s32 *, 0x110) = -1;
    M2C_FIELD(arg0, s32 *, 0x114) = -1;
    M2C_FIELD(arg0, s32 *, 0x11C) = -1;
    B_003E1C04 = arg0;
}

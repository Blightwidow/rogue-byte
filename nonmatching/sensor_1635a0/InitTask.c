#include "m2c_macros.h"

M2C_UNK InitLo();                                   /* extern */
extern M2C_UNK B_003DD490;

void InitTask(void *arg0) {
    InitLo();
    M2C_FIELD(arg0, s32 *, 0xF4) = 0;
    M2C_FIELD(arg0, s32 *, 0xC0) = -1;
    M2C_FIELD(arg0, s32 *, 0x54) = -1;
    M2C_FIELD(arg0, s32 *, 0xF0) = -1;
    M2C_FIELD(arg0, s32 *, 0x5C) = -1;
    M2C_FIELD(arg0, s32 *, 0xB8) = -1;
    M2C_FIELD(arg0, s32 *, 0xBC) = -1;
    M2C_FIELD(&B_003DD490, s32 *, 0x3AFC) = (s32) (M2C_FIELD(&B_003DD490, s32 *, 0x3AFC) + 1);
}

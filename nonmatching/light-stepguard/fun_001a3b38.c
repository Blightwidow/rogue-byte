#include "m2c_macros.h"

extern M2C_UNK B_003DD490;
extern s32 B_003E19E4;

void func_001A3B38(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x160) == 0) {
        M2C_FIELD(&B_003DD490, s32 *, 0x3D5C) = (s32) (M2C_FIELD(&B_003DD490, s32 *, 0x3D5C) + 1);
    }
    if ((M2C_FIELD(arg0, s32 *, 0x15C) == 0) && (M2C_FIELD(arg0, s32 *, 0xE0) != 0)) {
        B_003E19E4 = 1;
    }
}

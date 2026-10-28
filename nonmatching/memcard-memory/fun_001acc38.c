#include "m2c_macros.h"

extern M2C_UNK B_002E65E0;
extern f32 g_2ddf0c;

void func_001ACC38(void *arg0, s32 arg1) {
    if (arg1 != M2C_FIELD(arg0, s32 *, 0x44)) {
        if ((arg1 < 4) && (arg1 >= 2)) {
            M2C_FIELD(&B_002E65E0, s32 *, 0xFD50) = 0;
        }
        M2C_FIELD(arg0, s32 *, 0x44) = arg1;
        M2C_FIELD(arg0, f32 *, 0x48) = (f32) g_2ddf0c;
    }
}

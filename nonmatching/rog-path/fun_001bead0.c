#include "m2c_macros.h"

void func_001BEAD0(void *arg0, void *arg1) {
    s32 temp_v1;
    void *temp_v0;

    if (arg1 != NULL) {
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x104);
        M2C_FIELD((arg0 + (temp_v1 * 4)), void **, 0x108) = arg1;
        M2C_FIELD(arg0, s32 *, 0x104) = (s32) (temp_v1 + 1);
        M2C_FIELD(arg1, s32 *, 0x15C) = 1;
        M2C_FIELD(arg1, s32 *, 0x160) = 1;
        temp_v0 = M2C_FIELD(arg1, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *), 0x4C)(arg1 + M2C_FIELD(temp_v0, s16 *, 0x48), arg0);
    }
}

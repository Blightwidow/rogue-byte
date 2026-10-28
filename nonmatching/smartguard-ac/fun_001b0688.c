#include "m2c_macros.h"

M2C_UNK PauseMenu_Push(M2C_UNK *, s32, s32, M2C_UNK); /* extern */
extern M2C_UNK B_003D9ED0;

void func_001B0688(void *arg0) {
    PauseMenu_Push(&B_003D9ED0, M2C_FIELD(arg0, s32 *, 8), M2C_FIELD(arg0, s32 *, 0xC), 0);
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s32 *, 0x1C) = (s32) (M2C_FIELD(arg0, s32 *, 0x1C) | 2);
    }
}

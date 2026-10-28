#include "m2c_macros.h"

M2C_UNK Blot_Show();                                /* extern */
M2C_UNK SetHandsOff(M2C_UNK *, M2C_UNK);            /* extern */
M2C_UNK func_00213B00(void *, M2C_UNK);             /* extern */
extern M2C_UNK B_003DD490;

void PromptBlot_Show(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x7C) == -1) {
        Blot_Show();
        SetHandsOff(&B_003DD490, 0);
        M2C_FIELD(arg0, s32 *, 0x110) = 1;
        func_00213B00(arg0, 0x33A);
    }
}

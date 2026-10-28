#include "m2c_macros.h"

s32 PloNew(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);     /* extern */
extern s32 B_003DD48C;

void func_00205E70(void) {
    if (B_003DD48C == 0) {
        B_003DD48C = PloNew(0x7D, 0, 0x656, -1);
    }
}

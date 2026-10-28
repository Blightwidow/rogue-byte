#include "m2c_macros.h"

M2C_UNK RequestTransition(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SetSndbankMasterVolume(M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK B_003DD040;
extern M2C_UNK B_003DD490;

void func_0014C140(s32 arg0) {
    SetSndbankMasterVolume(&B_003DD040, 0);
    RequestTransition(&B_003DD490, 0, 0x189, -1);
}

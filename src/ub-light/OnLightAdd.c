#include "m2c_macros.h"

M2C_UNK AddLightToSw(M2C_UNK *, s32);               /* extern */
M2C_UNK func_001A6178();                            /* extern */
extern M2C_UNK B_003DD490;

void OnLightAdd(s32 arg0) {
    func_001A6178();
    AddLightToSw(&B_003DD490, arg0);
}

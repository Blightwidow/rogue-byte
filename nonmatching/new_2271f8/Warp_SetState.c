#include "m2c_macros.h"

M2C_UNK SetHandsOff(M2C_UNK *, M2C_UNK);            /* extern */
M2C_UNK func_001A6CA8(M2C_UNK);                     /* extern */
extern M2C_UNK B_003DD490;
extern f32 g_2dded0;

void Warp_SetState(void *arg0, s32 arg1) {
    if (arg1 != M2C_FIELD(arg0, s32 *, 0x13C)) {
        if (arg1 == 4) {
            func_001A6CA8(1);
            SetHandsOff(&B_003DD490, 3);
            M2C_FIELD(&B_003DD490, void **, 0x3C84) = arg0;
        }
        M2C_FIELD(arg0, s32 *, 0x13C) = arg1;
        M2C_FIELD(arg0, f32 *, 0x140) = (f32) g_2dded0;
    }
}

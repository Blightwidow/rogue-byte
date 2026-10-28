#include "m2c_macros.h"

extern f32 g_2dded0;

void SetVehicleAiState(void *arg0, s32 arg1) {
    if (arg1 != M2C_FIELD(arg0, s32 *, 0x188)) {
        M2C_FIELD(arg0, s32 *, 0x188) = arg1;
        M2C_FIELD(arg0, f32 *, 0x18C) = (f32) g_2dded0;
    }
}

#include "m2c_macros.h"

void UnpackColorU8ToVec_11dcd8(void *arg0, void *arg1) {
    M2C_FIELD(arg1, f32 *, 0) = (f32) ((f32) M2C_FIELD(arg0, u8 *, 0) * 0.003921569f);
    M2C_FIELD(arg1, f32 *, 4) = (f32) ((f32) M2C_FIELD(arg0, u8 *, 1) * 0.003921569f);
    M2C_FIELD(arg1, f32 *, 8) = (f32) ((f32) M2C_FIELD(arg0, u8 *, 2) * 0.003921569f);
}

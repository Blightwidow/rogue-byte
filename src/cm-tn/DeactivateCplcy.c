#include "m2c_macros.h"

M2C_UNK SetCmNearClip(M2C_UNK *, f32);              /* extern */
extern M2C_UNK B_002DDF40;

void DeactivateCplcy(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    SetCmNearClip(&B_002DDF40, M2C_FIELD(arg0, f32 *, 8));
    M2C_FIELD(&B_002DDF40, f32 *, 0x24) = (f32) M2C_FIELD(arg0, f32 *, 4);
}

#include "m2c_macros.h"

M2C_UNK ActivateCplcy();                            /* extern */
M2C_UNK SetCmNearClip(M2C_UNK *, M2C_UNK);          /* extern */
extern M2C_UNK B_002DDF40;

void ActivateCpattach(s32 arg0, void *arg1) {
    ActivateCplcy();
    SetCmNearClip(&B_002DDF40, 0x42440000);
    M2C_FIELD(&B_002DDF40, f32 *, 0x24) = (f32) M2C_FIELD(arg1, f32 *, 0x1BC);
}

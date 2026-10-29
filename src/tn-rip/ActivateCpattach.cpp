#include "m2c_macros.h"
extern "C" {

void ActivateCplcy();                            /* extern */
void SetCmNearClip(M2C_UNK *, float);          /* extern */
extern M2C_UNK B_002DDF40;

void ActivateCpattach(s32 arg0, void *arg1) {
    ActivateCplcy();
    SetCmNearClip(&B_002DDF40, 49.0f);
    M2C_FIELD(&B_002DDF40, f32 *, 0x24) = (f32) M2C_FIELD(arg1, f32 *, 0x1BC);
}
}

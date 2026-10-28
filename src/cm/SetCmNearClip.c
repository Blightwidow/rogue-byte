#include "m2c_macros.h"

M2C_UNK RecalcCmFrustrum__FP2CM();                  /* extern */

void SetCmNearClip(void *arg0, f32 fparg0) {
    M2C_FIELD(arg0, f32 *, 0x4C) = fparg0;
    RecalcCmFrustrum__FP2CM();
}

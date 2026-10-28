#include "m2c_macros.h"

M2C_UNK RecalcCmFrustrum__FP2CM();                  /* extern */

void SetCmFarFog(void *arg0, f32 fparg0) {
    M2C_FIELD(arg0, f32 *, 0x244) = fparg0;
    RecalcCmFrustrum__FP2CM();
}

#include "m2c_macros.h"

M2C_UNK SetAloAlpha();                  /* extern */
M2C_UNK SetAloFadeRate();                   /* extern */

void FadeAloOut(s32 arg0, f32 fparg0) {
    if (fparg0 <= 0.0f) {
        SetAloFadeRate(0);
        SetAloAlpha(arg0, 0);
        return;
    }
    SetAloFadeRate(arg0, -1.0f / fparg0);
}

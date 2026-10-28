#include "m2c_macros.h"

M2C_UNK ClearVjoyPresses(s32, s32);                 /* extern */
s32 GrfbtnVjoyPressedWithin();                      /* extern */

s32 FButtonPressedWithin(s32 arg0) {
    s32 temp_v0;

    temp_v0 = GrfbtnVjoyPressedWithin();
    ClearVjoyPresses(arg0, temp_v0);
    return temp_v0;
}

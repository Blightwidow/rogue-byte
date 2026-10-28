#include "m2c_macros.h"

M2C_UNK ConsumeJoyButton(s32, s32);                 /* extern */
s32 FJoyButtonPeek();                               /* extern */

s32 FJoyButtonPressed(s32 arg0, s32 arg1) {
    s32 temp_s2;

    temp_s2 = FJoyButtonPeek();
    ConsumeJoyButton(arg0, arg1);
    return temp_s2;
}

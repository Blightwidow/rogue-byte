#include "m2c_macros.h"

M2C_UNK ChangeSuck__FfP10DIFFICULTY(s32, f32);      /* extern */
f32 GetSuck();                                      /* extern */

void AddSuck(s32 arg0, f32 fparg0) {
    ChangeSuck__FfP10DIFFICULTY(arg0, GetSuck() + fparg0);
}

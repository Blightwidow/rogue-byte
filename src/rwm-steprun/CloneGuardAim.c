#include "m2c_macros.h"

M2C_UNK CloneAnimref(s32);                          /* extern */
M2C_UNK CLo_Clone();                                  /* extern */

void CloneGuardAim(s32 arg0) {
    CLo_Clone();
    CloneAnimref(arg0 + 0xB0);
}

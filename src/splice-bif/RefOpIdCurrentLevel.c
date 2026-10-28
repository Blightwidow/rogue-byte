#include "m2c_macros.h"

s32 IdCurrentLevel();                               /* extern */

void *RefOpIdCurrentLevel(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = IdCurrentLevel();
    M2C_FIELD(arg0, s32 *, 0) = 0x15;
    return arg0;
}

#include "m2c_macros.h"
extern "C" {

M2C_UNK WarpJtToSafePoint(s32, void *, s128);       /* extern */
M2C_UNK memset(void *, M2C_UNK, M2C_UNK);           /* extern */

void WarpJtToPoint(s32 arg0) {
    char sp[0x30];
    memset(sp, 0, 0x20);
    WarpJtToSafePoint(arg0, sp, M2C_ERROR(/* unknown instruction: por $s0, $zero, $a1 */));
}
}

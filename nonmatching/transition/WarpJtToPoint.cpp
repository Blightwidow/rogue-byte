#include "m2c_macros.h"
extern "C" {

M2C_UNK WarpJtToSafePoint(s32, void *);       /* extern */
M2C_UNK memset(void *, f32, M2C_UNK);           /* extern */

void WarpJtToPoint(s32 arg0) {
    char sp[0x30];
    memset(sp, 0, 0x20);
    WarpJtToSafePoint(arg0, sp);
}
}

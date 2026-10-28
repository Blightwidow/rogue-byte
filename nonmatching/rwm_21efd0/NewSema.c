#include "m2c_macros.h"

M2C_UNK CreateSema(void *, s32, s32);               /* extern */
M2C_UNK memset(void *, M2C_UNK, M2C_UNK);           /* extern */

void NewSema(s32 arg0, s32 arg1) {
    char sp[0x400];
    memset(sp, 0, 0x18);
    CreateSema(sp, arg1, arg0);
}

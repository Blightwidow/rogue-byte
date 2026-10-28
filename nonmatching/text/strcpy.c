#include "m2c_macros.h"

M2C_UNK CopyAb__FPvT0Ui(s32, s32, s32);             /* extern */
s32 strlen(s32);                                    /* extern */

s32 strcpy(s32 arg0, s32 arg1) {
    CopyAb__FPvT0Ui(arg0, arg1, strlen(arg1) + 1);
    return arg0;
}

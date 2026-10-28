#include "m2c_macros.h"

M2C_UNK Flush__5OSTRM();                            /* extern */
M2C_UNK __builtin_delete(s32);                      /* extern */

void func_0020D618(s32 arg0, s32 arg1) {
    Flush__5OSTRM();
    if (arg1 & 1) {
        __builtin_delete(arg0);
    }
}

#include "m2c_macros.h"

M2C_UNK Close__18CBinaryAsyncStream();              /* extern */
M2C_UNK __builtin_delete(s32);                      /* extern */

void func_001325B8(s32 arg0, s32 arg1) {
    Close__18CBinaryAsyncStream();
    if (arg1 & 1) {
        __builtin_delete(arg0);
    }
}

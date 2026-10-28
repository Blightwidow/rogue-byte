#include "m2c_macros.h"

M2C_UNK CM_Construct(s32);                          /* extern */
s32 __builtin_new(M2C_UNK);                         /* extern */

void func_00112DA8(void) {
    CM_Construct(__builtin_new(0x630));
}

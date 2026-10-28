#include "m2c_macros.h"

M2C_UNK Blot_Construct(s32);                        /* extern */
s32 __builtin_new(M2C_UNK);                         /* extern */

void func_00112BE8(void) {
    Blot_Construct(__builtin_new(0x110));
}

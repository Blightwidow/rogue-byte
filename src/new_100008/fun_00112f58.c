#include "m2c_macros.h"

M2C_UNK InitJumper(s32);                            /* extern */
s32 __builtin_new(M2C_UNK);                         /* extern */

void func_00112F58(void) {
    InitJumper(__builtin_new(0x70));
}

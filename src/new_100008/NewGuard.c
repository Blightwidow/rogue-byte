#include "m2c_macros.h"

M2C_UNK ConstructGuard(s32);                        /* extern */
s32 __builtin_new(M2C_UNK);                         /* extern */

void NewGuard(void) {
    ConstructGuard(__builtin_new(0x1010));
}

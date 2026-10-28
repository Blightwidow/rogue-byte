#include "m2c_macros.h"

M2C_UNK ConstructSly(s32);                          /* extern */
s32 __builtin_new(M2C_UNK);                         /* extern */

void NewSly(void) {
    ConstructSly(__builtin_new(0x2060));
}

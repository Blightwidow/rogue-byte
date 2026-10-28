#include "m2c_macros.h"

M2C_UNK ConstructMurray(s32);                       /* extern */
s32 __builtin_new(M2C_UNK);                         /* extern */

void NewMurray(void) {
    ConstructMurray(__builtin_new(0x1B00));
}

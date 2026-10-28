#include "m2c_macros.h"

M2C_UNK Sw_Construct(s32);                          /* extern */
s32 __builtin_new(M2C_UNK);                         /* extern */

void NewSw(void) {
    Sw_Construct(__builtin_new(0x4790));
}

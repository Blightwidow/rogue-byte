#include "m2c_macros.h"

s32 rand();                                         /* extern */

s32 NRandRaw(void) {
    return rand() % 905010707;
}

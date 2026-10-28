#include "m2c_macros.h"

/* Warning: missing "jr $ra" in last block of func_002584A0 (initial). */

u32 func_002584A0(void) {
    return (u32) M2C_ERROR(/* Read from unset register $v0 */) >> 4;
}

#include "m2c_macros.h"

/* Warning: missing "jr $ra" in last block of func_0014B9B8 (initial). */

s32 func_0014B9B8(void) {
    return M2C_ERROR(/* Read from unset register $v0 */) + 0xB8;
}

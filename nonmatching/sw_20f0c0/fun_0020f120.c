#include "m2c_macros.h"

/* Warning: missing "jr $ra" in last block of func_0020F120 (initial). */

s32 func_0020F120(void) {
    return M2C_ERROR(/* Read from unset register $v0 */) > 0;
}

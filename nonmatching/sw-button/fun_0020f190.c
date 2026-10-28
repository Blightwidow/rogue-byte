#include "m2c_macros.h"

/* Warning: missing "jr $ra" in last block of func_0020F190 (initial). */

s32 func_0020F190(void) {
    return M2C_ERROR(/* Read from unset register $v0 */) > 0;
}

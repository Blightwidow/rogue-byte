#include "m2c_macros.h"

/* Warning: missing "jr $ra" in last block of func_0014BF10 (initial). */

void func_0014BF10(void *arg1) {
    M2C_FIELD(arg1, s32 *, 0x14) = (s32) M2C_ERROR(/* Read from unset register $v0 */);
}

#include "m2c_macros.h"

M2C_UNK SetStepRadTarget(s32);                      /* extern */

void func_00209818(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 4) == 0) {
        SetStepRadTarget(M2C_FIELD(arg0, s32 *, 0xC));
    }
}

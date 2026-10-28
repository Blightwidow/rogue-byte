#include "m2c_macros.h"

M2C_UNK AdjustStepXps();                            /* extern */
M2C_UNK func_00199298(void *);                      /* extern */

void func_00140D70(void *arg0) {
    AdjustStepXps();
    if (M2C_FIELD(arg0, s32 *, 0x2DC) != -1) {
        func_00199298(arg0 + 0x2C0);
    }
}

#include "m2c_macros.h"

M2C_UNK FreeAct(s32);                               /* extern */
M2C_UNK RemoveLookat(s32);                          /* extern */

void func_0012E460(s32 *arg0) {
    s32 temp_s0;

    temp_s0 = *arg0;
    if (temp_s0 != 0) {
        RemoveLookat(temp_s0);
        FreeAct(temp_s0);
        *arg0 = 0;
    }
}

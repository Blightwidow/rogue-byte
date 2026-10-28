#include "m2c_macros.h"

s32 PsidebagNew();                                  /* extern */
M2C_UNK SidebagPtr_Assign(void *, s32);             /* extern */
M2C_UNK func_00258178(s32);                         /* extern */

void func_00132B78(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 4) == 0) {
        SidebagPtr_Assign(arg0 + 4, PsidebagNew());
        func_00258178(M2C_FIELD(arg0, s32 *, 4));
    }
}

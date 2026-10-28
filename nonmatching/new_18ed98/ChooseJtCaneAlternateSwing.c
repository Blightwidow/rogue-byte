#include "m2c_macros.h"

s32 FCheckJtCaneSide();                             /* extern */

s32 ChooseJtCaneAlternateSwing(void *arg0) {
    s32 temp_v1;
    s32 var_a0;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x18D8);
    switch (temp_v1) {                              /* irregular */
    case 23:
        var_a0 = 0x16;
        break;
    case 22:
        var_a0 = 0x17;
        break;
    default:
        var_a0 = (FCheckJtCaneSide() != 0) ? 0x17 : 0x16;
        break;
    }
    return var_a0;
}

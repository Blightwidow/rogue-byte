#include "m2c_macros.h"

M2C_UNK func_001431D0();                            /* extern */

void SetJtFocus(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg2 != M2C_FIELD(arg0, s32 *, 0x10DC)) {
        func_001431D0();
    }
    M2C_FIELD(arg0, s32 *, 0x10EC) = arg3;
    M2C_FIELD(arg0, s32 *, 0x10DC) = arg2;
    M2C_FIELD(arg0, s32 *, 0x10E4) = arg1;
    M2C_FIELD(arg0, s32 *, 0x10E8) = (s32) M2C_ERROR(/* Read from unset register $t0 */);
}

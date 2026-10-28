#include "m2c_macros.h"

M2C_UNK func_001A3B38();                      /* extern */

void SetLightDynamic(void *arg0, s32 arg1) {
    if (arg1 != M2C_FIELD(arg0, s32 *, 0x160)) {
        func_001A3B38();
        M2C_FIELD(arg0, s32 *, 0x160) = arg1;
        if (arg1 != 0) {
            M2C_FIELD(arg0, s32 *, 0x15C) = 0;
        }
        func_001A3B38(arg0);
    }
}

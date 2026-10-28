#include "m2c_macros.h"

s32 IglyphFromFontCh(s32);                          /* extern */

s32 PglyphFromFontCh(void *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = IglyphFromFontCh(arg1 & 0xFF);
    if (temp_v0 != 0) {
        return M2C_FIELD(arg0, s32 *, 0x14) + (temp_v0 << 6);
    }
    return 0;
}

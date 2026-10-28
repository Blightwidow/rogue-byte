#include "m2c_macros.h"

s32 IglyphFromFontCh(s32);                          /* extern */

f32 DxFromFontCh(void *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = IglyphFromFontCh(arg1 & 0xFF);
    if (temp_v0 != 0) {
        return M2C_FIELD(((temp_v0 * 4) + M2C_FIELD(arg0, s32 *, 0x1C)), f32 *, -4);
    }
    return 0.0f;
}

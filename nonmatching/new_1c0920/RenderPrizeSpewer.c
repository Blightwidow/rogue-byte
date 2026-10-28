#include "m2c_macros.h"

M2C_UNK func_001A5EE8(s32, s32, M2C_UNK, M2C_UNK);  /* extern */
M2C_UNK func_001F3C70();                            /* extern */

void RenderPrizeSpewer(void *arg0) {
    s32 temp_a0;

    func_001F3C70();
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x158);
    if (temp_a0 != 0) {
        func_001A5EE8(temp_a0, M2C_FIELD(arg0, s32 *, 0x150) + 0x40, 0x3F800000, 0x3F800000);
    }
}

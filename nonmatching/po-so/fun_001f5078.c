#include "m2c_macros.h"

M2C_UNK WakeXf(void *, s32);                        /* extern */

void func_001F5078(void *arg0) {
    void *temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0xEC) != 0) {
        temp_v0 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK), 0x17C)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x178), 4);
        if (M2C_FIELD(arg0, s32 *, 0xE8) != 0) {
            WakeXf(arg0, M2C_FIELD(arg0, s32 *, 0x58));
            WakeXf(arg0, M2C_FIELD(arg0, s32 *, 0x5C));
        }
    }
}

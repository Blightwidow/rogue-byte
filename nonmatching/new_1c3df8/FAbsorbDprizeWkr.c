#include "m2c_macros.h"

s32 FAbsorbDprizeWkr(void *arg0, void *arg1) {
    void *temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0x1C8) != 0) {
        if (M2C_FIELD(arg1, s32 *, 0x44) & 8) {
            temp_v0 = M2C_FIELD(arg0, void **, 0xC);
            M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK, void *), 0x264)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x260), 1, arg0);
            return 1;
        }
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}

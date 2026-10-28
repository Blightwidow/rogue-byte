#include "m2c_macros.h"

M2C_UNK HandleLoMessage();                          /* extern */

void HandleGadgetObjMessage(s32 arg0, s32 arg1, void *arg2) {
    void *temp_a2;
    void *temp_v0;

    HandleLoMessage();
    if (arg1 == 4) {
        temp_a2 = M2C_FIELD(arg2, void **, 4);
        if ((temp_a2 == arg0) && ((u32) (M2C_FIELD(temp_a2, s32 *, 0x150) - 1) < 2U)) {
            temp_v0 = M2C_FIELD(temp_a2, void **, 0xC);
            M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK, void *), 0x264)(temp_a2 + M2C_FIELD(temp_v0, s16 *, 0x260), 3, temp_a2);
        }
    }
}

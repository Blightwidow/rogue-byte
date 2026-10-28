#include "m2c_macros.h"

M2C_UNK HandleLoMessage();                          /* extern */
M2C_UNK PrimeBomb__FP4BOMBf(void *, M2C_UNK);       /* extern */

void HandleBombMessage__FP4BOMB5MSGIDPv(s32 arg0, s32 arg1, void *arg2) {
    void *temp_a0;

    HandleLoMessage();
    if (arg1 == 4) {
        temp_a0 = M2C_FIELD(arg2, void **, 4);
        if ((temp_a0 == arg0) && (M2C_FIELD(temp_a0, s32 *, 0x150) == 0)) {
            PrimeBomb__FP4BOMBf(temp_a0, 0);
        }
    }
}

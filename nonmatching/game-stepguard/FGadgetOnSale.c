#include "m2c_macros.h"

s32 NEpisodeBest(s32, M2C_UNK);                     /* extern */
extern M2C_UNK D_002BCD00;

s32 FGadgetOnSale(s32 arg0) {
    s32 temp_a0;
    void *temp_s0;

    temp_a0 = arg0 << 5;
    temp_s0 = temp_a0 + &D_002BCD00;
    if (M2C_FIELD(temp_s0, s32 *, 0x10) == -1) {
        return 0;
    }
    return NEpisodeBest(temp_a0, -1) >= M2C_FIELD(temp_s0, s32 *, 0x10);
}

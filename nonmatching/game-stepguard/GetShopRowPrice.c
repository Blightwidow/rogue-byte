#include "m2c_macros.h"

M2C_UNK sprintf(M2C_UNK *, s32);                    /* extern */
extern M2C_UNK B_003DA150;
extern M2C_UNK D_002BCD00;
extern M2C_UNK RO_002A79A0;

void GetShopRowPrice(s8 *arg0, s32 arg1) {
    s32 var_a2;
    u32 temp_a1;

    temp_a1 = M2C_FIELD((&B_003DA150 + ((M2C_FIELD(&B_003DA150, s32 *, 0x250) + arg1) * 8)), u32 *, 0x4C);
    var_a2 = 0;
    if (temp_a1 < 0x2BU) {
        var_a2 = M2C_FIELD((&D_002BCD00 + (temp_a1 << 5)), s32 *, 8);
    }
    if (var_a2 != 0) {
        sprintf(&RO_002A79A0, var_a2);
        return;
    }
    *arg0 = 0;
}

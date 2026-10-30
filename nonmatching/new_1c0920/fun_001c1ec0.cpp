#include "m2c_macros.h"
extern "C" {

M2C_UNK FindCrvClosestPointAll(s32, M2C_UNK *, void *); /* extern */
s128 PosLoWorld(s32);                    /* extern */
extern M2C_UNK B_003DD020;

s128 func_001C1EC0(void *arg0) {
    char sp[0x10];
    s128 sp0;
    s128 var_v0;
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0);
    if (temp_v0 != 0) {
        FindCrvClosestPointAll(temp_v0, &B_003DD020, sp);
    } else {
        temp_v0_2 = M2C_FIELD(arg0, s32 *, 4);
        if (temp_v0_2 == 0) {
            var_v0 = M2C_FIELD(arg0, s128 *, 0x10);
        } else {
            var_v0 = PosLoWorld(temp_v0_2);
        }
        sp0 = var_v0;
    }
    return sp0;
}
}

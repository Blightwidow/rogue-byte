#include "m2c_macros.h"

void *PglyffFromCh__8CFontBrxc(s32);                /* extern */

f32 DxFromCh__8CFontBrxc(void *arg0, s32 arg1) {
    f32 var_f0;
    f32 var_f1;
    void *temp_v0;

    temp_v0 = PglyffFromCh__8CFontBrxc(arg1 & 0xFF);
    if (temp_v0 != NULL) {
        var_f1 = M2C_FIELD(arg0, f32 *, 0x10);
        var_f0 = (f32) (M2C_FIELD(temp_v0, u16 *, 6) + 1);
    } else {
        var_f1 = (f32) M2C_FIELD(arg0, s32 *, 8);
        var_f0 = M2C_FIELD(arg0, f32 *, 0x10);
    }
    return var_f0 * var_f1;
}

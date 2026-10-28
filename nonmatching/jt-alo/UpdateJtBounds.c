#include "m2c_macros.h"

M2C_UNK ExtendSoBounds(void *, s128, f32);          /* extern */
M2C_UNK UpdateSoBounds();                           /* extern */

void UpdateJtBounds(void *arg0) {
    s128 *var_s1;
    s128 temp_a1;
    s32 var_s2;

    var_s2 = 0;
    UpdateSoBounds();
    var_s1 = arg0 + 0x1890;
    if (M2C_FIELD(arg0, s32 *, 0x1880) > 0) {
        do {
            temp_a1 = *var_s1;
            var_s2 += 1;
            var_s1 += 0x10;
            ExtendSoBounds(arg0, temp_a1, M2C_FIELD(arg0, f32 *, 0x19AC));
        } while (var_s2 < M2C_FIELD(arg0, s32 *, 0x1880));
    }
}

#include "m2c_macros.h"

M2C_UNK ConvertAloPos(void *, M2C_UNK, s128);       /* extern */
M2C_UNK ExtendSoBounds(void *, M2C_UNK, f32);       /* extern */
M2C_UNK UpdateSoBounds();                           /* extern */

void UpdateVehicleBounds(void *arg0) {
    f32 temp_f12;
    s32 var_s2;
    void *var_s0;

    var_s2 = 0;
    UpdateSoBounds();
    var_s0 = arg0 + 0x1A0;
    if (M2C_FIELD(arg0, s32 *, 0x190) > 0) {
        do {
            var_s2 += 1;
            ConvertAloPos(arg0, 0, M2C_FIELD(var_s0, s128 *, 0x50));
            temp_f12 = M2C_FIELD(var_s0, f32 *, 0x20);
            var_s0 += 0x60;
            ExtendSoBounds(arg0, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */), temp_f12);
        } while (var_s2 < M2C_FIELD(arg0, s32 *, 0x190));
    }
}

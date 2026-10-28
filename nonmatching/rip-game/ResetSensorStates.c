#include "m2c_macros.h"

extern f32 g_2dded0;

void ResetSensorStates(void *arg0) {
    s32 var_a1;
    void *var_v1;

    var_a1 = 0;
    if (M2C_FIELD(arg0, s32 *, 0xFC) > 0) {
        var_v1 = arg0 + 0x108;
        do {
            M2C_FIELD(var_v1, s32 *, -4) = 0;
            var_a1 += 1;
            M2C_FIELD(var_v1, f32 *, 0) = (f32) g_2dded0;
            var_v1 += 0x10;
        } while (var_a1 < M2C_FIELD(arg0, s32 *, 0xFC));
    }
}

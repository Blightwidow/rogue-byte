#include "m2c_macros.h"

extern f32 g_2dded0;

s32 FPausedEmitter__FP7EMITTER(void *arg0) {
    s32 temp_v1;
    s32 var_v0;

    if (!(g_2dded0 < M2C_FIELD(arg0, f32 *, 0x148))) {
        temp_v1 = M2C_FIELD(arg0, s32 *, 0xF0);
        var_v0 = 0;
        if ((temp_v1 < 2) && (temp_v1 >= 0)) {
            var_v0 = 1;
            if (M2C_FIELD(arg0, s32 *, 0xF4) != 0) {
                var_v0 = 0;
            }
        }
        return var_v0;
    }
    return 1;
}

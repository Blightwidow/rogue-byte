#include "m2c_macros.h"

s32 FStreamPlaying(void *arg0, s32 arg1) {
    s32 var_a0;
    void *temp_v0;

    temp_v0 = M2C_FIELD(arg0, void **, 0x200);
    if (temp_v0 != NULL) {
        var_a0 = 0;
        if ((arg1 == -1) || (M2C_FIELD(M2C_FIELD(temp_v0, void **, 0x60), s32 *, 0x40) == arg1)) {
            var_a0 = 1;
        }
        return var_a0;
    }
    return 0;
}

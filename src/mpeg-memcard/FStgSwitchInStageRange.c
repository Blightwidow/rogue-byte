#include "m2c_macros.h"

s32 FStgSwitchInStageRange(void *arg0) {
    s32 temp_v1;
    s32 var_a1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x15C);
    var_a1 = 0;
    if (((temp_v1 >= 0) && (temp_v1 < M2C_FIELD(arg0, s32 *, 0x160))) || (temp_v1 == -1)) {
        var_a1 = 1;
    }
    return var_a1;
}

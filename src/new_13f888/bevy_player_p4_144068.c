#include "m2c_macros.h"

s32 bevy_player_p4_144068(void *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if ((M2C_FIELD(arg0, s32 *, 0x270) > 0) || (M2C_FIELD(arg0, s32 *, 0x1084) != 0)) {
        var_v1 = 1;
    }
    return var_v1;
}

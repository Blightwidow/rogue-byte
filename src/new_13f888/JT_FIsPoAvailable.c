#include "m2c_macros.h"

s32 bevy_player_p7_damage_1a23c0(s32);              /* extern */
s32 func_001C41B8();                                /* extern */

s32 JT_FIsPoAvailable(s32 arg0) {
    if (func_001C41B8() == 0) {
        return 0;
    }
    return bevy_player_p7_damage_1a23c0(arg0 + 0xDF0) != 2;
}

#include "m2c_macros.h"

void bevy_player_p7_damage_1a2160(void *arg0, void *arg1) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 4);
    if ((temp_v1 == 5) || ((temp_v1 >= 6) && (temp_v1 < 0xD) && (temp_v1 >= 8))) {
        M2C_FIELD(arg1, s32 *, 0x34) = 0;
    }
    M2C_FIELD(arg1, s32 *, 0) = (s32) (M2C_FIELD(arg1, s32 *, 0) | 1);
}

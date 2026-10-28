#include "m2c_macros.h"

f32 UMaxCrv();                                      /* extern */
f32 UMinCrv(void *);                                /* extern */

f32 bevy_player_p5_target_1e77e8(void *arg0) {
    f32 temp_f20;

    temp_f20 = UMaxCrv();
    return (temp_f20 - UMinCrv(arg0)) / ((f32) M2C_FIELD(arg0, s32 *, 0xE8) * 10.0f);
}

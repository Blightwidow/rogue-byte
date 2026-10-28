#include "m2c_macros.h"

s32 bevy_player_p15_binoc_active(void *arg0) {
    return (u32) M2C_FIELD(arg0, u32 *, 0xF04) < 3U;
}

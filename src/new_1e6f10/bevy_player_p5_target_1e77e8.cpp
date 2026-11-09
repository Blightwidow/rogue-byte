#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
f32 UMaxCrv(s8 *);                                      /* extern */
f32 UMinCrv(s8 *);                                /* extern */

f32 bevy_player_p5_target_1e77e8(s8 *arg0) {
    f32 temp_f20;

    temp_f20 = UMaxCrv(arg0);
    return (temp_f20 - UMinCrv(arg0)) / ((f32) M2C_FIELD(arg0, s32 *, 0xE8) * 10.0f);
}

}

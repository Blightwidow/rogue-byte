#include "m2c_macros.h"

M2C_UNK SetSwGuardsFrozen(M2C_UNK);                 /* extern */
extern f32 D_FLT_002BF938;
extern f32 g_2dded0;

void UpdateSwGuardsFrozen(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x4748) != 0) {
        if (D_FLT_002BF938 < (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x474C))) {
            SetSwGuardsFrozen(0);
        }
    }
}

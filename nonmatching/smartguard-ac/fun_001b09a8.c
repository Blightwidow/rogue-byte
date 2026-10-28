#include "m2c_macros.h"

M2C_UNK RequestTransition(M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK bevy_jobs_162e38(s32);                      /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK RO_002A3928;

void func_001B09A8(void *arg0) {
    RequestTransition(&B_003DD490, &RO_002A3928, 0x189, -1);
    if (M2C_FIELD(&B_003DD490, s32 *, 0x3B0C) != 0) {
        bevy_jobs_162e38(M2C_FIELD(&B_003DD490, s32 *, 0x3B0C));
    }
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s32 *, 0x1C) = (s32) (M2C_FIELD(arg0, s32 *, 0x1C) | 2);
    }
}

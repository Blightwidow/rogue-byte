#include "m2c_macros.h"

s128 PosLoWorld(s32);                               /* extern */
s32 PpoSwFocus(M2C_UNK *);                          /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK B_003DD490;

s128 bevy_classes_k30_cam_150780(void *arg0) {
    M2C_UNK unksp8;
    s128 sp0;
    s32 temp_a0;
    s32 temp_v0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0x10);
    if (temp_a0 == 0) {
        temp_v0 = PpoSwFocus(&B_003DD490);
        if (temp_v0 == 0) {
            sp0 = M2C_FIELD(&B_002DDF40, s128 *, 0x90);
        } else {
            sp0 = PosLoWorld(temp_v0);
            unksp8 += 150.0f;
        }
    } else {
        sp0 = PosLoWorld(temp_a0);
    }
    return sp0;
}

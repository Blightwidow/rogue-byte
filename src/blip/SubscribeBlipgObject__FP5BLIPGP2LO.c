#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
M2C_UNK SubscribeLoObject();                        /* extern */

void SubscribeBlipgObject__FP5BLIPGP2LO(void *arg0, void *arg1) {
    SubscribeLoObject();
    if (FIsBasicDerivedFrom(arg1, 0x1D) != 0) {
        M2C_FIELD(arg0, void **, 0xE0) = arg1;
        M2C_FIELD(arg0, f32 *, 0x38) = (f32) M2C_FIELD(arg1, f32 *, 0x38);
    }
}

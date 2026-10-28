#include "m2c_macros.h"

void *PattachCrv(M2C_UNK);                          /* extern */

f32 func_001E79A0(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xE8) > 0) {
        return M2C_FIELD(((M2C_FIELD(arg0, s32 *, 0xE8) * 4) + M2C_FIELD(PattachCrv(0), s32 *, 0x5C)), f32 *, -4);
    }
    return 0.0f;
}

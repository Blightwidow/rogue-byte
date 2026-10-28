#include "m2c_macros.h"

s32 FFindSurfaceAlongUp(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s128); /* extern */
s128 PosLoWorld(void *);                            /* extern */

s32 func_0014A478(void *arg0) {
    char sp[0x400];
    void *temp_a0;

    temp_a0 = M2C_FIELD(arg0, void **, 0x10);
    if (M2C_FIELD(temp_a0, s32 *, 0x208) != 0) {
        return 0;
    }
    return FFindSurfaceAlongUp(sp, 1, 0, 0x42C80000, 0xC37A0000, PosLoWorld(temp_a0)) == 0;
}

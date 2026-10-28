#include "m2c_macros.h"

M2C_UNK UpdateSpriteInstance(s32, s32, void *, M2C_UNK); /* extern */

void func_00215850(void *arg0, void *arg1, void *arg3) {
    char sp[0x400];
    M2C_UNK sp10;

    if (M2C_FIELD(arg0, s32 *, 4) == 4) {
        sp10 = M2C_UNALIGNED32(M2C_FIELD(M2C_ERROR(/* Read from unset register $t0 */), M2C_UNK *, 0));
        UpdateSpriteInstance(M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 0x84) + (M2C_FIELD(arg0, s32 *, 0x10) * 0x30), M2C_FIELD(arg1, s32 *, 0x58), sp, M2C_UNALIGNED32(M2C_FIELD(arg3, M2C_UNK *, 0)));
    }
}

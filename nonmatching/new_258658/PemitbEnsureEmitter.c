#include "m2c_macros.h"

s32 *PvAllocSwCopyImpl__FiPv(void *, s32 *, M2C_UNK, s32, s32); /* extern */

s32 *PemitbEnsureEmitter(void *arg0, s32 arg1) {
    char sp[0x400];
    s32 *temp_a0;
    s32 *temp_v0;
    s32 temp_v1;

    if (arg1 == 1) {
        M2C_FIELD(arg0, s32 *, 0xE0) = arg1;
        temp_a0 = M2C_FIELD(arg0, s32 **, 0xE4);
        temp_v1 = *temp_a0;
        if (temp_v1 >= 2) {
            *temp_a0 = temp_v1 - 1;
            temp_v0 = PvAllocSwCopyImpl__FiPv(sp, M2C_FIELD(arg0, s32 **, 0xE4), 0x10, 0x100, 0x10);
            M2C_FIELD(arg0, s32 **, 0xE4) = temp_v0;
            *temp_v0 = arg1;
        }
    }
    return M2C_FIELD(arg0, s32 **, 0xE4);
}

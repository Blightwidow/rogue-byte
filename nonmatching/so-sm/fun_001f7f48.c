#include "m2c_macros.h"

M2C_UNK RecalcSoLocked(void *, void *);             /* extern */

void func_001F7F48(void *arg0, s32 arg1) {
    u64 temp_a0;

    temp_a0 = M2C_FIELD(arg0, u64 *, 0x148);
    if (arg1 != ((temp_a0 >> 0x22) & 1)) {
        M2C_FIELD(arg0, u64 *, 0x148) = (u64) ((temp_a0 & ((0xBFFFFFFF * 0x10) | 0xF)) | ((arg1 & 1) << 0x22));
        RecalcSoLocked(arg0, arg0);
    }
}

#include "m2c_macros.h"

M2C_UNK ReinsertSwRoot(M2C_UNK *, s32, u64);        /* extern */
extern M2C_UNK B_003DD490;

void func_001A6CA8(void *arg0, s32 arg1) {
    u64 temp_a2;
    u64 temp_a2_2;

    temp_a2 = M2C_FIELD(arg0, u64 *, 0x28);
    if ((arg1 != ((s64) (temp_a2 << 8) >> 0x3C)) && (temp_a2_2 = (temp_a2 & ((((((0xFF0F << 0x10) | 0xFFFF) << 0x10) | 0xFFFF) << 0x10) | 0xFFFF)) | ((arg1 & 0xF) << 0x34), M2C_FIELD(arg0, u64 *, 0x28) = temp_a2_2, (M2C_FIELD(arg0, s32 *, 0x10) == 0))) {
        if ((temp_a2_2 >> 0x3C) & 1) {
            ReinsertSwRoot(&B_003DD490, M2C_FIELD(arg0, s32 *, 0x14), temp_a2_2);
        }
    }
}

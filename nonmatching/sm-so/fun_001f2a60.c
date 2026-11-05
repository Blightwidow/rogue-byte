#include "m2c_macros.h"

M2C_UNK AddSoGeomToOxa();                           /* extern */

void func_001F2A60(void *arg0, void *arg1) {
    s64 temp_v1;

    temp_v1 = M2C_FIELD(arg1, s64 *, 0x10);
    if (temp_v1 & (0x8000 << 0x23)) {
        M2C_FIELD(arg1, s64 *, 0x10) = (s64) (temp_v1 & ((((((0xFFFB << 0x10) | 0xFFFF) << 0x10) | 0xFFFF) << 0x10) | 0xFFFF));
        if (((u64) M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1) {
            AddSoGeomToOxa();
        }
    }
}

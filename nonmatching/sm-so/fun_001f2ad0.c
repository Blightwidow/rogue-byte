#include "m2c_macros.h"

M2C_UNK RemoveSoGeomFromOxa(s64);                   /* extern */

void func_001F2AD0(void *arg0, void *arg1) {
    s64 temp_a2;
    s64 temp_v1;

    temp_a2 = 0x8000 << 0x23;
    temp_v1 = M2C_FIELD(arg1, s64 *, 0x10);
    if (!(temp_v1 & temp_a2)) {
        M2C_FIELD(arg1, s64 *, 0x10) = (s64) (temp_v1 | temp_a2);
        if (((u64) M2C_FIELD(arg0, u64 *, 0x28) >> 0x3C) & 1) {
            RemoveSoGeomFromOxa(temp_a2);
        }
    }
}

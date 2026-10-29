#include "m2c_macros.h"
extern "C" {

s32 FFilterOxaBasic(s32 arg0, void *arg1) {
    s32 var_a2;
    void *temp_a1;

    var_a2 = 0;
    if (!(M2C_FIELD(arg1, s64 *, 0x10) & (0x8000L << 0x21))) {
        temp_a1 = M2C_FIELD(M2C_FIELD(arg1, void **, 4), void **, 0xEC);
        if (!(M2C_FIELD(temp_a1, s64 *, 0x70) & 4)) {
            var_a2 = (s32) temp_a1 != arg0;
        }
    }
    return var_a2;
}
}

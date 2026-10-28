#include "m2c_macros.h"

M2C_UNK func_001F2AD0(void *, void *);              /* extern */

void func_001F6B48(void *arg0, s32 arg1) {
    s32 var_s1;
    s32 var_s2;
    void *temp_a1;

    var_s1 = 0;
    if (M2C_FIELD(arg0, s32 *, 0xE0) > 0) {
        var_s2 = 0;
        do {
            temp_a1 = M2C_FIELD(arg0, s32 *, 0xE4) + var_s2;
            if (M2C_FIELD(temp_a1, s32 *, 0xC) == arg1) {
                func_001F2AD0(arg0, temp_a1);
            }
            var_s1 += 1;
            var_s2 += 0xB0;
        } while (var_s1 < M2C_FIELD(arg0, s32 *, 0xE0));
    }
}

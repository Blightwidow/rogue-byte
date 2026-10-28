#include "m2c_macros.h"

M2C_UNK func_00169198(s32, void *);                 /* extern */

void func_001BEE60(void *arg0) {
    s32 *var_s1;
    s32 temp_a0;
    s32 var_s2;

    if (M2C_FIELD(arg0, s32 *, 0x128) != 0) {
        var_s2 = 0;
        if (M2C_FIELD(arg0, s32 *, 0xE0) > 0) {
            var_s1 = arg0 + 0xE4;
            do {
                temp_a0 = *var_s1;
                var_s2 += 1;
                var_s1 += 4;
                func_00169198(temp_a0 + 0x80, arg0);
            } while (var_s2 < M2C_FIELD(arg0, s32 *, 0xE0));
        }
    }
}

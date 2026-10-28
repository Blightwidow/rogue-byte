#include "m2c_macros.h"

M2C_UNK SetLoGrfzon(void *, s8);                    /* extern */

void func_001A6DC8(void *arg0, s8 arg1) {
    void *var_s0;

    var_s0 = M2C_FIELD(arg0, void **, 0x64);
    M2C_FIELD(arg0, s8 *, 0x2D) = arg1;
    if (var_s0 != NULL) {
        do {
            if (!(M2C_FIELD(var_s0, s64 *, 0x28) & (0x8000 << 0x2B))) {
                SetLoGrfzon(var_s0, arg1);
            }
            var_s0 = M2C_FIELD(var_s0, void **, 0x24);
        } while (var_s0 != NULL);
    }
}

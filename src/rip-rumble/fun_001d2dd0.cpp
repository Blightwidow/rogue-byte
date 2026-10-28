#include "m2c_macros.h"

void *func_001D2DD0(s32 arg0, void *arg1) {
    f32 temp_f0;
    f32 var_f1;
    void *var_v0;
    void *var_v1;

    var_v1 = M2C_FIELD(arg1, void **, 8);
    var_f1 = -3.4028235e38f;
    var_v0 = NULL;
    if (var_v1 != NULL) {
        do {
            temp_f0 = M2C_FIELD(var_v1, f32 *, 0x90);
            if (var_f1 < temp_f0) {
                var_f1 = temp_f0;
                var_v0 = var_v1;
            }
            var_v1 = M2C_FIELD(var_v1, void **, 0xAC);
        } while (var_v1 != NULL);
    }
    return var_v0;
}

#include "m2c_macros.h"

void UpdateSoDriven(void *arg0) {
    void **var_s0;
    void *temp_v0;
    void *var_a2;

    var_s0 = M2C_FIELD(arg0, void ***, 0x138);
    if (var_s0 != NULL) {
        var_a2 = *var_s0;
loop_2:
        temp_v0 = M2C_FIELD(var_a2, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void **, void *), 0x23C)(var_a2 + M2C_FIELD(temp_v0, s16 *, 0x238), var_s0, var_a2);
        var_s0 = M2C_FIELD(var_s0, void ***, 8);
        if (var_s0 != NULL) {
            var_a2 = *var_s0;
            goto loop_2;
        }
    }
}

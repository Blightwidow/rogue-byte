#include "m2c_macros.h"

M2C_UNK UpdateAloXfWorld();                         /* extern */

void UpdateAloXfWorldHierarchy(void *arg0) {
    void *var_s0;
    void *var_v0;

    UpdateAloXfWorld();
    var_s0 = M2C_FIELD(arg0, void **, 0x64);
    if (var_s0 != M2C_FIELD(arg0, s32 *, 0x70)) {
        var_v0 = M2C_FIELD(var_s0, void **, 0xC);
loop_2:
        M2C_FIELD(var_v0, M2C_UNK (**)(void *), 0x94)(var_s0 + M2C_FIELD(var_v0, s16 *, 0x90));
        var_s0 = M2C_FIELD(var_s0, void **, 0x24);
        if (var_s0 != M2C_FIELD(arg0, s32 *, 0x70)) {
            var_v0 = M2C_FIELD(var_s0, void **, 0xC);
            goto loop_2;
        }
    }
}

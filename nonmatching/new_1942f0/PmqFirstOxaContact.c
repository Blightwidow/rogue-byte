#include "m2c_macros.h"

s32 PmqFirstOxaContact(void *arg0) {
    s32 var_v0;
    void *var_v1;

    var_v1 = M2C_FIELD(arg0, void **, 0x64);
    var_v0 = 0;
    if (var_v1 != NULL) {
loop_1:
        var_v0 = M2C_FIELD(var_v1, s32 *, 0);
        if (var_v0 == 0) {
            var_v1 = M2C_FIELD(var_v1, void **, 4);
            if (var_v1 == NULL) {
                var_v0 = 0;
            } else {
                goto loop_1;
            }
        }
    }
    return var_v0;
}

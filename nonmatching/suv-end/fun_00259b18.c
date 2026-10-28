#include "m2c_macros.h"

s32 func_00259B18(void *arg0) {
    s32 var_v0;
    void *temp_v0;
    void *var_v1;

    temp_v0 = M2C_FIELD(arg0, void **, 0xE8);
    var_v1 = NULL;
    if (temp_v0 != NULL) {
        var_v1 = M2C_FIELD(temp_v0, void **, 0xDC);
    }
    var_v0 = 0;
    if (var_v1 != NULL) {
        var_v0 = M2C_FIELD(var_v1, s32 *, 0x10);
    }
    return var_v0;
}

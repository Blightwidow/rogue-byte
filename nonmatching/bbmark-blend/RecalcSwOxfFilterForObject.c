#include "m2c_macros.h"

M2C_UNK UpdateSwPox(void *, s32, void *, M2C_UNK);  /* extern */
M2C_UNK func_001F4BF8(void *);                      /* extern */

void RecalcSwOxfFilterForObject(void *arg0, void *arg1) {
    void *var_s0;

    if (M2C_FIELD(arg1, s32 *, 0xEC) != 0) {
        func_001F4BF8(arg1);
        var_s0 = M2C_FIELD(arg0, void **, 0x3D10);
        if (var_s0 != NULL) {
loop_3:
            if (var_s0 != M2C_FIELD(arg1, s32 *, 0xEC)) {
                UpdateSwPox(arg0, M2C_FIELD(arg1, s32 *, 0xEC), var_s0, 0);
            }
            var_s0 = M2C_FIELD(var_s0, void **, 0x48);
            if (var_s0 != NULL) {
                goto loop_3;
            }
        }
    }
}

#include "m2c_macros.h"

M2C_UNK SaveJobVariables(void *);                   /* extern */
M2C_UNK SaveTaskVariables(void *);                  /* extern */

void ResetJob(void *arg0) {
    void *var_s0;

    var_s0 = M2C_FIELD(arg0, void **, 0x80);
    if (var_s0 != NULL) {
        M2C_FIELD(var_s0, s32 *, 0x64) = 0;
loop_2:
        var_s0 = M2C_FIELD(var_s0, void **, 0x84);
        SaveTaskVariables(var_s0);
        if (var_s0 != NULL) {
            M2C_FIELD(var_s0, s32 *, 0x64) = 0;
            goto loop_2;
        }
    }
    M2C_FIELD(arg0, s32 *, 0x7C) = 0;
    SaveJobVariables(arg0);
}

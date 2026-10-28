#include "m2c_macros.h"

M2C_UNK AddGuardBusyGoal(s32);                      /* extern */
s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */

void func_001EEFC0(void *arg0) {
    void *var_a0;

    if (M2C_FIELD(arg0, s32 *, 0x1C) == 0) {
        M2C_FIELD(arg0, s32 *, 0x1C) = 1;
        if (FIsBasicDerivedFrom(M2C_FIELD(arg0, s32 *, 0x10), 0x38) != 0) {
            AddGuardBusyGoal(M2C_FIELD(arg0, s32 *, 0x10));
        }
        var_a0 = M2C_FIELD(arg0, void **, 0x14);
        if (var_a0 != NULL) {
            do {
                M2C_FIELD(var_a0, s32 *, 0x20) = (s32) (M2C_FIELD(var_a0, s32 *, 0x20) + 1);
                var_a0 = M2C_FIELD(var_a0, void **, 0x14);
            } while (var_a0 != NULL);
        }
    }
}

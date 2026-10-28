#include "m2c_macros.h"

M2C_UNK SetAsegaMasterSpeed(void *, f32);           /* extern */

void SetAsegsvtMaster(void *arg0, f32 fparg0) {
    void *var_a0;
    void *var_s0;

    var_s0 = M2C_FIELD(arg0, void **, 0x50);
    if (var_s0 != NULL) {
        var_a0 = var_s0;
        do {
            SetAsegaMasterSpeed(var_a0, fparg0);
            var_s0 = M2C_FIELD(var_s0, void **, 0x2C);
            var_a0 = var_s0;
        } while (var_s0 != NULL);
    }
    M2C_FIELD(arg0, f32 *, 0x78) = fparg0;
}

#include "m2c_macros.h"

s32 FActDrivesXf(void *);                           /* extern */
M2C_UNK SetXfKind(s32, void *, M2C_UNK);            /* extern */

void func_00131A90(void *arg0, f32 fparg0) {
    void *temp_a1;
    void *var_s0;

    var_s0 = M2C_FIELD(arg0, void **, 0x34);
    if (var_s0 != NULL) {
        do {
            if (FActDrivesXf(var_s0) != 0) {
                temp_a1 = M2C_FIELD(var_s0, void **, 8);
                if (M2C_FIELD(temp_a1, s16 *, 0x98) == 7) {
                    SetXfKind(M2C_FIELD(var_s0, s32 *, 4), temp_a1, 9);
                    M2C_FIELD(M2C_FIELD(var_s0, void **, 8), f32 *, 0xA8) = fparg0;
                }
            }
            var_s0 = M2C_FIELD(var_s0, void **, 0x28);
        } while (var_s0 != NULL);
    }
}

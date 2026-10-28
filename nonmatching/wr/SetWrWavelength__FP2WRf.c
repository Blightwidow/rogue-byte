#include "m2c_macros.h"

void *PwreGetWrCircle__FP2WR4ENSK(M2C_UNK);         /* extern */

void SetWrWavelength__FP2WRf(f32 fparg0) {
    f32 var_f0;
    void *temp_v0;

    temp_v0 = PwreGetWrCircle__FP2WR4ENSK(1);
    var_f0 = 0.0f;
    if (fparg0 != 0.0f) {
        var_f0 = 1.0f / fparg0;
    }
    M2C_FIELD(temp_v0, f32 *, 0x64) = var_f0;
}

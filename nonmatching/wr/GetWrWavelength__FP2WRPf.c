#include "m2c_macros.h"

void *PwreGetWrCircle__FP2WR4ENSK(M2C_UNK);         /* extern */

f32 GetWrWavelength__FP2WRPf(void) {
    f32 temp_f1;
    f32 var_f0;

    temp_f1 = M2C_FIELD(PwreGetWrCircle__FP2WR4ENSK(1), f32 *, 0x64);
    var_f0 = 0.0f;
    if (temp_f1 != 0.0f) {
        var_f0 = 1.0f / temp_f1;
    }
    return var_f0;
}

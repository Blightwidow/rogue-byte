#include "m2c_macros.h"

M2C_UNK GetSoCpdefi__FP2SOfP6CPDEFI();              /* extern */

void GetDancerCpdefi(s32 arg0, void *arg1) {
    GetSoCpdefi__FP2SOfP6CPDEFI();
    M2C_FIELD(arg1, f32 *, 0x30) = (f32) (M2C_FIELD(arg1, f32 *, 0x30) - 2.3561945f);
}

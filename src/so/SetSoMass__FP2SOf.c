#include "m2c_macros.h"

M2C_UNK AdjustSoMomint__FP2SOf(f32);                /* extern */

void SetSoMass__FP2SOf(void *arg0, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f12;
    void *temp_v0;

    temp_v0 = M2C_FIELD(arg0, void **, 0xE8);
    temp_f0 = M2C_FIELD(temp_v0, f32 *, 0xD0);
    temp_f12 = fparg0 / temp_f0;
    M2C_FIELD(temp_v0, f32 *, 0xD0) = (f32) (temp_f0 * temp_f12);
    AdjustSoMomint__FP2SOf(temp_f12);
}

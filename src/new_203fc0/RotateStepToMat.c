#include "m2c_macros.h"

f32 RadYawSo(void *);                               /* extern */
M2C_UNK RotateSoToMat();                            /* extern */
M2C_UNK SetStepRadTarget(void *, f32);              /* extern */

void RotateStepToMat(void *arg0) {
    void *temp_v0;

    RotateSoToMat();
    SetStepRadTarget(arg0, RadYawSo(arg0));
    temp_v0 = M2C_FIELD(arg0, void **, 0x150);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, f32 *, 0x18) = (f32) M2C_FIELD(arg0, f32 *, 0x1A8);
    }
}
